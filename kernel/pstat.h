// mastoras ->>
#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"   // για NPROC

struct pstat {
  int pid[NPROC];
  int ppid[NPROC];
  int priority[NPROC];
  int state[NPROC];
  char name[NPROC][16];
};

#endif
// <<- mastoras
