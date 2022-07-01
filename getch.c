
char buffer[100];
int bufp = 0;

int _getch() {
    return (bufp > 0) ? buffer[--bufp] : getchar();
    // FUCK YOU
}

void _ungetch(int c) {
    buffer[bufp++] = c;
}