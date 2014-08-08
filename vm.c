#include <stdio.h>
#include <stdlib.h>
#include "vm.h"
#include "bytecode.h"
#include "functions.h"

void verlag_init (verlag_state *s) {
  s->ip = 0;
  s->sp = -1;
  
  s->running = 1;

  int i;
  for (i = 0; i < 100; i++) {
    s->code[i] = 0;
  }

  for (i = 0; i < 10; i++) {
    s->stack[i] = 0;
  }
}

void verlag_cpu (verlag_state *s) {
  int opcode;
  while (s->running && s->ip < 100) { // 100 == a->code.length
    opcode = s->code[(s->ip)++];

    printf("%04d: %s", s->ip, opcodes[opcode]);

    verlag_functions[opcode](s);

    printf("\n");
  }
}

void verlag_stack_push (verlag_state *s, int value) {
  if (s->sp + 1 >= 10) {
    verlag_vm_err(s, "\nERROR: stack overflow");
  }
  s->stack[++(s->sp)] = value;
}

int verlag_stack_pop (verlag_state *s) {
  if (s->sp - 1 < -1) {
    verlag_vm_err(s, "\nERROR: can't POP an empty stack");
  }
  return s->stack[(s->sp)--];
}

void verlag_vm_err (verlag_state *s, char *e) {
  puts(e);
  exit(1);
}

