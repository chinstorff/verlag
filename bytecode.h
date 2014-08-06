#ifndef VERLAG_BYTECODE_H
#define VERLAG_BYTECODE_H

enum {
  HALT,
  PUSH,
  POP,
  PRINT, 
  IADD,
  ISUB,
  IMUL,
  ILT,     // int less than
  IEQ,     // int equal
  BR,      // branch
  BRT,     // branch if true
  BRF,     // branch if false
  LOAD,    // load from local
  GLOAD,   // load from global
  STORE,   // store in local
  GSTORE  // store in global
};

static char *opcodes[] = {
  "HALT",
  "PUSH",
  "POP",
  "PRINT",
  "IADD",
  "ISUB",
  "IMUL",
  "ILT",
  "IEQ",
  "BR",
  "BRT",
  "BRF",
  "LOAD",
  "GLOAD",
  "STORE",
  "GSTORE"
};

#endif
