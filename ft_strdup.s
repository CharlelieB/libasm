extern malloc
extern ft_strlen
extern ft_strcpy
extern __errno_location

section .text
	
	align 8	
	
	global ft_strdup
	
	ft_strdup:
	
		push rdi
		call ft_strlen
		inc rax
		mov rdi, rax
		call malloc wrt ..plt
		cmp rax, 0
		je malloc_failure
		pop rsi ;put rdi in second arg
		push rdi
		mov rdi, rax
		call ft_strcpy
		pop rdi
		ret
		malloc_failure:
			mov rdx, rax
			call __errno_location wrt ..plt
			neg rdx
			mov [rax], rdx
			mov rax, 0
			pop rdi
			ret
