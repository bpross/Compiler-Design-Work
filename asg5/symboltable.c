#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "attributes.h"
#include "stringtable.h"
#include "astree.rep.h"
#include "symboltable.h"

#define HASH_LIMIT .75


struct symboltable {
    struct symbolnode **buckets;
    struct symbolnode *top;
    int size;
    int entries;
};

struct symbolnode {
    stringnode_ref sn;
    bitset_t attribs;
    struct symbolnode * fields;
    int filenr;
    int linenr;
    int offset;
    int block_num;
    char* lexinfo;
    uintptr_t hashcode;
    struct symbolnode * params;
    struct symbolnode * next;
} ;

symboltable_ref new_symboltable(void){
    symboltable_ref sym_tab;
    sym_tab = calloc(1, sizeof(symboltable_ref) );
    sym_tab->size = 31;
    sym_tab->buckets = calloc(1, (sizeof(symbolnode_ref) * sym_tab->size) );
    sym_tab->entries = 0;
    return sym_tab;
}

void insert_symbolnode(symboltable_ref sym_tab, astree astnode, stringnode_ref strnode){
    uintptr_t node_addr;
    int bucket_number = 0;
    symbolnode_ref new_symnode;
    symbolnode_ref tmp_symnode;
    double hash_percent_full = 0;
    assert(strnode != NULL);
    assert(astnode != NULL);

    new_symnode = calloc(1, sizeof(symbolnode_ref) );

    node_addr = (uintptr_t) strnode;

    new_symnode->hashcode = node_addr;
    new_symnode->filenr = astnode->filenr;
    new_symnode->linenr = astnode->linenr;
    new_symnode->offset = astnode->offset;
    new_symnode->lexinfo = astnode->lexinfo;
    new_symnode->sn = strnode;

    bucket_number = node_addr%sym_tab->size;

    hash_percent_full = (double) sym_tab->entries/(double) sym_tab->size;
    if(hash_percent_full >= HASH_LIMIT){
        sym_tab->size *= 2;
        sym_tab->size++;
        sym_tab->buckets = realloc(sym_tab->buckets, (sizeof(symbolnode_ref)*sym_tab->size));
    }

    tmp_symnode = sym_tab->buckets[bucket_number];

    if(tmp_symnode == NULL){
        new_symnode->next = NULL;
        sym_tab->buckets[bucket_number] = new_symnode;
        sym_tab->entries++;
    }else{
        symbolnode_ref first = sym_tab->buckets[bucket_number];
        for(tmp_symnode = sym_tab->buckets[bucket_number]; tmp_symnode != NULL; tmp_symnode = tmp_symnode->next);
        tmp_symnode->next = new_symnode;
        new_symnode->next = NULL;
        sym_tab->entries++;
        sym_tab->buckets[bucket_number] = first; 
    }
    return; 
}
