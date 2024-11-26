#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  pid_t p;
  int status;
  int PID = getpid();
  printf("%d about to create 2 child processes\n",PID);
  p = fork();
  if(p != 0){
    p = fork();
  }
  if(p == 0){
    int PID = getpid();
    srand(PID);
    int r = rand()%5 + 1;
    printf("%d %dsec\n",PID,r);
    sleep(r);
    printf("%d finished after %dsec\n",PID,r);
    return(r);
  }
  if(p != 0){
    pid_t d = wait(&status);
    int r = WEXITSTATUS(status);
    printf("Main Process %d is done. Child %d slept for %dsec\n",PID,d,r);
  }
}
