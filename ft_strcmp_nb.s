section .text
	
	align 8	
	
	global ft_cmp_nb
	
	ft_cmp_nb:
	
	xor rax, rax ;same as mov rax, 0
	
	mov rax, [rdi]
	sub rax, [rsi]
	
	ret
