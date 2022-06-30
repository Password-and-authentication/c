#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.c"

int getword(char *s, int *linenum);


int main() {
    
    char word[200];
    int linenum = 1;

    while ((getword(word, &linenum)) != EOF) {
        printf("%s\n", word);
    }
 
    
    //printf("%s", word);

    
    return 0;
}

int getword(char *s, int *linenum) {
    char c;
    //printf("%d\n", c);
    if ((c = _getch()) == EOF) {
        return EOF;
    }
    *s++ = c;
    //putchar(c);
    while ((*s = _getch()) != EOF && *s != 10 && *s != 32) {
        ++s;
    }    
    //printf("%d\n", *s);
    if (*s == EOF) {
        *s = 0;
        _ungetch(EOF);
    }
    *s = 0;
    //printf("%d\n", *s);      
}