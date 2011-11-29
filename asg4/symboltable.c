#include <stdio.h>
#include "attributes.h"
#include "stringtable.h"

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
    char file[64];
    int line;
    int offset;
    int block_num;
    hashcode_t hashcode;
    struct symbolnode * params;
    struct symbolnode * next;
} ;

symboltable * new_symboltable(void){
    symboltable * sym_tab;
    sym_tab = calloc(1, sizeof(symboltable) );
    sym_tab->size = 31;
    sym_tab->buckets = calloc(1, (sizeof(symbolnode) * sym_tab->size) );
    sym_tab->entries = 0;
    return sym_tab;
}

stringnode * intern_symboltable(symboltable * sym_tab, cstring data){
    size_t string_len;
    hashcode_t h;
    int bucket_number = 0;
    symbolnode * new_symnode;
    symbolnode * tmp_symnode;
    double hash_percent_full = 0;
    assert(data != NULL);
    string_len = strlen(data);

    h = strhash(data);
    bucket_number = h%sym_tab->size;

    temp_symnode = sym_tab->buckets[bucket_number];
    for(new_symnode = sym_tab->buckets[bucket_number]; new_symnode != NULL; new_symnode = new_symnode->next){
        if(new_symnode->hashcode = h){
            sym_tab->buckets[bucket_number] = temp_symnode;
            return new_symnode;
        }
    }

    new_symnode = sym_tab->buckets[bucket_number];

    if(tmp_symnode == NULL){
        new_symnode->hashcode = h;
        new_symnode->next = NULL;
        sym_tab->buckets[bucket_number] = new_symnode;
        sym_tab->entries++;
    }else{
        new_symnode->hashcode = h;
        symbolnode * first = sym_tab->buckets[bucket_number];
        for(tmp_symnode = sym_tab->buckets[bucket_number]; tmp_symnode != NULL; tmp_symnode = tmp_symnode->next);
        tmp_symnode->next = new_symnode;
        new_symnode->next = NULL;
        sym_tab->entries++;
        sym_tab->buckets[bucket_number] = first; 
    }
    return new_symnode;
}
