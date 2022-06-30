#include <stdio.h>


int strngcmp(char *s, char *t, int n);

int main() {
    
    char s[100] = "cccc";
    char *t = "ccc";
    printf("%d", strngcmp(s, t, 5));
    
    

    return 0;
}

int strngcmp(char *s, char *t, int n) {
    while (n-- && (*s && *t)) {
        if (*s++ < *t++) return -1;
        if (*t < *s) return 1;
    }
    return 0;
}






