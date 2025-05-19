#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	
	double a,b,c;
	double x1,x2,d;
		
    while (1) {
		printf("Type a value for A argument: ");
		scanf("%lf", &a);
		
		printf("Type a value for B argument: ");
		scanf("%lf", &b);
		
		printf("Type a value for C argument: ");
		scanf("%lf", &c);
		
		d = pow(b, 2) - (4*a*c);
		
		if (d < 0) printf("\nDiscrimant is negative.\n");
		else if(d == 0) {
		    x1 = -b / (2*a);
		} else {
		    x1 = (-b + sqrt(d)) / (2*a);
		    x2 = (-b - sqrt(d)) / (2*a);
		}
	
		if (d >= 0) printf("\nDiscriminant = %lf", d);
		if (d >= 0) printf("\nX1 = %lf", x1);
		if (d > 0) printf("\nX2 = %lf", x2);
		
		printf("\n\n");
    }
    
    return 0;
}
