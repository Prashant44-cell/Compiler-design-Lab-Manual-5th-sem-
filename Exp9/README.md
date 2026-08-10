# Experiment 9: Code Optimization Techniques in C

## AIM
To write a C program to implement simple code optimization techniques such as Constant Folding, Strength Reduction, and Algebraic Simplification on Three-Address Code.

## ALGORITHM
1. Read lines of Three-Address Code (TAC) from input.
2. For each TAC statement, check for optimization patterns:
   - **Constant Folding**: If both operands are numbers (e.g. `a=2+4;`), evaluate expression at compile time (`a=6;`).
   - **Algebraic Simplification**: If multiplying/dividing by 1 (e.g. `b=d*1;`), simplify to assignment (`b=d;`).
   - **Strength Reduction**: If multiplying by 2 (e.g. `c=s*2;`), replace with addition (`c=s+s;`).
3. Output the optimized TAC lines.

## FILES
- `optimize.c`: Source code implementing code optimization rules.
- `infile.txt`: Input file containing unoptimized TAC.
- `output.txt`: Sample output showing unoptimized and optimized code.

## COMPILATION & EXECUTION
```bash
gcc -o optimize optimize.c
./optimize
```
