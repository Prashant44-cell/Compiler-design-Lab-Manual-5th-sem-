# Experiment 7: Three-Address Code Generation Using LEX and YACC

## AIM
To write a program using LEX and YACC to generate Three-Address Code (TAC) for a simple arithmetic expression.

## ALGORITHM
- **LEX**:
  1. Tokenize identifiers and numbers using regular expressions.
  2. Duplicate string lexemes (`strdup`) and pass them to YACC via `yylval.str`.
- **YACC**:
  1. Define operator precedence (`+`, `-`, `*`, `/`).
  2. Maintain a temporary variable counter (`t1`, `t2`, etc.).
  3. Emit TAC instructions as expressions are parsed bottom-up.

## FILES
- `tac.l`: LEX specification for TAC tokenizing.
- `tac.y`: YACC specification for intermediate code generation.
- `output.txt`: Sample output of execution.

## COMPILATION & EXECUTION
```bash
lex tac.l
yacc -d tac.y
gcc y.tab.c lex.yy.c -o tac
./tac
```
