#include <assert.h>
#include <stdio.h>
#include "strhash.h"

/* Note: This is mostly code taken from www.ks.uiuc.edu.\
    It has been modified to work for our CMPS104 asg1 */


struct hash_t {
  struct hash_node_t **bucket;
  int size;
  int entries;
  int downshift;
  int mask;
};

typedef struct hash_node_t {
  int data;
  const char * key;
  struct hash_node_t * next;
} hash_node_t;


/* hash() - Inputs a string, outputs a hash number for a certain key
 * 
 */


hashcode_t strhash (char *string) {
   hashcode_t hashcode = 0;
   assert (string != NULL);
   for (;;) {
      hashcode_t byte = (unsigned char) *string++;
      if (byte == '\0') break;
      hashcode = (hashcode << 5) - hashcode + byte;
   };
   return hashcode;
}

/* hash_init() - Initialize new hash table
 * 
 * htp = Hash table pointer
 * Buckets = The number of slots to initialize with
 */




