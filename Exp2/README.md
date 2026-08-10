# Experiment 2: Implementation of Lexical Analyzer in C

## AIM
To write a C program that reads a C source code file and identifies individual tokens such as identifiers, keywords, constants, operators, headers, preprocessor directives, and delimiters.

## ALGORITHM
1. Open the target C source file.
2. Read characters sequentially and classify them into:
   - Preprocessor directives (`#include`, `#define`)
   - Header files (`stdio.h`, `conio.h`, etc.)
   - Keywords (`int`, `void`, `char`, etc.)
   - Identifiers
   - Delimiters (`(`, `)`, `{`, `}`, `;`, etc.)
   - Operators (`+`, `-`, `*`, `/`, `=`, etc.)
3. Print each recognized token with its category.
4. Close the file upon reaching EOF.

## FILES
- `lexical_analyzer.c`: Source code for the lexical analyzer.
- `iplex.c`: Sample input C file to analyze.
- `output.txt`: Sample output of execution.

## COMPILATION & EXECUTION
```bash
gcc -o lexical_analyzer lexical_analyzer.c
./lexical_analyzer
# Input when prompted: iplex.c
```
