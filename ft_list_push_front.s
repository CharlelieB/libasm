extern malloc
extern __errno_location

section .text
	
	align 8	
	
	global ft_list_push_front

	ft_list_push_front:
    
    push rdi
    push rsi
    mov rdi, 16 ;struct is 16 bytes
	call malloc wrt ..plt
    pop rsi
    pop rdi
    cmp rax, 0
	je malloc_failure

    mov [rax], rsi
    mov rcx, [rdi]
    mov [rax + 8], rcx
    mov [rdi], rax

    ret
    malloc_failure:
    	mov rdx, rax
		call __errno_location wrt ..plt
		neg rdx
		mov [rax], rdx
		mov rax, 0
		ret