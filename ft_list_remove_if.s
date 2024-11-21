extern free

section .text
	
	align 8	
	
	global ft_list_remove_if

    ft_list_remove_if:

    cmp rdi, 0
	je end
	cmp qword [rdi], 0
	je end
	cmp rdx, 0 ;if cpm funct is null
	je end
    cmp rcx, 0 ;if del funct is null
    je end

    push rbx
    push r12 ;save data_ref
    push r13 ;save cmp ft
    push r14 ;save del ft
    push r15

    mov r12, rsi ;save data_ref
    mov r13, rdx ;save cmp ft
    mov r14, rcx ;save del ft

    mov rbx, [rdi] ;tmp = *begin_list
    mov r9, 0 ;prev = 0
    mov r10, rdi ;save **begin_list to update head if needed 

    loop:
        cmp rbx, 0 ;if tmp = 0
        je end_loop

        mov rdi, [rbx] ;put tmp->data in arg
		mov rsi, r12 ;put data_ref in snd arg
        
        push r9
        push r10
		call r13 ;call cmp
        cdqe ;signed extend eax result to rax    
        pop r10
        pop r9
        cmp rax, 0
        jne list_advance ;if cmp return != 0, don't delete
        mov rdi, [rbx] ;put tmp->data in arg
        push r9
        push r10
        call r14 ;call del ft
        pop r10
        pop r9
        mov r15, [rbx + 8] ;next = tmp->next
        mov rdi, rbx
        push r9
        push r10
        call free wrt ..plt
        pop r10
        pop r9
        mov rbx, r15 ;tmp = next
        cmp r9, 0
        je update_head ;if prev = NULL, we must update the head of the list
        mov [r9 + 8], rbx ; prev->next = tmp (update the next of prev)
        jmp loop
        update_head:
        mov [r10], rbx ; *begin_list = tmp
        jmp loop
        list_advance:
        mov r9, rbx ; prev = tmp 
        mov r8, [rbx + 8] ;tmp->next
		mov rbx, r8 ;tmp = tmp->next 
        jmp loop

    end_loop:
    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx
    
    end:

    ret