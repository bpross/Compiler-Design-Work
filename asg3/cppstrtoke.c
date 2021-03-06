// $Id: cppstrtok.c,v 1.7 2011-09-28 13:51:18-07 - - $

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

// Run cpp against the lines of the file.
void cpplines (FILE *pipe, char *filename) {
   int linenr = 1;
   char inputname[LINESIZE];
   strcpy (inputname, filename);
   for (;;) {
      char buffer[LINESIZE];
      char *fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == NULL) break;
      chomp (buffer, '\n');
      printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      char flags[LINESIZE];
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"%[^\n]",
                              &linenr, filename, flags);
      if (sscanf_rc == 3) {
         printf ("Directive: line %d, file \"%s\", flags \"%s\"\n",
                 linenr, filename, flags);
         continue;
      }
      char *savepos = NULL;
      char *bufptr = buffer;
      for (int tokenct = 1;; ++tokenct) {
         char *token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = NULL;
         if (token == NULL) break;
         printf ("token %d.%d: [%s]\n",
                 linenr, tokenct, token);
      }
   }
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
   for (int argi = 1; argi < argc; ++argi) {
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

//TEST// cid + foo*.*
//TEST// runprog -x cppstrtok.lis cppstrtok foo.oc
//TEST// catnv foo*.* >cppstrtok.input
//TEST// mkpspdf cppstrtok.ps cppstrtok.c cppstrtok.c.log \
//TEST//        cppstrtok.input cppstrtok.lis
