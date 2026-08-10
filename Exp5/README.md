# Experiment 5: Recognize Valid Control Structures Syntax in C Using LEX and YACC

## AIM
To write a LEX and YACC program to recognize valid control structure syntax in C (such as `if`, `if-else`, `while`, `for`, and `switch-case`).

## ALGORITHM
- **LEX**:
  1. Define regular expressions for control structure keywords (`if`, `else`, `for`, `while`, `switch`, `case`, `default`).
  2. Tokenize identifiers, numbers, relational operators, and symbols (`{`, `}`, `(`, `)`, `:`, `;`).
- **YACC**:
  1. Define grammar rules for `if`, `while`, `for`, and `switch` statements.
  2. Parse input control statements and print whether the syntax is valid.

## FILES
- `control.l`: LEX file for control structure keywords and tokens.
- `control.y`: YACC file defining C control structure grammar.
- `output.txt`: Sample output of execution.

## COMPILATION & EXECUTION
```bash
lex control.l
yacc -d control.y
gcc lex.yy.c y.tab.c -o control
./control
```
