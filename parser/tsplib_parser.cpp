// A Bison parser, made by GNU Bison 3.0.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 4 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:398
 /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>


#line 43 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "tsplib_parser.hpp"

// User implementation prologue.
#line 117 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:406


#include "tsplib_driver.h"
#include "tsplib_lexer.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 69 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:406


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 38 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:473
namespace TSPLIB {
#line 155 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:473

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 6: // "string"

#line 112 "..\..\..\cph-tsp\parser\parser\tsplib.y" // lalr1.cc:598
        { delete (yysym.value.stringVal); }
#line 374 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:598
        break;

      case 31: // coord_section

#line 112 "..\..\..\cph-tsp\parser\parser\tsplib.y" // lalr1.cc:598
        { delete (yysym.value.coordMap); }
#line 381 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:598
        break;

      case 32: // coords

#line 112 "..\..\..\cph-tsp\parser\parser\tsplib.y" // lalr1.cc:598
        { delete (yysym.value.coordList); }
#line 388 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:598
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 46 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:726
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 527 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:726

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* If YYLEN is nonzero, implement the default value of the action:
       '$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYLHS.VALUE to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yylhs.value = yystack_[yylen - 1].value;
    else
      yylhs.value = yystack_[0].value;

    // Compute the default @$.
    {
      slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
      YYLLOC_DEFAULT (yylhs.location, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    try
      {
        switch (yyn)
          {
  case 2:
#line 135 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        (yylhs.value.stringVal) = (yystack_[0].value.stringVal);
    }
#line 641 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 3:
#line 139 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        // Found a field separator
    }
#line 649 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 4:
#line 141 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        // Separator is optional
    }
#line 657 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 5:
#line 145 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        (yylhs.value.integerList) = new std::vector<int>();
        (yylhs.value.integerList)->push_back((yystack_[0].value.doubleVal));
    }
#line 666 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 6:
#line 149 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        (yylhs.value.integerList) = (yystack_[2].value.integerList);
        (yystack_[2].value.integerList)->push_back((yystack_[1].value.doubleVal));
    }
#line 675 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 7:
#line 153 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        (yylhs.value.integerList) = (yystack_[1].value.integerList);
        (yystack_[1].value.integerList)->push_back((yystack_[0].value.doubleVal));
    }
#line 684 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 8:
#line 158 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        (yylhs.value.coordMap) = new std::map<int, std::vector<double>>();
        (*(yylhs.value.coordMap))[(yystack_[2].value.integerVal)] = *(yystack_[1].value.coordList);
    }
#line 693 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 9:
#line 162 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        (yylhs.value.coordMap) = (yystack_[3].value.coordMap);
        (*(yylhs.value.coordMap))[(yystack_[2].value.integerVal)] = *(yystack_[1].value.coordList);
    }
#line 702 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 10:
#line 167 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        (yylhs.value.coordList) = new std::vector<double>();
        (yylhs.value.coordList)->push_back((yystack_[0].value.doubleVal));
    }
#line 711 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 11:
#line 171 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        (yylhs.value.coordList) = (yystack_[1].value.coordList);
        (yystack_[1].value.coordList)->push_back((yystack_[0].value.doubleVal));
    }
#line 720 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 13:
#line 176 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    { (yylhs.value.doubleVal) = (yystack_[0].value.integerVal);}
#line 726 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 18:
#line 185 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
       driver.get_instance().set_name(*(yystack_[0].value.stringVal));
    }
#line 734 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 19:
#line 188 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        driver.get_instance().set_comment(*(yystack_[0].value.stringVal));
    }
#line 742 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 20:
#line 191 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        driver.create_instance((yystack_[0].value.tspType));
    }
#line 750 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 21:
#line 194 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        driver.get_tsp_instance().set_edge_weight_type((yystack_[0].value.edgeWeightType));
    }
#line 758 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 22:
#line 197 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        driver.get_tsp_instance().set_edge_weight_format((yystack_[0].value.edgeWeightFormat));
    }
#line 766 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 23:
#line 200 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        driver.get_tsp_instance().set_node_coordinate_type((yystack_[0].value.nodeCoordType));
    }
#line 774 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 24:
#line 203 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        driver.get_tsp_instance().set_dimension((yystack_[0].value.integerVal));
    }
#line 782 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 25:
#line 206 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        // ignore for now
    }
#line 790 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 26:
#line 212 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        TSPLIB::BaseInstance & instance = driver.get_tsp_instance();
        instance.set_node_coordinate_section(* (yystack_[0].value.coordMap));
    }
#line 799 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 27:
#line 216 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        TSPLIB::BaseInstance & instance = driver.get_tsp_instance();
        instance.set_node_coordinate_section(* (yystack_[0].value.coordMap));
    }
#line 808 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 28:
#line 220 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
     driver.get_tsp_instance().set_edge_weights(*(yystack_[0].value.integerList));
    }
#line 816 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 29:
#line 223 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
     driver.get_tsp_instance().set_edge_weights(*(yystack_[0].value.integerList));
    }
