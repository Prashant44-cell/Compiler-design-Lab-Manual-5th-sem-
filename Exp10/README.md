# Experiment 10: Compiler Back-End (8086 Assembly Generation)

## AIM
To write a C program to implement the back-end of a compiler which takes Three-Address Code (TAC) as input and generates equivalent 8086 assembly language code.

## ALGORITHM
1. Read the number of TAC lines and store each TAC line in an array.
2. For each line, parse components using string matching (`result`, `op1`, `operator`, `op2`).
3. Translate TAC operations to 8086 assembly instructions:
   - Assignment (`x = y`): `MOV AX, y` -> `MOV x, AX`
   - Addition (`+`): `MOV AX, op1` -> `ADD AX, op2` -> `MOV result, AX`
   - Subtraction (`-`): `MOV AX, op1` -> `SUB AX, op2` -> `MOV result, AX`
   - Multiplication (`*`): `MOV AX, op1` -> `MUL op2` -> `MOV result, AX`
   - Division (`/`): `MOV AX, op1` -> `MOV DX, 0` -> `MOV BX, op2` -> `DIV BX` -> `MOV result, AX`
4. Output generated 8086 assembly instructions.

## FILES
- `backend.c`: C program translating TAC to 8086 assembly language instructions.
- `output.txt`: Sample output of execution.

## COMPILATION & EXECUTION
```bash
gcc -o backend backend.c
./backend
```
