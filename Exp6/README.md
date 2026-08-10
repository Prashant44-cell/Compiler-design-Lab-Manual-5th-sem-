# Experiment 6: Implementation of Calculator Using LEX and YACC

## AIM
To write a program to implement a calculator using LEX and YACC.

## ALGORITHM
- **LEX**:
  1. Define pattern for digits `[0-9]+`.
  2. Convert matched numeric strings to double using `atof()` and assign to `yylval`.
- **YACC**:
  1. Define operator precedence (`%left '+` `-`, `%left '*' '/'`).
  2. Define rules for addition, subtraction, multiplication, and division.
  3. Print calculated floating-point answer on expression evaluation.

## FILES
- `cal.l`: LEX specification for calculator tokens.
- `cal.y`: YACC specification for arithmetic expression evaluation.
- `output.txt`: Sample output of execution.

## COMPILATION & EXECUTION
```bash
lex cal.l
yacc -d cal.y
gcc lex.yy.c y.tab.c -o calc
./calc
```
