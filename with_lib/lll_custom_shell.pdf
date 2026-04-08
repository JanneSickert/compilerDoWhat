	.file	"lll_custom_shell.c"
	.intel_syntax noprefix
	.text
	.local	unix_index
	.comm	unix_index,4,4
	.data
	.align 4
	.type	unix_max, @object
	.size	unix_max, 4
unix_max:
	.long	1024
	.local	mem_head
	.comm	mem_head,8,8
	.section	.rodata
.LC0:
	.string	"txt"
.LC1:
	.string	"c"
.LC2:
	.string	"cpp"
.LC3:
	.string	"ino"
.LC4:
	.string	"py"
.LC5:
	.string	"java"
.LC6:
	.string	"sh"
.LC7:
	.string	"js"
.LC8:
	.string	"html"
.LC9:
	.string	"asm"
.LC10:
	.string	"rs"
	.section	.data.rel.local,"aw"
	.align 32
	.type	types, @object
	.size	types, 352
types:
	.long	0
	.zero	4
	.quad	.LC0
	.quad	0
	.long	0
	.zero	4
	.long	0
	.zero	4
	.quad	.LC1
	.quad	0
	.long	1
	.zero	4
	.long	0
	.zero	4
	.quad	.LC2
	.quad	0
	.long	2
	.zero	4
	.long	0
	.zero	4
	.quad	.LC3
	.quad	0
	.long	3
	.zero	4
	.long	0
	.zero	4
	.quad	.LC4
	.quad	0
	.long	4
	.zero	4
	.long	0
	.zero	4
	.quad	.LC5
	.quad	0
	.long	5
	.zero	4
	.long	0
	.zero	4
	.quad	.LC6
	.quad	0
	.long	6
	.zero	4
	.long	0
	.zero	4
	.quad	.LC7
	.quad	0
	.long	7
	.zero	4
	.long	0
	.zero	4
	.quad	.LC8
	.quad	0
	.long	8
	.zero	4
	.long	0
	.zero	4
	.quad	.LC9
	.quad	0
	.long	9
	.zero	4
	.long	0
	.zero	4
	.quad	.LC10
	.quad	0
	.long	10
	.zero	4
	.section	.rodata
.LC11:
	.string	"undefined"
.LC12:
	.string	"C"
.LC13:
	.string	"C++"
.LC14:
	.string	"ESP"
.LC15:
	.string	"Python"
.LC16:
	.string	"Java"
.LC17:
	.string	"ShellScript"
.LC18:
	.string	"JavaScript"
.LC19:
	.string	"HTML"
.LC20:
	.string	"Assembly"
.LC21:
	.string	"Rust"
	.section	.data.rel.local
	.align 32
	.type	nameList, @object
	.size	nameList, 88
nameList:
	.quad	.LC11
	.quad	.LC12
	.quad	.LC13
	.quad	.LC14
	.quad	.LC15
	.quad	.LC16
	.quad	.LC17
	.quad	.LC18
	.quad	.LC19
	.quad	.LC20
	.quad	.LC21
	.section	.rodata
	.align 32
	.type	colorList, @object
	.size	colorList, 88
colorList:
	.quad	37529549567948
	.quad	37529514829414
	.quad	37529594241791
	.quad	37529691531776
	.quad	37529435285602
	.quad	37529441009408
	.quad	37529440944144
	.quad	37529436487696
	.quad	37529433180296
	.quad	37529440978944
	.quad	37529438823812
.LC22:
	.string	"w"
.LC23:
	.string	"xclip -selection clipboard"
	.text
	.globl	clipper
	.type	clipper, @function
