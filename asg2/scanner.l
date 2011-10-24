// I have all my comments like this
%{
// $Id: scanner.l,v 1.6 2011-08-31 18:10:49-07 - - $

#include <stdlib.h>

#include "auxlib.h"
#include "lyutils.h"

#define YY_USER_ACTION  { scanner_useraction (); }
#define IGNORE(THING)   { }

%}

%option 8bit
%option backup
%option debug
%option ecs
%option nodefault
%option nounput
%option perf-report
%option verbose


LETTER          [A-Za-z_]
DIGIT           [0-9]
TOK_INT         ({DIGIT}+)
TOK_IDENT       ({LETTER}({LETTER}|{DIGIT})*)
TOK_NEWARRAY    \[\]
TOK_EQ          ==
TOK_NE          !=
TOK_LE          <=
TOK_GE          >=


%%

"#".*           { scanner_include(); }
[ \t]+          { IGNORE (white space) }
\n              { scanner_newline(); }


{TOK_INT}       { return yylval_token (TOK_INT); }
{TOK_IDENT}     { return yylval_token (TOK_IDENT); }
{TOK_NEWARRAY}  { return yylval_token (TOK_NEWARRAY); }
{TOK_EQ}  { return yylval_token (TOK_EQ); }
{TOK_NE}  { return yylval_token (TOK_NE); }
{TOK_LE}  { return yylval_token (TOK_LE); }
{TOK_GE}  { return yylval_token (TOK_GE); }


"="             { return yylval_token ('='); }
"+"             { return yylval_token ('+'); }
"-"             { return yylval_token ('-'); }
"*"             { return yylval_token ('*'); }
"/"             { return yylval_token ('/'); }
"^"             { return yylval_token ('^'); }
"("             { return yylval_token ('('); }
")"             { return yylval_token (')'); }
";"             { return yylval_token (';'); }
"["             { return yylval_token ('['); }
"]"             { return yylval_token (']'); }
","             { return yylval_token (','); }
"."             { return yylval_token ('.'); }
"!"             { return yylval_token ('!'); }
"{"             { return yylval_token ('{'); }
"}"             { return yylval_token ('}'); }
"<"             { return yylval_token (TOK_LT); }
">"             { return yylval_token (TOK_GT); }
"void"          { return yylval_token (TOK_VOID); }
"bool"          { return yylval_token (TOK_BOOL); }
"char"          { return yylval_token (TOK_CHAR); }
"int"           { return yylval_token (TOK_INT); }
"string"        { return yylval_token (TOK_STRING); }
"struct"        { return yylval_token (TOK_STRUCT); }
"if"            { return yylval_token (TOK_IF); }
"else"          { return yylval_token (TOK_ELSE); }
"while"         { return yylval_token (TOK_WHILE); }
"return"        { return yylval_token (TOK_RETURN); }
"false"         { return yylval_token (TOK_FALSE); }
"true"          { return yylval_token (TOK_TRUE); }
"null"          { return yylval_token (TOK_NULL); }
"new"           { return yylval_token (TOK_NEW); }



.               { scanner_badchar (*yytext); }

%%

// unset: %option noyywrap
int yywrap (void){
   yy_delete_buffer (YY_CURRENT_BUFFER);
   if (yy_flex_debug) eprintf ("yywrap() return %d\n", TRUE);
   return TRUE;
}


