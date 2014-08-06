#ifndef VERLAG_VM_H
#define VERLAG_VM_H

typedef struct verlag_state_s {
  int ip; // holds current place in vm code
  int sp; // holds current place in stack
  int fp; // ?

  int code[100];
  int stack[10];
} verlag_state;

void verlag_init (verlag_state *);
void verlag_cpu (verlag_state *);

#endif
