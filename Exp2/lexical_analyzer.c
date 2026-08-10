#include <stdio.h> 
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>

FILE *fp;
char delim[14] = { ' ', '\t', '\n', ',', ';', '(', ')', '{', '}', '[', ']', '#', '<', '>' }; 
char oper[7] = { '+', '-', '*', '/', '%', '=', '!' };
char key[21][12] = {
    "int", "float", "char", "double", "bool", "void", "extern", "unsigned", "goto",
    "static", "class", "struct", "for", "if", "else", "return", "register", "long", "while", "do"
};
char predirect[2][12] = { "include", "define" };
char header[6][15] = { "stdio.h", "conio.h", "malloc.h", "process.h", "string.h", "ctype.h" };

void skipcomment(); 
void analyze();
void check(char t[]); 
int isdelim(char c); 
int isop(char c);

int fop = 0, numflag = 0, f = 0; 
char c, ch, sop;

int main() {
    char fname[50]; 
    printf("\nEnter filename : "); 
    if (scanf("%s", fname) != 1) return 1;
    fp = fopen(fname, "r"); 
    if (fp == NULL) {
        printf("\nThe file doesn't exist.\n"); 
    } else {
        analyze(); 
        fclose(fp);
        printf("\nEnd of file\n"); 
    }
    return 0;
}

void analyze() {
    char token[50]; 
    int j = 0;
    while ((c = getc(fp)) != EOF) {
        if (c == '/') {
            skipcomment();
        } else if (c == '"') {
            while ((c = getc(fp)) != '"' && c != EOF); 
        } else if (isalpha(c)) {
            token[j++] = c;
            while ((c = getc(fp)) != EOF && (isalnum(c) || c == '.')) {
                token[j++] = c;
            }
            token[j] = '\0';
            check(token);
            j = 0;
            if (c != EOF) ungetc(c, fp);
        } else if (isdigit(c)) {
            token[j++] = c;
            while ((c = getc(fp)) != EOF && isdigit(c)) {
                token[j++] = c;
            }
            token[j] = '\0';
            numflag = 1;
            check(token);
            numflag = 0;
            j = 0;
            if (c != EOF) ungetc(c, fp);
        } else if (isdelim(c)) {
            printf("\nDelimitter\t %c", c);
        } else if (isop(c)) {
            printf("\nOperator\t %c", c);
        }
    }
}

int isdelim(char c) {
    int i;
    for (i = 0; i < 14; i++) {
        if (c == delim[i]) return 1;
    }
    return 0;
}

int isop(char c) {
    int i;
    for (i = 0; i < 7; i++) {
        if (c == oper[i]) return 1;
    }
    return 0;
}

void check(char t[]) {
    int i;
    if (numflag == 1) {
        printf("\nNumber\t\t %s", t); 
        return;
    }
    for (i = 0; i < 2; i++) {
        if (strcmp(t, predirect[i]) == 0) {
            printf("\nPreprocessor directive %s", t); 
            return;
        }
    }
    for (i = 0; i < 6; i++) {
        if (strcmp(t, header[i]) == 0) {
            printf("\nHeader file\t %s", t); 
            return;
        }
    }
    for (i = 0; i < 21; i++) {
        if (strcmp(key[i], t) == 0) {
            printf("\nKeyword\t\t %s", key[i]); 
            return;
        }
    }
    printf("\nIdentifier\t %s", t);
}

void skipcomment() {
    ch = getc(fp); 
    if (ch == '/') {
        while ((ch = getc(fp)) != '\n' && ch != EOF);
    } else if (ch == '*') {
        while (1) {
            ch = getc(fp);
            if (ch == EOF) break;
            if (ch == '*') { 
                c = getc(fp); 
                if (c == '/') break;
            }
        }
    } else {
        ungetc(ch, fp);
        printf("\nOperator\t /");
    }
}
