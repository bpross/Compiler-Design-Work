// Authors: bpross@ucsc.edu, esteggal@ucsc.edu
// TA: Richard Halpert
// Professor: Wesley Mackey
// CMPS 104a
%{

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
CHAR_CONST	(’([^\\’\n]|\\[\\’"0nt])’)
STR_CONST	(\"([^\\"\n]|\\[\\’"0nt])*\")
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
[ \n]?           { scanner_newline(); }


"void"          { return yyprint_token (TOK_VOID); }
"bool"          { return yyprint_token (TOK_BOOL); }
"char"          { return yyprint_token (TOK_CHAR); }
"int"           { return yyprint_token (TOK_INT); }
"string"        { return yyprint_token (TOK_STRING); }
"struct"        { return yyprint_token (TOK_STRUCT); }
"if"            { return yyprint_token (TOK_IF); }
"else"          { return yyprint_token (TOK_ELSE); }
"while"         { return yyprint_token (TOK_WHILE); }
"return"        { return yyprint_token (TOK_RETURN); }
"false"         { return yyprint_token (TOK_FALSE); }
"true"          { return yyprint_token (TOK_TRUE); }
"null"          { return yyprint_token (TOK_NULL); }
"new"           { return yyprint_token (TOK_NEW); }
"="             { return yyprint_token ('='); }
"+"             { return yyprint_token ('+'); }
"-"             { return yyprint_token ('-'); }
"*"             { return yyprint_token ('*'); }
"/"             { return yyprint_token ('/'); }
"^"             { return yyprint_token ('^'); }
"("             { return yyprint_token ('('); }
")"             { return yyprint_token (')'); }
";"             { return yyprint_token (';'); }
"["             { return yyprint_token ('['); }
"]"             { return yyprint_token (']'); }
","             { return yyprint_token (','); }
"."             { return yyprint_token ('.'); }
"!"             { return yyprint_token ('!'); }
"{"             { return yyprint_token ('{'); }
"}"             { return yyprint_token ('}'); }
"<"             { return yyprint_token (TOK_LT); }
">"             { return yyprint_token (TOK_GT); }
{TOK_INT}       { return yyprint_token (TOK_INTCON); }
{CHAR_CONST}	{ return yyprint_token (TOK_CHARCON); }
{STR_CONST}	{ return yyprint_token (TOK_STRINGCON); }
{TOK_NEWARRAY}  { return yyprint_token (TOK_NEWARRAY); }
{TOK_EQ}  { return yyprint_token (TOK_EQ); }
{TOK_NE}  { return yyprint_token (TOK_NE); }
{TOK_LE}  { return yyprint_token (TOK_LE); }
{TOK_GE}  { return yyprint_token (TOK_GE); }
{TOK_IDENT}     { return yyprint_token (TOK_IDENT); }



.               { scanner_badchar (*yytext); }

%%

// unset: %option noyywrap
int yywrap (void){
   yy_delete_buffer (YY_CURRENT_BUFFER);
   if (yy_flex_debug) eprintf ("yywrap() return %d\n", TRUE);
   return TRUE;
}


