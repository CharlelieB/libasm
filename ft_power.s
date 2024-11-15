section .text
	
	align 8	
	
	global ft_power

	ft_power:
	mov rax, 1
	cmp rsi, 0 ;if exponent = 0 return 1
	je end
	push rsi
	shr rsi, 1 ;divide exponent by 2
	call ft_power
	mov r8, rax ;save result
	pop rsi
	test r8, 1 ;r8 & 1 and carry flag is 0 if even (r8 % 2)
	jz is_even
	jmp is_odd

	end:
	ret

	is_even:
		imul rax, r8
		jmp end

	is_odd:
		imul r8
		imul r8, rdi
		mov rax, r8
		jmp end

