#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

void type_promt(){
  static int first_time = 1;

  if(first_time == 1){
    system("clear");
    first_time = 0; 
  }

  printf("$");
}

void read_input(char *par[]){
  char *input; int t = 0, b = 0;
  fgets(input, 10000, stdin);

 char *token = strtok(input, " ");

 while(token != NULL){
   par[b++] = strdup(token);
   token = strtok(NULL, " ");
 }
 par[b] = NULL;

}


int main(){
  char *cmd;
  char *args[128];
  char *envs[] = {NULL};

  while(1){
    type_promt();
    read_input(args);

    if( fork() != 0){
      wait(NULL);
    } else {
      strcpy(cmd, "/bin/");
      strcat(cmd, args[0]);
      execve(cmd, args, envs);
    }
    if(strcmp(args[0], "exit") == 0)
      break;

  }

  return EXIT_SUCCESS;
}






