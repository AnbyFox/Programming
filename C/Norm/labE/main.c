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

int fibonacci_opt(int n, int prev2, int prev1) {
    if (n == 0) return prev2;
    if (n == 1) return prev1;
    
    return fibonacci_opt(n - 1, prev1, prev2 + prev1);
}

int sum_fib(jmp_buf buffer, int n) {
    int sum = 0;
    //for(int i = 0; i <= n; i++) sum += fibonacci(i);
    sum = fibonacci_opt(n, 0, 1);
	
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
