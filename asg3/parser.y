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
%right    TOK_POS "u+" TOK_NEG "u-"

%start start


%%

start       : program        { yyparse_astree = $1; }
            ;
program     : program structdef { $$ = adopt1 ($1, $2); } 
            | program function { $$ = adopt1 ($1, $2); } 
            | program statement { $$ = adopt1 ($1, $2); } 
            | program error '}' { $$ = adopt1 ($$, $1); } 
            | program error ';' { $$ = adopt1 ($$, $1); } 
            |                   { $$ = new_parseroot (); } 
            ;
structdef   : structdef struct TOK_TYPEID '{' { adopt2 ($2, $1, $3); }
            | structdef indentdecl';' 
            | structdef '}' { adopt1($1, $2); }
            ;
identdecl   : identdecl basetype '[]' TOK_IDENT {adopt2($2, $1, $3); }
            | identdecl basetype TOK_IDENT {adopt1($1, $2); }
            ;
basetype    : basetype 'void'
            | basetype 'bool'
            | basetype 'char'
            | basetype 'int'
            | basetype 'string'
            | basetype TOK_TYPEID
            ;
function    : function identdecl '(' TOK_PARAMLIST 
            | function block
            | TOK_PROTOTYPE identdecl';'
            | TOK_FUNCTION identdecl'{'
            ;
paramlist   : paramlist '(' identdecl
            | paramlist ',' identdecl
            | paramlist '(' identdecl
            | paramlist ')' identdecl
            ;
block       : block '{' statement 
            | block statement
            | '}'
            | '{' '}'
            | ';'
            ;
statement   : statement block
            | statement vardeclinit
            | statement while 
            | statement elseif 
            | statement return
            | statement expr ';'
            ;
vardeclinit : identdecl '=' expr ';'
            ;

while       : while 'while' '(' expr ')' stmt
            ;

ifelse      : ifelse 'if' '(' expr ')' stmt
            | ifelse 'if' '(' expr ')' stmt 'else' stmt
            ;

return      : 'return' ';'
            | 'return' expr ';'
            ;

expr        : expr BINOP expr
            | UNOP expr
            | allocator
            | call
            | variable
            | constant
            | '(' expr ')'
            ;
              
allocator   : 'new' TOK_TYPEID '('')'
            | 'new string' '(' expr ')'
            | 'new' basetype '[' expr ']'
            ;

call        : call TOK_IDENT '(' 
            | call expr
            | call ',' expr
            | ')'
variable    : TOK_IDENT
            | expr '[' expr ']' 
            | expr '.' 
            | TOK_FIELD
constant    : TOK_INTCON
            | TOK_CHARCON
            | TOK_STRING
            | 'false'
            | 'true'
            | 'null'
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
