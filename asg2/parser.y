/* $Id: parser.y,v 1.1 2011-08-31 19:28:12-07 - - $

/*
* Prototype parser for c0 for use in assignment 2 (the scanner).
*
* To use this file, copy it into your directory then translate it
* into C with the command:
*
*    bison -dtv parser.y -o parser.c
*
* Generated files are:
*
*    parser.h - a header file containing the #define symbols that
*       you need to use with your scanner.  Note that this file must
*       be included AFTER the file typedefing YYSTYPE.
*
*    parser.c - a parser for the grammar, which you will not really
*       want to examine in a lot of detail and should be treated as
*       a machine code file.  This will need to be linked into your
*       code.
*
* In project 3, you will discard this file and replace it with the
* parser that you write.
*
*/

%token  TOK_IDENT TOK_ARRAY
%token  TOK_CHAR_LIT TOK_INT_LIT TOK_STRING_LIT
%token  TOK_WHILE TOK_IF TOK_ELSE TOK_RETURN TOK_NEW
%token  TOK_VOID TOK_BOOL TOK_CHAR TOK_INT
%token  TOK_STRUCT TOK_STRING TOK_UNCHECKED_TYPE
%token  TOK_FALSE TOK_TRUE TOK_NULL
%token  TOK_EQ TOK_NE TOK_GT TOK_GE TOK_LT TOK_LE

%start program

%%

program : program token
        |
        ;

token   : TOK_IDENT
        | TOK_BOOL_LIT
        | TOK_CHAR_LIT
        | TOK_INT_LIT
        | TOK_STRING_LIT
        | TOK_CHAR
        | TOK_WHILE
        | TOK_IF
        | TOK_ELSE
        | TOK_RETURN
        | TOK_NEW
        | TOK_VOID
        | TOK_BOOL
        | TOK_CHAR
        | TOK_INT
        | TOK_STRUCT
        | TOK_STRING
        | TOK_UNCHECKED_TYPE
        | TOK_FALSE
        | TOK_TRUE
        | TOK_NULL
        | '('
        | ')'
        | '['
        | ']'
        | '{'
        | '}'
        | ':'
        | ';'
        | ','
        | '='
        | TOK_EQ
        | TOK_NE
        | TOK_GT
        | TOK_GE
        | TOK_LT
        | TOK_LE
        | '+'
        | '-'
        | '*'
        | '/'
        | '%'
        | '.'
        | '!'
        | '@'
        ;

%%

const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