#line 824 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 30:
#line 226 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        driver.get_gtsp_instance().set_gtsp_cluster_amount((yystack_[0].value.integerVal));
    }
#line 832 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;

  case 31:
#line 230 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:846
    {
        driver.get_gtsp_instance().set_gtsp_clusters(*(yystack_[0].value.integerList));
    }
#line 840 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
    break;


#line 844 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:846
          default:
            break;
          }
      }
    catch (const syntax_error& yyexc)
      {
        error (yyexc);
        YYERROR;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yylhs);
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    // Shift the result of the reduction.
    yypush_ (YY_NULL, yylhs);
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -49;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -49,    31,   -49,   -49,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,    27,   -49,   -49,    14,
      17,    14,    28,    25,    16,    18,    19,    29,     9,    28,
      27,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
      28,    11,    28,   -49,   -49,   -49,   -49,   -49,    11,   -49,
     -49,   -49,    11,   -49,    11,    11,     9,   -49,    28,    27,
      11,    11,     9,   -49,   -49,   -49,   -49
  };

  const unsigned char
  Parser::yydefact_[] =
  {
      32,     0,     1,    33,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,    35,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    16,    34,     2,    18,    20,    19,    15,    24,
      27,     0,     0,    23,    21,    22,    25,    14,    29,     5,
      12,    13,     0,    30,     0,     0,     0,    10,    26,     7,
      28,    31,     0,    11,     8,     6,     9
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -49,    32,    53,   -48,     8,    -3,   -38,   -49,   -21,   -23,
     -49,   -49,   -49
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    35,    19,    48,    40,    56,    49,    50,    51,    33,
      16,    17,     1
  };

  const unsigned char
  Parser::yytable_[] =
  {
      42,    39,    41,    57,    60,    52,    61,    54,    53,    31,
      59,    18,    32,    38,    47,    38,    47,    57,    63,    55,
      34,    41,    59,    59,    63,    31,    36,    31,    32,    38,
      32,     2,    38,    64,     3,    43,    65,    55,    44,    66,
      45,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      58,    46,    62,    37,     0,    13,    14,    15,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30
  };

  const signed char
  Parser::yycheck_[] =
  {
      23,    22,    23,    41,    52,    28,    54,    30,    29,     0,
      48,     7,     3,     4,     5,     4,     5,    55,    56,    40,
       6,    42,    60,    61,    62,     0,     9,     0,     3,     4,
       3,     0,     4,    56,     3,    19,    59,    58,    20,    62,
      21,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      42,    22,    55,    21,    -1,    24,    25,    26,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    39,     0,     3,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    24,    25,    26,    37,    38,     7,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,     0,     3,    36,     6,    28,     9,    28,     4,    35,
      31,    35,    36,    19,    20,    21,    22,     5,    30,    33,
      34,    35,    36,    35,    36,    35,    32,    33,    31,    33,
      30,    30,    32,    33,    36,    36,    36
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    27,    28,    29,    29,    30,    30,    30,    31,    31,
      32,    32,    33,    33,    34,    35,    36,    36,    37,    37,
      37,    37,    37,    37,    37,    37,    38,    38,    38,    38,
      38,    38,    39,    39,    39,    39
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     0,     1,     3,     2,     3,     4,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     4,     3,
       3,     4,     0,     2,     3,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"integer\"", "\"double\"", "\"string\"", "\"key-value separator\"",
  "\"unmatched input token\"", "TSPTYPE", "NAME", "TYPE", "COMMENT",
  "DIMENSION", "NODE_COORD_SECTION", "NODE_COORD_TYPE", "EDGE_WEIGHT_TYPE",
  "EDGE_WEIGHT_FORMAT", "DISPLAY_DATA_TYPE", "NODE_COORD_TYPE_LITERAL",
  "EDGE_WEIGHT_TYPE_LITERAL", "EDGE_WEIGHT_FORMAT_LITERAL",
  "DISPLAY_DATA_TYPE_LITERAL", "EDGE_DATA_SECTION", "EDGE_WEIGHT_SECTION",
  "GTSP_SETS", "GTSP_SET_SECTION", "$accept", "string_value", "separator",
  "integer_list", "coord_section", "coords", "number", "real", "integer",
  "end", "specification", "data", "start", YY_NULL
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   135,   135,   139,   141,   145,   149,   153,   158,   162,
     167,   171,   176,   176,   178,   180,   182,   182,   185,   188,
     191,   194,   197,   200,   203,   206,   212,   216,   220,   223,
     226,   229,   234,   235,   236,   237
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
    };
    const unsigned int user_token_number_max_ = 281;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 38 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:1156
} // TSPLIB
#line 1304 "..\\..\\..\\cph-tsp\\parser\\parser/tsplib_parser.cpp" // lalr1.cc:1156
#line 241 "..\\..\\..\\cph-tsp\\parser\\parser\\tsplib.y" // lalr1.cc:1157
 /*** Additional Code ***/

void TSPLIB::Parser::error(const Parser::location_type& l,
                const std::string& m)
{
    driver.error(l, m);
}

