#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	
	int task_type = 1;
	// 1 - 1st task with 3x3 massive
	// 2 - 2nd task with 2x2 massive 
	
	if(task_type == 1) {
	    double M[3][3];
	    
	    for(int i = 0; i < 3; i++) {
	    	for(int j = 0; j < 3; j++) {
	    		printf("Type value for %d %d argument: ", i, j);
		        scanf("%lf", &M[i][j]);
	    	}
	    }
		
	    double a, b;
	    a = M[0][0] + M[1][1] + M[2][2];
	    b = M[2][0] + M[1][1] + M[0][2];
	    printf("\nMain horizontal line summ = %lf\n", a);
	    printf("Side horizontal line summ = %lf", b);
	} else {
	    int M[2][2];
		
		int num;
	    for(int i = 0; i < 2; i++) {
	    	for(int j = 0; j < 2; j++) {
	    	    printf("Type value for %d %d argument: ", i, j);
		        scanf("%d", &num);
		        M[i][j] = num * num;
	    	}
	    }
		
	    printf("\nCurrent massive:\n");
	    for(int i = 0; i < 2; i++) {
	    	for(int j = 0; j < 2; j++) {
	    	    printf("[%d]", M[i][j]);
	    	    if(j > 0) printf("\n");
	    	}
	    }
		
	}
	
	return 0;
}
