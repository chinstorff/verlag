#include "bytecode.h"
#include "vm.h"

void copy_array (int from[], int to[], int length) {
  int i;
  for (i = 0; i < length; i++) {
    to[i] = from[i];
  }
}


int main () {
  verlag_state s;
  verlag_init(&s);

  int code[3] = { ICONST, 2, PRINT };
  copy_array(code, s->code, 3);

  cpu(&s);
}

