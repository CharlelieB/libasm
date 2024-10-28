# Calling convention

An implementation-level (low-level) scheme for how subroutines or functions **receive parameters** from their caller and how they **return** a result

Consider it's a contract between the caller and the called function

Defines for instance :

- where parameters are placed (registers, on the stack, both...)
- the order of parameters (left to right...)
- how variadic arg are handled
- how return values are delivered from the callee back to the caller (stack, register, reference to the heap...)
- ...

# To compile
```
nasm -f elf64 prog.s
gcc -c main.c
gcc main.o prog.o -o prog
```
# GDB
```
gdb ./a.out
b myfunction
r
set disassemble-flavor intel
disassemble
stepi
```

check flags : 

```
info registers eflags
```

print (/type)
```
p/d $register 
```
# Ressources

- [instruction reference](https://www.felixcloutier.com/x86/)
- [cheat sheet](https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html)
- [assembly language programming with ubuntu](https://github.com/mandm-pt/OperatingSystem/blob/master/literature/x86-64%20Assembly%20Language%20Programming%20with%20Ubuntu.pdf)
- [debugging assembly code with gdb](https://web.cecs.pdx.edu/~apt/cs510comp/gdb.pdf)
- [the 64 bit x86 C Calling convention](https://aaronbloomfield.github.io/pdr/book/x86-64bit-ccc-chapter.pdf)
