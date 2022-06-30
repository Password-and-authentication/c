#include <stdio.h>


void readlines(char *ptrarr[], char lines[]);

int main() {
    
    char *ptrarr[200];
    char lines[10000];
    readlines(ptrarr, lines);
    char *c = *ptrarr;
    putchar(*c);                
    

    return 0;
}

void readlines(char *ptrarr[], char lines[]) {
    char line[100];
    char *c = line;
    int len = 1;
    while (++len && (*c++ = getchar()) != EOF) {

        *lines++ = *(c - 1);
        if (*(c - 1) == 10) {
            len -= 2;          
            *c = 0;
            c = line;
            *ptrarr++ = lines - len - 1;
            len = 1;
        }
    }
}
