// $Id: stringtable.c,v 1.1 2011-09-29 12:30:26-07 - - $

// Use cpp to scan a file and print line numbers.
// Print out each input line read in, then strtok it for
// tokens.

#define _GNU_SOURCE
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include "stringtable.h"
#include "strhash.h"

int exit_status = EXIT_SUCCESS;
char *progname;
#define CPP "/usr/bin/cpp"
#define LINESIZE 1024

// Print a warning after a failed system call.
void syswarn (char *problem) {
   fflush (NULL);
   fprintf (stderr, "%s: %s: %s\n",
            progname, problem, strerror (errno));
   fflush (NULL);
   exit_status = EXIT_FAILURE;
}

// Chomp the last character from a buffer if it is delim.
void chomp (char *string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char *nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

void remove_file_ext(char *filename) {
  int dot = 3;
  int o = 2;
  int c = 1;
  size_t len = strlen(filename);
  if (len == 0) return;
  char *check = filename + len - dot;
  if (*check == '.') {
    check = filename + len - o;
    if(*check == 'o') {
      check = filename + len - c;
      if(*check == 'c') {
        chomp(filename,'c');
        chomp(filename,'o');
        chomp(filename,'.');
      }
      else {
        fprintf(stderr, "Wrong File Extension\n");
      }
    }
    else {
      fprintf(stderr, "Wrong File Extension\n");
    }

  }
        


}
// Run cpp against the lines of the file.
void cpplines (FILE *pipe, char *filename) {
   int linenr = 1;
   int tokenct;
   char inputname[LINESIZE];
   char *base = basename(filename);
   remove_file_ext(base);
   printf("base: %s\n",base);
   stringtable_ref st = new_stringtable();
   stringnode_ref sn;
   strcpy (inputname, filename);
   for (;;) {
      char buffer[LINESIZE];
      char *fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == NULL) break;
      chomp (buffer, '\n');
      printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      //char flags[LINESIZE];
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, filename);
      printf("sscanf_rc: %d\n",sscanf_rc);
      if (sscanf_rc == 2) {
         printf ("Directive: line %d, file \"%s\"\n",
                 linenr, filename);
         continue;
      }
      char *savepos = NULL;
      char *bufptr = buffer;
      for (tokenct = 1;; ++tokenct) {
         char *token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = NULL;
         if (token == NULL) break;
         printf ("token %d.%d: [%s]\n",
                 linenr, tokenct, token);
         sn = intern_stringtable(st, token);
      }
   }
   strcat(base,".str");
   FILE *fp = fopen(base,"w");
   debugdump_stringtable(st,fp);
   fclose(fp);
}

// Print signal information.  
void eprint_signal (char *kind, int signal) {
   fprintf (stderr, ", %s %d", kind, signal);
   char *sigstr = strsignal (signal);
   if (sigstr != NULL) fprintf (stderr, " %s", sigstr);
}

// Print the status, signal, and core of an exiting process.
void eprint_status (char *command, int status) {
   fflush (NULL);
   if (status == 0) return;
   fprintf (stderr, "%s: status 0x%04X", command, status);
   if (WIFEXITED (status)) {
      fprintf (stderr, ", exit %d", WEXITSTATUS (status));
   }
   // LINTED (warning: cast from 32-bit integer to 8-bit integer)
   if (WIFSIGNALED (status)) {
      eprint_signal ("Terminated", WTERMSIG (status));
      #ifdef WCOREDUMP
      if (WCOREDUMP (status)) fprintf (stderr, ", core dumped");
      #endif
   }
   if (WIFSTOPPED (status)) {
      eprint_signal ("Stopped", WSTOPSIG (status));
   }
   if (WIFCONTINUED (status)) {
      fprintf (stderr, ", Continued");
   }
   fprintf (stderr, "\n");
   fflush (NULL);
}

int main (int argc, char **argv) {
   progname = basename (argv[0]);
   int argi;
   for (argi = 1; argi < argc; ++argi) {
      char *filename = argv[argi];
      char command[strlen (CPP) + 1 + strlen (filename) + 1];
      strcpy (command, CPP);
      strcat (command, " ");
      strcat (command, filename);
      printf ("command=\"%s\"\n", command);
      FILE *pipe = popen (command, "r");
      if (pipe == NULL) {
         syswarn (command);
      }else {
         cpplines (pipe, filename);
         int pclose_rc = pclose (pipe);
         eprint_status (command, pclose_rc);
      }
   }
   return EXIT_SUCCESS;
}

