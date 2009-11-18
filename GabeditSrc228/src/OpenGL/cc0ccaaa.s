	.file	"UtilsOrb.c"
	.text
	.p2align 4,,15
.globl _glMaterialdv
	.def	_glMaterialdv;	.scl	2;	.type	32;	.endef
_glMaterialdv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	16(%ebp), %eax
	fldl	(%eax)
	fstps	-24(%ebp)
	fldl	8(%eax)
	fstps	-20(%ebp)
	fldl	16(%eax)
	fstps	-16(%ebp)
	fldl	24(%eax)
	leal	-24(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	fstps	-12(%ebp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_glMaterialfv@12
	subl	$12, %esp
	leave
	ret
	.p2align 4,,15
.globl _glLightdv
	.def	_glLightdv;	.scl	2;	.type	32;	.endef
_glLightdv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	16(%ebp), %eax
	fldl	(%eax)
	fstps	-24(%ebp)
	fldl	8(%eax)
	fstps	-20(%ebp)
	fldl	16(%eax)
	fstps	-16(%ebp)
	fldl	24(%eax)
	leal	-24(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	fstps	-12(%ebp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_glLightfv@12
	subl	$12, %esp
	leave
	ret
	.p2align 4,,15
.globl _glFogdv
	.def	_glFogdv;	.scl	2;	.type	32;	.endef
_glFogdv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	12(%ebp), %eax
	fldl	(%eax)
	fstps	-24(%ebp)
	fldl	8(%eax)
	fstps	-20(%ebp)
	fldl	16(%eax)
	fstps	-16(%ebp)
	fldl	24(%eax)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	fstps	-12(%ebp)
	movl	%eax, (%esp)
	call	_glFogfv@8
	subl	$8, %esp
	leave
	ret
	.data
	.align 32
def.1:
	.long	17
	.long	25
	.long	33
	.long	49
	.long	65
	.long	97
	.long	129
	.long	193
	.long	257
	.long	385
	.long	513
	.long	769
	.long	1025
	.align 4
nd.2:
	.long	13
	.text
	.p2align 4,,15
	.def	_getOptimalN;	.scl	3;	.type	32;	.endef
_getOptimalN:
	pushl	%ebp
	cmpl	$16, %eax
	movl	%esp, %ebp
	pushl	%ebx
	movl	%eax, %ecx
	jg	L5
	movl	$17, %ecx
L5:
	movl	nd.2, %eax
	xorl	%edx, %edx
	decl	%eax
	cmpl	$0, %eax
	jle	L7
	movl	%eax, %ebx
	.p2align 4,,15
L10:
	movl	def.1(,%edx,4), %eax
	cmpl	%ecx, %eax
	jge	L8
	cmpl	%ecx, def.1+4(,%edx,4)
	jg	L15
L8:
	incl	%edx
	cmpl	%edx, %ebx
	jg	L10
L7:
	movl	%ecx, %eax
	andl	$1, %eax
	cmpl	$1, %eax
	adcl	$0, %ecx
	cmpl	$65, %ecx
	jle	L12
	movl	$65, %ecx
L12:
	popl	%ebx
	movl	%ecx, %eax
	popl	%ebp
	ret
L15:
	movl	%eax, %ecx
	jmp	L7
	.p2align 4,,15
.globl _InitializeAll
	.def	_InitializeAll;	.scl	2;	.type	32;	.endef
_InitializeAll:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	popl	%ebp
	movl	%eax, _CoefAlphaOrbitals
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, _EnerAlphaOrbitals
	movl	$-1, %eax
	movl	%edx, _TypeSelOrb
	movl	%eax, _NumSelOrb
	ret
	.p2align 4,,15
.globl _CreateTable2
	.def	_CreateTable2;	.scl	2;	.type	32;	.endef
_CreateTable2:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$12, %esp
	xorl	%ebx, %ebx
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	cmpl	8(%ebp), %ebx
	movl	%eax, %edi
	jge	L23
	movl	8(%ebp), %esi
	sall	$3, %esi
	.p2align 4,,15
L21:
	movl	%esi, (%esp)
	call	_g_malloc
	movl	%eax, (%edi,%ebx,4)
	incl	%ebx
	cmpl	8(%ebp), %ebx
	jl	L21
L23:
	addl	$12, %esp
	movl	%edi, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
.globl _FreeTable2
	.def	_FreeTable2;	.scl	2;	.type	32;	.endef
_FreeTable2:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%esi, -8(%ebp)
	movl	12(%ebp), %esi
	movl	%ebx, -12(%ebp)
	xorl	%ebx, %ebx
	cmpl	%esi, %ebx
	movl	%edi, -4(%ebp)
	movl	8(%ebp), %edi
	jge	L30
	.p2align 4,,15
L32:
	movl	(%edi,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	%esi, %ebx
	jl	L32
L30:
	movl	%edi, (%esp)
	call	_g_free
	movl	-12(%ebp), %ebx
	xorl	%eax, %eax
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,15
.globl _GetTotalNelectrons
	.def	_GetTotalNelectrons;	.scl	2;	.type	32;	.endef
_GetTotalNelectrons:
	pushl	%ebp
	movl	_Ncenters, %eax
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	xorl	%ebx, %ebx
	cmpl	%eax, %ebx
	jge	L40
	movl	_GeomOrb, %ecx
	movl	%eax, %edx
	movl	_Type, %esi
	addl	$344, %ecx
	.p2align 4,,15
L38:
	movl	(%ecx), %eax
	sall	$4, %eax
	movl	4(%eax,%esi), %eax
	testl	%eax, %eax
	jle	L36
	addl	%eax, %ebx
L36:
	addl	$400, %ecx
	decl	%edx
	jne	L38
L40:
	movl	%ebx, %eax
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,15
.globl _GetSumAbsCharges
	.def	_GetSumAbsCharges;	.scl	2;	.type	32;	.endef
_GetSumAbsCharges:
	pushl	%ebp
	movl	_Ncenters, %eax
	fldz
	movl	%esp, %ebp
	testl	%eax, %eax
	jle	L47
	movl	_GeomOrb, %edx
	addl	$32, %edx
	.p2align 4,,15
L45:
	fldl	(%edx)
	addl	$400, %edx
	decl	%eax
	fabs
	faddp	%st, %st(1)
	jne	L45
L47:
	popl	%ebp
	ret
