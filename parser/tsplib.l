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

%s EXPECT_REST_OF_LINE_STRING REST_OF_LINE_STRING

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

%option case-insensitive

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

KEYWORD             [a-z][a-z_]*
INTEGER             -?[[:digit:]][[:digit:]]*
/* float exponent */
EXP     ([Ee][-+]?[0-9]+)
FLOAT               -?([0-9]*\.[0-9]+|[0-9]+\.){EXP}?[flFL]?
WHITESPACE          [[:blank:]\r]

/* literal keywords */
KEYWORD_NAME        name
KEYWORD_TYPE        type
KEYWORD_COMMENT     comment

/* normal TSP types, as defined in TSPLIB */
KEYWORD_TSP         tsp
KEYWORD_ATSP        atsp
KEYWORD_SOP         sop

KEYWORD_HCP         hcp
KEYWORD_CVRP        cvrp
KEYWORD_TOUR        tour

/* generalized TSP extension, according to the rules specified in:
 * http://www.cs.rhul.ac.uk/home/zvero/GTSPLIB/ and
 * http://www.cs.nott.ac.uk/~dxk/gtsp.html
 */

KEYWORD_GTSP        gtsp
KEYWORD_AGTSP       agtsp

KEYWORD_GTSP_SETS   gtsp_sets
KEYWORD_GTSP_SET_SECTION gtsp_set_section

/*
 * Other attributes
 */
KEYWORD_DIMENSION   dimension
KEYWORD_CAPACITY    capacity
KEYWORD_EDGE_WEIGHT_TYPE  edge_weight_type
KEYWORD_EDGE_WEIGHT_FORMAT edge_weight_format
KEYWORD_EDGE_DATA_FORMAT   edge_data_format
KEYWORD_EDGE_DATA_SECTION   edge_data_section
KEYWORD_NODE_COORD_TYPE node_coord_type
KEYWORD_NODE_COORD_SECTION node_coord_section
KEYWORD_EDGE_WEIGHT_SECTION edge_weight_section

/*
 * Edge weight types
 */
KEYWORD_EXPLICIT    explicit
KEYWORD_EUC_2D      euc_2d
KEYWORD_EUC_3D      euc_3d
KEYWORD_MAX_2D      max_2d
KEYWORD_MAX_3D      max_3d
KEYWORD_CEIL_2D     ceil_2d
KEYWORD_GEO         geo
KEYWORD_ATT         att
KEYWORD_XRAY1       xray1
KEYWORD_XRAY2       xray2
KEYWORD_SPECIAL     special

/*
 * Edge weight formats
 */
KEYWORD_FUNCTION    function
KEYWORD_FULL_MATRIX full_matrix
KEYWORD_UPPER_ROW   upper_row
KEYWORD_LOWER_ROW   lower_row
KEYWORD_UPPER_COL   upper_col
KEYWORD_LOWER_COL   lower_col
KEYWORD_UPPER_DIAG_COL  upper_diag_col
KEYWORD_LOWER_DIAG_COL  lower_diag_col

/*
 * Edge data formats
 */
KEYWORD_EDGE_LIST edge_list
KEYWORD_ADJ_LIST  adj_list

/*
 * Node coordinates types
 */
KEYWORD_TWOD_COORDS twod_coords
KEYWORD_THREED_COORDS threed_coords
KEYWORD_NO_COORDS no_coords

/*
 * Display data types
 */
KEYRWORD_COORD_DISPLAY  coord_display
KEYWORD_TWOD_DISPLAY    twod_display
KEYWORD_NO_DISPLAY      no_display

SEPARATOR               ":"

KEYWORD_EOF eof

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

{INTEGER} {
    yylval->integerVal = atoi(yytext);
    return token::INTEGER;
}

{FLOAT} {
    yylval->doubleVal = atof(yytext);
    return token::DOUBLE;
}
<EXPECT_REST_OF_LINE_STRING>{SEPARATOR} {
    BEGIN(REST_OF_LINE_STRING);
    return token::KEY_VALUE_SEPARATOR;
}

{SEPARATOR} {
    #ifdef FLEX_SCANNER_DEBUG
        std::cout << "sep" << std::endl;
    #endif
    return token::KEY_VALUE_SEPARATOR;
}

{KEYWORD_NAME} {
    BEGIN(EXPECT_REST_OF_LINE_STRING);
    return token::NAME;
}

{KEYWORD_COMMENT} {
    BEGIN(EXPECT_REST_OF_LINE_STRING);
    return token::COMMENT;
}

