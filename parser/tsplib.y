/* $Id: parser.yy 19 2007-08-19 20:36:24Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the TSPLIB Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>

%}

%code requires{
    #include <map>
    #include<vector>
    #include <common/tsp.h>
    #include <common/tsplibinstance.h>
}

/*** yacc/bison Declarations ***/

/* Require bison 3.0 or later */
%require "3.0"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start start

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%define api.namespace {TSPLIB}

/* set the parser's class identifier */
%define "parser_class_name" {Parser}

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

 /*** BEGIN TSPLIB - Change the TSPLIB grammar's tokens below ***/

%union {
    int  			integerVal;
    double 			doubleVal;
    std::string*		stringVal;
    std::vector<int>*     integerList;
    std::vector<float>*   floatList;
    std::map<int, std::vector<double>>* coordMap;
    std::vector<double>* coordList;
    TSP::TYPE           tspType;
    TSP::EDGE_WEIGHT_TYPE   edgeWeightType;
//    TSP::EDGE_WEIGHT_FORMAT edgeWeightFormat;
//    TSP::EDGE_DATA_FORMAT   edgeDataFormat;
    TSP::NODE_COORD_TYPE    nodeCoordType;
//    TSP::DISPLAY_DATA_TYPE  displayDataType;
}

%token			END	     0	"end of file"
%token			EOL		"end of line"
%token <integerVal> 	INTEGER		"integer"
%token <doubleVal> 	DOUBLE		"double"
%token <stringVal> 	STRING		"string"
%token          KEY_VALUE_SEPARATOR "key-value separator"
%token <stringVal> UNMATCHED_TOKEN "unmatched input token"

%token <tspType> TSPTYPE
%token          NAME
%token          TYPE
%token          COMMENT
%token          DIMENSION
%token          NODE_COORD_SECTION

%type<stringVal> string_value
%type<integerVal> integer
%type<doubleVal> real
%type<floatList> float_list
%type<integerList> integer_list
%type<coordMap> coord_section
%type<coordList> coords

%destructor { delete $$; } STRING integer_list float_list coord_section coords


 /*** END TSPLIB - Change the TSPLIB grammar's tokens above ***/

%{

#include "tsplib_driver.h"
#include "tsplib_lexer.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/

 /*** BEGIN TSPLIB - Change the TSPLIB grammar rules below ***/


string_value : STRING {
        $$ = $1;
    }

separator : KEY_VALUE_SEPARATOR {
        // Found a field separator
    } | %empty {
        // Separator is optional
    }

integer_list : integer {
        $$ = new std::vector<int>();
        $$->push_back($1);
    }
    | integer_list integer {
        $$ = $1;
        $1->push_back($2);
    }

coord_section : separator integer coords {
        $$ = new std::map<int, std::vector<double>>();
        (*$$)[$2] = *$3;
    }
    | coord_section integer coords {
        $$ = $1;
        (*$$)[$2] = *$3;
    }
coords : real {
        $$ = new std::vector<double>();
    }
    | coords real {
        $$ = $1;
        $1->push_back($2);
    }

real : DOUBLE; // TODO: also accept integers

integer : INTEGER;

end : EOL | END;

specification : NAME separator string_value {
       driver.set_name($3);
    }
    | TYPE separator TSPTYPE {
        driver.create_instance($3);
    }

data : NODE_COORD_SECTION coord_section {
        TSPLIB::Instance * instance = driver.get_instance();
        if(instance = driver.get_instance()) {
            instance->set_coordinate_section(* $2);
        } else {
            driver.error(@$, "Unexpected coordinate section, not able to construct ");
        }
    }

start	: %empty
        | start EOL
        | start specification end
        | start data end

 /*** END TSPLIB - Change the TSPLIB grammar rules above ***/

%% /*** Additional Code ***/

void TSPLIB::Parser::error(const Parser::location_type& l,
                const std::string& m)
{
    driver.error(l, m);
}
