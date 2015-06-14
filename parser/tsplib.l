/* $Id: scanner.ll 44 2008-10-23 09:03:19Z tb $ -*- mode: c++ -*- */
/** \file scanner.ll Define the TSPLIB Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>
#include <iostream>

#include "tsplib_lexer.h"

/* import the parser's token type into a local typedef */
typedef TSPLIB::Parser::token token;
typedef TSPLIB::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

%s VALUE

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "TSPLIBFlexLexer" */
%option prefix="TSPLIB"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

 /*** BEGIN TSPLIB - Change the TSPLIB lexer rules below ***/

[0-9]+ {
    yylval->integerVal = atoi(yytext);
    return token::INTEGER;
}

[0-9]+"."[0-9]* {
    yylval->doubleVal = atof(yytext);
    return token::DOUBLE;
}
":" {
    BEGIN(VALUE);
    return token::KEY_VALUE_SEPARATOR;
}

 /* gobble up white-spaces */
[ \t\r]+ {
    yylloc->step();
}

 /* read a single word */
<INITIAL>[A-Za-z]+ {
        yylval->stringVal = new std::string(yytext, yyleng);
        BEGIN(INITIAL);
        return token::STRING;
}

 /* read the rest of the line as a single string */
<VALUE>[^\n]* {
    yylval->stringVal = new std::string(yytext, yyleng);
    BEGIN(INITIAL);
    return token::STRING;
}

 /* gobble up end-of-lines */
\n {
    yylloc->lines(yyleng); yylloc->step();
    return token::EOL;
}

 /* pass all other characters up to bison */
. {
    return static_cast<token_type>(*yytext);
}

 /*** END TSPLIB - Change the TSPLIB lexer rules above ***/

%% /*** Additional Code ***/

namespace TSPLIB {

Scanner::Scanner(std::istream* in,
         std::ostream* out)
    : TSPLIBFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of TSPLIBFlexLexer::yylex() is required to fill the
 * vtable of the class TSPLIBFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int TSPLIBFlexLexer::yylex()
{
    std::cerr << "in TSPLIBFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int TSPLIBFlexLexer::yywrap()
{
    return 1;
}
