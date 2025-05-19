#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	char stroka[100], strokaFormat[100], strokaFinal[100];
	
	char *istr;
	char sep[10] = " ";

	double result; // -123.5 + 4 - 456+56 -> -123.5 +4 -456 +56 -> -519.50000
	int count = 0;
	int offset = 0;
	
	// Getting the numbers
			
	printf("Type: ");
	fgets(stroka, sizeof(stroka), stdin);
	
	// Formatting

	while(count < 100) {
		if(stroka[count] == ' ') {
			strokaFormat[count+offset] = ' ';
		} else {
			strokaFormat[count+offset] = stroka[count];
		}
		
		if(stroka[count] != ' ') {
			if(stroka[count+1] == '+') {
				strokaFormat[count+offset] = stroka[count];
				offset++;
				strokaFormat[count+offset] = ' ';
				strokaFormat[count+offset+1] = stroka[count+1];
			}
			
			if(stroka[count+1] == '-') {
				strokaFormat[count+offset] = stroka[count];
				offset++;
				strokaFormat[count+offset] = ' ';
				strokaFormat[count+offset+1] = stroka[count+1];
			}
		}
		
		count++;
	}
	
	printf("%s\n", strokaFormat);
	count = offset = 0;

	while(count < 100) {
		if(strokaFormat[count+offset] == '+') {
			if(strokaFormat[count+offset+1] == ' ') {
				strokaFinal[count] = strokaFormat[count+offset];
				count++;
				offset++;
			}
		}
		
		if(strokaFormat[count+offset] == '-') {
			if(strokaFormat[count+offset+1] == ' ') {
				strokaFinal[count] = strokaFormat[count+offset];
				count++;
				offset++;
			}
		}

		strokaFinal[count] = strokaFormat[count+offset];
		count++;
	}
	
	printf("%s\n", strokaFinal);
	count = offset = 0;
	
	// Result
	
	istr = strtok(strokaFinal, sep);
	while(istr != NULL) {
        result += atof(istr);
		istr = strtok(NULL, sep);
	}

	printf("%lf\n", result);
	
	return 0;
}
