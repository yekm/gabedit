	.file	"ColorMap.c"
	.text
	.p2align 4,,15
.globl _colormap_free
	.def	_colormap_free;	.scl	2;	.type	32;	.endef
_colormap_free:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$4, %esp
	movl	8(%ebp), %ebx
	testl	%ebx, %ebx
	je	L1
	movl	4(%ebx), %edx
	testl	%edx, %edx
	je	L6
L4:
	movl	$0, (%ebx)
L1:
	popl	%eax
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L6:
	movl	$0, (%esp)
	call	_g_free
	jmp	L4
	.p2align 4,,15
	.def	_new_colorMap;	.scl	3;	.type	32;	.endef
_new_colorMap:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	$0, -12(%ebp)
	movl	-12(%ebp), %ecx
	movl	%eax, %ebx
	movl	$0, -16(%ebp)
	testl	%ecx, %ecx
	jne	L17
L8:
	movl	$1, -16(%ebp)
	movl	$16, (%esp)
	call	_g_malloc
	movl	%eax, -12(%ebp)
	xorl	%edx, %edx
	movl	%eax, %ecx
	.p2align 4,,15
L14:
	movl	(%ebx,%edx,4), %eax
	movl	%eax, (%ecx,%edx,4)
	incl	%edx
	cmpl	$2, %edx
	jle	L14
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%eax, 12(%ecx)
	movl	-16(%ebp), %eax
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
L17:
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_colormap_free
	jmp	L8
	.p2align 4,,15
	.def	_add_to_colorMap;	.scl	3;	.type	32;	.endef
_add_to_colorMap:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$28, %esp
	movl	%eax, -16(%ebp)
	movl	(%eax), %eax
	movl	%edx, -20(%ebp)
	sall	$4, %eax
	addl	$16, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, %ebx
	movl	-16(%ebp), %eax
	movl	(%eax), %edi
	cmpl	$0, %edi
	jle	L31
	movl	4(%eax), %ecx
	.p2align 4,,15
L22:
	movl	%esi, %eax
	sall	$4, %eax
	incl	%esi
	movl	(%eax,%ecx), %edx
	cmpl	%esi, %edi
	movl	%edx, (%eax,%ebx)
	movl	4(%eax,%ecx), %edx
	movl	%edx, 4(%eax,%ebx)
	movl	8(%eax,%ecx), %edx
	movl	%edx, 8(%eax,%ebx)
	movl	12(%eax,%ecx), %edx
	movl	%edx, 12(%eax,%ebx)
	jg	L22
L28:
	sall	$4, %edi
	xorl	%esi, %esi
	movl	%edi, %edx
	movl	%edi, -24(%ebp)
	addl	%ebx, %edx
L26:
	movl	-20(%ebp), %edi
	movl	(%edi,%esi,4), %eax
	incl	%esi
	movl	%eax, (%edx)
	addl	$4, %edx
	cmpl	$2, %esi
	jle	L26
	movl	%ecx, (%esp)
	movl	8(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%eax, 12(%edx,%ebx)
	call	_g_free
	movl	-16(%ebp), %edi
	incl	(%edi)
	movl	%ebx, 4(%edi)
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L31:
	movl	-16(%ebp), %edx
	movl	4(%edx), %ecx
	jmp	L28
	.p2align 4,,15
	.def	_sort_colorMap;	.scl	3;	.type	32;	.endef
_sort_colorMap:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	movl	(%eax), %edi
	movl	%eax, -44(%ebp)
	movl	$0, -48(%ebp)
	leal	-1(%edi), %eax
	cmpl	$0, %eax
	jle	L45
	.p2align 4,,15
L51:
	movl	-48(%ebp), %esi
	movl	%esi, %eax
	incl	%eax
	movl	%eax, -52(%ebp)
	cmpl	%eax, %edi
	movl	%eax, %ecx
	jle	L47
	movl	-44(%ebp), %eax
	movl	4(%eax), %ebx
	.p2align 4,,15
L41:
	movl	%esi, %eax
	movl	%ecx, %edx
	sall	$4, %eax
	flds	12(%eax,%ebx)
	sall	$4, %edx
	flds	12(%edx,%ebx)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L38
	movl	%ecx, %esi
L38:
	incl	%ecx
	cmpl	%ecx, %edi
	jg	L41
L47:
	cmpl	-48(%ebp), %esi
	je	L35
	movl	-44(%ebp), %eax
	movl	%esi, %edx
	movl	-48(%ebp), %ecx
	sall	$4, %edx
	movl	4(%eax), %ebx
	sall	$4, %ecx
	movl	(%ecx,%ebx), %eax
	movl	%eax, -40(%ebp)
	movl	4(%ecx,%ebx), %eax
	movl	%eax, -36(%ebp)
	movl	8(%ecx,%ebx), %eax
	movl	%eax, -32(%ebp)
	movl	12(%ecx,%ebx), %eax
	movl	%eax, -28(%ebp)
	movl	(%edx,%ebx), %eax
	movl	%eax, (%ecx,%ebx)
	movl	4(%edx,%ebx), %eax
	movl	%eax, 4(%ecx,%ebx)
	movl	8(%edx,%ebx), %eax
	movl	%eax, 8(%ecx,%ebx)
	movl	12(%edx,%ebx), %eax
	movl	%eax, 12(%ecx,%ebx)
	movl	-40(%ebp), %eax
	movl	%eax, (%edx,%ebx)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%edx,%ebx)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%edx,%ebx)
	movl	-28(%ebp), %eax
	movl	%eax, 12(%edx,%ebx)
L35:
	movl	-52(%ebp), %eax
	movl	%eax, -48(%ebp)
	leal	-1(%edi), %eax
	cmpl	-48(%ebp), %eax
	jg	L51
L45:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
	.align 4
LC3:
	.long	1117782016
	.align 8
LC5:
	.long	-1717986918
	.long	1068079513
	.text
	.p2align 4,,15
.globl _new_colorMap_min_max
	.def	_new_colorMap_min_max;	.scl	2;	.type	32;	.endef
