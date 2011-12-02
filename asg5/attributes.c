
#include "attributes.h"
const bitset_t ATTR_VOID     = 1 << ATTR_INDEX_VOID;
const bitset_t ATTR_BOOL     = 1 << ATTR_INDEX_BOOL;
const bitset_t ATTR_CHAR     = 1 << ATTR_INDEX_CHAR;
const bitset_t ATTR_INT      = 1 << ATTR_INDEX_INT;
const bitset_t ATTR_NULL     = 1 << ATTR_INDEX_NULL;
const bitset_t ATTR_STRING   = 1 << ATTR_INDEX_STRING;
const bitset_t ATTR_STRUCT   = 1 << ATTR_INDEX_STRUCT;
const bitset_t ATTR_ARRAY    = 1 << ATTR_INDEX_ARRAY;
const bitset_t ATTR_FUNCTION = 1 << ATTR_INDEX_FUNCTION;
const bitset_t ATTR_VARIABLE = 1 << ATTR_INDEX_VARIABLE;
const bitset_t ATTR_FIELD    = 1 << ATTR_INDEX_FIELD;
const bitset_t ATTR_TYPEID   = 1 << ATTR_INDEX_TYPEID;
const bitset_t ATTR_PARAM    = 1 << ATTR_INDEX_PARAM;
const bitset_t ATTR_LVALUE   = 1 << ATTR_INDEX_LVALUE;
const bitset_t ATTR_CONST    = 1 << ATTR_INDEX_CONST;
const bitset_t ATTR_VREG     = 1 << ATTR_INDEX_VREG;
const bitset_t ATTR_VADDR    = 1 << ATTR_INDEX_VADDR;

// The following initialization style is a gcc-ism and will
// not work with some C compilers, and confuses lint.
const char *attr_names[] = {
   [ATTR_INDEX_VOID    ] "void"    ,
   [ATTR_INDEX_BOOL    ] "bool"    ,
   [ATTR_INDEX_CHAR    ] "char"    ,
   [ATTR_INDEX_INT     ] "int"     ,
   [ATTR_INDEX_NULL    ] "null"    ,
   [ATTR_INDEX_STRING  ] "string"  ,
   [ATTR_INDEX_STRUCT  ] "struct"  ,
   [ATTR_INDEX_ARRAY   ] "array"   ,
   [ATTR_INDEX_FUNCTION] "function",
   [ATTR_INDEX_VARIABLE] "variable",
   [ATTR_INDEX_FIELD   ] "field"   ,
   [ATTR_INDEX_TYPEID  ] "typeid"  ,
   [ATTR_INDEX_PARAM   ] "param"   ,
   [ATTR_INDEX_LVALUE  ] "lvalue"  ,
   [ATTR_INDEX_CONST   ] "const"   ,
   [ATTR_INDEX_VREG    ] "vreg"    ,
   [ATTR_INDEX_VADDR   ] "vaddr"   ,
};


bitset_t bitset (int attribute_index) {
   return 1L << attribute_index;
}

bool is_primitive (bitset_t attributes) {
   return attributes
          & (ATTR_BOOL | ATTR_CHAR | ATTR_INT)
       && ! (attributes | ATTR_ARRAY);
}

bool is_reference (bitset_t attributes) {
   return attributes
          & (ATTR_NULL | ATTR_STRING | ATTR_STRUCT | ATTR_ARRAY)
       && TRUE;
}

void print_attributes (bitset_t attributes) {
   ssize_t size = sizeof attr_names / sizeof *attr_names;
   int index;
   for (index = 0; index < size; ++index) {
      if (attributes & bitset (index)) {
         printf (" %s", attr_names [index]);
      }
   }
}

