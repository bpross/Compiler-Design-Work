#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

typedef struct symboltable * symboltable_ref;

typedef struct symbolnode * symbolnode_ref;

symboltable_ref new_symboltable(void);

void insert_symbolnode(symboltable_ref, astree, stringnode_ref);

#endif
