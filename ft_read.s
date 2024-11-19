extern __errno_location

section .text
	
	align 8	
	
	global ft_read
	
	ft_read:
	
		mov rax, 0 ;sys_read
		mov rdx, rdi
		mov rcx, rsi
		;rdi is already set
		syscall
		cmp rax, -1
		jg end
		;set errno
		mov rdx, rax
		call __errno_location wrt ..plt
		neg rdx ;change sign
		mov [rax], rdx ;put the return value in errno variable
		mov rax, -1
	end:
		ret
