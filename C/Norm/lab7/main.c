#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[100], secondame[100];
    int year;
} human;

int main() {
    FILE *f = fopen("in.txt", "r");
    
    int human_size = 4;
    human m1[human_size], m2[human_size];
    
    if (f != NULL) {
    	printf("1st massive (\"in.txt\"):");
    	for(int i = 0; i < human_size; i++) {
			fscanf(f, "%s %s %d", m1[i].name, m1[i].secondame, &m1[i].year);
			printf("\n%s %s %d", m1[i].name, m1[i].secondame, m1[i].year);
			m2[i] = m1[i];
	    }
	    
	    printf("\n\n2nd massive (filtering):");
	    for(int i = 0; i < human_size; i++) {
	        for(int j = 0; j < human_size - 1; j++) {
	        	if(m2[j].year > m2[j+1].year) {
	        		human tmp = m2[j];
	        		m2[j] = m2[j+1];
	        		m2[j+1] = tmp;
	        	}
	        }
	        
	        if(m2[i].name[0] == 'a') printf("\n%s %s %d", m2[i].name, m2[i].secondame, m2[i].year);
	    }

	    fclose(f);
    } else {
    	printf("Couldn't open the txt file. Try again.");
	}
    
    return 0;
}
