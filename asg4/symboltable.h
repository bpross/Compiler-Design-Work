
typedef struct symboltable * symboltable_ref;

typedef struct symbolnode * symbolnode_ref;

symboltable_ref new_symboltable(void);

symbolnode_ref isert_symbolnode(symboltable_ref sym_tab, astree astnode, stringnode_ref strnode);


