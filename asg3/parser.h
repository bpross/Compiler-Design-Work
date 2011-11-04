/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_IDENT = 258,
     TOK_LIT_CHAR = 259,
     TOK_LIT_INT = 260,
     TOK_LIT_STRING = 261,
     TOK_WHILE_KW = 262,
     TOK_IF_KW = 263,
     TOK_ELSE_KW = 264,
     TOK_RETURN_KW = 265,
     TOK_NEW_KW = 266,
     TOK_VOID_KW = 267,
     TOK_BOOL_KW = 268,
     TOK_CHAR_KW = 269,
     TOK_INT_KW = 270,
     TOK_STRUCT_KW = 271,
     TOK_STRING_KW = 272,
     TOK_UNCHECKED_TYPE_KW = 273,
     TOK_FALSE_KW = 274,
     TOK_TRUE_KW = 275,
     TOK_NULL_KW = 276,
     TOK_EQ = 277,
     TOK_NE = 278,
     TOK_GT = 279,
     TOK_GE = 280,
     TOK_LT = 281,
     TOK_LE = 282
   };
#endif
/* Tokens.  */
#define TOK_IDENT 258
#define TOK_LIT_CHAR 259
#define TOK_LIT_INT 260
#define TOK_LIT_STRING 261
#define TOK_WHILE_KW 262
#define TOK_IF_KW 263
#define TOK_ELSE_KW 264
#define TOK_RETURN_KW 265
#define TOK_NEW_KW 266
#define TOK_VOID_KW 267
#define TOK_BOOL_KW 268
#define TOK_CHAR_KW 269
#define TOK_INT_KW 270
#define TOK_STRUCT_KW 271
#define TOK_STRING_KW 272
#define TOK_UNCHECKED_TYPE_KW 273
#define TOK_FALSE_KW 274
#define TOK_TRUE_KW 275
#define TOK_NULL_KW 276
#define TOK_EQ 277
#define TOK_NE 278
#define TOK_GT 279
#define TOK_GE 280
#define TOK_LT 281
#define TOK_LE 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

