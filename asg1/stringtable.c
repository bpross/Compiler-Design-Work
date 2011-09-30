#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringtable.h"

#define HASH_LIMIT .75

/* Note: This is mostly code taken from www.ks.uiuc.edu.\
    It has been modified to work for our CMPS104 asg1 */


struct stringtable {
  struct stringnode **buckets;
  int size;
  int mask;
  int entries;
};

struct stringnode {
  char * data;
  hashcode_t key;
  struct stringnode * next;
};


/* new_strintable() - Initialize new hash table
 * 
 * st = Hash table
 * sn = String node
 */

stringtable_ref new_stringtable(void){
  stringtable_ref st;
  st = calloc(1, sizeof(stringtable_ref) );
  st->size = 31;
  st->buckets = calloc(1, (sizeof(stringnode_ref) * st->size));
  st->entries = 0;
  return(st);
}

cstring peek_stringtable(stringnode_ref input_node){
  cstring ret_value;
  assert(input_node != NULL);
  assert(input_node->data != NULL);
//  ret_value = calloc(1, sizeof(cstring) );
  ret_value = input_node->data;
  return ret_value;
}


void debugdump_stringtable(stringtable_ref, FILE*){
}
stringnode_ref intern_stringtable(stringtable_ref st, cstring data){
  hashcode_t h;
  int bucket_number = 0;
  stringnode_ref sn;
  stringnode_ref temp_sn;
  double hash_percent_full = 0;
  assert(data != NULL);
  cstring already_hashed;

  printf("data = %s\n", data);
  
  
  h = strhash(data);
  bucket_number = h%st->size;
  printf("Bucket Number = %u\n",bucket_number);
  printf("Hash = %u\n", h);

  for(sn = st->buckets[bucket_number]; sn != NULL; sn = sn->next){
    if(sn->key == h){ 
      return sn;
    }
  }
  printf("Past here\n");

  sn = calloc(1, sizeof(stringnode_ref) );
  printf("Past calloc\n");

  hash_percent_full = (double) st->entries/ (double) st->size;
  printf("Hash percent %lf\n", hash_percent_full);
  if(hash_percent_full >= HASH_LIMIT){
    st->size *= 2;
    st->size++;
    st->buckets = realloc(st->buckets, (sizeof(stringnode_ref) * st->size) );
  }

  temp_sn = st->buckets[bucket_number];
  
  if (temp_sn == NULL){
    sn->key = h;
    printf("Key worked\n");
    sn->data = data;
    printf("Past putting in data\n");
    if(sn->data == NULL){
      printf("Copy broke in intern_string()\n");
      return NULL;
    }
    sn->next = NULL;
    st->buckets[bucket_number] = sn;
    st->entries++;
  }else{
//    already_hashed = peek_stringtable(temp_sn);
//    printf("Already_hashed = %s\n", already_hashed);
    sn->key = h;
    printf("Key Worked\n");
    sn->data = data;
    for (temp_sn = st->buckets[bucket_number]; temp_sn->next != NULL; temp_sn = temp_sn->next);
    temp_sn->next = sn;
    sn->next = NULL;
    st->entries++;
  }
  
  return sn;
}
