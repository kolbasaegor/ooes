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
  char input[1024];
  fgets(input, 1024, stdin);
  int size_of_par = 0;  

  char *token = strtok(input, " ");
  par[size_of_par++] = strdup(token);
  printf("%s lenght = %ld\n", token, strlen(token)); 
  

  while(token != NULL){
    token = strtok(NULL, " ");
    if(token != NULL){
      par[size_of_par++] = strdup(token);
    }
  }
  par[size_of_par] = NULL;
 
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






