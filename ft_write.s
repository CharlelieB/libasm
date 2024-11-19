extern __errno_location

section .text
	
	align 8	
	
	global ft_write
	
	ft_write:
	
		mov rax, 1 ;sys_write
		mov rdx, rdi
		mov rcx, rsi
		;rdx is already set
		syscall
		cmp rax, -1
		jg end
		;set errno
		mov rdx, rax ;save write return
		call __errno_location wrt ..plt
		neg rdx ;change sign
		mov [rax], rdx ;put the return value in errno variable
		mov rax, -1
	end:
		ret
