
#include <stdio.h>
#include <assert.h>

#include "astree.h"
#include "astree.rep.h"
#include "emit.h"
#include "lyutils.h"
#include "auxlib.h"

void emit (astree);

void emit_insn (char *opcode, char *operand, astree tree) {
   printf ("%-10s%-10s%-20s; %s %d.%d\n", "",
            opcode, operand, scanner_filename (tree->filenr),
            tree->linenr, tree->offset);
}

void postorder (astree tree) {
   astree itor;
   assert (tree != NULL);
   for (itor = tree->first; itor != NULL; itor = itor->next) {
      emit (itor);
   }
}

void postorder_emit_stmts (astree tree) {
   postorder (tree);
}

void postorder_emit_oper (astree tree, char *opcode) {
   postorder (tree);
   emit_insn (opcode, "", tree);
}

void postorder_emit_semi (astree tree) {
   postorder (tree);
   emit_insn ("", "", tree);
}

void emit_push (astree tree, char *opcode) {
   assert (tree != NULL);
   assert (tree->first == NULL);
   emit_insn (opcode, tree->lexinfo, tree);
}

void emit_assign (astree tree) {
   astree left = NULL;
   assert (tree != NULL);
   left = tree->first;
   assert (left != NULL);
   assert (left->next != NULL);
   assert (left->next->next == NULL);
   emit (left->next);
   if (left->symbol != IDENT) {
      eprintf ("%:%s: %d: left operand of `=' is not an identifier\n",
               scanner_filename (left->filenr), left->linenr);
   }else{
      emit_insn ("popvar", left->lexinfo, left);
   }
}

void emit (astree tree) {
   assert (is_astree (tree));
   switch (tree->symbol) {
      case ROOT  : postorder_emit_stmts (tree);       break;
      case ';'   : postorder_emit_semi (tree);        break;
      case '='   : emit_assign (tree);                break;
      case '+'   : postorder_emit_oper (tree, "add"); break;
      case '-'   : postorder_emit_oper (tree, "sub"); break;
      case '*'   : postorder_emit_oper (tree, "mul"); break;
      case '/'   : postorder_emit_oper (tree, "div"); break;
      case '^'   : postorder_emit_oper (tree, "pow"); break;
      case POS   : postorder_emit_oper (tree, "pos"); break;
      case NEG   : postorder_emit_oper (tree, "neg"); break;
      case IDENT : emit_push (tree, "pushvar");       break;
      case NUMBER: emit_push (tree, "pushnum");       break;
      default    : assert (! "emit default");         break;
   }
}

void emit_sm_code (astree tree) {
   printf ("\n");
   if (tree) emit (tree);
}

// LINTED(static unused)
RCSC(EMIT_C,"$Id: emit.c,v 1.4 2011-09-21 18:54:07-07 - - $")

