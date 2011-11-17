%{
// Authors: bpross@ucsc.edu, esteggal@ucsc.edu
// TA: Richard Halpert
// Professor: Wesley Mackey
// CMPS 104a
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"
#include "astree.rep.h"


#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYPRINT yyprint
#define YYMALLOC yycalloc

static void *yycalloc (size_t size);

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%token TOK_ROOT TOK_TYPEID TOK_FIELD TOK_INDEX TOK_POS 
%token TOK_NEG TOK_CALL TOK_NEWARRAY TOK_NEWSTRING TOK_IFELSE
%token TOK_RETURNVOID TOK_BLOCK TOK_VARDECLINIT TOK_FUNCTION
%token TOK_PARAMLIST TOK_PROTOTYPE TOK_WHILE
%token TOK_IDENT TOK_CHARCON TOK_INTCON TOK_STRINGCON 
%token TOK_NEW TOK_NULL TOK_STRING TOK_STRUCT 
%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_RETURN
%token TOK_FALSE TOK_TRUE TOK_LE TOK_GE

%right    TOK_IF TOK_ELSE
%right    '='
%left     TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left     '+' '-'
%left     '*' '/' '%'
%right    TOK_POS TOK_NEG '!' TOK_CHAR
%left    '[' ']' '.' '(' ')'

%start start


%%

start       : program   { $$ = $1; }
            ;

program     : program structdef   { $$ = adopt1 ($1, $2); } 
            | program statement   { $$ = adopt1 ($1, $2); } 
            | program error '}'   { $$ = adopt1 ($$, $1); } 
            | program error ';'   { $$ = adopt1 ($$, $1); } 
            |                     { $$ = new_parseroot (); } 
            ;

structdef   : TOK_STRUCT TOK_IDENT '{' identdecls '}' { freeast2($3,$5); $2 = adoptsym($2,TOK_TYPEID); $$ = adopt2($1, $2, $4);}
            ;

identdecls  : identdecl ';'        { freeast($2); $$ = $1;  }
            | identdecls identdecl ';' { freeast($3); $$ = adopt1($1, $2) ; }
            ;

identdecl   : basetype TOK_NEWARRAY TOK_IDENT { $$ = adopt2($1, $2, $3); }
            | basetype TOK_IDENT      { $$ = adopt1($1, $2); }
            ;

basetype    : TOK_VOID     { $$ = $1; }
            | TOK_BOOL     { $$ = $1; }
            | TOK_CHAR     { $$ = $1; }
            | TOK_INT      { $$ = $1; }
            | TOK_STRING   { $$ = $1; }
            | TOK_TYPEID   { $$ = $1; }
            | TOK_IDENT    { $$ = $1; }
            ;

block       : '{' state_list '}'            {freeast($3); $$ = adopt1sym($1,$2,TOK_BLOCK); }
            | '{' '}'                       {freeast($2); $$ = adopt1sym($$,$1,TOK_BLOCK); } 
            | ';'                           {$$ = adoptsym($1,TOK_BLOCK);}
            ;

state_list  : state_list statement     {$$ = adopt1($1, $2); }
            | statement                {$$ = $1; }
            ;

statement   : block               { $$ = $1; }
            | vardeclinit         { $$ = $1; }
            | whilehead               { $$ = $1;} 
            | ifelse              { $$ = $1; }
            | returnhead              { $$ = $1; }
            | expr ';'            { freeast($2); $$ = $1; }
            ;

vardeclinit : identdecl '=' expr ';' { freeast($4); $$ = adopt2($2, $1, $3) ; }
            ;

whilehead   : TOK_WHILE '(' expr ')' statement { freeast2($2, $4); $$ = adopt2($1, $3, $5) ;}
            ;

ifelse      : TOK_IF '(' expr ')' statement TOK_ELSE statement { freeast($6); $$ = adopt3sym($1,$2,$5,$7,TOK_IFELSE);}
            | TOK_IF '(' expr ')' statement {freeast2($2, $4); $$ = adopt2($1, $3, $5); }
            ;

returnhead  : TOK_RETURN ';'        { $$ = adopt1sym($1,$2, TOK_RETURNVOID) ; }
            | TOK_RETURN expr ';'   { freeast($3);  $$ = adopt1($1, $2) ; }
            ;

expr        : expr '+' expr { $$ = adopt2($2,$1,$3); }
            | '+' expr %prec TOK_POS { $$ = adopt1sym($1, $2, TOK_POS); }
            | expr '-' expr { $$ = adopt2($2,$1,$3); }
            | '-' expr %prec TOK_NEG { $$ = adopt1sym($1, $2, TOK_NEG); }
            | expr '=' expr          { $$ = adopt2($2,$1,$3); }
            | expr TOK_EQ expr       { $$ = adopt2($2,$1,$3); }
            | expr TOK_NE expr       { $$ = adopt2($2,$1,$3); }
            | expr '<' expr          { $$ = adopt2($2,$1,$3); }
            | expr '>' expr          { $$ = adopt2($2,$1,$3); }
            | expr TOK_LE expr       { $$ = adopt2($2,$1,$3); }
            | expr TOK_GE expr       { $$ = adopt2($2,$1,$3); }
            | expr '.' expr          { $$ = adopt2($2,$1,$3); } 
            | expr '*' expr          { $$ = adopt2($2,$1,$3); }
            | allocator              { $$ = $1 ; }
            | call                   { $$ = $1 ; }
            | variable               { $$ = $1 ; }
            | constant               { $$ = $1 ; }
            | '(' expr ')'           { freeast2($1,$3); $$ = $2; }
            ;

allocator   : TOK_NEW TOK_IDENT '('')' { freeast2($3,$4); $2 = adoptsym($2, TOK_TYPEID); $$ = adopt1($1, $2) ;}
            | TOK_NEW TOK_STRING '(' expr ')' { freeast2($3,$5); $$ = adopt1sym($1,$4,TOK_NEWSTRING); }
            | TOK_NEW basetype '[' expr ']' { freeast2($3,$5); $$ = adopt2sym($1,$2,$4,TOK_NEWARRAY); }
            ;

call        : TOK_IDENT call_list ')' { freeast($3); $$ = adopt1sym($2, $1, TOK_CALL); }
            | TOK_IDENT '(' ')'       { freeast($3); $$ = adopt1sym($2, $1, TOK_CALL); }
            ;

call_list   :  call_list ',' expr      { freeast($2); $$ = adopt1($1, $2) ; }
            | '(' expr                 { $$ = adopt1($1,$2); }
            ;

variable    : TOK_IDENT        { $$ = $1; }
            | expr '[' expr ']'  { freeast2($2, $4); $$ = adopt1($1, $3) ; }
            | expr '.'          { freeast($2); $$ = $1; }
            | TOK_FIELD         { $$ = $1; }
            ;

constant    : TOK_INTCON      { $$ = $1 ; }
            | TOK_CHARCON     { $$ = $1 ; }
            | TOK_STRINGCON   { $$ = $1 ; }
            | TOK_FALSE         { $$ = $1 ; }
            | TOK_TRUE          { $$ = $1 ; }
            | TOK_NULL          { $$ = $1 ; }
            ;

%%

const char *get_yytname (int symbol) {
    return yytname [YYTRANSLATE (symbol)];
}

static void *yycalloc (size_t size) {
   void *result = calloc (1, size);
   assert (result != NULL);
   return result;
}

