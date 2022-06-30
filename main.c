#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getch.c"

int getword(char *s, int *newline);
struct Node* addtree(struct Node *root, char *word, int linenum);
void treePrint(struct Node *n);

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
    int newline = 0;
    while ((getword(word, &newline)) != EOF) {
        root = addtree(root, word, linenum);
        if (newline) ++linenum;
    }  

    treePrint(root);
    
    return 0;
}


void treePrint(struct Node *n) {
    if (n != NULL) {
        treePrint(n->left);
        int i = 0;
        printf("%s\t", n->word);
        while (n->lines[i] != 69) {
            printf("%d", n->lines[i++]);
            putchar(32);
        }
        putchar(10);
        treePrint(n->right);
    }
    
}

struct Node* addtree(struct Node *n, char *word, int linenum) {

    int cond;
    if (n == NULL) {
        n = malloc(sizeof(*n));
        n->word = strdup(word);
        n->lines[0] = linenum;
        n->lines[1] = 69;
        n->i = 0;
        n->left = n->right = NULL;
    } else if ((cond = strcmp(n->word, word)) == 0) {
        n->i++;
        n->lines[n->i] = linenum;
        n->lines[n->i + 1] = 69;
    } else if (cond < 0) {
        n->left = addtree(n->left, word, linenum);
    } else {
        n->right = addtree(n->right, word, linenum);
    }

    return n;
    
   
    //printf("%s\n", word);
}


int getword(char *s, int *newline) {
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
    if (*s == 10) *newline = 1;
    //printf("%d\n", *s);
    if (*s == EOF) {
        *s = 0;
        _ungetch(EOF);
    }
    *s = 0;
    //printf("%d\n", *s);      
}