enum {
  HALT,
  ICONST,
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
  GSTORE,  // store in global
  POP,
};
