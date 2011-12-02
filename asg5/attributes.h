#ifndef __ATTRIBUTES_H__
#define __ATTRIBUTES_H__
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "auxlib.h"


typedef unsigned long bitset_t;

enum {
   ATTR_INDEX_VOID     =  0,
   ATTR_INDEX_BOOL     =  1,
   ATTR_INDEX_CHAR     =  2,
   ATTR_INDEX_INT      =  3,
   ATTR_INDEX_NULL     =  4,
   ATTR_INDEX_STRING   =  5,
   ATTR_INDEX_STRUCT   =  6,
   ATTR_INDEX_ARRAY    =  7,
   ATTR_INDEX_FUNCTION =  8,
   ATTR_INDEX_VARIABLE =  9,
   ATTR_INDEX_FIELD    = 10,
   ATTR_INDEX_TYPEID   = 11,
   ATTR_INDEX_PARAM    = 12,
   ATTR_INDEX_LVALUE   = 13,
   ATTR_INDEX_CONST    = 14,
   ATTR_INDEX_VREG     = 15,
   ATTR_INDEX_VADDR    = 16,
};

bitset_t bitset (int attribute_index);
bool is_primitive(bitset_t attributes);
bool is_reference(bitset_t attributes);
void print_attributes(bitset_t attributes);

#endif
