#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(){
	char *ptr;
	int size = 10 * 1024 * 1024;
	for(int i = 0; i < 10; i++){
		ptr = malloc(size);
		memset(ptr, 0, size);
		sleep(1);
	}
	
	return 0;
}
