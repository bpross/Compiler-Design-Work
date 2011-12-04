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

#include "typecheck.h"
#include "astree.h"
#include "astree.rep.h"
#include "stringtable.h"
#include "lyutils.h"
#include "attributes.h"
#include "symboltable.h"



int block_count = 0;

void ast_dfspost_traverse(symboltable_ref sym_table, astree root,
         stringtable_ref st, blockstack_ref bs, symbolstack_ref ss){
    if(root == NULL) return;
    assert(is_astree(root));
    astree child = NULL;
    cstring name = strdup(root->lexinfo);
    stringnode_ref strnode;
    strnode = intern_stringtable(st, name);
    symbolnode_ref temp;
    switch (root->symbol) {
        case TOK_STRUCT:
            handle_struct(root, strnode);
            break;
        case TOK_BLOCK:
           block_count++;
           push_bs(bs,block_count);
           for(child = root->first; child != NULL; child = child->next){
               ast_dfspost_traverse(sym_table, child, st, bs, ss);
           }
           pop_bs(bs);
           break;
        case TOK_FUNCTION:
           temp = insert_symbolnode(sym_table,root,
                       strnode,ATTR_INDEX_FUNCTION);
           if (temp == NULL){ //no matching prototype 
               block_count++;
               push_bs(bs, block_count);
               for(child = root->first; child != NULL;
                                  child = child->next){
                   ast_dfspost_traverse(sym_table, child, st, bs, ss);
               }   
           }
           break;
        case TOK_PARAMLIST:
             for(child = root->first; child != NULL;
                                child = child->next){
                   ast_dfspost_traverse(sym_table, child, st, bs, ss);
               }
            break;
        case TOK_VARDECLINIT:
            temp = insert_symbolnode(sym_table,root,
                        strnode,ATTR_INDEX_VARIABLE);
            if (temp == NULL) {
                push_ss(ss, temp);
            }
            break;
        case TOK_INT:
            child = root->first;
            temp = insert_symbolnode(sym_table,child,
                              strnode,ATTR_INDEX_INT);
            break;
        case TOK_STRING:
            child = root->first;
            temp = insert_symbolnode(sym_table,child,
                           strnode,ATTR_INDEX_STRING);
            break;
        case TOK_CHAR:
            child = root->first;
            temp = insert_symbolnode(sym_table,child,
                             strnode,ATTR_INDEX_CHAR);
            break;
        case TOK_BOOL:
            child = root->first;
            temp = insert_symbolnode(sym_table,child,
                             strnode,ATTR_INDEX_BOOL);
            break;
        case TOK_NEW:
            child = root->first;
            temp = insert_symbolnode(sym_table, child,
                            strnode, ATTR_INDEX_ARRAY);
            break;
        case TOK_INTCON:
            child = root->first;
            temp = insert_symbolnode(sym_table,child,
                              strnode,ATTR_INDEX_INT);
            break;
        case TOK_STRINGCON:
            child = root->first;
            temp = insert_symbolnode(sym_table,child,
                           strnode,ATTR_INDEX_STRING);
            break;
        case TOK_CHARCON:
            child = root->first;
            temp = insert_symbolnode(sym_table,child,
                             strnode,ATTR_INDEX_CHAR);
            break;
    }
    
}

void handle_struct(astree root,stringnode_ref strnode){
    symboltable_ref struct_table = new_symboltable();
    symbolnode_ref sn = insert_symbolnode(struct_table,
                        root,strnode,ATTR_INDEX_STRUCT);
    symboltable_ref field_table = new_symboltable();
    astree current_field = root->first->next; 
    while(current_field != NULL){
        sn = insert_symbolnode(field_table,current_field,
                               strnode,ATTR_INDEX_FIELD);
        current_field = current_field->next;
    }

    set_fields(struct_table, field_table);
}