_new_colorMap_min_max:
	pushl	%ebp
	movl	$0x3f800000, %eax
	movl	%esp, %ebp
	pushl	%edi
	movl	$1, %edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	movl	%eax, -40(%ebp)
	movl	$0x00000000, %eax
	flds	8(%ebp)
	xorl	%ebx, %ebx
	fsubrs	12(%ebp)
	movl	%eax, -36(%ebp)
	movl	%eax, -32(%ebp)
	fdivs	LC3
	movl	$8, (%esp)
	fstps	-48(%ebp)
	call	_g_malloc
	flds	8(%ebp)
	movl	%eax, -52(%ebp)
	leal	-40(%ebp), %eax
	fstps	(%esp)
	call	_new_colorMap
	movl	-52(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
L64:
	movl	$19, %esi
	.p2align 4,,15
L63:
	testl	%ebx, %ebx
	jne	L59
	flds	-36(%ebp)
	faddl	LC5
L69:
	fstps	-36(%ebp)
L62:
	pushl	%edi
	movl	-52(%ebp), %eax
	leal	-40(%ebp), %edx
	fildl	(%esp)
	addl	$4, %esp
	incl	%edi
	fmuls	-48(%ebp)
	fadds	8(%ebp)
	fstps	(%esp)
	call	_add_to_colorMap
	decl	%esi
	jns	L63
	incl	%ebx
	cmpl	$4, %ebx
	jl	L64
	movl	-52(%ebp), %eax
	call	_sort_colorMap
	movl	-52(%ebp), %eax
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L59:
	cmpl	$1, %ebx
	je	L70
	cmpl	$2, %ebx
	je	L71
	cmpl	$3, %ebx
	jne	L62
	flds	-36(%ebp)
	fsubl	LC5
	jmp	L69
	.p2align 4,,7
L70:
	flds	-40(%ebp)
	fsubl	LC5
	fstps	-40(%ebp)
	jmp	L62
	.p2align 4,,7
L71:
	flds	-32(%ebp)
	faddl	LC5
	fstps	-32(%ebp)
	jmp	L62
	.section .rdata,"dr"
	.align 4
LC10:
	.long	1117782016
	.align 8
LC11:
	.long	-1717986918
	.long	1068079513
	.text
	.p2align 4,,15
.globl _new_colorMap_fromGrid
	.def	_new_colorMap_fromGrid;	.scl	2;	.type	32;	.endef
_new_colorMap_fromGrid:
	pushl	%ebp
	fldz
	movl	%esp, %ebp
	pushl	%edi
	xorl	%eax, %eax
	fld	%st(0)
	pushl	%esi
	movl	$1, %edx
	pushl	%ebx
	subl	$92, %esp
	movl	8(%ebp), %ebx
	fstps	-48(%ebp)
	testl	%ebx, %ebx
	je	L118
	movl	8(%ebp), %eax
	xorl	%edi, %edi
	movl	(%eax), %eax
	movl	%eax, -60(%ebp)
	cmpl	$0, %eax
	jle	L105
	movl	8(%ebp), %ecx
	movl	4(%ecx), %ecx
	movl	%ecx, -64(%ebp)
L91:
	xorl	%esi, %esi
	cmpl	$0, -64(%ebp)
	jle	L107
	movl	8(%ebp), %ebx
	movl	8(%ebx), %ecx
	.p2align 4,,15
L90:
	cmpl	$0, %ecx
	jle	L109
	movl	8(%ebp), %ebx
	movl	12(%ebx), %eax
	movl	%ecx, %ebx
	movl	(%eax,%edi,4), %eax
	movl	(%eax,%esi,4), %eax
	addl	$16, %eax
	movl	%eax, -76(%ebp)
	jmp	L89
	.p2align 4,,7
L120:
	fstp	%st(1)
	fsts	-48(%ebp)
	xorl	%edx, %edx
L82:
	addl	$20, -76(%ebp)
	decl	%ebx
	je	L109
L89:
	movl	-76(%ebp), %eax
	testl	%edx, %edx
	flds	(%eax)
	jne	L120
	flds	-48(%ebp)
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	jbe	L85
	fsts	-48(%ebp)
L85:
	fucom	%st(1)
	fnstsw	%ax
	sahf
	jbe	L119
	fstp	%st(1)
	addl	$20, -76(%ebp)
	decl	%ebx
	jne	L89
	.p2align 4,,15
L109:
	incl	%esi
	cmpl	%esi, -64(%ebp)
	jg	L90
L107:
	incl	%edi
	cmpl	%edi, -60(%ebp)
	jg	L91
L105:
	fsubs	-48(%ebp)
	movl	$0x3f800000, %eax
	movl	$0x00000000, -36(%ebp)
	movl	$1, %ebx
	movl	%eax, -40(%ebp)
	xorl	%esi, %esi
	movl	$0x00000000, -32(%ebp)
	fdivs	LC10
	movl	$8, (%esp)
	fstps	-52(%ebp)
	call	_g_malloc
	flds	-48(%ebp)
	movl	%eax, -56(%ebp)
	leal	-40(%ebp), %eax
	fstps	(%esp)
	call	_new_colorMap
	movl	-56(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
L103:
	movl	$19, %edi
	.p2align 4,,15
L102:
	testl	%esi, %esi
	jne	L98
	flds	-36(%ebp)
	faddl	LC11
L115:
	fstps	-36(%ebp)
L101:
	pushl	%ebx
	movl	-56(%ebp), %eax
	leal	-40(%ebp), %edx
	fildl	(%esp)
	addl	$4, %esp
	incl	%ebx
	fmuls	-52(%ebp)
	fadds	-48(%ebp)
	fstps	(%esp)
	call	_add_to_colorMap
	decl	%edi
	jns	L102
	incl	%esi
	cmpl	$4, %esi
	jl	L103
	movl	-56(%ebp), %eax
	call	_sort_colorMap
	movl	-56(%ebp), %eax
L72:
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L119:
	fstp	%st(0)
	jmp	L82
L98:
	cmpl	$1, %esi
	je	L116
	cmpl	$2, %esi
	je	L117
	cmpl	$3, %esi
	jne	L101
	flds	-36(%ebp)
	fsubl	LC11
	jmp	L115
L116:
	flds	-40(%ebp)
	fsubl	LC11
	fstps	-40(%ebp)
	jmp	L101
L117:
	flds	-32(%ebp)
	faddl	LC11
	fstps	-32(%ebp)
	jmp	L101
L118:
	fstp	%st(0)
	jmp	L72
	.p2align 4,,15
.globl _set_Color_From_colorMap
	.def	_set_Color_From_colorMap;	.scl	2;	.type	32;	.endef
_set_Color_From_colorMap:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	movl	8(%ebp), %eax
	movl	12(%ebp), %edi
	flds	16(%ebp)
	movl	(%eax), %ecx
	testl	%ecx, %ecx
	jle	L158
	movl	4(%eax), %edx
	flds	12(%edx)
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	jbe	L127
	fstp	%st(0)
	xorl	%ecx, %ecx
	.p2align 4,,15
L132:
	movl	(%edx), %eax
	addl	$4, %edx
	movl	%eax, (%edi,%ecx,4)
	incl	%ecx
	cmpl	$2, %ecx
	jle	L132
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L127:
	leal	-1(%ecx), %ebx
	sall	$4, %ebx
	flds	12(%ebx,%edx)
	fxch	%st(1)
	fucom	%st(1)
	fnstsw	%ax
	fstp	%st(1)
	sahf
	ja	L159
	leal	-1(%ecx), %eax
	movl	$1, %ebx
	cmpl	$1, %eax
	jle	L160
	movl	%eax, %ecx
	.p2align 4,,15
L144:
	movl	%ebx, %eax
	sall	$4, %eax
	flds	12(%eax,%edx)
	movl	%esi, %eax
	sall	$4, %eax
	flds	12(%eax,%edx)
	fxch	%st(1)
	fsub	%st(2), %st
	fxch	%st(1)
	fsub	%st(2), %st
	fxch	%st(1)
	fabs
	fxch	%st(1)
	fabs
	fucompp
	fnstsw	%ax
	sahf
	jbe	L141
	movl	%ebx, %esi
L141:
	incl	%ebx
	cmpl	%ebx, %ecx
	jg	L144
L160:
	fstp	%st(0)
	sall	$4, %esi
	xorl	%ecx, %ecx
	leal	(%esi,%edx), %edx
L148:
	movl	(%edx), %eax
	addl	$4, %edx
	movl	%eax, (%edi,%ecx,4)
	incl	%ecx
	cmpl	$2, %ecx
	jle	L148
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L158:
	fstp	%st(0)
	xorl	%ecx, %ecx
L126:
	movl	$0x3f000000, (%edi,%ecx,4)
	incl	%ecx
	cmpl	$2, %ecx
	jle	L126
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L159:
	fstp	%st(0)
	xorl	%ecx, %ecx
	leal	(%ebx,%edx), %edx
L138:
	movl	(%edx), %eax
	addl	$4, %edx
	movl	%eax, (%edi,%ecx,4)
	incl	%ecx
	cmpl	$2, %ecx
	jle	L138
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC15:
	.ascii "Pixmap\0"
LC16:
	.ascii "Font\0"
LC18:
	.ascii "Gdkgc\0"
LC17:
	.ascii "ColorMap\0"
LC20:
	.ascii "%0.3f\0"
	.align 4
LC19:
	.long	1199570688
	.text
	.p2align 4,,15
	.def	_configure_event;	.scl	3;	.type	32;	.endef
_configure_event:
	pushl	%ebp
	movl	$80, %eax
	movl	%esp, %ebp
	pushl	%edi
	movl	$LC15, %edi
	pushl	%esi
	movl	$80, %esi
	pushl	%ebx
	subl	$1180, %esp
	movl	$LC16, %ebx
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	movl	$80, %edi
	call	_g_object_get_data
	movl	%eax, -1100(%ebp)
	movl	8(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	$LC18, %esi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -1104(%ebp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	8(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC17, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -1108(%ebp)
	movl	8(%ebp), %eax
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -1112(%ebp)
	movl	-1100(%ebp), %ebx
	testl	%ebx, %ebx
	je	L163
	movl	-1100(%ebp), %edx
	movl	%edx, (%esp)
	call	_gdk_drawable_unref
L163:
	movl	$-1, %ecx
	xorl	%ebx, %ebx
	movl	%ecx, 12(%esp)
	movl	8(%ebp), %ecx
	movl	48(%ecx), %eax
	movl	%eax, 8(%esp)
	movl	44(%ecx), %eax
	movl	%eax, 4(%esp)
	movl	52(%ecx), %eax
	movl	%eax, (%esp)
	call	_gdk_pixmap_new
	movl	%eax, -1100(%ebp)
	movl	8(%ebp), %edx
	movl	52(%edx), %eax
	movl	%eax, (%esp)
	call	_gdk_drawable_get_colormap
	movl	%eax, -1096(%ebp)
	movl	8(%ebp), %ecx
	movl	48(%ecx), %ecx
	movl	%eax, (%esp)
	movl	%ecx, -1092(%ebp)
	call	_gdk_colormap_get_visual
	cmpl	$15, 16(%eax)
	movl	$1, %edx
	movl	%edx, 12(%esp)
	movl	-1096(%ebp), %edx
	movw	$-25536, -36(%ebp)
	setg	%bl
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	leal	-40(%ebp), %eax
	movw	$-25536, -34(%ebp)
	movw	$-25536, -32(%ebp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_gdk_colormap_alloc_color
	testl	%ebx, %ebx
	je	L166
	movl	8(%ebp), %ecx
	xorl	%edi, %edi
	movl	44(%ecx), %ebx
	cmpl	$0, %ebx
	jle	L186
	leal	-56(%ebp), %esi
	.p2align 4,,15
L170:
	pushl	%edi
	movl	-1108(%ebp), %eax
	fildl	(%esp)
	movl	%ebx, (%esp)
	fildl	(%esp)
	addl	$4, %esp
	fdivrp	%st, %st(1)
	fildl	(%eax)
	fnstcw	-1082(%ebp)
	movzwl	-1082(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -1084(%ebp)
	fmulp	%st, %st(1)
	movl	-1108(%ebp), %eax
	fldcw	-1084(%ebp)
	fistpl	-1088(%ebp)
	fldcw	-1082(%ebp)
	movl	-1088(%ebp), %edx
	movl	4(%eax), %ecx
	sall	$4, %edx
	flds	(%edx,%ecx)
	fmuls	LC19
	fldcw	-1084(%ebp)
	fistpl	-1088(%ebp)
	fldcw	-1082(%ebp)
	movl	-1088(%ebp), %eax
	flds	4(%edx,%ecx)
	fmuls	LC19
	movw	%ax, -52(%ebp)
	fldcw	-1084(%ebp)
	fistpl	-1088(%ebp)
	fldcw	-1082(%ebp)
	movl	-1088(%ebp), %eax
	flds	8(%edx,%ecx)
	fmuls	LC19
	movw	%ax, -50(%ebp)
	fldcw	-1084(%ebp)
	fistpl	-1088(%ebp)
	fldcw	-1082(%ebp)
	movl	-1088(%ebp), %eax
	movl	%esi, 4(%esp)
	movl	-1096(%ebp), %edx
	movw	%ax, -48(%ebp)
	movl	$1, %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%edx, (%esp)
	movl	%eax, 8(%esp)
	call	_gdk_colormap_alloc_color
	movl	%esi, 4(%esp)
	movl	-1112(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_gdk_gc_set_foreground
	movl	%edi, 16(%esp)
	movl	-1092(%ebp), %eax
	movl	-1112(%ebp), %edx
	movl	%edi, 8(%esp)
	movl	-1100(%ebp), %ecx
	incl	%edi
	movl	%eax, 20(%esp)
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	call	_gdk_draw_line
	movl	8(%ebp), %eax
	movl	44(%eax), %ebx
	cmpl	%edi, %ebx
	jg	L170
L186:
	movl	$-1, %eax
	xorl	%edi, %edi
	cmpl	$0, %ebx
	movl	%eax, -1116(%ebp)
	jle	L180
	.p2align 4,,15
L195:
	pushl	%edi
	movl	-1108(%ebp), %edx
	fildl	(%esp)
	movl	%ebx, (%esp)
	movl	(%edx), %edx
	fildl	(%esp)
	addl	$4, %esp
	movl	%edx, -1148(%ebp)
	fnstcw	-1082(%ebp)
	movzwl	-1082(%ebp), %eax
	fdivrp	%st, %st(1)
	orw	$3072, %ax
	movw	%ax, -1084(%ebp)
	testl	%edx, %edx
	fildl	-1148(%ebp)
	fmulp	%st, %st(1)
	fldcw	-1084(%ebp)
	fistpl	-1088(%ebp)
	fldcw	-1082(%ebp)
	movl	-1088(%ebp), %esi
	js	L191
L175:
	sarl	$2, %edx
	movl	%esi, %eax
	movl	%edx, %ecx
	cltd
	idivl	%ecx
	testl	%edx, %edx
	sete	%dl
	xorl	%eax, %eax
	testl	%esi, %esi
	setg	%al
	testl	%edx, %eax
	je	L173
	movl	-1148(%ebp), %eax
	decl	%eax
	cmpl	%esi, %eax
	setg	%dl
	xorl	%eax, %eax
	cmpl	-1116(%ebp), %esi
	setne	%al
	testl	%edx, %eax
	je	L173
	movl	-1092(%ebp), %eax
	testl	%eax, %eax
	js	L192
L176:
	movl	-1108(%ebp), %ecx
	sarl	$2, %eax
	xorl	%ebx, %ebx
	movl	-1092(%ebp), %edx
	subl	%eax, %edx
	movl	4(%ecx), %eax
	movl	%edx, -1120(%ebp)
	movl	%esi, %edx
	sall	$4, %edx
	flds	12(%edx,%eax)
	movl	$LC20, %eax
	movl	%eax, 4(%esp)
	leal	-1080(%ebp), %eax
	fstpl	8(%esp)
	movl	%eax, (%esp)
	call	_sprintf
	movl	-1104(%ebp), %ecx
	testl	%ecx, %ecx
	je	L177
	movl	-1104(%ebp), %ecx
	leal	-1080(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	call	_gdk_string_width
	movl	%eax, %ebx
L177:
	movw	$0, -36(%ebp)
	movl	%ebx, %eax
	movl	-1096(%ebp), %edx
	movw	$0, -34(%ebp)
	shrl	$31, %eax
	leal	(%ebx,%eax), %eax
	movl	%edx, (%esp)
	sarl	%eax
	movl	%edi, %ebx
	movw	$0, -32(%ebp)
	subl	%eax, %ebx
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gdk_color_alloc
	movl	-1112(%ebp), %eax
	leal	-40(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_gdk_gc_set_foreground
	movl	$1, %edx
	movl	$2, %eax
	movl	%edx, 16(%esp)
	movl	-1112(%ebp), %edx
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_gdk_gc_set_line_attributes
	movl	-1104(%ebp), %eax
	testl	%eax, %eax
	je	L178
	movl	%ebx, 12(%esp)
	movl	-1120(%ebp), %eax
	leal	-1080(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	-1112(%ebp), %edx
	movl	-1104(%ebp), %ecx
	movl	%eax, 16(%esp)
	movl	-1100(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_gdk_draw_string
L178:
	movl	%esi, -1116(%ebp)
	movl	8(%ebp), %edx
	movl	44(%edx), %ebx
	.p2align 4,,15
L173:
	incl	%edi
	cmpl	%edi, %ebx
	jg	L195
L180:
	movl	8(%ebp), %eax
	movl	$80, %edi
	movl	$LC15, %esi
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-1100(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	addl	$1180, %esp
	movl	$1, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L191:
	addl	$3, %edx
	jmp	L175
L166:
	movl	-1112(%ebp), %eax
	leal	-40(%ebp), %ecx
	xorl	%edi, %edi
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_gdk_gc_set_foreground
	movl	8(%ebp), %edx
	movl	44(%edx), %eax
	testl	%eax, %eax
	jle	L180
	.p2align 4,,15
L184:
	movl	%edi, 16(%esp)
	xorl	%eax, %eax
	movl	-1092(%ebp), %ecx
	movl	%eax, 12(%esp)
	movl	-1100(%ebp), %edx
	movl	-1112(%ebp), %eax
	movl	%ecx, 20(%esp)
	movl	%edi, 8(%esp)
	incl	%edi
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_gdk_draw_line
	movl	8(%ebp), %ecx
	cmpl	%edi, 44(%ecx)
	jg	L184
	jmp	L180
L192:
	addl	$3, %eax
	jmp	L176
	.section .rdata,"dr"
LC22:
	.ascii "DrawingArea\0"
	.text
	.p2align 4,,15
.globl _color_map_refresh
	.def	_color_map_refresh;	.scl	2;	.type	32;	.endef
_color_map_refresh:
	pushl	%ebp
	movl	$80, %eax
	movl	%esp, %ebp
	subl	$8, %esp
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC22, %ecx
	movl	%ecx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	%edx, 4(%esp)
	call	_configure_event
	leave
	ret
	.p2align 4,,15
	.def	_expose_event;	.scl	3;	.type	32;	.endef
_expose_event:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	%esi, -8(%ebp)
	movl	12(%ebp), %esi
	movl	%edi, -4(%ebp)
	movl	8(%ebp), %edi
	movl	%ebx, -12(%ebp)
	movl	32(%esi), %ebx
	testl	%ebx, %ebx
	jle	L200
L197:
	movl	-12(%ebp), %ebx
	xorl	%eax, %eax
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L200:
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC15, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	testl	%eax, %eax
	movl	%eax, %ebx
	je	L197
	movl	24(%edi), %eax
	movl	%eax, -16(%ebp)
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movzbl	18(%eax), %ecx
	movl	24(%esi), %eax
	movl	%eax, 32(%esp)
	movl	20(%esi), %eax
	movl	%eax, 28(%esp)
	movl	16(%esi), %edx
	movl	%edx, 24(%esp)
	movl	12(%esi), %eax
	movl	%edx, 16(%esp)
	movl	-16(%ebp), %edx
	movl	%eax, 20(%esp)
	movl	%eax, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	528(%edx,%ecx,4), %eax
	movl	%eax, 4(%esp)
	movl	52(%edi), %eax
	movl	%eax, (%esp)
	call	_gdk_draw_drawable
	jmp	L197
	.section .rdata,"dr"
LC23:
	.ascii "helvetica bold 12\0"
LC24:
	.ascii "configure_event\0"
LC25:
	.ascii "expose_event\0"
LC26:
	.ascii "EntryLeft\0"
LC27:
	.ascii "EntryRight\0"
LC28:
	.ascii "Handlebox\0"
LC29:
	.ascii "OtherEntry\0"
LC30:
	.ascii "activate\0"
	.text
	.p2align 4,,15
.globl _create_color_map_show
	.def	_create_color_map_show;	.scl	2;	.type	32;	.endef
_create_color_map_show:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	movl	16(%ebp), %esi
	call	_gtk_handle_box_new
	movl	%eax, -16(%ebp)
	call	_gtk_handle_box_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	%edx, 4(%esp)
	call	_gtk_handle_box_set_shadow_type
	movl	%ebx, 4(%esp)
	movl	-16(%ebp), %edx
	xorl	%ebx, %ebx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	xorl	%edi, %edi
	call	_gtk_handle_box_set_handle_position
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 8(%esp)
	movl	-16(%ebp), %edx
	movl	$4, %ebx
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_box_pack_start
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$1, (%esp)
	call	_gtk_table_new
	movl	%eax, -20(%ebp)
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-20(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_add
	testl	%esi, %esi
	je	L202
	movl	%esi, (%esp)
	call	_gtk_label_new
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_gtk_widget_show
	call	_gtk_table_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	$6, %edi
	movl	$6, %esi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 28(%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 36(%esp)
	movl	$1, %edi
	movl	$1, %ecx
	movl	%edx, 32(%esp)
	xorl	%edx, %edx
	movl	%esi, 24(%esp)
	xorl	%esi, %esi
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_table_attach
L202:
	call	_gtk_entry_new
	movl	%eax, (%esp)
	movl	%eax, %edi
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	$-1, %ebx
	xorl	%esi, %esi
	movl	%ebx, 8(%esp)
	movl	$6, %ebx
	call	_gtk_widget_set_size_request
	movl	%edi, (%esp)
	call	_gtk_widget_show
	call	_gtk_table_get_type
	movl	%eax, -32(%ebp)
	movl	-20(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 32(%esp)
	xorl	%edx, %edx
	movl	$6, %ecx
	movl	%edx, 36(%esp)
	xorl	%esi, %esi
	movl	$1, %edx
	movl	%ebx, 28(%esp)
	movl	$2, %ebx
	movl	%ecx, 24(%esp)
	movl	$1, %ecx
	movl	%edx, 20(%esp)
	movl	%ecx, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	call	_gtk_table_attach
	movl	%edi, -24(%ebp)
	movl	_PrincipalWindow, %eax
	xorl	%edi, %edi
	movl	52(%eax), %eax
	movl	%eax, (%esp)
	call	_gdk_gc_new
	movl	%eax, -28(%ebp)
	movl	$LC23, (%esp)
	call	_pango_font_description_from_string
	testl	%eax, %eax
	je	L203
	movl	%eax, (%esp)
	call	_gdk_font_from_description
	movl	%eax, %edi
L203:
	call	_gtk_drawing_area_new
	movl	%eax, %esi
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	$300, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$-1, %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$5, %ebx
	call	_gtk_widget_set_size_request
	movl	-20(%ebp), %edx
	movl	-32(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 28(%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 36(%esp)
	movl	$5, %ecx
	xorl	%ebx, %ebx
	movl	%edx, 32(%esp)
	movl	$1, %edx
	movl	%ecx, 24(%esp)
	movl	$3, %ecx
	movl	%edx, 20(%esp)
	movl	$2, %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	movl	%eax, (%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_table_attach
	movl	%esi, (%esp)
	call	_gtk_widget_realize
	movl	$-1, %eax
	movl	%eax, 12(%esp)
	movl	48(%esi), %eax
	movl	%eax, 8(%esp)
	movl	44(%esi), %eax
	movl	%eax, 4(%esp)
	movl	52(%esi), %eax
	movl	%eax, (%esp)
	call	_gdk_pixmap_new
	movl	%esi, (%esp)
	movl	%eax, %ebx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 8(%esp)
	movl	$LC15, %ebx
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_object_set_data
	movl	%esi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 8(%esp)
	movl	$LC16, %edx
	movl	$80, %edi
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_object_set_data
	movl	%edi, 4(%esp)
	movl	$_configure_event, %edi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 20(%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 12(%esp)
	movl	$LC24, %ebx
	movl	%ecx, 16(%esp)
	movl	%edi, 8(%esp)
	xorl	%edi, %edi
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$_expose_event, %ecx
	movl	%edx, 20(%esp)
	movl	$LC25, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$80, %ebx
	call	_g_signal_connect_data
	call	_gtk_entry_new
	movl	%ebx, 4(%esp)
	movl	%eax, %edi
	movl	$-1, %eax
	movl	%eax, 8(%esp)
	movl	$6, %ebx
	movl	%edi, (%esp)
	call	_gtk_widget_set_size_request
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	-20(%ebp), %edx
	movl	-32(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 28(%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 36(%esp)
	movl	$6, %ecx
	xorl	%ebx, %ebx
	movl	%edx, 32(%esp)
	movl	$1, %edx
	movl	%ecx, 24(%esp)
	movl	$4, %ecx
	movl	%edx, 20(%esp)
	movl	$3, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	$LC26, %ebx
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_table_attach
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	-16(%ebp), %edx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-24(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	$LC22, %ebx
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	-16(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC27, %edx
	movl	%edi, 8(%esp)
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	movl	-16(%ebp), %edx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC18, %ebx
	call	_g_object_set_data
	movl	-16(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$LC17, %edx
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-28(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	$LC18, %ebx
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	%esi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$LC17, %edx
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	movl	%esi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-28(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	$LC22, %ebx
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	-24(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC22, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 8(%esp)
	call	_g_object_set_data
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC17, %ebx
	call	_g_object_set_data
	movl	-24(%ebp), %edx
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$LC17, %edx
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	12(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	$LC28, %ebx
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	-24(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$LC28, %edx
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-16(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	$LC22, %ebx
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	-24(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC22, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 8(%esp)
	call	_g_object_set_data
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 8(%esp)
	movl	$80, %esi
	movl	%ebx, 4(%esp)
	movl	$LC29, %ebx
	call	_g_object_set_data
	movl	-24(%ebp), %edx
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC29, %edx
	movl	%edx, 4(%esp)
	movl	%edi, 8(%esp)
	call	_g_object_set_data
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-24(%ebp), %edx
	xorl	%esi, %esi
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	-24(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$_reset_colorMap, %ecx
	movl	%edx, 20(%esp)
	movl	$LC30, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%esi, 16(%esp)
	movl	$80, %esi
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 4(%esp)
	movl	%eax, %ebx
	movl	$LC30, %esi
	movl	%edi, (%esp)
	movl	$_reset_colorMap, %edi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ebx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	call	_g_signal_connect_data
	movl	-16(%ebp), %eax
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC34:
	.ascii "%f\0"
LC33:
	.ascii "%0.1e\0"
	.align 8
LC31:
	.long	-755914244
	.long	1062232653
	.align 8
LC32:
	.long	-500134854
	.long	1044740494
	.text
	.p2align 4,,15
.globl _color_map_show
	.def	_color_map_show;	.scl	2;	.type	32;	.endef
_color_map_show:
	pushl	%ebp
	movl	$80, %ecx
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$1068, %esp
	movl	$LC27, %ebx
	movl	%ecx, 4(%esp)
	movl	8(%ebp), %esi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC26, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%esi, (%esp)
	movl	%eax, %edi
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -1052(%ebp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC17, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	movl	(%eax), %eax
	testl	%eax, %eax
	jle	L206
	movl	4(%ebx), %edx
	flds	12(%edx)
	fld	%st(0)
	fabs
	fldl	LC31
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	ja	L224
	fstp	%st(0)
	flds	12(%edx)
	fld	%st(0)
	fabs
	fldl	LC32
	fucompp
	fnstsw	%ax
	sahf
	ja	L225
	fstp	%st(0)
	flds	12(%edx)
	movl	$LC34, %eax
	movl	%eax, 4(%esp)
	leal	-1048(%ebp), %eax
	fstpl	8(%esp)
	movl	%eax, (%esp)
L219:
	call	_sprintf
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	leal	-1048(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	(%ebx), %ecx
	movl	4(%ebx), %edx
	movl	%ecx, %eax
	sall	$4, %eax
	flds	-4(%edx,%eax)
	fld	%st(0)
	fabs
	fldl	LC31
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	ja	L226
	fstp	%st(0)
	movl	%ecx, %eax
	sall	$4, %eax
	flds	-4(%edx,%eax)
	fld	%st(0)
	fabs
	fldl	LC32
	fucompp
	fnstsw	%ax
	sahf
	jbe	L216
	fstpl	8(%esp)
	movl	$LC33, %ebx
	movl	%ebx, 4(%esp)
L222:
	leal	-1048(%ebp), %edx
	movl	%edx, (%esp)
L220:
	call	_sprintf
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	-1052(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	leal	-1048(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
L206:
	movl	%esi, (%esp)
	call	_gtk_widget_show_all
	addl	$1068, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L225:
	fstpl	8(%esp)
	movl	$LC33, %eax
L223:
	movl	%eax, 4(%esp)
	leal	-1048(%ebp), %edx
	movl	%edx, (%esp)
	jmp	L219
	.p2align 4,,7
L216:
	fstp	%st(0)
	sall	$4, %ecx
	leal	-1048(%ebp), %eax
	flds	-4(%edx,%ecx)
	movl	$LC34, %ecx
	movl	%ecx, 4(%esp)
	fstpl	8(%esp)
	movl	%eax, (%esp)
	jmp	L220
	.p2align 4,,7
L224:
	fstpl	8(%esp)
	movl	$LC20, %eax
	jmp	L223
	.p2align 4,,7
L226:
	fstpl	8(%esp)
	movl	$LC20, %edi
	movl	%edi, 4(%esp)
	jmp	L222
	.p2align 4,,15
.globl _color_map_hide
	.def	_color_map_hide;	.scl	2;	.type	32;	.endef
_color_map_hide:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	jmp	_gtk_widget_hide
	.section .rdata,"dr"
	.align 4
LC39:
	.long	1117782016
	.align 8
LC40:
	.long	-1717986918
	.long	1068079513
	.text
	.p2align 4,,15
.globl _reset_colorMap
	.def	_reset_colorMap;	.scl	2;	.type	32;	.endef
_reset_colorMap:
	pushl	%ebp
	movl	$80, %eax
	movl	%esp, %ebp
	pushl	%edi
	movl	$LC17, %edi
	pushl	%esi
	movl	$80, %esi
	pushl	%ebx
	subl	$92, %esp
	movl	$LC28, %ebx
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	movl	$LC29, %edi
	call	_g_object_get_data
	movl	%eax, -60(%ebp)
	movl	8(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -68(%ebp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	8(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC22, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -72(%ebp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -76(%ebp)
	movl	-60(%ebp), %esi
	testl	%esi, %esi
	je	L228
	movl	-60(%ebp), %edx
	movl	(%edx), %eax
	testl	%eax, %eax
	jle	L228
	movl	12(%ebp), %ebx
	testl	%ebx, %ebx
	je	L231
	movl	4(%edx), %eax
	flds	12(%eax)
	fstps	-52(%ebp)
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_atof
	fstps	-48(%ebp)
L232:
	flds	-48(%ebp)
	movl	$0x3f800000, %eax
	movl	$8, (%esp)
	movl	$1, %edi
	fsubs	-52(%ebp)
	xorl	%ebx, %ebx
	movl	%eax, -40(%ebp)
	movl	$0x00000000, %eax
	fdivs	LC39
	movl	%eax, -36(%ebp)
	movl	%eax, -32(%ebp)
	fstps	-56(%ebp)
	call	_g_malloc
	flds	-52(%ebp)
	movl	%eax, -64(%ebp)
	leal	-40(%ebp), %eax
	fstps	(%esp)
	call	_new_colorMap
	movl	-64(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
L244:
	movl	$19, %esi
	.p2align 4,,15
L243:
	testl	%ebx, %ebx
	jne	L239
	flds	-36(%ebp)
	faddl	LC40
L249:
	fstps	-36(%ebp)
L242:
	pushl	%edi
	movl	-64(%ebp), %eax
	leal	-40(%ebp), %edx
	fildl	(%esp)
	addl	$4, %esp
	incl	%edi
	fmuls	-56(%ebp)
	fadds	-52(%ebp)
	fstps	(%esp)
	call	_add_to_colorMap
	decl	%esi
	jns	L243
	incl	%ebx
	cmpl	$4, %ebx
	jl	L244
	movl	-64(%ebp), %eax
	movl	$LC17, %edi
	movl	$80, %esi
	movl	$LC17, %ebx
	call	_sort_colorMap
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	_colormap_free
	movl	-60(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	8(%ebp), %ecx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-64(%ebp), %edx
	movl	%edi, 4(%esp)
	movl	$80, %edi
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	%esi, 4(%esp)
	movl	-68(%ebp), %ecx
	movl	$LC17, %esi
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-64(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	$1, %ebx
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	-72(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-64(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$LC17, %edx
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	movl	%edi, 4(%esp)
	movl	-76(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-64(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	%ebx, _RebuildSurf
	movl	_GLArea, %eax
	movl	%eax, (%esp)
	call	_glarea_rafresh
	movl	-68(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_color_map_hide
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	_color_map_refresh
	movl	-68(%ebp), %edx
	movl	%edx, (%esp)
	call	_color_map_show
L228:
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L239:
	cmpl	$1, %ebx
	je	L250
	cmpl	$2, %ebx
	je	L251
	cmpl	$3, %ebx
	jne	L242
	flds	-36(%ebp)
	fsubl	LC40
	jmp	L249
	.p2align 4,,7
L250:
	flds	-40(%ebp)
	fsubl	LC40
	fstps	-40(%ebp)
	jmp	L242
	.p2align 4,,7
L251:
	flds	-32(%ebp)
	faddl	LC40
	fstps	-32(%ebp)
	jmp	L242
L231:
	movl	-60(%ebp), %edx
	sall	$4, %eax
	movl	4(%edx), %ecx
	addl	%ecx, %eax
	flds	-4(%eax)
	fstps	-48(%ebp)
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_atof
	fstps	-52(%ebp)
	jmp	L232
	.comm	_limits, 32	 # 32
	.comm	_NumPoints, 16	 # 12
	.comm	_firstDirection, 16	 # 12
	.comm	_secondDirection, 16	 # 12
	.comm	_thirdDirection, 16	 # 12
	.comm	_originOfCube, 16	 # 12
	.comm	_PrincipalWindow, 16	 # 4
	.comm	_GLArea, 16	 # 4
	.comm	_GeomOrb, 16	 # 4
	.comm	_ScreenWidth, 16	 # 4
	.comm	_ScreenHeight, 16	 # 4
	.comm	_FontStyle, 32	 # 28
	.comm	_Title, 16	 # 4
	.comm	_ffact, 608	 # 600
	.comm	_fact, 608	 # 600
	.comm	_CIJ, 90000	 # 90000
	.comm	_Type, 16	 # 4
	.comm	_AOrb, 16	 # 4
	.comm	_Ncenters, 16	 # 4
	.comm	_Ntype, 16	 # 4
	.comm	_NAOrb, 16	 # 4
	.comm	_NOrb, 16	 # 4
	.comm	_NAlphaOrb, 16	 # 4
	.comm	_NBetaOrb, 16	 # 4
	.comm	_NTotOcc, 16	 # 4
	.comm	_NAlphaOcc, 16	 # 4
	.comm	_NBetaOcc, 16	 # 4
	.comm	_TypeSelOrb, 16	 # 4
	.comm	_NumSelOrb, 16	 # 4
	.comm	_forb, 16	 # 4
	.comm	_CoefAlphaOrbitals, 16	 # 4
	.comm	_OccAlphaOrbitals, 16	 # 4
	.comm	_EnerAlphaOrbitals, 16	 # 4
	.comm	_SymAlphaOrbitals, 16	 # 4
	.comm	_CoefBetaOrbitals, 16	 # 4
	.comm	_EnerBetaOrbitals, 16	 # 4
	.comm	_OccBetaOrbitals, 16	 # 4
	.comm	_SymBetaOrbitals, 16	 # 4
	.comm	_TypeGeom, 16	 # 4
	.comm	_TypeGrid, 16	 # 4
	.comm	_TypeTexture, 16	 # 4
	.comm	_TypeBlend, 16	 # 4
	.comm	_TypePosWireFrame, 16	 # 4
	.comm	_TypeNegWireFrame, 16	 # 4
	.comm	_SurfShow, 16	 # 4
	.comm	_PopupMenuIsOpen, 16	 # 4
	.comm	_isopositive, 16	 # 4
	.comm	_isonegative, 16	 # 4
	.comm	_isonull, 16	 # 4
	.comm	_grid, 16	 # 4
	.comm	_gridPlaneForContours, 16	 # 4
	.comm	_reDrawContoursPlane, 16	 # 4
	.comm	_gridPlaneForPlanesMapped, 16	 # 4
	.comm	_reDrawPlaneMappedPlane, 16	 # 4
	.comm	_AOAvailable, 16	 # 4
	.comm	_RebuildSurf, 16	 # 4
	.comm	_RebuildGeom, 16	 # 4
	.comm	_newSurface, 16	 # 4
	.comm	_newContours, 16	 # 4
	.comm	_DeleteContours, 16	 # 4
	.comm	_CancelCalcul, 16	 # 4
	.comm	_ShowDipoleOrb, 16	 # 4
	.comm	_ShowHBondOrb, 16	 # 4
	.comm	_ShowHAtomOrb, 16	 # 4
	.comm	_ShowMultiBondsOrb, 16	 # 4
	.comm	_ShowVibration, 16	 # 4
	.comm	_openGLOptions, 32	 # 24
	.comm	_createBMPFiles, 16	 # 4
	.comm	_numBMPFile, 16	 # 4
	.comm	_createPPMFiles, 16	 # 4
	.comm	_numPPMFile, 16	 # 4
	.comm	_createPOVFiles, 16	 # 4
	.comm	_numPOVFile, 16	 # 4
	.def	_gtk_widget_hide;	.scl	3;	.type	32;	.endef
	.def	_gtk_widget_show_all;	.scl	3;	.type	32;	.endef
	.def	_gtk_entry_set_text;	.scl	3;	.type	32;	.endef
	.def	_gtk_object_get_type;	.scl	3;	.type	32;	.endef
	.def	_gdk_gc_new;	.scl	3;	.type	32;	.endef
	.def	_gtk_entry_new;	.scl	3;	.type	32;	.endef
	.def	_gtk_label_new;	.scl	3;	.type	32;	.endef
	.def	_gtk_container_get_type;	.scl	3;	.type	32;	.endef
	.def	_gtk_container_add;	.scl	3;	.type	32;	.endef
	.def	_gtk_table_new;	.scl	3;	.type	32;	.endef
	.def	_gtk_box_get_type;	.scl	3;	.type	32;	.endef
	.def	_gtk_box_pack_start;	.scl	3;	.type	32;	.endef
	.def	_gtk_widget_show;	.scl	3;	.type	32;	.endef
	.def	_gtk_handle_box_set_handle_position;	.scl	3;	.type	32;	.endef
	.def	_gtk_handle_box_get_type;	.scl	3;	.type	32;	.endef
	.def	_gtk_handle_box_set_shadow_type;	.scl	3;	.type	32;	.endef
	.def	_gtk_handle_box_new;	.scl	3;	.type	32;	.endef
	.def	_g_signal_connect_data;	.scl	3;	.type	32;	.endef
	.def	_gtk_widget_realize;	.scl	3;	.type	32;	.endef
	.def	_gtk_table_get_type;	.scl	3;	.type	32;	.endef
	.def	_gtk_table_attach;	.scl	3;	.type	32;	.endef
	.def	_gtk_widget_set_size_request;	.scl	3;	.type	32;	.endef
	.def	_gtk_drawing_area_new;	.scl	3;	.type	32;	.endef
	.def	_gdk_font_from_description;	.scl	3;	.type	32;	.endef
	.def	_pango_font_description_from_string;	.scl	3;	.type	32;	.endef
	.def	_gtk_widget_get_type;	.scl	3;	.type	32;	.endef
	.def	_gdk_draw_drawable;	.scl	3;	.type	32;	.endef
	.def	_gdk_draw_string;	.scl	3;	.type	32;	.endef
	.def	_gdk_gc_set_line_attributes;	.scl	3;	.type	32;	.endef
	.def	_gdk_color_alloc;	.scl	3;	.type	32;	.endef
	.def	_gdk_string_width;	.scl	3;	.type	32;	.endef
	.def	_sprintf;	.scl	3;	.type	32;	.endef
	.def	_gdk_draw_line;	.scl	3;	.type	32;	.endef
	.def	_gdk_gc_set_foreground;	.scl	3;	.type	32;	.endef
	.def	_gdk_colormap_alloc_color;	.scl	3;	.type	32;	.endef
	.def	_gdk_colormap_get_visual;	.scl	3;	.type	32;	.endef
	.def	_gdk_drawable_get_colormap;	.scl	3;	.type	32;	.endef
	.def	_gdk_pixmap_new;	.scl	3;	.type	32;	.endef
	.def	_gdk_drawable_unref;	.scl	3;	.type	32;	.endef
	.def	_color_map_show;	.scl	3;	.type	32;	.endef
	.def	_color_map_refresh;	.scl	3;	.type	32;	.endef
	.def	_color_map_hide;	.scl	3;	.type	32;	.endef
	.def	_glarea_rafresh;	.scl	3;	.type	32;	.endef
	.def	_g_object_set_data;	.scl	3;	.type	32;	.endef
	.def	_atof;	.scl	3;	.type	32;	.endef
	.def	_gtk_entry_get_type;	.scl	3;	.type	32;	.endef
	.def	_gtk_entry_get_text;	.scl	3;	.type	32;	.endef
	.def	_g_type_check_instance_cast;	.scl	3;	.type	32;	.endef
	.def	_g_object_get_data;	.scl	3;	.type	32;	.endef
	.def	_g_malloc;	.scl	3;	.type	32;	.endef
	.def	_g_free;	.scl	3;	.type	32;	.endef
