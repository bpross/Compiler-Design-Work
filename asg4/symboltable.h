#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__



typedef struct symboltable *symboltable_ref;

typedef struct symbolnode * symbolnode_ref;

symboltable_ref new_symboltable(void);

symboltable_ref insert_symbolnode(symboltable_ref sym_tab, astree astnode, stringnode_ref strnode);

#endif
