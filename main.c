#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getch.c"

int getword(char *s, int *linenum);
struct Node* addtree(struct Node *root, char *word);

struct Node {
    char *word;
    int lines[10];
    int i;
    struct Node *left;
    struct Node *right;
};


int main() {
    
    char word[200];
    int linenum = 1;

    struct Node *root;
    root = NULL;

    while ((getword(word, &linenum)) != EOF) {
        root = addtree(root, word);
    }  
    return 0;
}


struct Node* addtree(struct Node *n, char *word) {

    int cond;
    if (n == NULL) {
        n = malloc(sizeof(*n));
        n->word = strdup(word);
        n->i = 0;
        n->left = n->right = NULL;
    } else if ((cond = strcmp(n->word, word)) == 0) {
        n->i++;
    } else if (cond < 0) {
        n->left = addtree(n->left, word);
    } else {
        n->right = addtree(n->right, word);
    }
    
    
    return n;
    
   
    //printf("%s\n", word);
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