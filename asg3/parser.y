// Authors: bpross@ucsc.edu, esteggal@ucsc.edu
// TA: Richard Halpert
// Professor: Wesley Mackey
// CMPS 104a
%{
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

%right    TOK_IF TOK_ELSE
%right    '='
%left     TOK_EQ TOK_NE '<' TOK_LT '>' TOK_GT TOK_GE
%left     '+' '-'
%left     '*' '/' '%'
%right    '^'
%right    TOK_POS TOK_NEG '!'

%start start


%%

start       : program             { yyparse_astree = $1; }
            ;
program     : program structdef   { $$ = adopt1 ($1, $2); } 
            | program function    { $$ = adopt1 ($1, $2); } 
            | program statement   { $$ = adopt1 ($1, $2); } 
            | program error '}'   { $$ = adopt1 ($$, $1); } 
            | program error ';'   { $$ = adopt1 ($$, $1); } 
            |                     { $$ = new_parseroot (); } 
            ;

structdef   : TOK_STRUCT TOK_TYPEID identdecls '}' { freeast($4); $$ = adopt1($1, $2, $3); }
            ;

identdecls  : identdecls identdecl ';' { freeast($3); $$ = adopt1($1, $2) ; }
            | '{' identdecl ';'        { freeast2($1, $3); $$ = $2;  }
            ;

identdecl   : basetype TOK_NEWARRAY TOK_IDENT { $$ = adopt2($1, $2, $3); }
            | basetype TOK_IDENT      { $$ = adopt1($1, $2); }
            ;

basetype    : 'void'     { $$ = $1; }
            | 'bool'     { $$ = $1; }
            | 'char'     { $$ = $1; }
            | 'int'      { $$ = $1; }
            | 'string'   { $$ = $1; }
            | TOK_TYPEID { $$ = $1; }
            ;

function    : identdecl paramlist ')' ';'   { freeast($3); $$ = adopt2(TOK_PROTOTYPE, $1, $2) ; }
            | identdecl paramlist ')' block { $$ = adopt3(TOK_FUNCTION, $1, $2, $3); }
            ;

paramlist   : '(' params                               { $$ = adopt1(TOK_PARAMLIST,$1); }
            ;

params      : params ',' identdecl           {freeast($2); adopt1($1, $3); }
            | identdecl                      {$$ = $1;}
            ;

block       : '{' state_list '}'            {freeast2($1, $3); $$ = adopt1(TOK_BLOCK,$2); }
            | '{' '}'                       {freeast2($1, $2); $$ = TOK_BLOCK}
            | ';'                           {freeast1($1); $$ = TOK_BLOCK}
            ;

state_list  : state_list statement     {$$ = adopt1($1, $2); }
            | statement                {$$ = $1; }
            ;

statement   : block               { $$ = $1; }
            | vardeclinit         { $$ = $1; }
            | while               { $$ = $1; } 
            | ifelse              { $$ = $1; }
            | return              { $$ = $1; }
            | expr ';'            { freeast($2); $$ = $1; }
            ;

vardeclinit : identdecl '=' expr ';' { freeast($4); adopt2($2, $1, $3) ; }
            ;

while       : TOK_WHILE '(' expr ')' statement { freeast3($1, $2, $4); adopt2($1, $3, $5) ;}
            ;

ifelse      : TOK_IF '(' expr ')' statement {freeast3($1, $2, $4); $$ = adopt2($1, $3, $5); }
            | TOK_IF '(' expr ')' statement 'else' statement { freeast4($1,$2,$4,$6); $$ = adopt3(TOK_IFELSE, $3, $5, $7); }
            ;



return      : 'return' ';'        { adopt1($1, TOK_RETURNVOID) ; }
            | 'return' expr ';'   { adopt1($1, $2) ; }
            ;

expr        : expr '+' expr { adopt1sym($1, $2, $3); }
            | '+' expr %prec TOK_POS { adopt1sym($1, $2, TOK_POS); }
            | expr '-' expr { adopt1sym($1, $2, $3); }
            | '-' expr %prec TOK_NEG { adopt1sym($1, $2, TOK_NEG); }
            | allocator              { $$ = $1 ; }
            | call                   { $$ = $1 ; }
            | variable               { $$ = $1 ; }
            | constant               { $$ = $1 ; }
            | '(' expr ')'           { freeast2($1,$3); $$ = $2; }
            ;
              
allocator   : TOK_NEW TOK_TYPEID '('')' { freeast3($1,$3,$4); adopt1($1, $2) ;}
            | TOK_NEW TOK_STRING '(' expr ')' { freeast4($1,$2,$3,$5); adopt1(TOK_NEWSTRING, $4); }
            | TOK_NEW basetype '[' expr ']' { freeast3($1,$3,$5); adopt2(TOK_NEWARRAY, $2, $4};
            ;

call        : TOK_IDENT call_list ')' { freeast($3); $$ = adopt1sym($2, $1, TOK_CALL); }
            ;

call_list   :  call_list ',' expr      { freeast($2); $$ = adopt1($1, $2) ; }
            | '(' expr                 { freeast($1); $$ = adopt1($1,$2); }
            ;

variable    : TOK_IDENT        { $$ = $1; }
            | expr '[' expr ']'  { freeast2($2, $4); $$ = adopt1($1, $3) ; }
            | expr '.'          { freeast($2); $$ = $1; }
            | TOK_FIELD         { $$ = $1; }
            ;

constant    : TOK_INTCON      { $$ = $1 ; }
            | TOK_CHARCON     { $$ = $1 ; }
            | TOK_STRINGCON   { $$ = $1 ; }
            | 'false'         { $$ = $1 ; }
            | 'true'          { $$ = $1 ; }
            | 'null'          { $$ = $1 ; }
            ;

%%

const char *get_yytname (int symbol) {
    return yytname [YYTRANSLATE (symbol)];
}
