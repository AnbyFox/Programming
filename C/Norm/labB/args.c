#include <stdio.h>
#include <stdarg.h>

int arg_sum(int n, ...) {
	int result = 0;
		
	va_list list;
    va_start(list, n);
    while(n) {
    	result += va_arg(list, int);
    	--n;
	}
	
	va_end(list);

	return result;
}

int arg_max(int n, ...) {
	int result = 0;
	int M[n];
		
	va_list list;
    va_start(list, n);
    for(int i = 0; i < n; i++) {
    	M[i] = va_arg(list, int);
    	if(result < M[i]) result = M[i];
	}
	
	va_end(list);

	return result;
}

int arg_min(int n, ...) {
	int result = 0;
	int M[n];
		
	va_list list;
    va_start(list, n);
    for(int i = 0; i < n; i++) {
    	M[i] = va_arg(list, int);
	}
	
	va_end(list);
	
	result = M[n-1];
	for(int i = 0; i < n; i++) {
    	if(result > M[i]) result = M[i];
	}

	return result;
}

int arg_avg(int n, ...) {
	int result = 0;
	int M[n];
		
	va_list list;
    va_start(list, n);
    for(int i = 0; i < n; i++) {
    	M[i] = va_arg(list, int);
    	result += M[i];
	}
	
	va_end(list);
	
	result /= n;

	return result;
}