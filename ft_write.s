extern __errno_location

section .text
	
	align 8	
	
	global ft_write
	
	ft_write:
	
		push rbx
		mov rax, 1 ;sys_write
		syscall
		cmp rax, -1
		jg end
		;set errno
		mov rbx, rax ;save write return
		call __errno_location wrt ..plt
		neg rbx ;change sign
		mov [rax], rbx ;put the return value in errno variable
		mov rax, -1
	end:
		pop rbx
		ret
