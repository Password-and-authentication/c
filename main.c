#include <stdio.h>

#define swap(t, x, y) { \
    t temp;             \
    temp = x;           \
    x = y;              \
    y = temp;           \
}                       \

int main() {
    int x = 10;
    int y = 20;
    swap(int, x, y);
    printf("%d", x);
    
    return 0;
}

