#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

char delims[] = ", .()[]\"=\\/?_*~`:;!@#$%^|";
int isflineBufferEmpty = 1;
char* flineBuffer = NULL;
int F_LINE_BUFF_LEN = 1000;

typedef struct word {
    int count;
    char* Word;
} WORD;

int cmpword_alpha(WORD*, WORD*);
int cmpword_quant(WORD*, WORD*);
char* getword(FILE* F);
void getwordFlush();
void toLowerCase(char* str);
int iscontain(WORD* words, char* word, int len);
void writeListToFile(WORD* words, int len, FILE* F);
void showList(WORD* words, int len);

WORD words[10000000];
int curEmptyIndex = 0;

int main(int ac, char* av[])
{
    FILE* OUTA, * OUTQ, * IN;
    char* pword;

    if (ac < 2)
	{
        printf("You forgot to specify the files!\n"); exit(0);
    } 
	while (--ac)
	{
        IN = fopen(av[ac], "r");
        printf("Checking the file %s\n",av[ac]);
        
        while((pword = getword(IN)) != NULL)
		{           
            toLowerCase(pword);
            
            int wordIndex = iscontain(words, pword, curEmptyIndex);
            if(wordIndex != -1)	words[wordIndex].count++;   
			else {
                words[curEmptyIndex].Word = (char*)malloc(sizeof(char) * strlen(pword));
                strcpy(words[curEmptyIndex].Word, pword);
                words[curEmptyIndex].count = 1;
                curEmptyIndex++;
            }
        }
        
        fclose(IN);
    }

    qsort(words, curEmptyIndex, sizeof(WORD), (int (*)(const void*, const void*))cmpword_alpha);
    OUTA = fopen("out-alphabet.txt", "w");
    writeListToFile(words, curEmptyIndex, OUTA);
    fclose(OUTA);

    qsort(words, curEmptyIndex, sizeof(WORD), (int (*)(const void*, const void*))cmpword_quant);
    OUTQ = fopen("out-quant.txt", "w");
    writeListToFile(words, curEmptyIndex, OUTQ);
    fclose(OUTQ);

    printf("\nTotal: [ %d ]", curEmptyIndex);
    getwordFlush();
    
    return 0;
}

char* getword(FILE* F)
{
    if(feof(F) && isflineBufferEmpty) return NULL;
    if(flineBuffer == NULL) {
        flineBuffer = (char*)malloc(sizeof(char) * (F_LINE_BUFF_LEN + 1));
        flineBuffer[F_LINE_BUFF_LEN] = '\0';
    }    

    int i = 0;
    while (isflineBufferEmpty) {
        char ch = fgetc(F);
        if(ch == -1 || ch == '.') {
            flineBuffer[i] = '\0';
            break;
        }

        if(isalpha(ch) == 0 && ch != ' ') continue;
        else {
            flineBuffer[i] = ch;
            i++;
            if (i == F_LINE_BUFF_LEN) break;               
        }
    }

    char* s;

    if (isflineBufferEmpty) {
        isflineBufferEmpty = 0;
        s = strtok(flineBuffer, delims);
    } else {
        s = strtok(NULL, delims);
    }

    if(s == NULL) {
        isflineBufferEmpty = 1;
        return getword(F);
    }

    return s;
}

void getwordFlush()
{
    free(flineBuffer);
}

int iscontain(WORD* words, char* word, int len)
{
	int i;
    for(i = 0; i < len; i++) {
        if(strcmp(words[i].Word, word) == 0) return i;
    }

    return -1;
}

void toLowerCase(char* str) {
    while(*str) {
        *str = tolower(*str);
        str++;
    }
}

int cmpword_alpha(WORD* w1, WORD* w2)
{
    return strcmp(w1->Word, w2->Word);
}

int cmpword_quant(WORD* w1, WORD* w2)
{
    if(w1->count > w2->count)
        return -1;
    else if (w1->count < w2->count)
        return 1;
    else
		return 0;
}

void writeListToFile(WORD* words, int len, FILE* F)
{
	int i;
    char buff[100];
    for(i = 0; i < len; i++) {
        sprintf(buff, "[ %s ]\t -- \t[ %d ]\n", words[i].Word, words[i].count);
        fwrite(buff, sizeof(char), strlen(buff), F);
    }
}
