# $Id: Makefile,v 1.1 2011-08-31 19:29:11-07 - - $

#
# The parser in this directory is a dummy useable for asg2.
# It allows any sequence of tokens to be used in any order
# without actually doing a syntax check.  It is only useful
# as a test harness for the scanner assignment.
#

CCOPT   = -D__EXTENSIONS__ -g -xO0 -Xc
LINTOPT = -D__EXTENSIONS__ -Xa -fd -m -u -x -errchk=%all,no%longptr64
LISTING = Code.Listing.ps

all: parser.c cppstrtok.c parser.h printtokens keywords
	cid + Makefile

parser.c parser.h: parser.y
	cid + parser.y
	M4=gm4 bison -dtv parser.y -o parser.c

printtokens: printtokens.c parser.c parser.h
	cid + printtokens.c
	lint ${LINTOPT} printtokens.c
	cc ${CCOPT} printtokens.c parser.c -o printtokens

keywords: keywords.c
	lint ${LINTOPT} keywords.c
	cc ${CCOPT} keywords.c -o keywords

keywords.c: parser.h make-kw-table.perl
	cid + make-kw-table.perl
	make-kw-table.perl parser.h keywords.c

lis: printtokens.output keywords.output Makefile
	mkpspdf ${LISTING} parser.h parser.y \
	   keywords.c keywords.output \
	   printtokens.c printtokens.output \
	   make-kw-table.perl Makefile

clean :
	- rm parser.o parser.h parser.c \
	     keywords keywords.c keywords.output \
	     printtokens printtokens.o printtokens.output \
	     keywords.output parser.output printtokens.output

ci :
	cid + strhash.h strhash.c make-kw-table.perl \
	    parser.y printtokens.c Makefile \

%.output: %
	$< >$@

