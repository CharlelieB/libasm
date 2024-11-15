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
	
	iterate_base:
		cmp byte [rsi + r9], 0
		je end_iterate_base
		xor rdx, rdx
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

	;SKIP SPACES
	skip_spaces:
		cmp byte [rdi + r10], 32
		jne skip_whitespaces
		add rdi, 8
		jmp skip_spaces

	skip_whitespaces:
		cmp byte [rdi + r10], 9
		jle iterate_nb
		cmp byte [rdi + r10], 13
		jge iterate_nb
		add rdi, 8
		jmp skip_spaces

	iterate_nb:
		cmp byte [rdi + r10], 0
		je convert_base
		xor rdx, rdx
		mov dl, byte [rdi + r10]
		cmp byte [rbx + rdx], 0
		je wrong_base
		inc r10
		jmp iterate_nb

	;iterate over nb str
	convert_base:
		mov r11, 0
	.loop:
		cmp byte [rdi], 0
		je end
		;jmp wrong_base
		push rdi
		push rsi
		mov dil, byte [rdi]
		and rdi, 0FFh ;just in case, clear all bytes except the least signigicant
		call get_index
		mov r8, rax ;save the index
		mov rdi, r9 ;base len as first arg
		dec r10 ;decrement size of nb
		mov rsi, r10 ;nb len - 1 as sec arg
		push r8
		call ft_power
		pop r8
		imul r8, rax ;multiply index with power
		add r11, r8 ; add result to nb
		pop rsi
		pop rdi
		inc rdi ;advance in nb str
		jmp .loop
		
	end:
		mov rax, r11
		pop rbx
		ret

	wrong_base:
		pop rbx
		mov rax, 0
		ret

	;FT_POWER ----

	ft_power:
		mov rax, 1
		cmp rsi, 0 ;if exponent = 0 return 1
		je base_case
		push rsi
		shr rsi, 1 ;divide exponent by 2
		call ft_power
		mov r8, rax ;save result
		pop rsi
		test rsi, 1 ;test if exponent is odd. rsi & 1, carry flag is 0 if even (rsi % 2)
		jz is_even
		imul r8, r8
		imul r8, rdi
		mov rax, r8
		jmp base_case

	is_even:
		imul r8, r8
		mov rax, r8
		jmp base_case

	base_case:
		ret

	;GET_INDEX ----

	get_index:
		mov rax, 0
	
	.loop:
		cmp byte [rsi + rax], 0
		je get_index_end
		cmp byte [rsi + rax], dil
		je get_index_end
		inc rax
		jmp .loop

	get_index_end:
		ret
