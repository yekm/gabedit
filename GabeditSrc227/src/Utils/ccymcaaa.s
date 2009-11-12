	.file	"GTF.c"
	.text
	.p2align 4,,15
	.def	_f;	.scl	3;	.type	32;	.endef
_f:
	pushl	%ebp
	fldz
	movl	%esp, %ebp
	pushl	%edi
	movl	%edx, %edi
	xorl	%edx, %edx
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$44, %esp
	movl	8(%ebp), %ecx
	fstpl	-32(%ebp)
	subl	%ecx, %eax
	cmpl	$0, %eax
	jle	L2
	movl	%eax, %edx
L2:
	movl	%esi, -20(%ebp)
	cmpl	%edi, %esi
	jle	L3
	movl	%edi, -20(%ebp)
L3:
	movl	%edx, %ebx
	cmpl	-20(%ebp), %ebx
	jg	L9
	.p2align 4,,15
L14:
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	_binomial
	movl	%esi, %eax
	subl	%ebx, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	fstpl	-40(%ebp)
	movl	%eax, (%esp)
	call	_binomial
	fmull	-40(%ebp)
	movl	%edi, %eax
	subl	%ebx, %eax
	movl	%eax, 8(%esp)
	fstpl	-40(%ebp)
	fldl	12(%ebp)
	fchs
	fstpl	(%esp)
	call	_dpn
	fmull	-40(%ebp)
	movl	8(%ebp), %eax
	subl	%esi, %eax
	addl	%ebx, %eax
	incl	%ebx
	fstpl	-40(%ebp)
	fldl	20(%ebp)
	movl	%eax, 8(%esp)
	fchs
	fstpl	(%esp)
	call	_dpn
	fmull	-40(%ebp)
	fstpl	-40(%ebp)
	fldl	-32(%ebp)
	faddl	-40(%ebp)
	fstpl	-32(%ebp)
	cmpl	-20(%ebp), %ebx
	jle	L14
L9:
	fldl	-32(%ebp)
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_Theta;	.scl	3;	.type	32;	.endef
_Theta:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	%edx, %esi
	pushl	%ebx
	subl	$32, %esp
	movl	%eax, %ebx
	fldl	24(%ebp)
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	fstpl	12(%esp)
	fldl	16(%ebp)
	movl	%eax, (%esp)
	movl	%ebx, %eax
	fstpl	4(%esp)
	call	_f
	movl	%ebx, (%esp)
	fstpl	-16(%ebp)
	call	_factorial
	fmull	-16(%ebp)
	movl	%esi, (%esp)
	fstpl	-16(%ebp)
	call	_factorial
	fdivrl	-16(%ebp)
	movl	%ebx, %edx
	leal	(%esi,%esi), %eax
	subl	%eax, %edx
	subl	%esi, %ebx
	movl	%edx, (%esp)
	fstpl	-16(%ebp)
	call	_factorial
	fdivrl	-16(%ebp)
	pushl	%ebx
	fstpl	-16(%ebp)
	fildl	(%esp)
	addl	$4, %esp
	fstpl	8(%esp)
	fldl	32(%ebp)
	fstpl	(%esp)
	call	_pow
	fdivrl	-16(%ebp)
	fstl	-16(%ebp)
	addl	$32, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_B;	.scl	3;	.type	32;	.endef
