#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

int count = 0, i = 0, j = 0, l = 0;
char key[4][12] = {"int", "float", "char", "double"}; 
char dstr[100][100], estr[100][100];
char token[100], resultvardt[100], arg1dt[100], arg2dt[100];

struct table { 
    char var[10]; 
    char dt[10];
} tbl[20];

void entry(char *declaration); 
int check(char t[]);
int search(char variable[]);
void typecheck(char *expression);

void safe_gets(char *buf, int size) {
    if (fgets(buf, size, stdin)) {
        buf[strcspn(buf, "\r\n")] = '\0';
    }
}

int main() {
    printf("\nIMPLEMENTATION OF TYPE CHECKING\n");
    printf("\nDECLARATIONS (END to finish):\n"); 
    while (1) {
        printf("\t");
        safe_gets(dstr[i], sizeof(dstr[i]));
        if (strcmp(dstr[i], "END") == 0) break; 
        entry(dstr[i]);
        i++;
    }
    printf("\nEXPRESSIONS (END to finish):\n"); 
    while (1) {
        printf("\t");
        safe_gets(estr[l], sizeof(estr[l]));
        if (strcmp(estr[l], "END") == 0) break; 
        l++;
    }
    printf("\nSEMANTIC ANALYZER (TYPE CHECKING):\n");
    for (i = 0; i < l; i++) { 
        typecheck(estr[i]);
    }
    return 0;
}

void entry(char *declaration) { 
    char datatype[10], varname[10];
    if (sscanf(declaration, "%s %[^;];", datatype, varname) < 2) return;
    if (!check(datatype)) {
        printf("Invalid datatype: %s\n", datatype); 
        return;
    }
    if (search(varname) != -1) {
        printf("The variable '%s' is already declared\n", varname); 
        return;
    }
    strcpy(tbl[count].dt, datatype); 
    strcpy(tbl[count].var, varname); 
    count++;
}

int check(char t[]) {
    for (int in = 0; in < 4; in++) { 
        if (strcmp(key[in], t) == 0) {
            return 1;
        }
    }
    return 0;
}

int search(char variable[]) {
    for (int idx = 0; idx < count; idx++) {
        if (strcmp(tbl[idx].var, variable) == 0) { 
            return idx;
        }
    }
    return -1;
}

void typecheck(char *expression) {
    char result[10] = {0}, op1[10] = {0}, op2[10] = {0}, operator = '\0';
    if (sscanf(expression, "%s = %s %c %[^;];", result, op1, &operator, op2) < 4) {
        sscanf(expression, "%[^=]=%[^*+-/]%c%[^;];", result, op1, &operator, op2);
    }
    
    char clean_res[10] = {0}, clean_op1[10] = {0}, clean_op2[10] = {0};
    sscanf(result, "%s", clean_res);
    sscanf(op1, "%s", clean_op1);
    sscanf(op2, "%s", clean_op2);

    int rIndex = search(clean_res); 
    int o1Index = search(clean_op1); 
    int o2Index = search(clean_op2);

    if (rIndex == -1) {
        printf("Undefined variable: %s\n", clean_res); 
        return;
    }
    if (o1Index == -1) {
        printf("Undefined variable: %s\n", clean_op1); 
        return;
    }
    if (o2Index == -1) {
        printf("Undefined variable: %s\n", clean_op2); 
        return;
    }

    strcpy(resultvardt, tbl[rIndex].dt); 
    strcpy(arg1dt, tbl[o1Index].dt); 
    strcpy(arg2dt, tbl[o2Index].dt);

    if (strcmp(arg1dt, arg2dt) == 0) {
        if (strcmp(resultvardt, arg1dt) == 0) {
            printf("\n\tThere is no type mismatch in the expression %s\n", expression);
        } else {
            printf("\n\tType mismatch: Lvalue and Rvalue must be same in '%s'\n", expression);
        }
    } else {
        printf("\n\tType Mismatch\n");
    }
}
