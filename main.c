#include <stdio.h>


int strend(char *s, char *t);

int main() {
    
    char s[100] = "skateboard";
    char t[] = "board";
    printf("%d", strend(s, t));

    return 0;
}

int strend(char *s, char *t) {
    int i = 0;
    char *temp = t;
    while (*++temp && ++i);
    ++i;
    while (*++s);
    s -= i;

    while (*s) {
        if (*s++ != *t++) return 0;
    }
    return 1;
    
}

