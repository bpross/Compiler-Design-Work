#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "attributes.h"
#include "stringtable.h"
#include "astree.h"
#include "astree.rep.h"
#include "symboltable.h"

#define HASH_LIMIT .75


struct symboltable {
    struct symbolnode **buckets;
    struct symbolnode *top;
    struct symboltable * fields;
    int size;
    int entries;
};

struct symbolnode {
    stringnode_ref sn;
    bitset_t attribs;
    int filenr;
    int linenr;
    int offset;
    int block_num;
    char* lexinfo;
    uintptr_t hashcode;
    struct symbolnode * params;
    struct symbolnode * next;
    struct symbolnode * prev;
} ;

struct symbolstack {
    struct symbolnode *top;
    int size;
};

struct blocknode {
    int blocknum;
    struct blocknode * next;
    struct blocknode * prev;
};

struct blockstack {
    struct blocknode * top;
    int size;
};

blocknode_ref new_blocknode(int blocknum) {
    blocknode_ref bn = calloc(1,sizeof(blocknode_ref));
    bn->blocknum = blocknum;
    bn->next = NULL;
    bn->prev = NULL;
    return bn;
}

blockstack_ref new_blockstack(void){
    blockstack_ref bs = calloc(1,sizeof(blockstack_ref));
    bs->top = NULL;
    bs->size = 0;
    return bs;
}

void push_bs(blockstack_ref bs, int blocknum){
    assert(bs != NULL);
    if (bs->top == NULL){ //stack is empty
        bs->top = new_blocknode(blocknum);
        bs->size++;
    }
    else {
        blocknode_ref bn = new_blocknode(blocknum);
        bs->top->next = bn;
        bn->prev = bs->top;
        bs->top = bn;
        bs->size++;
    }
}

void pop_bs(blockstack_ref bs){
    if (bs->top != NULL) {
        bs->top = bs->top->prev;
        bs->top->next = NULL;
    }
}

symbolstack_ref new_symbolstack(void) {
    symbolstack_ref ss = calloc(1,sizeof(symbolstack_ref));
    ss->top = NULL;
    ss->size = 0;
    return ss;
}

void push_ss(symbolstack_ref ss, symbolnode_ref sn){
     assert(ss != NULL);
     if (ss->top == NULL) {
        ss->top = sn;
        ss->size++;
     }
     else {
         ss->top->next = sn;
         sn->prev = ss->top;
         ss->top = sn;
         ss->size++;
     }
}

void pop_ss(symbolstack_ref ss){
     if(ss->top != NULL) {
         ss->top = ss->top->prev;
         ss->top->next = NULL;
     }
}

symboltable_ref new_symboltable(void){
    symboltable_ref sym_tab;
    sym_tab = calloc(1, sizeof(symboltable_ref) );
    sym_tab->size = 31;
    sym_tab->buckets = calloc(1,
                      (sizeof(symbolnode_ref) * sym_tab->size) );
    sym_tab->entries = 0;
    return sym_tab;
}

void set_fields(symboltable_ref sym_tab, symboltable_ref fields){
    sym_tab->fields = fields;
}

symbolnode_ref insert_symbolnode(symboltable_ref sym_tab,
              astree astnode, stringnode_ref strnode, int att_i){
    uintptr_t node_addr;
    int bucket_number = 0;
    symbolnode_ref new_symnode;
    symbolnode_ref ptr;
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
    new_symnode->attribs = bitset(att_i);

    bucket_number = node_addr%sym_tab->size;

    tmp_symnode = sym_tab->buckets[bucket_number];
    for(ptr = sym_tab->buckets[bucket_number];
        ptr != NULL; ptr = ptr->next){
        if(strcmp(ptr->lexinfo, new_symnode->lexinfo)){
            sym_tab->buckets[bucket_number] = tmp_symnode;
            return ptr;
        }
    }

    hash_percent_full = (double) sym_tab->entries/
                           (double) sym_tab->size;
    if(hash_percent_full >= HASH_LIMIT){
        sym_tab->size *= 2;
        sym_tab->size++;
        sym_tab->buckets = realloc(sym_tab->buckets,
               (sizeof(symbolnode_ref)*sym_tab->size));
    }

    tmp_symnode = sym_tab->buckets[bucket_number];

    if(tmp_symnode == NULL){
        new_symnode->next = NULL;
        new_symnode->prev = NULL;
        sym_tab->buckets[bucket_number] = new_symnode;
        sym_tab->entries++;
    }else{
        symbolnode_ref first = sym_tab->buckets[bucket_number];
        for(tmp_symnode = sym_tab->buckets[bucket_number];
            tmp_symnode != NULL; tmp_symnode = tmp_symnode->next);
        tmp_symnode->next = new_symnode;
        new_symnode->next = NULL;
        new_symnode->prev = NULL;
        sym_tab->entries++;
        sym_tab->buckets[bucket_number] = first; 
    }
    return NULL; 
}

void delete_symbolnode(symboltable_ref sym_tab,
                     symbolnode_ref input_node){
    assert(input_node != NULL);
    int bucket_number = 0;
    uintptr_t node_addr = 0;
    symbolnode_ref tmp_node;
    node_addr = (uintptr_t) input_node->sn;
    assert(node_addr != 0);
    bucket_number = node_addr%sym_tab->size;
    tmp_node = sym_tab->buckets[bucket_number];
    if(tmp_node->next == NULL){
        sym_tab->buckets[bucket_number] = NULL;
        free(input_node);
    }else{
        sym_tab->buckets[bucket_number] = tmp_node->next;
        free(input_node);
    }
}
        



