# Experiment 4: Recognize Valid Variable Name Using LEX and YACC

## AIM
To write a LEX and YACC program to recognize a valid variable name that starts with a letter followed by any number of letters or digits.

## ALGORITHM
- **LEX**:
  1. Return token `LET` for letters `[a-zA-Z]`.
  2. Return token `DIG` for digits `[0-9]`.
- **YACC**:
  1. Define grammar rules ensuring variable starts with `LET` and can be followed by recursive combinations of `LET` or `DIG`.
  2. Output "Valid variable" if parsed successfully, else call `yyerror()` for "Invalid variable".

## FILES
- `valvar.l`: LEX file for variable token recognition.
- `valvar.y`: YACC file for syntax validation.
- `output.txt`: Sample output of execution.

## COMPILATION & EXECUTION
```bash
lex valvar.l
yacc -d valvar.y
gcc lex.yy.c y.tab.c -o valvar
./valvar
```
