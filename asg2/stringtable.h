#ifndef __STRTABLE_H__
#define __STRINGTABLE_H__

#include "strhash.h"


typedef struct stringtable * stringtable_ref;

typedef struct stringnode * stringnode_ref;

typedef char *cstring;

#define HASH_FAIL -1

stringtable_ref new_stringtable(void);

void delete_stringtable(stringtable_ref);

void debugdump_stringtable(stringtable_ref, FILE*);

stringnode_ref intern_stringtable(stringtable_ref, cstring);

cstring peek_stringtable(stringnode_ref);

hashcode_t hashcode_stringtable(stringnode_ref);

#endif
