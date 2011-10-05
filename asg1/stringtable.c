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

void delete_stringtable(stringtable_ref st){
  int i;
  stringnode_ref sn;
  stringnode_ref tmp_sn;
  assert(st != NULL);
  printf("delete_stringtable() before frees\n");

  for(i = 0; i < st->size; i++){
    if(st->buckets[i] != NULL){
      sn = st->buckets[i];
      for(; sn != NULL;){
        printf("sn->data = %s\n", sn->data);
        if(sn != NULL){
          tmp_sn = sn->next;
          free(sn->data);
          free(sn);
          sn = tmp_sn;
        }
      }
    }
  }
  printf("At the end\n");
  free(st->buckets);
  free(st);
}

cstring peek_stringtable(stringnode_ref input_node){
  cstring ret_value;
  assert(input_node != NULL);
  assert(input_node->data != NULL);
//  ret_value = calloc(1, sizeof(cstring) );
  ret_value = input_node->data;
  return ret_value;
}

hashcode_t hashcode_stringtable(stringnode_ref sn){
  hashcode_t hashcode = sn->key;
  return hashcode;
}
void debugdump_stringtable(stringtable_ref st, FILE* fp){
  int count = 0;
  stringnode_ref sn;
  for(;count < st->size;count++){
    sn = st->buckets[count];
    if(sn != NULL){
      assert(sn->data != NULL);
      fprintf(fp,"%8d  %12u  \"%s\"        %p\n",count,sn->key,sn->data,sn);
      if(sn->next != NULL)
        for(sn = sn->next; sn != NULL; sn=sn->next)
            fprintf(fp,"          %12u  \"%s\"         %p\n",sn->key,sn->data,sn);
    }
  }
}
stringnode_ref intern_stringtable(stringtable_ref st, cstring data){
  size_t string_len;
  hashcode_t h;
  int bucket_number = 0;
  stringnode_ref sn;
  stringnode_ref temp_sn;
  double hash_percent_full = 0;
  assert(data != NULL);
  string_len = strlen(data);
  

  h = strhash(data);
  bucket_number = h%st->size;
  printf("Bucket Number = %u  Hash = %u  Data = %s\n",bucket_number,h,data);
  
  temp_sn = st->buckets[bucket_number];
  for(sn = st->buckets[bucket_number]; sn != NULL; sn = sn->next){
    if(sn->key == h){ 
      printf("Bucket found\n");
      st->buckets[bucket_number] = temp_sn;
      return sn;
    }
  }

  sn = calloc(1, sizeof(stringnode_ref) );

  hash_percent_full = (double) st->entries/ (double) st->size;
  if(hash_percent_full >= HASH_LIMIT){
    st->size *= 2;
    st->size++;
    st->buckets = realloc(st->buckets, (sizeof(stringnode_ref) * st->size) );
  }

  temp_sn = st->buckets[bucket_number];
  
  if (temp_sn == NULL){
    sn->key = h;
    sn->data = calloc(1, (string_len*sizeof(char) ) );
    sn->data = data;
    if(sn->data == NULL){
      return NULL;
    }
    sn->next = NULL;
    st->buckets[bucket_number] = sn;
    st->entries++;
  }else{
//    already_hashed = peek_stringtable(temp_sn);
//    printf("Already_hashed = %s\n", already_hashed);
    sn->key = h;
    sn->data = data;
    stringnode_ref first = st->buckets[bucket_number];
    for (temp_sn = st->buckets[bucket_number]; temp_sn->next != NULL; temp_sn = temp_sn->next);
    temp_sn->next = sn;
    sn->next = NULL;
    st->entries++;
    st->buckets[bucket_number] = first;
  }
  return sn;
}