clipper:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	QWORD PTR -40[rbp], rdi
	mov	rax, QWORD PTR -40[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	QWORD PTR -8[rbp], rax
	lea	rax, .LC22[rip]
	mov	rsi, rax
	lea	rax, .LC23[rip]
	mov	rdi, rax
	call	popen@PLT
	mov	QWORD PTR -16[rbp], rax
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	fileno@PLT
	mov	DWORD PTR -20[rbp], eax
	mov	rdx, QWORD PTR -8[rbp]
	mov	rcx, QWORD PTR -40[rbp]
	mov	eax, DWORD PTR -20[rbp]
	mov	rsi, rcx
	mov	edi, eax
	call	write@PLT
	mov	QWORD PTR -32[rbp], rax
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	pclose@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	clipper, .-clipper
	.type	mode_to_str, @function
mode_to_str:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -4[rbp], edi
	mov	QWORD PTR -16[rbp], rsi
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 61440
	cmp	eax, 16384
	je	.L3
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 61440
	cmp	eax, 40960
	je	.L4
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 61440
	cmp	eax, 8192
	je	.L5
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 61440
	cmp	eax, 24576
	je	.L6
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 61440
	cmp	eax, 4096
	je	.L7
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 61440
	cmp	eax, 49152
	jne	.L8
	mov	eax, 115
	jmp	.L14
.L8:
	mov	eax, 45
	jmp	.L14
.L7:
	mov	eax, 112
	jmp	.L14
.L6:
	mov	eax, 98
	jmp	.L14
.L5:
	mov	eax, 99
	jmp	.L14
.L4:
	mov	eax, 108
	jmp	.L14
.L3:
	mov	eax, 100
.L14:
	mov	rdx, QWORD PTR -16[rbp]
	mov	BYTE PTR [rdx], al
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 256
	test	eax, eax
	je	.L15
	mov	edx, 114
	jmp	.L16
.L15:
	mov	edx, 45
.L16:
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 1
	mov	BYTE PTR [rax], dl
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 128
	test	eax, eax
	je	.L17
	mov	edx, 119
	jmp	.L18
.L17:
	mov	edx, 45
.L18:
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 2
	mov	BYTE PTR [rax], dl
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 64
	test	eax, eax
	je	.L19
	mov	edx, 120
	jmp	.L20
.L19:
	mov	edx, 45
.L20:
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 3
	mov	BYTE PTR [rax], dl
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 32
	test	eax, eax
	je	.L21
	mov	edx, 114
	jmp	.L22
.L21:
	mov	edx, 45
.L22:
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 4
	mov	BYTE PTR [rax], dl
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 16
	test	eax, eax
	je	.L23
	mov	edx, 119
	jmp	.L24
.L23:
	mov	edx, 45
.L24:
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 5
	mov	BYTE PTR [rax], dl
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 8
	test	eax, eax
	je	.L25
	mov	edx, 120
	jmp	.L26
.L25:
	mov	edx, 45
.L26:
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 6
	mov	BYTE PTR [rax], dl
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 4
	test	eax, eax
	je	.L27
	mov	edx, 114
	jmp	.L28
.L27:
	mov	edx, 45
.L28:
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 7
	mov	BYTE PTR [rax], dl
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 2
	test	eax, eax
	je	.L29
	mov	edx, 119
	jmp	.L30
.L29:
	mov	edx, 45
.L30:
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 8
	mov	BYTE PTR [rax], dl
	mov	eax, DWORD PTR -4[rbp]
	and	eax, 1
	test	eax, eax
	je	.L31
	mov	edx, 120
	jmp	.L32
.L31:
	mov	edx, 45
.L32:
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 9
	mov	BYTE PTR [rax], dl
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 10
	mov	BYTE PTR [rax], 0
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	mode_to_str, .-mode_to_str
	.type	isDoubleIndex, @function
isDoubleIndex:
.LFB2:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -4[rbp], edi
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	sal	rax, 5
	mov	rdx, rax
	lea	rax, types[rip]
	mov	eax, DWORD PTR [rdx+rax]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	isDoubleIndex, .-isDoubleIndex
	.section	.rodata
.LC24:
	.string	"B"
.LC25:
	.string	"KB"
.LC26:
	.string	"MB"
.LC27:
	.string	"GB"
.LC28:
	.string	"TB"
.LC30:
	.string	"%.1f %s"
	.text
	.type	process_size, @function
process_size:
.LFB3:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 96
	mov	QWORD PTR -72[rbp], rdi
	mov	QWORD PTR -80[rbp], rsi
	mov	QWORD PTR -88[rbp], rdx
	lea	rax, .LC24[rip]
	mov	QWORD PTR -64[rbp], rax
	lea	rax, .LC25[rip]
	mov	QWORD PTR -56[rbp], rax
	lea	rax, .LC26[rip]
	mov	QWORD PTR -48[rbp], rax
	lea	rax, .LC27[rip]
	mov	QWORD PTR -40[rbp], rax
	lea	rax, .LC28[rip]
	mov	QWORD PTR -32[rbp], rax
	pxor	xmm0, xmm0
	cvtsi2sd	xmm0, QWORD PTR -72[rbp]
	movsd	QWORD PTR -8[rbp], xmm0
	mov	DWORD PTR -12[rbp], 0
	jmp	.L36
.L39:
	movsd	xmm0, QWORD PTR -8[rbp]
	movsd	xmm1, QWORD PTR .LC29[rip]
	divsd	xmm0, xmm1
	movsd	QWORD PTR -8[rbp], xmm0
	add	DWORD PTR -12[rbp], 1
.L36:
	movsd	xmm0, QWORD PTR -8[rbp]
	comisd	xmm0, QWORD PTR .LC29[rip]
	jb	.L37
	cmp	DWORD PTR -12[rbp], 3
	jle	.L39
.L37:
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	mov	rcx, QWORD PTR -64[rbp+rax*8]
	mov	rdx, QWORD PTR -8[rbp]
	mov	rsi, QWORD PTR -88[rbp]
	mov	rax, QWORD PTR -80[rbp]
	movq	xmm0, rdx
	lea	rdx, .LC30[rip]
	mov	rdi, rax
	mov	eax, 1
	call	snprintf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	process_size, .-process_size
	.globl	memlist_add
	.type	memlist_add, @function
memlist_add:
.LFB4:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	cmp	QWORD PTR -24[rbp], 0
	jne	.L42
	mov	eax, -1
	jmp	.L43
.L42:
	mov	edi, 16
	call	malloc@PLT
	mov	QWORD PTR -8[rbp], rax
	cmp	QWORD PTR -8[rbp], 0
	jne	.L44
	mov	eax, -1
	jmp	.L43
.L44:
	mov	rax, QWORD PTR -8[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	QWORD PTR [rax], rdx
	mov	rdx, QWORD PTR mem_head[rip]
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR 8[rax], rdx
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR mem_head[rip], rax
	mov	eax, 0
.L43:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	memlist_add, .-memlist_add
	.globl	memlist_free_all
	.type	memlist_free_all, @function
memlist_free_all:
.LFB5:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	rax, QWORD PTR mem_head[rip]
	mov	QWORD PTR -8[rbp], rax
	jmp	.L46
.L48:
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR 8[rax]
	mov	QWORD PTR -16[rbp], rax
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR [rax]
	test	rax, rax
	je	.L47
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR [rax]
	mov	rdi, rax
	call	free@PLT
.L47:
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	free@PLT
	mov	rax, QWORD PTR -16[rbp]
	mov	QWORD PTR -8[rbp], rax
.L46:
	cmp	QWORD PTR -8[rbp], 0
	jne	.L48
	mov	QWORD PTR mem_head[rip], 0
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	memlist_free_all, .-memlist_free_all
	.section	.rodata
.LC31:
	.string	"\033[0m"
	.align 8
.LC32:
	.string	"\033[38;2;%u;%u;%um\033[48;2;%u;%u;%um"
	.text
	.globl	coloramaprintifarma
	.type	coloramaprintifarma, @function
coloramaprintifarma:
.LFB6:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 96
	mov	QWORD PTR -88[rbp], rdi
	mov	QWORD PTR -96[rbp], rsi
	mov	rax, QWORD PTR -96[rbp]
	shr	rax, 40
	mov	BYTE PTR -1[rbp], al
	mov	rax, QWORD PTR -96[rbp]
	shr	rax, 32
	mov	BYTE PTR -2[rbp], al
	mov	rax, QWORD PTR -96[rbp]
	shr	rax, 24
	mov	BYTE PTR -3[rbp], al
	mov	rax, QWORD PTR -96[rbp]
	shr	rax, 16
	mov	BYTE PTR -4[rbp], al
	mov	rax, QWORD PTR -96[rbp]
	shr	rax, 8
	mov	BYTE PTR -5[rbp], al
	mov	rax, QWORD PTR -96[rbp]
	mov	BYTE PTR -6[rbp], al
	lea	rax, .LC31[rip]
	mov	QWORD PTR -16[rbp], rax
	lea	rax, .LC32[rip]
	mov	QWORD PTR -24[rbp], rax
	movzx	edi, BYTE PTR -3[rbp]
	movzx	esi, BYTE PTR -2[rbp]
	movzx	ecx, BYTE PTR -1[rbp]
	movzx	r9d, BYTE PTR -6[rbp]
	movzx	r8d, BYTE PTR -5[rbp]
	movzx	edx, BYTE PTR -4[rbp]
	mov	rax, QWORD PTR -24[rbp]
	sub	rsp, 8
	push	rdi
	push	rsi
	push	rcx
	mov	ecx, edx
	mov	rdx, rax
	mov	esi, 0
	mov	edi, 0
	mov	eax, 0
	call	snprintf@PLT
	add	rsp, 32
	mov	DWORD PTR -28[rbp], eax
	cmp	DWORD PTR -28[rbp], 0
	jns	.L50
	mov	eax, 0
	jmp	.L51
.L50:
	mov	rax, QWORD PTR -88[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	QWORD PTR -40[rbp], rax
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	QWORD PTR -48[rbp], rax
	mov	eax, DWORD PTR -28[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -40[rbp]
	add	rdx, rax
	mov	rax, QWORD PTR -48[rbp]
	add	rax, rdx
	add	rax, 1
	mov	QWORD PTR -56[rbp], rax
	mov	rax, QWORD PTR -56[rbp]
	mov	rdi, rax
	call	malloc@PLT
	mov	QWORD PTR -64[rbp], rax
	cmp	QWORD PTR -64[rbp], 0
	jne	.L52
	mov	eax, 0
	jmp	.L51
.L52:
	mov	rax, QWORD PTR -64[rbp]
	mov	rdi, rax
	call	memlist_add
	movzx	r9d, BYTE PTR -3[rbp]
	movzx	r8d, BYTE PTR -2[rbp]
	movzx	edi, BYTE PTR -1[rbp]
	movzx	r11d, BYTE PTR -6[rbp]
	movzx	r10d, BYTE PTR -5[rbp]
	movzx	ecx, BYTE PTR -4[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	rsi, QWORD PTR -56[rbp]
	mov	rax, QWORD PTR -64[rbp]
	sub	rsp, 8
	push	r9
	push	r8
	push	rdi
	mov	r9d, r11d
	mov	r8d, r10d
	mov	rdi, rax
	mov	eax, 0
	call	snprintf@PLT
	add	rsp, 32
	mov	DWORD PTR -68[rbp], eax
	mov	eax, DWORD PTR -68[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -64[rbp]
	lea	rcx, [rdx+rax]
	mov	rdx, QWORD PTR -40[rbp]
	mov	rax, QWORD PTR -88[rbp]
	mov	rsi, rax
	mov	rdi, rcx
	call	memcpy@PLT
	mov	rax, QWORD PTR -48[rbp]
	lea	rdx, 1[rax]
	mov	eax, DWORD PTR -68[rbp]
	movsx	rcx, eax
	mov	rax, QWORD PTR -40[rbp]
	add	rcx, rax
	mov	rax, QWORD PTR -64[rbp]
	add	rcx, rax
	mov	rax, QWORD PTR -16[rbp]
	mov	rsi, rax
	mov	rdi, rcx
	call	memcpy@PLT
	mov	rax, QWORD PTR -64[rbp]
.L51:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	coloramaprintifarma, .-coloramaprintifarma
	.type	utf8_char_len, @function
utf8_char_len:
.LFB7:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	eax, edi
	mov	BYTE PTR -4[rbp], al
	movzx	eax, BYTE PTR -4[rbp]
	test	al, al
	js	.L54
	mov	eax, 1
	jmp	.L55
.L54:
	movzx	eax, BYTE PTR -4[rbp]
	shr	al, 5
	cmp	al, 6
	jne	.L56
	mov	eax, 2
	jmp	.L55
.L56:
	movzx	eax, BYTE PTR -4[rbp]
	shr	al, 4
	cmp	al, 14
	jne	.L57
	mov	eax, 3
	jmp	.L55
.L57:
	movzx	eax, BYTE PTR -4[rbp]
	shr	al, 3
	cmp	al, 30
	jne	.L58
	mov	eax, 4
	jmp	.L55
.L58:
	mov	eax, 1
.L55:
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	utf8_char_len, .-utf8_char_len
	.type	coloramaprintifarmafillup, @function
coloramaprintifarmafillup:
.LFB8:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 64
	mov	QWORD PTR -56[rbp], rdi
	mov	QWORD PTR -64[rbp], rsi
	cmp	QWORD PTR -56[rbp], 0
	jne	.L60
	mov	eax, 0
	jmp	.L61
.L60:
	mov	edi, 16
	call	malloc@PLT
	mov	QWORD PTR -24[rbp], rax
	cmp	QWORD PTR -24[rbp], 0
	jne	.L62
	mov	eax, 0
	jmp	.L61
.L62:
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	memlist_add
	mov	QWORD PTR -8[rbp], 0
	mov	QWORD PTR -16[rbp], 0
	jmp	.L63
.L66:
	mov	rdx, QWORD PTR -56[rbp]
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movzx	eax, al
	mov	edi, eax
	call	utf8_char_len
	mov	QWORD PTR -32[rbp], rax
	mov	rdx, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR -32[rbp]
	add	rax, rdx
	cmp	rax, 15
	ja	.L69
	mov	rdx, QWORD PTR -56[rbp]
	mov	rax, QWORD PTR -16[rbp]
	lea	rsi, [rdx+rax]
	mov	rdx, QWORD PTR -24[rbp]
	mov	rax, QWORD PTR -8[rbp]
	lea	rcx, [rdx+rax]
	mov	rax, QWORD PTR -32[rbp]
	mov	rdx, rax
	mov	rdi, rcx
	call	memcpy@PLT
	mov	rax, QWORD PTR -32[rbp]
	add	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR -32[rbp]
	add	QWORD PTR -16[rbp], rax
.L63:
	cmp	QWORD PTR -8[rbp], 14
	ja	.L67
	mov	rdx, QWORD PTR -56[rbp]
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	test	al, al
	jne	.L66
	jmp	.L67
.L69:
	nop
	jmp	.L67
.L68:
	mov	rax, QWORD PTR -8[rbp]
	lea	rdx, 1[rax]
	mov	QWORD PTR -8[rbp], rdx
	mov	rdx, QWORD PTR -24[rbp]
	add	rax, rdx
	mov	BYTE PTR [rax], 32
.L67:
	cmp	QWORD PTR -8[rbp], 14
	jbe	.L68
	mov	rax, QWORD PTR -24[rbp]
	add	rax, 15
	mov	BYTE PTR [rax], 0
	mov	rdx, QWORD PTR -64[rbp]
	mov	rax, QWORD PTR -24[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	coloramaprintifarma
	mov	QWORD PTR -40[rbp], rax
	mov	rax, QWORD PTR -40[rbp]
.L61:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	coloramaprintifarmafillup, .-coloramaprintifarmafillup
	.section	.rodata
.LC33:
	.string	"\033[38;2;%u;%u;%um"
	.text
	.type	coll, @function
coll:
.LFB9:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 96
	mov	QWORD PTR -88[rbp], rdi
	mov	QWORD PTR -96[rbp], rsi
	mov	rax, QWORD PTR -88[rbp]
	shr	rax, 16
	mov	BYTE PTR -1[rbp], al
	mov	rax, QWORD PTR -88[rbp]
	shr	rax, 8
	mov	BYTE PTR -2[rbp], al
	mov	rax, QWORD PTR -88[rbp]
	mov	BYTE PTR -3[rbp], al
	lea	rax, .LC31[rip]
	mov	QWORD PTR -16[rbp], rax
	lea	rax, .LC33[rip]
	mov	QWORD PTR -24[rbp], rax
	movzx	esi, BYTE PTR -3[rbp]
	movzx	ecx, BYTE PTR -2[rbp]
	movzx	edx, BYTE PTR -1[rbp]
	mov	rax, QWORD PTR -24[rbp]
	mov	r9d, esi
	mov	r8d, ecx
	mov	ecx, edx
	mov	rdx, rax
	mov	esi, 0
	mov	edi, 0
	mov	eax, 0
	call	snprintf@PLT
	mov	DWORD PTR -28[rbp], eax
	cmp	DWORD PTR -28[rbp], 0
	jns	.L71
	mov	eax, 0
	jmp	.L72
.L71:
	mov	rax, QWORD PTR -96[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	QWORD PTR -40[rbp], rax
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	QWORD PTR -48[rbp], rax
	mov	eax, DWORD PTR -28[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -40[rbp]
	add	rdx, rax
	mov	rax, QWORD PTR -48[rbp]
	add	rax, rdx
	add	rax, 1
	mov	QWORD PTR -56[rbp], rax
	mov	rax, QWORD PTR -56[rbp]
	mov	rdi, rax
	call	malloc@PLT
	mov	QWORD PTR -64[rbp], rax
	cmp	QWORD PTR -64[rbp], 0
	jne	.L73
	mov	eax, 0
	jmp	.L72
.L73:
	mov	rax, QWORD PTR -64[rbp]
	mov	rdi, rax
	call	memlist_add
	movzx	r8d, BYTE PTR -3[rbp]
	movzx	edi, BYTE PTR -2[rbp]
	movzx	ecx, BYTE PTR -1[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	rsi, QWORD PTR -56[rbp]
	mov	rax, QWORD PTR -64[rbp]
	mov	r9d, r8d
	mov	r8d, edi
	mov	rdi, rax
	mov	eax, 0
	call	snprintf@PLT
	mov	DWORD PTR -68[rbp], eax
	mov	eax, DWORD PTR -68[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -64[rbp]
	lea	rcx, [rdx+rax]
	mov	rdx, QWORD PTR -40[rbp]
	mov	rax, QWORD PTR -96[rbp]
	mov	rsi, rax
	mov	rdi, rcx
	call	memcpy@PLT
	mov	rax, QWORD PTR -48[rbp]
	lea	rdx, 1[rax]
	mov	eax, DWORD PTR -68[rbp]
	movsx	rcx, eax
	mov	rax, QWORD PTR -40[rbp]
	add	rcx, rax
	mov	rax, QWORD PTR -64[rbp]
	add	rcx, rax
	mov	rax, QWORD PTR -16[rbp]
	mov	rsi, rax
	mov	rdi, rcx
	call	memcpy@PLT
	mov	rax, QWORD PTR -64[rbp]
.L72:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	coll, .-coll
	.type	chngg, @function
chngg:
.LFB10:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 80
	mov	QWORD PTR -56[rbp], rdi
	mov	QWORD PTR -64[rbp], rsi
	mov	DWORD PTR -68[rbp], edx
	cmp	DWORD PTR -68[rbp], 1
	jne	.L75
	mov	eax, 45
	jmp	.L76
.L75:
	mov	eax, 15
.L76:
	mov	DWORD PTR -20[rbp], eax
	mov	eax, DWORD PTR -20[rbp]
	add	eax, 1
	cdqe
	mov	rdi, rax
	call	malloc@PLT
	mov	QWORD PTR -32[rbp], rax
	cmp	QWORD PTR -32[rbp], 0
	jne	.L77
	mov	eax, 0
	jmp	.L78
.L77:
	mov	rax, QWORD PTR -32[rbp]
	mov	rdi, rax
	call	memlist_add
	mov	QWORD PTR -8[rbp], 0
	mov	QWORD PTR -16[rbp], 0
	jmp	.L79
.L82:
	mov	rdx, QWORD PTR -56[rbp]
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movzx	eax, al
	mov	edi, eax
	call	utf8_char_len
	mov	QWORD PTR -40[rbp], rax
	mov	rdx, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR -40[rbp]
	add	rax, rdx
	mov	edx, DWORD PTR -20[rbp]
	movsx	rdx, edx
	cmp	rdx, rax
	jb	.L85
	mov	rdx, QWORD PTR -56[rbp]
	mov	rax, QWORD PTR -16[rbp]
	lea	rsi, [rdx+rax]
	mov	rdx, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR -8[rbp]
	lea	rcx, [rdx+rax]
	mov	rax, QWORD PTR -40[rbp]
	mov	rdx, rax
	mov	rdi, rcx
	call	memcpy@PLT
	mov	rax, QWORD PTR -40[rbp]
	add	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR -40[rbp]
	add	QWORD PTR -16[rbp], rax
.L79:
	mov	eax, DWORD PTR -20[rbp]
	cdqe
	cmp	QWORD PTR -8[rbp], rax
	jnb	.L83
	mov	rdx, QWORD PTR -56[rbp]
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	test	al, al
	jne	.L82
	jmp	.L83
.L85:
	nop
	jmp	.L83
.L84:
	mov	rax, QWORD PTR -8[rbp]
	lea	rdx, 1[rax]
	mov	QWORD PTR -8[rbp], rdx
	mov	rdx, QWORD PTR -32[rbp]
	add	rax, rdx
	mov	BYTE PTR [rax], 32
.L83:
	mov	eax, DWORD PTR -20[rbp]
	cdqe
	cmp	QWORD PTR -8[rbp], rax
	jb	.L84
	mov	eax, DWORD PTR -20[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -32[rbp]
	add	rax, rdx
	mov	BYTE PTR [rax], 0
	mov	rdx, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR -64[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	coll
	mov	QWORD PTR -48[rbp], rax
	mov	rax, QWORD PTR -48[rbp]
.L78:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	chngg, .-chngg
	.type	chngg_wrapper, @function
chngg_wrapper:
.LFB11:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR -4[rbp], edi
	mov	QWORD PTR -16[rbp], rsi
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	lea	rax, colorList[rip]
	mov	rdx, QWORD PTR [rdx+rax]
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	lea	rcx, 0[0+rax*8]
	lea	rax, nameList[rip]
	mov	rax, QWORD PTR [rcx+rax]
	mov	rsi, rdx
	mov	rdi, rax
	call	coloramaprintifarmafillup
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	chngg_wrapper, .-chngg_wrapper
	.type	get_type_ind_by_name, @function
get_type_ind_by_name:
.LFB12:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -4[rbp], 1
	jmp	.L89
.L92:
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	sal	rax, 5
	mov	rdx, rax
	lea	rax, types[rip+8]
	mov	rax, QWORD PTR [rdx+rax]
	mov	rdx, QWORD PTR -24[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	strcmp@PLT
	test	eax, eax
	jne	.L90
	mov	eax, DWORD PTR -4[rbp]
	jmp	.L91
.L90:
	add	DWORD PTR -4[rbp], 1
.L89:
	cmp	DWORD PTR -4[rbp], 10
	jle	.L92
	mov	eax, 268414975
.L91:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	get_type_ind_by_name, .-get_type_ind_by_name
	.type	add_type_value, @function
add_type_value:
.LFB13:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -20[rbp], edi
	mov	QWORD PTR -32[rbp], rsi
	mov	rax, QWORD PTR -32[rbp]
	mov	QWORD PTR -8[rbp], rax
	mov	eax, DWORD PTR -20[rbp]
	cdqe
	sal	rax, 5
	mov	rdx, rax
	lea	rax, types[rip+16]
	mov	rdx, QWORD PTR [rdx+rax]
	mov	rax, QWORD PTR -8[rbp]
	lea	rcx, [rdx+rax]
	mov	eax, DWORD PTR -20[rbp]
	cdqe
	sal	rax, 5
	mov	rdx, rax
	lea	rax, types[rip+16]
	mov	QWORD PTR [rdx+rax], rcx
	mov	eax, 0
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	add_type_value, .-add_type_value
	.type	get_type, @function
get_type:
.LFB14:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 64
	mov	QWORD PTR -40[rbp], rdi
	mov	DWORD PTR -44[rbp], esi
	mov	QWORD PTR -56[rbp], rdx
	mov	DWORD PTR -8[rbp], 0
	mov	eax, DWORD PTR -44[rbp]
	sub	eax, 1
	mov	DWORD PTR -4[rbp], eax
	jmp	.L96
.L100:
	mov	eax, DWORD PTR -4[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -40[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	cmp	al, 46
	jne	.L97
	mov	DWORD PTR -8[rbp], 1
	jmp	.L98
.L97:
	mov	eax, DWORD PTR -4[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -40[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	cmp	al, 47
	jne	.L99
	mov	DWORD PTR -8[rbp], 0
	jmp	.L98
.L99:
	sub	DWORD PTR -4[rbp], 1
.L96:
	cmp	DWORD PTR -4[rbp], 0
	jns	.L100
.L98:
	cmp	DWORD PTR -8[rbp], 0
	je	.L108
	mov	eax, DWORD PTR -44[rbp]
	sub	eax, DWORD PTR -4[rbp]
	sub	eax, 1
	mov	DWORD PTR -16[rbp], eax
	cmp	DWORD PTR -16[rbp], 0
	jle	.L109
	mov	eax, DWORD PTR -16[rbp]
	add	eax, 1
	cdqe
	mov	rdi, rax
	call	malloc@PLT
	mov	QWORD PTR -24[rbp], rax
	cmp	QWORD PTR -24[rbp], 0
	je	.L110
	mov	DWORD PTR -12[rbp], 0
	jmp	.L105
.L106:
	mov	eax, DWORD PTR -4[rbp]
	lea	edx, 1[rax]
	mov	eax, DWORD PTR -12[rbp]
	add	eax, edx
	movsx	rdx, eax
	mov	rax, QWORD PTR -40[rbp]
	add	rax, rdx
	mov	edx, DWORD PTR -12[rbp]
	movsx	rcx, edx
	mov	rdx, QWORD PTR -24[rbp]
	add	rdx, rcx
	movzx	eax, BYTE PTR [rax]
	mov	BYTE PTR [rdx], al
	add	DWORD PTR -12[rbp], 1
.L105:
	mov	eax, DWORD PTR -12[rbp]
	cmp	eax, DWORD PTR -16[rbp]
	jl	.L106
	mov	eax, DWORD PTR -16[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	mov	BYTE PTR [rax], 0
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	get_type_ind_by_name
	mov	DWORD PTR -28[rbp], eax
	cmp	DWORD PTR -28[rbp], 268414975
	je	.L107
	mov	eax, DWORD PTR -28[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	edi, eax
	call	add_type_value
.L107:
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	free@PLT
	jmp	.L95
.L108:
	nop
	jmp	.L95
.L109:
	nop
	jmp	.L95
.L110:
	nop
.L95:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	get_type, .-get_type
	.section	.rodata
.LC34:
	.string	"opendir"
.LC35:
	.string	"."
.LC36:
	.string	".."
.LC37:
	.string	"%s/%s"
.LC38:
	.string	"lstat"
	.text
	.type	folder_size, @function
folder_size:
.LFB15:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 4296
	.cfi_offset 3, -24
	mov	QWORD PTR -4296[rbp], rdi
	mov	rax, QWORD PTR -4296[rbp]
	mov	rdi, rax
	call	opendir@PLT
	mov	QWORD PTR -32[rbp], rax
	cmp	QWORD PTR -32[rbp], 0
	jne	.L112
	lea	rax, .LC34[rip]
	mov	rdi, rax
	call	perror@PLT
	mov	eax, 0
	jmp	.L113
.L112:
	mov	QWORD PTR -24[rbp], 0
	jmp	.L114
.L122:
	mov	rax, QWORD PTR -40[rbp]
	add	rax, 19
	lea	rdx, .LC35[rip]
	mov	rsi, rdx
	mov	rdi, rax
	call	strcmp@PLT
	test	eax, eax
	je	.L123
	mov	rax, QWORD PTR -40[rbp]
	add	rax, 19
	lea	rdx, .LC36[rip]
	mov	rsi, rdx
	mov	rdi, rax
	call	strcmp@PLT
	test	eax, eax
	je	.L123
	mov	rax, QWORD PTR -40[rbp]
	lea	rcx, 19[rax]
	mov	rdx, QWORD PTR -4296[rbp]
	lea	rax, -4144[rbp]
	mov	r8, rcx
	mov	rcx, rdx
	lea	rdx, .LC37[rip]
	mov	esi, 4096
	mov	rdi, rax
	mov	eax, 0
	call	snprintf@PLT
	cmp	eax, 4095
	jg	.L124
	lea	rdx, -4288[rbp]
	lea	rax, -4144[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	lstat@PLT
	cmp	eax, -1
	jne	.L119
	lea	rax, .LC38[rip]
	mov	rdi, rax
	call	perror@PLT
	jmp	.L114
.L119:
	mov	eax, DWORD PTR -4264[rbp]
	and	eax, 61440
	cmp	eax, 16384
	jne	.L120
	lea	rax, -4144[rbp]
	mov	rdi, rax
	call	folder_size
	add	QWORD PTR -24[rbp], rax
	jmp	.L114
.L120:
	mov	rax, QWORD PTR -4240[rbp]
	add	QWORD PTR -24[rbp], rax
	mov	rax, QWORD PTR -4240[rbp]
	mov	rbx, rax
	lea	rax, -4144[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	ecx, eax
	lea	rax, -4144[rbp]
	mov	rdx, rbx
	mov	esi, ecx
	mov	rdi, rax
	call	get_type
	jmp	.L114
.L123:
	nop
	jmp	.L114
.L124:
	nop
.L114:
	mov	rax, QWORD PTR -32[rbp]
	mov	rdi, rax
	call	readdir@PLT
	mov	QWORD PTR -40[rbp], rax
	cmp	QWORD PTR -40[rbp], 0
	jne	.L122
	mov	rax, QWORD PTR -32[rbp]
	mov	rdi, rax
	call	closedir@PLT
	mov	rax, QWORD PTR -24[rbp]
.L113:
	mov	rbx, QWORD PTR -8[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	folder_size, .-folder_size
	.type	getDomLangIndex, @function
getDomLangIndex:
.LFB16:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 24
	mov	QWORD PTR -136[rbp], rdi
	mov	QWORD PTR -144[rbp], rsi
	lea	rdx, -128[rbp]
	mov	eax, 0
	mov	ecx, 11
	mov	rdi, rdx
	rep stosq
	mov	DWORD PTR -4[rbp], 1
	jmp	.L126
.L128:
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	sal	rax, 5
	mov	rdx, rax
	lea	rax, types[rip+24]
	mov	eax, DWORD PTR [rdx+rax]
	mov	DWORD PTR -28[rbp], eax
	cmp	DWORD PTR -28[rbp], 0
	js	.L127
	cmp	DWORD PTR -28[rbp], 10
	jg	.L127
	mov	eax, DWORD PTR -28[rbp]
	cdqe
	mov	rdx, QWORD PTR -128[rbp+rax*8]
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	sal	rax, 5
	mov	rcx, rax
	lea	rax, types[rip+16]
	mov	rax, QWORD PTR [rcx+rax]
	add	rdx, rax
	mov	eax, DWORD PTR -28[rbp]
	cdqe
	mov	QWORD PTR -128[rbp+rax*8], rdx
.L127:
	add	DWORD PTR -4[rbp], 1
.L126:
	cmp	DWORD PTR -4[rbp], 10
	jle	.L128
	mov	DWORD PTR -8[rbp], 0
	mov	QWORD PTR -16[rbp], 0
	mov	DWORD PTR -20[rbp], 0
	jmp	.L129
.L131:
	mov	eax, DWORD PTR -20[rbp]
	cdqe
	mov	rax, QWORD PTR -128[rbp+rax*8]
	cmp	QWORD PTR -16[rbp], rax
	jnb	.L130
	mov	eax, DWORD PTR -20[rbp]
	cdqe
	mov	rax, QWORD PTR -128[rbp+rax*8]
	mov	QWORD PTR -16[rbp], rax
	mov	eax, DWORD PTR -20[rbp]
	mov	DWORD PTR -8[rbp], eax
.L130:
	add	DWORD PTR -20[rbp], 1
.L129:
	cmp	DWORD PTR -20[rbp], 10
	jle	.L131
	mov	rax, QWORD PTR -136[rbp]
	mov	edx, DWORD PTR -8[rbp]
	mov	DWORD PTR [rax], edx
	mov	rax, QWORD PTR -144[rbp]
	mov	rdx, QWORD PTR -16[rbp]
	mov	QWORD PTR [rax], rdx
	mov	DWORD PTR -24[rbp], 0
	jmp	.L132
.L133:
	mov	eax, DWORD PTR -24[rbp]
	cdqe
	sal	rax, 5
	mov	rdx, rax
	lea	rax, types[rip+16]
	mov	QWORD PTR [rdx+rax], 0
	add	DWORD PTR -24[rbp], 1
.L132:
	cmp	DWORD PTR -24[rbp], 10
	jle	.L133
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	getDomLangIndex, .-getDomLangIndex
	.section	.rodata
.LC39:
	.string	"ERROR: getcwd"
	.text
	.globl	getAbsolutPath
	.type	getAbsolutPath, @function
getAbsolutPath:
.LFB17:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 4400
	mov	QWORD PTR -4392[rbp], rdi
	mov	DWORD PTR -4396[rbp], esi
	lea	rax, -4384[rbp]
	mov	esi, 4352
	mov	rdi, rax
	call	getcwd@PLT
	test	rax, rax
	je	.L135
	lea	rax, -4384[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	DWORD PTR -12[rbp], eax
	mov	edx, DWORD PTR -12[rbp]
	mov	eax, DWORD PTR -4396[rbp]
	add	eax, edx
	add	eax, 2
	mov	DWORD PTR -16[rbp], eax
	mov	eax, DWORD PTR -16[rbp]
	add	eax, 1
	cdqe
	mov	rdi, rax
	call	malloc@PLT
	mov	QWORD PTR -24[rbp], rax
	mov	eax, DWORD PTR -16[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	mov	BYTE PTR [rax], 0
	mov	DWORD PTR -4[rbp], 0
	mov	DWORD PTR -8[rbp], 0
	jmp	.L136
.L140:
	mov	eax, DWORD PTR -8[rbp]
	cmp	eax, DWORD PTR -12[rbp]
	jge	.L137
	mov	eax, DWORD PTR -8[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -24[rbp]
	add	rdx, rax
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	movzx	eax, BYTE PTR -4384[rbp+rax]
	mov	BYTE PTR [rdx], al
	add	DWORD PTR -4[rbp], 1
.L137:
	mov	eax, DWORD PTR -8[rbp]
	cmp	eax, DWORD PTR -12[rbp]
	jle	.L138
	mov	eax, DWORD PTR -4[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -4392[rbp]
	add	rax, rdx
	mov	edx, DWORD PTR -8[rbp]
	movsx	rcx, edx
	mov	rdx, QWORD PTR -24[rbp]
	add	rdx, rcx
	movzx	eax, BYTE PTR [rax]
	mov	BYTE PTR [rdx], al
	add	DWORD PTR -4[rbp], 1
.L138:
	mov	eax, DWORD PTR -8[rbp]
	cmp	eax, DWORD PTR -12[rbp]
	jne	.L139
	mov	eax, DWORD PTR -8[rbp]
	movsx	rdx, eax
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	mov	BYTE PTR [rax], 47
	mov	DWORD PTR -4[rbp], 0
.L139:
	add	DWORD PTR -8[rbp], 1
.L136:
	mov	eax, DWORD PTR -8[rbp]
	cmp	eax, DWORD PTR -16[rbp]
	jl	.L140
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	puts@PLT
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	clipper
	mov	rax, QWORD PTR -24[rbp]
	mov	rdi, rax
	call	free@PLT
	jmp	.L142
.L135:
	lea	rax, .LC39[rip]
	mov	rdi, rax
	call	perror@PLT
.L142:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	getAbsolutPath, .-getAbsolutPath
	.section	.rodata
.LC40:
	.string	"malloc unixTimestamps"
.LC41:
	.string	"malloc copy"
.LC42:
	.string	"malloc new unixTimestamps"
	.text
	.globl	addUnixTimestamp
	.type	addUnixTimestamp, @function
addUnixTimestamp:
.LFB18:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	mov	QWORD PTR -32[rbp], rsi
	mov	rax, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR [rax]
	test	rax, rax
	jne	.L144
	mov	eax, DWORD PTR unix_max[rip]
	cdqe
	sal	rax, 3
	mov	rdi, rax
	call	malloc@PLT
	mov	rdx, rax
	mov	rax, QWORD PTR -32[rbp]
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR [rax]
	test	rax, rax
	jne	.L144
	lea	rax, .LC40[rip]
	mov	rdi, rax
	call	perror@PLT
	jmp	.L143
.L144:
	mov	rax, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR [rax]
	mov	edx, DWORD PTR unix_index[rip]
	movsx	rdx, edx
	sal	rdx, 3
	add	rdx, rax
	mov	rax, QWORD PTR -24[rbp]
	mov	QWORD PTR [rdx], rax
	mov	eax, DWORD PTR unix_index[rip]
	add	eax, 1
	mov	DWORD PTR unix_index[rip], eax
	mov	edx, DWORD PTR unix_index[rip]
	mov	eax, DWORD PTR unix_max[rip]
	cmp	edx, eax
	jne	.L143
	mov	eax, DWORD PTR unix_max[rip]
	cdqe
	sal	rax, 3
	mov	rdi, rax
	call	malloc@PLT
	mov	QWORD PTR -16[rbp], rax
	cmp	QWORD PTR -16[rbp], 0
	jne	.L146
	lea	rax, .LC41[rip]
	mov	rdi, rax
	call	perror@PLT
	jmp	.L143
.L146:
	mov	DWORD PTR -4[rbp], 0
	jmp	.L147
.L148:
	mov	rax, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR [rax]
	mov	edx, DWORD PTR -4[rbp]
	movsx	rdx, edx
	sal	rdx, 3
	add	rax, rdx
	mov	edx, DWORD PTR -4[rbp]
	movsx	rdx, edx
	lea	rcx, 0[0+rdx*8]
	mov	rdx, QWORD PTR -16[rbp]
	add	rdx, rcx
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR [rdx], rax
	add	DWORD PTR -4[rbp], 1
.L147:
	mov	eax, DWORD PTR unix_max[rip]
	cmp	DWORD PTR -4[rbp], eax
	jl	.L148
	mov	rax, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR [rax]
	mov	rdi, rax
	call	free@PLT
	mov	eax, DWORD PTR unix_max[rip]
	add	eax, eax
	mov	DWORD PTR unix_max[rip], eax
	mov	eax, DWORD PTR unix_max[rip]
	cdqe
	sal	rax, 3
	mov	rdi, rax
	call	malloc@PLT
	mov	rdx, rax
	mov	rax, QWORD PTR -32[rbp]
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR [rax]
	test	rax, rax
	jne	.L149
	lea	rax, .LC42[rip]
	mov	rdi, rax
	call	perror@PLT
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	free@PLT
	jmp	.L143
.L149:
	mov	DWORD PTR -8[rbp], 0
	jmp	.L150
.L151:
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -16[rbp]
	lea	rcx, [rdx+rax]
	mov	rax, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR [rax]
	mov	edx, DWORD PTR -8[rbp]
	movsx	rdx, edx
	sal	rdx, 3
	add	rdx, rax
	mov	rax, QWORD PTR [rcx]
	mov	QWORD PTR [rdx], rax
	add	DWORD PTR -8[rbp], 1
.L150:
	mov	eax, DWORD PTR unix_max[rip]
	mov	edx, eax
	shr	edx, 31
	add	eax, edx
	sar	eax
	cmp	DWORD PTR -8[rbp], eax
	jl	.L151
	mov	rax, QWORD PTR -16[rbp]
	mov	rdi, rax
	call	free@PLT
.L143:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	addUnixTimestamp, .-addUnixTimestamp
	.globl	swap
	.type	swap, @function
swap:
.LFB19:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -24[rbp], rdi
	mov	QWORD PTR -32[rbp], rsi
	mov	rax, QWORD PTR -24[rbp]
	mov	rdx, QWORD PTR 8[rax]
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR -16[rbp], rax
	mov	QWORD PTR -8[rbp], rdx
	mov	rcx, QWORD PTR -24[rbp]
	mov	rax, QWORD PTR -32[rbp]
	mov	rdx, QWORD PTR 8[rax]
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rcx, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR -16[rbp]
	mov	rdx, QWORD PTR -8[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE19:
	.size	swap, .-swap
	.globl	reverseArray
	.type	reverseArray, @function
reverseArray:
.LFB20:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	mov	DWORD PTR -28[rbp], esi
	mov	DWORD PTR -4[rbp], 0
	mov	eax, DWORD PTR -28[rbp]
	sub	eax, 1
	mov	DWORD PTR -8[rbp], eax
	jmp	.L154
.L155:
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	sal	rax, 4
	mov	rdx, rax
	mov	rax, QWORD PTR -24[rbp]
	add	rdx, rax
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	sal	rax, 4
	mov	rcx, rax
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rcx
	mov	rsi, rdx
	mov	rdi, rax
	call	swap
	add	DWORD PTR -4[rbp], 1
	sub	DWORD PTR -8[rbp], 1
.L154:
	mov	eax, DWORD PTR -4[rbp]
	cmp	eax, DWORD PTR -8[rbp]
	jl	.L155
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE20:
	.size	reverseArray, .-reverseArray
	.section	.rodata
.LC43:
	.string	"malloc TTAS array"
	.text
	.globl	sortByTimestamp
	.type	sortByTimestamp, @function
sortByTimestamp:
.LFB21:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 80
	mov	QWORD PTR -56[rbp], rdi
	mov	QWORD PTR -64[rbp], rsi
	mov	DWORD PTR -68[rbp], edx
	cmp	QWORD PTR -56[rbp], 0
	je	.L171
	cmp	QWORD PTR -64[rbp], 0
	je	.L171
	cmp	DWORD PTR -68[rbp], 1
	jle	.L171
	mov	DWORD PTR -4[rbp], 0
	jmp	.L160
.L165:
	mov	eax, DWORD PTR -4[rbp]
	mov	DWORD PTR -8[rbp], eax
	mov	eax, DWORD PTR -4[rbp]
	add	eax, 1
	mov	DWORD PTR -12[rbp], eax
	jmp	.L161
.L163:
	mov	eax, DWORD PTR -12[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	add	rax, rdx
	mov	rdx, QWORD PTR [rax]
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rcx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	add	rax, rcx
	mov	rax, QWORD PTR [rax]
	cmp	rdx, rax
	jle	.L162
	mov	eax, DWORD PTR -12[rbp]
	mov	DWORD PTR -8[rbp], eax
.L162:
	add	DWORD PTR -12[rbp], 1
.L161:
	mov	eax, DWORD PTR -12[rbp]
	cmp	eax, DWORD PTR -68[rbp]
	jl	.L163
	mov	eax, DWORD PTR -8[rbp]
	cmp	eax, DWORD PTR -4[rbp]
	je	.L164
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	add	rax, rdx
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR -40[rbp], rax
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	add	rax, rdx
	mov	edx, DWORD PTR -4[rbp]
	movsx	rdx, edx
	lea	rcx, 0[0+rdx*8]
	mov	rdx, QWORD PTR -56[rbp]
	add	rdx, rcx
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR [rdx], rax
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	add	rdx, rax
	mov	rax, QWORD PTR -40[rbp]
	mov	QWORD PTR [rdx], rax
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -64[rbp]
	add	rax, rdx
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR -48[rbp], rax
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -64[rbp]
	add	rax, rdx
	mov	edx, DWORD PTR -4[rbp]
	movsx	rdx, edx
	lea	rcx, 0[0+rdx*8]
	mov	rdx, QWORD PTR -64[rbp]
	add	rdx, rcx
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR [rdx], rax
	mov	eax, DWORD PTR -8[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -64[rbp]
	add	rdx, rax
	mov	rax, QWORD PTR -48[rbp]
	mov	QWORD PTR [rdx], rax
.L164:
	add	DWORD PTR -4[rbp], 1
.L160:
	mov	eax, DWORD PTR -68[rbp]
	sub	eax, 1
	cmp	DWORD PTR -4[rbp], eax
	jl	.L165
	mov	eax, DWORD PTR -68[rbp]
	cdqe
	sal	rax, 4
	mov	rdi, rax
	call	malloc@PLT
	mov	QWORD PTR -32[rbp], rax
	cmp	QWORD PTR -32[rbp], 0
	jne	.L166
	lea	rax, .LC43[rip]
	mov	rdi, rax
	call	perror@PLT
	jmp	.L156
.L166:
	mov	DWORD PTR -16[rbp], 0
	jmp	.L167
.L168:
	mov	eax, DWORD PTR -16[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	add	rax, rdx
	mov	edx, DWORD PTR -16[rbp]
	movsx	rdx, edx
	mov	rcx, rdx
	sal	rcx, 4
	mov	rdx, QWORD PTR -32[rbp]
	add	rdx, rcx
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR [rdx], rax
	mov	eax, DWORD PTR -16[rbp]
	cdqe
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -64[rbp]
	add	rax, rdx
	mov	edx, DWORD PTR -16[rbp]
	movsx	rdx, edx
	mov	rcx, rdx
	sal	rcx, 4
	mov	rdx, QWORD PTR -32[rbp]
	add	rdx, rcx
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR 8[rdx], rax
	add	DWORD PTR -16[rbp], 1
.L167:
	mov	eax, DWORD PTR -16[rbp]
	cmp	eax, DWORD PTR -68[rbp]
	jl	.L168
	mov	edx, DWORD PTR -68[rbp]
	mov	rax, QWORD PTR -32[rbp]
	mov	esi, edx
	mov	rdi, rax
	call	reverseArray
	mov	DWORD PTR -20[rbp], 0
	jmp	.L169
.L170:
	mov	eax, DWORD PTR -20[rbp]
	cdqe
	sal	rax, 4
	mov	rdx, rax
	mov	rax, QWORD PTR -32[rbp]
	add	rax, rdx
	mov	edx, DWORD PTR -20[rbp]
	movsx	rdx, edx
	lea	rcx, 0[0+rdx*8]
	mov	rdx, QWORD PTR -56[rbp]
	add	rdx, rcx
	mov	rax, QWORD PTR [rax]
	mov	QWORD PTR [rdx], rax
	mov	eax, DWORD PTR -20[rbp]
	cdqe
	sal	rax, 4
	mov	rdx, rax
	mov	rax, QWORD PTR -32[rbp]
	add	rax, rdx
	mov	edx, DWORD PTR -20[rbp]
	movsx	rdx, edx
	lea	rcx, 0[0+rdx*8]
	mov	rdx, QWORD PTR -64[rbp]
	add	rdx, rcx
	mov	rax, QWORD PTR 8[rax]
	mov	QWORD PTR [rdx], rax
	add	DWORD PTR -20[rbp], 1
.L169:
	mov	eax, DWORD PTR -20[rbp]
	cmp	eax, DWORD PTR -68[rbp]
	jl	.L170
	mov	rax, QWORD PTR -32[rbp]
	mov	rdi, rax
	call	free@PLT
	jmp	.L156
.L171:
	nop
.L156:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE21:
	.size	sortByTimestamp, .-sortByTimestamp
	.section	.rodata
.LC44:
	.string	"./%s"
.LC45:
	.string	"unknown"
.LC46:
	.string	"%e. %b %H:%M"
.LC47:
	.string	"%s %2lu %s %s %8s %s %s -> %s"
.LC48:
	.string	"%s %2lu %s %s %8s %s %s"
.LC49:
	.string	"%s %2lu %s %s %8s %s %s %s"
.LC50:
	.string	"realloc rows"
.LC51:
	.string	"strdup"
	.text
	.globl	main_lll
	.type	main_lll, @function
main_lll:
.LFB22:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	sub	rsp, 13032
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	lea	rax, .LC35[rip]
	mov	rdi, rax
	call	opendir@PLT
	mov	QWORD PTR -88[rbp], rax
	cmp	QWORD PTR -88[rbp], 0
	jne	.L173
	lea	rax, .LC34[rip]
	mov	rdi, rax
	call	perror@PLT
	mov	eax, 1
	jmp	.L205
.L173:
	mov	QWORD PTR -56[rbp], 0
	mov	QWORD PTR -192[rbp], 0
	mov	QWORD PTR -64[rbp], 0
	mov	QWORD PTR -72[rbp], 0
	jmp	.L175
.L202:
	mov	rax, QWORD PTR -96[rbp]
	add	rax, 19
	lea	rdx, .LC35[rip]
	mov	rsi, rdx
	mov	rdi, rax
	call	strcmp@PLT
	test	eax, eax
	je	.L206
	mov	rax, QWORD PTR -96[rbp]
	add	rax, 19
	lea	rdx, .LC36[rip]
	mov	rsi, rdx
	mov	rdi, rax
	call	strcmp@PLT
	test	eax, eax
	je	.L206
	mov	rax, QWORD PTR -96[rbp]
	lea	rdx, 19[rax]
	lea	rax, -12768[rbp]
	mov	rcx, rdx
	lea	rdx, .LC44[rip]
	mov	esi, 4096
	mov	rdi, rax
	mov	eax, 0
	call	snprintf@PLT
	cmp	eax, 4095
	jg	.L207
	lea	rdx, -12912[rbp]
	lea	rax, -12768[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	lstat@PLT
	cmp	eax, -1
	jne	.L180
	lea	rax, .LC38[rip]
	mov	rdi, rax
	call	perror@PLT
	jmp	.L175
.L180:
	mov	eax, DWORD PTR -12888[rbp]
	lea	rdx, -203[rbp]
	mov	rsi, rdx
	mov	edi, eax
	call	mode_to_str
	mov	rax, QWORD PTR -12896[rbp]
	mov	QWORD PTR -104[rbp], rax
	mov	eax, DWORD PTR -12884[rbp]
	mov	edi, eax
	call	getpwuid@PLT
	mov	QWORD PTR -112[rbp], rax
	mov	eax, DWORD PTR -12880[rbp]
	mov	edi, eax
	call	getgrgid@PLT
	mov	QWORD PTR -120[rbp], rax
	cmp	QWORD PTR -112[rbp], 0
	je	.L181
	mov	rax, QWORD PTR -112[rbp]
	mov	rax, QWORD PTR [rax]
	jmp	.L182
.L181:
	lea	rax, .LC45[rip]
.L182:
	mov	QWORD PTR -128[rbp], rax
	cmp	QWORD PTR -120[rbp], 0
	je	.L183
	mov	rax, QWORD PTR -120[rbp]
	mov	rax, QWORD PTR [rax]
	jmp	.L184
.L183:
	lea	rax, .LC45[rip]
.L184:
	mov	QWORD PTR -136[rbp], rax
	lea	rax, -13040[rbp]
	lea	rdx, -12912[rbp]
	add	rdx, 88
	mov	rsi, rax
	mov	rdi, rdx
	call	localtime_r@PLT
	lea	rdx, -13040[rbp]
	lea	rax, -12976[rbp]
	mov	rcx, rdx
	lea	rdx, .LC46[rip]
	mov	esi, 64
	mov	rdi, rax
	call	strftime@PLT
	mov	rax, QWORD PTR -12824[rbp]
	mov	QWORD PTR -144[rbp], rax
	mov	eax, DWORD PTR -12888[rbp]
	and	eax, 61440
	cmp	eax, 16384
	jne	.L185
	mov	eax, 102
	jmp	.L186
.L185:
	mov	eax, 100
.L186:
	mov	BYTE PTR -145[rbp], al
	mov	eax, DWORD PTR -12888[rbp]
	and	eax, 61440
	cmp	eax, 16384
	jne	.L187
	lea	rax, -12768[rbp]
	mov	rdi, rax
	call	folder_size
	mov	QWORD PTR -160[rbp], rax
	lea	rcx, -13072[rbp]
	mov	rax, QWORD PTR -160[rbp]
	mov	edx, 32
	mov	rsi, rcx
	mov	rdi, rax
	call	process_size
	mov	rbx, QWORD PTR -160[rbp]
	lea	rax, -12768[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	ecx, eax
	lea	rax, -12768[rbp]
	mov	rdx, rbx
	mov	esi, ecx
	mov	rdi, rax
	call	get_type
	jmp	.L188
.L187:
	mov	rax, QWORD PTR -12864[rbp]
	lea	rcx, -13072[rbp]
	mov	edx, 32
	mov	rsi, rcx
	mov	rdi, rax
	call	process_size
	mov	rax, QWORD PTR -12864[rbp]
	mov	rbx, rax
	lea	rax, -12768[rbp]
	mov	rdi, rax
	call	strlen@PLT
	mov	ecx, eax
	lea	rax, -12768[rbp]
	mov	rdx, rbx
	mov	esi, ecx
	mov	rdi, rax
	call	get_type
.L188:
	mov	DWORD PTR -208[rbp], 0
	mov	QWORD PTR -216[rbp], 0
	lea	rdx, -216[rbp]
	lea	rax, -208[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	getDomLangIndex
	mov	eax, DWORD PTR -12888[rbp]
	and	eax, 61440
	cmp	eax, 40960
	jne	.L189
	lea	rcx, -8672[rbp]
	lea	rax, -12768[rbp]
	mov	edx, 4095
	mov	rsi, rcx
	mov	rdi, rax
	call	readlink@PLT
	mov	QWORD PTR -168[rbp], rax
	cmp	QWORD PTR -168[rbp], -1
	je	.L190
	lea	rdx, -8672[rbp]
	mov	rax, QWORD PTR -168[rbp]
	add	rax, rdx
	mov	BYTE PTR [rax], 0
	mov	rax, QWORD PTR -96[rbp]
	lea	rsi, 19[rax]
	mov	r8, QWORD PTR -128[rbp]
	mov	rdi, QWORD PTR -104[rbp]
	lea	rdx, -203[rbp]
	lea	rax, -4576[rbp]
	sub	rsp, 8
	lea	rcx, -8672[rbp]
	push	rcx
	push	rsi
	lea	rcx, -12976[rbp]
	push	rcx
	lea	rcx, -13072[rbp]
	push	rcx
	push	QWORD PTR -136[rbp]
	mov	r9, r8
	mov	r8, rdi
	mov	rcx, rdx
	lea	rdx, .LC47[rip]
	mov	esi, 4352
	mov	rdi, rax
	mov	eax, 0
	call	snprintf@PLT
	add	rsp, 48
	jmp	.L192
.L190:
	mov	rax, QWORD PTR -96[rbp]
	lea	rcx, 19[rax]
	mov	rdi, QWORD PTR -128[rbp]
	mov	rsi, QWORD PTR -104[rbp]
	lea	rdx, -203[rbp]
	lea	rax, -4576[rbp]
	push	rcx
	lea	rcx, -12976[rbp]
	push	rcx
	lea	rcx, -13072[rbp]
	push	rcx
	push	QWORD PTR -136[rbp]
	mov	r9, rdi
	mov	r8, rsi
	mov	rcx, rdx
	lea	rdx, .LC48[rip]
	mov	esi, 4352
	mov	rdi, rax
	mov	eax, 0
	call	snprintf@PLT
	add	rsp, 32
	jmp	.L192
.L189:
	cmp	BYTE PTR -145[rbp], 102
	jne	.L193
	mov	ecx, 10066431
	jmp	.L194
.L193:
	mov	ecx, 16724991
.L194:
	mov	rax, QWORD PTR -96[rbp]
	add	rax, 19
	mov	edx, 1
	mov	rsi, rcx
	mov	rdi, rax
	call	chngg
	mov	r15, rax
	mov	rdx, QWORD PTR -216[rbp]
	mov	eax, DWORD PTR -208[rbp]
	mov	rsi, rdx
	mov	edi, eax
	call	chngg_wrapper
	mov	r14, rax
	lea	rax, -12976[rbp]
	mov	edx, 0
	mov	esi, 8947814
	mov	rdi, rax
	call	chngg
	mov	r13, rax
	lea	rax, -13072[rbp]
	mov	edx, 0
	mov	esi, 16711680
	mov	rdi, rax
	call	chngg
	mov	r12, rax
	mov	rax, QWORD PTR -136[rbp]
	mov	edx, 0
	mov	esi, 8978312
	mov	rdi, rax
	call	chngg
	mov	rbx, rax
	mov	rax, QWORD PTR -128[rbp]
	mov	edx, 0
	mov	esi, 4521796
	mov	rdi, rax
	call	chngg
	mov	rcx, rax
	mov	rsi, QWORD PTR -104[rbp]
	lea	rdx, -203[rbp]
	lea	rax, -4576[rbp]
	sub	rsp, 8
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	mov	r9, rcx
	mov	r8, rsi
	mov	rcx, rdx
	lea	rdx, .LC49[rip]
	mov	esi, 4352
	mov	rdi, rax
	mov	eax, 0
	call	snprintf@PLT
	add	rsp, 48
.L192:
	mov	rax, QWORD PTR -64[rbp]
	add	rax, 1
	cmp	QWORD PTR -72[rbp], rax
	jnb	.L195
	cmp	QWORD PTR -72[rbp], 0
	je	.L196
	mov	rax, QWORD PTR -72[rbp]
	add	rax, rax
	jmp	.L197
.L196:
	mov	eax, 64
.L197:
	mov	QWORD PTR -176[rbp], rax
	mov	rax, QWORD PTR -176[rbp]
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	realloc@PLT
	mov	QWORD PTR -184[rbp], rax
	cmp	QWORD PTR -184[rbp], 0
	jne	.L198
	lea	rax, .LC50[rip]
	mov	rdi, rax
	call	perror@PLT
	jmp	.L201
.L198:
	mov	rax, QWORD PTR -184[rbp]
	mov	QWORD PTR -56[rbp], rax
	mov	rax, QWORD PTR -176[rbp]
	mov	QWORD PTR -72[rbp], rax
.L195:
	mov	rax, QWORD PTR -64[rbp]
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	lea	rbx, [rdx+rax]
	lea	rax, -4576[rbp]
	mov	rdi, rax
	call	strdup@PLT
	mov	QWORD PTR [rbx], rax
	mov	rax, QWORD PTR -64[rbp]
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	add	rax, rdx
	mov	rax, QWORD PTR [rax]
	test	rax, rax
	jne	.L200
	lea	rax, .LC51[rip]
	mov	rdi, rax
	call	perror@PLT
	jmp	.L201
.L200:
	lea	rdx, -192[rbp]
	mov	rax, QWORD PTR -144[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	addUnixTimestamp
	add	QWORD PTR -64[rbp], 1
	jmp	.L175
.L206:
	nop
	jmp	.L175
.L207:
	nop
.L175:
	mov	rax, QWORD PTR -88[rbp]
	mov	rdi, rax
	call	readdir@PLT
	mov	QWORD PTR -96[rbp], rax
	cmp	QWORD PTR -96[rbp], 0
	jne	.L202
.L201:
	mov	rax, QWORD PTR -88[rbp]
	mov	rdi, rax
	call	closedir@PLT
	mov	rax, QWORD PTR -64[rbp]
	mov	edx, eax
	mov	rax, QWORD PTR -192[rbp]
	mov	rcx, QWORD PTR -56[rbp]
	mov	rsi, rcx
	mov	rdi, rax
	call	sortByTimestamp
	mov	QWORD PTR -80[rbp], 0
	jmp	.L203
.L204:
	mov	rax, QWORD PTR -80[rbp]
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	add	rax, rdx
	mov	rax, QWORD PTR [rax]
	mov	rdi, rax
	call	puts@PLT
	mov	rax, QWORD PTR -80[rbp]
	lea	rdx, 0[0+rax*8]
	mov	rax, QWORD PTR -56[rbp]
	add	rax, rdx
	mov	rax, QWORD PTR [rax]
	mov	rdi, rax
	call	free@PLT
	add	QWORD PTR -80[rbp], 1
.L203:
	mov	rax, QWORD PTR -80[rbp]
	cmp	rax, QWORD PTR -64[rbp]
	jb	.L204
	mov	rax, QWORD PTR -56[rbp]
	mov	rdi, rax
	call	free@PLT
	mov	rax, QWORD PTR -192[rbp]
	mov	rdi, rax
	call	free@PLT
	mov	eax, 0
.L205:
	lea	rsp, -40[rbp]
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE22:
	.size	main_lll, .-main_lll
	.section	.rodata
.LC52:
	.string	"max"
.LC53:
	.string	"MAX PATH LENGTH: %ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR -4[rbp], edi
	mov	QWORD PTR -16[rbp], rsi
	cmp	DWORD PTR -4[rbp], 1
	jne	.L209
	mov	eax, 0
	call	main_lll
	mov	eax, 0
	call	memlist_free_all
.L209:
	cmp	DWORD PTR -4[rbp], 2
	jne	.L210
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 8
	mov	rax, QWORD PTR [rax]
	mov	edx, 3
	lea	rcx, .LC52[rip]
	mov	rsi, rcx
	mov	rdi, rax
	call	memcmp@PLT
	test	eax, eax
	jne	.L211
	mov	esi, 4352
	lea	rax, .LC53[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	mov	eax, 0
	jmp	.L212
.L211:
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 8
	mov	rax, QWORD PTR [rax]
	mov	rdi, rax
	call	strlen@PLT
	mov	edx, eax
	mov	rax, QWORD PTR -16[rbp]
	add	rax, 8
	mov	rax, QWORD PTR [rax]
	mov	esi, edx
	mov	rdi, rax
	call	getAbsolutPath
.L210:
	mov	eax, 0
.L212:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC29:
	.long	0
	.long	1083179008
	.ident	"GCC: (GNU) 14.3.0"
	.section	.note.GNU-stack,"",@progbits
