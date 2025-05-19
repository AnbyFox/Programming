#include <stdio.h>
#include <stdlib.h>

#include "massives.h"

int main(int argc, char *argv[]) {
	
	int n = 2;
	char choice;
	
	while(1) {
		printf("Type the length of 'n': ");
		scanf("%d", &n);
		
		if(n < 1) n = 1;
		
		double **M1, **M2, **M;
		M1 = (double**)malloc(n*sizeof(double*));
		M2 = (double**)malloc(n*sizeof(double*));
		
		for(int i = 0; i < n; i++) {
			M1[i] = (double*)malloc(n*sizeof(double));
			M2[i] = (double*)malloc(n*sizeof(double));
		}
		
		for(int i = 0; i < n; i++) {
		    for(int j = 0; j < n; j++) {
		    	printf("- Type value for [%d][%d] argument for 1st massive: ", i, j);
			    scanf("%lf", &M1[i][j]);
		    }
		}
		
		for(int i = 0; i < n; i++) {
		    for(int j = 0; j < n; j++) {
		    	printf("- Type value for [%d][%d] argument for 2nd massive: ", i, j);
			    scanf("%lf", &M2[i][j]);
		    }
		}
		
		printf("Select the math action: (+|-|*) ");
		scanf(" %c", &choice);
		
		M = massiveOperation(n, M1, M2, choice);
		
		printf("Result Massive = [\n");
		for(int i = 0; i < n; i++) {
		    for(int j = 0; j < n; j++) {
		    	if(j == 0) printf("  ");
				printf("[%lf]", M[i][j]);
				if(j == (n-1)) printf("\n");
		    }
		} 
		printf("]\n\n");
		
		for(int i = 0; i < n; i++) {
			free(M1[i]);
			free(M2[i]);
			free(M[i]);
		}
		free(M1);
		free(M2);
		free(M);
	}
}
