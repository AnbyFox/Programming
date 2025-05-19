#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct human {
	char name[100], surname[100];
	int year;
	char sex[10];
	int height;	
};

void sortname(struct human *h, int N, int cmptype, int changer) {
	struct human temp;
	
	for(int i = 0; i < N-1; i++) {
		for(int j = 0; j < N-i-1; j++) {
			if(
				(changer == 2 && strcmp(h[j].surname, h[j+1].surname) == 0) ||
				(changer == 3 && h[j].year == h[j+1].year) ||
				(changer == 4 && h[j].sex[0] == h[j+1].sex[0]) ||
				(changer == 5 && h[j].height == h[j+1].height) || changer == 0
			)  {
				if(cmptype == 2) {
					if(strcmp(h[j].name, h[j+1].name) == 1) {
						temp = h[j];
						h[j] = h[j+1];
						h[j+1] = temp;
					}
				} else {
					if(strcmp(h[j].name, h[j+1].name) == -1) {
						temp = h[j+1];
						h[j+1] = h[j];
						h[j] = temp;
					}
				}
			}
		}
	}
}

void sortsurname(struct human *h, int N, int cmptype, int changer) {
	struct human temp;
	
	for(int i = 0; i < N-1; i++) {
		for(int j = 0; j < N-i-1; j++) {
			if(
				(changer == 1 && strcmp(h[j].name, h[j+1].name) == 0) ||
				(changer == 3 && h[j].year == h[j+1].year) ||
				(changer == 4 && h[j].sex[0] == h[j+1].sex[0]) ||
				(changer == 5 && h[j].height == h[j+1].height) || changer == 0
			)  {
				if(cmptype == 2) {
					if(strcmp(h[j].surname, h[j+1].surname) == 1) {
						temp = h[j];
						h[j] = h[j+1];
						h[j+1] = temp;
					}
				} else {
					if(strcmp(h[j].surname, h[j+1].surname) == -1) {
						temp = h[j+1];
						h[j+1] = h[j];
						h[j] = temp;
					}
				}
			}
		}
	}
}

void sortyear(struct human *h, int N, int cmptype, int changer) {
	struct human temp;
	
	for(int i = 0; i < N-1; i++) {
		for(int j = 0; j < N-i-1; j++) {
			if(
				(changer == 1 && strcmp(h[j].name, h[j+1].name) == 0) ||
				(changer == 2 && strcmp(h[j].surname, h[j+1].surname) == 0) ||
				(changer == 4 && h[j].sex[0] == h[j+1].sex[0]) ||
				(changer == 5 && h[j].height == h[j+1].height) || changer == 0
			)  {	
				if(cmptype == 2) {
					if(h[j].year > h[j+1].year) {
						temp = h[j];
						h[j] = h[j+1];
						h[j+1] = temp;
					}
				} else {
					if(h[j].year < h[j+1].year) {
						temp = h[j+1];
						h[j+1] = h[j];
						h[j] = temp;
					}
				}
			}
		}
	}
}

void sortsex(struct human * h, int N, int cmptype, int changer) {
	struct human temp;
	
	for(int i = 0; i < N-1; i++) {
		for(int j = 0; j < N-i-1; j++) {
			if(
				(changer == 1 && strcmp(h[j].name, h[j+1].name) == 0) ||
				(changer == 2 && strcmp(h[j].surname, h[j+1].surname) == 0) ||
				(changer == 3 && h[j].year == h[j+1].year) ||
				(changer == 5 && h[j].height == h[j+1].height) || changer == 0
			)  {
				if(cmptype == 2) {
					if(h[j].sex[0] > h[j+1].sex[0]) {
						temp = h[j];
						h[j] = h[j+1];
						h[j+1] = temp;
					}
				} else {
					if(h[j].sex[0] < h[j+1].sex[0]) {
						temp = h[j+1];
						h[j+1] = h[j];
						h[j] = temp;
					}
				}
			}
		}
	}
}

