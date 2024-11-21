ASM_SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_atoi_base.s ft_list_push_front.s ft_list_size.s \
			ft_list_sort.s
C_SRC = main.c
ASM_OBJ = $(ASM_SRC:.s=.o)
C_OBJ = main.o
OUTPUT = prog

NASM = nasm
NASMFLAGS = -f elf64 -g -O0
CC = gcc -g3 -O0
CFLAGS = -c

all: $(OUTPUT)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

#$(ASM_OBJ): $(ASM_SRC)
#	$(NASM) $(NASMFLAGS) $(ASM_SRC) -o $(ASM_OBJ)

$(C_OBJ): $(C_SRC)
	$(CC) $(CFLAGS) $(C_SRC)

$(OUTPUT): $(ASM_OBJ) $(C_OBJ)
	$(CC) $(ASM_OBJ) $(C_OBJ) -o $(OUTPUT)

re: clean all

clean:
	rm -f $(ASM_OBJ) $(C_OBJ) $(OUTPUT)
