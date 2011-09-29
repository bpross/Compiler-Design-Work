
#include <assert.h>
#include <stdio.h>

#include "strhash.h"

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

// LINTED(static unused)
RCSH(STRHASH_C,"$Id: strhash.c,v 1.2 2011-09-22 18:37:08-07 - - $")

