extern __errno_location

section .text
	
	align 8	
	
	global ft_read
	
	ft_read:
	
		push rbx
		mov rax, 0 ;sys_read
		syscall
		cmp rax, -1
		jg end
		;set errno
		mov rbx, rax
		call __errno_location wrt ..plt
		neg rbx ;change sign
		mov [rax], rbx ;put the return value in errno variable
		mov rax, -1
	end:
		pop rbx
		ret
