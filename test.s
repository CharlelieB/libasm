;this is a comment

section .text
	
	align 8	
	
	global ft_strlen
	
	ft_strlen:

	;calling convention
	push rbp ;save old base pointer
	mov rbp, rsp ;set new base pointer

	mov rax, [rbp + 16] ;move the argument (the string) to rax, which is at base pointer + 16

	sub rsp, 8 ;allocate 8 bytes on stack for the counter
	
	mov [rbp-8], rbx ;
	pop rbp ;restore old base pointer
	ret
	

; push instruction decrement rsp register by the size of pushed value, and store the pushed value at current addr of rsp register
