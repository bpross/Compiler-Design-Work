// $Id: prthexaddr.c,v 1.1 2011-08-31 19:29:39-07 - - $

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

#define xprintf  (void) printf
#define xsprintf (void) sprintf

#define PRINT(SYMBOL,DESCR) { \
        xprintf ("%16p: %s - %s\n", (void*) SYMBOL, #SYMBOL, DESCR); \
        }

extern char _start;
extern char _etext;
extern char _edata;
extern char _end;
extern char **environ;
static double init_var[] = {
   3.141592653589793238462643383279502884197169399,
   2.718281828459045235360287471352662497757247093,
   0.301029995663981195213738894724493026768189881,
   1.414213562373095048801688724209698078569671875,
};
static int uninit_var1[1<<10];
static int uninit_var2[1<<10];

char *fmt (char *text, int value) {
   char *buffer = malloc (strlen (text) + 16);
   xsprintf (buffer, "%s %d", text, value);
   return buffer;
}

void stack (int level) {
   if (level < 5) stack (level + 1);
   char *message = fmt ("address of a stack variable at level", level);
   PRINT (&level, message);
   free (message);
}

void *stack_bottom (char **start) {
   for (; *start != NULL; ++start) {}
   --start;
   char *startstr = *start;
   while (*startstr != '\0') ++startstr;
   return startstr;
}

void print_uname (void) {
   struct utsname name;
   int rc = uname (&name);
   if (rc < 0) {
      xprintf ("uname: %s\n", strerror (errno));
      return;
   }
   xprintf ("sysname  = \"%s\"\n", name.sysname );
   xprintf ("nodename = \"%s\"\n", name.nodename);
   xprintf ("release  = \"%s\"\n", name.release );
   xprintf ("version  = \"%s\"\n", name.version );
   xprintf ("machine  = \"%s\"\n", name.machine );
}

int main (int argc, char **argv) {
   print_uname ();
   int main_local;
   xprintf ("\n");
   PRINT (NULL, "null pointer");

   xprintf ("\nAddresses of some local variables:\n");
   stack (1);
   PRINT (&main_local, "address of a local variable in main");
   PRINT (&argc, "address of argc");
   PRINT (&argv, "address of argv");
   PRINT (argv, "address of arg vector");
   PRINT (environ, "address of environ vector");
   PRINT (stack_bottom (environ), "byte at bottom of stack");

   xprintf ("\nAddresses of some static variables:\n");
   PRINT (printf, "(text) address of the printf() function");
   PRINT (&_start, "start of program text");
   PRINT (main, "(text) address of the main() function");
   PRINT (&_etext, "end of program text");
   PRINT (&init_var, "address of an init static variable");
   PRINT (&_edata, "end of init data segment");
   PRINT (&uninit_var1, "address of an uninit static variable1");
   PRINT (&uninit_var2, "address of an uninit static variable2");
   PRINT (&_end, "end of uninit data segment");

   xprintf ("\nAddresses of some heap variables:\n");
   for (int heap_count = 0; heap_count < 10; ++heap_count) {
      void *heap_variable = calloc (1000, sizeof (int));
      assert (heap_variable != NULL);
      char *message = fmt ("heap variable ", heap_count);
      PRINT (heap_variable, message);
      free (message);
   }

   return EXIT_SUCCESS;
}

