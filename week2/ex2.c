#include <stdio.h>
#include <string.h>

int main(){
  char usr_string[128];

  scanf("%s", usr_string);

  for(int i = 0; i < strlen(usr_string)/ 2; i++){
    char tmp = usr_string[i];		
    usr_string[i] = usr_string[strlen(usr_string)-1-i];
    usr_string[strlen(usr_string)-1-i] = tmp;
  }

  printf("%s\n", usr_string);

  return 0;
}
