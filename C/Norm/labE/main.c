#include <stdio.h>
#include <setjmp.h>

int fibonacci(int n) {
	if (n == 0)
		return 0;
    else if (n == 1)
		return 1;
    else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int sum_fib(jmp_buf buffer, int n) {
    int sum = 0;
    for(int i = 0; i <= n; i++) sum += fibonacci(i);
	
	longjmp(buffer, sum);
}

int main() {
	jmp_buf buffer = {0};
	
    int n;
    printf("Type N: "); scanf("%d", &n);
    
    int result = setjmp(buffer);
    if(result == 0) sum_fib(buffer, n);
    
    printf("Sum: %d", result);
}
