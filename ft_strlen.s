global ft_strlen

ft_strlen:
	push	rcx
	xor	rcx, rcx

loop:
	cmp	[rdi], byte 0
	jz	return
	inc	rcx
	inc	rdi
	jmp	loop

return:
	mov	rax, rcx
	pop	rcx
	ret
