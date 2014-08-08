#include <stdio.h>
#include "vm.h"
#include "bytecode.h"
#include "functions.h"

void verlag_HALT (verlag_state *s) {
  s->running = 0;
}

void verlag_PUSH (verlag_state *s) {
  printf("  %d", s->code[s->ip]);
  verlag_stack_push(s, s->code[(s->ip)++]);
}

void verlag_POP (verlag_state *s) {
  verlag_stack_pop(s);
}

void verlag_PRINT (verlag_state *s) {
  printf("\n%d", verlag_stack_pop(s));
}

void verlag_IADD (verlag_state *s) {
  int b = verlag_stack_pop(s);
  int a = verlag_stack_pop(s);
  verlag_stack_push(s, a + b);
}

void verlag_ISUB (verlag_state *s) {
  int b = verlag_stack_pop(s);
  int a = verlag_stack_pop(s);
  verlag_stack_push(s, a - b);
}

void verlag_IMUL (verlag_state *s) {
  int b = verlag_stack_pop(s);
  int a = verlag_stack_pop(s);
  verlag_stack_push(s, a * b);
}

void verlag_ILT (verlag_state *s) {
  int b = verlag_stack_pop(s);
  int a = verlag_stack_pop(s);
  verlag_stack_push(s, a < b);
}

void verlag_IEQ (verlag_state *s) {
  int b = verlag_stack_pop(s);
  int a = verlag_stack_pop(s);
  verlag_stack_push(s, a == b);
}
