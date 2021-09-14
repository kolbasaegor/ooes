#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
  char command[100];

  while(1){
    scanf("%s", command);
    if(strcmp(command, "exit") == 0)
      break;
    system(command);
  }
  system("exit");

  return 0;
}
