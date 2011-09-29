#include <assert.h>
#include <stdio.h>
#include "stringtable.h"

/* Note: This is mostly code taken from www.ks.uiuc.edu.\
    It has been modified to work for our CMPS104 asg1 */


struct stringtable {
  struct stringnode **bucket;
  int size;
  int entries;
  int downshift;
  int mask;
};

struct stringnode {
  int data;
  const char * key;
  struct stringnode * next;
};


/* () - Initialize new hash table
 * 
 * st = Hash table
 */

stringtable_ref new_stringtable(void){
  stringtable_ref st;

  return(st);
  
}



