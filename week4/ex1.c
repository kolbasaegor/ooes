#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
  int n;
  pid_t x = fork();

  if(x == 0){
    printf("Hello from child [%d - %d]\n", getpid(), n);
  } else {
    printf("Hello from parent [%d - %d]\n", getpid(), n);
  }

  return EXIT_SUCCESS;

}
