#include <stdio.h>
#include <string.h>



void reverse(char s[]);

int main() {

    char s[] = "hello";
    reverse(s);
    printf("%s", s);
    
    return 0;
}

void reverse(char s[]) {
    static int i;
    static int j;

    if (s[i] != 0) {
        char c = s[i++];
        reverse(s);

        s[j++] = c;
    }
}
