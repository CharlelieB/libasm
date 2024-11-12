extern malloc
extern ft_strlen
extern ft_strcpy
extern __errno_location

section .text
	
	align 8	
	
	global ft_strdup
	
	ft_strdup:
	
		mov rbx, rdi
		call ft_strlen
		inc rax
		mov rdi, rax
		call malloc wrt ..plt
		cmp rax, 0
		je malloc_failure
		mov rdi, rax
		mov rsi, rbx
		call ft_strcpy
		ret
		malloc_failure:
			call __errno_location wrt ..plt
			neg rbx
			mov [rax], rbx
			mov rax, 0
			ret
