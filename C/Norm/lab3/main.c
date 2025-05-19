#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	
	char str[81];
	
	printf("Type the sentence: ");
	fgets(str, sizeof(str), stdin);

	for(int i = 0; i < sizeof(str); i++) {
		if(str[i] == 'a') str[i] = 'A';
		if(str[i] == 'b') str[i] = 'B';
	}
	
	printf("Result: %s", str);
	return 0;
}
