global ft_strcmp

ft_strcmp:
	cmp	rsi, 0
	jz	is_null
	cmp	rdi, 0
	jz	is_null
	mov	rcx, 0
	jmp	loop
loop:
	mov	dl, byte[rsi + rcx]
	cmp	dl, byte[rdi + rcx]
	jnbe	is_less
	jb	is_big
	je	is_equal
	
is_equal:
	cmp	dl, 0
	je	is_null
	inc	rcx
	jmp	loop
is_null:
	mov	rax, 0
	ret
is_less:
	mov	rax, -1
	ret
is_big:
	mov	rax, 1
	ret