void sortheight(struct human *h, int N, int cmptype, int changer) {
	struct human temp;
	
	for(int i = 0; i < N-1; i++) {
		for(int j = 0; j < N-i-1; j++) {
			if(
				(changer == 1 && strcmp(h[j].name, h[j+1].name) == 0) ||
				(changer == 2 && strcmp(h[j].surname, h[j+1].surname) == 0) ||
				(changer == 3 && h[j].year == h[j+1].year) ||
				(changer == 4 && h[j].sex[0] == h[j+1].sex[0]) || changer == 0
			)  {
				if(cmptype == 2) {
					if(h[j].height > h[j+1].height) {
						temp = h[j];
						h[j] = h[j+1];
						h[j+1] = temp;
					}
				} else {
					if(h[j].height < h[j+1].height) {
						temp = h[j+1];
						h[j+1] = h[j];
						h[j] = temp;
					}
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	
	while(1) {
		struct human *h1, *h2;
		int N = 0;
	
		FILE *in = fopen("in.txt", "r");
		char buf[256];
		
		while(fgets(buf, 256, in) != NULL) N++;
		
		rewind(in);
		
		h1 = malloc(sizeof(struct human)*N);
		h2 = malloc(sizeof(struct human)*N);
		
		int i = 0;
		
		printf("--------------->\n");
		printf("List:\n");
		while(fscanf(in, "%s %s %d %s %d", h1[i].name, h1[i].surname, &h1[i].year, h1[i].sex, &h1[i].height) != EOF) {
			printf(" %d. %s %s %d %s %d\n", i+1, h1[i].name, h1[i].surname, h1[i].year, h1[i].sex, h1[i].height);
			h2[i] = h1[i];
			i++;
		}
		
		int cmptype = 0; 
		printf("\nChoose the compare type: (Only for names and numbers!)\n 1. A more B (A > B)\n 2. A less B (A < B)\nInput: ");
		scanf("%d", &cmptype);
		
		if(cmptype > 2 || cmptype < 1) {
			printf("\nError: Incorrect input. ");
			if(cmptype > 2) {
				cmptype = 2;
				printf("Comparing type: A less B (A < B)\n");
			}
			if(cmptype < 1) {
				cmptype = 1;
				printf("Comparing type: A more B (A > B)\n");
			}
		}
		
		int prsort1 = 0, prsort2 = 0;
		printf("\nChoose the sort type:\n 1. By name\n 2. By surname\n 3. By year\n 4. By sex\n 5. By height\nInput 1: ");
		scanf("%d", &prsort1);
		printf("Input 2: ");
		scanf("%d", &prsort2);
		
		switch(prsort1) {
			case 1:
				sortname(h2, N, cmptype, 0);
				break;
			case 2:
				sortsurname(h2, N, cmptype, 0);
				break;
			case 3:
				sortyear(h2, N, cmptype, 0);
				break;
			case 4:
				sortsex(h2, N, cmptype, 0);
				break;
			case 5:
				sortheight(h2, N, cmptype, 0);
				break;
			default:
				printf("\nError: Incorrect input. Sort type: By name.\n");
				sortname(h2, N, cmptype, 0);
				break;
		}
		
		switch(prsort2) {
			case 1:
				sortname(h2, N, cmptype, prsort1);
				break;
			case 2:
				sortsurname(h2, N, cmptype, prsort1);
				break;
			case 3:
				sortyear(h2, N, cmptype, prsort1);
				break;
			case 4:
				sortsex(h2, N, cmptype, prsort1);
				break;
			case 5:
				sortheight(h2, N, cmptype, prsort1);
				break;
			default:
				printf("\nError: Incorrect input. Sort type: By surname.\n");
				sortsurname(h2, N, cmptype, 1);
				break;
		}
		
		printf("\nResult: (N = %d)\n", N);

		for(int i = 0; i < N; i++) {
			printf(" %d. %s %s %d %s %d\n", i+1, h2[i].name, h2[i].surname, h2[i].year, h2[i].sex, h2[i].height);
		}
		
		fclose(in);
		
		free(h1);
		free(h2);	
	}
	
	return 0;
}
