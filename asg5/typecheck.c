// Authors: bpross@ucsc.edu, esteggal@ucsc.edu
// TA: Richard Halpert
// Professor: Wesley Mackey
// CMPS 104a
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.rep.h"
#include "stringtable.h"
#include "symboltable.h"




void ast_dfspost_traverse(astree root, stringtable_ref st){
    if(root == NULL) return;
    assert(is_astree(root));
    astree child = NULL;
    cstring name = strdup(root->lexinfo);
    stringnode_ref strnode;
    strnode = intern_stringtable(st, name);
    cstring data = peek_stringtable(strnode);
    for(child = root->first; child != NULL; child = child->next){
        ast_dfspost_traverse(child, st);
    }
    printf("node = %s\n", root->lexinfo);
    if(strnode != NULL){
      printf("strnode %s\n", data);
    }
}
