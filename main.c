#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(){
  pid_t p;
  int PID = getpid();
  printf("%d about to create 2 child processes\n",PID);
  int r = srand(time(NULL));
  p = fork();
  if(p != 0){
    p = fork();
  }
  if(p == 0){
    int PID = getpid();
    printf("%d\n",PID);
  }
}
