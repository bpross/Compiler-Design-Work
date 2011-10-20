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
MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)
NUMBER          ({MANTISSA}{EXPONENT}?)
NOTNUMBER       ({MANTISSA}[Ee][+-]?)
IDENT           ({LETTER}({LETTER}|{DIGIT})*)

%%

"#".*           { scanner_include(); }
[ \t]+          { IGNORE (white space) }
\n              { scanner_newline(); }

{NUMBER}        { return yylval_token (NUMBER); }
{IDENT}         { return yylval_token (IDENT); }
{ROOT}          { return yylval_token (ROOT); }


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
"[]"            { return yylval_token (TOK_NEWARRAY); }
"=="            { return yylval_token (TOK_EQ); }
"!="            { return yylval_token (TOK_NE); }
"<"             { return yylval_token (TOK_LT); }
">"             { return yylval_token (TOK_GT); }
"<="            { return yylval_token (TOK_LE); }
">="            { return yylval_token (TOK_GE); }


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


{NOTNUMBER}     { scanner_badtoken (yytext);
                  return yylval_token (NUMBER); }

.               { scanner_badchar (*yytext); }

%%

// unset: %option noyywrap
int yywrap (void){
   yy_delete_buffer (YY_CURRENT_BUFFER);
   if (yy_flex_debug) eprintf ("yywrap() return %d\n", TRUE);
   return TRUE;
}

// LINTED(static unused)
RCSC(SCANNER_L,"$Id: scanner.l,v 1.6 2011-08-31 18:10:49-07 - - $")

