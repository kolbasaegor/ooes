#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(){
	char *ptr;
	struct rusage usage;
	int size = 10 * 1024 * 1024;
	for(int i = 0; i < 10; i++){
		ptr = malloc(size);
		memset(ptr, 0, size);
		getrusage(RUSAGE_SELF, &usage);
		printf("%lu\n", usage.ru_maxrss);
		sleep(1);
	}

	return 0;
}
