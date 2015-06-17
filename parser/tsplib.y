/* $Id: parser.yy 19 2007-08-19 20:36:24Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the TSPLIB Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>

%}

%code requires{
//    #include "expression.h"
}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

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
}

%token			END	     0	"end of file"
%token			EOL		"end of line"
%token <integerVal> 	INTEGER		"integer"
%token <doubleVal> 	DOUBLE		"double"
%token <stringVal> 	STRING		"string"
%token          KEY_VALUE_SEPARATOR

%type<stringVal> value keyword

//%type <calcnode>	constant variable
//%type <calcnode>	atomexpr powexpr unaryexpr mulexpr addexpr expr

%destructor { delete $$; } STRING
//%destructor { delete $$; } constant variable
//%destructor { delete $$; } atomexpr powexpr unaryexpr mulexpr addexpr expr

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


value : STRING
           {
            $$ = $1;
//           if (!driver.calc.existsVariable(*$1)) {
//           error(@$, std::string("Unknown variable \"") + *$1 + "\"");
//           delete $1;
//           YYERROR;
//           }
//           else {
//           $$ = new CNConstant( driver.calc.getVariable(*$1) );
//           delete $1;
//           }
       }

keyword : STRING {
        $$ = $1;
    }

separator : KEY_VALUE_SEPARATOR {

    } | %empty {

    }
start	: %empty
        | start ';'
        | start EOL
        | start keyword separator value EOL
          {
            driver.start_field($2);
            driver.add_value($4);
//          driver.calc.expressions.push_back($2);
      }
        | start keyword END
          {
//          driver.calc.expressions.push_back($2);
      }

 /*** END TSPLIB - Change the TSPLIB grammar rules above ***/

%% /*** Additional Code ***/

void TSPLIB::Parser::error(const Parser::location_type& l,
                const std::string& m)
{
    driver.error(l, m);
}
