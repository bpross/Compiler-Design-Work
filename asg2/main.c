#include <libgen.h>
#include <wait.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "astree.h"
#include "lyutils.h"
#include "auxlib.h"
#include "stringtable.h"
#include "strhash.h"

#define CPP "/usr/bin/cpp"

struct options{
   bool dumptree;
   bool echoinput;
};
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


// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assignes opened pipe to FILE *yyin.
char *yyin_cpp_command = NULL;
void yyin_cpp_popen (char *filename) {
   char temp_file[1024];
   strcpy(temp_file,filename);
   char *base = basename(temp_file); char tok[1024];
   remove_file_ext(base);

   strcpy(tok,base);
   strcat(tok,".tok");
   yytok = fopen(tok,"w");

   yyin_cpp_command = malloc (strlen (CPP) + strlen (filename) + 2);
   assert (yyin_cpp_command != NULL);
   strcpy (yyin_cpp_command, CPP);
   strcat (yyin_cpp_command, " ");
   strcat (yyin_cpp_command, filename);
   yyin = popen (yyin_cpp_command, "r");
   if (yyin == NULL) {
      syserrprintf (yyin_cpp_command);
      exit (get_exitstatus());
   }
      int token;
   char toke[1024];
   stringtable_ref st = new_stringtable();
   stringnode_ref sn;
   for (token = yylex(); token != 0; token=yylex()){
      strcpy(toke,get_yytname(token));
      sn = intern_stringtable(st, toke);
   }
   strcat(base,".str");
   FILE *fp = fopen(base,"w");
   debugdump_stringtable(st,fp);
   fclose(fp);
   fclose(yytok);
}


void yyin_cpp_pclose (void) {
   int pclose_rc = pclose (yyin);
   eprint_status (yyin_cpp_command, pclose_rc);
}

void scan_opts (int argc, char **argv, struct options *options) {
   int option;
   opterr = 0;
   yy_flex_debug = 0;
   yydebug = 0;
   for(;;) {
      option = getopt (argc, argv, "@:ely");
      if (option == EOF) break;
      switch (option) {
         case '@': set_debugflags (optarg);   break;
         case 'e': options->echoinput = TRUE; break;
         case 'l': yy_flex_debug = 1;         break;
         case 'y': yydebug = 1;               break;
         default:  errprintf ("%:bad option (%c)\n", optopt); break;
      }
   }
   if (optind > argc) {
      errprintf ("Usage: %s [-ly] [filename]\n", get_execname());
      exit (get_exitstatus());
   }
   char *filename = optind == argc ? "-" : argv[optind];
   yyin_cpp_popen (filename);
   DEBUGF ('m', "filename = %s, yyin = %p, fileno (yyin) = %d\n",
           filename, yyin, fileno (yyin));
   scanner_newfilename (filename);
}

int main (int argc, char **argv) {
   struct options options = {FALSE, FALSE};
   int parsecode = 0;
   set_execname (argv[0]);
   scan_opts (argc, argv, &options);
   scanner_setecho (options.echoinput);
   //parsecode = yyparse();
   if (parsecode) {
      errprintf ("%:parse failed (%d)\n", parsecode);
   }else {
      DEBUGSTMT ('a', dump_astree (stderr, yyparse_astree); );
//      emit_sm_code (yyparse_astree);
   }
   freeast (yyparse_astree);
   yyin_cpp_pclose();
   return get_exitstatus();
}

// LINTED(static unused)
RCSC(MAIN_C,"$Id: main.c,v 1.10 2011-08-31 17:54:03-07 - - $")

