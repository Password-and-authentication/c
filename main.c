#include <stdio.h>
#include "getch.c"

int getword(char *s, int *linenum);


int main() {
    
    char word[200];
    int linenum = 1;

    int i = getword(word, &linenum);
    printf("%s", word);

    
    return 0;
}

int getword(char *s, int *linenum) {
    
    while ((*s++ = _getch()) != 32);
}