# Calling convention

An implementation-level (low-level) scheme for how subroutines or functions **receive parameters** from their caller and how they **return** a result

Consider it's a contract between the caller and the called function

Defines for instance :

-Where parameters are placed (registers, on the stack, both...)
-the order of parameters (left to right...)
-how variadic arg are handled
-how return values are delivered from the callee back to the caller (stack, register, reference to the heap...)
...

# To compile

nasm -f elf64 prog.s
gcc -c main.c
gcc main.o prog.o -o prog

# GDB

gdb ./a.out
b myfunction
r
set disassemble-flavor intel
disassemble
stepi

to check flags : 

```
info registers eflags
```

print (/type)
```
p/d $register 
```
# Ressources

felixcloutier.com/x86
https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html
