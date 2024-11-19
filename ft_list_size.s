section .text
	
	align 8	
	
	global ft_list_size

	ft_list_size:

	mov rax, 0 ;i = 0
    
	loop:
		cmp rdi, 0
		je end
		mov rcx, [rdi + 8]
    	mov rdi, rcx
		inc rax
		jmp loop

	end:
    	ret