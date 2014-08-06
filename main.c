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

  int code[] = { ICONST, 2, ICONST, 3, IADD, PRINT, ICONST, 4, ICONST, 3, ISUB, PRINT };
  copy_array(code, s.code, 12);

  verlag_cpu(&s);
}
