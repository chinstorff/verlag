#include "bytecode.h"
#include "vm.h"

void verlag_init (verlag_state *s) {
  s->ip = 0;
  s->sp = -1;

  for (int i = 0; i < 100; i++) {
    s->code[i] = 0;
  }

  for (int i = 0; i < 10; i++) {
    s->stack[i] = 0;
  }
}
