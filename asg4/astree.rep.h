#ifndef __ASTREEREP_H__
#define __ASTREEREP_H__

#include "astree.h"

struct astree_rep {
   char *tag;           // tag field to verify class membership
   int symbol;          // token code
   int filenr;          // index into filename stack
   int linenr;          // line number from source code
   int offset;          // offset of token with current line
   char *lexinfo;       // pointer to lexical information
   astree first;        // first child node of this node
   astree last;         // last child node of this node
   astree next;         // next younger sibling of this node
};

// LINTED(static unused)
RCSH(ASTREEREP_H,"$Id: astree.rep.h,v 1.4 2011-10-06 22:05:30-07 - - $")
#endif
