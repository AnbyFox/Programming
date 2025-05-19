#include <stdio.h>
#include <string.h>

// https://habr.com/ru/articles/276957/

typedef unsigned int       u32;
typedef unsigned long long u64;

u32 count_long(u32 n) {
	u32 result = 0;
    while(n) {
    	result++;
    	n &= n-1;
	}
	
	return result;
}

u64 count_double(u64 n) {
	u64 result = 0;
    while(n) {
    	result++;
    	n &= n-1;
	}
	
	return result;
}

int main() {
	while(1) {
		long num_long;
	    printf("Type <long> number: "); scanf("%ld", &num_long);
	    printf("- This number has %d set bytes.\n", count_long(num_long));
	    
		double num_double;
	    printf("Type <double> number: "); scanf("%lf", &num_double);
	    printf("- This number has %d set bytes.\n\n", count_double(num_double));
	}

    return 0;
}
