# Experiment 8: Type Checking Implementation in C

## AIM
To write a C program to implement type checking of variables in a simple expression using a symbol table.

## ALGORITHM
1. Store variable declarations (datatype and variable name) in a symbol table.
2. Read assignment expressions and extract the left-hand side variable and operands.
3. Check if all variables are declared in the symbol table.
4. Compare data types of operands and assigned variable.
5. Display "There is no type mismatch" if types match, or "Type Mismatch" if they differ.

## FILES
- `typecheck.c`: C program implementing type checking using symbol table lookup.
- `output.txt`: Sample output of execution.

## COMPILATION & EXECUTION
```bash
gcc -o typecheck typecheck.c
./typecheck
```
