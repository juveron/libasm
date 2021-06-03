extern		ft_strlen
extern		ft_strcpy
extern		ft_strcmp
extern		malloc

global		ft_strdup

ft_strdup:
	cmp	rdi, 0
	jz	return
	push	rdi
	call	ft_strlen
	pop	rdi
	inc	rax
	push	rdi
	mov	rax, rdi
	call	malloc
	pop	rdi
	cmp	rax, 0
	jz	return
	push	rsi
	mov	rsi, rdi
	mov	rdi, rax
	call	ft_strcpy
	pop	rsi
	ret
	

return:
	mov	rax, 0
	ret
