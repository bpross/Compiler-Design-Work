// $Id: uintptr_t.c,v 1.1 2011-08-31 19:29:39-07 - - $

//
// Illustrate the use of uintptr_t to turn a pointer into an
// integer of the appropriate kind, such as for indexing into
// a hash table.
//

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
   int count = argc < 10 ? 10 : atoi (argv[1]);
   printf ("sizeof (char*) = %d, sizeof (uintptr_t) = %d\n",
            sizeof (char*),      sizeof (uintptr_t));
   for (int bytes = 0; bytes < count; ++bytes) {
      char *pointer = malloc (bytes * 10);
      uintptr_t ptr_as_int = (uintptr_t) pointer >> 3;
      printf ("pointer = %p, ptr_as_int = %d\n",
              (void*) pointer, ptr_as_int);
   }
   return EXIT_SUCCESS;
}
