#include <stdio.h>
#include <string.h>




int main(int argc, char *argv[]) {

    int cond;
    char c;
    if ((cond = strcmp(*argv, "./upper") == 0)) {
        
        while ((c = getchar()) != EOF) {
            if (c >= 'a' && c <= 'z') {
                c -= 32;
            }
            putchar(c);
        }
    } else {
        while ((c = getchar()) != EOF) {
            if (c >= 'A' && c <= 'Z') {
                c += 32;
            }
            putchar(c);
        }
    }

    return 0;
}



