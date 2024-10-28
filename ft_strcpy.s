section .text
	
	align 8	
	
	global ft_strcpy
	
	ft_strcpy:
	
	mov rax, 0 ;i = 0
	start_loop:
		cmp byte [rsi + rax], 0 ; while src[i]
		je end_loop
		mov cl, byte [rsi + rax]
		mov byte [rdi + rax], cl
		inc rax
		jmp start_loop
	end_loop:
		mov byte [rdi + rax], 0 ;null terminate
		mov rax, rdi ;put the result in rax to return it
		ret
