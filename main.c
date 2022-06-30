#include <stdio.h>



char *strngcat(char *s, char *t, int n);

int main() {
    
    char s[100] = "sidemen";
    char t[] = "ksi";
    char *ptr = strngcat(s, t, 3);
    printf("%s", ptr);
    

    return 0;
}

char *strngcat(char *s, char *t, int n) {
    char *ret = s;
    while(*s++);
    --s;
    while(n-- && (*s++ = *t++));
    *s = 0;
    return ret;
}





