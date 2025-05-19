#include <stdio.h>
#include <ctype.h>

int isvowel(int c);

int main() {
    char filename[256];
    FILE *F;
    
    int c;
    int total = 0;
	int lines = 0, digits = 0, punct = 0, spaces = 0;
	int letters = 0, lowercase = 0, uppercase = 0, vowels = 0, consonants = 0;

    printf("Type the name of the file: "); scanf("%255s", filename);

    // Opening the file.
    F = fopen(filename, "r");
    if (F != NULL) {
	    // Read it simbol by simbol.
	    while((c = fgetc(F)) != EOF) {
	        total++;
	        
	        if(c == '\n') lines++;
	        if(isdigit(c)) digits++;
	        if(ispunct(c)) punct++;
	        if(isspace(c)) spaces++;
	        
	        if(isalpha(c)) {
	            letters++;
	            if(islower(c)) lowercase++;
	            if(isupper(c)) uppercase++;
	            if(isvowel(c)) vowels++; else consonants++;
	        }
	    }
	
	    fclose(F);
	
	    // Result:
	    printf("Total: %d\n\n", total);
	    
	    printf("Lines: %d\n", lines);
	    printf("Digits %d\n", digits);
	    printf("Punct: %d\n", punct);
	    printf("Spaces: %d\n\n", spaces);
	    
	    printf("Letters: %d\n", letters);
	    printf("   lowecase: %d\n", lowercase);
	    printf("   uppercase: %d\n", uppercase);
	    printf("   vowels: %d\n", vowels);
	    printf("   consonants: %d\n", consonants);
    } else {
    	printf("Could't open the file. Try again.");
        return 1;
	}

    return 0;
}

int isvowel(int c)
{
	switch(tolower(c)) {
		case 'a': 
		case 'e':
		case 'i': 
		case 'o': 
		case 'u':
		case 'y': return 1;
	}
	
	return 0;
}
