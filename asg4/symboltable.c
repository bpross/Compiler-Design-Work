#include <stdio.h>
#include "attributes.h"
#include "stringtable.h"

struct symbolnode {
    stringnode_ref sn;
    bitset_t attribs;
    struct symbolnode * fields;
    char file[64];
    int line;
    int offset;
    int block_num;
    struct symbolnode * params;
    struct symbolnode * next;
} ;

