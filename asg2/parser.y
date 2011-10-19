%{
// $Id: parser.y,v 1.6 2011-08-31 17:54:03-07 - - $

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

%token  ROOT IDENT NUMBER

%right  '='
%left   '+' '-'
%left   '*' '/'
%right  '^'
%right  POS "u+" NEG "u-"

%start  program

%%

program : stmtseq               { $$ = $1; }
        ;

stmtseq : stmtseq expr ';'      { freeast ($3); $$ = adopt1 ($1, $2); }
        | stmtseq error ';'     { freeast ($3); $$ = $1; }
        | stmtseq ';'           { freeast ($2); $$ = $1; }
        |                       { $$ = new_parseroot(); }
        ;

expr    : expr '=' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '+' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '-' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '*' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '/' expr         { $$ = adopt2 ($2, $1, $3); }
        | expr '^' expr         { $$ = adopt2 ($2, $1, $3); }
        | '+' expr %prec POS    { $$ = adopt1sym ($1, $2, POS); }
        | '-' expr %prec NEG    { $$ = adopt1sym ($1, $2, NEG); }
        | '(' expr ')'          { freeast2 ($1, $3); $$ = $2; }
        | IDENT                 { $$ = $1; }
        | NUMBER                { $$ = $1; }
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

// LINTED(static unused)
RCSC(PARSER_Y,"$Id: parser.y,v 1.6 2011-08-31 17:54:03-07 - - $")