{KEYWORD_NODE_COORD_TYPE} { return token::NODE_COORD_TYPE; }

{KEYWORD_TWOD_COORDS} {
    yylval->nodeCoordType = TSP::NODE_COORD_TYPE::TWO_D;
    return token::NODE_COORD_TYPE_LITERAL;
}

{KEYWORD_THREED_COORDS} {
    yylval->nodeCoordType = TSP::NODE_COORD_TYPE::THREE_D;
    return token::NODE_COORD_TYPE_LITERAL;
}

{KEYWORD_NO_COORDS} {
    yylval->nodeCoordType = TSP::NODE_COORD_TYPE::NONE;
    return token::NODE_COORD_TYPE_LITERAL;
}

{KEYWORD_NODE_COORD_SECTION} { return token::NODE_COORD_SECTION; }

{KEYWORD_DIMENSION} { return token::DIMENSION; }

{KEYWORD_TYPE} { return token::TYPE; }

{KEYWORD_TOUR} {
    yylval->tspType = TSP::TYPE::TOUR;
    return token::TSPTYPE;
}

{KEYWORD_TSP} {
    yylval->tspType = TSP::TYPE::TSP;
    return token::TSPTYPE;
}

{KEYWORD_ATSP} {
    yylval->tspType = TSP::TYPE::ATSP;
    return token::TSPTYPE;
}

{KEYWORD_GTSP} {
    yylval->tspType = TSP::TYPE::GTSP;
    return token::TSPTYPE;
}

{KEYWORD_AGTSP} {
    yylval->tspType = TSP::TYPE::AGTSP;
    return token::TSPTYPE;
}

{KEYWORD_GTSP_SETS} {
    return token::GTSP_SETS;
}

{KEYWORD_GTSP_SET_SECTION} {
    return token::GTSP_SET_SECTION;
}

{KEYWORD_EDGE_WEIGHT_TYPE} {
    return token::EDGE_WEIGHT_TYPE;
}

{KEYWORD_EDGE_WEIGHT_SECTION} {
    return token::EDGE_WEIGHT_SECTION;
}

{KEYWORD_EUC_2D} {
    yylval->edgeWeightType = TSP::EDGE_WEIGHT_TYPE::EUC_2D;
    return token::EDGE_WEIGHT_TYPE_LITERAL;
}
{KEYWORD_EUC_3D} {
    yylval->edgeWeightType = TSP::EDGE_WEIGHT_TYPE::EUC_3D;
    return token::EDGE_WEIGHT_TYPE_LITERAL;
}
{KEYWORD_EXPLICIT} {
    yylval->edgeWeightType = TSP::EDGE_WEIGHT_TYPE::EXPLICIT;
    return token::EDGE_WEIGHT_TYPE_LITERAL;
}

{KEYWORD_EDGE_WEIGHT_FORMAT} {
    return token::EDGE_WEIGHT_FORMAT;
}

{KEYWORD_EDGE_DATA_SECTION} {
    return token::EDGE_DATA_SECTION;
}
{KEYWORD_FULL_MATRIX} {
    yylval->edgeWeightFormat = TSP::EDGE_WEIGHT_FORMAT::FULL_MATRIX;
    return token::EDGE_WEIGHT_FORMAT_LITERAL;
}

 /* read the rest of the line as a single string */
<REST_OF_LINE_STRING>[[:^blank:]][^\n]+ {
    yylval->stringVal = new std::string(yytext, yyleng);
    #ifdef FLEX_SCANNER_DEBUG
        std::cout << "rest_of_line: " << *(yylval->stringVal) << std::endl;
    #endif

    BEGIN(INITIAL);
    return token::STRING;
}

 /* gobble up white-spaces */
{WHITESPACE} {
   #ifdef FLEX_SCANNER_DEBUG
    std::cout << "ws" << yytext << std::endl;
   #endif
   yylloc->step();
}

 /* gobble up end-of-lines */
\n {
    yylloc->lines(yyleng); yylloc->step();
    return token::EOL;
}

{KEYWORD_EOF} {
    return token::END;
}
 /* pass all other characters to bison */
[[:alnum:]_]* {
    yylval->stringVal = new std::string(yytext, yyleng);
    #ifdef FLEX_SCANNER_DEBUG
       std::cout << "UNMATCHED INPUT! " << yytext << std::endl;
    #endif
    std::stringstream err;
    err << "syntax error, unmatched input token: " << *yylval->stringVal;
    driver.error(err.str());
    return token::UNMATCHED_TOKEN;
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
