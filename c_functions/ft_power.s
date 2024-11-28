section .text
	
	align 8	
	
	global ft_power_test

	ft_power_test:
	mov rax, 1
	cmp rsi, 0 ;if exponent = 0 return 1
	je end
	push rsi
	shr rsi, 1 ;divide exponent by 2
	call ft_power_test
	mov r8, rax ;save result
	pop rsi
	test rsi, 1 ;r8 & 1 and carry flag is 0 if even (r8 % 2)
	jz is_even
	jmp is_odd

	end:
	ret

	is_even:
		imul r8, r8
		mov rax, r8
		jmp end

	is_odd:
		imul r8, r8
		imul r8, rdi
		mov rax, r8
		jmp end


; int	ft_power(int x, unsigned int y)
; {
; 	int	temp;

; 	if (y == 0)
; 		return (1);
; 	temp = ft_power(x, y / 2);
; 	if (y % 2 == 0)
; 		return (temp * temp);
; 	else
; 		return (x * temp * temp);
; }

; x = 2
; y = 5
; 5/2 = 2
; 2/2 = 1
; 1/2 = 0
; return 1
; tmp = 1
; return 1 * 1 * 2
; tmp = 2
; return 2 * 2 = 4
; tmp = 4
; return 4 * 4 * 2 = 32