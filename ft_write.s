section .text
	
	align 8	
	
	global ft_write
	
	ft_write:
	
	mov rax, 1 ;rax = 4 to call write syscall
	mov rbx, rdi
	mov rcx, rsi
	;rdx is already set
	syscall
	ret
