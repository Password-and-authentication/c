#include <stdio.h>


char* strncopy(char *s, char *t, int n);

int main() {
    
    char t[] = "ksi";
    char s[100];
    char *ptr = strncopy(s, t, 23);
    printf("%s", ptr);

    return 0;
}

char *strncopy(char *s, char *t, int n) {
    char *temp = s;
    while(n-- && (*s++ = *t++));
    return temp;
}



