section .text
	
	align 8	
	
	global ft_isalnum
	
	ft_isalnum:
	
	mov rax, 0
	
	;check uppercase
	cmp rdi, 65
	jl check_nb ;if < 'A', can't be alpha so move to number check
	cmp rdi, 90
	jle alnum_true ;return true if >= 'A' but <= 'Z'

	check_lowercase:
	
	cmp rdi, 97
	jl end ;if < 'a' return false
	cmp rdi, 122
	jle alnum_true ;if <= 'z' return true
	jmp end ;else return false

	check_nb:

	cmp rdi, 48
	jl end ;if < '0' return false
	cmp rdi, 57
	jg end ;if > '9' return false

	alnum_true:
		mov rax, 1

	end:
	ret

