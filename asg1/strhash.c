#include <assert.h>
#include <stdio.h>
#include "strhash.h"

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

