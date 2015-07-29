/* $Id: parser.yy 19 2007-08-19 20:36:24Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the TSPLIB Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>

%}

%code requires{
    #include <map>
    #include <vector>
    #include <common/tsp.h>
    #include <common/tsplibinstance.h>
    #include <sstream>
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
%lex-param { class Driver& driver }
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
    TSP::EDGE_WEIGHT_FORMAT edgeWeightFormat;
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
%token          NODE_COORD_TYPE
%token          EDGE_WEIGHT_TYPE
%token          EDGE_WEIGHT_FORMAT
%token <nodeCoordType> NODE_COORD_TYPE_LITERAL
%token <edgeWeightType> EDGE_WEIGHT_TYPE_LITERAL
%token <edgeWeightFormat> EDGE_WEIGHT_FORMAT_LITERAL
%token          EDGE_DATA_SECTION

%type<stringVal> string_value
%type<integerVal> integer
%type<doubleVal> real number
%type<integerList> integer_list
%type<coordMap> coord_section
%type<coordList> coords

%destructor { delete $$; } STRING coord_section coords


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

integer_list : number {
        $$ = new std::vector<int>();
        $$->push_back($1);
    }
    | integer_list number end { // how to make this `end` token optional between two numbers?
        $$ = $1;
        $1->push_back($2);
    }
    | integer_list number {
        $$ = $1;
        $1->push_back($2);
    }

coord_section : integer coords end {
        $$ = new std::map<int, std::vector<double>>();
        (*$$)[$1] = *$2;
    }
    | coord_section integer coords end {
        $$ = $1;
        (*$$)[$2] = *$3;
    }
coords : number {
        $$ = new std::vector<double>();
        $$->push_back($1);
    }
    | coords number {
        $$ = $1;
        $1->push_back($2);
    }

number : real | integer { $$ = $1;};

real : DOUBLE; // TODO: also accept integers

integer : INTEGER;

end : EOL | END;

specification :
    NAME separator string_value {
       driver.get_instance().set_name(*$3);
    }
    | COMMENT separator string_value {
        driver.get_instance().set_comment(*$3);
    }
    | TYPE separator TSPTYPE {
        driver.create_instance($3);
    }
    | EDGE_WEIGHT_TYPE separator EDGE_WEIGHT_TYPE_LITERAL{
        driver.get_tsp_instance().set_edge_weight_type($3);
    }
    | EDGE_WEIGHT_FORMAT separator EDGE_WEIGHT_FORMAT_LITERAL{
        driver.get_tsp_instance().set_edge_weight_format($3);
    }
    | NODE_COORD_TYPE separator NODE_COORD_TYPE_LITERAL{
        driver.get_tsp_instance().set_node_coordinate_type($3);
    }
    | DIMENSION separator integer {
        driver.get_tsp_instance().set_dimension($3);
    }
    | EDGE_DATA_SECTION separator integer_list {
        driver.get_tsp_instance().set_edge_weights(*$3);
    }

data : NODE_COORD_SECTION separator coord_section {
        TSPLIB::BaseInstance & instance = driver.get_tsp_instance();
        instance.set_node_coordinate_section(* $3);
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

