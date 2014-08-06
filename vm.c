#include <stdio.h>
#include <stdlib.h>
#include "bytecode.h"
#include "vm.h"

void verlag_init (verlag_state *s) {
  s->ip = 0;
  s->sp = -1;
  
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
  while (s->ip < 100) { // 100 == a->code.length
    opcode = s->code[(s->ip)++];

    printf("%04d: %s", s->ip, opcodes[opcode]);

    switch (opcode) {
    case PUSH: {
      printf("\t%d", s->code[s->ip]);
      push(s, s->code[(s->ip)++]);
    } break;
    case POP: {
      pop(s);
    } break;
    case PRINT: {
      printf("\n%d", pop(s));
    } break;
    case IADD: {
      int b = pop(s);
      int a = pop(s);
      push(s, a + b);
    } break;
    case ISUB: {
      int b = pop(s);
      int a = pop(s);
      push(s, a - b);
    } break;
    case IMUL: {
      int b = pop(s);
      int a = pop(s);
      push(s, a * b);
    } break;
    case ILT: {
      int b = pop(s);
      int a = pop(s);
      push(s, a < b);
    } break;
    case IEQ: {
      int b = pop(s);
      int a = pop(s);
      push(s, a == b);
    } break;
    case HALT: {
      printf("\n");
      return;
    } break;
    }

    printf("\n");
  }
}

void push (verlag_state *s, int value) {
  if (s->sp + 1 >= 10) {
    verlag_vm_err(s, "\nERROR: stack overflow");
  }
  s->stack[++(s->sp)] = value;
}

int pop (verlag_state *s) {
  if (s->sp - 1 < -1) {
    verlag_vm_err(s, "\nERROR: can't POP an empty stack");
  }
  return s->stack[(s->sp)--];
}

void verlag_vm_err (verlag_state *s, char *e) {
  puts(e);
  exit(1);
}
