#include <stdio.h>
#include <stdlib.h>

// n - number of processes
// m - number of types
// E - existnce resources
// A - Available resources
// E_j = A_i + sum from i = 1 to n (C_ij)
// C - current allocation maxtrix
// R - request matrix

/*
 * algorithm for detecting deadlock.
 * the same one that was at the lab
 */
void deadlock_check(int n, int m, int *E, int *A, int **C, int **R){
	int *term_proc = calloc(n, sizeof(int));
	
	int swap = 1;
	
	while(swap){
		swap = 0;
		for(int i = 0; i < n; i++){
			if(term_proc[i] == 0){
				int free_proc = 1;
				for(int j = 0; j < m; j++){
					if(R[i][j] > A[j]){
						free_proc = 0;
						break;
					}
				}
				if(free_proc){
					
					swap = 1;
					term_proc[i] = 1;
					for(int j = 0; j < m; j++){
						A[j] += C[i][j];
						C[i][j] = 0;
					}
				}
			}
		}
	}
	
	int dead = 0;
	
	for(int i = 0; i < n; i++){
		if(term_proc[i] == 0){
			printf("process %d is deadlocked\n", i+1);
			dead = 1;
		}
	}
	if(!dead)
		printf("there is no deadlock\n");
	
	
}

int main(){
	int n,m;
	int *E; int *A;
	int **C;int **R;
	
	/*
	 * reading from file
	 */
	FILE *fp;
    char name[] = "input.txt";
    if ((fp = fopen(name, "r")) == NULL)
    {
      printf("cant open the file");
      return 0;
    }
   
    fscanf(fp,"%d", &n);
    fscanf(fp,"%d", &m);
    
    E = malloc(m * sizeof(int));
	A = malloc(m * sizeof(int));
	
	C = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        C[i] = malloc(m * sizeof(int));
    }
    
    R = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        R[i] = malloc(m * sizeof(int));
    }
   
    for(int i = 0; i < m; i++){
    	fscanf(fp, "%d", &E[i]);
    }
    for(int i = 0; i < m; i++){
    	fscanf(fp, "%d", &A[i]);
    }
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		fscanf(fp, "%d", &C[i][j]);
    	}
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		fscanf(fp, "%d", &R[i][j]);
    	}
    }
   
    fclose(fp);
   
    deadlock_check(n,m,E,A,C,R);


	return 0;
}

