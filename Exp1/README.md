# Experiment 1: Symbol Table Implementation in C

## AIM
To develop a lexical analyzer / symbol table manager program to recognize tokens such as identifiers, constants, comments, and operators, and to maintain a symbol table data structure while recognizing identifiers.

## ALGORITHM
1. Define the symbol table structure with fields `var` (variable name) and `value`.
2. Provide menu options to Create, Insert, Modify, Search, Display, and Exit.
3. Validate variable names to ensure they start with an alphabet and avoid duplicate entries.
4. Update or retrieve entries based on user operations.

## FILES
- `symbol_table.c`: Source code for Symbol Table operations.
- `output.txt`: Sample output of execution.

## COMPILATION & EXECUTION
```bash
gcc -o symbol_table symbol_table.c
./symbol_table
```