_B:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	leal	(%eax,%edx), %edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	%edi, %ebx
	movl	8(%ebp), %eax
	addl	%eax, %eax
	subl	%eax, %ebx
	movl	12(%ebp), %eax
	addl	%eax, %eax
	subl	%eax, %ebx
	movl	16(%ebp), %eax
	movl	%ebx, %esi
	addl	%eax, %edx
	movl	%edx, (%esp)
	call	_m1p
	pushl	%eax
	fildl	(%esp)
	addl	$4, %esp
	fmull	36(%ebp)
	movl	%ebx, (%esp)
	fmull	44(%ebp)
	fstpl	44(%ebp)
	call	_factorial
	fmull	44(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	fstpl	44(%ebp)
	call	_factorial
	fdivrl	44(%ebp)
	movl	16(%ebp), %eax
	addl	%eax, %eax
	subl	%eax, %esi
	movl	%esi, (%esp)
	fstpl	44(%ebp)
	call	_factorial
	fdivrl	44(%ebp)
	pushl	%esi
	fstpl	44(%ebp)
	fildl	(%esp)
	addl	$4, %esp
	fstpl	8(%esp)
	fldl	20(%ebp)
	fstpl	(%esp)
	call	_pow
	fmull	44(%ebp)
	movl	8(%ebp), %eax
	subl	%eax, %edi
	movl	12(%ebp), %eax
	fstpl	44(%ebp)
	subl	%eax, %edi
	pushl	%edi
	movl	$1074790400, %edi
	fildl	(%esp)
	addl	$4, %esp
	movl	%edi, 4(%esp)
	movl	$0, (%esp)
	fstpl	8(%esp)
	call	_pow
	movl	16(%ebp), %esi
	fstpl	-24(%ebp)
	subl	%esi, %ebx
	pushl	%ebx
	fildl	(%esp)
	addl	$4, %esp
	fstpl	8(%esp)
	fldl	28(%ebp)
	fstpl	(%esp)
	call	_pow
	fmull	-24(%ebp)
	fstpl	-24(%ebp)
	fldl	44(%ebp)
	fdivl	-24(%ebp)
	fstl	44(%ebp)
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.data
	.align 8
TMAX.4:
	.long	0
	.long	1078525952
	.align 4
MAXFACT.5:
	.long	200
	.align 8
acc.6:
	.long	-1747416644
	.long	1016910514
	.section .rdata,"dr"
	.align 4
LC11:
	.ascii "Divergence in F, Ionic integrals\0"
	.align 8
LC8:
	.long	-1850413206
	.long	1073503224
	.align 4
LC10:
	.long	1056964608
	.text
	.p2align 4,,15
	.def	_F;	.scl	3;	.type	32;	.endef
_F:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$76, %esp
	fldl	8(%ebp)
	fchs
	fstpl	(%esp)
	call	_exp
	fldl	acc.6
	fldz
	fld1
	fxch	%st(3)
	fstpl	-24(%ebp)
	fldl	8(%ebp)
	fxch	%st(1)
	fstpl	-40(%ebp)
	fxch	%st(2)
	fstl	-48(%ebp)
	fxch	%st(2)
	fadd	%st(0), %st
	fstpl	-32(%ebp)
	fldl	8(%ebp)
	fabs
	fxch	%st(1)
	fucom	%st(1)
	fnstsw	%ax
	fstp	%st(1)
	sahf
	jb	L18
	fstp	%st(0)
	leal	1(%esi,%esi), %eax
	pushl	%eax
	fildl	(%esp)
	addl	$4, %esp
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	fdivrp	%st, %st(1)
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L18:
	fldl	TMAX.4
	fldl	8(%ebp)
	fucompp
	fnstsw	%ax
	sahf
	jae	L36
	fldl	-40(%ebp)
	fdivrp	%st, %st(2)
	fxch	%st(1)
	fabs
	fucompp
	fnstsw	%ax
	sahf
	jbe	L30
	movl	MAXFACT.5, %eax
	movl	%esi, %ebx
	cmpl	%eax, %esi
	jge	L25
	leal	-1(%esi,%esi), %eax
	movl	%eax, -68(%ebp)
	.p2align 4,,15
L27:
	movl	-68(%ebp), %eax
	incl	%edi
	movl	%eax, (%esp)
	call	_doubleFactorial
	leal	1(%ebx,%ebx), %eax
	fstpl	-64(%ebp)
	movl	%eax, (%esp)
	call	_doubleFactorial
	fldl	-64(%ebp)
	fldl	-48(%ebp)
	fmull	-32(%ebp)
	fxch	%st(1)
	fdivp	%st, %st(2)
	fxch	%st(1)
	fmull	-48(%ebp)
	fldl	-40(%ebp)
	fxch	%st(2)
	fstpl	-48(%ebp)
	fadd	%st, %st(1)
	fxch	%st(1)
	fstl	-40(%ebp)
	fdivrp	%st, %st(1)
	fabs
	fldl	acc.6
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L32
	leal	(%esi,%edi), %ebx
	cmpl	MAXFACT.5, %ebx
	jl	L27
L33:
	movl	$LC11, (%esp)
	call	_printf
	movl	$1, (%esp)
	call	_exit
	.p2align 4,,7
L36:
	fstp	%st(0)
	fstp	%st(0)
	leal	-1(%esi,%esi), %eax
	movl	%eax, (%esp)
	call	_doubleFactorial
	fmull	LC8
	movl	$1073741824, %eax
	fstpl	-56(%ebp)
	movl	%eax, 4(%esp)
	movl	%esi, 8(%esp)
	movl	$0, (%esp)
	call	_dpn
	fdivrl	-56(%ebp)
	fstpl	-56(%ebp)
	movl	%esi, 8(%esp)
	fldl	8(%ebp)
	fstpl	(%esp)
	call	_dpn
	fdivrl	-56(%ebp)
	fmuls	LC10
	fstpl	-56(%ebp)
	fldl	8(%ebp)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L39
	jne	L39
L40:
	fdivrl	-56(%ebp)
L41:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L30:
	movl	MAXFACT.5, %eax
	movl	%esi, %ebx
L25:
	cmpl	%eax, %ebx
	jge	L33
	fldl	-40(%ebp)
	fmull	-24(%ebp)
	jmp	L41
L39:
	fstp	%st(0)
	fldl	8(%ebp)
	fstpl	(%esp)
	call	_sqrt
	jmp	L40
L32:
	movl	MAXFACT.5, %eax
	leal	(%esi,%edi), %ebx
	jmp	L25
	.section .rdata,"dr"
	.align 4
LC15:
	.long	1082130432
	.text
	.p2align 4,,15
	.def	_A;	.scl	3;	.type	32;	.endef
_A:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	%edx, %esi
	pushl	%ebx
	subl	$60, %esp
	movl	%eax, %ebx
	movl	8(%ebp), %edx
	leal	(%eax,%edx), %eax
	movl	%eax, (%esp)
	call	_m1p
	pushl	%eax
	movl	16(%ebp), %eax
	movl	12(%ebp), %edx
	fildl	(%esp)
	addl	$4, %esp
	movl	%eax, (%esp)
	movl	%ebx, %eax
	fstpl	-24(%ebp)
	fldl	28(%ebp)
	fstpl	12(%esp)
	fldl	20(%ebp)
	fstpl	4(%esp)
	call	_f
	fmull	-24(%ebp)
	movl	%ebx, (%esp)
	fstpl	-24(%ebp)
	call	_factorial
	fmull	-24(%ebp)
	movl	%ebx, %edx
	movl	8(%ebp), %eax
	leal	(%esi,%eax), %edi
	leal	(%edi,%edi), %eax
	subl	%eax, %edx
	fstpl	-24(%ebp)
	fldl	36(%ebp)
	movl	%edx, 8(%esp)
	fstpl	(%esp)
	call	_dpn
	fmull	-24(%ebp)
	movl	%esi, (%esp)
	fstpl	-24(%ebp)
	call	_factorial
	movl	8(%ebp), %eax
	fstpl	-32(%ebp)
	movl	%eax, (%esp)
	call	_factorial
	fmull	-32(%ebp)
	movl	8(%ebp), %edx
	leal	(%esi,%esi), %eax
	subl	%eax, %ebx
	addl	%edx, %edx
	subl	%edx, %ebx
	movl	%ebx, (%esp)
	fstpl	-32(%ebp)
	call	_factorial
	fmull	-32(%ebp)
	movl	%edi, 8(%esp)
	fstpl	-32(%ebp)
	fldl	44(%ebp)
	fmuls	LC15
	fstpl	(%esp)
	call	_dpn
	fmull	-32(%ebp)
	fstpl	-32(%ebp)
	fldl	-24(%ebp)
	fdivl	-32(%ebp)
	fstl	-24(%ebp)
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
	.align 8
LC18:
	.long	1413754136
	.long	1074340347
	.text
	.p2align 4,,15
	.def	_GTFstarGTF;	.scl	3;	.type	32;	.endef
_GTFstarGTF:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$204, %esp
	fldl	(%eax)
	fldl	(%edx)
	movl	%eax, -124(%ebp)
	fld	%st(1)
	fadd	%st(1), %st
	movl	%edx, -128(%ebp)
	fstpl	-136(%ebp)
	fldz
	fstpl	-144(%ebp)
L48:
	movl	-124(%ebp), %eax
	fld	%st(0)
	movl	-128(%ebp), %edx
	fld	%st(2)
	fldl	32(%eax,%esi,8)
	fxch	%st(2)
	fmull	32(%edx,%esi,8)
	fxch	%st(1)
	fmul	%st(2), %st
	faddp	%st, %st(1)
	fdivl	-136(%ebp)
	fsubr	%st, %st(1)
	fxch	%st(1)
	fstpl	-88(%ebp,%esi,8)
	fsubrl	32(%edx,%esi,8)
	fstpl	-120(%ebp,%esi,8)
	fldl	32(%edx,%esi,8)
	fsubrl	32(%eax,%esi,8)
	incl	%esi
	cmpl	$2, %esi
	fmul	%st(0), %st
	faddl	-144(%ebp)
	fstpl	-144(%ebp)
	jle	L48
	fldl	-136(%ebp)
	fdivrl	LC18
	fstl	-160(%ebp)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L67
	jne	L67
L49:
	fxch	%st(2)
	fchs
	fxch	%st(2)
	xorl	%esi, %esi
	fmull	-160(%ebp)
	fxch	%st(2)
	fmulp	%st, %st(1)
	fdivl	-136(%ebp)
	fmull	-144(%ebp)
	fxch	%st(1)
	fstpl	-152(%ebp)
	fstpl	(%esp)
	call	_exp
	fmull	-152(%ebp)
	fstpl	-152(%ebp)
L57:
	movl	-124(%ebp), %eax
	fldz
	xorl	%edi, %edi
	fstpl	-56(%ebp,%esi,8)
	movl	16(%eax,%esi,4), %ecx
	movl	-128(%ebp), %eax
	movl	%ecx, %edx
	movl	16(%eax,%esi,4), %ebx
	addl	%ebx, %edx
	movl	%edx, %eax
	shrl	$31, %eax
	addl	%eax, %edx
	js	L63
	.p2align 4,,15
L56:
	fldl	-120(%ebp,%esi,8)
	movl	-128(%ebp), %edx
	leal	(%edi,%edi), %ebx
	fstpl	12(%esp)
	fldl	-88(%ebp,%esi,8)
	fstpl	4(%esp)
	movl	16(%edx,%esi,4), %eax
	movl	%ecx, %edx
	movl	%eax, (%esp)
	movl	%ebx, %eax
	decl	%ebx
	call	_f
	movl	%ebx, (%esp)
	fstpl	-168(%ebp)
	call	_doubleFactorial
	fmull	-168(%ebp)
	movl	$1073741824, %eax
	movl	%eax, 4(%esp)
	movl	%edi, 8(%esp)
	movl	$0, (%esp)
	fstpl	-168(%ebp)
	call	_dpn
	movl	%edi, 8(%esp)
	incl	%edi
	fstpl	-176(%ebp)
	fldl	-136(%ebp)
	fstpl	(%esp)
	call	_dpn
	fmull	-176(%ebp)
	movl	-124(%ebp), %eax
	movl	-128(%ebp), %edx
	movl	16(%eax,%esi,4), %ecx
	movl	16(%edx,%esi,4), %ebx
	movl	%ecx, %eax
	fstpl	-176(%ebp)
	addl	%ebx, %eax
	movl	%eax, %edx
	fldl	-168(%ebp)
	shrl	$31, %edx
	addl	%edx, %eax
	fdivl	-176(%ebp)
	sarl	%eax
	cmpl	%edi, %eax
	faddl	-56(%ebp,%esi,8)
	fstpl	-56(%ebp,%esi,8)
	jge	L56
L63:
	incl	%esi
	cmpl	$2, %esi
	jle	L57
	fldl	-152(%ebp)
	fmull	-56(%ebp)
	fmull	-48(%ebp)
	fmull	-40(%ebp)
	fstl	-152(%ebp)
	addl	$204, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L67:
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	fldl	-160(%ebp)
	fstpl	(%esp)
	call	_sqrt
	movl	-124(%ebp), %eax
	movl	-128(%ebp), %edx
	fldl	(%eax)
	fldl	(%edx)
	fxch	%st(1)
	fxch	%st(2)
	jmp	L49
	.section .rdata,"dr"
	.align 8
LC22:
	.long	1413754136
	.long	1074340347
	.align 4
LC23:
	.long	1082130432
	.text
	.p2align 4,,15
.globl _normeGTF
	.def	_normeGTF;	.scl	2;	.type	32;	.endef
_normeGTF:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$52, %esp
	movl	8(%ebp), %ebx
	fldl	(%ebx)
	fld	%st(0)
	fadd	%st(1), %st
	fdivl	LC22
	fstl	-16(%ebp)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L79
	jne	L79
L69:
	fxch	%st(1)
	fmuls	LC23
	fxch	%st(1)
	movl	16(%ebx), %ecx
	movl	20(%ebx), %eax
	fmull	-16(%ebp)
	fxch	%st(1)
	movl	24(%ebx), %edx
	addl	%ecx, %eax
	fstpl	(%esp)
	addl	%edx, %eax
	movl	%eax, 8(%esp)
	fstpl	-16(%ebp)
	call	_dpn
	fmull	-16(%ebp)
	movl	16(%ebx), %eax
	movl	%eax, (%esp)
	fstpl	-16(%ebp)
	call	_doubleFactorial
	movl	20(%ebx), %eax
	fstpl	-24(%ebp)
	movl	%eax, (%esp)
	call	_doubleFactorial
	fmull	-24(%ebp)
	movl	24(%ebx), %eax
	movl	%eax, (%esp)
	fstpl	-24(%ebp)
	call	_doubleFactorial
	fmull	-24(%ebp)
	fstpl	-24(%ebp)
	fldl	-16(%ebp)
	fdivl	-24(%ebp)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L80
	je	L70
L80:
	fstp	%st(0)
	fldl	(%ebx)
	fld	%st(0)
	fadd	%st(1), %st
	fdivl	LC22
	fstl	-32(%ebp)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L82
	jne	L82
L71:
	fxch	%st(1)
	fmuls	LC23
	fxch	%st(1)
	movl	16(%ebx), %ecx
	movl	20(%ebx), %eax
	fmull	-32(%ebp)
	fxch	%st(1)
	movl	24(%ebx), %edx
	addl	%ecx, %eax
	fstpl	(%esp)
	addl	%edx, %eax
	movl	%eax, 8(%esp)
	fstpl	-32(%ebp)
	call	_dpn
	fmull	-32(%ebp)
	movl	16(%ebx), %eax
	movl	%eax, (%esp)
	fstpl	-32(%ebp)
	call	_doubleFactorial
	movl	20(%ebx), %eax
	fstpl	-40(%ebp)
	movl	%eax, (%esp)
	call	_doubleFactorial
	fmull	-40(%ebp)
	movl	24(%ebx), %eax
	movl	%eax, (%esp)
	fstpl	-40(%ebp)
	call	_doubleFactorial
	fmull	-40(%ebp)
	fstpl	-40(%ebp)
	fldl	-32(%ebp)
	fdivl	-40(%ebp)
	fstpl	(%esp)
	call	_sqrt
L70:
	addl	$52, %esp
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L79:
	fstp	%st(0)
	fstp	%st(0)
	fldl	-16(%ebp)
	fstpl	(%esp)
	call	_sqrt
	fldl	(%ebx)
	fxch	%st(1)
	jmp	L69
	.p2align 4,,7
L82:
	fstp	%st(0)
	fstp	%st(0)
	fldl	-32(%ebp)
	fstpl	(%esp)
	call	_sqrt
	fldl	(%ebx)
	fxch	%st(1)
	jmp	L71
	.p2align 4,,15
.globl _normaliseRadialGTF
	.def	_normaliseRadialGTF;	.scl	2;	.type	32;	.endef
_normaliseRadialGTF:
	pushl	%ebp
	cld
	movl	%esp, %ebp
	subl	$88, %esp
	movl	%esi, -8(%ebp)
	movl	$14, %ecx
	movl	8(%ebp), %esi
	movl	%edi, -4(%ebp)
	leal	-72(%ebp), %edi
	rep
	movsl
	movl	-56(%ebp), %edi
	movl	-52(%ebp), %eax
	movl	$0, -52(%ebp)
	movl	-48(%ebp), %esi
	movl	$0, -48(%ebp)
	addl	%edi, %eax
	addl	%esi, %eax
	movl	%eax, -56(%ebp)
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	_normeGTF
	movl	8(%ebp), %eax
	fmull	8(%eax)
	fstpl	8(%eax)
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,15
.globl _normaliseGTF
	.def	_normaliseGTF;	.scl	2;	.type	32;	.endef
_normaliseGTF:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$4, %esp
	movl	8(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_normeGTF
	fmull	8(%ebx)
	fstpl	8(%ebx)
	popl	%eax
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,15
.globl _overlapGTF
	.def	_overlapGTF;	.scl	2;	.type	32;	.endef
_overlapGTF:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	fldl	8(%edx)
	fmull	8(%eax)
	fstpl	-24(%ebp)
	call	_GTFstarGTF
	fldl	-24(%ebp)
	leave
	fmulp	%st, %st(1)
	ret
