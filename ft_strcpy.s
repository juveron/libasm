global ft_strcpy

ft_strcpy:
	cmp	rdi, 0
	jz	return
	mov	rcx, 0
loop:
	mov	dl, byte[rsi, rcx]
	mov	byte[rdi, rcx], dl
	cmp	dl, 0
	jz	return
	inc	rcx
	jmp	loop
return:
	mov	rax, rdi
	ret
