# $Id: Makefile,v 1.4 2010-12-13 20:12:44-08 - - $

MKFILE      = Makefile
DEPSFILE    = ${MKFILE}.deps
NOINCL      = ci clean spotless
NEEDINCL    = ${filter ${NOINCL}, ${MAKECMDGOALS}}
GMAKE       = ${MAKE} --no-print-directory
UNAME      ?= ${shell uname -s}

ifeq (${UNAME},SunOS)
COMPILE  = CC -g -features=extensions
MAKEDEPS = CC -xM1
endif
ifeq (${UNAME},Linux)
COMPILE  = gcc -g -O0 -Wall -Wextra -Werror
MAKEDEPS = gcc -MM
endif

SOURCE      = stringtable.c strhash.c main.c
HEADER      = stringtable.h strhash.h
EXECBIN     = oc
OBJECTS     = ${SOURCE:.c=.o}
OTHERS      = ${MKFILE} README PARTNER
ALLSOURCES  = ${HEADER} ${SOURCE} ${OTHERS}
CLASS       = cmps104a-wm.f11
PROJECT     = asg1
LINTOPT  = -D__EXTENSIONS__ -Xa -fd -m -u -x -errchk=%all,no%longptr64

all : ${EXECBIN}
	- checksource ${ALLSOURCES}

lint : ${SOURCES}
	for cprog in ${SOURCES} \
	; do echo lint ${LINTOPT} $$cprog \
	; lint ${LINTOPT} $$cprog \
	; done

${EXECBIN} : ${OBJECTS}
	${COMPILE} -o $@ ${OBJECTS}

%.o : %.c
	${COMPILE} -c $<

ci : ${ALLSOURCES}
	- checksource ${ALLSOURCES}
	git commit ${ALLSOURCES}

clean :
	- rm ${OBJECTS} ${DEPSFILE} core ${EXECBIN}.errs

spotless : clean
	- rm ${EXECBIN} 

submit : ${ALLSOURCES}
	- checksource ${ALLSOURCES}
	submit ${CLASS} ${PROJECT} ${ALLSOURCES}
	testsubmit ${CLASS} ${PROJECT} ${ALLSOURCES}

deps : ${SOURCE} ${HEADER}
	@ echo "# ${DEPSFILE} created `LC_TIME=C date`" >${DEPSFILE}
	${MAKEDEPS} ${SOURCE} | sort | uniq >>${DEPSFILE}

${DEPSFILE} :
	@ touch ${DEPSFILE}
	${GMAKE} deps

again :
	gmake --no-print-directory spotless deps ci all lis

ifeq (${NEEDINCL}, )
include ${DEPSFILE}
endif

