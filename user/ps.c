// mastoras ->>
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"


struct pstat st;

static char*
stname(int s)
{
  switch(s){
  case 0: return "UNUSED";
  case 1: return "USED";
  case 2: return "SLEEP";
  case 3: return "RUNNABLE";
  case 4: return "RUNNING";
  case 5: return "ZOMBIE";
  }
  return "?";
}

int
main(void)
{
  if(getpinfo(&st) < 0){
    printf("getpinfo failed\n");
    exit(1);
  }

  printf("PID\tPPID\tPRIO\tSTATE\tNAME\n");

  for(int i = 0; i < NPROC; i++){
    if(st.pid[i] == 0) continue;
        printf("%d\t%d\t%d\t%s\t%s\n",
            st.pid[i], st.ppid[i], st.priority[i],
            stname(st.state[i]), st.name[i]);
  }

  exit(0);
}
// <<- mastoras
