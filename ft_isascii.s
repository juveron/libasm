global	_ft_isascii

_ft_isascii:
	cmp	rdi,	127
	jg	is_no_ascii
is_ascii:
	mov	rax,	1
	ret
is_not_ascii:
	xor	rax,	rax
	ret
