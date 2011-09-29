
//
// NAME
//    strhash - return an unsigned 32-bit hash code for a string
//
// SYNOPSIS
//    hashcode_t strhash (char *string);
//
// DESCRIPTION
//    Uses Horner's method to compute the hash code of a string
//    as is done by java.lang.String.hashCode:
//    .  s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]
//    Using strength reduction, the multiplication is replaced by
//    a shift.  However, instead of returning a signed number,
//    this function returns an unsigned number.
//
// REFERENCE
//    http://java.sun.com/j2se/1.4.1/docs/api/java/lang/
//    String.html#hashCode()
// 
//

#ifndef __STRHASH_H__
#define __STRHASH_H__

#include <inttypes.h>

//#include <auxlib.h>

typedef uint32_t hashcode_t;

typedef struct hash_t * hash_t;

#define HASH_FAIL -1

int hash_init(hash_t *, int);

int hash_lookup(const hash_t *, const char *);

int hash_insert(hash_t *, const char *, int);

int hash_delete(hash_t *, const char *);

int hash_destroy(hash_t *);


hashcode_t strhash (char *string);


#endif

