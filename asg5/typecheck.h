#ifndef __TYPECHECK_H__
#define __TYPECHECK_H__
#include "symboltable.h"

void ast_dfspost_traverse(symboltable_ref sym_table, astree root,
       stringtable_ref st, blockstack_ref bs, symbolstack_ref ss);

#endif
