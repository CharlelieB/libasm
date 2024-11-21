ASM_SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
BONUS_SRC = ft_atoi_base.s ft_list_push_front.s ft_list_size.s \
			ft_list_sort.s ft_list_remove_if.s
ASM_OBJ = $(ASM_SRC:.s=.o)
BONUS_ASM_OBJ = $(BONUS_SRC:.s=.o)
NAME = libasm.a
NASM = nasm
NASMFLAGS = -f elf64 -O0
AR = ar rcs

all: $(NAME)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

$(NAME): $(ASM_OBJ)
	$(AR) $@ $^

bonus: $(BONUS_ASM_OBJ)
	$(AR) $(NAME) $^

$(C_OBJ): $(C_SRC)
	$(CC) $(CFLAGS) $(C_SRC)

re: clean all

clean:
	rm -f $(ASM_OBJ) $(BONUS_ASM_OBJ) $(NAME)

re: fclean all

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re bonus