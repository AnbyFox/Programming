#include <stdio.h>
#include <stdlib.h>

double** massiveOperation(int size, double **M1, double **M2, char operation) {
	
    double **M;
	M = (double**)malloc(size*sizeof(double*));
	
	for(int i = 0; i < size; i++) {
		M[i] = (double*)malloc(size*sizeof(double));
	}
	
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			M[i][j] = M1[i][j] + M2[i][j];
			if(operation == '-') M[i][j] = M1[i][j] - M2[i][j];
			if(operation == '*') M[i][j] = M1[i][j] * M2[i][j];
			if(operation == '/') M[i][j] = M1[i][j] / M2[i][j];
		}
	}  
	
	return M;
}