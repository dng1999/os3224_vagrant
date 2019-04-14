#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[]){
  int numForks = 20;
  int i;

  int wtime;
  int rtime;
  int iotime;
  int pid;

  printf(1, "pid\tready\trunning\tsleeping\t\n");
  for (i = 0; i < numForks; i++) {
		pid = fork();
		if (pid) { //aka parent process
      continue;
    }
    else { //aka child process
      int j;
      int timeEater = 0;
      for (j = 0; j < 200000000; j++){
        timeEater = (24.012/7.59)*2.54;
      }
      timeEater++;
      for(j = 0; j < 100; j++){
        sleep(1);
      }
      exit();
    }
  }
  int totWtime = 0;
  int totRtime = 0;
  int totIOtime = 0;
  for (i = 0; i < numForks; i++) {
    //&pid should be last child proc
		pid = wait_stat(&wtime, &rtime, &iotime, &pid);
    totWtime += wtime;
    totRtime += rtime;
    totIOtime += iotime;
		printf(1, "%d\t%d\t%d\t%d\n", pid, wtime, rtime, iotime);
  }
  printf(1, "AVG\t%d\t%d\t%d\n", totWtime/numForks, totRtime/numForks, totIOtime/numForks);
  exit();
}