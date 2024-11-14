extern ft_strlen
extern ft_isalnum
extern __errno_location

section .data
    bool_array db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  ;256 bits all set to 0

section .text
	
	align 8	
	
	global ft_atoi_base
	
	ft_atoi_base:

		push rbx
		mov rcx, 0
		;check if ptr are null
		cmp rdi, 0
		je wrong_base
		cmp rsi, 0
		je wrong_base

		mov r8, rdi ;save 1st arg
		mov rdi, rsi
		call ft_strlen
		;save nb len
		mov rcx, rax
		cmp rcx, 1
		;return if len <= 1
		jbe wrong_base

		;check base format

		mov r9, 0 ;i = 0

		lea rbx, [rel bool_array]
		start_loop:
			cmp byte [rsi + r9], 0
			je end_loop ;exit if equal (zf=0)
			mov dl, byte [rsi + r9] ;only rbx can be use as index
			cmp byte [rbx + rdx], 1
			je wrong_base
			mov byte [rbx + rdx], 1
			inc rax ;++i
			jmp start_loop

		end_loop:
		
		pop rbx
		ret

		wrong_base:
			pop rbx
			mov rax, 0
			ret
