#ifndef VERLAG_VM_H
#define VERLAG_VM_H

typedef struct verlag_state_s {
  int ip; // holds current place in vm code
  int sp; // holds current place in stack
  int fp; // ?

  int code[100];
  int stack[10];

  int running;
} verlag_state;

void verlag_init (verlag_state *);
void verlag_cpu  (verlag_state *);
void verlag_stack_push (verlag_state *, int);
int  verlag_stack_pop  (verlag_state *);
void verlag_vm_err (verlag_state *, char *);

#endif
