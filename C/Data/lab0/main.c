#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
	printf("Type the range: "); scanf("%d", &n);

	int P[n];
	int i, j;
	int p = 2;
	
	// Fill the massive with nums from 2 to N.
	for(i = 0; i < n; i++) P[i] = i + 2;
	
	while(p*p <= n) {
		// Replace nums which can be devided to P. (from 2*P to N)
		for(i = (2*p)-2; i < n; i++) if(P[i] % p == 0) P[i] = 0;
		
		// P will take the first number which doesn't equal 0.
		for(j = 0; j < n; j++) if(p < P[j]) {
			p = P[j];
			break;
		}
	}

	// Result.
    printf("Simple numbers: ");
	for(i = 0; i < n; i++) if(P[i] != 0) printf("%d ", P[i]);
	
    return 0;
}
