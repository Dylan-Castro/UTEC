#include <sys/types.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#define number_of_testcase 100
struct timespec start, finish;
void void_function(){}
void pipes(){
  clock_gettime(CLOCK_REALTIME, &start);

  char *message_parent="p";
  char *message_child="c";
  int p1[2],p2[2];
  pid_t cpid;
  if (pipe(p1) == -1) {
      perror("pipe");
      exit(EXIT_FAILURE);
  }
  if (pipe(p2) == -1) {
      perror("pipe");
      exit(EXIT_FAILURE);
  }
  cpid = fork();
  if (cpid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
  }

  if (cpid == 0) {
      close(p1[1]);
      close(p2[0]);
      write(p2[1],message_child, 1);
      close(p2[1]);
      read(p1[0], &message_child, 1);
      close(p1[0]);
      _exit(EXIT_SUCCESS);

  } else {
      close(p1[0]);
      close(p2[1]);
      write(p1[1],message_parent, 1);
      close(p1[1]);
      wait(NULL);
      read(p2[0], &message_parent, 1);
      close(p2[0]);
  }

  clock_gettime(CLOCK_REALTIME, &finish);
}
void sys_call(){
  clock_gettime(CLOCK_REALTIME, &start);
  getpid();
  clock_gettime(CLOCK_REALTIME, &finish);
}
double calc_time(long seconds,long ns){
  if (start.tv_nsec > finish.tv_nsec) { // clock underflow
	--seconds;
	ns += 1000000000;
    }
    return (double)seconds + (double)ns/(double)1000000000;
}
int main(){
  double prom;
  for (int i = 0; i < number_of_testcase; i++) {
    //clock_gettime(CLOCK_REALTIME, &start);
    //void_function();                              //Funcion minima
    //clock_gettime(CLOCK_REALTIME, &finish);
    //sys_call();                                     //Syscall minimo
    //pipes();                                      //Cambio de contexto
    prom+=calc_time(finish.tv_sec - start.tv_sec,finish.tv_nsec - start.tv_nsec);
  }
  printf("Promedio de tiempo de ejecucion(seg): %e\n", prom/number_of_testcase);
}
