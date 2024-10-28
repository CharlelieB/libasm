ASM_SRC = ft_strlen.s
C_SRC = main.c
ASM_OBJ = ft_strlen.o
C_OBJ = main.o
OUTPUT = prog

NASM = nasm
NASMFLAGS = -f elf64
CC = gcc
CFLAGS = -c

all: $(OUTPUT)

$(ASM_OBJ): $(ASM_SRC)
	$(NASM) $(NASMFLAGS) $(ASM_SRC) -o $(ASM_OBJ)

$(C_OBJ): $(C_SRC)
	$(CC) $(CFLAGS) $(C_SRC)

$(OUTPUT): $(ASM_OBJ) $(C_OBJ)
	$(CC) $(ASM_OBJ) $(C_OBJ) -o $(OUTPUT)

clean:
	rm -f $(ASM_OBJ) $(C_OBJ) $(OUTPUT)
