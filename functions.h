#ifndef VERLAG_FUNCTIONS_H
#define VERLAG_FUNCTIONS_H

void verlag_HALT (verlag_state *);
void verlag_PUSH (verlag_state *);
void verlag_POP (verlag_state *);
void verlag_PRINT (verlag_state *);
void verlag_IADD (verlag_state *);
void verlag_ISUB (verlag_state *);
void verlag_IMUL (verlag_state *);
void verlag_ILT (verlag_state *);
void verlag_IEQ (verlag_state *);
void verlag_BR (verlag_state *);
void verlag_BRT (verlag_state *);
void verlag_BRF (verlag_state *);
void verlag_LOAD (verlag_state *);
void verlag_GLOAD (verlag_state *);
void verlag_STORE (verlag_state *);
void verlag_GSTORE (verlag_state *);

static void (*verlag_functions[]) (verlag_state *) = {
  verlag_HALT,
  verlag_PUSH,
  verlag_POP,
  verlag_PRINT,
  verlag_IADD,
  verlag_ISUB,
  verlag_IMUL,
  verlag_ILT,
  verlag_IEQ,
  /* verlag_BR, */
  /* verlag_BRT, */
  /* verlag_BRF, */
  /* verlag_LOAD, */
  /* verlag_GLOAD, */
  /* verlag_STORE, */
  /* verlag_GSTORE */
};

#endif
