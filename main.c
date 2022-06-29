#include <stdio.h>


void strcatt(char *s, char *t);

int main() {
    
    char s[100] = "hello";
    char t[] = "lol";
    strcatt(s, t);
    printf("%s", s);

    return 0;
}

void strcatt(char *s, char *t) {
    while (*++s);
    while((*s++ = *t++));
}

