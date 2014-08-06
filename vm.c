#include <stdio.h>
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

    switch (opcode) {
    case ICONST: {
      s->stack[++(s->sp)] = s->code[(s->ip)++];
    } break;
    case PRINT: {
      printf("%d", s->stack[(s->sp)--]);
    } break;
    case IADD: {
      int b = s->stack[(s->sp)--];
      int a = s->stack[(s->sp)--];
      s->stack[++(s->sp)] = a + b;
    } break;
    case ISUB: {
      int b = s->stack[(s->sp)--];
      int a = s->stack[(s->sp)--];
      s->stack[++(s->sp)] = a - b;
    } break;
    case IMUL: {
      int b = s->stack[(s->sp)--];
      int a = s->stack[(s->sp)--];
      s->stack[++(s->sp)] = a * b;    
    } break;
    case POP: {
      (s->sp)--;
    } break;
    case HALT: {
      return;
    } break;
    }
  }
}
