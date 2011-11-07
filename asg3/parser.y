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
%token TOK_PARAMLIST TOK_PROTOTYPE

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

structdef   : struct TOK_TYPEID identdecls '}' { $$ = adopt1 ($1, $2); }
            ;

identdecls  : '{' identdecl ';'        { $$ = adopt1($1, $2);  }
            | identdecls identdecl ';' { $$ = adopt1($1, $2) ; }
            ;

identdecl   : basetype '[]' TOK_IDENT {adopt2($1, $2, $3); }
            | basetype TOK_IDENT      {adopt1($1, $2); }
            ;

basetype    : 'void'     { $$ = $1; }
            | 'bool'     { $$ = $1; }
            | 'char'     { $$ = $1; }
            | 'int'      { $$ = $1; }
            | 'string'   { $$ = $1; }
            | TOK_TYPEID { $$ = $1; }
            ;

function    : TOK_FUNCTION identdecl '(' 
            | identdecl ')' block
            | function ',' identdecl       { adopt2
            | block                        { $$ = $1 ; }
            | TOK_PROTOTYPE identdecl';'
            ;

block       : block '{' statement {$$ = adopt2($1,$2,$3); }
            | block statement     {$$ = adopt1($1,$2); }
            | block '}'           {$$ = adopt1($1,$2); }
            | block '{' '}'       {$$ = adopt2($1,$2,$3); }
            | block ';'           {$$ = adopt1($1,$2); }
            ;

statement   : block               { $$ = $1; }
            | vardeclinit         { $$ = $1; }
            | while               { $$ = $1; } 
            | elseif              { $$ = $1; }
            | return              { $$ = $1; }
            | expr ';'            { $$ = $1; }
            ;
vardeclinit : identdecl '=' expr ';' { adopt2($2, $1, $3) ; }
            ;

while       : 'while' '(' expr ')' stmt { adopt2($4, $1, $5) ;}
            ;

ifelse      : ifelse 'if' '(' expr ')' stmt
            | ifelse 'if' '(' expr ')' stmt 'else' stmt
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
            | '(' expr ')'           { $$ = $2 ' }
            ;
              
allocator   : 'new' TOK_TYPEID '('')' { adopt1(TOK_NEW, $2) ;}
            | 'new' string '(' expr ')' { adopt1(TOK_NEWSTRING, $4) ; }
            | 'new' basetype '[' expr ']'
            ;

call        : TOK_IDENT expr '(' { adopt1sym($2, $1, TOK_CALL) ; }
            | TOK_IDENT '(' ')'  { adopt1sym($2, $1, TOK_CALL) ; }
            | call ',' expr
            | expr
            ;

args

variable    : TOK_IDENT
            | expr '[' expr ']' 
            | expr '.' 
            | TOK_FIELD
            ;

constant    : TOK_INTCON      { $$ = $1 ; }
            | TOK_CHARCON     { $$ = $1 ; }
            | TOK_STRING      { $$ = $1 ; }
            | 'false'         { $$ = $1 ; }
            | 'true'          { $$ = $1 ; }
            | 'null'          { $$ = $1 ; }
            ;
/*
token   : '(' | ')' | '[' | ']' | '{' | '}' | ';' | ',' | '.'
        | '=' | '+' | '-' | '*' | '/' | '%' | '!' 
        | TOK_VOID | TOK_BOOL | TOK_CHAR | TOK_INT | TOK_STRING
        | TOK_IF | TOK_ELSE | TOK_WHILE | TOK_RETURN | TOK_STRUCT
        | TOK_FALSE | TOK_TRUE | TOK_NULL | TOK_NEW | TOK_ARRAY
        | TOK_EQ | TOK_NE | TOK_LT | TOK_LE | TOK_GT | TOK_GE
        | TOK_IDENT | TOK_INTCON | TOK_CHARCON | TOK_STRINGCON
        ;
*/

%%

const char *get_yytname (int symbol) {
    return yytname [YYTRANSLATE (symbol)];
}
