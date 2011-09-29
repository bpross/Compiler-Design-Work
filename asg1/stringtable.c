#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stringtable.h"

/* Note: This is mostly code taken from www.ks.uiuc.edu.\
    It has been modified to work for our CMPS104 asg1 */


struct stringtable {
  struct stringnode **buckets;
  int size;
  int mask;
  int entries;
};

struct stringnode {
  int data;
  const char * key;
};


/* () - Initialize new hash table
 * 
 * st = Hash table
 * sn = String node
 */

stringtable_ref new_stringtable(void){
  stringtable_ref st;
  st = calloc(1, sizeof(stringtable_ref) );
  st->entries = 0;
  st->size = 31;
  return(st);
}



