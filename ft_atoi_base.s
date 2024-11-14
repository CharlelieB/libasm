extern ft_strlen
extern ft_isalnum
extern __errno_location

section .text
	
	align 8	
	
	global ft_atoi_base
	
	ft_atoi_base:
	
		mov rcx, 0
		#check if ptr are null
		cmp rdi, 0
		je wrong_base
		cmp rsi, 0
		je wrong_base

		mov r8, rdi #save 1st arg
		mov rdi, rsi
		call ft_strlen
		#save nb len
		mov rcx, rax
		cmp rcx, 1
		#return if len <= 1
		jbe wrong_base

		#check base format

		push rcx #save rcx on stack
		push rdi #save 1st arg
		mov r9, 0 ;i = 0
		start_loop:
			cmp byte [rsi + r9], 0
			je end_loop ;exit if equal (zf=0)
			mov rdi, byte [rsi + r9]
			call ft_isalnum
			cmp rax, 0
			je wrong_base
			inc rax ;++i
			dec rcx
			jmp start_loop

		end_loop:
			

		ret

		wrong_base:
			mov rax, 0
			ret
