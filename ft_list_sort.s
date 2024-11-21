section .text
	
	align 8	
	
	global ft_list_sort

	ft_list_sort:

	cmp rdi, 0
	je end
	cmp qword [rdi], 0
	je end
	cmp rsi, 0
	je end

	push rbx
	push r15 ;swapped
	push r12 ;t_list *ptr
	push r13 ;t_list *lptr
	push r14

	mov r13, 0 ;lptr = NULL
	mov rbx, rsi ;save addr of function cmp
	mov r14, rdi ;save begin_list

	loop:
		mov r15, 0 ;swapped = 0
		mov r12, [r14] ;ptr = *begin_list
	snd_loop:
		cmp [r12 + 8], r13
		je end_snd_loop ;if ptr->next = lptr
		mov rdi, [r12] ;put ptr->data in arg
		mov r8, [r12 + 8] ;ptr->next in r8
		mov rsi, [r8] ;put ptr->next->data in sec arg
		call rbx ;call cmp
		cdqe ;signed extend eax result to rax
		cmp rax, 0
		jle list_advance ;if cmp return <= 0, no sorting
		;sort
		mov r8, [r12] ;tmp = ptr->data
		mov r9, [r12 + 8] ; var = ptr->next
		mov r10, [r9] ;ptr->next->data
		mov [r12], r10 ; ptr->data = ptr->next->data
		mov [r9], r8 ;ptr->next->data = tmp
		mov r15, 1 ;swapped = 1
		list_advance:
			mov r8, [r12 + 8] ;ptr->next
			mov r12, r8 ;ptr = ptr->next
		jmp snd_loop

		end_snd_loop:
			mov r13, r12 ;lptr = ptr
		cmp r15, 0
		jne loop ;if swapped != 0 keep koing
	
	pop r14
	pop r13
	pop r12
	pop r15
	pop rbx

	end:
    	ret