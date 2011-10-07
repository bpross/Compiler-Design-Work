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
#include <unistd.h>
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

// checks to see if the file has a valid extension
// removes the extension if it is valid
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
   /* Create new stringtable */
   stringtable_ref st = new_stringtable();
   stringnode_ref sn;
   strcpy (inputname, filename);
   /* For loop to run through the file */
   for (;;) {
      char buffer[LINESIZE];
      /* Get next line */
      char *fgets_rc = fgets (buffer, LINESIZE, pipe);
      /* If next line is NULL, loop is done */
      if (fgets_rc == NULL) break;
      /* Replace \n with '\0' */
      chomp (buffer, '\n');
      /* Scan and clean out symbols we dont want */
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, filename);
      if (sscanf_rc == 2) {
         printf ("Directive: line %d, file \"%s\"\n",
                 linenr, filename);
         continue;
      }
      char *savepos = NULL;
      char *bufptr = buffer;
      /* Run through the line and proccess each token */
      for (tokenct = 1;; ++tokenct) {
         char *token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = NULL;
         if (token == NULL) break;
         printf ("token %d.%d: [%s]\n",
                 linenr, tokenct, token);
         sn = intern_stringtable(st, token);
      }
   }
   remove_file_ext(base);
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
   int c;
   int lflag, yflag,dflag,total_args = 0;
   char *debug_flag;
   extern char *optarg;
   extern int optind, optopt;

   /* Check to see if there are options */
   while ((c = getopt(argc, argv, ":ly:D:")) != -1) {
     switch(c) {
     case 'l':
       fprintf(stderr,"Debug yylex is turned on\n");
       lflag = 1;
       total_args++;
       break;
     case 'y':
       fprintf(stderr,"Debug yyparse is turned on\n");
       yflag = 1;
       total_args++;
       break;
     case 'D':
       debug_flag = optarg;
       dflag = 1;
       total_args++;
       break;
     case '?':
       fprintf(stderr,"Unrecognized option: -%c\n", optopt);
       exit(1);
     }
   }

   int argi;
   /* Scan through the input file(s) */
   for (argi = total_args; argi < argc; ++argi) {
      /* Create new char array to hold the filename */
      char *filename = argv[argi];
      char command[strlen (CPP) + 1 + strlen (filename) + 1];
      strcpy (command, CPP);
      if(dflag == 1) {
          strcat (command, " ");
          strcat (command, "-D ");
          strcat (command, debug_flag);
      }
      strcat (command, " ");
      strcat (command, filename);
      printf ("command=\"%s\"\n", command);
      /* Make pipe */
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

