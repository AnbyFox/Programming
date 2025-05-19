#include <stdio.h>
#include <stdlib.h>

#include "tringle.h"

int main(int argc, char *argv[]) {
	
	double a, b, c;
	
	while (1) {
		printf("Type a value for A side: ");
		scanf("%lf", &a);
			
		printf("Type a value for B side: ");
		scanf("%lf", &b);
			
		printf("Type a value for C side: ");
		scanf("%lf", &c);
		
		if(tringleExists(a,b,c)) {
			double curP, curS;
			curP = Pmath(a, b, c);
			curS = Smath(a, b, c, curP/2);
			
			printf("\nTriangle's P: %lf", curP);
			printf("\nTriangle's S: %lf", curS);
		} else {
			printf("\nTriangle doesn't exist.");
		}
		
		printf("\n\n");
	}

	return 0;
}
