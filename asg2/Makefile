# $Id: Makefile,v 1.4 2010-12-13 20:12:44-08 - - $

MKFILE      = Makefile
DEPSFILE    = ${MKFILE}.deps
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

SOURCE      = stringtable.c strhash.c main.c astree.c lyutils.c auxlib.c
HEADER      = stringtable.h strhash.h astree.h astree.rep.h lyutils.h auxlib.h
LSOURCES    = scanner.l
YSOURCES    = parser.y
CLGEN       = yylex.c
HYGEN       = yyparse.h
CYGEN       = yyparse.c
CGENS       = ${CLGEN} ${CYGEN}
ALLGENS     = ${HYGEN} ${CGENS}
LREPORT     = yylex.output
YREPORT     = yyparse.output
EXECBIN     = oc
OBJECTS     = ${SOURCE:.c=.o}
OTHERS      = ${MKFILE} README PARTNER
ALLSOURCES  = ${HEADER} ${SOURCE} ${OTHERS} ${ALLGENS}
CLASS       = cmps104a-wm.f11
PROJECT     = asg1
LINTOPT     = -D__EXTENSIONS__ -Xa -fd -m -u -x -errchk=%all,no%longptr64

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
	flex -o ${CLGEN} ${LSOURCES} 2>${LREPORT}
	- grep -v '^  ' ${LREPORT}
	- (perl -e 'print "="x65,"\n"'; cat lex.backup) >>${LREPORT} 
	- rm lex.backup

${CYGEN} ${HYGEN} : ${YSOURCES}
	bison -dtv -o${CYGEN} ${YSOURCES}

ci : ${ALLSOURCES}
	checksource ${ALLSOURCES}
	- git commit ${ALLSOURCES}

clean :
	rm ${OBJECTS} ${DEPSFILE} core ${EXECBIN}.errs

spotless : clean
	- rm ${EXECBIN} 

submit : ${ALLSOURCES}
	- checksource ${ALLSOURCES}
	submit ${CLASS} ${PROJECT} ${ALLSOURCES}
	testsubmit ${CLASS} ${PROJECT} ${ALLSOURCES}


