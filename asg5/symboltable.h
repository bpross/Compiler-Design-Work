#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include "stringtable.h"
#include "astree.h"

typedef struct symboltable * symboltable_ref;

typedef struct symbolnode * symbolnode_ref;

typedef struct symbolstack * symbolstack_ref;
typedef struct blocknode * blocknode_ref;
typedef struct blockstack * blockstack_ref;

blocknode_ref new_blocknode(int blocknum);
blockstack_ref new_blockstack(void);
void push_bs(blockstack_ref bs, int blocknum);
void pop_bs(blockstack_ref bs);
symbolstack_ref new_symbolstack(void);
void push_ss(symbolstack_ref ss, symbolnode_ref sn);
void pop_ss(symbolstack_ref ss);

symboltable_ref new_symboltable(void);
void set_fields(symboltable_ref sym_tab, symboltable_ref fields);
symbolnode_ref insert_symbolnode(symboltable_ref, astree,
                                 stringnode_ref, int att_i);
void handle_struct(astree root, stringnode_ref strnode);

#endif
