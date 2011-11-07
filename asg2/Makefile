# Authors: bpross@ucsc.edu, esteggal@ucsc.edu
# TA: Richard Halpert
# Professor: Wesley Mackey
# CMPS 104a

MKFILE      = Makefile
NOINCL      = ci clean spotless
NEEDINCL    = ${filter ${NOINCL}, ${MAKECMDGOALS}}
GMAKE       = ${MAKE} --no-print-directory
UNAME       = ${shell uname -s}

ifeq (${UNAME},SunOS)
COMPILE  = CC -g -features=extensions
MAKEDEPS = CC -xM1
endif
ifeq (${UNAME},Linux)
COMPILE  = gcc -g -O0 -Wall -Wextra -Werror
MAKEDEPS = gcc -MM
endif

SOURCE      = stringtable.c strhash.c main.c lyutils.c ${MSOURCE}
MSOURCE     = astree.c auxlib.c
HEADER      = stringtable.h strhash.h lyutils.h ${MHEADER}
MHEADER     = astree.h astree.rep.h auxlib.h
LSOURCES    = scanner.l
YSOURCES    = parser.y
YY          = ${LSOURCES} ${YSOURCES}
CLGEN       = yylex.c
HYGEN       = yyparse.h
CYGEN       = yyparse.c
CGENS       = ${CLGEN} ${CYGEN}
ALLGENS     = ${HYGEN} ${CGENS}
LREPORT     = yylex.output
YREPORT     = yyparse.output
EXECBIN     = oc
OBJECTS     = ${SOURCE:.c=.o} ${CYGEN:.c=.o} ${CLGEN:.c=.o}
MOBJECT     = ${MSOURCE:.c=.o}
OTHERS      = ${MKFILE} README PARTNER ${MSOURCE} ${MHEADER}
ALLSOURCES  = ${HEADER} ${SOURCE} ${OTHERS} ${ALLGENS} ${YY}
CLASS       = cmps104a-wm.f11
PROJECT     = asg2

all : ${EXECBIN}
	checksource ${ALLSOURCES}

lint : ${SOURCES}
	for cprog in ${SOURCES} \
	; do echo lint ${LINTOPT} $$cprog \
	; lint ${LINTOPT} $$cprog \
	; done

${EXECBIN} : ${OBJECTS}
	${COMPILE} -o $@ ${OBJECTS}

%.o : %.c
	${COMPILE} -c $<

${CLGEN} : ${LSOURCES}
	flex -o${CLGEN} ${LSOURCES} 2>${LREPORT}
	- grep -v '^  ' ${LREPORT}
	- (perl -e 'print "="x65,"\n"'; cat lex.backup) >>${LREPORT} 
	- rm lex.backup

${CYGEN} ${HYGEN} : ${YSOURCES}
	bison -dtv -o${CYGEN} ${YSOURCES}

ci : ${ALLSOURCES}
	checksource ${ALLSOURCES}
	- git commit ${ALLSOURCES}

clean :
	rm ${OBJECTS}

spotless : clean
	- rm ${EXECBIN} 

submit : ${ALLSOURCES}
	- checksource ${ALLSOURCES}
	submit ${CLASS} ${PROJECT} ${ALLSOURCES}
	testsubmit ${CLASS} ${PROJECT} ${ALLSOURCES}


