section .text
	
	align 8	
	
	global ft_strcmp
	
	ft_strcmp:
	
	xor rax, rax ;same as mov rax, 0
	start_loop:
		; similar to *s1 | *s2
		cmp byte [rdi], 0
		jne main_loop ;if not equal
		cmp byte [rsi], 0
		je end_loop
	main_loop:
		mov al, byte [rdi]
		sub al, byte [rsi]
		jne convert_al
		inc rdi
		inc rsi
		jmp start_loop
	convert_al:
		movsx rax, al
	end_loop:
		ret
