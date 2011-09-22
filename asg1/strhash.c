
#include <assert.h>

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
RCSH(STRHASH_C,"$Id: strhash.c,v 1.1 2011-08-31 19:29:11-07 - - $")

