extern ft_strlen
extern ft_isalnum
extern __errno_location

section .data
    bool_array db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  ;256 bits all set to 0

section .text
	
	align 8	
	
	global ft_atoi_base
	
	ft_atoi_base:

		;base_len -> r9
		;nb_len ->r10
		push rbx
		
		;PARSING
		;check if ptr are null
		cmp rdi, 0
		je wrong_base
		cmp rsi, 0
		je wrong_base

		;check base format

		mov r9, 0 ;i = 0

		lea rbx, [rel bool_array]
		xor rdx, rdx
		iterate_base:
			cmp byte [rsi + r9], 0
			je end_iterate_base
			mov dl, byte [rsi + r9] ;set the char in dl to use it as index with rdx
			cmp byte [rbx + rdx], 1
			je wrong_base
			mov byte [rbx + rdx], 1
			inc r9 ;++i
			jmp iterate_base

		end_iterate_base:
	
		;return if base len <= 1
		cmp r9, 1
		jle wrong_base

		;calculate nb string size and check if chars exist in base
		mov r10, 0
		xor rdx, rdx

		;SKIP SPACES
		skip_spaces:
			cmp byte [rdi + r10], 32
			jne skip_whitespaces
			add rdi, 8
			skip_spaces
		skip_whitespaces:
			cmp byte [rdi + r10], 9
			jle iterate_nb
			cmp byte [rdi + r10], 13
			jge iterate_nb
			add rdi, 8
			skip_spaces

		iterate_nb:
			cmp byte [rdi + r10], 0
			je end_iterate_nb
			mov dl, byte [rdi + r10]
			cmp byte [rbx + rdx], 1
			je wrong_base
			inc r10
			jmp iterate_nb	

		end_iterate_nb:

		;iterate over nb str
		convert_base:
			cmp byte [rdi], 0
			je end
			push rdi
			push rsi
			mov rdi, byte [rdi]
			call get_index
			pop rdi
			mov r8, rax ;save the index
			
			add rdi, 8
			dec r10	
		
		ft_power:
			mov r8, 0
			mov r12, 1
			loop_power:
				cmp r10 - 1, 0
				je convert_base
		end:
			pop rbx
			ret

		wrong_base:
			pop rbx
			mov rax, 0
			ret


get_index:
	mov rax, 0
	
	loop:
		cmp byte [rsi + rax], 0
		je end
		cmp byte [rsi, rax], rdi
		je end
		inc rax
	end:
	ret

ft_power:
	mov rax, 1
	cmp rsi, 0
	je end
	push rax
	push rsi
	shr rsi, 1 ;divide exponent by 2
	call ft_power
	mov r8, rax
	pop rsi
	pop rax
	test r8, 2 ;r8 & 2 and carry flag is 0 if even (r8 % 2)
	jz is_even
	end:
	ret

	is_even:
		r8 * r8
		jmp end

	is_odd:
		r8 * r8 * rdi
		jmp end
