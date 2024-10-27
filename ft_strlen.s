section .text
	
	align 8	
	
	global ft_strlen
	
	ft_strlen:
	
	mov rax, 0 ;i = 0
	start_loop:
		cmp byte [rdi + rax], 0
		je end_loop ;exit if equal (zf=0)
		inc rax ;++i
		jmp start_loop
	end_loop:
		ret
	
