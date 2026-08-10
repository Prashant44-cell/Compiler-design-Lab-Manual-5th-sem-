# Experiment 3: Recognize Valid Arithmetic Expression Using LEX and YACC

## AIM
To write a LEX and YACC program to recognize a valid arithmetic expression that uses operators `+`, `-`, `*`, and `/`.

## ALGORITHM
- **LEX**:
  1. Define patterns for identifiers, digits, and operators.
  2. Return tokens (`ID`, `DIG`, operators) to YACC parser.
- **YACC**:
  1. Declare tokens and operator associativity (`%left '+` `-`, `%left '*' '/'`, `%right UMINUS`).
  2. Define grammar rules for arithmetic expressions.
  3. Validate input expression during parsing.

## FILES
- `art_expr.l`: LEX specification for tokenizing arithmetic expressions.
- `art_expr.y`: YACC specification for parsing arithmetic grammar.
- `output.txt`: Sample output of execution.

## COMPILATION & EXECUTION
```bash
lex art_expr.l
yacc -d art_expr.y
gcc lex.yy.c y.tab.c -o art_expr
./art_expr
```
