#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *f1 = fopen("in.txt", "r");
	FILE *f2 = fopen("out.txt", "w");
	
	char surname[100], name[100], secname[100];
	int year;
	
	if(f1 != NULL) {
		while(fscanf(f1, "%s %s %s %d", surname, name, secname, &year) == 4) {
			if(year > 1980) fprintf(f2, "%s %s %s %d\n", surname, name, secname, year);
		}
		
		fclose(f1);
		fclose(f2);
		
		printf("File 'out.txt' was successfully overwritten!");
	} else {
		printf("Couldn't detect 'in.txt' file. Try again.");
	}
	
    return 0;
}
