/* stringtable.c
   Authors: Benjamin Ross and Erik Steggal
   Date: 10-05-11

   This file implements a string table, as needed for the first
   assignment for CMPS 104A at UCSC, Fall Quarter 2011.
   This project was worked on via Pair Programming between the
   dates 9-29-11 to 10-5-11
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringtable.h"

#define HASH_LIMIT .75


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

/* delete_stringnode() 
   frees the entire stringtable
   not completely working. may come back
   and fix later if time permits 
   @param st: string table to free
*/
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

/* peek_stringtable()
   Returns the string that is associated with the node
   @param input_node: node to get the string of
*/
cstring peek_stringtable(stringnode_ref input_node){
  cstring ret_value;
  assert(input_node != NULL);
  assert(input_node->data != NULL);
  ret_value = input_node->data;
  return ret_value;
}

/* hashcode_stringtable()
   This function is used to return the hashcode associated
   with a string node
   @param sn: string node to get hash value
*/
hashcode_t hashcode_stringtable(stringnode_ref sn){
  hashcode_t hashcode = sn->key;
  return hashcode;
}

/* debugdump_stringtable()
   This function is used to print the string table to a a file.
   It prints out in this format:
   Bucket Number   Hash Code    String
   @param st: String Table to print out
   @param fp: file pointer to print the string table to
*/
void debugdump_stringtable(stringtable_ref st, FILE* fp){
  int count = 0;
  stringnode_ref sn;
  for(;count < st->size;count++){
    /*Get the first node in the bucket*/
    sn = st->buckets[count];
    if(sn != NULL){
      assert(sn->data != NULL);
      fprintf(fp,"%8d  %12u  \"%s\"\n",count,sn->key,sn->data);
      /*Checks to see if the next node is NULL
        if it is not, print that node and continue
        checking until NULL is reached */
      if(sn->next != NULL)
        for(sn = sn->next; sn != NULL; sn=sn->next)
            /*This does not print the bucket number, because it is
              printed above */
            fprintf(fp,"          %12u  \"%s\"\n",sn->key,sn->data);
    }
  }
}

/* intern_stringtable()
   This function adds a new node to the string table, unless it already
   exists. If it already exists, it returns the node. If it does not
   exist, then it adds the string to the table and returns the node.
   @param sn : string node to be added
   @param st : string table
   @param h : new data's hashcode
   @param data : new data being added
*/
stringnode_ref intern_stringtable(stringtable_ref st, cstring data){
  size_t string_len;
  hashcode_t h;
  int bucket_number = 0;
  stringnode_ref sn;
  stringnode_ref temp_sn;
  double hash_percent_full = 0;
  assert(data != NULL);
  string_len = strlen(data);
  
  /* Get hash for data */
  h = strhash(data);
  bucket_number = h%st->size;
  
  temp_sn = st->buckets[bucket_number];
  /* Search through stringtable */
  for(sn = st->buckets[bucket_number]; sn != NULL; sn = sn->next){
    if(sn->key == h){ 
      st->buckets[bucket_number] = temp_sn;
      return sn;
    }
  }

  sn = calloc(1, sizeof(stringnode_ref) );
  /* Check if hash table is full, if it is double it */
  hash_percent_full = (double) st->entries/ (double) st->size;
  if(hash_percent_full >= HASH_LIMIT){
    st->size *= 2;
    st->size++;
    st->buckets = realloc(st->buckets, (sizeof(stringnode_ref) * st->size) );
  }

  temp_sn = st->buckets[bucket_number];
  
  /* Check to see if string has been processed */
  /* If no collision add it to buckets*/
  if (temp_sn == NULL){
    sn->key = h;
    sn->data = calloc(1, (string_len*sizeof(char) ) );
    strcpy(sn->data,data);
    if(sn->data == NULL){
      return NULL;
    }
    sn->next = NULL;
    st->buckets[bucket_number] = sn;
    st->entries++;
  /* If there is a collision, add it as the next node */
  }else{
    sn->key = h;
    sn->data = calloc(1, (string_len*sizeof(char)));
    strcpy(sn->data,data);
    stringnode_ref first = st->buckets[bucket_number];
    for (temp_sn = st->buckets[bucket_number]; temp_sn->next != NULL; temp_sn = temp_sn->next);
    temp_sn->next = sn;
    sn->next = NULL;
    st->entries++;
    st->buckets[bucket_number] = first;
  }
  return sn;
}

