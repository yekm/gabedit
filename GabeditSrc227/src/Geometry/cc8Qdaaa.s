	.file	"GeomZmatrix.c"
	.data
	.align 4
_LineSelectedV:
	.long	-1
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "  <popup name=\"MenuZMatVariables\">\12    <separator name=\"sepMenuPopNew\" />\12    <menuitem name=\"Edit\" action=\"Edit\" />\12    <menuitem name=\"New\" action=\"New\" />\12    <menuitem name=\"Delete\" action=\"Delete\" />\12    <separator name=\"sepMenuPopAll\" />\12    <menuitem name=\"All\" action=\"All\" />\12    <menuitem name=\"One\" action=\"One\" />\12  </popup>\12\0"
	.data
	.align 4
_uiMenuZMatVariablesInfo:
	.long	LC0
	.align 4
_numberOfGtkActionEntriesZMatVariables:
	.long	5
	.section .rdata,"dr"
LC1:
	.ascii "Edit\0"
LC2:
	.ascii "_Edit\0"
LC3:
	.ascii "New\0"
LC4:
	.ascii "gabedit-new\0"
LC5:
	.ascii "_New\0"
LC6:
	.ascii "Delete\0"
LC7:
	.ascii "gabedit-cut\0"
LC8:
	.ascii "_Delete\0"
LC9:
	.ascii "All\0"
LC10:
	.ascii "<=_All\0"
LC11:
	.ascii "<=All\0"
LC12:
	.ascii "One\0"
LC13:
	.ascii "<=_On\0"
LC14:
	.ascii "<=One\0"
	.data
	.align 32
_gtkActionEntriesZMatVariables:
	.long	LC1
	.long	0
	.long	LC2
	.long	0
	.long	LC1
	.long	_activate_action_zmat_variables
	.long	LC3
	.long	LC4
	.long	LC5
	.long	0
	.long	LC3
	.long	_activate_action_zmat_variables
	.long	LC6
	.long	LC7
	.long	LC8
	.long	0
	.long	LC6
	.long	_activate_action_zmat_variables
	.long	LC9
	.long	0
	.long	LC10
	.long	0
	.long	LC11
	.long	_activate_action_zmat_variables
	.long	LC12
	.long	0
	.long	LC13
	.long	0
	.long	LC14
	.long	_activate_action_zmat_variables
	.align 8
_entryWidth:
	.long	-1717986918
	.long	1070176665
	.align 8
_labelWidth:
	.long	858993459
	.long	1069757235
	.align 4
_LineSelectedOld:
	.long	-1
	.align 4
_LineSelected:
	.long	-1
.lcomm _InEdit,16
	.section .rdata,"dr"
	.align 4
LC15:
	.ascii "  <popup name=\"MenuZMatGeom\">\12    <separator name=\"sepMenuPopNew\" />\12    <menuitem name=\"Edit\" action=\"Edit\" />\12    <menuitem name=\"New\" action=\"New\" />\12    <menuitem name=\"Delete\" action=\"Delete\" />\12    <separator name=\"sepMenuPopDraw\" />\12    <menuitem name=\"Draw\" action=\"Draw\" />\12    <separator name=\"sepMenuPopSave\" />\12    <menuitem name=\"Save\" action=\"Save\" />\12    <separator name=\"sepMenuPopSave\" />\12    <menuitem name=\"Save\" action=\"Save\" />\12    <separator name=\"sepMenuPopAll\" />\12    <menuitem name=\"All\" action=\"All\" />\12    <menuitem name=\"AllR\" action=\"AllR\" />\12    <menuitem name=\"AllAngles\" action=\"AllAngles\" />\12    <menuitem name=\"AllDihedrals\" action=\"AllDihedrals\" />\12    <menuitem name=\"One\" action=\"One\" />\12    <separator name=\"sepMenuPopMul\" />\12    <menuitem name=\"MultiplyBya0\" action=\"MultiplyBya0\" />\12    <menuitem name=\"DivideBya0\" action=\"DivideBya0\" />\12    <separator name=\"sepMenuPopZmat\" />\12    <menuitem name=\"ToXYZ\" action=\"ToXYZ\" />\12  </popup>\12\0"
	.data
	.align 4
_uiMenuZMatGeomInfo:
	.long	LC15
	.align 4
_numberOfGtkActionEntriesZMatGeom:
	.long	13
	.section .rdata,"dr"
LC16:
	.ascii "Draw\0"
LC17:
	.ascii "gabedit-draw\0"
LC18:
	.ascii "D_raw\0"
LC19:
	.ascii "Save\0"
LC20:
	.ascii "gabedit-save\0"
LC21:
	.ascii "_Save\0"
LC22:
	.ascii "_All=>\0"
LC23:
	.ascii "All=>\0"
LC24:
	.ascii "AllR\0"
LC25:
	.ascii "All _R =>\0"
LC26:
	.ascii "All R=>\0"
LC27:
	.ascii "AllAngles\0"
LC28:
	.ascii "All _Angles =>\0"
LC29:
	.ascii "All Angles =>\0"
LC30:
	.ascii "AllDihedrals\0"
LC31:
	.ascii "All _Dihedral =>\0"
LC32:
	.ascii "All Dihedral =>\0"
LC33:
	.ascii "_One=>\0"
LC34:
	.ascii "One=>\0"
LC35:
	.ascii "MultiplyBya0\0"
LC36:
	.ascii "gabedit-a0p\0"
LC37:
	.ascii "M_ultiply by a0\0"
LC38:
	.ascii "Multiply by a0\0"
LC39:
	.ascii "DivideBya0\0"
LC40:
	.ascii "gabedit-a0d\0"
LC41:
	.ascii "D_ivide by a0\0"
LC42:
	.ascii "ToXYZ\0"
LC43:
	.ascii "to _XYZ\0"
LC44:
	.ascii "to XYZ\0"
	.data
	.align 32
_gtkActionEntriesZMatGeom:
	.long	LC1
	.long	0
	.long	LC2
	.long	0
	.long	LC1
	.long	_activate_action_xyz_geom
	.long	LC3
	.long	LC4
	.long	LC5
	.long	0
	.long	LC3
	.long	_activate_action_xyz_geom
	.long	LC6
	.long	LC7
	.long	LC8
	.long	0
	.long	LC6
	.long	_activate_action_xyz_geom
	.long	LC16
	.long	LC17
	.long	LC18
	.long	0
	.long	LC16
	.long	_activate_action_xyz_geom
	.long	LC19
	.long	LC20
	.long	LC21
	.long	0
	.long	LC19
	.long	_activate_action_xyz_geom
	.long	LC9
	.long	0
	.long	LC22
	.long	0
	.long	LC23
	.long	_activate_action_xyz_geom
	.long	LC24
	.long	0
	.long	LC25
	.long	0
	.long	LC26
	.long	_activate_action_xyz_geom
	.long	LC27
	.long	0
	.long	LC28
	.long	0
	.long	LC29
	.long	_activate_action_xyz_geom
	.long	LC30
	.long	0
	.long	LC31
	.long	0
	.long	LC32
	.long	_activate_action_xyz_geom
	.long	LC12
	.long	0
	.long	LC33
	.long	0
	.long	LC34
	.long	_activate_action_xyz_geom
	.long	LC35
	.long	LC36
	.long	LC37
	.long	0
	.long	LC38
	.long	_activate_action_xyz_geom
	.long	LC39
	.long	LC40
	.long	LC41
	.long	0
	.long	LC41
	.long	_activate_action_xyz_geom
	.long	LC42
	.long	0
	.long	LC43
	.long	0
	.long	LC44
	.long	_activate_action_xyz_geom
	.text
	.p2align 4,,15
	.def	_clearList;	.scl	3;	.type	32;	.endef
_clearList:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	%eax, %ebx
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, %ebx
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_list_store_clear
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.section .rdata,"dr"
LC45:
	.ascii "%d\0"
	.text
	.p2align 4,,15
	.def	_removeFromList;	.scl	3;	.type	32;	.endef
_removeFromList:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$72, %esp
	movl	%ebx, -12(%ebp)
	testl	%edx, %edx
	movl	%eax, %ebx
	movl	%esi, -8(%ebp)
	movl	%edi, -4(%ebp)
	js	L2
	movl	%edx, 4(%esp)
	leal	-40(%ebp), %esi
	movl	$LC45, (%esp)
	call	_g_strdup_printf
	movl	%eax, -44(%ebp)
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, %ebx
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 4(%esp)
	movl	%eax, %edi
	movl	-44(%ebp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	call	_gtk_tree_model_get_iter_from_string
	testl	%eax, %eax
	jne	L6
L4:
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L2:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L6:
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	_gtk_list_store_remove
	jmp	L4
	.p2align 4,,15
	.def	_insertToList;	.scl	3;	.type	32;	.endef
_insertToList:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	%edx, %edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	%eax, -44(%ebp)
	movl	%edx, %eax
	notl	%eax
	movl	%eax, %esi
	sarl	$31, %esi
	andl	%edx, %esi
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, %ebx
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -48(%ebp)
	leal	-40(%ebp), %edx
	movl	%esi, 8(%esp)
	xorl	%esi, %esi
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_list_store_insert
	jmp	L19
	.p2align 4,,7
L20:
	movl	-44(%ebp), %ecx
	xorl	%ebx, %ebx
	cmpl	_list, %ecx
	sete	%bl
	testl	%esi, %esi
	sete	%al
	xorl	%ecx, %ecx
	testl	%eax, %ebx
	sete	%cl
	testl	%edi, %edi
	setle	%al
	testl	%eax, %ebx
	je	L13
	cmpl	$4, %esi
	setg	%dl
	xorl	%eax, %eax
	cmpl	$10, %esi
	setle	%al
	testl	%edx, %eax
	sete	%al
	movzbl	%al, %eax
	negl	%eax
	andl	%eax, %ecx
L13:
	cmpl	$1, %edi
	setle	%al
	testl	%eax, %ebx
	je	L14
	cmpl	$6, %esi
	setg	%dl
	xorl	%eax, %eax
	cmpl	$10, %esi
	setle	%al
	testl	%edx, %eax
	sete	%al
	movzbl	%al, %eax
	negl	%eax
	andl	%eax, %ecx
L14:
	cmpl	$2, %edi
	setle	%al
	testl	%eax, %ebx
	je	L15
	cmpl	$8, %esi
	setg	%dl
	xorl	%eax, %eax
	cmpl	$10, %esi
	setle	%al
	testl	%edx, %eax
	sete	%al
	movzbl	%al, %eax
	negl	%eax
	andl	%eax, %ecx
L15:
	movl	%ecx, 20(%esp)
	leal	(%esi,%esi), %edx
	movl	8(%ebp), %ecx
	movl	$-1, %eax
	movl	%eax, 24(%esp)
	leal	1(%edx), %eax
	movl	%eax, 16(%esp)
	movl	(%ecx,%esi,4), %eax
	movl	%edx, 8(%esp)
	movl	-48(%ebp), %edx
	movl	%eax, 12(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_gtk_list_store_set
	movl	8(%ebp), %ecx
	movl	(%ecx,%esi,4), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_g_free
L19:
	cmpl	12(%ebp), %esi
	jl	L20
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_appendToList;	.scl	3;	.type	32;	.endef
_appendToList:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$76, %esp
	movl	_NcentersZmat, %edi
	movl	%edx, -48(%ebp)
	movl	%eax, -44(%ebp)
	decl	%edi
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, %ebx
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -52(%ebp)
	leal	-40(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_list_store_append
	jmp	L32
	.p2align 4,,7
L33:
	movl	-44(%ebp), %ecx
	xorl	%ebx, %ebx
	cmpl	_list, %ecx
	sete	%bl
	testl	%esi, %esi
	sete	%al
	xorl	%ecx, %ecx
	testl	%eax, %ebx
	sete	%cl
	testl	%edi, %edi
	setle	%al
	testl	%eax, %ebx
	je	L26
	cmpl	$4, %esi
	setg	%dl
	xorl	%eax, %eax
	cmpl	$10, %esi
	setle	%al
	testl	%edx, %eax
	sete	%al
	movzbl	%al, %eax
	negl	%eax
	andl	%eax, %ecx
L26:
	cmpl	$1, %edi
	setle	%al
	testl	%eax, %ebx
	je	L27
	cmpl	$6, %esi
	setg	%dl
	xorl	%eax, %eax
	cmpl	$10, %esi
	setle	%al
	testl	%edx, %eax
	sete	%al
	movzbl	%al, %eax
	negl	%eax
	andl	%eax, %ecx
L27:
	cmpl	$2, %edi
	setle	%al
	testl	%eax, %ebx
	je	L28
	cmpl	$8, %esi
	setg	%dl
	xorl	%eax, %eax
	cmpl	$10, %esi
	setle	%al
	testl	%edx, %eax
	sete	%al
	movzbl	%al, %eax
	negl	%eax
	andl	%eax, %ecx
L28:
	movl	%ecx, 20(%esp)
	movl	$-1, %edx
	movl	-48(%ebp), %ecx
	movl	%edx, 24(%esp)
	leal	(%esi,%esi), %edx
	leal	1(%edx), %eax
	movl	%eax, 16(%esp)
	movl	(%ecx,%esi,4), %eax
	movl	%edx, 8(%esp)
	movl	-52(%ebp), %edx
	movl	%eax, 12(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_gtk_list_store_set
	movl	-48(%ebp), %ecx
	movl	(%ecx,%esi,4), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_g_free
L32:
	cmpl	8(%ebp), %esi
	jl	L33
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC46:
	.ascii " \0"
	.text
	.p2align 4,,15
	.def	_append_list_geom;	.scl	3;	.type	32;	.endef
_append_list_geom:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$140, %esp
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	_list, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, %ebx
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	cmpl	_NcentersZmat, %esi
	movl	%eax, %edi
	jae	L57
L64:
	xorl	%ebx, %ebx
	.p2align 4,,15
L41:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -104(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jbe	L41
	cmpl	$1, %esi
	je	L44
	jb	L43
	cmpl	$2, %esi
	je	L45
	movl	$LC45, (%esp)
	leal	1(%esi), %eax
	leal	0(,%esi,8), %ebx
	movl	%eax, -108(%ebp)
	subl	%esi, %ebx
	sall	$3, %ebx
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -104(%ebp)
	movl	_Geom, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -100(%ebp)
	movl	_Geom, %eax
	movl	8(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -96(%ebp)
	movl	_Geom, %eax
	movl	12(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -92(%ebp)
	movl	_Geom, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp)
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -84(%ebp)
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -80(%ebp)
	movl	_Geom, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -76(%ebp)
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp)
	movl	_Geom, %eax
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -68(%ebp)
	movl	_Geom, %eax
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -64(%ebp)
L63:
	movl	_Geom, %eax
	movl	48(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -60(%ebp)
	movl	_Geom, %eax
	movl	52(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -56(%ebp)
L42:
	movl	%edi, (%esp)
	leal	-40(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, 4(%esp)
	call	_gtk_list_store_append
	.p2align 4,,15
L54:
	xorl	%ecx, %ecx
	testl	%ebx, %ebx
	setne	%cl
	testl	%esi, %esi
	sete	%dl
	xorl	%eax, %eax
	cmpl	$4, %ebx
	setg	%al
	testl	%edx, %eax
	je	L51
	xorl	%eax, %eax
	cmpl	$10, %ebx
	setg	%al
	negl	%eax
	andl	%eax, %ecx
L51:
	cmpl	$1, %esi
	setbe	%al
	xorl	%edx, %edx
	cmpl	$6, %ebx
	setg	%dl
	testl	%eax, %edx
	je	L52
	xorl	%eax, %eax
	cmpl	$10, %ebx
	setg	%al
	negl	%eax
	andl	%eax, %ecx
L52:
	cmpl	$2, %esi
	setbe	%al
	xorl	%edx, %edx
	cmpl	$8, %ebx
	setg	%dl
	testl	%eax, %edx
	je	L53
	xorl	%eax, %eax
	cmpl	$10, %ebx
	setg	%al
	negl	%eax
	andl	%eax, %ecx
L53:
	movl	%ecx, 20(%esp)
	leal	(%ebx,%ebx), %edx
	movl	$-1, %eax
	movl	%eax, 24(%esp)
	leal	1(%edx), %eax
	movl	%eax, 16(%esp)
	movl	-104(%ebp,%ebx,4), %eax
	movl	%edx, 8(%esp)
	movl	%edi, (%esp)
	movl	%eax, 12(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gtk_list_store_set
	movl	-104(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$12, %ebx
	jle	L54
	movl	-108(%ebp), %esi
	cmpl	_NcentersZmat, %esi
	jb	L64
L57:
	addl	$140, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L43:
	movl	$LC45, (%esp)
	leal	1(%esi), %eax
	leal	0(,%esi,8), %ebx
	movl	%eax, -108(%ebp)
	subl	%esi, %ebx
	sall	$3, %ebx
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -104(%ebp)
	movl	_Geom, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -100(%ebp)
	movl	_Geom, %eax
	movl	8(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -96(%ebp)
	movl	_Geom, %eax
	movl	12(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -92(%ebp)
	movl	_Geom, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp)
	jmp	L63
L44:
	movl	$LC45, (%esp)
	movl	$2, %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -104(%ebp)
	movl	_Geom, %eax
	movl	60(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -100(%ebp)
	movl	_Geom, %eax
	movl	64(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -96(%ebp)
	movl	_Geom, %eax
	movl	68(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -92(%ebp)
	movl	_Geom, %eax
	movl	72(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp)
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -84(%ebp)
	movl	_Geom, %eax
	movl	84(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -80(%ebp)
	movl	_Geom, %eax
	movl	104(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -60(%ebp)
	movl	_Geom, %eax
	movl	108(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -56(%ebp)
	movl	$2, -108(%ebp)
	jmp	L42
L45:
	movl	$LC45, (%esp)
	movl	$3, %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -104(%ebp)
	movl	_Geom, %eax
	movl	116(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -100(%ebp)
	movl	_Geom, %eax
	movl	120(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -96(%ebp)
	movl	_Geom, %eax
	movl	124(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -92(%ebp)
	movl	_Geom, %eax
	movl	128(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp)
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -84(%ebp)
	movl	_Geom, %eax
	movl	140(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -80(%ebp)
	movl	_Geom, %eax
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -76(%ebp)
	movl	_Geom, %eax
	movl	148(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp)
	movl	_Geom, %eax
	movl	160(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -60(%ebp)
	movl	_Geom, %eax
	movl	164(%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -56(%ebp)
	movl	$3, -108(%ebp)
	jmp	L42
	.p2align 4,,15
	.def	_TestVariablesCreated;	.scl	3;	.type	32;	.endef
_TestVariablesCreated:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	xorl	%ebx, %ebx
	movl	%eax, -16(%ebp)
	movl	_NVariables, %edi
	movl	%edx, -20(%ebp)
	movl	$0, -24(%ebp)
	cmpl	%edi, %ebx
	jae	L67
	movl	_Variables, %eax
	xorl	%esi, %esi
	movl	%eax, -28(%ebp)
	.p2align 4,,15
L71:
	cmpl	-20(%ebp), %ebx
	je	L68
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-28(%ebp), %edx
	movl	(%esi,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L73
L68:
	incl	%ebx
	addl	$12, %esi
	cmpl	%edi, %ebx
	jb	L71
L67:
	movl	-24(%ebp), %eax
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L73:
	movl	$1, -24(%ebp)
	movl	-24(%ebp), %eax
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC47:
	.ascii "NumColumn\0"
	.align 4
LC49:
	.ascii "Sorry a other variable have any Name !\12\0"
LC48:
	.ascii " Error \0"
LC51:
	.ascii "%s.0\0"
LC50:
	.ascii "Sorry %s is not a number \12\0"
	.text
	.p2align 4,,15
	.def	_editedVariable;	.scl	3;	.type	32;	.endef
_editedVariable:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	$-1, %ebx
	call	_gtk_tree_model_get_type
	movl	%eax, 4(%esp)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %edi
	movl	8(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC47, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -44(%ebp)
	testl	%eax, %eax
	movl	$0, -48(%ebp)
	je	L105
	cmpl	$1, -44(%ebp)
	je	L106
L79:
	testl	%ebx, %ebx
	js	L74
	movl	-44(%ebp), %ecx
	testl	%ecx, %ecx
	je	L107
	cmpl	$1, -44(%ebp)
	je	L108
L85:
	movl	12(%ebp), %edx
	leal	-40(%ebp), %ebx
	movl	%edx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	%eax, %esi
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$-1, %edx
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	-44(%ebp), %edx
	addl	%edx, %edx
	movl	%edx, 8(%esp)
	call	_gtk_list_store_set
	movl	%esi, (%esp)
	call	_gtk_tree_path_free
	movl	-44(%ebp), %eax
	testl	%eax, %eax
	sete	%dl
	xorl	%eax, %eax
	cmpl	$0, -48(%ebp)
	setne	%al
	testl	%edx, %eax
	je	L87
	movl	$-1, -52(%ebp)
	xorl	%esi, %esi
	cmpl	_NcentersZmat, %esi
	jae	L99
	xorl	%edi, %edi
	jmp	L97
	.p2align 4,,7
L92:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 24(%edi,%ebx)
	movl	$0, -52(%ebp)
L91:
	cmpl	$1, %esi
	jle	L93
	movl	-48(%ebp), %eax
	movl	_Geom, %ebx
	movl	%eax, 4(%esp)
	movl	32(%edi,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L93
	movl	32(%edi,%ebx), %eax
	testl	%eax, %eax
	jne	L109
L94:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 32(%edi,%ebx)
	movl	$0, -52(%ebp)
	.p2align 4,,15
L93:
	cmpl	$2, %esi
	jle	L90
	movl	-48(%ebp), %eax
	movl	_Geom, %ebx
	movl	%eax, 4(%esp)
	movl	40(%edi,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L90
	movl	40(%edi,%ebx), %eax
	testl	%eax, %eax
	jne	L110
L96:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 40(%edi,%ebx)
	movl	$0, -52(%ebp)
	.p2align 4,,15
L90:
	incl	%esi
	addl	$56, %edi
	cmpl	_NcentersZmat, %esi
	jae	L111
L97:
	testl	%esi, %esi
	jle	L91
	movl	-48(%ebp), %eax
	movl	_Geom, %ebx
	movl	%eax, 4(%esp)
	movl	24(%edi,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L91
	movl	24(%edi,%ebx), %eax
	testl	%eax, %eax
	je	L92
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L92
	.p2align 4,,7
L111:
	movl	-52(%ebp), %eax
	testl	%eax, %eax
	jne	L99
	movl	_list, %eax
	call	_clearList
	call	_append_list_geom
	.p2align 4,,15
L99:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L87:
	cmpl	$1, -44(%ebp)
	jne	L74
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L74
	call	_rafresh_drawing
	.p2align 4,,15
L74:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L105:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_variable_name_valid
	testl	%eax, %eax
	je	L112
	movl	16(%ebp), %edx
	cmpb	$0, (%edx)
	je	L74
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %edx
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	call	_TestVariablesCreated
	testl	%eax, %eax
	je	L79
	movl	$LC49, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	call	_MessageGeom
	jmp	L74
	.p2align 4,,7
L107:
	movl	_Variables, %esi
	leal	(%ebx,%ebx,2), %ebx
	sall	$2, %ebx
	movl	16(%ebp), %edx
	movl	(%ebx,%esi), %eax
	movl	%edx, (%esp)
	movl	%eax, -48(%ebp)
	call	_g_strdup
	movl	%eax, (%ebx,%esi)
	jmp	L85
L109:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L94
L110:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L96
L108:
	movl	_Variables, %esi
	leal	(%ebx,%ebx,2), %eax
	leal	0(,%eax,4), %ebx
	movl	4(%ebx,%esi), %eax
	testl	%eax, %eax
	jne	L113
L86:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx,%esi)
	jmp	L85
L106:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	je	L114
	movl	16(%ebp), %edx
	cmpb	$0, (%edx)
	je	L74
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	16(%ebp), %edx
	movl	%eax, %ebx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	je	L79
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L79
	movl	$LC51, (%esp)
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 16(%ebp)
	jmp	L79
	.p2align 4,,7
L112:
	call	_show_forbidden_characters
	jmp	L74
L113:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Variables, %esi
	jmp	L86
L114:
	movl	$LC50, (%esp)
	movl	16(%ebp), %eax
	movl	$1, %edi
	movl	$LC48, %esi
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	%eax, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	jmp	L74
	.section .rdata,"dr"
LC53:
	.ascii "%f\0"
	.align 4
LC56:
	.ascii "Warning : rbc < 0.0001 in get_distance_zmatrix\0"
	.align 8
LC54:
	.long	-1433277178
	.long	1066524486
	.align 8
LC55:
	.long	-350469331
	.long	1058682594
	.align 8
LC58:
	.long	-417264663
	.long	1072693245
	.align 8
LC59:
	.long	-1717986918
	.long	1069128089
	.align 8
LC60:
	.long	-640172613
	.long	1037794527
	.text
	.p2align 4,,15
	.def	_get_distance_zmatrix;	.scl	3;	.type	32;	.endef
_get_distance_zmatrix:
	pushl	%ebp
	xorl	%ecx, %ecx
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$300, %esp
	movl	%edx, -32(%ebp)
	movl	%edx, -188(%ebp)
	movl	_NcentersZmat, %edx
	movl	%eax, -28(%ebp)
	cmpl	$1, %edx
	jbe	L115
	testl	%eax, %eax
	js	L115
	movl	-32(%ebp), %esi
	testl	%esi, %esi
	js	L115
	movl	-32(%ebp), %eax
	cmpl	%eax, -28(%ebp)
	jg	L183
L119:
	leal	-1(%edx), %eax
	xorl	%ecx, %ecx
	cmpl	%eax, -188(%ebp)
	ja	L115
	leal	0(,%edx,8), %eax
	xorl	%esi, %esi
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -176(%ebp)
	movl	_NcentersZmat, %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -180(%ebp)
	movl	_NcentersZmat, %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -184(%ebp)
	movl	_NcentersZmat, %eax
	cmpl	$0, %eax
	jmp	L176
	.p2align 4,,7
L184:
	movl	-184(%ebp), %edx
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
	xorl	%edi, %edi
	movl	$0, (%edx,%esi,8)
	movl	%ebx, 4(%edx,%esi,8)
	movl	-180(%ebp), %edx
	movl	$0, (%edx,%esi,8)
	movl	%ecx, 4(%edx,%esi,8)
	movl	-176(%ebp), %edx
	movl	$0, (%edx,%esi,8)
	movl	%edi, 4(%edx,%esi,8)
	incl	%esi
	cmpl	%esi, %eax
L176:
	jg	L184
	movl	-176(%ebp), %eax
	movl	-180(%ebp), %edx
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movl	-184(%ebp), %eax
	movl	$0, (%edx)
	movl	$0, 4(%edx)
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L125
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
	movl	-176(%ebp), %edx
	fstpl	8(%edx)
L126:
	cmpl	$2, _NcentersZmat
	fldz
	movl	-180(%ebp), %edx
	movl	-184(%ebp), %eax
	fstl	8(%edx)
	sete	%dl
	fstpl	8(%eax)
	xorl	%eax, %eax
	cmpl	$1, -188(%ebp)
	setle	%al
	testl	%edx, %eax
	je	L127
	movl	-176(%ebp), %edx
	fldl	8(%edx)
	movl	%edx, (%esp)
	fstpl	-200(%ebp)
	call	_g_free
	movl	-180(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-184(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	fldl	-200(%ebp)
L182:
	fstpl	4(%esp)
	movl	$LC53, (%esp)
	call	_g_strdup_printf
	movl	%eax, %ecx
L115:
	addl	$300, %esp
	movl	%ecx, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L183:
	movl	-28(%ebp), %eax
	movl	%eax, -188(%ebp)
	jmp	L119
L125:
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	-176(%ebp), %eax
	fstpl	8(%eax)
	jmp	L126
L127:
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L128
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
	movl	_Geom, %eax
	fstpl	-72(%ebp)
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L130
L199:
	movl	_Geom, %eax
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L178:
	fstpl	-80(%ebp)
	fldl	-80(%ebp)
	fmull	LC54
	fstl	-80(%ebp)
	fstpl	(%esp)
	call	_cos
	fstpl	-56(%ebp)
	fldl	-80(%ebp)
	fstpl	(%esp)
	call	_sin
	movl	_Geom, %eax
	fstpl	-64(%ebp)
	movl	148(%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	$2, %eax
	je	L185
	fldl	-56(%ebp)
	movl	-176(%ebp), %eax
	fmull	-72(%ebp)
	fstl	-56(%ebp)
	fsubrl	8(%eax)
L195:
	fstpl	16(%eax)
	fldl	-64(%ebp)
	movl	-180(%ebp), %eax
	movl	-184(%ebp), %edx
	fmull	-72(%ebp)
	cmpl	$2, -188(%ebp)
	fstpl	16(%eax)
	fldz
	fstpl	16(%edx)
	jg	L134
	movl	-176(%ebp), %edx
	movl	-32(%ebp), %eax
	fldl	(%edx,%eax,8)
	movl	-28(%ebp), %eax
	fldl	(%edx,%eax,8)
	movl	-180(%ebp), %eax
	movl	-32(%ebp), %edx
	fsubp	%st, %st(1)
	fldl	(%eax,%edx,8)
	fxch	%st(1)
	movl	-28(%ebp), %edx
	fmul	%st(0), %st
	fxch	%st(1)
	fsubrl	(%eax,%edx,8)
	movl	-32(%ebp), %eax
	movl	-184(%ebp), %edx
	fmul	%st(0), %st
	faddp	%st, %st(1)
	fldl	(%edx,%eax,8)
	movl	-28(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	fmul	%st(0), %st
	faddp	%st, %st(1)
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	fstpl	-208(%ebp)
	sahf
	jp	L172
	jne	L172
	fstp	%st(0)
L135:
	movl	-176(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	-180(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-184(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	fldl	-208(%ebp)
	jmp	L182
L128:
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_Geom, %eax
	fstpl	-72(%ebp)
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L199
L130:
	movl	_Geom, %eax
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L178
L134:
	cmpl	$3, _NcentersZmat
	movl	$3, %esi
	jle	L137
	movl	$168, %ebx
	movl	%ebx, -236(%ebp)
	jmp	L161
L200:
	movl	-236(%ebp), %edx
	movl	_Geom, %eax
	movl	24(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_Geom, %eax
	movl	-236(%ebp), %edx
	fstpl	-72(%ebp)
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L142
L201:
	movl	-236(%ebp), %edx
	movl	_Geom, %eax
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
	movl	_Geom, %eax
	movl	-236(%ebp), %edx
	fstpl	-80(%ebp)
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L144
L202:
	movl	_Geom, %eax
	movl	-236(%ebp), %edx
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L181:
	fstpl	-88(%ebp)
	movl	-236(%ebp), %edx
	movl	_Geom, %eax
	fldl	LC54
	fldl	-80(%ebp)
	movl	28(%edx,%eax), %eax
	fmul	%st(1), %st
	fxch	%st(1)
	movl	%eax, (%esp)
	fmull	-88(%ebp)
	fxch	%st(1)
	fstpl	-80(%ebp)
	fstpl	-88(%ebp)
	call	_atoi
	leal	-1(%eax), %edi
	movl	-236(%ebp), %edx
	movl	_Geom, %eax
	movl	36(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %ebx
	movl	-236(%ebp), %edx
	movl	_Geom, %eax
	decl	%ebx
	movl	44(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	decl	%eax
	movl	-180(%ebp), %edx
	movl	%eax, -172(%ebp)
	movl	-176(%ebp), %eax
	fldl	(%eax,%edi,8)
	fsubrl	(%eax,%ebx,8)
	movl	-184(%ebp), %eax
	fstpl	-120(%ebp)
	fldl	(%edx,%edi,8)
	fsubrl	(%edx,%ebx,8)
	fstpl	-128(%ebp)
	fldl	(%eax,%edi,8)
	fsubrl	(%eax,%ebx,8)
	fldl	-128(%ebp)
	fmul	%st(0), %st
	fxch	%st(1)
	fstpl	-136(%ebp)
	fldl	-120(%ebp)
	fmul	%st(0), %st
	fxch	%st(1)
	fstl	-232(%ebp)
	fxch	%st(1)
	fstl	-224(%ebp)
	faddp	%st, %st(1)
	fstpl	-144(%ebp)
	fldl	-136(%ebp)
	fmul	%st(0), %st
	faddl	-144(%ebp)
	fstpl	-144(%ebp)
	fldl	-144(%ebp)
	fldl	LC55
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	ja	L167
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L191
	jne	L191
	fstp	%st(1)
L148:
	fld1
	fdivp	%st, %st(1)
	fldl	-80(%ebp)
	fxch	%st(1)
	fstpl	-144(%ebp)
	fstpl	(%esp)
	call	_cos
	fldl	-80(%ebp)
	fxch	%st(1)
	fstpl	-56(%ebp)
	fstpl	(%esp)
	call	_sin
	fldl	-56(%ebp)
	fxch	%st(1)
	fstpl	-64(%ebp)
	fldl	LC58
	fxch	%st(1)
	fabs
	fucompp
	fnstsw	%ax
	sahf
	jb	L149
	fldl	-72(%ebp)
	movl	-176(%ebp), %eax
	movl	-184(%ebp), %edx
	fmull	-144(%ebp)
	fldl	-120(%ebp)
	fxch	%st(1)
	fmull	-56(%ebp)
	fmul	%st, %st(1)
	fxch	%st(1)
	faddl	(%eax,%edi,8)
	fstpl	(%eax,%esi,8)
	movl	-180(%ebp), %eax
	fldl	-128(%ebp)
	fmul	%st(1), %st
	fxch	%st(1)
	fmull	-136(%ebp)
	fxch	%st(1)
L198:
	faddl	(%eax,%edi,8)
	fstpl	(%eax,%esi,8)
	faddl	(%edx,%edi,8)
	fstpl	(%edx,%esi,8)
L138:
	addl	$56, -236(%ebp)
	incl	%esi
	cmpl	%esi, _NcentersZmat
	jle	L137
L161:
	cmpl	-188(%ebp), %esi
	jg	L137
	movl	_Geom, %eax
	movl	-236(%ebp), %edx
	movl	24(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L200
	movl	-236(%ebp), %edx
	movl	_Geom, %eax
	movl	24(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
	movl	_Geom, %eax
	movl	-236(%ebp), %edx
	fstpl	-72(%ebp)
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L201
L142:
	movl	-236(%ebp), %edx
	movl	_Geom, %eax
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_Geom, %eax
	movl	-236(%ebp), %edx
	fstpl	-80(%ebp)
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L202
L144:
	movl	-236(%ebp), %edx
	movl	_Geom, %eax
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L181
L149:
	movl	-176(%ebp), %eax
	movl	-172(%ebp), %edx
	fldl	(%eax,%edi,8)
	fsubrl	(%eax,%edx,8)
	movl	-180(%ebp), %eax
	fstpl	-96(%ebp)
	fldl	(%eax,%edi,8)
	fsubrl	(%eax,%edx,8)
	movl	-184(%ebp), %edx
	movl	-172(%ebp), %eax
	fstpl	-104(%ebp)
	fldl	(%edx,%edi,8)
	fsubrl	(%edx,%eax,8)
	fstpl	-112(%ebp)
	fldl	-88(%ebp)
	fstpl	(%esp)
	call	_sin
	fldl	-88(%ebp)
	fxch	%st(1)
	fstpl	-168(%ebp)
	xorb	$-128, -161(%ebp)
	fstpl	(%esp)
	call	_cos
	fstpl	-160(%ebp)
	fldl	-72(%ebp)
	fmull	-56(%ebp)
	fldl	-160(%ebp)
	fxch	%st(1)
	fstpl	-152(%ebp)
	fldl	-72(%ebp)
	fmull	-64(%ebp)
	fmul	%st, %st(1)
	fmull	-168(%ebp)
	fxch	%st(1)
	fstpl	-160(%ebp)
	fldl	-224(%ebp)
	faddl	-232(%ebp)
	fxch	%st(1)
	fstpl	-168(%ebp)
	fldl	LC59
	fxch	%st(1)
	fsqrt
	fxch	%st(1)
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	jbe	L152
	fstp	%st(0)
	fldl	-112(%ebp)
	movl	$1, %ebx
	movl	-96(%ebp), %eax
	movl	-92(%ebp), %edx
	fstpl	-96(%ebp)
	xorl	$-2147483648, %edx
	fldl	-136(%ebp)
	movl	%edx, -108(%ebp)
	movl	-116(%ebp), %edx
	fld	%st(0)
	movl	%eax, -112(%ebp)
	fmul	%st(1), %st
	fxch	%st(1)
	movl	-120(%ebp), %eax
	fstpl	-120(%ebp)
	xorl	$-2147483648, %edx
	movl	%edx, -132(%ebp)
	faddl	-232(%ebp)
	movl	%eax, -136(%ebp)
	fsqrt
L154:
	fldl	-120(%ebp)
	fldl	-136(%ebp)
	fmull	-144(%ebp)
	fxch	%st(1)
	fdiv	%st(2), %st
	fld	%st(0)
	fxch	%st(3)
	fdivrl	-128(%ebp)
	fxch	%st(1)
	fstpl	-40(%ebp)
	fld	%st(0)
	fmull	-104(%ebp)
	fxch	%st(3)
	fmull	-96(%ebp)
	fldl	-40(%ebp)
	fxch	%st(2)
	fstl	-48(%ebp)
	fxch	%st(2)
	fmull	-104(%ebp)
	fxch	%st(1)
	faddp	%st, %st(4)
	fld	%st(2)
	fxch	%st(2)
	fmull	-96(%ebp)
	fxch	%st(2)
	fmul	%st(3), %st
	fxch	%st(1)
	fsubp	%st, %st(2)
	fld1
	fsubp	%st, %st(1)
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L193
	jne	L193
	fstp	%st(1)
L155:
	fldl	-112(%ebp)
	fxch	%st(4)
	fmul	%st(3), %st
	fxch	%st(4)
	fmul	%st(1), %st
	fld	%st(2)
	fmul	%st(3), %st
	fxch	%st(1)
	fsubp	%st, %st(5)
	fld	%st(4)
	fmul	%st(5), %st
	faddp	%st, %st(1)
	fldl	LC60
	fxch	%st(1)
	fsqrt
	fucom	%st(1)
	fnstsw	%ax
	fstp	%st(1)
	sahf
	jbe	L156
	fldl	-160(%ebp)
	fxch	%st(3)
	fdiv	%st(1), %st
	fldl	-168(%ebp)
	fxch	%st(2)
	fdivrp	%st, %st(6)
	fmul	%st, %st(3)
	fmull	-168(%ebp)
	fxch	%st(1)
	fmul	%st(5), %st
	fxch	%st(5)
	fmull	-160(%ebp)
	fxch	%st(3)
	fsubp	%st, %st(5)
	faddp	%st, %st(2)
L158:
	fldl	-152(%ebp)
	testl	%ebx, %ebx
	fld	%st(3)
	fldl	-40(%ebp)
	fxch	%st(1)
	fmul	%st(4), %st
	fxch	%st(2)
	fmul	%st(3), %st
	fxch	%st(5)
	fmull	-152(%ebp)
	fxch	%st(5)
	fsubp	%st, %st(2)
	fldl	-48(%ebp)
	fxch	%st(3)
	fmulp	%st, %st(4)
	fmul	%st(1), %st
	fldl	-40(%ebp)
	fxch	%st(3)
	fmul	%st(6), %st
	fxch	%st(3)
	fmulp	%st, %st(6)
	fxch	%st(1)
	fmull	-48(%ebp)
	fxch	%st(3)
	faddp	%st, %st(4)
	fsubp	%st, %st(1)
	fxch	%st(3)
	faddp	%st, %st(1)
	je	L159
	movl	-176(%ebp), %edx
	movl	-180(%ebp), %eax
	fldl	(%edx,%edi,8)
	fsubp	%st, %st(2)
	fxch	%st(1)
	fstpl	(%edx,%esi,8)
	movl	-184(%ebp), %edx
	jmp	L198
L159:
	fxch	%st(2)
	movl	-176(%ebp), %eax
	movl	-180(%ebp), %edx
	faddl	(%eax,%edi,8)
	fstpl	(%eax,%esi,8)
	fxch	%st(1)
	movl	-184(%ebp), %eax
	faddl	(%edx,%edi,8)
	fstpl	(%edx,%esi,8)
	faddl	(%eax,%edi,8)
	fstpl	(%eax,%esi,8)
	jmp	L138
L156:
	fstp	%st(0)
	fstp	%st(1)
	fstp	%st(2)
	fldl	-160(%ebp)
	fldl	-168(%ebp)
	fxch	%st(1)
	fxch	%st(3)
	jmp	L158
L152:
	xorl	%ebx, %ebx
	jmp	L154
L137:
	movl	-176(%ebp), %eax
	movl	-32(%ebp), %edx
	fldl	(%eax,%edx,8)
	movl	-28(%ebp), %edx
	fldl	(%eax,%edx,8)
	movl	-180(%ebp), %edx
	movl	-32(%ebp), %eax
	fsubp	%st, %st(1)
	fldl	(%edx,%eax,8)
	fxch	%st(1)
	movl	-28(%ebp), %eax
	fmul	%st(0), %st
	fxch	%st(1)
	fsubrl	(%edx,%eax,8)
	movl	-184(%ebp), %eax
	movl	-32(%ebp), %edx
	fmul	%st(0), %st
	faddp	%st, %st(1)
	fldl	(%eax,%edx,8)
	movl	-28(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	fmul	%st(0), %st
	faddp	%st, %st(1)
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	fstpl	-216(%ebp)
	sahf
	jp	L175
	jne	L175
	fstp	%st(0)
L162:
	movl	-176(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	-180(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-184(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	fldl	-216(%ebp)
	jmp	L182
L185:
	fldl	-56(%ebp)
	movl	-176(%ebp), %eax
	fmull	-72(%ebp)
	faddl	(%eax)
	jmp	L195
L191:
	fstp	%st(0)
	fstpl	(%esp)
	call	_sqrt
	jmp	L148
L193:
	fstp	%st(0)
	fxch	%st(3)
	fstpl	-264(%ebp)
	fxch	%st(1)
	fstpl	-280(%ebp)
	fstpl	-296(%ebp)
	fstpl	(%esp)
	call	_sqrt
	fldl	-296(%ebp)
	fldl	-280(%ebp)
	fldl	-264(%ebp)
	fxch	%st(3)
	fxch	%st(1)
	fxch	%st(2)
	fxch	%st(1)
	jmp	L155
L172:
	fstpl	(%esp)
	call	_sqrt
	fstpl	-208(%ebp)
	jmp	L135
L175:
	fstpl	(%esp)
	call	_sqrt
	fstpl	-216(%ebp)
	jmp	L162
L167:
	fstp	%st(0)
	movl	-176(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-180(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	-184(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	$LC56, (%esp)
	call	_puts
	xorl	%ecx, %ecx
	jmp	L115
	.section .rdata,"dr"
	.align 8
LC65:
	.long	-1433277178
	.long	1066524486
	.align 8
LC66:
	.long	-350469331
	.long	1058682594
	.align 8
LC68:
	.long	-417264663
	.long	1072693245
	.align 8
LC69:
	.long	-1717986918
	.long	1069128089
	.align 8
LC70:
	.long	-640172613
	.long	1037794527
	.text
	.p2align 4,,15
	.def	_get_angle_zmatrix;	.scl	3;	.type	32;	.endef
_get_angle_zmatrix:
	pushl	%ebp
	xorl	%ecx, %ecx
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$364, %esp
	movl	%edx, -96(%ebp)
	movl	_NcentersZmat, %edx
	movl	%eax, -92(%ebp)
	movl	8(%ebp), %eax
	cmpl	$1, %edx
	movl	%eax, -252(%ebp)
	jbe	L203
	movl	-92(%ebp), %ebx
	testl	%ebx, %ebx
	js	L203
	movl	-96(%ebp), %edi
	testl	%edi, %edi
	js	L203
	testl	%eax, %eax
	js	L203
	cmpl	%eax, -92(%ebp)
	jg	L267
L208:
	movl	-252(%ebp), %eax
	cmpl	%eax, -96(%ebp)
	jle	L209
	movl	-96(%ebp), %eax
	movl	%eax, -252(%ebp)
L209:
	leal	-1(%edx), %eax
	xorl	%ecx, %ecx
	cmpl	%eax, -252(%ebp)
	ja	L203
	leal	0(,%edx,8), %eax
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -240(%ebp)
	movl	_NcentersZmat, %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -244(%ebp)
	movl	_NcentersZmat, %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -248(%ebp)
	movl	_NcentersZmat, %eax
	cmpl	$0, %eax
	jmp	L259
	.p2align 4,,7
L268:
	movl	-248(%ebp), %edx
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
	movl	$0, (%edx,%edi,8)
	movl	%esi, 4(%edx,%edi,8)
	movl	-244(%ebp), %edx
	movl	$0, (%edx,%edi,8)
	movl	%ebx, 4(%edx,%edi,8)
	movl	-240(%ebp), %edx
	movl	$0, (%edx,%edi,8)
	movl	%ecx, 4(%edx,%edi,8)
	incl	%edi
	cmpl	%edi, %eax
L259:
	jg	L268
	movl	-240(%ebp), %eax
	movl	-244(%ebp), %edx
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movl	-248(%ebp), %eax
	movl	$0, (%edx)
	movl	$0, 4(%edx)
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L215
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
	movl	-240(%ebp), %edx
	fstpl	8(%edx)
L216:
	movl	-248(%ebp), %eax
	fldz
	movl	-244(%ebp), %edx
	fstl	8(%edx)
	fstpl	8(%eax)
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L217
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L260:
	fstpl	-136(%ebp)
	movl	_Geom, %eax
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L219
	movl	_Geom, %eax
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L261:
	fstpl	-144(%ebp)
	fldl	-144(%ebp)
	fmull	LC65
	fstl	-144(%ebp)
	fstpl	(%esp)
	call	_cos
	fldl	-144(%ebp)
	fxch	%st(1)
	fstpl	-120(%ebp)
	fstpl	(%esp)
	call	_sin
	movl	_Geom, %eax
	fstpl	-128(%ebp)
	movl	148(%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	$2, %eax
	je	L269
	fldl	-120(%ebp)
	movl	-240(%ebp), %eax
	fmull	-136(%ebp)
	fstl	-120(%ebp)
	fsubrl	8(%eax)
L262:
	fstpl	16(%eax)
	movl	-244(%ebp), %eax
	movl	-248(%ebp), %edx
	fldl	-128(%ebp)
	fmull	-136(%ebp)
	cmpl	$2, -252(%ebp)
	fstpl	16(%eax)
	fldz
	fstpl	16(%edx)
	jle	L270
	cmpl	$3, _NcentersZmat
	movl	$3, %edi
	jle	L225
	movl	$168, %eax
	movl	%eax, -276(%ebp)
	jmp	L249
	.p2align 4,,7
L281:
	movl	-276(%ebp), %edx
	movl	_Geom, %eax
	movl	24(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_Geom, %eax
	movl	-276(%ebp), %edx
	fstpl	-136(%ebp)
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L230
L282:
	movl	-276(%ebp), %edx
	movl	_Geom, %eax
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
	movl	_Geom, %eax
	movl	-276(%ebp), %edx
	fstpl	-144(%ebp)
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L232
L283:
	movl	_Geom, %eax
	movl	-276(%ebp), %edx
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L265:
	fstpl	-152(%ebp)
	movl	-276(%ebp), %edx
	movl	_Geom, %eax
	fldl	LC65
	fldl	-144(%ebp)
	movl	28(%edx,%eax), %eax
	fmul	%st(1), %st
	fxch	%st(1)
	movl	%eax, (%esp)
	fmull	-152(%ebp)
	fxch	%st(1)
	fstpl	-144(%ebp)
	fstpl	-152(%ebp)
	call	_atoi
	leal	-1(%eax), %esi
	movl	-276(%ebp), %edx
	movl	_Geom, %eax
	movl	36(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %ebx
	movl	-276(%ebp), %edx
	movl	_Geom, %eax
	decl	%ebx
	movl	44(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	decl	%eax
	movl	-244(%ebp), %edx
	movl	%eax, -236(%ebp)
	movl	-240(%ebp), %eax
	fldl	(%eax,%esi,8)
	fsubrl	(%eax,%ebx,8)
	movl	-248(%ebp), %eax
	fstpl	-184(%ebp)
	fldl	(%edx,%esi,8)
	fsubrl	(%edx,%ebx,8)
	fstpl	-192(%ebp)
	fldl	(%eax,%esi,8)
	fsubrl	(%eax,%ebx,8)
	fldl	-192(%ebp)
	fmul	%st(0), %st
	fxch	%st(1)
	fstpl	-200(%ebp)
	fldl	-184(%ebp)
	fmul	%st(0), %st
	fxch	%st(1)
	fstl	-272(%ebp)
	fxch	%st(1)
	fstl	-264(%ebp)
	faddp	%st, %st(1)
	fstpl	-208(%ebp)
	fldl	-200(%ebp)
	fmul	%st(0), %st
	faddl	-208(%ebp)
	fstpl	-208(%ebp)
	fldl	-208(%ebp)
	fldl	LC66
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	ja	L254
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L275
	jne	L275
	fstp	%st(1)
L236:
	fld1
	fdivp	%st, %st(1)
	fldl	-144(%ebp)
	fxch	%st(1)
	fstpl	-208(%ebp)
	fstpl	(%esp)
	call	_cos
	fldl	-144(%ebp)
	fxch	%st(1)
	fstpl	-120(%ebp)
	fstpl	(%esp)
	call	_sin
	fldl	-120(%ebp)
	fxch	%st(1)
	fstpl	-128(%ebp)
	fldl	LC68
	fxch	%st(1)
	fabs
	fucompp
	fnstsw	%ax
	sahf
	jb	L237
	fldl	-136(%ebp)
	movl	-240(%ebp), %eax
	movl	-248(%ebp), %edx
	fmull	-208(%ebp)
	fldl	-184(%ebp)
	fxch	%st(1)
	fmull	-120(%ebp)
	fmul	%st, %st(1)
	fxch	%st(1)
	faddl	(%eax,%esi,8)
	fstpl	(%eax,%edi,8)
	movl	-244(%ebp), %eax
	fldl	-192(%ebp)
	fmul	%st(1), %st
	fxch	%st(1)
	fmull	-200(%ebp)
	fxch	%st(1)
L280:
	faddl	(%eax,%esi,8)
	fstpl	(%eax,%edi,8)
	faddl	(%edx,%esi,8)
	fstpl	(%edx,%edi,8)
L226:
	addl	$56, -276(%ebp)
	incl	%edi
	cmpl	%edi, _NcentersZmat
	jle	L225
L249:
	cmpl	-252(%ebp), %edi
	jg	L225
	movl	_Geom, %eax
	movl	-276(%ebp), %edx
	movl	24(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L281
	movl	-276(%ebp), %edx
	movl	_Geom, %eax
	movl	24(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
	movl	_Geom, %eax
	movl	-276(%ebp), %edx
	fstpl	-136(%ebp)
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L282
L230:
	movl	-276(%ebp), %edx
	movl	_Geom, %eax
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_Geom, %eax
	movl	-276(%ebp), %edx
	fstpl	-144(%ebp)
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L283
L232:
	movl	-276(%ebp), %edx
	movl	_Geom, %eax
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L265
L267:
	movl	-92(%ebp), %eax
	movl	%eax, -252(%ebp)
	jmp	L208
L225:
	movl	-240(%ebp), %eax
	movl	-96(%ebp), %edx
	fldl	(%eax,%edx,8)
	movl	-92(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-244(%ebp), %edx
	movl	-96(%ebp), %eax
	fstpl	-88(%ebp)
	fldl	(%edx,%eax,8)
	movl	-92(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	movl	-248(%ebp), %eax
	movl	-96(%ebp), %edx
	fstpl	-80(%ebp)
	fldl	(%eax,%edx,8)
	movl	-92(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-240(%ebp), %edx
	movl	-96(%ebp), %eax
	fstpl	-72(%ebp)
	fldl	(%edx,%eax,8)
	movl	8(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	movl	-244(%ebp), %eax
	movl	-96(%ebp), %edx
	fstpl	-56(%ebp)
	fldl	(%eax,%edx,8)
	movl	8(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-248(%ebp), %edx
	movl	-96(%ebp), %eax
	fstpl	-48(%ebp)
	fldl	(%edx,%eax,8)
	movl	8(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	fstpl	-40(%ebp)
	movl	-240(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	-244(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-248(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	-56(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	-84(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-80(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-76(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-72(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-68(%ebp), %eax
L266:
	movl	%eax, 20(%esp)
	call	_get_angle_vectors
	movl	%eax, %ecx
L203:
	addl	$364, %esp
	movl	%ecx, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L237:
	movl	-240(%ebp), %eax
	movl	-236(%ebp), %edx
	fldl	(%eax,%esi,8)
	fsubrl	(%eax,%edx,8)
	movl	-244(%ebp), %eax
	fstpl	-160(%ebp)
	fldl	(%eax,%esi,8)
	fsubrl	(%eax,%edx,8)
	movl	-248(%ebp), %edx
	movl	-236(%ebp), %eax
	fstpl	-168(%ebp)
	fldl	(%edx,%esi,8)
	fsubrl	(%edx,%eax,8)
	fstpl	-176(%ebp)
	fldl	-152(%ebp)
	fstpl	(%esp)
	call	_sin
	fldl	-152(%ebp)
	fxch	%st(1)
	fstpl	-232(%ebp)
	xorb	$-128, -225(%ebp)
	fstpl	(%esp)
	call	_cos
	fstpl	-224(%ebp)
	fldl	-136(%ebp)
	fmull	-120(%ebp)
	fldl	-224(%ebp)
	fxch	%st(1)
	fstpl	-216(%ebp)
	fldl	-136(%ebp)
	fmull	-128(%ebp)
	fmul	%st, %st(1)
	fmull	-232(%ebp)
	fxch	%st(1)
	fstpl	-224(%ebp)
	fldl	-264(%ebp)
	faddl	-272(%ebp)
	fxch	%st(1)
	fstpl	-232(%ebp)
	fldl	LC69
	fxch	%st(1)
	fsqrt
	fxch	%st(1)
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	jbe	L240
	fstp	%st(0)
	fldl	-176(%ebp)
	movl	$1, %ebx
	movl	-160(%ebp), %eax
	movl	-156(%ebp), %edx
	fstpl	-160(%ebp)
	xorl	$-2147483648, %edx
	fldl	-200(%ebp)
	movl	%edx, -172(%ebp)
	movl	-180(%ebp), %edx
	fld	%st(0)
	movl	%eax, -176(%ebp)
	fmul	%st(1), %st
	fxch	%st(1)
	movl	-184(%ebp), %eax
	fstpl	-184(%ebp)
	xorl	$-2147483648, %edx
	movl	%edx, -196(%ebp)
	faddl	-272(%ebp)
	movl	%eax, -200(%ebp)
	fsqrt
L242:
	fldl	-184(%ebp)
	fldl	-200(%ebp)
	fmull	-208(%ebp)
	fxch	%st(1)
	fdiv	%st(2), %st
	fld	%st(0)
	fxch	%st(3)
	fdivrl	-192(%ebp)
	fxch	%st(1)
	fstpl	-104(%ebp)
	fld	%st(0)
	fmull	-168(%ebp)
	fxch	%st(3)
	fmull	-160(%ebp)
	fldl	-104(%ebp)
	fxch	%st(2)
	fstl	-112(%ebp)
	fxch	%st(2)
	fmull	-168(%ebp)
	fxch	%st(1)
	faddp	%st, %st(4)
	fld	%st(2)
	fxch	%st(2)
	fmull	-160(%ebp)
	fxch	%st(2)
	fmul	%st(3), %st
	fxch	%st(1)
	fsubp	%st, %st(2)
	fld1
	fsubp	%st, %st(1)
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L277
	jne	L277
	fstp	%st(1)
L243:
	fldl	-176(%ebp)
	fxch	%st(4)
	fmul	%st(3), %st
	fxch	%st(4)
	fmul	%st(1), %st
	fld	%st(2)
	fmul	%st(3), %st
	fxch	%st(1)
	fsubp	%st, %st(5)
	fld	%st(4)
	fmul	%st(5), %st
	faddp	%st, %st(1)
	fldl	LC70
	fxch	%st(1)
	fsqrt
	fucom	%st(1)
	fnstsw	%ax
	fstp	%st(1)
	sahf
	jbe	L244
	fldl	-224(%ebp)
	fxch	%st(3)
	fdiv	%st(1), %st
	fldl	-232(%ebp)
	fxch	%st(2)
	fdivrp	%st, %st(6)
	fmul	%st, %st(3)
	fmull	-232(%ebp)
	fxch	%st(1)
	fmul	%st(5), %st
	fxch	%st(5)
	fmull	-224(%ebp)
	fxch	%st(3)
	fsubp	%st, %st(5)
	faddp	%st, %st(2)
L246:
	fldl	-216(%ebp)
	testl	%ebx, %ebx
	fld	%st(3)
	fldl	-104(%ebp)
	fxch	%st(1)
	fmul	%st(4), %st
	fxch	%st(2)
	fmul	%st(3), %st
	fxch	%st(5)
	fmull	-216(%ebp)
	fxch	%st(5)
	fsubp	%st, %st(2)
	fldl	-112(%ebp)
	fxch	%st(3)
	fmulp	%st, %st(4)
	fmul	%st(1), %st
	fldl	-104(%ebp)
	fxch	%st(3)
	fmul	%st(6), %st
	fxch	%st(3)
	fmulp	%st, %st(6)
	fxch	%st(1)
	fmull	-112(%ebp)
	fxch	%st(3)
	faddp	%st, %st(4)
	fsubp	%st, %st(1)
	fxch	%st(3)
	faddp	%st, %st(1)
	je	L247
	movl	-240(%ebp), %edx
	movl	-244(%ebp), %eax
	fldl	(%edx,%esi,8)
	fsubp	%st, %st(2)
	fxch	%st(1)
	fstpl	(%edx,%edi,8)
	movl	-248(%ebp), %edx
	jmp	L280
L240:
	xorl	%ebx, %ebx
	jmp	L242
L247:
	fxch	%st(2)
	movl	-240(%ebp), %eax
	movl	-244(%ebp), %edx
	faddl	(%eax,%esi,8)
	fstpl	(%eax,%edi,8)
	fxch	%st(1)
	movl	-248(%ebp), %eax
	faddl	(%edx,%esi,8)
	fstpl	(%edx,%edi,8)
	faddl	(%eax,%esi,8)
	fstpl	(%eax,%edi,8)
	jmp	L226
L244:
	fstp	%st(0)
	fstp	%st(1)
	fstp	%st(2)
	fldl	-224(%ebp)
	fldl	-232(%ebp)
	fxch	%st(1)
	fxch	%st(3)
	jmp	L246
L215:
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	-240(%ebp), %eax
	fstpl	8(%eax)
	jmp	L216
L219:
	movl	_Geom, %eax
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L261
L217:
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L260
L270:
	movl	-240(%ebp), %edx
	movl	-96(%ebp), %eax
	fldl	(%edx,%eax,8)
	movl	-92(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	movl	-244(%ebp), %eax
	movl	-96(%ebp), %edx
	fstpl	-56(%ebp)
	fldl	(%eax,%edx,8)
	movl	-92(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-248(%ebp), %edx
	movl	-96(%ebp), %eax
	fstpl	-48(%ebp)
	fldl	(%edx,%eax,8)
	movl	-92(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	movl	-240(%ebp), %eax
	movl	-96(%ebp), %edx
	fstpl	-40(%ebp)
	fldl	(%eax,%edx,8)
	movl	8(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-244(%ebp), %edx
	movl	-96(%ebp), %eax
	fstpl	-88(%ebp)
	fldl	(%edx,%eax,8)
	movl	8(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	movl	-248(%ebp), %eax
	movl	-96(%ebp), %edx
	fstpl	-80(%ebp)
	fldl	(%eax,%edx,8)
	movl	8(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	fstpl	-72(%ebp)
	movl	-240(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-244(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	-248(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-88(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-84(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-80(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-76(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-72(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-36(%ebp), %eax
	jmp	L266
L269:
	fldl	-120(%ebp)
	movl	-240(%ebp), %eax
	fmull	-136(%ebp)
	faddl	(%eax)
	jmp	L262
	.p2align 4,,7
L275:
	fstp	%st(0)
	fstpl	(%esp)
	call	_sqrt
	jmp	L236
L277:
	fstp	%st(0)
	fxch	%st(3)
	fstpl	-296(%ebp)
	fxch	%st(1)
	fstpl	-312(%ebp)
	fstpl	-328(%ebp)
	fstpl	(%esp)
	call	_sqrt
	fldl	-328(%ebp)
	fldl	-312(%ebp)
	fldl	-296(%ebp)
	fxch	%st(3)
	fxch	%st(1)
	fxch	%st(2)
	fxch	%st(1)
	jmp	L243
L254:
	fstp	%st(0)
	movl	-240(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	-244(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-248(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	$LC56, (%esp)
	call	_puts
	xorl	%ecx, %ecx
	jmp	L203
	.section .rdata,"dr"
	.align 8
LC75:
	.long	-1433277178
	.long	1066524486
	.align 8
LC76:
	.long	-350469331
	.long	1058682594
	.align 8
LC78:
	.long	-417264663
	.long	1072693245
	.align 8
LC79:
	.long	-1717986918
	.long	1069128089
	.align 8
LC80:
	.long	-640172613
	.long	1037794527
	.align 8
LC81:
	.long	-1998362383
	.long	1055193269
	.align 4
LC82:
	.long	-1082130432
	.text
	.p2align 4,,15
	.def	_get_dihedral_zmatrix;	.scl	3;	.type	32;	.endef
_get_dihedral_zmatrix:
	pushl	%ebp
	xorl	%ecx, %ecx
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$492, %esp
	movl	%edx, -192(%ebp)
	movl	_NcentersZmat, %edx
	movl	%eax, -188(%ebp)
	movl	12(%ebp), %eax
	cmpl	$1, %edx
	movl	%eax, -348(%ebp)
	jbe	L284
	movl	-188(%ebp), %esi
	testl	%esi, %esi
	js	L284
	movl	-192(%ebp), %ebx
	testl	%ebx, %ebx
	js	L284
	movl	8(%ebp), %edi
	testl	%edi, %edi
	js	L284
	testl	%eax, %eax
	js	L284
	cmpl	%eax, -188(%ebp)
	jg	L354
L290:
	movl	-348(%ebp), %eax
	cmpl	%eax, -192(%ebp)
	jle	L291
	movl	-192(%ebp), %eax
	movl	%eax, -348(%ebp)
L291:
	movl	-348(%ebp), %eax
	cmpl	%eax, 8(%ebp)
	jle	L292
	movl	8(%ebp), %eax
	movl	%eax, -348(%ebp)
L292:
	leal	-1(%edx), %eax
	xorl	%ecx, %ecx
	cmpl	%eax, -348(%ebp)
	ja	L284
	leal	0(,%edx,8), %eax
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -336(%ebp)
	movl	_NcentersZmat, %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -340(%ebp)
	movl	_NcentersZmat, %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -344(%ebp)
	movl	_NcentersZmat, %eax
	cmpl	$0, %eax
	jmp	L347
	.p2align 4,,7
L355:
	movl	-344(%ebp), %edx
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
	movl	$0, (%edx,%edi,8)
	movl	%esi, 4(%edx,%edi,8)
	movl	-340(%ebp), %edx
	movl	$0, (%edx,%edi,8)
	movl	%ebx, 4(%edx,%edi,8)
	movl	-336(%ebp), %edx
	movl	$0, (%edx,%edi,8)
	movl	%ecx, 4(%edx,%edi,8)
	incl	%edi
	cmpl	%edi, %eax
L347:
	jg	L355
	movl	-336(%ebp), %eax
	movl	-340(%ebp), %edx
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movl	-344(%ebp), %eax
	movl	$0, (%edx)
	movl	$0, 4(%edx)
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L298
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
	movl	-336(%ebp), %edx
	fstpl	8(%edx)
L299:
	movl	-344(%ebp), %eax
	fldz
	movl	-340(%ebp), %edx
	fstl	8(%edx)
	fstpl	8(%eax)
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L300
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L348:
	fstpl	-232(%ebp)
	movl	_Geom, %eax
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L302
	movl	_Geom, %eax
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L349:
	fstpl	-240(%ebp)
	fldl	-240(%ebp)
	fmull	LC75
	fstl	-240(%ebp)
	fstpl	(%esp)
	call	_cos
	fldl	-240(%ebp)
	fxch	%st(1)
	fstpl	-216(%ebp)
	fstpl	(%esp)
	call	_sin
	movl	_Geom, %eax
	fstpl	-224(%ebp)
	movl	148(%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	$2, %eax
	je	L356
	fldl	-216(%ebp)
	movl	-336(%ebp), %eax
	fmull	-232(%ebp)
	fstl	-216(%ebp)
	fsubrl	8(%eax)
L350:
	fstpl	16(%eax)
	movl	-340(%ebp), %eax
	movl	$3, %edi
	fldl	-224(%ebp)
	movl	-344(%ebp), %edx
	fmull	-232(%ebp)
	cmpl	$3, _NcentersZmat
	fstpl	16(%eax)
	fldz
	fstpl	16(%edx)
	jle	L307
	movl	$168, %esi
	movl	%esi, -380(%ebp)
	jmp	L331
	.p2align 4,,7
L368:
	movl	-380(%ebp), %edx
	movl	_Geom, %eax
	movl	24(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_Geom, %eax
	movl	-380(%ebp), %edx
	fstpl	-232(%ebp)
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L312
L369:
	movl	-380(%ebp), %edx
	movl	_Geom, %eax
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
	movl	_Geom, %eax
	movl	-380(%ebp), %edx
	fstpl	-240(%ebp)
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L314
L370:
	movl	_Geom, %eax
	movl	-380(%ebp), %edx
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L353:
	fstpl	-248(%ebp)
	movl	-380(%ebp), %edx
	movl	_Geom, %eax
	fldl	LC75
	fldl	-240(%ebp)
	movl	28(%edx,%eax), %eax
	fmul	%st(1), %st
	fxch	%st(1)
	movl	%eax, (%esp)
	fmull	-248(%ebp)
	fxch	%st(1)
	fstpl	-240(%ebp)
	fstpl	-248(%ebp)
	call	_atoi
	leal	-1(%eax), %esi
	movl	-380(%ebp), %edx
	movl	_Geom, %eax
	movl	36(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %ebx
	movl	-380(%ebp), %edx
	movl	_Geom, %eax
	decl	%ebx
	movl	44(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	decl	%eax
	movl	-340(%ebp), %edx
	movl	%eax, -332(%ebp)
	movl	-336(%ebp), %eax
	fldl	(%eax,%esi,8)
	fsubrl	(%eax,%ebx,8)
	movl	-344(%ebp), %eax
	fstpl	-280(%ebp)
	fldl	(%edx,%esi,8)
	fsubrl	(%edx,%ebx,8)
	fstpl	-288(%ebp)
	fldl	(%eax,%esi,8)
	fsubrl	(%eax,%ebx,8)
	fldl	-288(%ebp)
	fmul	%st(0), %st
	fxch	%st(1)
	fstpl	-296(%ebp)
	fldl	-280(%ebp)
	fmul	%st(0), %st
	fxch	%st(1)
	fstl	-376(%ebp)
	fxch	%st(1)
	fstl	-368(%ebp)
	faddp	%st, %st(1)
	fstpl	-304(%ebp)
	fldl	-296(%ebp)
	fmul	%st(0), %st
	faddl	-304(%ebp)
	fstpl	-304(%ebp)
	fldl	-304(%ebp)
	fldl	LC76
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	ja	L342
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L362
	jne	L362
	fstp	%st(1)
L318:
	fld1
	fdivp	%st, %st(1)
	fldl	-240(%ebp)
	fxch	%st(1)
	fstpl	-304(%ebp)
	fstpl	(%esp)
	call	_cos
	fldl	-240(%ebp)
	fxch	%st(1)
	fstpl	-216(%ebp)
	fstpl	(%esp)
	call	_sin
	fldl	-216(%ebp)
	fxch	%st(1)
	fstpl	-224(%ebp)
	fldl	LC78
	fxch	%st(1)
	fabs
	fucompp
	fnstsw	%ax
	sahf
	jb	L319
	fldl	-232(%ebp)
	movl	-336(%ebp), %eax
	movl	-344(%ebp), %edx
	fmull	-304(%ebp)
	fldl	-280(%ebp)
	fxch	%st(1)
	fmull	-216(%ebp)
	fmul	%st, %st(1)
	fxch	%st(1)
	faddl	(%eax,%esi,8)
	fstpl	(%eax,%edi,8)
	movl	-340(%ebp), %eax
	fldl	-288(%ebp)
	fmul	%st(1), %st
	fxch	%st(1)
	fmull	-296(%ebp)
	fxch	%st(1)
L367:
	faddl	(%eax,%esi,8)
	fstpl	(%eax,%edi,8)
	faddl	(%edx,%esi,8)
	fstpl	(%edx,%edi,8)
L308:
	addl	$56, -380(%ebp)
	incl	%edi
	cmpl	%edi, _NcentersZmat
	jle	L307
L331:
	cmpl	-348(%ebp), %edi
	jg	L307
	movl	_Geom, %eax
	movl	-380(%ebp), %edx
	movl	24(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L368
	movl	-380(%ebp), %edx
	movl	_Geom, %eax
	movl	24(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
	movl	_Geom, %eax
	movl	-380(%ebp), %edx
	fstpl	-232(%ebp)
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L369
L312:
	movl	-380(%ebp), %edx
	movl	_Geom, %eax
	movl	32(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_Geom, %eax
	movl	-380(%ebp), %edx
	fstpl	-240(%ebp)
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L370
L314:
	movl	-380(%ebp), %edx
	movl	_Geom, %eax
	movl	40(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L353
L354:
	movl	-188(%ebp), %eax
	movl	%eax, -348(%ebp)
	jmp	L290
	.p2align 4,,7
L307:
	movl	-336(%ebp), %eax
	movl	-192(%ebp), %edx
	fldl	(%eax,%edx,8)
	movl	-188(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-340(%ebp), %edx
	movl	-192(%ebp), %eax
	fstpl	-120(%ebp)
	fldl	(%edx,%eax,8)
	movl	-188(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	movl	-344(%ebp), %eax
	movl	-192(%ebp), %edx
	fstpl	-112(%ebp)
	fldl	(%eax,%edx,8)
	movl	-188(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-336(%ebp), %edx
	movl	-192(%ebp), %eax
	fstpl	-104(%ebp)
	fldl	(%edx,%eax,8)
	movl	8(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	movl	-340(%ebp), %eax
	movl	-192(%ebp), %edx
	fstpl	-152(%ebp)
	fldl	(%eax,%edx,8)
	movl	8(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-344(%ebp), %edx
	movl	-192(%ebp), %eax
	fstpl	-144(%ebp)
	fldl	(%edx,%eax,8)
	movl	8(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	leal	-56(%ebp), %edx
	fstpl	-136(%ebp)
	movl	-152(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 28(%esp)
	movl	-148(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-144(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-140(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-136(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-132(%ebp), %eax
	movl	%eax, 48(%esp)
	movl	-120(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-116(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-112(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-108(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-104(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-100(%ebp), %eax
	movl	%eax, 24(%esp)
	call	_get_produit_vectoriel
	movl	-336(%ebp), %eax
	subl	$4, %esp
	movl	8(%ebp), %edx
	fldl	(%eax,%edx,8)
	movl	12(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-340(%ebp), %edx
	movl	8(%ebp), %eax
	fstpl	-120(%ebp)
	fldl	(%edx,%eax,8)
	movl	12(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	movl	-344(%ebp), %eax
	movl	8(%ebp), %edx
	fstpl	-112(%ebp)
	fldl	(%eax,%edx,8)
	movl	12(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-336(%ebp), %edx
	movl	8(%ebp), %eax
	fstpl	-104(%ebp)
	fldl	(%edx,%eax,8)
	movl	-192(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	movl	-340(%ebp), %eax
	movl	8(%ebp), %edx
	fstpl	-152(%ebp)
	fldl	(%eax,%edx,8)
	movl	-192(%ebp), %edx
	fsubrl	(%eax,%edx,8)
	movl	-344(%ebp), %edx
	movl	8(%ebp), %eax
	fstpl	-144(%ebp)
	fldl	(%edx,%eax,8)
	movl	-192(%ebp), %eax
	fsubrl	(%edx,%eax,8)
	leal	-88(%ebp), %edx
	fstpl	-136(%ebp)
	movl	-120(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 28(%esp)
	movl	-116(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-112(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-108(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-104(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-100(%ebp), %eax
	movl	%eax, 48(%esp)
	movl	-152(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-148(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-144(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-140(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-136(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-132(%ebp), %eax
	movl	%eax, 24(%esp)
	call	_get_produit_vectoriel
	movl	-88(%ebp), %eax
	subl	$4, %esp
	movl	%eax, 24(%esp)
	movl	-84(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-80(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-76(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-72(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, 20(%esp)
	call	_get_angle_vectors
	movl	%eax, (%esp)
	call	_atof
	movl	-88(%ebp), %eax
	leal	-184(%ebp), %edx
	fstpl	-360(%ebp)
	movl	%edx, (%esp)
	movl	%eax, 28(%esp)
	movl	-84(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-80(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-76(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-72(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 48(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, 24(%esp)
	call	_get_produit_vectoriel
	movl	-184(%ebp), %eax
	subl	$4, %esp
	movl	%eax, (%esp)
	movl	-180(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-176(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-172(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-168(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-164(%ebp), %eax
	movl	%eax, 20(%esp)
	call	_get_module
	fldl	LC81
	fucompp
	fnstsw	%ax
	sahf
	jbe	L360
L335:
	fld1
L334:
	fmull	-360(%ebp)
	movl	$LC53, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ecx
L284:
	leal	-12(%ebp), %esp
	movl	%ecx, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L319:
	movl	-336(%ebp), %eax
	movl	-332(%ebp), %edx
	fldl	(%eax,%esi,8)
	fsubrl	(%eax,%edx,8)
	movl	-340(%ebp), %eax
	fstpl	-256(%ebp)
	fldl	(%eax,%esi,8)
	fsubrl	(%eax,%edx,8)
	movl	-344(%ebp), %edx
	movl	-332(%ebp), %eax
	fstpl	-264(%ebp)
	fldl	(%edx,%esi,8)
	fsubrl	(%edx,%eax,8)
	fstpl	-272(%ebp)
	fldl	-248(%ebp)
	fstpl	(%esp)
	call	_sin
	fldl	-248(%ebp)
	fxch	%st(1)
	fstpl	-328(%ebp)
	xorb	$-128, -321(%ebp)
	fstpl	(%esp)
	call	_cos
	fstpl	-320(%ebp)
	fldl	-232(%ebp)
	fmull	-216(%ebp)
	fldl	-320(%ebp)
	fxch	%st(1)
	fstpl	-312(%ebp)
	fldl	-232(%ebp)
	fmull	-224(%ebp)
	fmul	%st, %st(1)
	fmull	-328(%ebp)
	fxch	%st(1)
	fstpl	-320(%ebp)
	fldl	-368(%ebp)
	faddl	-376(%ebp)
	fxch	%st(1)
	fstpl	-328(%ebp)
	fldl	LC79
	fxch	%st(1)
	fsqrt
	fxch	%st(1)
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	jbe	L322
	fstp	%st(0)
	fldl	-272(%ebp)
	movl	$1, %ebx
	movl	-256(%ebp), %eax
	movl	-252(%ebp), %edx
	fstpl	-256(%ebp)
	xorl	$-2147483648, %edx
	fldl	-296(%ebp)
	movl	%edx, -268(%ebp)
	movl	-276(%ebp), %edx
	fld	%st(0)
	movl	%eax, -272(%ebp)
	fmul	%st(1), %st
	fxch	%st(1)
	movl	-280(%ebp), %eax
	fstpl	-280(%ebp)
	xorl	$-2147483648, %edx
	movl	%edx, -292(%ebp)
	faddl	-376(%ebp)
	movl	%eax, -296(%ebp)
	fsqrt
L324:
	fldl	-280(%ebp)
	fldl	-296(%ebp)
	fmull	-304(%ebp)
	fxch	%st(1)
	fdiv	%st(2), %st
	fld	%st(0)
	fxch	%st(3)
	fdivrl	-288(%ebp)
	fxch	%st(1)
	fstpl	-200(%ebp)
	fld	%st(0)
	fmull	-264(%ebp)
	fxch	%st(3)
	fmull	-256(%ebp)
	fldl	-200(%ebp)
	fxch	%st(2)
	fstl	-208(%ebp)
	fxch	%st(2)
	fmull	-264(%ebp)
	fxch	%st(1)
	faddp	%st, %st(4)
	fld	%st(2)
	fxch	%st(2)
	fmull	-256(%ebp)
	fxch	%st(2)
	fmul	%st(3), %st
	fxch	%st(1)
	fsubp	%st, %st(2)
	fld1
	fsubp	%st, %st(1)
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	L364
	jne	L364
	fstp	%st(1)
L325:
	fldl	-272(%ebp)
	fxch	%st(4)
	fmul	%st(3), %st
	fxch	%st(4)
	fmul	%st(1), %st
	fld	%st(2)
	fmul	%st(3), %st
	fxch	%st(1)
	fsubp	%st, %st(5)
	fld	%st(4)
	fmul	%st(5), %st
	faddp	%st, %st(1)
	fldl	LC80
	fxch	%st(1)
	fsqrt
	fucom	%st(1)
	fnstsw	%ax
	fstp	%st(1)
	sahf
	jbe	L326
	fldl	-320(%ebp)
	fxch	%st(3)
	fdiv	%st(1), %st
	fldl	-328(%ebp)
	fxch	%st(2)
	fdivrp	%st, %st(6)
	fmul	%st, %st(3)
	fmull	-328(%ebp)
	fxch	%st(1)
	fmul	%st(5), %st
	fxch	%st(5)
	fmull	-320(%ebp)
	fxch	%st(3)
	fsubp	%st, %st(5)
	faddp	%st, %st(2)
L328:
	fldl	-312(%ebp)
	testl	%ebx, %ebx
	fld	%st(3)
	fldl	-200(%ebp)
	fxch	%st(1)
	fmul	%st(4), %st
	fxch	%st(2)
	fmul	%st(3), %st
	fxch	%st(5)
	fmull	-312(%ebp)
	fxch	%st(5)
	fsubp	%st, %st(2)
	fldl	-208(%ebp)
	fxch	%st(3)
	fmulp	%st, %st(4)
	fmul	%st(1), %st
	fldl	-200(%ebp)
	fxch	%st(3)
	fmul	%st(6), %st
	fxch	%st(3)
	fmulp	%st, %st(6)
	fxch	%st(1)
	fmull	-208(%ebp)
	fxch	%st(3)
	faddp	%st, %st(4)
	fsubp	%st, %st(1)
	fxch	%st(3)
	faddp	%st, %st(1)
	je	L329
	movl	-336(%ebp), %edx
	movl	-340(%ebp), %eax
	fldl	(%edx,%esi,8)
	fsubp	%st, %st(2)
	fxch	%st(1)
	fstpl	(%edx,%edi,8)
	movl	-344(%ebp), %edx
	jmp	L367
	.p2align 4,,7
L322:
	xorl	%ebx, %ebx
	jmp	L324
	.p2align 4,,7
L329:
	fxch	%st(2)
	movl	-336(%ebp), %eax
	movl	-340(%ebp), %edx
	faddl	(%eax,%esi,8)
	fstpl	(%eax,%edi,8)
	fxch	%st(1)
	movl	-344(%ebp), %eax
	faddl	(%edx,%esi,8)
	fstpl	(%edx,%edi,8)
	faddl	(%eax,%esi,8)
	fstpl	(%eax,%edi,8)
	jmp	L308
	.p2align 4,,7
L326:
	fstp	%st(0)
	fstp	%st(1)
	fstp	%st(2)
	fldl	-320(%ebp)
	fldl	-328(%ebp)
	fxch	%st(1)
	fxch	%st(3)
	jmp	L328
L360:
	movl	-152(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-148(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-144(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-140(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-136(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-132(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-184(%ebp), %eax
	movl	%eax, (%esp)
	movl	-180(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-176(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-172(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-168(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-164(%ebp), %eax
	movl	%eax, 20(%esp)
	call	_get_scalaire
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L335
	flds	LC82
	jmp	L334
L298:
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	-336(%ebp), %eax
	fstpl	8(%eax)
	jmp	L299
L302:
	movl	_Geom, %eax
	movl	144(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L349
L300:
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L348
L356:
	fldl	-216(%ebp)
	movl	-336(%ebp), %eax
	fmull	-232(%ebp)
	faddl	(%eax)
	jmp	L350
	.p2align 4,,7
L362:
	fstp	%st(0)
	fstpl	(%esp)
	call	_sqrt
	jmp	L318
L364:
	fstp	%st(0)
	fxch	%st(3)
	fstpl	-408(%ebp)
	fxch	%st(1)
	fstpl	-424(%ebp)
	fstpl	-440(%ebp)
	fstpl	(%esp)
	call	_sqrt
	fldl	-440(%ebp)
	fldl	-424(%ebp)
	fldl	-408(%ebp)
	fxch	%st(3)
	fxch	%st(1)
	fxch	%st(2)
	fxch	%st(1)
	jmp	L325
L342:
	fstp	%st(0)
	movl	-336(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	-340(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-344(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	$LC56, (%esp)
	call	_puts
	xorl	%ecx, %ecx
	jmp	L284
	.p2align 4,,15
	.def	_set_text_column;	.scl	3;	.type	32;	.endef
_set_text_column:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$72, %esp
	movl	%edx, (%esp)
	movl	%ebx, -12(%ebp)
	movl	%eax, %ebx
	movl	%esi, -8(%ebp)
	leal	-40(%ebp), %esi
	movl	%edi, -4(%ebp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$-1, %edx
	movl	%edx, 16(%esp)
	movl	8(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	call	_gtk_list_store_set
	movl	%edi, (%esp)
	call	_gtk_tree_path_free
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_testav;	.scl	3;	.type	32;	.endef
_testav:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	%eax, -16(%ebp)
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	movl	$-1, %edx
	jne	L372
	movl	_NVariables, %eax
	xorl	%esi, %esi
	cmpl	%eax, %esi
	movl	%eax, -20(%ebp)
	jae	L381
	movl	_Variables, %edi
	xorl	%ebx, %ebx
	.p2align 4,,15
L378:
	movl	(%ebx,%edi), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L382
	incl	%esi
	addl	$12, %ebx
	cmpl	-20(%ebp), %esi
	jb	L378
L381:
	movl	$-2, %edx
L372:
	addl	$28, %esp
	movl	%edx, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L382:
	addl	$28, %esp
	movl	%esi, %edx
	movl	%edx, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_append_list_variables;	.scl	3;	.type	32;	.endef
_append_list_variables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	_listv, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, %ebx
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %edi
	call	_gtk_tree_model_get_type
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	$0, -52(%ebp)
	xorl	%eax, %eax
	cmpl	_NVariables, %eax
	jae	L393
	movl	$0, -56(%ebp)
	.p2align 4,,15
L391:
	movl	-56(%ebp), %edx
	xorl	%esi, %esi
	movl	_Variables, %eax
	movl	(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -48(%ebp)
	movl	-56(%ebp), %edx
	movl	_Variables, %eax
	movl	4(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -44(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_gtk_list_store_append
L390:
	movl	%edi, (%esp)
	leal	(%esi,%esi), %edx
	movl	$-1, %ebx
	movl	%ebx, 24(%esp)
	leal	1(%edx), %eax
	movl	$1, %ecx
	movl	%eax, 16(%esp)
	leal	0(,%esi,4), %ebx
	movl	-48(%ebx,%ebp), %eax
	movl	%edx, 8(%esp)
	leal	-40(%ebp), %edx
	incl	%esi
	movl	%ecx, 20(%esp)
	movl	%eax, 12(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_list_store_set
	movl	-48(%ebx,%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$1, %esi
	jle	L390
	incl	-52(%ebp)
	addl	$12, -56(%ebp)
	movl	-52(%ebp), %eax
	cmpl	_NVariables, %eax
	jb	L391
L393:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_reset_r_value;	.scl	3;	.type	32;	.endef
_reset_r_value:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	%edx, %esi
	leal	0(,%eax,8), %edx
	pushl	%ebx
	subl	%eax, %edx
	subl	$16, %esp
	movl	_Geom, %eax
	leal	0(,%edx,8), %ebx
	movl	24(%ebx,%eax), %eax
	call	_testav
	testl	%eax, %eax
	js	L397
	movl	_Variables, %edx
	leal	(%eax,%eax,2), %eax
	leal	0(,%eax,4), %ebx
	movl	4(%ebx,%edx), %eax
	testl	%eax, %eax
	jne	L401
L398:
	movl	%esi, 4(%ebx,%edx)
	movl	_listv, %eax
	call	_clearList
	call	_append_list_variables
	addl	$16, %esp
	xorl	%eax, %eax
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L401:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Variables, %edx
	jmp	L398
	.p2align 4,,7
L397:
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %edx
	testl	%edx, %edx
	jne	L402
L400:
	movl	%esi, 24(%ebx,%eax)
	addl	$16, %esp
	movl	$1, %eax
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
L402:
	movl	%edx, (%esp)
	call	_g_free
	movl	_Geom, %eax
	jmp	L400
	.p2align 4,,15
	.def	_reset_angle_value;	.scl	3;	.type	32;	.endef
_reset_angle_value:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	%edx, %esi
	leal	0(,%eax,8), %edx
	pushl	%ebx
	subl	%eax, %edx
	subl	$16, %esp
	movl	_Geom, %eax
	leal	0(,%edx,8), %ebx
	movl	32(%ebx,%eax), %eax
	call	_testav
	testl	%eax, %eax
	js	L404
	movl	_Variables, %edx
	leal	(%eax,%eax,2), %eax
	leal	0(,%eax,4), %ebx
	movl	4(%ebx,%edx), %eax
	testl	%eax, %eax
	jne	L408
L405:
	movl	%esi, 4(%ebx,%edx)
	movl	_listv, %eax
	call	_clearList
	call	_append_list_variables
	addl	$16, %esp
	xorl	%eax, %eax
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L408:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Variables, %edx
	jmp	L405
	.p2align 4,,7
L404:
	movl	_Geom, %eax
	movl	32(%ebx,%eax), %edx
	testl	%edx, %edx
	jne	L409
L407:
	movl	%esi, 32(%ebx,%eax)
	addl	$16, %esp
	movl	$1, %eax
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
L409:
	movl	%edx, (%esp)
	call	_g_free
	movl	_Geom, %eax
	jmp	L407
	.p2align 4,,15
	.def	_reset_dihedral_value;	.scl	3;	.type	32;	.endef
_reset_dihedral_value:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	%edx, %esi
	leal	0(,%eax,8), %edx
	pushl	%ebx
	subl	%eax, %edx
	subl	$16, %esp
	movl	_Geom, %eax
	leal	0(,%edx,8), %ebx
	movl	40(%ebx,%eax), %eax
	call	_testav
	testl	%eax, %eax
	js	L411
	movl	_Variables, %edx
	leal	(%eax,%eax,2), %eax
	leal	0(,%eax,4), %ebx
	movl	4(%ebx,%edx), %eax
	testl	%eax, %eax
	jne	L415
L412:
	movl	%esi, 4(%ebx,%edx)
	movl	_listv, %eax
	call	_clearList
	call	_append_list_variables
	addl	$16, %esp
	xorl	%eax, %eax
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L415:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Variables, %edx
	jmp	L412
	.p2align 4,,7
L411:
	movl	_Geom, %eax
	movl	40(%ebx,%eax), %edx
	testl	%edx, %edx
	jne	L416
L414:
	movl	%esi, 40(%ebx,%eax)
	addl	$16, %esp
	movl	$1, %eax
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
L416:
	movl	%edx, (%esp)
	call	_g_free
	movl	_Geom, %eax
	jmp	L414
	.section .rdata,"dr"
LC86:
	.ascii "%d %d\12\0"
	.text
	.p2align 4,,15
	.def	_selectedCell;	.scl	3;	.type	32;	.endef
_selectedCell:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$80, %edi
	pushl	%esi
	movl	$LC47, %esi
	pushl	%ebx
	subl	$44, %esp
	movl	%edi, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %esi
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	testl	%eax, %eax
	movl	%eax, %edi
	js	L417
	leal	-5(%esi), %eax
	cmpl	$1, %eax
	jbe	L423
L419:
	leal	-7(%esi), %eax
	cmpl	$1, %eax
	setbe	%dl
	xorl	%eax, %eax
	cmpl	$1, %edi
	setg	%al
	testl	%edx, %eax
	jne	L424
L421:
	leal	-9(%esi), %eax
	cmpl	$1, %eax
	setbe	%dl
	xorl	%eax, %eax
	cmpl	$2, %edi
	setg	%al
	testl	%edx, %eax
	jne	L425
L417:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L423:
	testl	%edi, %edi
	jle	L419
	movl	_Geom, %edx
	leal	0(,%edi,8), %eax
	subl	%edi, %eax
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, 8(%esp)
	leal	1(%edi), %eax
	movl	%eax, 4(%esp)
	movl	$LC86, (%esp)
	call	_printf
	leal	-7(%esi), %eax
	cmpl	$1, %eax
	setbe	%dl
	xorl	%eax, %eax
	cmpl	$1, %edi
	setg	%al
	testl	%edx, %eax
	je	L421
	.p2align 4,,15
L424:
	movl	_Geom, %eax
	leal	0(,%edi,8), %ebx
	subl	%edi, %ebx
	sall	$3, %ebx
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -16(%ebp)
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	-16(%ebp), %edx
	movl	%eax, 8(%esp)
	leal	1(%edi), %eax
	movl	%edx, 12(%esp)
	movl	%eax, 4(%esp)
	movl	$LC86, (%esp)
	call	_printf
	leal	-9(%esi), %eax
	cmpl	$1, %eax
	setbe	%dl
	xorl	%eax, %eax
	cmpl	$2, %edi
	setg	%al
	testl	%edx, %eax
	je	L417
	.p2align 4,,15
L425:
	leal	0(,%edi,8), %ebx
	movl	_Geom, %eax
	subl	%edi, %ebx
	sall	$3, %ebx
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -20(%ebp)
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -24(%ebp)
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	-20(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	-24(%ebp), %edx
	movl	%eax, 8(%esp)
	leal	1(%edi), %eax
	movl	%edx, 12(%esp)
	movl	%eax, 4(%esp)
	movl	$LC86, (%esp)
	call	_printf
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC99:
	.ascii "High\0"
LC100:
	.ascii "Medium\0"
LC101:
	.ascii "Low\0"
	.align 4
LC88:
	.ascii "Sorry\12 %s \12is not a number \12and is not a variable \0"
	.align 4
LC87:
	.ascii "Sorry %s is not a symbol for an atom \12\0"
LC93:
	.ascii "Sorry\12 %s \12is not an integer \0"
	.align 4
LC94:
	.ascii "Sorry\12 %s \12is not an integer between 1 and %d\0"
	.align 4
LC92:
	.ascii "Sorry : The distance can not be <0.01\0"
LC98:
	.ascii "%s\0"
	.align 4
LC90:
	.ascii "Sorry : The distance can not be negative\0"
	.align 4
LC102:
	.ascii "Sorry  The layer should be High, Medium, Low or one space \12\0"
	.align 4
LC97:
	.ascii "Because a multiple references to a center on the same card\12I set NR to %d\12\0"
	.align 4
LC96:
	.ascii "Because a multiple references to a center on the same card\12I set ND to %d\12\0"
	.align 4
LC95:
	.ascii "Because a multiple references to a center on the same card\12I set NA to %d\12\0"
	.align 8
LC91:
	.long	1202590843
	.long	1065646817
	.text
	.p2align 4,,15
	.def	_editedGeom;	.scl	3;	.type	32;	.endef
_editedGeom:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$152, %esp
	movl	%ebx, -12(%ebp)
	movl	$LC47, %ebx
	movl	%esi, -8(%ebp)
	movl	$80, %esi
	movl	%edi, -4(%ebp)
	call	_gtk_tree_model_get_type
	movl	%eax, 4(%esp)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -44(%ebp)
	movl	8(%ebp), %eax
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_g_object_get_data
	testl	%eax, %eax
	movl	%eax, %edi
	je	L426
	movl	16(%ebp), %ecx
	testl	%ecx, %ecx
	je	L426
	cmpl	$1, %eax
	je	L611
	cmpl	$2, %eax
	je	L612
	cmpl	$3, %eax
	je	L613
	cmpl	$4, %eax
	je	L614
	cmpl	$5, %eax
	sete	%al
	cmpl	$7, %edi
	sete	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L460
	cmpl	$9, %edi
	je	L460
	cmpl	$6, %edi
	sete	%al
	cmpl	$8, %edi
	sete	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L476
	cmpl	$10, %edi
	je	L476
	cmpl	$11, %edi
	je	L615
	cmpl	$12, %edi
	jne	L426
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_strlen
	testl	%eax, %eax
	movl	%eax, %esi
	jle	L426
	movl	16(%ebp), %ecx
	movl	$1, %ebx
	movsbl	(%ecx),%eax
	movl	%eax, (%esp)
	call	_toupper
	movl	16(%ebp), %edx
	movb	%al, (%edx)
	jmp	L600
L616:
	movl	16(%ebp), %ecx
	movsbl	(%ebx,%ecx),%eax
	movl	%eax, (%esp)
	call	_tolower
	movl	16(%ebp), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
L600:
	cmpl	%esi, %ebx
	jl	L616
	movl	12(%ebp), %ecx
	movl	$LC99, %edi
	movl	%ecx, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	16(%ebp), %esi
	movl	$5, %ecx
	cld
	repe
	cmpsb
	je	L573
	movl	16(%ebp), %esi
	movl	$LC100, %edi
	movl	$7, %ecx
	repe
	cmpsb
	je	L573
	movl	16(%ebp), %esi
	movl	$LC101, %edi
	movl	$4, %ecx
	repe
	cmpsb
	je	L573
	movl	16(%ebp), %esi
	movl	$LC46, %edi
	movl	$2, %ecx
	repe
	cmpsb
	jne	L617
L573:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	52(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L618
L574:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 52(%esi,%ebx)
	movl	12(%ebp), %edx
	leal	-40(%ebp), %ebx
	movl	%edx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	-44(%ebp), %ecx
	movl	%eax, %esi
	movl	%ebx, 4(%esp)
	movl	%ecx, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	16(%ebp), %edx
	movl	$-1, %ecx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	$24, %edx
	movl	%edx, 8(%esp)
	jmp	L605
	.p2align 4,,7
L613:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L426
	movl	12(%ebp), %esi
	movl	%esi, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	_Geom, %ebx
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	12(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L622
L441:
	movl	16(%ebp), %eax
	movl	$-1, %edi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 12(%esi,%ebx)
	movl	12(%ebp), %edx
	leal	-40(%ebp), %ebx
	movl	%edx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	-44(%ebp), %ecx
	movl	%eax, %esi
	movl	%ebx, 4(%esp)
	movl	%ecx, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 16(%esp)
	movl	16(%ebp), %edx
	movl	$6, %ecx
	.p2align 4,,15
L663:
	movl	%edx, 12(%esp)
	movl	%ecx, 8(%esp)
L605:
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_list_store_set
	movl	%esi, (%esp)
	call	_gtk_tree_path_free
L606:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L426
	call	_rafresh_drawing
	.p2align 4,,15
L426:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L460:
	movl	16(%ebp), %esi
	movl	%esi, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L426
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	%esi, %eax
	call	_testav
	incl	%eax
	jge	L462
	movl	%esi, 4(%esp)
	movl	$LC88, (%esp)
L607:
	call	_g_strdup_printf
L604:
	movl	%eax, %ebx
	movl	$LC48, %edi
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%ebx, (%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	jmp	L426
	.p2align 4,,7
L611:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	testl	%eax, %eax
	movl	%eax, %ebx
	jle	L426
	movl	16(%ebp), %edx
	movsbl	(%edx),%eax
	movl	%eax, (%esp)
	call	_toupper
	movl	16(%ebp), %ecx
	decl	%ebx
	movb	%al, (%ecx)
	jg	L619
L431:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_test_atom_define
	testl	%eax, %eax
	jne	L668
	movl	$LC87, (%esp)
L666:
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	jmp	L607
L612:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L426
	movl	12(%ebp), %esi
	movl	%esi, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	_Geom, %ebx
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	8(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L623
L437:
	movl	16(%ebp), %eax
	movl	$-1, %edi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%esi,%ebx)
	movl	12(%ebp), %edx
	leal	-40(%ebp), %ebx
	movl	%edx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	-44(%ebp), %ecx
	movl	%eax, %esi
	movl	%ebx, 4(%esp)
	movl	%ecx, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 16(%esp)
	movl	16(%ebp), %edx
	movl	$4, %ecx
	jmp	L663
L668:
	movl	12(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	_Geom, %ebx
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	4(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L621
L433:
	movl	16(%ebp), %eax
	movl	$-1, %edi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%esi,%ebx)
	movl	12(%ebp), %edx
	leal	-40(%ebp), %ebx
	movl	%edx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	-44(%ebp), %ecx
	movl	%eax, %esi
	movl	%ebx, 4(%esp)
	movl	%ecx, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 16(%esp)
	movl	16(%ebp), %edx
	movl	$2, %ecx
	jmp	L663
L623:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L437
L614:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L426
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	16(%ebp), %ecx
	sall	$3, %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	movl	%ecx, 4(%esp)
	subl	%edx, %eax
	sall	$3, %eax
	movl	%eax, -52(%ebp)
	movl	%eax, %esi
	movl	16(%eax,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L445
	movl	16(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L624
L446:
	movl	16(%ebp), %eax
	movl	$-1, %edi
	xorl	%esi, %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-52(%ebp), %edx
	movl	%eax, 16(%edx,%ebx)
	movl	_Geom, %ebx
	movl	%edi, 20(%edx,%ebx)
	movl	_NcentersZmat, %edi
	cmpl	$0, %edi
	jle	L448
	movl	%edx, -116(%ebp)
	movl	$0, -120(%ebp)
L451:
	cmpl	%esi, -48(%ebp)
	je	L449
	movl	-120(%ebp), %ecx
	movl	-116(%ebp), %edx
	movl	16(%ecx,%ebx), %eax
	movl	%eax, 4(%esp)
	movl	16(%edx,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L581
L449:
	addl	$56, -120(%ebp)
	incl	%esi
	cmpl	%esi, %edi
	jg	L451
L448:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	sall	$3, %eax
	subl	%esi, %eax
	sall	$3, %eax
	cmpl	$-1, 20(%eax,%ebx)
	je	L625
L445:
	movl	12(%ebp), %ecx
	leal	-40(%ebp), %ebx
	movl	$8, %edi
	movl	%ecx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	%eax, %esi
	movl	-44(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 8(%esp)
	movl	16(%ebp), %ecx
	movl	$-1, %edx
	movl	%edx, 16(%esp)
	movl	%ecx, 12(%esp)
	jmp	L605
L476:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_strlen
	movl	$-1, -56(%ebp)
	testl	%eax, %eax
	movl	$-1, -60(%ebp)
	movl	$-1, -64(%ebp)
	jle	L426
	movl	12(%ebp), %esi
	movl	%esi, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_isInteger
	testl	%eax, %eax
	jne	L478
	movl	$LC93, (%esp)
	jmp	L666
L619:
	movsbl	1(%ecx),%eax
	movl	%eax, (%esp)
	call	_tolower
	movl	16(%ebp), %esi
	movb	%al, 1(%esi)
	jmp	L431
L462:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L626
L463:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L464
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_atof
	fldz
	fucompp
	fnstsw	%ax
	sahf
	jbe	L464
	cmpl	$5, %edi
	je	L627
L464:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L628
L466:
	cmpl	$5, %edi
	je	L629
L468:
	cmpl	$7, %edi
	je	L630
	cmpl	$9, %edi
	je	L631
L472:
	movl	12(%ebp), %edx
	leal	-40(%ebp), %ebx
	movl	%edx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	-44(%ebp), %ecx
	movl	%eax, %esi
	movl	%ebx, 4(%esp)
	movl	%ecx, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	16(%ebp), %edx
	movl	$-1, %ecx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	leal	(%edi,%edi), %edx
	movl	%edx, 8(%esp)
	jmp	L605
L622:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L441
L621:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L433
L478:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_atoi
	testl	%eax, %eax
	movl	%eax, %ebx
	jle	L480
	movl	-48(%ebp), %eax
	incl	%eax
	cmpl	%ebx, %eax
	jg	L479
L480:
	movl	$LC94, (%esp)
	movl	-48(%ebp), %esi
	movl	16(%ebp), %eax
	movl	%esi, 8(%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	jmp	L604
L626:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L463
	movl	$LC51, (%esp)
	movl	16(%ebp), %esi
	movl	%esi, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 16(%ebp)
	jmp	L463
L628:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_atof
	fldl	LC91
	fxch	%st(1)
	fabs
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L466
	cmpl	$5, %edi
	jne	L468
	movl	$LC92, (%esp)
	call	_g_strdup_printf
	jmp	L604
	.p2align 4,,7
L629:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%ecx, %eax
	leal	0(,%eax,8), %esi
	movl	24(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L632
L469:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 24(%esi,%ebx)
	jmp	L472
L630:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	32(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L633
L471:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	%eax, 32(%esi,%ebx)
	jmp	L472
L624:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L446
L625:
	movl	_NcentersZmat, %edi
	xorl	%esi, %esi
	cmpl	$0, %edi
	jle	L578
	movl	%edi, -112(%ebp)
	leal	20(%ebx), %ecx
L457:
	movl	(%ecx), %edx
	cmpl	%edx, 20(%eax,%ebx)
	jge	L455
	movl	%edx, 20(%eax,%ebx)
	movl	-112(%ebp), %edi
L455:
	incl	%esi
	addl	$56, %ecx
	cmpl	%esi, %edi
	jg	L457
L578:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	sall	$3, %eax
	subl	%ecx, %eax
	incl	20(%ebx,%eax,8)
	jmp	L445
L615:
	movl	16(%ebp), %esi
	movl	%esi, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L426
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	%esi, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L561
	movl	%esi, 4(%esp)
	movl	$LC50, (%esp)
	jmp	L607
L479:
	cmpl	$6, %edi
	je	L634
	cmpl	$8, %edi
	je	L635
L482:
	cmpl	$10, %edi
	je	L636
L483:
	cmpl	$6, %edi
	je	L637
L485:
	cmpl	$8, %edi
	je	L638
	cmpl	$10, %edi
	je	L639
	cmpl	$6, %edi
	je	L582
	cmpl	$8, %edi
	je	L583
	cmpl	$10, %edi
	je	L584
L540:
	leal	(%edi,%edi), %eax
	movl	16(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%ecx, (%esp)
	call	_set_text_column
	jmp	L606
L631:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	40(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L640
L473:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 40(%esi,%ebx)
	jmp	L472
L581:
	movl	-120(%ebp), %ecx
	movl	-116(%ebp), %esi
	movl	20(%ecx,%ebx), %eax
	movl	%eax, 20(%esi,%ebx)
	jmp	L448
L632:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L469
L633:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L471
L561:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	je	L562
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	je	L641
L562:
	movl	$LC98, (%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
L599:
	call	_g_strdup_printf
	movl	%eax, %edi
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	48(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L642
L564:
	movl	%edi, (%esp)
	call	_g_strdup
	movl	%eax, 48(%esi,%ebx)
	movl	12(%ebp), %edx
	leal	-40(%ebp), %ebx
	movl	%edx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	-44(%ebp), %ecx
	movl	%eax, %esi
	movl	%ebx, 4(%esp)
	movl	%ecx, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$-1, %ecx
	movl	$22, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 8(%esp)
	movl	%edi, 12(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_list_store_set
	movl	%esi, (%esp)
	call	_gtk_tree_path_free
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L643
L565:
	testl	%edi, %edi
	je	L426
	movl	%edi, (%esp)
	call	_g_free
	jmp	L426
L637:
	cmpl	$1, -48(%ebp)
	movl	%ebx, -56(%ebp)
	jg	L644
L487:
	cmpl	$2, -48(%ebp)
	jle	L582
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	44(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-56(%ebp), %eax
	jne	L582
L486:
	cmpl	$1, -48(%ebp)
	movl	$0, -68(%ebp)
	jg	L645
L488:
	cmpl	$2, -48(%ebp)
	jg	L646
L489:
	movl	-68(%ebp), %edx
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_MessageGeom
	movl	-68(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_free
L582:
	movl	$0, -84(%ebp)
	movl	-56(%ebp), %ecx
	xorl	%ebx, %ebx
	movl	-48(%ebp), %edx
	decl	%ecx
	movl	%ecx, %eax
	movl	%ecx, -104(%ebp)
	call	_get_distance_zmatrix
	movl	%eax, -80(%ebp)
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jle	L503
	movl	-60(%ebp), %eax
	movl	-48(%ebp), %esi
	decl	%eax
	movl	%esi, (%esp)
L593:
	movl	-104(%ebp), %edx
	call	_get_angle_zmatrix
	movl	%eax, -84(%ebp)
L504:
	movl	-64(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L506
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	leal	-1(%eax), %edx
	movl	-48(%ebp), %ecx
	movl	-64(%ebp), %eax
	movl	-104(%ebp), %esi
	movl	%ecx, 4(%esp)
	decl	%eax
	movl	%esi, (%esp)
L594:
	call	_get_dihedral_zmatrix
	movl	%eax, %ebx
L507:
	movl	-80(%ebp), %eax
	testl	%eax, %eax
	je	L509
	movl	-80(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_r_value
	testl	%eax, %eax
	jne	L647
L509:
	movl	-84(%ebp), %eax
	testl	%eax, %eax
	je	L511
	movl	-84(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_angle_value
	testl	%eax, %eax
	jne	L648
L511:
	testl	%ebx, %ebx
	je	L513
	movl	-48(%ebp), %eax
	movl	%ebx, %edx
	call	_reset_dihedral_value
	testl	%eax, %eax
	jne	L649
L513:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	28(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L650
L515:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 28(%esi,%ebx)
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jle	L516
	movl	_Geom, %ebx
	movl	36(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L517
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L517:
	movl	$LC45, (%esp)
	movl	-60(%ebp), %ecx
	movl	%ecx, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 36(%esi,%ebx)
	movl	$16, %eax
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	_Geom, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
L516:
	movl	-64(%ebp), %eax
	testl	%eax, %eax
	jle	L540
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	44(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L519
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L519:
	movl	-64(%ebp), %eax
	movl	%eax, 4(%esp)
L603:
	movl	$LC45, (%esp)
	call	_g_strdup_printf
	movl	%eax, 44(%esi,%ebx)
	movl	_Geom, %eax
	movl	$20, %ebx
	movl	%ebx, 4(%esp)
	movl	44(%esi,%eax), %eax
L598:
	movl	%eax, (%esp)
	movl	12(%ebp), %edx
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L540
L640:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L473
L627:
	movl	$LC90, (%esp)
	call	_g_strdup_printf
	jmp	L604
L638:
	movl	%ebx, -60(%ebp)
	movl	-48(%ebp), %esi
	testl	%esi, %esi
	jle	L493
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%ecx, %eax
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-60(%ebp), %eax
	je	L492
L493:
	cmpl	$2, -48(%ebp)
	jle	L583
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	44(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-60(%ebp), %eax
	jne	L583
L492:
	movl	$0, -72(%ebp)
	movl	-48(%ebp), %esi
	testl	%esi, %esi
	jle	L494
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	sall	$3, %eax
	subl	%ecx, %eax
	leal	0(,%eax,8), %esi
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	je	L651
L494:
	cmpl	$2, -48(%ebp)
	jg	L652
L495:
	movl	-72(%ebp), %esi
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_MessageGeom
	movl	%esi, (%esp)
	call	_g_free
L583:
	movl	$0, -88(%ebp)
	movl	-56(%ebp), %ecx
	xorl	%esi, %esi
	testl	%ecx, %ecx
	jle	L522
	movl	-56(%ebp), %ebx
	movl	-48(%ebp), %edx
	decl	%ebx
	movl	%ebx, %eax
	call	_get_distance_zmatrix
	movl	%eax, -88(%ebp)
	movl	-60(%ebp), %edx
	movl	-48(%ebp), %ecx
	decl	%edx
	movl	%edx, -108(%ebp)
	movl	-108(%ebp), %eax
	movl	%ecx, (%esp)
	movl	%ebx, %edx
L595:
	call	_get_angle_zmatrix
	movl	%eax, -92(%ebp)
	movl	-64(%ebp), %eax
	testl	%eax, %eax
	jle	L524
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ebx
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%ebx, %eax
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	-64(%ebp), %ecx
	decl	%eax
	movl	-48(%ebp), %esi
	movl	%eax, (%esp)
	movl	-108(%ebp), %edx
	decl	%ecx
	movl	%esi, 4(%esp)
	movl	%ecx, %eax
L597:
	call	_get_dihedral_zmatrix
	movl	%eax, %esi
L525:
	movl	-88(%ebp), %eax
	testl	%eax, %eax
	je	L529
	movl	-88(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_r_value
	testl	%eax, %eax
	je	L529
	movl	$10, %eax
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
L529:
	movl	-92(%ebp), %eax
	testl	%eax, %eax
	je	L531
	movl	-92(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_angle_value
	testl	%eax, %eax
	je	L531
	movl	-92(%ebp), %edx
	movl	$14, %ebx
	movl	-44(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	12(%ebp), %edx
	call	_set_text_column
L531:
	testl	%esi, %esi
	je	L533
	movl	-48(%ebp), %eax
	movl	%esi, %edx
	call	_reset_dihedral_value
	testl	%eax, %eax
	je	L533
	movl	%esi, (%esp)
	movl	12(%ebp), %edx
	movl	$18, %ecx
	movl	%ecx, 4(%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
L533:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	36(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L535
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L535:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	%eax, 36(%esi,%ebx)
	movl	-56(%ebp), %eax
	testl	%eax, %eax
	jle	L536
	movl	_Geom, %ebx
	movl	28(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L653
L537:
	movl	$LC45, (%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 28(%esi,%ebx)
	movl	$12, %eax
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
L536:
	movl	-64(%ebp), %eax
	testl	%eax, %eax
	jle	L540
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	44(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L654
L539:
	movl	-64(%ebp), %edx
	movl	%edx, 4(%esp)
	jmp	L603
L639:
	cmpl	$1, -48(%ebp)
	movl	%ebx, -64(%ebp)
	jg	L655
L499:
	movl	-48(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L584
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-64(%ebp), %eax
	jne	L584
L498:
	cmpl	$1, -48(%ebp)
	movl	$0, -76(%ebp)
	jg	L656
L500:
	movl	-48(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L501
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	je	L657
L501:
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	movl	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	_MessageGeom
	movl	-76(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
L584:
	movl	$0, -96(%ebp)
	movl	-56(%ebp), %ecx
	xorl	%esi, %esi
	movl	$0, -100(%ebp)
	testl	%ecx, %ecx
	jle	L542
	movl	-56(%ebp), %ebx
	movl	-48(%ebp), %edx
	decl	%ebx
	movl	%ebx, %eax
	call	_get_distance_zmatrix
	movl	%eax, -96(%ebp)
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	-48(%ebp), %ecx
	decl	%eax
	movl	%ebx, %edx
	movl	%ecx, (%esp)
	call	_get_angle_zmatrix
	movl	%eax, -100(%ebp)
L542:
	movl	-60(%ebp), %ecx
	movl	-56(%ebp), %ebx
	testl	%ecx, %ecx
	setg	%al
	shrl	$31, %ebx
	testl	%eax, %ebx
	je	L543
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	leal	-1(%eax), %edx
	movl	-60(%ebp), %eax
	movl	-48(%ebp), %ecx
	decl	%eax
	movl	%ecx, (%esp)
	call	_get_angle_zmatrix
	movl	%eax, -100(%ebp)
L543:
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jle	L544
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	-64(%ebp), %ecx
	decl	%eax
	movl	-60(%ebp), %edx
	movl	%eax, (%esp)
	movl	-48(%ebp), %esi
	decl	%ecx
	decl	%edx
	movl	%ecx, %eax
	movl	%esi, 4(%esp)
	call	_get_dihedral_zmatrix
	movl	%eax, %esi
L544:
	movl	-56(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L545
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	-48(%ebp), %ecx
	leal	-1(%eax), %edx
	movl	-64(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	-56(%ebp), %ecx
	decl	%eax
	decl	%ecx
	movl	%ecx, (%esp)
	call	_get_dihedral_zmatrix
	movl	%eax, %esi
L545:
	movl	-60(%ebp), %eax
	shrl	$31, %eax
	testl	%eax, %ebx
	je	L546
	movl	-48(%ebp), %ebx
	movl	-48(%ebp), %eax
	sall	$3, %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	leal	-1(%eax), %esi
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%esi, (%esp)
	leal	-1(%eax), %edx
	movl	-64(%ebp), %eax
	movl	-48(%ebp), %ecx
	decl	%eax
	movl	%ecx, 4(%esp)
	call	_get_dihedral_zmatrix
	movl	%eax, %esi
L546:
	movl	-96(%ebp), %eax
	testl	%eax, %eax
	je	L547
	movl	-96(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_r_value
	testl	%eax, %eax
	jne	L658
L547:
	movl	-100(%ebp), %eax
	testl	%eax, %eax
	je	L549
	movl	-100(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_angle_value
	testl	%eax, %eax
	jne	L659
L549:
	testl	%esi, %esi
	je	L551
	movl	-48(%ebp), %eax
	movl	%esi, %edx
	call	_reset_dihedral_value
	testl	%eax, %eax
	jne	L660
L551:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	44(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L553
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L553:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	%eax, 44(%esi,%ebx)
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jle	L554
	movl	_Geom, %ebx
	movl	36(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L661
L555:
	movl	$LC45, (%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 36(%esi,%ebx)
	movl	_Geom, %eax
	movl	$16, %ebx
	movl	%ebx, 4(%esp)
	movl	12(%ebp), %edx
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
L554:
	movl	-56(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L540
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	28(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L662
L557:
	movl	$LC45, (%esp)
	movl	-56(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 28(%esi,%ebx)
	movl	$12, %eax
	movl	%eax, 4(%esp)
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	jmp	L598
L618:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L574
L634:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L482
	jmp	L426
L635:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L483
	jmp	L426
L636:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%ecx, %eax
	movl	44(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L485
	jmp	L426
L506:
	cmpl	$2, -48(%ebp)
	jle	L507
	movl	-48(%ebp), %ebx
	movl	-48(%ebp), %eax
	sall	$3, %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	leal	-1(%eax), %esi
	movl	_Geom, %eax
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	-48(%ebp), %edx
	decl	%eax
	movl	-104(%ebp), %ecx
	movl	%edx, 4(%esp)
	movl	%esi, %edx
	movl	%ecx, (%esp)
	jmp	L594
L503:
	cmpl	$1, -48(%ebp)
	jle	L504
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	-48(%ebp), %edx
	decl	%eax
	movl	%edx, (%esp)
	jmp	L593
L650:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L515
L524:
	cmpl	$2, -48(%ebp)
	jle	L525
	movl	-56(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L527
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	44(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	-48(%ebp), %edx
	decl	%eax
	movl	%edx, 4(%esp)
	movl	-56(%ebp), %edx
	decl	%edx
	movl	%edx, (%esp)
	movl	-108(%ebp), %edx
	jmp	L597
L643:
	call	_rafresh_drawing
	jmp	L565
L642:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L564
L653:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L537
L644:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-56(%ebp), %eax
	jne	L487
	jmp	L486
L522:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	leal	-1(%eax), %edx
	movl	-60(%ebp), %eax
	movl	-48(%ebp), %ecx
	decl	%eax
	movl	%eax, -108(%ebp)
	movl	%ecx, (%esp)
	jmp	L595
L654:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L539
L648:
	movl	-84(%ebp), %eax
	movl	$14, %esi
	movl	12(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L511
L649:
	movl	%ebx, (%esp)
	movl	12(%ebp), %edx
	movl	$18, %ecx
	movl	%ecx, 4(%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L513
L647:
	movl	$10, %eax
	movl	-80(%ebp), %esi
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%esi, (%esp)
	call	_set_text_column
	jmp	L509
L641:
	movl	$LC51, (%esp)
	movl	16(%ebp), %esi
	movl	%esi, 4(%esp)
	jmp	L599
L617:
	movl	$LC102, (%esp)
	call	_g_strdup_printf
	jmp	L604
L662:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L557
L655:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-64(%ebp), %eax
	jne	L499
	jmp	L498
	.p2align 4,,7
L658:
	movl	$10, %eax
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L547
L659:
	movl	-100(%ebp), %edx
	movl	$14, %ebx
	movl	-44(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	12(%ebp), %edx
	call	_set_text_column
	jmp	L549
L660:
	movl	%esi, (%esp)
	movl	12(%ebp), %edx
	movl	$18, %ecx
	movl	%ecx, 4(%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L551
L661:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L555
L651:
	movl	_Geom, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -56(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC97, (%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp)
	jmp	L494
L652:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	_Geom, %eax
	movl	44(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L495
	movl	_Geom, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -64(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC96, (%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp)
	jmp	L495
L527:
	movl	-48(%ebp), %ebx
	movl	-48(%ebp), %eax
	sall	$3, %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	leal	-1(%eax), %esi
	movl	_Geom, %eax
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%esi, (%esp)
	movl	-48(%ebp), %ecx
	decl	%eax
	movl	-108(%ebp), %edx
	movl	%ecx, 4(%esp)
	jmp	L597
L657:
	movl	_Geom, %eax
	movl	44(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -56(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC97, (%esp)
	call	_g_strdup_printf
	movl	%eax, -76(%ebp)
	jmp	L501
L645:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	sall	$3, %eax
	subl	%ecx, %eax
	leal	0(,%eax,8), %esi
	movl	_Geom, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L488
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -60(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC95, (%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	jmp	L488
L656:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	_Geom, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L500
	movl	_Geom, %eax
	movl	44(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -60(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC95, (%esp)
	call	_g_strdup_printf
	movl	%eax, -76(%ebp)
	jmp	L500
L646:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	_Geom, %eax
	movl	44(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L489
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -64(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC96, (%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	jmp	L489
	.p2align 4,,15
	.def	_set_sensitive_option;	.scl	3;	.type	32;	.endef
_set_sensitive_option:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_ui_manager_get_widget
	movl	%eax, %ebx
	call	_gtk_widget_get_type
	testl	%ebx, %ebx
	je	L671
	movl	(%ebx), %edx
	testl	%edx, %edx
	jne	L674
L671:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L669
L673:
	movl	%ebx, (%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gtk_widget_set_sensitive
L669:
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L674:
	cmpl	%eax, (%edx)
	jne	L671
	jmp	L673
	.section .rdata,"dr"
LC105:
	.ascii "/MenuZMatGeom\0"
	.data
	.align 4
menuName.1:
	.long	LC105
	.section .rdata,"dr"
LC106:
	.ascii "destroy\0"
LC107:
	.ascii "GabeditListOfProject\0"
LC109:
	.ascii "MenuName\0"
LC108:
	.ascii "building menus failed: %s\0"
	.text
	.p2align 4,,15
	.def	_newMenuZMatGeom;	.scl	3;	.type	32;	.endef
_newMenuZMatGeom:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$28, %esp
	movl	$0, -16(%ebp)
	call	_gtk_ui_manager_new
	movl	%eax, 12(%esp)
	movl	%eax, %edi
	movl	$_g_object_unref, %eax
	movl	%eax, 8(%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%ecx, 20(%esp)
	movl	$LC106, %eax
	movl	%edx, 16(%esp)
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_signal_connect_data
	movl	$LC107, (%esp)
	call	_gtk_action_group_new
	movl	%eax, %ebx
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	movl	_numberOfGtkActionEntriesZMatGeom, %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	$_gtkActionEntriesZMatGeom, %eax
	movl	%eax, 4(%esp)
	call	_gtk_action_group_add_actions
	movl	%ebx, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	%edi, (%esp)
	call	_gtk_ui_manager_insert_action_group
	movl	%edi, (%esp)
	call	_gtk_ui_manager_get_accel_group
	movl	%eax, %ebx
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_add_accel_group
	movl	%edi, (%esp)
	leal	-16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$-1, %eax
	movl	%eax, 8(%esp)
	movl	_uiMenuZMatGeomInfo, %eax
	movl	%eax, 4(%esp)
	call	_gtk_ui_manager_add_ui_from_string
	testl	%eax, %eax
	je	L677
L676:
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	menuName.1, %edx
	movl	%edx, 8(%esp)
	movl	$LC109, %edx
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	addl	$28, %esp
	movl	%edi, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L677:
	movl	-16(%ebp), %eax
	movl	$LC108, %esi
	movl	$32, %ebx
	movl	8(%eax), %eax
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, 12(%esp)
	movl	$0, (%esp)
	call	_g_log
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_error_free
	jmp	L676
	.section .rdata,"dr"
LC110:
	.ascii "/MenuZMatVariables\0"
	.data
	.align 4
menuName.0:
	.long	LC110
	.text
	.p2align 4,,15
	.def	_newMenuZMatVariables;	.scl	3;	.type	32;	.endef
_newMenuZMatVariables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$28, %esp
	movl	$0, -16(%ebp)
	xorl	%ebx, %ebx
	call	_gtk_ui_manager_new
	movl	%ebx, 16(%esp)
	movl	$_g_object_unref, %ecx
	movl	$LC106, %edx
	movl	%ecx, 8(%esp)
	movl	%eax, %edi
	movl	$2, %eax
	movl	%edx, 4(%esp)
	movl	%eax, 20(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, (%esp)
	call	_g_signal_connect_data
	movl	$LC107, (%esp)
	call	_gtk_action_group_new
	movl	%eax, %ebx
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	movl	_numberOfGtkActionEntriesZMatVariables, %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	$_gtkActionEntriesZMatVariables, %eax
	movl	%eax, 4(%esp)
	call	_gtk_action_group_add_actions
	movl	%ebx, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	%edi, (%esp)
	call	_gtk_ui_manager_insert_action_group
	movl	%edi, (%esp)
	call	_gtk_ui_manager_get_accel_group
	movl	%eax, %ebx
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_add_accel_group
	movl	%edi, (%esp)
	leal	-16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$-1, %eax
	movl	%eax, 8(%esp)
	movl	_uiMenuZMatVariablesInfo, %eax
	movl	%eax, 4(%esp)
	call	_gtk_ui_manager_add_ui_from_string
	testl	%eax, %eax
	je	L680
L679:
	movl	%edi, (%esp)
	movl	$80, %esi
	movl	$LC109, %ebx
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	menuName.0, %edx
	movl	%ebx, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	addl	$28, %esp
	movl	%edi, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L680:
	movl	-16(%ebp), %eax
	movl	8(%eax), %eax
	movl	$0, (%esp)
	movl	%eax, 12(%esp)
	movl	$LC108, %eax
	movl	%eax, 8(%esp)
	movl	$32, %eax
	movl	%eax, 4(%esp)
	call	_g_log
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_error_free
	jmp	L679
	.p2align 4,,15
	.def	_freeList;	.scl	3;	.type	32;	.endef
_freeList:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	%eax, %edi
	pushl	%esi
	movl	%edx, %esi
	pushl	%ebx
	xorl	%ebx, %ebx
	subl	$12, %esp
	cmpl	%esi, %ebx
	jge	L688
	.p2align 4,,15
L691:
	movl	(%edi,%ebx,4), %eax
	testl	%eax, %eax
	jne	L690
	incl	%ebx
L692:
	cmpl	%esi, %ebx
	jl	L691
L688:
	movl	%edi, (%esp)
	call	_g_free
	addl	$12, %esp
	xorl	%eax, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L690:
	movl	%eax, (%esp)
	incl	%ebx
	call	_g_free
	jmp	L692
	.p2align 4,,15
.globl _FreeGeom
	.def	_FreeGeom;	.scl	2;	.type	32;	.endef
_FreeGeom:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %edi
	movl	16(%ebp), %edx
	movl	%eax, -16(%ebp)
	movl	20(%ebp), %eax
	movl	%edx, -20(%ebp)
	movl	%eax, -24(%ebp)
	xorl	%eax, %eax
	testl	%edi, %edi
	movl	%eax, _Dipole
	je	L713
	xorl	%esi, %esi
	cmpl	%edx, %esi
	jge	L722
	movl	$0, -28(%ebp)
	leal	48(%edi), %ebx
	jmp	L712
	.p2align 4,,7
L698:
	movl	-40(%ebx), %eax
	testl	%eax, %eax
	jne	L725
L699:
	movl	-36(%ebx), %eax
	testl	%eax, %eax
	jne	L726
L700:
	testl	%esi, %esi
	je	L701
	movl	-24(%ebx), %eax
	testl	%eax, %eax
	jne	L727
L702:
	movl	-20(%ebx), %eax
	testl	%eax, %eax
	jne	L728
L701:
	cmpl	$1, %esi
	jbe	L704
	movl	-16(%ebx), %eax
	testl	%eax, %eax
	jne	L729
L705:
	movl	-28(%ebp), %edx
	movl	36(%edx,%edi), %eax
	testl	%eax, %eax
	jne	L730
L704:
	cmpl	$2, %esi
	jbe	L707
	movl	-8(%ebx), %eax
	testl	%eax, %eax
	jne	L731
L708:
	movl	-28(%ebp), %edx
	movl	44(%edx,%edi), %eax
	testl	%eax, %eax
	jne	L732
L707:
	movl	(%ebx), %eax
	testl	%eax, %eax
	jne	L733
L710:
	movl	-28(%ebp), %edx
	movl	52(%edx,%edi), %eax
	testl	%eax, %eax
	jne	L734
	addl	$56, -28(%ebp)
	incl	%esi
	addl	$56, %ebx
	cmpl	-20(%ebp), %esi
	jge	L722
L712:
	movl	-44(%ebx), %eax
	testl	%eax, %eax
	je	L698
	movl	%eax, (%esp)
	call	_g_free
	movl	-40(%ebx), %eax
	testl	%eax, %eax
	je	L699
	.p2align 4,,15
L725:
	movl	%eax, (%esp)
	call	_g_free
	movl	-36(%ebx), %eax
	testl	%eax, %eax
	je	L700
	.p2align 4,,15
L726:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L700
	.p2align 4,,7
L734:
	movl	%eax, (%esp)
	incl	%esi
	call	_g_free
	addl	$56, -28(%ebp)
	addl	$56, %ebx
	cmpl	-20(%ebp), %esi
	jl	L712
	.p2align 4,,15
L722:
	testl	%edi, %edi
	je	L713
	movl	%edi, (%esp)
	call	_g_free
L713:
	movl	-16(%ebp), %eax
	testl	%eax, %eax
	je	L693
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	jg	L735
L724:
	movl	-16(%ebp), %eax
	movl	%eax, 8(%ebp)
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_g_free
	.p2align 4,,7
L733:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L710
	.p2align 4,,7
L728:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L701
	.p2align 4,,7
L727:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L702
	.p2align 4,,7
L732:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L707
	.p2align 4,,7
L731:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L708
	.p2align 4,,7
L730:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L704
	.p2align 4,,7
L729:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L705
L735:
	movl	-24(%ebp), %esi
	xorl	%ebx, %ebx
	jmp	L720
	.p2align 4,,7
L718:
	movl	-16(%ebp), %edx
	movl	4(%ebx,%edx), %eax
	testl	%eax, %eax
	jne	L736
L717:
	addl	$12, %ebx
	decl	%esi
	je	L724
L720:
	movl	-16(%ebp), %edx
	movl	(%ebx,%edx), %eax
	testl	%eax, %eax
	je	L718
	movl	%eax, (%esp)
	call	_g_free
	movl	-16(%ebp), %edx
	movl	4(%ebx,%edx), %eax
	testl	%eax, %eax
	je	L717
	.p2align 4,,15
L736:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L717
L693:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
.globl _freeGeom
	.def	_freeGeom;	.scl	2;	.type	32;	.endef
_freeGeom:
	pushl	%ebp
	xorl	%edx, %edx
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	_Geom, %eax
	movl	%edx, _Dipole
	testl	%eax, %eax
	je	L737
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	cmpl	_NcentersZmat, %esi
	jb	L745
	movl	%eax, (%esp)
	call	_g_free
	xorl	%eax, %eax
	movl	%eax, _Geom
	xorl	%eax, %eax
	movl	%eax, _NcentersZmat
	.p2align 4,,15
L737:
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L753:
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$1, %esi
	ja	L750
	.p2align 4,,15
L743:
	cmpl	$2, %esi
	ja	L751
L744:
	movl	_Geom, %eax
	incl	%esi
	movl	48(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	52(%ebx,%eax), %eax
	addl	$56, %ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	_NcentersZmat, %esi
	jae	L752
	movl	_Geom, %eax
L745:
	movl	4(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	8(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	12(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	testl	%esi, %esi
	jne	L753
	cmpl	$1, %esi
	jbe	L743
L750:
	movl	_Geom, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$2, %esi
	jbe	L744
	.p2align 4,,15
L751:
	movl	_Geom, %eax
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	jmp	L744
L752:
	movl	_Geom, %eax
	movl	%eax, (%esp)
	call	_g_free
	xorl	%eax, %eax
	movl	%eax, _Geom
	xorl	%eax, %eax
	movl	%eax, _NcentersZmat
	jmp	L737
	.p2align 4,,15
.globl _freeVariables
	.def	_freeVariables;	.scl	2;	.type	32;	.endef
_freeVariables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	_Variables, %eax
	testl	%eax, %eax
	je	L754
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	cmpl	_NVariables, %esi
	jb	L759
	movl	%eax, (%esp)
	xorl	%ebx, %ebx
	call	_g_free
	movl	%ebx, _Variables
	xorl	%ecx, %ecx
	movl	%ecx, _NVariables
	.p2align 4,,15
L754:
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L762:
	movl	_Variables, %eax
L759:
	movl	(%ebx,%eax), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_g_free
	movl	_Variables, %eax
	movl	4(%ebx,%eax), %eax
	addl	$12, %ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	_NVariables, %esi
	jb	L762
	movl	_Variables, %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_free
	movl	%ebx, _Variables
	xorl	%ecx, %ecx
	movl	%ecx, _NVariables
	jmp	L754
	.p2align 4,,15
	.def	_destroy_dialogue;	.scl	3;	.type	32;	.endef
_destroy_dialogue:
	pushl	%ebp
	movl	_DestroyDialog, %eax
	movl	%esp, %ebp
	testl	%eax, %eax
	jne	L765
	popl	%ebp
	ret
	.p2align 4,,7
L765:
	popl	%ebp
	jmp	_delete_child
	.section .rdata,"dr"
LC111:
	.ascii "%s.gzmt\0"
LC112:
	.ascii "w\0"
LC115:
	.ascii "%s\12\0"
LC117:
	.ascii "%s\11%s\11%s\11%s\11%s\12\0"
LC118:
	.ascii "%s\11%s\11%s\11%s\11%s\11%s\11%s\12\0"
LC119:
	.ascii " \12\0"
LC120:
	.ascii "%s\11%s\12\0"
LC116:
	.ascii "%s\11%s\11%s\12\0"
	.align 4
LC113:
	.ascii "Sorry,\12 I can not open %s file\0"
LC114:
	.ascii "Error\0"
	.text
	.p2align 4,,15
.globl _save_gzmatrix_file
	.def	_save_gzmatrix_file;	.scl	2;	.type	32;	.endef
_save_gzmatrix_file:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	$LC111, (%esp)
	call	_g_strdup_printf
	movl	%eax, -16(%ebp)
	movl	%ebx, (%esp)
	call	_g_free
	movl	$LC112, %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_FOpen
	movl	%eax, -24(%ebp)
	testl	%eax, %eax
	je	L811
	movl	_Geom, %eax
	movl	$LC115, %ebx
	movl	4(%eax), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	movl	_NcentersZmat, %edx
	cmpl	$1, %edx
	movl	%edx, -36(%ebp)
	ja	L812
L768:
	cmpl	$2, -36(%ebp)
	jbe	L772
	cmpl	$1, _Units
	je	L774
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L773
L774:
	movl	_Geom, %edx
	movl	144(%edx), %eax
	movl	%eax, 24(%esp)
	movl	148(%edx), %eax
	movl	%eax, 20(%esp)
	movl	136(%edx), %eax
	movl	%eax, 16(%esp)
	movl	140(%edx), %eax
	movl	%eax, 12(%esp)
	movl	116(%edx), %eax
	movl	%eax, 8(%esp)
	movl	$LC117, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	movl	_NcentersZmat, %edx
	movl	%edx, -36(%ebp)
L772:
	movl	$3, -20(%ebp)
	movl	-36(%ebp), %edx
	cmpl	%edx, -20(%ebp)
	jae	L798
	movl	$168, %ebx
	jmp	L782
	.p2align 4,,7
L780:
	movl	_Geom, %edx
	movl	40(%ebx,%edx), %eax
	movl	%eax, 32(%esp)
	movl	44(%ebx,%edx), %eax
	movl	%eax, 28(%esp)
	movl	32(%ebx,%edx), %eax
	movl	%eax, 24(%esp)
	movl	36(%ebx,%edx), %eax
	movl	%eax, 20(%esp)
	movl	24(%ebx,%edx), %eax
	movl	%eax, 16(%esp)
	movl	28(%ebx,%edx), %eax
	movl	%eax, 12(%esp)
	movl	4(%ebx,%edx), %eax
	addl	$56, %ebx
	movl	%eax, 8(%esp)
	movl	$LC118, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_fprintf
	incl	-20(%ebp)
	movl	-20(%ebp), %edx
	cmpl	_NcentersZmat, %edx
	jae	L798
L782:
	cmpl	$1, _Units
	je	L780
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L780
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_bohr_to_ang
	movl	_Geom, %ecx
	movl	40(%ebx,%ecx), %edx
	movl	%edx, 32(%esp)
	movl	44(%ebx,%ecx), %edx
	movl	%edx, 28(%esp)
	movl	32(%ebx,%ecx), %edx
	movl	%edx, 24(%esp)
	movl	36(%ebx,%ecx), %edx
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	movl	28(%ebx,%ecx), %eax
	movl	%eax, 12(%esp)
	movl	4(%ebx,%ecx), %eax
	addl	$56, %ebx
	movl	%eax, 8(%esp)
	movl	$LC118, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	incl	-20(%ebp)
	movl	-20(%ebp), %edx
	cmpl	_NcentersZmat, %edx
	jb	L782
L798:
	movl	-24(%ebp), %ecx
	movl	$2, %eax
	movl	%eax, 8(%esp)
	movl	$1, %eax
	movl	%ecx, 12(%esp)
	movl	%eax, 4(%esp)
	movl	$LC119, (%esp)
	call	_fwrite
	movl	$0, -20(%ebp)
	xorl	%eax, %eax
	cmpl	_NVariables, %eax
	jae	L800
	movl	$0, -40(%ebp)
	.p2align 4,,15
L795:
	cmpl	$1, _Units
	je	L813
L786:
	movl	_NcentersZmat, %edx
	movl	$1, %edi
	cmpl	%edx, %edi
	movl	%edx, -36(%ebp)
	jae	L802
	movl	_Geom, %ecx
	movl	$56, %ebx
	movl	_Variables, %esi
	movl	%ecx, -32(%ebp)
	movl	-40(%ebp), %edx
	movl	(%edx,%esi), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %ecx
	movl	24(%ebx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L803
	.p2align 4,,15
L814:
	incl	%edi
	addl	$56, %ebx
	cmpl	-36(%ebp), %edi
	jae	L793
	movl	-40(%ebp), %edx
	movl	(%edx,%esi), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %ecx
	movl	24(%ebx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L814
L803:
	movl	-40(%ebp), %edx
	movl	4(%edx,%esi), %eax
	movl	%eax, (%esp)
	call	_bohr_to_ang
	movl	%eax, 12(%esp)
	movl	-40(%ebp), %ecx
	movl	_Variables, %eax
L808:
	movl	(%ecx,%eax), %eax
	movl	$LC120, %edi
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	incl	-20(%ebp)
	addl	$12, -40(%ebp)
	movl	-20(%ebp), %eax
	cmpl	_NVariables, %eax
	jb	L795
L800:
	movl	-24(%ebp), %edx
	movl	$1, %ecx
	movl	$2, %ebx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	$LC119, (%esp)
	call	_fwrite
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_fclose
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_name_file
	movl	%eax, -28(%ebp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_get_suffix_name_file
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_get_name_file
	movl	%ebx, (%esp)
	movl	%eax, %edi
	call	_get_name_dir
	movl	%eax, %esi
	movl	_lastdirectory, %eax
	testl	%eax, %eax
	jne	L815
L796:
	movl	%esi, (%esp)
	call	_g_strdup
	movl	%eax, _lastdirectory
	movl	_defaultNetWorkProtocol, %eax
	xorl	%edx, %edx
	movl	%edx, 40(%esp)
	movl	%eax, 44(%esp)
	movl	$14, %eax
	movl	%eax, 36(%esp)
	xorl	%eax, %eax
	movl	%eax, 32(%esp)
	xorl	%eax, %eax
	movl	%eax, 28(%esp)
	xorl	%eax, %eax
	movl	%eax, 24(%esp)
	xorl	%eax, %eax
	movl	%eax, 20(%esp)
	movl	_noeud+56, %eax
	movl	%esi, 16(%esp)
	movl	-28(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	_treeViewProjects, %eax
	movl	%ecx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%eax, (%esp)
	call	_CreeFeuille
	movl	%ebx, (%esp)
	call	_g_free
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	movl	%esi, 8(%ebp)
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_g_free
L812:
	cmpl	$1, _Units
	je	L770
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L769
L770:
	movl	_Geom, %edx
	movl	$LC116, %ecx
	movl	80(%edx), %eax
	movl	%eax, 16(%esp)
	movl	84(%edx), %eax
	movl	%eax, 12(%esp)
	movl	60(%edx), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_fprintf
	movl	_NcentersZmat, %eax
	movl	%eax, -36(%ebp)
	jmp	L768
L802:
	movl	_Variables, %esi
L793:
	movl	-40(%ebp), %edx
	movl	4(%edx,%esi), %eax
	movl	%eax, 12(%esp)
	movl	(%edx,%esi), %eax
	movl	$LC120, %esi
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_fprintf
	incl	-20(%ebp)
	addl	$12, -40(%ebp)
	movl	-20(%ebp), %eax
	cmpl	_NVariables, %eax
	jae	L800
	cmpl	$1, _Units
	jne	L786
L813:
	movl	-40(%ebp), %ecx
	movl	_Variables, %eax
	movl	4(%ecx,%eax), %edx
	movl	%edx, 12(%esp)
	jmp	L808
L811:
	movl	-16(%ebp), %ecx
	movl	$LC113, (%esp)
	movl	$1, %edi
	movl	$LC114, %esi
	movl	%ecx, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	%eax, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_Message
	movl	%ebx, 8(%ebp)
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_g_free
L815:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L796
L769:
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_bohr_to_ang
	movl	%eax, 16(%esp)
	movl	_Geom, %edx
	movl	84(%edx), %eax
	movl	%eax, 12(%esp)
	movl	60(%edx), %eax
	movl	$LC116, %edx
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_fprintf
	movl	_NcentersZmat, %ecx
	movl	%ecx, -36(%ebp)
	jmp	L768
L773:
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_bohr_to_ang
	movl	_Geom, %ecx
	movl	144(%ecx), %edx
	movl	%edx, 24(%esp)
	movl	148(%ecx), %edx
	movl	%eax, 16(%esp)
	movl	%edx, 20(%esp)
	movl	140(%ecx), %eax
	movl	%eax, 12(%esp)
	movl	116(%ecx), %eax
	movl	%eax, 8(%esp)
	movl	$LC117, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_fprintf
	movl	_NcentersZmat, %eax
	movl	%eax, -36(%ebp)
	jmp	L772
	.section .rdata,"dr"
LC121:
	.ascii "Sorry\12 No selected file\0"
	.text
	.p2align 4,,15
.globl _save_geometry_gzmatrix_file
	.def	_save_geometry_gzmatrix_file;	.scl	2;	.type	32;	.endef
_save_geometry_gzmatrix_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$-5, 12(%ebp)
	movl	8(%ebp), %eax
	je	L820
	leave
	ret
	.p2align 4,,7
L820:
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	testl	%eax, %eax
	je	L819
	cmpb	$0, (%eax)
	jne	L818
L819:
	movl	$LC121, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	call	_Message
	leave
	ret
L818:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_gzmatrix_file
	.p2align 4,,15
.globl _save_gzmatrix_file_entry
	.def	_save_gzmatrix_file_entry;	.scl	2;	.type	32;	.endef
_save_gzmatrix_file_entry:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	testl	%eax, %eax
	je	L821
	cmpb	$0, (%eax)
	jne	L824
L821:
	leave
	ret
	.p2align 4,,7
L824:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_gzmatrix_file
	.section .rdata,"dr"
LC122:
	.ascii "%s.zmt\0"
	.align 4
LC123:
	.ascii "\12\12     MOPAC file created by Gabedit\12\0"
	.align 4
LC128:
	.ascii "%3s %20s %5s %20s %5s %20s %5s %5s %5s %5s\12\0"
LC125:
	.ascii "%20.10f\0"
LC126:
	.ascii "0\0"
	.align 8
LC127:
	.long	640652440
	.long	1071705861
	.text
	.p2align 4,,15
.globl _save_mzmatrix_file
	.def	_save_mzmatrix_file;	.scl	2;	.type	32;	.endef
_save_mzmatrix_file:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$156, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	$LC122, (%esp)
	call	_g_strdup_printf
	movl	%eax, 8(%ebp)
	movl	%ebx, (%esp)
	xorl	%ebx, %ebx
	call	_g_free
	movl	$LC112, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_FOpen
	movl	%eax, -80(%ebp)
	testl	%eax, %eax
	je	L883
	.p2align 4,,15
L830:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$9, %ebx
	jbe	L830
	movl	$LC123, (%esp)
	movl	-80(%ebp), %eax
	movl	$37, %edi
	movl	%edi, 8(%esp)
	movl	$1, %esi
	movl	%esi, 4(%esp)
	movl	%eax, 12(%esp)
	call	_fwrite
	movl	$0, -76(%ebp)
	xorl	%eax, %eax
	cmpl	_NcentersZmat, %eax
	jae	L867
	leal	-72(%ebp), %esi
	xorl	%edi, %edi
L862:
	xorl	%ebx, %ebx
	.p2align 4,,15
L837:
	movl	-72(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$9, %ebx
	jbe	L837
	cmpl	$2, -76(%ebp)
	jg	L852
	cmpl	$1, -76(%ebp)
	je	L842
	jle	L884
	cmpl	$2, -76(%ebp)
	je	L846
	cmpl	$3, -76(%ebp)
	je	L852
L861:
	movl	-36(%ebp), %eax
	addl	$56, %edi
	movl	%eax, 44(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-64(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-72(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC128, %eax
	movl	%eax, 4(%esp)
	movl	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	incl	-76(%ebp)
	movl	-76(%ebp), %eax
	cmpl	_NcentersZmat, %eax
	jb	L862
L867:
	movl	$48, (%esp)
	movl	-80(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_fputc
	movl	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_name_file
	movl	%eax, -84(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_get_name_file
	movl	%ebx, (%esp)
	movl	%eax, %edi
	call	_get_name_dir
	movl	%eax, %esi
	movl	_lastdirectory, %eax
	testl	%eax, %eax
	jne	L885
L863:
	movl	%esi, (%esp)
	call	_g_strdup
	movl	%eax, _lastdirectory
	movl	_defaultNetWorkProtocol, %eax
	movl	$15, %ecx
	movl	%ecx, 36(%esp)
	xorl	%edx, %edx
	movl	%edx, 32(%esp)
	movl	%eax, 44(%esp)
	xorl	%eax, %eax
	movl	%eax, 40(%esp)
	xorl	%eax, %eax
	movl	%eax, 28(%esp)
	xorl	%eax, %eax
	movl	%eax, 24(%esp)
	xorl	%eax, %eax
	movl	%eax, 20(%esp)
	movl	-84(%ebp), %eax
	movl	%esi, 16(%esp)
	movl	%edi, 8(%esp)
	movl	%eax, 12(%esp)
	movl	_noeud+60, %eax
	movl	%eax, 4(%esp)
	movl	_treeViewProjects, %eax
	movl	%eax, (%esp)
	call	_CreeFeuille
	movl	%ebx, (%esp)
	call	_g_free
	movl	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	movl	%esi, (%esp)
L880:
	call	_g_free
	addl	$156, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L885:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L863
	.p2align 4,,7
L852:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L853
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L876:
	fstpl	-96(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L855
	fldl	-96(%ebp)
	fmull	LC127
	fstpl	-96(%ebp)
L855:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L856
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L877:
	fstpl	-104(%ebp)
	movl	_Geom, %eax
	movl	40(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L858
	movl	_Geom, %eax
	movl	40(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L878:
	fstpl	-112(%ebp)
	movl	_Geom, %eax
	movl	4(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	fldl	-96(%ebp)
	movl	%eax, (%esi)
	movl	$LC125, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	fldl	-104(%ebp)
	movl	%eax, 8(%esi)
	movl	$LC125, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 12(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	fldl	-112(%ebp)
	movl	%eax, 16(%esi)
	movl	$LC125, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 20(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	movl	%eax, 24(%esi)
	movl	_Geom, %eax
	movl	28(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%esi)
	movl	_Geom, %eax
	movl	36(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 32(%esi)
	movl	_Geom, %eax
	movl	44(%edi,%eax), %eax
	movl	%eax, (%esp)
L879:
	call	_g_strdup
	movl	%eax, 36(%esi)
	jmp	L861
L853:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L876
L858:
	movl	_Geom, %eax
	movl	40(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L878
L856:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L877
L884:
	movl	-76(%ebp), %ebx
	testl	%ebx, %ebx
	jne	L861
	movl	_Geom, %eax
	movl	4(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, (%esi)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC125, (%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	movl	%eax, 8(%esi)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$LC125, (%esp)
	call	_g_strdup_printf
	movl	%eax, 12(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	movl	%eax, 16(%esi)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$LC125, (%esp)
	call	_g_strdup_printf
	movl	%eax, 20(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	movl	%eax, 24(%esi)
	movl	$LC126, (%esp)
L881:
	call	_g_strdup
	movl	%eax, 28(%esi)
	movl	$LC126, (%esp)
L882:
	call	_g_strdup
	movl	%eax, 32(%esi)
	movl	$LC126, (%esp)
	jmp	L879
L842:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L843
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L873:
	fstpl	-96(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L845
	fldl	-96(%ebp)
	fmull	LC127
	fstpl	-96(%ebp)
L845:
	movl	_Geom, %eax
	xorl	%ebx, %ebx
	movl	4(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	fldl	-96(%ebp)
	movl	%eax, (%esi)
	movl	$LC125, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	movl	%eax, 8(%esi)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, 8(%esp)
	movl	$LC125, (%esp)
	call	_g_strdup_printf
	movl	%eax, 12(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	movl	%eax, 16(%esi)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC125, (%esp)
	call	_g_strdup_printf
	movl	%eax, 20(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	movl	%eax, 24(%esi)
	movl	_Geom, %eax
	movl	28(%edi,%eax), %eax
	movl	%eax, (%esp)
	jmp	L881
L846:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L847
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L874:
	fstpl	-96(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L849
	fldl	-96(%ebp)
	fmull	LC127
	fstpl	-96(%ebp)
L849:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L850
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L875:
	fstpl	-104(%ebp)
	movl	_Geom, %eax
	movl	4(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	fldl	-96(%ebp)
	movl	%eax, (%esi)
	movl	$LC125, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	fldl	-104(%ebp)
	movl	%eax, 8(%esi)
	movl	$LC125, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 12(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	movl	%eax, 16(%esi)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$LC125, (%esp)
	call	_g_strdup_printf
	movl	%eax, 20(%esi)
	movl	$LC126, (%esp)
	call	_g_strdup
	movl	%eax, 24(%esi)
	movl	_Geom, %eax
	movl	28(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%esi)
	movl	_Geom, %eax
	movl	36(%edi,%eax), %eax
	movl	%eax, (%esp)
	jmp	L882
L843:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L873
L847:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L874
L850:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L875
L883:
	movl	$LC113, (%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC114, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_Message
	movl	%ebx, (%esp)
	jmp	L880
	.p2align 4,,15
.globl _save_geometry_mzmatrix_file
	.def	_save_geometry_mzmatrix_file;	.scl	2;	.type	32;	.endef
_save_geometry_mzmatrix_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$-5, 12(%ebp)
	movl	8(%ebp), %eax
	je	L890
	leave
	ret
	.p2align 4,,7
L890:
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	testl	%eax, %eax
	je	L889
	cmpb	$0, (%eax)
	jne	L888
L889:
	movl	$LC121, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	call	_Message
	leave
	ret
L888:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_mzmatrix_file
	.p2align 4,,15
.globl _save_mzmatrix_file_entry
	.def	_save_mzmatrix_file_entry;	.scl	2;	.type	32;	.endef
_save_mzmatrix_file_entry:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	testl	%eax, %eax
	je	L891
	cmpb	$0, (%eax)
	jne	L894
L891:
	leave
	ret
	.p2align 4,,7
L894:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_mzmatrix_file
	.section .rdata,"dr"
LC131:
	.ascii "ButtonGZmat\0"
LC132:
	.ascii "Entry\0"
	.text
	.p2align 4,,15
.globl _save_gmzmatrix_file
	.def	_save_gmzmatrix_file;	.scl	2;	.type	32;	.endef
_save_gmzmatrix_file:
	pushl	%ebp
	movl	$80, %eax
	movl	%esp, %ebp
	pushl	%esi
	movl	$LC131, %esi
	pushl	%ebx
	subl	$16, %esp
	movl	8(%ebp), %ebx
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_g_object_get_data
	movl	%ebx, (%esp)
	movl	$80, %ecx
	movl	%eax, %esi
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC132, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	call	_gtk_toggle_button_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	testb	$1, 88(%eax)
	je	L896
	movl	%ebx, 8(%ebp)
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	jmp	_save_gzmatrix_file_entry
	.p2align 4,,7
L896:
	movl	%ebx, 8(%ebp)
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	jmp	_save_mzmatrix_file_entry
	.p2align 4,,15
.globl _reset_extended_gzmat_file
	.def	_reset_extended_gzmat_file;	.scl	2;	.type	32;	.endef
_reset_extended_gzmat_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ebx, -12(%ebp)
	movl	%esi, -8(%ebp)
	movl	%edi, -4(%ebp)
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -16(%ebp)
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %edi
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	$LC111, (%esp)
	call	_g_strdup_printf
	movl	%edi, 4(%esp)
	movl	%eax, %ebx
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, (%esp)
	call	_g_free
	movl	%esi, 8(%ebp)
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	jmp	_g_free
	.p2align 4,,15
.globl _reset_extended_mzmat_file
	.def	_reset_extended_mzmat_file;	.scl	2;	.type	32;	.endef
_reset_extended_mzmat_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ebx, -12(%ebp)
	movl	%esi, -8(%ebp)
	movl	%edi, -4(%ebp)
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -16(%ebp)
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %edi
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	$LC122, (%esp)
	call	_g_strdup_printf
	movl	%edi, 4(%esp)
	movl	%eax, %ebx
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, (%esp)
	call	_g_free
	movl	%esi, 8(%ebp)
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	jmp	_g_free
	.section .rdata,"dr"
LC135:
	.ascii "*.gzmt *.zmt\0"
LC136:
	.ascii "*.gzmt\0"
LC137:
	.ascii "*.zmt\0"
LC138:
	.ascii "*\0"
	.data
	.align 4
patterns.2:
	.long	LC135
	.long	LC136
	.long	LC137
	.long	LC138
	.long	0
	.section .rdata,"dr"
LC133:
	.ascii " File  : \0"
LC134:
	.ascii "Save in Z-matrix file\0"
LC141:
	.ascii "%s%s%s.gzmt\0"
LC140:
	.ascii "\\\0"
LC142:
	.ascii " Save Z-matrix \0"
LC143:
	.ascii "delete_event\0"
LC144:
	.ascii "Type of file\0"
LC145:
	.ascii "Gaussian Z-matrix \0"
LC146:
	.ascii "Mopac Z-matrix\0"
LC147:
	.ascii "clicked\0"
LC148:
	.ascii "ButtonMZmat\0"
LC149:
	.ascii "Cancel\0"
LC150:
	.ascii "OK\0"
LC139:
	.ascii " Sorry No Center  !\0"
	.text
	.p2align 4,,15
.globl _create_window_save_zmat
	.def	_create_window_save_zmat;	.scl	2;	.type	32;	.endef
_create_window_save_zmat:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	_WindowGeom, %eax
	movl	%eax, -36(%ebp)
	movl	$LC133, (%esp)
	call	_g_strdup
	movl	%eax, -40(%ebp)
	movl	$LC134, (%esp)
	call	_g_strdup
	movl	%eax, %esi
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	je	L903
	movl	-36(%ebp), %ebx
	testl	%ebx, %ebx
	je	L904
L902:
	movl	$LC141, (%esp)
	movl	_fileopen, %eax
	movl	$LC140, %ecx
	movl	%ecx, 8(%esp)
	xorl	%edi, %edi
	movl	%eax, 12(%esp)
	movl	_fileopen+24, %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -44(%ebp)
	movl	$0, (%esp)
	call	_gtk_window_new
	movl	%eax, -16(%ebp)
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	call	_gtk_window_set_title
	movl	%ebx, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_position
	movl	%ebx, 4(%esp)
	movl	_Fenetre, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -48(%ebp)
	movl	%ebx, 4(%esp)
	movl	-16(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-48(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_window_set_transient_for
	movl	$LC142, %eax
	movl	%eax, 12(%esp)
	movl	$_gtk_widget_destroy, %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	call	_add_child
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_delete_child, %ecx
	movl	$LC143, %edx
	movl	%ecx, 8(%esp)
	movl	%edi, 20(%esp)
	xorl	%edi, %edi
	movl	%esi, 16(%esp)
	xorl	%esi, %esi
	movl	%ebx, 12(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_gtk_widget_destroy, %ecx
	movl	$LC143, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edi, 20(%esp)
	movl	$5, %edi
	movl	%esi, 16(%esp)
	movl	$5, %esi
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	call	_gtk_container_get_type
	movl	%eax, -52(%ebp)
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_container_set_border_width
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_vbox
	movl	%eax, -20(%ebp)
	movl	$LC144, (%esp)
	call	_gtk_frame_new
	movl	%eax, %ebx
	movl	-52(%ebp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_set_border_width
	movl	-52(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_container_add
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	%ebx, (%esp)
	movl	$10, %ebx
	call	_create_vbox
	movl	%eax, -24(%ebp)
	movl	%ebx, 4(%esp)
	movl	$1, (%esp)
	call	_gtk_hbox_new
	movl	-52(%ebp), %edx
	movl	%eax, %esi
	movl	%edx, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edi, %edi
	xorl	%ebx, %ebx
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	movl	$LC145, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_radio_button_new_with_label
	movl	%eax, -28(%ebp)
	call	_gtk_box_get_type
	movl	%eax, -56(%ebp)
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 12(%esp)
	movl	$5, %edx
	xorl	%edi, %edi
	movl	%ebx, 8(%esp)
	movl	$patterns.2, %ebx
	movl	%edx, 16(%esp)
	movl	-28(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	call	_gtk_radio_button_get_type
	movl	%eax, 4(%esp)
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_radio_button_get_group
	movl	%eax, (%esp)
	movl	$LC146, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_radio_button_new_with_label
	movl	%eax, -32(%ebp)
	movl	-56(%ebp), %eax
	movl	%esi, (%esp)
	xorl	%esi, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 12(%esp)
	movl	$5, %edx
	xorl	%edi, %edi
	movl	%esi, 8(%esp)
	xorl	%esi, %esi
	movl	%edx, 16(%esp)
	movl	-32(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hseparator
	movl	%ebx, 16(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-40(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-36(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_browser
	movl	%eax, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC132, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hseparator
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_reset_extended_gzmat_file, %ecx
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edi, 20(%esp)
	xorl	%edi, %edi
	movl	%esi, 16(%esp)
	xorl	%esi, %esi
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 20(%esp)
	movl	$_reset_extended_mzmat_file, %ecx
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	$80, %edi
	movl	%esi, 16(%esp)
	movl	$LC131, %esi
	movl	%ebx, 12(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%edi, 4(%esp)
	movl	-16(%ebp), %edx
	movl	$80, %edi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	-28(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	$LC132, %esi
	movl	%edx, 8(%esp)
	movl	%eax, (%esp)
	call	_g_object_set_data
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-32(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 8(%esp)
	movl	$LC148, %edx
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	movl	%edi, 4(%esp)
	movl	-16(%ebp), %eax
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 8(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 4(%esp)
	call	_g_object_set_data
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hseparator
	movl	%ebx, 4(%esp)
	movl	$LC149, %ebx
	movl	$0, (%esp)
	call	_gtk_hbox_new
	movl	%eax, %esi
	movl	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$5, %ecx
	xorl	%edx, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_realize
	movl	%ebx, 4(%esp)
	movl	-16(%ebp), %edx
	xorl	%ebx, %ebx
	movl	%edx, (%esp)
	call	_create_button
	movl	%eax, %edi
	movl	-56(%ebp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$3, %ecx
	xorl	%edx, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_end
	call	_gtk_object_get_type
	movl	%eax, -60(%ebp)
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%eax, %ebx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 12(%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 20(%esp)
	movl	$LC147, %ebx
	movl	$_delete_child, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	-60(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	$LC150, %ecx
	movl	%ecx, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_button
	movl	%eax, %edi
	movl	-56(%ebp), %eax
	movl	%esi, (%esp)
	xorl	%esi, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$3, %edx
	movl	%edx, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_end
	movl	-60(%ebp), %edx
	movl	%edi, (%esp)
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	%edi, (%esp)
	call	_gtk_widget_grab_default
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	-60(%ebp), %eax
	xorl	%esi, %esi
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%eax, %ebx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	$_save_gmzmatrix_file, %ecx
	movl	%edx, 20(%esp)
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	%esi, 16(%esp)
	xorl	%esi, %esi
	movl	%ebx, 12(%esp)
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	%eax, %ebx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	$2, %edi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_delete_child, %ecx
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show_all
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L903:
	movl	$LC139, (%esp)
	movl	$1, %edi
	movl	$LC48, %esi
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L904:
	movl	_Fenetre, %edx
	movl	%edx, -36(%ebp)
	jmp	L902
	.p2align 4,,15
	.def	_ChangeVariablesUseds;	.scl	3;	.type	32;	.endef
_ChangeVariablesUseds:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	cmpl	_NVariables, %eax
	movl	$0, -16(%ebp)
	jae	L924
	movl	$0, -32(%ebp)
	movl	_Variables, %edx
	movl	_NcentersZmat, %ecx
	movl	_Geom, %eax
	movl	%edx, -24(%ebp)
	movl	%ecx, -20(%ebp)
	movl	%eax, -28(%ebp)
	.p2align 4,,15
L922:
	xorl	%edi, %edi
	xorl	%esi, %esi
	cmpl	-20(%ebp), %edi
	jae	L910
	movl	-28(%ebp), %ebx
	.p2align 4,,15
L921:
	cmpl	$5, (%ebx)
	jle	L912
	movl	24(%ebx), %eax
	movl	-32(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L926
	testl	%edi, %edi
	jne	L910
L912:
	cmpl	$7, (%ebx)
	jle	L915
	movl	32(%ebx), %eax
	movl	-32(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L926
	testl	%edi, %edi
	jne	L910
L915:
	cmpl	$9, (%ebx)
	jle	L911
	movl	40(%ebx), %eax
	movl	-32(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L926
	testl	%edi, %edi
	jne	L910
L911:
	incl	%esi
	addl	$56, %ebx
	cmpl	-20(%ebp), %esi
	jb	L921
L910:
	incl	-16(%ebp)
	movl	-32(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%edi, 8(%eax,%edx)
	addl	$12, %eax
	cmpl	_NVariables, %ecx
	movl	%eax, -32(%ebp)
	jb	L922
L924:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L926:
	incl	-16(%ebp)
	movl	$1, %edi
	movl	-32(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%edi, 8(%eax,%edx)
	addl	$12, %eax
	cmpl	_NVariables, %ecx
	movl	%eax, -32(%ebp)
	jb	L922
	jmp	L924
	.p2align 4,,15
.globl _AllocationVariable
	.def	_AllocationVariable;	.scl	2;	.type	32;	.endef
_AllocationVariable:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	_Variables, %edx
	testl	%edx, %edx
	je	L928
	movl	_NVariables, %eax
	movl	%edx, (%esp)
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	%eax, 4(%esp)
	call	_g_realloc
	movl	%eax, _Variables
	leave
	ret
	.p2align 4,,7
L928:
	movl	_NVariables, %eax
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, _Variables
	leave
	ret
	.p2align 4,,15
.globl _AddVariableZmat
	.def	_AddVariableZmat;	.scl	2;	.type	32;	.endef
_AddVariableZmat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ebx, -12(%ebp)
	movl	%esi, -8(%ebp)
	movl	8(%ebp), %esi
	movl	%edi, -4(%ebp)
	movl	12(%ebp), %edi
	incl	_NVariables
	call	_AllocationVariable
	movl	_NVariables, %ebx
	movl	_Variables, %eax
	movl	%esi, (%esp)
	leal	(%ebx,%ebx,2), %ebx
	sall	$2, %ebx
	addl	%eax, %ebx
	call	_g_strdup
	movl	%eax, -12(%ebx)
	movl	_NVariables, %ebx
	movl	_Variables, %eax
	movl	%edi, (%esp)
	leal	(%ebx,%ebx,2), %ebx
	sall	$2, %ebx
	addl	%eax, %ebx
	subl	$12, %ebx
	call	_g_strdup
	movl	%eax, 4(%ebx)
	movl	%esi, (%esp)
	call	_g_strdup
	movl	%eax, -24(%ebp)
	movl	%edi, (%esp)
	call	_g_strdup
	movl	%eax, -20(%ebp)
	movl	16(%ebp), %eax
	testl	%eax, %eax
	jne	L933
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L933:
	movl	$2, (%esp)
	leal	-24(%ebp), %edx
	movl	_listv, %eax
	call	_appendToList
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.section .rdata,"dr"
LC151:
	.ascii "%c%s%d\0"
	.text
	.p2align 4,,15
	.def	_trans_coord_Zmat;	.scl	3;	.type	32;	.endef
_trans_coord_Zmat:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	movb	%al, -25(%ebp)
	movl	%edx, %eax
	sall	$3, %eax
	movl	%edx, -32(%ebp)
	subl	%edx, %eax
	leal	0(,%eax,8), %ebx
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	cmpb	$65, -25(%ebp)
	fstpl	-40(%ebp)
	je	L947
	cmpb	$68, -25(%ebp)
	je	L948
L936:
	movl	-32(%ebp), %eax
	incl	%eax
	movl	%eax, 12(%esp)
	movl	_Geom, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, 8(%esp)
	movsbl	-25(%ebp),%eax
	movl	$LC151, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	fldl	-40(%ebp)
	movl	%eax, -44(%ebp)
	movl	$LC53, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, -48(%ebp)
	movl	-44(%ebp), %eax
	call	_testav
	testl	%eax, %eax
	movl	%eax, %edi
	js	L938
	movl	_Variables, %ebx
	leal	(%eax,%eax,2), %eax
	leal	0(,%eax,4), %esi
	movl	4(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L949
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%esi,%ebx)
	movl	8(%ebp), %ebx
	testl	%ebx, %ebx
	jne	L950
L937:
	cmpb	$82, -25(%ebp)
	je	L951
L956:
	cmpb	$65, -25(%ebp)
	je	L952
	cmpb	$68, -25(%ebp)
	je	L953
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L949:
	movl	%eax, (%esp)
	call	_g_free
	movl	-48(%ebp), %eax
	movl	_Variables, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%esi,%ebx)
	movl	8(%ebp), %ebx
	testl	%ebx, %ebx
	je	L937
	.p2align 4,,15
L950:
	movl	_Variables, %edx
	movl	(%esi,%edx), %eax
	movl	%eax, -24(%ebp)
	movl	4(%esi,%edx), %eax
	movl	%edi, %edx
	movl	%eax, -20(%ebp)
	movl	_listv, %eax
	call	_removeFromList
	leal	-24(%ebp), %eax
	movl	$2, %ecx
	movl	%edi, %edx
	movl	%eax, (%esp)
	movl	_listv, %eax
	movl	%ecx, 4(%esp)
	call	_insertToList
	cmpb	$82, -25(%ebp)
	jne	L956
	.p2align 4,,15
L951:
	movl	-32(%ebp), %esi
	movl	-32(%ebp), %edx
	movl	-44(%ebp), %eax
	movl	_Geom, %ebx
	sall	$3, %esi
	subl	%edx, %esi
	movl	%eax, (%esp)
	sall	$3, %esi
	call	_g_strdup
	movl	%eax, 24(%esi,%ebx)
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L947:
	movl	_Geom, %eax
	movl	32(%ebx,%eax), %eax
L946:
	movl	%eax, (%esp)
	call	_atof
	fstpl	-40(%ebp)
	jmp	L936
	.p2align 4,,7
L948:
	movl	_Geom, %eax
	movl	40(%ebx,%eax), %eax
	jmp	L946
	.p2align 4,,7
L952:
	movl	-32(%ebp), %esi
	movl	-32(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %esi
	subl	%eax, %esi
	movl	%edx, (%esp)
	sall	$3, %esi
	call	_g_strdup
	movl	%eax, 32(%esi,%ebx)
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L953:
	movl	-32(%ebp), %esi
	movl	-32(%ebp), %eax
	movl	_Geom, %ebx
	sall	$3, %esi
	subl	%eax, %esi
	movl	-44(%ebp), %eax
	sall	$3, %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 40(%esi,%ebx)
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L938:
	movl	8(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	call	_AddVariableZmat
	jmp	L937
	.p2align 4,,15
.globl _set_variable_one_atom_in_GeomZMatrix
	.def	_set_variable_one_atom_in_GeomZMatrix;	.scl	2;	.type	32;	.endef
_set_variable_one_atom_in_GeomZMatrix:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$4, %esp
	movl	8(%ebp), %ebx
	testl	%ebx, %ebx
	jle	L958
	movl	_Geom, %edx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	movl	24(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L961
L958:
	cmpl	$1, %ebx
	jg	L962
L959:
	cmpl	$2, %ebx
	jg	L963
L960:
	popl	%eax
	popl	%ebx
	popl	%ebp
	jmp	_ChangeVariablesUseds
	.p2align 4,,7
L963:
	movl	_Geom, %edx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	movl	40(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L960
	movl	$0, (%esp)
	movl	%ebx, %edx
	movl	$68, %eax
	call	_trans_coord_Zmat
	jmp	L960
	.p2align 4,,7
L962:
	movl	_Geom, %edx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	movl	32(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L959
	movl	$0, (%esp)
	movl	%ebx, %edx
	movl	$65, %eax
	call	_trans_coord_Zmat
	jmp	L959
	.p2align 4,,7
L961:
	movl	$0, (%esp)
	movl	%ebx, %edx
	movl	$82, %eax
	call	_trans_coord_Zmat
	jmp	L958
	.p2align 4,,15
.globl _trans_OneGeom_to_variables
	.def	_trans_OneGeom_to_variables;	.scl	2;	.type	32;	.endef
_trans_OneGeom_to_variables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$80, %esp
	xorl	%ebx, %ebx
	movl	8(%ebp), %esi
	.p2align 4,,15
L968:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jbe	L968
	testl	%esi, %esi
	jne	L977
L969:
	cmpl	$1, %esi
	ja	L978
L970:
	cmpl	$2, %esi
	ja	L979
L971:
	movl	$LC45, (%esp)
	leal	1(%esi), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp)
	leal	0(,%esi,8), %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %ebx
	movl	_Geom, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -68(%ebp)
	movl	_Geom, %eax
	movl	8(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -64(%ebp)
	movl	_Geom, %eax
	movl	12(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -60(%ebp)
	movl	_Geom, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -56(%ebp)
	testl	%esi, %esi
	jne	L980
L972:
	cmpl	$1, %esi
	ja	L981
L973:
	cmpl	$2, %esi
	ja	L982
L974:
	movl	_Geom, %eax
	movl	48(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -28(%ebp)
	movl	_Geom, %eax
	movl	52(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -24(%ebp)
	movl	_list, %eax
	movl	%esi, %edx
	call	_removeFromList
	movl	$13, %eax
	movl	%esi, %edx
	movl	%eax, 4(%esp)
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	_list, %eax
	call	_insertToList
	call	_ChangeVariablesUseds
	addl	$80, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
L977:
	movl	_Geom, %edx
	leal	0(,%esi,8), %eax
	subl	%esi, %eax
	movl	24(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L969
	movl	12(%ebp), %eax
	testl	%eax, %eax
	je	L969
	movl	$1, (%esp)
	movl	%esi, %edx
	movl	$82, %eax
	call	_trans_coord_Zmat
	jmp	L969
L982:
	movl	_Geom, %eax
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -36(%ebp)
	movl	_Geom, %eax
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -32(%ebp)
	jmp	L974
L981:
	movl	_Geom, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -44(%ebp)
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -40(%ebp)
	jmp	L973
L980:
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -52(%ebp)
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -48(%ebp)
	jmp	L972
L979:
	movl	_Geom, %edx
	leal	0(,%esi,8), %eax
	subl	%esi, %eax
	movl	40(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L971
	movl	20(%ebp), %eax
	testl	%eax, %eax
	je	L971
	movl	$1, (%esp)
	movl	%esi, %edx
	movl	$68, %eax
	call	_trans_coord_Zmat
	jmp	L971
L978:
	movl	_Geom, %edx
	leal	0(,%esi,8), %eax
	subl	%esi, %eax
	movl	32(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L970
	movl	16(%ebp), %eax
	testl	%eax, %eax
	je	L970
	movl	$1, (%esp)
	movl	%esi, %edx
	movl	$65, %eax
	call	_trans_coord_Zmat
	jmp	L970
	.p2align 4,,15
.globl _trans_allGeom_to_variables
	.def	_trans_allGeom_to_variables;	.scl	2;	.type	32;	.endef
_trans_allGeom_to_variables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	je	L983
	xorl	%ebx, %ebx
	cmpl	%eax, %ebx
	jae	L991
	.p2align 4,,15
L993:
	movl	%ebx, (%esp)
	movl	$1, %eax
	movl	$1, %ecx
	movl	%eax, 12(%esp)
	movl	$1, %edx
	incl	%ebx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_trans_OneGeom_to_variables
	cmpl	_NcentersZmat, %ebx
	jb	L993
L991:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L983
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	jmp	_rafresh_drawing
	.p2align 4,,7
L983:
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,15
.globl _ModifyCoord
	.def	_ModifyCoord;	.scl	2;	.type	32;	.endef
_ModifyCoord:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movzbl	8(%ebp), %edx
	movl	%ebx, -12(%ebp)
	movl	16(%ebp), %ecx
	movl	%esi, -8(%ebp)
	movl	12(%ebp), %ebx
	movl	%edi, -4(%ebp)
	cmpb	$82, %dl
	je	L1001
	cmpb	$65, %dl
	je	L1002
	xorl	%eax, %eax
	cmpb	$68, %dl
	je	L1003
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L1001:
	leal	(%ecx,%ecx,2), %eax
	movl	_Variables, %edi
	leal	0(,%eax,4), %esi
	movl	_Geom, %eax
	movl	%eax, -16(%ebp)
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	leal	0(,%eax,8), %ebx
	movl	(%esi,%edi), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	24(%ebx,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L1004
L1000:
	movl	$1, %eax
L1005:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L1002:
	leal	(%ecx,%ecx,2), %eax
	movl	_Variables, %edi
	leal	0(,%eax,4), %esi
	movl	_Geom, %eax
	movl	%eax, -20(%ebp)
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	leal	0(,%eax,8), %ebx
	movl	(%esi,%edi), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %edx
	movl	32(%ebx,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L1000
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-20(%ebp), %edx
	movl	%eax, 32(%ebx,%edx)
	movl	$1, %eax
	jmp	L1005
	.p2align 4,,7
L1003:
	leal	(%ecx,%ecx,2), %eax
	movl	_Variables, %edi
	leal	0(,%eax,4), %esi
	movl	_Geom, %eax
	movl	%eax, -24(%ebp)
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	leal	0(,%eax,8), %ebx
	movl	(%esi,%edi), %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	40(%ebx,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L1000
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-24(%ebp), %edx
	movl	%eax, 40(%ebx,%edx)
	movl	$1, %eax
	jmp	L1005
L1004:
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-16(%ebp), %edx
	movl	%eax, 24(%ebx,%edx)
	movl	$1, %eax
	jmp	L1005
	.p2align 4,,15
.globl _OneVariableToConst
	.def	_OneVariableToConst;	.scl	2;	.type	32;	.endef
_OneVariableToConst:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	movl	8(%ebp), %ecx
	movl	_Variables, %edx
	leal	(%ecx,%ecx,2), %eax
	movl	8(%edx,%eax,4), %eax
	testl	%eax, %eax
	je	L1006
	xorl	%edi, %edi
	cmpl	_NcentersZmat, %edi
	jae	L1031
	.p2align 4,,15
L1044:
	xorl	%ebx, %ebx
	testl	%edi, %edi
	jne	L1038
	cmpl	$1, %edi
	ja	L1039
L1012:
	cmpl	$2, %edi
	ja	L1040
L1013:
	testl	%ebx, %ebx
	leal	1(%edi), %esi
	je	L1010
	xorl	%ebx, %ebx
	.p2align 4,,15
L1018:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jbe	L1018
	movl	$LC45, (%esp)
	leal	1(%edi), %esi
	movl	%esi, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -88(%ebp)
	leal	0(,%edi,8), %eax
	subl	%edi, %eax
	leal	0(,%eax,8), %ebx
	movl	_Geom, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -84(%ebp)
	movl	_Geom, %eax
	movl	8(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -80(%ebp)
	movl	_Geom, %eax
	movl	12(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -76(%ebp)
	movl	_Geom, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp)
	testl	%edi, %edi
	jne	L1041
L1019:
	cmpl	$1, %edi
	ja	L1042
L1020:
	cmpl	$2, %edi
	ja	L1043
L1021:
	movl	_Geom, %eax
	movl	48(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -44(%ebp)
	movl	_Geom, %eax
	movl	52(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -40(%ebp)
	movl	_list, %eax
	movl	%edi, %edx
	call	_removeFromList
	movl	$13, %eax
	movl	%edi, %edx
	movl	%eax, 4(%esp)
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	_list, %eax
	call	_insertToList
L1010:
	movl	%esi, %edi
	cmpl	_NcentersZmat, %edi
	jb	L1044
L1031:
	movl	_NVariables, %ecx
	movl	8(%ebp), %edi
	leal	-1(%ecx), %eax
	cmpl	%edi, %eax
	jbe	L1035
	movl	_Variables, %edx
	leal	(%edi,%edi,2), %eax
	leal	0(,%eax,4), %esi
	.p2align 4,,15
L1027:
	leal	(%esi,%edx), %ebx
	incl	%edi
	movl	12(%ebx), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, (%ebx)
	movl	_Variables, %ebx
	movl	16(%ebx,%esi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%esi,%ebx)
	movl	_Variables, %edx
	movl	_NVariables, %ecx
	movl	20(%edx,%esi), %eax
	movl	%eax, 8(%esi,%edx)
	leal	-1(%ecx), %eax
	addl	$12, %esi
	cmpl	%edi, %eax
	ja	L1027
L1035:
	leal	-1(%ecx), %eax
	testl	%eax, %eax
	movl	%eax, _NVariables
	je	L1028
	call	_AllocationVariable
L1029:
	movl	8(%ebp), %edx
	movl	_listv, %eax
	call	_removeFromList
L1006:
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1040:
	movl	%edi, 4(%esp)
	movl	8(%ebp), %eax
	movl	$68, (%esp)
	movl	%eax, 8(%esp)
	call	_ModifyCoord
	addl	%eax, %ebx
	jmp	L1013
L1038:
	movl	%edi, 4(%esp)
	movl	8(%ebp), %eax
	movl	$82, (%esp)
	movl	%eax, 8(%esp)
	call	_ModifyCoord
	cmpl	$1, %edi
	movl	%eax, %ebx
	jbe	L1012
L1039:
	movl	%edi, 4(%esp)
	movl	8(%ebp), %ecx
	movl	$65, (%esp)
	movl	%ecx, 8(%esp)
	call	_ModifyCoord
	addl	%eax, %ebx
	jmp	L1012
L1043:
	movl	_Geom, %eax
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -52(%ebp)
	movl	_Geom, %eax
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -48(%ebp)
	jmp	L1021
L1042:
	movl	_Geom, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -60(%ebp)
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -56(%ebp)
	jmp	L1020
L1041:
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -68(%ebp)
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -64(%ebp)
	jmp	L1019
L1028:
	call	_freeVariables
	jmp	L1029
	.p2align 4,,15
	.def	_trans_allVariables_to_Constants;	.scl	3;	.type	32;	.endef
_trans_allVariables_to_Constants:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	movl	_NVariables, %eax
	movl	$0, -20(%ebp)
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -24(%ebp)
	movl	_NVariables, %eax
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -28(%ebp)
	movl	_NVariables, %eax
	cmpl	%eax, %edi
	jae	L1073
	movl	$0, -40(%ebp)
	movl	_Variables, %esi
	movl	$0, -44(%ebp)
	.p2align 4,,15
L1057:
	movl	-24(%ebp), %edx
	movl	-44(%ebp), %ecx
	movl	$0, (%edx,%edi,4)
	movl	8(%ecx,%esi), %ebx
	testl	%ebx, %ebx
	je	L1048
	xorl	%ebx, %ebx
	cmpl	_NcentersZmat, %ebx
	jb	L1056
	jmp	L1075
	.p2align 4,,7
L1053:
	cmpl	$1, %ebx
	ja	L1082
L1054:
	cmpl	$2, %ebx
	ja	L1083
L1052:
	incl	%ebx
	cmpl	_NcentersZmat, %ebx
	jae	L1084
L1056:
	testl	%ebx, %ebx
	je	L1053
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$82, (%esp)
	call	_ModifyCoord
	cmpl	$1, %ebx
	jbe	L1054
	.p2align 4,,15
L1082:
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$65, (%esp)
	call	_ModifyCoord
	cmpl	$2, %ebx
	jbe	L1052
	.p2align 4,,15
L1083:
	movl	%ebx, 4(%esp)
	incl	%ebx
	movl	%edi, 8(%esp)
	movl	$68, (%esp)
	call	_ModifyCoord
	cmpl	_NcentersZmat, %ebx
	jb	L1056
	.p2align 4,,15
L1084:
	movl	_Variables, %esi
L1075:
	incl	-20(%ebp)
	xorl	%ecx, %ecx
	movl	-24(%ebp), %eax
	movl	-40(%ebp), %edx
	movl	$1, (%eax,%edi,4)
	movl	_NVariables, %eax
	movl	%ecx, 8(%edx,%esi)
L1048:
	addl	$12, -44(%ebp)
	incl	%edi
	addl	$12, -40(%ebp)
	cmpl	%eax, %edi
	jb	L1057
L1073:
	xorl	%edi, %edi
	cmpl	%eax, %edi
	jae	L1077
	movl	_Variables, %esi
	xorl	%ebx, %ebx
	.p2align 4,,15
L1061:
	movl	(%ebx,%esi), %eax
	incl	%edi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-28(%ebp), %ecx
	movl	%eax, (%ebx,%ecx)
	movl	_Variables, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-28(%ebp), %edx
	movl	_Variables, %esi
	movl	%eax, 4(%ebx,%edx)
	movl	8(%ebx,%esi), %eax
	movl	%eax, 8(%ebx,%edx)
	movl	_NVariables, %eax
	addl	$12, %ebx
	cmpl	%eax, %edi
	jb	L1061
L1077:
	movl	%eax, -16(%ebp)
	xorl	%edi, %edi
	call	_freeVariables
	movl	-16(%ebp), %eax
	movl	-20(%ebp), %edx
	subl	%edx, %eax
	movl	%eax, _NVariables
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	cmpl	-16(%ebp), %edi
	movl	%eax, %esi
	movl	%eax, _Variables
	jae	L1079
	movl	$0, -32(%ebp)
	movl	$-12, -36(%ebp)
	jmp	L1066
	.p2align 4,,7
L1064:
	addl	$12, -32(%ebp)
	incl	%edi
	cmpl	-16(%ebp), %edi
	jae	L1079
L1066:
	movl	-24(%ebp), %ecx
	movl	(%ecx,%edi,4), %eax
	testl	%eax, %eax
	jne	L1064
	addl	$12, -36(%ebp)
	incl	%edi
	movl	-32(%ebp), %edx
	movl	-28(%ebp), %ecx
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-36(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	_Variables, %ebx
	movl	%eax, (%edx,%esi)
	movl	-28(%ebp), %edx
	movl	4(%ecx,%edx), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-36(%ebp), %ecx
	movl	-32(%ebp), %edx
	movl	_Variables, %esi
	movl	%eax, 4(%ecx,%ebx)
	movl	-28(%ebp), %ecx
	addl	$12, -32(%ebp)
	cmpl	-16(%ebp), %edi
	movl	8(%edx,%ecx), %eax
	movl	-36(%ebp), %edx
	movl	%eax, 8(%edx,%esi)
	jb	L1066
L1079:
	movl	_listv, %eax
	xorl	%edi, %edi
	call	_clearList
	call	_append_list_variables
	movl	_list, %eax
	call	_clearList
	call	_append_list_geom
	cmpl	_NVariables, %edi
	jae	L1081
	xorl	%ebx, %ebx
	.p2align 4,,15
L1070:
	movl	-28(%ebp), %ecx
	incl	%edi
	movl	(%ebx,%ecx), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-28(%ebp), %edx
	movl	4(%ebx,%edx), %eax
	addl	$12, %ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	_NVariables, %edi
	jb	L1070
L1081:
	movl	-28(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_free
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1085
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1085:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_rafresh_drawing
	.section .rdata,"dr"
	.align 8
LC157:
	.long	-1717986918
	.long	1072273817
	.align 8
LC158:
	.long	640652440
	.long	1071705861
	.text
	.p2align 4,,15
	.def	_set_entry_Zmat;	.scl	3;	.type	32;	.endef
_set_entry_Zmat:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$912, %esp
	call	_rand
	call	_rand
	movl	_NcentersZmat, %esi
	testl	%esi, %esi
	je	L1086
	movl	_InEdit, %ebx
	testl	%ebx, %ebx
	je	L1088
	movl	_LineSelected, %ecx
	testl	%ecx, %ecx
	jle	L1086
L1088:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	_Entry+4, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, 4(%esp)
	leal	-872(%ebp), %edx
	movl	%edx, (%esp)
	call	_prop_atom_get
	movl	_NcentersZmat, %edx
	subl	$4, %esp
	leal	-584(%ebp), %ecx
	leal	0(,%edx,8), %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	sall	$3, %eax
	addl	%edx, %eax
	movl	-52(%eax), %eax
	movl	%ecx, (%esp)
	movl	%eax, 4(%esp)
	call	_prop_atom_get
	fldl	-568(%ebp)
	subl	$4, %esp
	cmpl	$1, _Units
	faddl	-856(%ebp)
	fmull	LC157
	je	L1095
L1089:
	fstl	-904(%ebp)
	xorl	%eax, %eax
	movl	%eax, -896(%ebp)
	movl	$1079721984, %eax
	movl	%eax, -892(%ebp)
	xorl	%eax, %eax
	movl	%eax, -888(%ebp)
	movl	$1080459264, %eax
	fstpl	4(%esp)
	movl	%eax, -884(%ebp)
	movl	$LC53, (%esp)
	call	_g_strdup_printf
	movl	%esi, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+20, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	cmpl	$1, _NcentersZmat
	jbe	L1094
	movl	_InEdit, %eax
	testl	%eax, %eax
	je	L1090
	cmpl	$1, _LineSelected
	jle	L1094
L1090:
	fldl	-896(%ebp)
	movl	$LC53, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	_Entry+28, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	cmpl	$2, _NcentersZmat
	jbe	L1094
	movl	_InEdit, %esi
	testl	%esi, %esi
	je	L1092
	cmpl	$2, _LineSelected
	jle	L1094
L1092:
	fldl	-888(%ebp)
	movl	$LC53, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	_Entry+36, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	.p2align 4,,15
L1094:
	movl	%ebx, (%esp)
	call	_g_free
L1086:
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L1095:
	fmull	LC158
	jmp	L1089
	.p2align 4,,15
	.def	_SetAtom;	.scl	3;	.type	32;	.endef
_SetAtom:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	12(%ebp), %esi
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+8, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
	movl	_Entry+12, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
	movl	_Entry+4, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
	movl	_Entry+16, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_entry_set_text
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	_Entry+4, %eax
	movl	%eax, (%esp)
	call	_gtk_editable_set_editable
	movl	_FenetreTable, %eax
	movl	%eax, (%esp)
	call	_gtk_widget_destroy
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	jmp	_set_entry_Zmat
	.section .rdata,"dr"
LC160:
	.ascii "Select your atom\0"
LC163:
	.ascii "00\0"
	.align 8
LC161:
	.long	-1717986918
	.long	1071225241
	.align 4
LC162:
	.long	1056964608
	.text
	.p2align 4,,15
	.def	_SelectAtom;	.scl	3;	.type	32;	.endef
_SelectAtom:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$1, %edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	call	_get_periodic_table
	movl	%eax, -36(%ebp)
	movl	$0, (%esp)
	call	_gtk_window_new
	movl	%eax, _FenetreTable
	movl	%eax, %ebx
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	%ebx, (%esp)
	movl	$LC160, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_window_set_modal
	movl	%esi, 4(%esp)
	movl	_FenetreTable, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_title
	movl	%esi, 4(%esp)
	movl	_FenetreTable, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	fildl	_ScreenHeight
	fnstcw	-14(%ebp)
	movzwl	-14(%ebp), %edx
	fmull	LC161
	orw	$3072, %dx
	movw	%dx, -16(%ebp)
	fldcw	-16(%ebp)
	fistpl	8(%esp)
	fldcw	-14(%ebp)
	fildl	_ScreenWidth
	fmuls	LC162
	fldcw	-16(%ebp)
	fistpl	4(%esp)
	fldcw	-14(%ebp)
	movl	%eax, (%esp)
	call	_gtk_window_set_default_size
	movl	$0, (%esp)
	call	_gtk_frame_new
	movl	%eax, %ebx
	call	_gtk_frame_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$4, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_frame_set_shadow_type
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_set_border_width
	movl	%esi, 4(%esp)
	movl	_FenetreTable, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_container_add
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	$9, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$18, %eax
	movl	%eax, 4(%esp)
	call	_gtk_table_new
	movl	%eax, -20(%ebp)
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	-20(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_container_add
	movl	_FenetreTable, %eax
	movl	%eax, (%esp)
	call	_gtk_widget_get_style
	movl	%eax, -32(%ebp)
	movl	$0, -24(%ebp)
	.p2align 4,,15
L1106:
	movl	$0, -28(%ebp)
	movl	-24(%ebp), %ecx
	incl	%ecx
	movl	%ecx, -40(%ebp)
	jmp	L1105
	.p2align 4,,7
L1103:
	movl	%esi, -28(%ebp)
	cmpl	$17, %esi
	ja	L1112
L1105:
	cld
	movl	-28(%ebp), %esi
	movl	$LC163, %edi
	movl	-36(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	(%edx,%esi,4), %eax
	movl	(%eax,%ecx,4), %ebx
	movl	$3, %ecx
	movl	%ebx, %esi
	repe
	cmpsb
	movl	-28(%ebp), %ecx
	seta	%dl
	setb	%al
	cmpb	%al, %dl
	leal	1(%ecx), %esi
	je	L1103
	movl	%ebx, (%esp)
	call	_gtk_button_new_with_label
	movl	-36(%ebp), %edx
	movl	%eax, %ebx
	xorl	%edi, %edi
	movl	-28(%ebp), %esi
	movl	-24(%ebp), %ecx
	movl	(%edx,%esi,4), %eax
	movl	(%eax,%ecx,4), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-32(%ebp), %esi
	movl	%esi, (%esp)
	xorl	%esi, %esi
	call	_set_button_style
	movl	%ebx, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 20(%esp)
	movl	$1, %edi
	movl	%esi, 16(%esp)
	movl	-28(%ebp), %ecx
	movl	-36(%ebp), %esi
	movl	(%esi,%ecx,4), %edx
	movl	-24(%ebp), %ecx
	movl	(%edx,%ecx,4), %edx
	movl	%eax, (%esp)
	movl	$_SetAtom, %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 12(%esp)
	movl	$LC147, %edx
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	call	_gtk_table_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %esi
	movl	%esi, (%esp)
	movl	$1, %esi
	call	_g_type_check_instance_cast
	movl	%edi, 36(%esp)
	movl	$5, %ecx
	movl	$5, %edx
	movl	%esi, 32(%esp)
	movl	%ecx, 28(%esp)
	movl	%edx, 24(%esp)
	movl	-40(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	-28(%ebp), %esi
	incl	%esi
	movl	%esi, 12(%esp)
	movl	-28(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	movl	%edx, 8(%esp)
	call	_gtk_table_attach
	movl	%esi, -28(%ebp)
	cmpl	$17, %esi
	jbe	L1105
	.p2align 4,,15
L1112:
	movl	-40(%ebp), %ecx
	cmpl	$8, %ecx
	movl	%ecx, -24(%ebp)
	jbe	L1106
	movl	_FenetreTable, %eax
	movl	%eax, 8(%ebp)
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_show_all
	.p2align 4,,15
	.def	_DelAtom;	.scl	3;	.type	32;	.endef
_DelAtom:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	_NcentersZmat, %edx
	decl	%edx
	cmpl	$-1, %edx
	movl	%edx, _NcentersZmat
	jle	L1114
	leal	0(,%edx,8), %eax
	subl	%edx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	movl	_Geom, %eax
	movl	%eax, (%esp)
	call	_g_realloc
	movl	%eax, _Geom
	movl	_NcentersZmat, %edx
	movl	_list, %eax
	call	_removeFromList
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1118
	cmpl	$1, _iprogram
	je	L1119
L1117:
	leave
	jmp	_ChangeVariablesUseds
	.p2align 4,,7
L1118:
	call	_rafresh_drawing
	cmpl	$1, _iprogram
	jne	L1117
	.p2align 4,,15
L1119:
	call	_set_spin_of_electrons
	leave
	jmp	_ChangeVariablesUseds
	.p2align 4,,7
L1114:
	call	_freeGeom
	leave
	jmp	_ChangeVariablesUseds
	.section .rdata,"dr"
LC166:
	.ascii "Sorry a Entry text is void !\12\0"
LC165:
	.ascii " Warning \0"
	.text
	.p2align 4,,15
	.def	_AddAtom;	.scl	3;	.type	32;	.endef
_AddAtom:
	pushl	%ebp
	movl	$1, %ecx
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	xorl	%ebx, %ebx
	movl	$0, -92(%ebp)
	movl	%ecx, _DestroyDialog
	.p2align 4,,15
L1124:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jle	L1124
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+4, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -84(%ebp)
	movl	_Entry+8, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -80(%ebp)
	movl	_Entry+12, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -76(%ebp)
	movl	_Entry+16, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp)
	movl	-84(%ebp), %eax
	testl	%eax, %eax
	je	L1120
	cmpb	$0, (%eax)
	je	L1120
	movl	_NcentersZmat, %ecx
	movl	_Geom, %edx
	incl	%ecx
	movl	%ecx, _NcentersZmat
	testl	%edx, %edx
	je	L1193
	movl	%edx, (%esp)
	leal	0(,%ecx,8), %eax
	subl	%ecx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	call	_g_realloc
L1190:
	movl	%eax, _Geom
	movl	_NcentersZmat, %eax
	movl	$LC45, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -88(%ebp)
	movl	_NcentersZmat, %edx
	leal	0(,%edx,8), %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	sall	$3, %eax
	addl	%edx, %eax
	leal	-56(%eax), %ebx
	movl	$5, -56(%eax)
	movl	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx)
	movl	_NcentersZmat, %eax
	leal	0(,%eax,8), %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	addl	%eax, %ebx
	movl	-80(%ebp), %eax
	subl	$56, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	movl	_NcentersZmat, %eax
	movl	_Geom, %edi
	leal	0(,%eax,8), %ebx
	subl	%eax, %ebx
	movl	-76(%ebp), %eax
	sall	$3, %ebx
	addl	%edi, %ebx
	subl	$56, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	movl	_NcentersZmat, %eax
	movl	_Geom, %esi
	leal	0(,%eax,8), %ebx
	subl	%eax, %ebx
	movl	-72(%ebp), %eax
	sall	$3, %ebx
	addl	%esi, %ebx
	subl	$56, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 16(%ebx)
	movl	_NcentersZmat, %edx
	cmpl	$1, %edx
	je	L1194
	movl	_Geom, %edi
	leal	0(,%edx,8), %eax
	xorl	%ecx, %ecx
	subl	%edx, %eax
	xorl	%esi, %esi
	movl	%ecx, -36(%edi,%eax,8)
	leal	-1(%edx), %eax
	cmpl	$0, %eax
	jle	L1183
	movl	%edx, -96(%ebp)
	movl	%edx, %ecx
	leal	20(%edi), %ebx
	.p2align 4,,15
L1134:
	leal	0(,%ecx,8), %eax
	subl	%ecx, %eax
	leal	-56(%edi,%eax,8), %edx
	movl	(%ebx), %eax
	cmpl	%eax, 20(%edx)
	jge	L1132
	movl	%eax, 20(%edx)
	movl	-96(%ebp), %ecx
L1132:
	incl	%esi
	leal	-1(%ecx), %eax
	addl	$56, %ebx
	cmpl	%esi, %eax
	jg	L1134
L1176:
	leal	0(,%ecx,8), %eax
	subl	%ecx, %eax
	incl	-36(%edi,%eax,8)
L1129:
	movl	_NcentersZmat, %ecx
	cmpl	$1, %ecx
	ja	L1195
L1135:
	cmpl	$2, %ecx
	seta	%al
	xorl	%edx, %edx
	cmpl	$0, -92(%ebp)
	sete	%dl
	testl	%eax, %edx
	jne	L1196
L1145:
	cmpl	$3, %ecx
	seta	%al
	xorl	%edx, %edx
	cmpl	$0, -92(%ebp)
	sete	%dl
	testl	%eax, %edx
	jne	L1197
L1155:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	_Entry+44, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -44(%ebp)
	movl	_NcentersZmat, %edx
	movl	%eax, (%esp)
	leal	0(,%edx,8), %ebx
	subl	%edx, %ebx
	movl	_Geom, %edx
	sall	$3, %ebx
	addl	%edx, %ebx
	subl	$56, %ebx
	call	_g_strdup
	cmpl	$3, _iprogram
	movl	%eax, 48(%ebx)
	je	L1165
	movl	%esi, 4(%esp)
	movl	_Entry+48, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
L1191:
	call	_g_strdup
	movl	%eax, -40(%ebp)
	movl	%eax, %edx
	movl	_NcentersZmat, %eax
	movl	%edx, (%esp)
	leal	0(,%eax,8), %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	addl	%eax, %ebx
	subl	$56, %ebx
	call	_g_strdup
	movl	%eax, 52(%ebx)
	movl	-92(%ebp), %eax
	testl	%eax, %eax
	je	L1198
	movl	_NcentersZmat, %edx
	decl	%edx
	testl	%edx, %edx
	movl	%edx, _NcentersZmat
	jne	L1199
	xorl	%eax, %eax
L1192:
	movl	%eax, _Geom
L1120:
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1193:
	movl	$56, (%esp)
	call	_g_malloc
	jmp	L1190
L1198:
	movl	$13, (%esp)
	movl	_list, %eax
	leal	-88(%ebp), %edx
	call	_appendToList
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1200
L1168:
	cmpl	$1, _iprogram
	jne	L1120
	call	_set_spin_of_electrons
	jmp	L1120
L1197:
	call	_gtk_entry_get_type
	movl	$9, %ebx
	movl	%eax, %esi
L1159:
	movl	%esi, 4(%esp)
	movl	_Entry(,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$10, %ebx
	jle	L1159
	movl	-52(%ebp), %edx
	testl	%edx, %edx
	je	L1161
	cmpb	$0, (%edx)
	je	L1161
L1160:
	movl	%edx, %eax
	call	_testav
	cmpl	$-1, %eax
	movl	%eax, %ebx
	jle	L1162
	leal	(%eax,%eax,2), %edx
	movl	_Variables, %eax
	movl	$1, %ecx
	movl	%ecx, 8(%eax,%edx,4)
L1162:
	incl	%ebx
	jl	L1201
L1163:
	movl	_NcentersZmat, %edx
	movl	_Geom, %edi
	leal	0(,%edx,8), %eax
	subl	%edx, %eax
	sall	$3, %eax
	addl	%edi, %eax
	movl	$11, -56(%eax)
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1202
L1189:
	movl	-52(%ebp), %edx
L1164:
	movl	%edx, (%esp)
	movl	_NcentersZmat, %eax
	movl	_Geom, %esi
	leal	0(,%eax,8), %ebx
	subl	%eax, %ebx
	sall	$3, %ebx
	addl	%esi, %ebx
	subl	$56, %ebx
	call	_g_strdup
	movl	%eax, 40(%ebx)
	movl	_NcentersZmat, %eax
	movl	_Geom, %ecx
	leal	0(,%eax,8), %ebx
	subl	%eax, %ebx
	movl	-48(%ebp), %eax
	sall	$3, %ebx
	addl	%ecx, %ebx
	subl	$56, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 44(%ebx)
	jmp	L1155
L1196:
	call	_gtk_entry_get_type
	movl	$7, %ebx
	movl	%eax, %esi
L1149:
	movl	%esi, 4(%esp)
	movl	_Entry(,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$8, %ebx
	jle	L1149
	movl	-60(%ebp), %edx
	testl	%edx, %edx
	je	L1151
	cmpb	$0, (%edx)
	je	L1151
L1150:
	movl	%edx, %eax
	call	_testav
	cmpl	$-1, %eax
	movl	%eax, %ebx
	jle	L1152
	leal	(%eax,%eax,2), %edx
	movl	_Variables, %eax
	movl	$1, %ecx
	movl	%ecx, 8(%eax,%edx,4)
L1152:
	incl	%ebx
	jl	L1203
L1153:
	movl	_NcentersZmat, %edx
	leal	0(,%edx,8), %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	sall	$3, %eax
	addl	%edx, %eax
	movl	$9, -56(%eax)
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1204
L1187:
	movl	-60(%ebp), %edx
L1154:
	movl	%edx, (%esp)
	movl	_NcentersZmat, %eax
	leal	0(,%eax,8), %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	addl	%eax, %ebx
	subl	$56, %ebx
	call	_g_strdup
	movl	%eax, 32(%ebx)
	movl	_NcentersZmat, %eax
	leal	0(,%eax,8), %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	addl	%eax, %ebx
	movl	-56(%ebp), %eax
	subl	$56, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 36(%ebx)
	movl	_NcentersZmat, %ecx
	jmp	L1145
L1195:
	call	_gtk_entry_get_type
	movl	$5, %ebx
	movl	%eax, %esi
L1139:
	movl	%esi, 4(%esp)
	movl	_Entry(,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$6, %ebx
	jle	L1139
	movl	-68(%ebp), %edx
	testl	%edx, %edx
	je	L1141
	cmpb	$0, (%edx)
	je	L1141
L1140:
	movl	%edx, %eax
	call	_testav
	cmpl	$-1, %eax
	movl	%eax, %ebx
	jle	L1142
	leal	(%eax,%eax,2), %edx
	movl	_Variables, %eax
	movl	$1, %ecx
	movl	%ecx, 8(%eax,%edx,4)
L1142:
	incl	%ebx
	jl	L1205
L1143:
	movl	_NcentersZmat, %edx
	leal	0(,%edx,8), %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	sall	$3, %eax
	addl	%edx, %eax
	movl	$7, -56(%eax)
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1206
L1185:
	movl	-68(%ebp), %edx
L1144:
	movl	%edx, (%esp)
	movl	_NcentersZmat, %eax
	leal	0(,%eax,8), %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	addl	%eax, %ebx
	subl	$56, %ebx
	call	_g_strdup
	movl	%eax, 24(%ebx)
	movl	_NcentersZmat, %eax
	leal	0(,%eax,8), %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	addl	%eax, %ebx
	movl	-64(%ebp), %eax
	subl	$56, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%ebx)
	movl	_NcentersZmat, %ecx
	jmp	L1135
L1165:
	movl	$LC46, (%esp)
	jmp	L1191
L1194:
	movl	_Geom, %eax
	movl	$0, 20(%eax)
	jmp	L1129
L1199:
	leal	0(,%edx,8), %eax
	subl	%edx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	movl	_Geom, %eax
	movl	%eax, (%esp)
	call	_g_realloc
	jmp	L1192
L1141:
	movl	$LC166, (%esp)
	movl	$1, %edi
	movl	$LC165, %esi
	movl	%edi, 8(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, _DestroyDialog
	movl	-68(%ebp), %edx
	movl	$1, -92(%ebp)
	jmp	L1140
L1151:
	movl	$LC166, (%esp)
	movl	$1, %edi
	movl	$LC165, %esi
	movl	%edi, 8(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, _DestroyDialog
	movl	-60(%ebp), %edx
	movl	$1, -92(%ebp)
	jmp	L1150
L1161:
	movl	$LC166, (%esp)
	movl	$1, %edi
	movl	$LC165, %esi
	movl	%edi, 8(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, _DestroyDialog
	movl	-52(%ebp), %edx
	movl	$1, -92(%ebp)
	jmp	L1160
L1202:
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1189
	movl	$LC51, (%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -52(%ebp)
	movl	%eax, %edx
	jmp	L1164
L1204:
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1187
	movl	$LC51, (%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -60(%ebp)
	movl	%eax, %edx
	jmp	L1154
L1206:
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1185
	movl	$LC51, (%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	movl	%eax, %edx
	jmp	L1144
L1183:
	movl	_NcentersZmat, %ecx
	jmp	L1176
L1201:
	movl	$LC88, (%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC165, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	movl	$1, -92(%ebp)
	xorl	%eax, %eax
	movl	%eax, _DestroyDialog
	jmp	L1163
L1200:
	call	_rafresh_drawing
	jmp	L1168
L1203:
	movl	$LC88, (%esp)
	movl	-60(%ebp), %eax
	movl	$1, %edi
	movl	$LC165, %esi
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	%eax, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	movl	$1, -92(%ebp)
	xorl	%ecx, %ecx
	movl	%ecx, _DestroyDialog
	jmp	L1153
L1205:
	movl	$LC88, (%esp)
	movl	-68(%ebp), %eax
	movl	$1, %edi
	movl	$LC165, %esi
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	%eax, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	movl	$1, -92(%ebp)
	xorl	%ecx, %ecx
	movl	%ecx, _DestroyDialog
	jmp	L1143
	.section .rdata,"dr"
LC167:
	.ascii "Sorry No line selected\0"
	.text
	.p2align 4,,15
	.def	_EditAtom;	.scl	3;	.type	32;	.endef
_EditAtom:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	movl	$1, %esi
	pushl	%ebx
	movl	$-1, %ebx
	subl	$188, %esp
	movl	%ebx, -160(%ebp)
	xorl	%ebx, %ebx
	movl	%edi, -164(%ebp)
	movl	%esi, _DestroyDialog
	.p2align 4,,15
L1211:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jle	L1211
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+4, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -84(%ebp)
	movl	_Entry+8, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -80(%ebp)
	movl	_Entry+12, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -76(%ebp)
	movl	_Entry+16, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp)
	movl	_LineSelected, %eax
	testl	%eax, %eax
	movl	%eax, -156(%ebp)
	movl	%eax, %edx
	js	L1285
L1212:
	cld
	movl	-156(%ebp), %esi
	movl	$14, %ebx
	movl	-156(%ebp), %ecx
	leal	-152(%ebp), %edi
	movl	_Geom, %eax
	sall	$3, %esi
	subl	%ecx, %esi
	sall	$3, %esi
	addl	%eax, %esi
	movl	-84(%ebp), %eax
	movl	%ebx, %ecx
	rep
	movsl
	testl	%eax, %eax
	je	L1213
	cmpb	$0, (%eax)
	je	L1213
	movl	%edx, -156(%ebp)
	testl	%edx, %edx
	js	L1286
L1214:
	movl	-156(%ebp), %eax
	movl	$LC45, (%esp)
	incl	%eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -88(%ebp)
	movl	-156(%ebp), %eax
	testl	%eax, %eax
	js	L1215
	cld
	xorl	%eax, %eax
	movl	-156(%ebp), %esi
	movl	%eax, -168(%ebp)
	movl	-156(%ebp), %eax
	leal	-152(%ebp), %edi
	movl	%ebx, %ecx
	sall	$3, %esi
	subl	%eax, %esi
	movl	_Geom, %eax
	sall	$3, %esi
	addl	%eax, %esi
	movl	-72(%ebp), %eax
	rep
	movsl
	movl	%eax, 4(%esp)
	movl	-136(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L1287
L1216:
	movl	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -148(%ebp)
	movl	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -144(%ebp)
	movl	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -140(%ebp)
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -136(%ebp)
	movl	-168(%ebp), %edi
	testl	%edi, %edi
	jne	L1215
	movl	_NcentersZmat, %edi
	movl	$-1, %esi
	xorl	%ebx, %ebx
	movl	%esi, -132(%ebp)
	cmpl	$0, %edi
	jle	L1219
	movl	_Geom, %eax
	xorl	%esi, %esi
	movl	%eax, -172(%ebp)
L1222:
	cmpl	%ebx, -156(%ebp)
	je	L1220
	movl	-172(%ebp), %edx
	movl	16(%esi,%edx), %eax
	movl	%eax, 4(%esp)
	movl	-136(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L1278
L1220:
	incl	%ebx
	addl	$56, %esi
	cmpl	%ebx, %edi
	jg	L1222
L1219:
	movl	-132(%ebp), %eax
	cmpl	$-1, %eax
	jne	L1215
	cmpl	$0, %edi
	jle	L1268
	movl	_Geom, %ecx
	movl	%edi, %ebx
	addl	$20, %ecx
L1228:
	movl	(%ecx), %edx
	cmpl	%edx, %eax
	jge	L1226
	movl	%edx, -132(%ebp)
	movl	%edx, %eax
L1226:
	addl	$56, %ecx
	decl	%ebx
	jne	L1228
L1268:
	incl	%eax
	movl	%eax, -132(%ebp)
L1215:
	movl	-156(%ebp), %ebx
	testl	%ebx, %ebx
	jle	L1229
	call	_gtk_entry_get_type
	movl	$5, %ebx
	movl	%eax, %esi
L1234:
	movl	%esi, 4(%esp)
	movl	_Entry(,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	call	_testav
	incl	%eax
	jl	L1279
	incl	%ebx
	cmpl	$6, %ebx
	jle	L1234
L1231:
	movl	-68(%ebp), %eax
	testl	%eax, %eax
	je	L1256
	cmpb	$0, (%eax)
	jne	L1235
L1256:
	movl	$LC166, (%esp)
	movl	$1, %ebx
	movl	$LC165, %ecx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	call	_MessageGeom
L1283:
	xorl	%eax, %eax
	movl	%eax, _DestroyDialog
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1213:
	movl	$LC167, (%esp)
	movl	$1, %esi
	movl	$LC165, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
L1263:
	call	_ChangeVariablesUseds
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1285:
	movl	_LineSelectedOld, %eax
	movl	%eax, -156(%ebp)
	jmp	L1212
L1287:
	movl	$1, %eax
	movl	%eax, -168(%ebp)
	jmp	L1216
L1235:
	movl	-164(%ebp), %edx
	testl	%edx, %edx
	jne	L1284
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1288
L1273:
	movl	-68(%ebp), %eax
L1238:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -128(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -124(%ebp)
L1229:
	cmpl	$1, -156(%ebp)
	jg	L1289
L1239:
	cmpl	$2, -156(%ebp)
	jle	L1249
	call	_gtk_entry_get_type
	movl	$9, %ebx
	movl	%eax, %esi
L1254:
	movl	%esi, 4(%esp)
	movl	_Entry(,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	call	_testav
	incl	%eax
	jl	L1281
	incl	%ebx
	cmpl	$10, %ebx
	jle	L1254
L1251:
	movl	-52(%ebp), %eax
	testl	%eax, %eax
	je	L1256
	cmpb	$0, (%eax)
	je	L1256
	movl	-164(%ebp), %edx
	testl	%edx, %edx
	je	L1257
L1284:
	movl	-160(%ebp), %edx
	movl	-88(%ebp,%edx,4), %eax
	movl	$LC88, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC165, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	jmp	L1283
L1257:
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1290
L1277:
	movl	-52(%ebp), %eax
L1258:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -112(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -108(%ebp)
L1249:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+44, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -44(%ebp)
	movl	%eax, (%esp)
	call	_g_strdup
	cmpl	$3, _iprogram
	movl	%eax, -104(%ebp)
	je	L1259
	movl	%ebx, 4(%esp)
	movl	_Entry+48, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
L1282:
	call	_g_strdup
	movl	%eax, -40(%ebp)
	leal	-152(%ebp), %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -100(%ebp)
	movl	-156(%ebp), %edi
	cld
	movl	-156(%ebp), %eax
	movl	$14, %ecx
	movl	-156(%ebp), %edx
	sall	$3, %edi
	subl	%eax, %edi
	movl	_Geom, %eax
	sall	$3, %edi
	addl	%eax, %edi
	rep
	movsl
	movl	_list, %eax
	call	_removeFromList
	movl	$13, %eax
	movl	%eax, 4(%esp)
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	-156(%ebp), %edx
	movl	_list, %eax
	call	_insertToList
	movl	_ZoneDessin, %edi
	testl	%edi, %edi
	jne	L1291
L1261:
	cmpl	$1, _iprogram
	jne	L1263
	call	_set_spin_of_electrons
	jmp	L1263
L1286:
	movl	_LineSelectedOld, %edx
	movl	%edx, -156(%ebp)
	jmp	L1214
L1289:
	call	_gtk_entry_get_type
	movl	$7, %ebx
	movl	%eax, %esi
L1244:
	movl	%esi, 4(%esp)
	movl	_Entry(,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	call	_testav
	incl	%eax
	jl	L1280
	incl	%ebx
	cmpl	$8, %ebx
	jle	L1244
L1241:
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	je	L1256
	cmpb	$0, (%eax)
	je	L1256
	movl	-164(%ebp), %edi
	testl	%edi, %edi
	jne	L1284
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1292
L1275:
	movl	-60(%ebp), %eax
L1248:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -120(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -116(%ebp)
	jmp	L1239
L1288:
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1273
	movl	-68(%ebp), %eax
	movl	$LC51, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	jmp	L1238
L1292:
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1275
	movl	-60(%ebp), %eax
	movl	$LC51, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -60(%ebp)
	jmp	L1248
	.p2align 4,,7
L1278:
	movl	-172(%ebp), %edx
	movl	20(%esi,%edx), %eax
	movl	%eax, -132(%ebp)
	jmp	L1219
L1291:
	call	_rafresh_drawing
	jmp	L1261
L1259:
	movl	$LC46, (%esp)
	jmp	L1282
L1279:
	movl	%ebx, -160(%ebp)
	movl	$1, %ecx
	movl	%ecx, -164(%ebp)
	jmp	L1231
L1290:
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1277
	movl	-52(%ebp), %eax
	movl	$LC51, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -52(%ebp)
	jmp	L1258
L1281:
	movl	%ebx, -160(%ebp)
	movl	$1, %esi
	movl	%esi, -164(%ebp)
	jmp	L1251
L1280:
	movl	%ebx, -160(%ebp)
	movl	$1, %eax
	movl	%eax, -164(%ebp)
	jmp	L1241
	.section .rdata,"dr"
LC168:
	.ascii "\0"
	.text
	.p2align 4,,15
	.def	_get_list_variables;	.scl	3;	.type	32;	.endef
_get_list_variables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$12, %esp
	xorl	%ebx, %ebx
	movl	_NVariables, %eax
	leal	4(,%eax,4), %eax
	movl	%eax, (%esp)
	call	_g_malloc
	cmpl	_NVariables, %ebx
	movl	%eax, %edi
	jae	L1299
	xorl	%esi, %esi
	.p2align 4,,15
L1297:
	movl	_Variables, %eax
	movl	(%esi,%eax), %eax
	addl	$12, %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%edi,%ebx,4)
	incl	%ebx
	cmpl	_NVariables, %ebx
	jb	L1297
L1299:
	movl	$LC168, (%esp)
	call	_g_strdup
	movl	%eax, (%edi)
	addl	$12, %esp
	movl	%edi, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_freelistvariables;	.scl	3;	.type	32;	.endef
_freelistvariables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$16, %esp
	xorl	%ebx, %ebx
	cmpl	$-1, _NVariables
	jne	L1304
L1306:
	movl	%esi, (%esp)
	call	_g_free
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L1304:
	movl	(%esi,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	movl	_NVariables, %eax
	incl	%eax
	cmpl	%ebx, %eax
	jbe	L1306
	movl	(%esi,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	movl	_NVariables, %eax
	incl	%eax
	cmpl	%ebx, %eax
	ja	L1304
	jmp	L1306
	.section .rdata,"dr"
LC169:
	.ascii " Name : \0"
LC170:
	.ascii " Value : \0"
LC173:
	.ascii "Edit Variable\0"
LC174:
	.ascii " Edit variable \0"
LC175:
	.ascii "frame\0"
LC171:
	.ascii "Create variable before \12\0"
LC172:
	.ascii "Please Select your variable \12\0"
	.text
	.p2align 4,,15
	.def	_DialogueEditV;	.scl	3;	.type	32;	.endef
_DialogueEditV:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	movl	_LineSelectedV, %edi
	movl	$LC169, -40(%ebp)
	movl	$LC170, -36(%ebp)
	testl	%edi, %edi
	js	L1314
	call	_gtk_dialog_new
	movl	%eax, -24(%ebp)
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC173, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_title
	movl	%ebx, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_position
	movl	%ebx, 4(%esp)
	movl	_WindowGeom, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
	movl	%eax, %esi
	movl	-24(%ebp), %eax
	movl	$80, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	movl	$_gtk_widget_destroy, %esi
	call	_gtk_window_set_transient_for
	movl	%esi, 8(%esp)
	movl	$LC174, %eax
	xorl	%esi, %esi
	movl	%eax, 12(%esp)
	movl	-24(%ebp), %edx
	movl	_WindowGeom, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_add_child
	movl	%ebx, 4(%esp)
	movl	-24(%ebp), %eax
	movl	$_delete_child, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$LC143, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, 16(%esp)
	movl	%esi, 12(%esp)
	movl	$_g_object_unref, %esi
	movl	%ebx, 8(%esp)
	call	_g_signal_connect_data
	movl	$0, (%esp)
	call	_gtk_frame_new
	movl	%eax, %ebx
	call	_gtk_frame_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$4, %edx
	movl	%edx, 4(%esp)
	call	_gtk_frame_set_shadow_type
	movl	%ebx, (%esp)
	call	_g_object_ref
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC175, %ecx
	movl	%ecx, 4(%esp)
	movl	%esi, 12(%esp)
	xorl	%esi, %esi
	movl	%ebx, 8(%esp)
	call	_g_object_set_data_full
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_set_border_width
	call	_gtk_box_get_type
	movl	%eax, -44(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, -48(%ebp)
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-44(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	148(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	%ebx, (%esp)
	call	_create_vbox
	movl	%eax, -28(%ebp)
	movl	%eax, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	movl	%eax, %edx
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -20(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-20(%ebp)
	fistpl	12(%esp)
	fldcw	-18(%ebp)
	fldcw	-20(%ebp)
	fistpl	8(%esp)
	fldcw	-18(%ebp)
	movl	-40(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	movl	%eax, _EntryV
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	leal	(%edi,%edi,2), %edx
	leal	0(,%edx,4), %ebx
	movl	_Variables, %edx
	movl	(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	_Variables, %eax
	movl	8(%ebx,%eax), %eax
	testl	%eax, %eax
	jne	L1315
L1312:
	movl	-28(%ebp), %edx
	movl	$LC170, %edi
	movl	%edx, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	movl	%eax, %edx
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -20(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-20(%ebp)
	fistpl	12(%esp)
	fldcw	-18(%ebp)
	fldcw	-20(%ebp)
	fistpl	8(%esp)
	fldcw	-18(%ebp)
	movl	%edx, (%esp)
	movl	%edi, 4(%esp)
	call	_create_label_entry
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	movl	$LC149, %esi
	movl	%eax, _EntryV+4
	call	_g_type_check_instance_cast
	movl	_Variables, %edx
	movl	4(%ebx,%edx), %edx
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_realize
	movl	%esi, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_button
	movl	%eax, %edi
	movl	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	-44(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	%eax, %ebx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%ecx, 20(%esp)
	movl	$_delete_child, %ecx
	movl	%edx, 16(%esp)
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	xorl	%ebx, %ebx
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	movl	$LC150, %edi
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	%edi, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_button
	movl	%eax, %edi
	movl	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	-44(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	$80, %ebx
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_box_pack_start
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$_EditVariable, %ecx
	movl	%edx, 16(%esp)
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	%eax, %ebx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%ecx, 20(%esp)
	movl	$_destroy_dialogue, %ecx
	movl	%edx, 16(%esp)
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	%edi, (%esp)
	call	_gtk_widget_grab_default
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_gtk_widget_show_all
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1314:
	movl	_NVariables, %eax
	testl	%eax, %eax
	jne	L1310
	movl	$LC171, (%esp)
	movl	$1, %eax
	movl	$LC165, %edi
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	call	_MessageGeom
L1319:
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1310:
	movl	$LC172, (%esp)
	movl	$1, %esi
	movl	$LC165, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
	jmp	L1319
	.p2align 4,,7
L1315:
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	_EntryV, %eax
	movl	%eax, (%esp)
	call	_gtk_editable_set_editable
	jmp	L1312
	.section .rdata,"dr"
LC181:
	.ascii "Delete Variable\0"
LC182:
	.ascii " Delete Variable \0"
LC184:
	.ascii " Question \0"
	.align 4
LC183:
	.ascii "\12 Are you sure to delete the variable\12 %s\12?\0"
LC185:
	.ascii "No\0"
LC186:
	.ascii "Yes\0"
LC177:
	.ascii "New Variable\0"
LC178:
	.ascii " New Variable \0"
	.align 4
LC187:
	.ascii "Tansform all variables to constants\0"
	.align 4
LC188:
	.ascii "\12 Are you sure to transform\12 all variables to constants? \12\0"
LC179:
	.ascii " No Variable to delet !\0"
	.align 4
LC180:
	.ascii "Sorry\12 %s \12 is used in Geometry\0"
LC189:
	.ascii "Sorry No Variable selected\0"
	.text
	.p2align 4,,15
	.def	_activate_action_zmat_variables;	.scl	3;	.type	32;	.endef
_activate_action_zmat_variables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$LC1, %edi
	pushl	%esi
	pushl	%ebx
	subl	$172, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_action_get_name
	cld
	movl	$5, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	je	L1343
	cld
	movl	$LC3, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	je	L1344
	cld
	movl	$LC6, %edi
	movl	$7, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1326
	movl	_NVariables, %edx
	testl	%edx, %edx
	je	L1345
	movl	_LineSelectedV, %eax
	testl	%eax, %eax
	js	L1346
L1329:
	movl	_Variables, %edx
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	8(%eax,%edx), %ecx
	testl	%ecx, %ecx
	jne	L1347
	call	_gtk_dialog_new
	movl	%eax, %edi
	call	_gtk_window_get_type
	movl	%eax, -88(%ebp)
	movl	$LC181, %ebx
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	movl	$80, %ebx
	call	_gtk_window_set_title
	movl	-88(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_position
	movl	-88(%ebp), %edx
	movl	_WindowGeom, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -92(%ebp)
	movl	-88(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-92(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_window_set_transient_for
	movl	%esi, 4(%esp)
	movl	$_gtk_widget_destroy, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_modal
	movl	%esi, 8(%esp)
	movl	$LC182, %eax
	xorl	%esi, %esi
	movl	%eax, 12(%esp)
	movl	_WindowGeom, %eax
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_add_child
	movl	%ebx, 4(%esp)
	movl	$_delete_child, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$LC143, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$_g_object_unref, %ebx
	call	_g_signal_connect_data
	movl	$0, (%esp)
	call	_gtk_frame_new
	movl	%eax, %esi
	call	_gtk_frame_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$4, %edx
	movl	%edx, 4(%esp)
	call	_gtk_frame_set_shadow_type
	movl	%esi, (%esp)
	call	_g_object_ref
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC175, %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, 12(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 8(%esp)
	call	_g_object_set_data_full
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_set_border_width
	call	_gtk_box_get_type
	movl	%eax, -96(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, -100(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	-96(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	148(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	%esi, (%esp)
	call	_create_vbox
	movl	%eax, -84(%ebp)
	movl	$LC184, %esi
	xorl	%ebx, %ebx
	movl	%edi, (%esp)
	call	_gtk_widget_realize
	movl	_LineSelectedV, %eax
	movl	_Variables, %edx
	leal	(%eax,%eax,2), %eax
	movl	(%edx,%eax,4), %eax
	movl	$LC183, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esp)
	movl	%esi, 8(%esp)
	movl	%edi, (%esp)
	call	_create_label_with_pixmap
	movl	%eax, -76(%ebp)
	movl	-96(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-84(%ebp), %eax
	movl	$LC185, %esi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 8(%esp)
	movl	-76(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	_create_button
	movl	%eax, -80(%ebp)
	movl	-100(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-96(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	$2, %ebx
	movl	%edx, 8(%esp)
	movl	-80(%ebp), %esi
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	call	_gtk_object_get_type
	movl	%eax, -104(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -108(%ebp)
	movl	$80, %eax
	movl	%esi, (%esp)
	movl	$LC147, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 20(%esp)
	xorl	%ecx, %ecx
	movl	$LC186, %ebx
	movl	%ecx, 16(%esp)
	movl	-108(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	movl	%edx, 12(%esp)
	movl	$_delete_child, %edx
	movl	%edx, 8(%esp)
	call	_g_signal_connect_data
	movl	-104(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	-80(%ebp), %edx
	movl	%edx, (%esp)
	call	_gtk_widget_grab_default
	movl	%ebx, 4(%esp)
	movl	$80, %ebx
	movl	%edi, (%esp)
	call	_create_button
	movl	%eax, -80(%ebp)
	movl	-100(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	movl	$1, %esi
	call	_g_type_check_instance_cast
	movl	-96(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 8(%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	-80(%ebp), %esi
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$_DelVariable, %ecx
	movl	%edx, 16(%esp)
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	movl	-104(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -112(%ebp)
	movl	$80, %eax
	movl	%esi, (%esp)
	movl	$2, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	xorl	%ebx, %ebx
	movl	$_delete_child, %ecx
	movl	%ebx, 16(%esp)
	movl	-112(%ebp), %edx
	movl	%ecx, 8(%esp)
	movl	%eax, (%esp)
	movl	%edx, 12(%esp)
	movl	$LC147, %edx
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	-104(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-80(%ebp), %eax
L1341:
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	%edi, 8(%ebp)
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_show_all
	.p2align 4,,7
L1344:
	movl	$LC169, -40(%ebp)
	movl	$80, %ebx
	movl	$LC170, -36(%ebp)
	call	_gtk_dialog_new
	movl	%eax, %edi
	call	_gtk_window_get_type
	movl	%eax, -44(%ebp)
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC177, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_title
	movl	-44(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_position
	movl	-44(%ebp), %edx
	movl	_WindowGeom, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -48(%ebp)
	movl	-44(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	movl	$_gtk_widget_destroy, %esi
	call	_g_type_check_instance_cast
	movl	-48(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_window_set_transient_for
	movl	%esi, 8(%esp)
	movl	$LC178, %eax
	xorl	%esi, %esi
	movl	%eax, 12(%esp)
	movl	_WindowGeom, %eax
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_add_child
	movl	%ebx, 4(%esp)
	movl	$_delete_child, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$LC143, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$_g_object_unref, %ebx
	call	_g_signal_connect_data
	movl	$0, (%esp)
	call	_gtk_frame_new
	movl	%eax, -32(%ebp)
	call	_gtk_frame_get_type
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %esi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$4, %edx
	movl	%edx, 4(%esp)
	call	_gtk_frame_set_shadow_type
	movl	%esi, (%esp)
	call	_g_object_ref
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC175, %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, 12(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 8(%esp)
	call	_g_object_set_data_full
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_set_border_width
	call	_gtk_box_get_type
	movl	%eax, -52(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, -56(%ebp)
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-52(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	148(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	%esi, (%esp)
	call	_create_vbox
	movl	%eax, (%esp)
	movl	%eax, %esi
	call	_create_hbox_false
	fildl	_ScreenHeight
	movl	%eax, %edx
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -20(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-20(%ebp)
	fistpl	12(%esp)
	fldcw	-18(%ebp)
	fldcw	-20(%ebp)
	fistpl	8(%esp)
	fldcw	-18(%ebp)
	movl	-40(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	movl	%eax, _EntryV
	movl	%esi, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	movl	%eax, %edx
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -20(%ebp)
	movl	$LC170, %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-20(%ebp)
	fistpl	12(%esp)
	fldcw	-18(%ebp)
	fldcw	-20(%ebp)
	fistpl	8(%esp)
	fldcw	-18(%ebp)
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	movl	%eax, _EntryV+4
	movl	%edi, (%esp)
	call	_gtk_widget_realize
	movl	%edi, (%esp)
	movl	$LC149, %eax
	movl	%eax, 4(%esp)
	call	_create_button
	movl	-56(%ebp), %edx
	movl	%eax, %ebx
	movl	%edi, (%esp)
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-52(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	152(%eax), %eax
	xorl	%esi, %esi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, 16(%esp)
	movl	$2, %esi
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	call	_gtk_object_get_type
	movl	%eax, -60(%ebp)
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -64(%ebp)
	movl	$80, %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	xorl	%ecx, %ecx
	movl	$LC147, %esi
	movl	%ecx, 16(%esp)
	movl	-64(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	movl	%edx, 12(%esp)
	movl	$_delete_child, %edx
	movl	%edx, 8(%esp)
	call	_g_signal_connect_data
	movl	-60(%ebp), %esi
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	$LC150, %ecx
	movl	%ecx, 4(%esp)
	movl	%edi, (%esp)
	call	_create_button
	movl	%eax, %ebx
	movl	-56(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-52(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$1, %ecx
	movl	%edx, 16(%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 20(%esp)
	xorl	%edx, %edx
	movl	%ecx, 16(%esp)
	movl	$_AddVariable, %ecx
	movl	%edx, 12(%esp)
	movl	$LC147, %edx
	movl	%edx, 4(%esp)
	movl	%ecx, 8(%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -68(%ebp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 16(%esp)
	movl	$2, %edx
	movl	$_destroy_dialogue, %ecx
	movl	%edx, 20(%esp)
	movl	-68(%ebp), %esi
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%esi, 12(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	-60(%ebp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	%ebx, (%esp)
	call	_gtk_widget_grab_default
	movl	%edi, 8(%ebp)
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_show_all
	.p2align 4,,7
L1343:
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_DialogueEditV
	.p2align 4,,7
L1326:
	cld
	movl	$LC9, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1332
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	je	L1348
	call	_gtk_dialog_new
	movl	%eax, %edi
	call	_gtk_window_get_type
	movl	%eax, -132(%ebp)
	movl	$LC187, %ebx
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	call	_gtk_window_set_title
	movl	-132(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_position
	movl	-132(%ebp), %edx
	movl	_WindowGeom, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -136(%ebp)
	movl	-132(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-136(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_window_set_transient_for
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_modal
	movl	%edi, 4(%esp)
	movl	$LC184, %eax
	movl	%eax, 12(%esp)
	movl	$_gtk_widget_destroy, %eax
	movl	%eax, 8(%esp)
	movl	_WindowGeom, %eax
	movl	%eax, (%esp)
	call	_add_child
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	movl	$_delete_child, %edx
	xorl	%ecx, %ecx
	movl	%edx, 8(%esp)
	movl	$LC143, %esi
	movl	%ecx, 12(%esp)
	movl	%ebx, 16(%esp)
	movl	$LC184, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%edi, (%esp)
	call	_gtk_widget_realize
	movl	%ebx, 8(%esp)
	movl	$LC188, %ecx
	movl	$_g_object_unref, %ebx
	movl	%ecx, 4(%esp)
	movl	%edi, (%esp)
	call	_create_label_with_pixmap
	movl	%eax, -120(%ebp)
	movl	$0, (%esp)
	call	_gtk_frame_new
	movl	%eax, -128(%ebp)
	call	_gtk_frame_get_type
	movl	%eax, 4(%esp)
	movl	-128(%ebp), %esi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$4, %edx
	movl	%edx, 4(%esp)
	call	_gtk_frame_set_shadow_type
	movl	%esi, (%esp)
	call	_g_object_ref
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC175, %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, 12(%esp)
	movl	%esi, 8(%esp)
	call	_g_object_set_data_full
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_set_border_width
	call	_gtk_box_get_type
	movl	%eax, -140(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, -144(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	-140(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	148(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ebx, %ebx
	movl	$1, %ecx
	movl	%ecx, 12(%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	%esi, (%esp)
	call	_create_vbox
	movl	-140(%ebp), %esi
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	movl	$LC185, %esi
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 8(%esp)
	movl	-120(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	_create_button
	movl	%eax, -124(%ebp)
	movl	-144(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-140(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	$2, %ebx
	movl	%edx, 8(%esp)
	movl	-124(%ebp), %esi
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	call	_gtk_object_get_type
	movl	%eax, -148(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -152(%ebp)
	movl	$80, %eax
	movl	%esi, (%esp)
	movl	$LC147, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 20(%esp)
	xorl	%ecx, %ecx
	movl	$LC186, %ebx
	movl	%ecx, 16(%esp)
	movl	-152(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	movl	%edx, 12(%esp)
	movl	$_delete_child, %edx
	movl	%edx, 8(%esp)
	call	_g_signal_connect_data
	movl	-148(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	-124(%ebp), %edx
	movl	%edx, (%esp)
	call	_gtk_widget_grab_default
	movl	%ebx, 4(%esp)
	movl	$80, %ebx
	movl	%edi, (%esp)
	call	_create_button
	movl	%eax, -124(%ebp)
	movl	-144(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	movl	$1, %esi
	call	_g_type_check_instance_cast
	movl	-140(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 8(%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	-124(%ebp), %esi
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$_trans_allVariables_to_Constants, %ecx
	movl	%edx, 16(%esp)
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	xorl	%ebx, %ebx
	call	_g_signal_connect_data
	movl	-148(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -156(%ebp)
	movl	$80, %eax
	movl	%esi, (%esp)
	movl	$2, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	movl	$_delete_child, %ecx
	movl	%ebx, 16(%esp)
	movl	-156(%ebp), %edx
	movl	%ecx, 8(%esp)
	movl	%eax, (%esp)
	movl	%edx, 12(%esp)
	movl	$LC147, %edx
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	-148(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-124(%ebp), %eax
	jmp	L1341
L1332:
	cld
	movl	$LC12, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1320
	movl	_LineSelectedV, %eax
	testl	%eax, %eax
	js	L1349
	movl	%eax, (%esp)
	call	_OneVariableToConst
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L1320
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_rafresh_drawing
L1348:
	movl	$LC139, (%esp)
	movl	$1, %edi
	movl	$LC165, %esi
L1352:
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
L1320:
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1345:
	movl	$LC179, (%esp)
	movl	$1, %esi
	movl	$LC165, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
	jmp	L1320
L1347:
	movl	(%eax,%edx), %eax
	movl	$1, %edi
	movl	$LC180, (%esp)
	movl	$LC165, %esi
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	jmp	L1352
L1346:
	leal	-1(%edx), %eax
	movl	%eax, _LineSelectedV
	jmp	L1329
L1349:
	movl	$LC189, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC165, %eax
	movl	%eax, 4(%esp)
	call	_MessageGeom
	jmp	L1320
	.section .rdata,"dr"
LC191:
	.ascii "Atom Symbol : \0"
LC192:
	.ascii "MM Type : \0"
LC193:
	.ascii "PDB Type : \0"
LC194:
	.ascii "Residue : \0"
LC195:
	.ascii "R : \0"
LC196:
	.ascii "Center : \0"
LC197:
	.ascii "Angle : \0"
LC198:
	.ascii "Dihedral : \0"
LC199:
	.ascii "Charge : \0"
LC200:
	.ascii "Layer : \0"
	.data
	.align 4
LC201:
	.long	LC46
	.long	LC191
	.long	LC192
	.long	LC193
	.long	LC194
	.long	LC195
	.long	LC196
	.long	LC197
	.long	LC196
	.long	LC198
	.long	LC196
	.long	LC199
	.long	LC200
	.section .rdata,"dr"
LC204:
	.ascii " Edit center\0"
LC205:
	.ascii " Edit Center \0"
LC206:
	.ascii " Set \0"
LC202:
	.ascii "Create center before \12\0"
LC203:
	.ascii "Please Select your center \12\0"
	.align 8
LC207:
	.long	1202590843
	.long	1068792545
	.text
	.p2align 4,,15
	.def	_DialogueEdit;	.scl	3;	.type	32;	.endef
_DialogueEdit:
	pushl	%ebp
	movl	$1, %eax
	movl	%esp, %ebp
	pushl	%edi
	cld
	leal	-88(%ebp), %edi
	pushl	%esi
	movl	$13, %ecx
	pushl	%ebx
	subl	$156, %esp
	movl	%eax, _InEdit
	movl	_LineSelected, %eax
	movl	$LC201, %esi
	rep
	movsl
	movl	$0, -116(%ebp)
	testl	%eax, %eax
	movl	%eax, -124(%ebp)
	jl	L1381
	jle	L1357
	movl	-124(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -116(%ebp)
	movl	-124(%ebp), %ebx
	testl	%ebx, %ebx
	jle	L1357
	movl	$1, %esi
	.p2align 4,,15
L1361:
	movl	%esi, 4(%esp)
	movl	%esi, %ebx
	movl	$LC45, (%esp)
	call	_g_strdup_printf
	movl	-116(%ebp), %edx
	movl	%eax, -4(%edx,%esi,4)
	incl	%esi
	cmpl	-124(%ebp), %ebx
	jl	L1361
L1357:
	call	_gtk_dialog_new
	movl	%eax, -104(%ebp)
	movl	$80, %edi
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC204, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_title
	movl	%ebx, 4(%esp)
	movl	-104(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_position
	movl	%ebx, 4(%esp)
	movl	_WindowGeom, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
	movl	%eax, %esi
	movl	-104(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	call	_gtk_window_set_transient_for
	movl	$LC205, %eax
	movl	%eax, 12(%esp)
	movl	$_gtk_widget_destroy, %eax
	movl	%eax, 8(%esp)
	movl	-104(%ebp), %edx
	movl	_WindowGeom, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_add_child
	movl	%edi, 4(%esp)
	movl	-104(%ebp), %eax
	movl	$LC143, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$_delete_child, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, 20(%esp)
	movl	$4, %esi
	movl	%ebx, 16(%esp)
	movl	%edi, 4(%esp)
	movl	$LC175, %edi
	call	_g_signal_connect_data
	movl	$0, (%esp)
	call	_gtk_frame_new
	movl	%eax, %ebx
	call	_gtk_frame_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	movl	$10, %esi
	call	_gtk_frame_set_shadow_type
	movl	%ebx, (%esp)
	call	_g_object_ref
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	-104(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_g_object_unref, %edx
	movl	%edx, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%edi, 4(%esp)
	movl	$1, %edi
	call	_g_object_set_data_full
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_set_border_width
	call	_gtk_box_get_type
	movl	%eax, %esi
	call	_gtk_dialog_get_type
	movl	%eax, 4(%esp)
	movl	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 4(%esp)
	movl	148(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	%ebx, (%esp)
	call	_create_vbox
	movl	%eax, -112(%ebp)
	movl	%eax, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	movl	%eax, %edi
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	12(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	8(%esp)
	fldcw	-98(%ebp)
	movl	-84(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	movl	%eax, _Entry+4
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	movl	$5, %ebx
	call	_g_type_check_instance_cast
	movl	-124(%ebp), %edx
	movl	-124(%ebp), %ecx
	sall	$3, %edx
	subl	%ecx, %edx
	movl	_Geom, %ecx
	movl	4(%ecx,%edx,8), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	_Entry+4, %eax
	movl	%eax, (%esp)
	call	_gtk_editable_set_editable
	movl	$LC206, (%esp)
	call	_gtk_button_new_with_label
	movl	%eax, -108(%ebp)
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	movl	%edi, (%esp)
	movl	$80, %edi
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 8(%esp)
	movl	-108(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, 4(%esp)
	movl	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	_Entry+4, %edx
	movl	$_SelectAtom, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 20(%esp)
	movl	%edx, 12(%esp)
	movl	$LC147, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	call	_g_signal_connect_data
	movl	-112(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	movl	$0, -92(%ebp)
	movl	%eax, %edi
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	_getListMMTypes
	movl	-92(%ebp), %edx
	movl	%eax, %esi
	testl	%edx, %edx
	je	L1362
	fildl	_ScreenHeight
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	movl	$1, %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	-80(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
L1376:
	movl	%eax, _Entry+8
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	-124(%ebp), %edx
	movl	-124(%ebp), %edi
	sall	$3, %edx
	subl	%edi, %edx
	leal	0(,%edx,8), %ebx
	movl	_Geom, %edx
	movl	8(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	testl	%esi, %esi
	je	L1364
	movl	-92(%ebp), %edx
	movl	%esi, %eax
	call	_freeList
L1364:
	movl	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	movl	$0, -96(%ebp)
	movl	%eax, %edi
	leal	-96(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	_Geom, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_getListPDBTypes
	movl	%eax, -128(%ebp)
	movl	-96(%ebp), %edx
	testl	%edx, %edx
	je	L1365
	fildl	_ScreenHeight
	movl	$1, %ebx
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%ebx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	-128(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-76(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
L1377:
	movl	%eax, _Entry+12
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	-124(%ebp), %edx
	movl	-124(%ebp), %ecx
	sall	$3, %edx
	subl	%ecx, %edx
	leal	0(,%edx,8), %ebx
	movl	_Geom, %edx
	movl	12(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-128(%ebp), %edi
	testl	%edi, %edi
	je	L1367
	movl	-96(%ebp), %edx
	movl	-128(%ebp), %eax
	call	_freeList
L1367:
	movl	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	movl	%eax, %edi
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	12(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	8(%esp)
	fldcw	-98(%ebp)
	movl	-72(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	movl	%eax, _Entry+16
	movl	_NcentersZmat, %ecx
	testl	%ecx, %ecx
	jne	L1368
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	$LC168, %edx
L1380:
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	call	_get_list_variables
	movl	%eax, -120(%ebp)
	movl	-124(%ebp), %edi
	testl	%edi, %edi
	jle	L1370
	movl	-112(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	movl	-124(%ebp), %ebx
	movl	%eax, %edi
	movl	-124(%ebp), %esi
	movl	_Geom, %eax
	sall	$3, %ebx
	subl	%esi, %ebx
	sall	$3, %ebx
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	fildl	_ScreenHeight
	movl	$1, %ecx
	movl	-120(%ebp), %edx
	movl	%eax, (%edx)
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	movl	_NVariables, %eax
	fmull	_labelWidth
	fxch	%st(1)
	incl	%eax
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%ecx, 16(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 12(%esp)
	movl	-68(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	fildl	_ScreenHeight
	movl	%eax, _Entry+20
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	fld	%st(0)
	fmull	LC207
	fxch	%st(1)
	movw	%ax, -100(%ebp)
	xorl	%eax, %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 16(%esp)
	movl	-124(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-116(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-64(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry+24
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	_Entry+20, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_Geom, %edx
	movl	24(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%esi, 4(%esp)
	movl	_Entry+24, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_Geom, %edx
	movl	28(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
L1370:
	cmpl	$1, -124(%ebp)
	jg	L1382
L1371:
	cmpl	$2, -124(%ebp)
	jg	L1383
L1372:
	movl	-116(%ebp), %ebx
	testl	%ebx, %ebx
	je	L1373
	movl	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L1373:
	movl	-120(%ebp), %eax
	call	_freelistvariables
	movl	-112(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	movl	%eax, %edi
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	12(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	8(%esp)
	fldcw	-98(%ebp)
	movl	-44(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	movl	%eax, _Entry+44
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	-124(%ebp), %edx
	movl	-124(%ebp), %ecx
	sall	$3, %edx
	subl	%ecx, %edx
	leal	0(,%edx,8), %ebx
	movl	_Geom, %edx
	movl	48(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	$16, (%esp)
	call	_g_malloc
	movl	%eax, -116(%ebp)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, (%edx)
	movl	$LC99, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	$LC100, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, 8(%edx)
	movl	$LC101, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, 12(%edx)
	movl	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	cmpl	$3, _iprogram
	movl	%eax, %edi
	je	L1374
	fildl	_ScreenHeight
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	xorl	%eax, %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 16(%esp)
	movl	$4, %eax
	movl	%eax, 12(%esp)
	movl	-116(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-40(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry+48
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_Geom, %edx
	movl	52(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
L1374:
	movl	-104(%ebp), %eax
	movl	$LC149, %esi
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_gtk_widget_realize
	movl	%esi, 4(%esp)
	movl	-104(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_button
	movl	%eax, -108(%ebp)
	call	_gtk_box_get_type
	movl	%eax, -132(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %edi
	movl	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-132(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-108(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %ebx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-108(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%ecx, 20(%esp)
	movl	$_delete_child, %ecx
	movl	%edx, 16(%esp)
	movl	$LC147, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	xorl	%ebx, %ebx
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	$LC150, %eax
	movl	%eax, 4(%esp)
	movl	-104(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_button
	movl	%eax, -108(%ebp)
	movl	%edi, 4(%esp)
	movl	-104(%ebp), %eax
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-132(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 8(%esp)
	movl	-108(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	_Entry+4, %edx
	movl	$_EditAtom, %ecx
	movl	%ecx, 8(%esp)
	movl	%edi, 20(%esp)
	movl	$80, %edi
	movl	%edx, 12(%esp)
	movl	$LC147, %edx
	movl	%ebx, 16(%esp)
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	-104(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 4(%esp)
	movl	%eax, %ebx
	movl	-108(%ebp), %eax
	movl	$_destroy_dialogue, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 12(%esp)
	movl	$2, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$LC147, %ebx
	movl	%edx, 16(%esp)
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	-108(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_grab_default
	movl	-104(%ebp), %edx
	movl	%edx, (%esp)
	call	_gtk_widget_show_all
	movl	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	addl	$156, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1368:
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_Geom, %edx
	movl	16(%ebx,%edx), %edx
	jmp	L1380
	.p2align 4,,7
L1365:
	fildl	_ScreenHeight
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	12(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	8(%esp)
	fldcw	-98(%ebp)
	movl	-76(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	jmp	L1377
	.p2align 4,,7
L1362:
	fildl	_ScreenHeight
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	12(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	8(%esp)
	fldcw	-98(%ebp)
	movl	-80(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	jmp	L1376
L1383:
	movl	-112(%ebp), %eax
	xorl	%esi, %esi
	movl	%eax, (%esp)
	call	_create_hbox_false
	movl	-124(%ebp), %ebx
	movl	%eax, %edi
	movl	-124(%ebp), %eax
	sall	$3, %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	fildl	_ScreenHeight
	movl	-120(%ebp), %edx
	movl	%eax, (%edx)
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	movl	$1, %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 16(%esp)
	movl	_NVariables, %eax
	movl	%edx, 8(%esp)
	incl	%eax
	movl	%eax, 12(%esp)
	movl	-52(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	fildl	_ScreenHeight
	movl	%eax, _Entry+36
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	fld	%st(0)
	fmull	LC207
	fxch	%st(1)
	movw	%ax, -100(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%esi, 16(%esp)
	movl	-124(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-116(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-48(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry+40
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	_Entry+36, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_Geom, %edx
	movl	40(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%esi, 4(%esp)
	movl	_Entry+40, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_Geom, %edx
	movl	44(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	jmp	L1372
L1382:
	movl	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	movl	-124(%ebp), %ebx
	movl	%eax, %edi
	movl	-124(%ebp), %eax
	sall	$3, %ebx
	subl	%eax, %ebx
	movl	_Geom, %eax
	sall	$3, %ebx
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	fildl	_ScreenHeight
	movl	-120(%ebp), %edx
	movl	%eax, (%edx)
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	movl	$1, %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 16(%esp)
	movl	_NVariables, %eax
	movl	%edx, 8(%esp)
	incl	%eax
	movl	%eax, 12(%esp)
	movl	-60(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	fildl	_ScreenHeight
	movl	%eax, _Entry+28
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	orw	$3072, %ax
	fld	%st(0)
	fmull	LC207
	fxch	%st(1)
	movw	%ax, -100(%ebp)
	xorl	%eax, %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 16(%esp)
	movl	-124(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-116(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-56(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry+32
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	_Entry+28, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_Geom, %edx
	movl	32(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%esi, 4(%esp)
	movl	_Entry+32, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_Geom, %edx
	movl	36(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	jmp	L1371
L1381:
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	jne	L1355
	movl	$LC202, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC165, %eax
	movl	%eax, 4(%esp)
	call	_MessageGeom
L1387:
	addl	$156, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1355:
	movl	$LC203, (%esp)
	movl	$1, %edi
	movl	$LC165, %esi
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
	jmp	L1387
	.section .rdata,"dr"
LC209:
	.ascii "Geom\0"
LC210:
	.ascii "%s/Edit\0"
LC211:
	.ascii "%s/Delete\0"
LC212:
	.ascii "%s/One\0"
LC213:
	.ascii "%s/All\0"
LC214:
	.ascii "Variable\0"
	.text
	.p2align 4,,15
	.def	_event_dispatcher;	.scl	3;	.type	32;	.endef
_event_dispatcher:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	12(%ebp), %esi
	movl	$-1, -24(%ebp)
	testl	%esi, %esi
	je	L1388
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_bin_window
	cmpl	%eax, 4(%esi)
	je	L1442
L1390:
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	8(%ebp), %edx
	movl	%eax, %ebx
	xorl	%edi, %edi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 24(%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	leal	-16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%ecx, 20(%esp)
	fldl	24(%esi)
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %edx
	orw	$3072, %dx
	movw	%dx, -20(%ebp)
	fldcw	-20(%ebp)
	fistpl	8(%esp)
	fldcw	-18(%ebp)
	fldl	16(%esi)
	fldcw	-20(%ebp)
	fistpl	4(%esp)
	fldcw	-18(%ebp)
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_path_at_pos
	testl	%eax, %eax
	jne	L1443
L1391:
	call	_gtk_ui_manager_get_type
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$80, %ecx
	movl	%eax, %edi
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC109, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	movl	$LC209, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1393
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	incl	%eax
	movl	%eax, _NSA
	movl	$-1, %eax
	movl	%eax, _NSA+12
	movl	$-1, %eax
	movl	%eax, _NSA+8
	movl	$-1, %eax
	movl	%edx, _LineSelected
	movl	%eax, _NSA+4
L1394:
	movl	_ZoneDessin, %ecx
	testl	%ecx, %ecx
	jne	L1444
	movl	(%esi), %eax
	cmpl	$5, %eax
	je	L1445
L1451:
	cmpl	$4, %eax
	je	L1446
L1399:
	movl	8(%ebp), %edx
	movl	(%edx), %eax
	movl	%esi, 4(%esp)
	movl	%edx, (%esp)
	call	*176(%eax)
L1388:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1443:
	movl	-16(%ebp), %edi
	testl	%edi, %edi
	je	L1391
	movl	%ebx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_selection
	movl	%eax, (%esp)
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_tree_selection_select_path
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_tree_path_to_string
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -24(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_tree_path_free
	jmp	L1391
	.p2align 4,,7
L1444:
	call	_rafresh_drawing
	movl	(%esi), %eax
	cmpl	$5, %eax
	jne	L1451
	.p2align 4,,15
L1445:
	movl	%ebx, (%esp)
	movl	$LC209, %edx
	movl	%edx, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1397
	call	_DialogueEdit
	movl	(%esi), %eax
L1453:
	cmpl	$4, %eax
	jne	L1399
	.p2align 4,,15
L1446:
	cmpl	$3, 40(%esi)
	jne	L1399
	testl	%ebx, %ebx
	je	L1418
	movl	%ebx, 4(%esp)
	movl	$LC210, (%esp)
	call	_g_strdup_printf
	movl	%eax, -28(%ebp)
	movl	%ebx, 4(%esp)
	movl	$LC211, (%esp)
	call	_g_strdup_printf
	movl	%eax, -32(%ebp)
	movl	%ebx, 4(%esp)
	movl	$LC212, (%esp)
	call	_g_strdup_printf
	movl	%eax, -36(%ebp)
	movl	%ebx, 4(%esp)
	movl	$LC213, (%esp)
	call	_g_strdup_printf
	movl	%eax, -40(%ebp)
	movl	-28(%ebp), %eax
	testl	%eax, %eax
	je	L1404
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	js	L1447
	movl	$1, (%esp)
L1433:
	movl	-28(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
L1404:
	movl	-36(%ebp), %eax
	testl	%eax, %eax
	je	L1407
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	js	L1448
	movl	$1, (%esp)
L1434:
	movl	-36(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L1407:
	movl	-32(%ebp), %eax
	testl	%eax, %eax
	je	L1410
	movl	%ebx, (%esp)
	movl	$LC209, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1411
	movl	_NcentersZmat, %ecx
	testl	%ecx, %ecx
L1439:
	jne	L1416
	movl	$0, (%esp)
L1435:
	movl	-32(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
L1414:
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
L1410:
	movl	-40(%ebp), %eax
	testl	%eax, %eax
	je	L1418
	movl	%ebx, (%esp)
	movl	$LC209, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1419
	movl	_NcentersZmat, %eax
L1441:
	testl	%eax, %eax
	jne	L1424
	movl	$0, (%esp)
L1436:
	movl	-40(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
L1422:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L1418:
	movl	40(%esi), %edx
	movl	12(%esi), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, -44(%ebp)
	movl	%eax, -48(%ebp)
	movl	%edi, (%esp)
	call	_gtk_ui_manager_get_widget
	movl	%eax, %ebx
	call	_gtk_menu_get_type
	testl	%ebx, %ebx
	je	L1427
	movl	(%ebx), %edx
	testl	%edx, %edx
	je	L1427
	cmpl	%eax, (%edx)
	je	L1430
L1427:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L1399
L1430:
	call	_gtk_menu_get_type
	movl	%eax, 4(%esp)
	xorl	%edi, %edi
	movl	%ebx, (%esp)
	xorl	%ebx, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-48(%ebp), %edx
	xorl	%ecx, %ecx
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 24(%esp)
	movl	-44(%ebp), %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 20(%esp)
	xorl	%edx, %edx
	movl	%edx, 4(%esp)
	call	_gtk_menu_popup
	jmp	L1399
	.p2align 4,,7
L1393:
	movl	-24(%ebp), %eax
	movl	%eax, _LineSelectedV
	movl	%eax, _LineSelectedOld
	jmp	L1394
L1442:
	movl	%ebx, 4(%esp)
	movl	8(%ebp), %edx
	xorl	%edi, %edi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 20(%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 24(%esp)
	xorl	%edx, %edx
	movl	%edx, 12(%esp)
	movl	%ecx, 16(%esp)
	fldl	24(%esi)
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %edx
	orw	$3072, %dx
	movw	%dx, -20(%ebp)
	fldcw	-20(%ebp)
	fistpl	8(%esp)
	fldcw	-18(%ebp)
	fldl	16(%esi)
	fldcw	-20(%ebp)
	fistpl	4(%esp)
	fldcw	-18(%ebp)
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_path_at_pos
	testl	%eax, %eax
	jne	L1390
	movl	%ebx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_selection
	movl	%eax, (%esp)
	call	_gtk_tree_selection_unselect_all
	jmp	L1390
L1397:
	call	_DialogueEditV
	movl	(%esi), %eax
	jmp	L1453
L1424:
	movl	$1, (%esp)
	jmp	L1436
L1416:
	movl	$1, (%esp)
	jmp	L1435
L1447:
	movl	$0, (%esp)
	jmp	L1433
L1448:
	movl	$0, (%esp)
	jmp	L1434
L1419:
	movl	%ebx, (%esp)
	movl	$LC214, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1422
	movl	_NVariables, %eax
	jmp	L1441
L1411:
	movl	%ebx, (%esp)
	movl	$LC214, %edx
	movl	%edx, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1414
	movl	_NVariables, %eax
	testl	%eax, %eax
	jmp	L1439
	.section .rdata,"dr"
LC216:
	.ascii "New Center\0"
LC217:
	.ascii " New Center \0"
LC218:
	.ascii "H\0"
LC219:
	.ascii "UNK\0"
LC221:
	.ascii "0.0\0"
	.align 8
LC220:
	.long	1202590843
	.long	1068792545
	.text
	.p2align 4,,15
	.def	_DialogueAdd;	.scl	3;	.type	32;	.endef
_DialogueAdd:
	pushl	%ebp
	cld
	movl	%esp, %ebp
	pushl	%edi
	movl	$13, %ecx
	pushl	%esi
	leal	-88(%ebp), %edi
	pushl	%ebx
	subl	$140, %esp
	movl	$LC201, %esi
	rep
	movsl
	movl	_NcentersZmat, %eax
	xorl	%esi, %esi
	movl	%esi, _InEdit
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -116(%ebp)
	movl	_NcentersZmat, %ebx
	testl	%ebx, %ebx
	je	L1478
	movl	$1, %esi
	.p2align 4,,15
L1458:
	movl	%esi, 4(%esp)
	movl	%esi, %ebx
	movl	$LC45, (%esp)
	call	_g_strdup_printf
	movl	-116(%ebp), %edx
	movl	%eax, -4(%edx,%esi,4)
	incl	%esi
	cmpl	_NcentersZmat, %ebx
	jb	L1458
L1478:
	call	_gtk_dialog_new
	movl	%eax, -104(%ebp)
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	-104(%ebp), %ecx
	movl	%eax, %ebx
	xorl	%edi, %edi
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC216, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_title
	movl	%ebx, 4(%esp)
	movl	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_position
	movl	%ebx, 4(%esp)
	movl	_WindowGeom, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
	movl	-104(%ebp), %edx
	movl	%eax, %esi
	xorl	%ebx, %ebx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	call	_gtk_window_set_transient_for
	movl	$LC217, %eax
	movl	-104(%ebp), %ecx
	movl	%eax, 12(%esp)
	movl	$_gtk_widget_destroy, %eax
	movl	%eax, 8(%esp)
	movl	_WindowGeom, %eax
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_add_child
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_delete_child, %ecx
	movl	$LC143, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edi, 20(%esp)
	movl	$4, %edi
	movl	%esi, 16(%esp)
	movl	$80, %esi
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	movl	$0, (%esp)
	call	_gtk_frame_new
	movl	%eax, %ebx
	call	_gtk_frame_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	movl	$10, %edi
	call	_gtk_frame_set_shadow_type
	movl	%ebx, (%esp)
	call	_g_object_ref
	movl	%esi, 4(%esp)
	movl	-104(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC175, %edx
	movl	$_g_object_unref, %ecx
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	movl	%ebx, 8(%esp)
	call	_g_object_set_data_full
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_container_set_border_width
	call	_gtk_box_get_type
	movl	%eax, %esi
	call	_gtk_dialog_get_type
	movl	%eax, 4(%esp)
	movl	-104(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 4(%esp)
	movl	148(%eax), %eax
	xorl	%esi, %esi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	%ebx, (%esp)
	call	_create_vbox
	movl	%eax, -112(%ebp)
	movl	%eax, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movl	%eax, %esi
	movzwl	-98(%ebp), %eax
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fld	%st(0)
	movl	-84(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-100(%ebp)
	fistpl	12(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	8(%esp)
	fldcw	-98(%ebp)
	call	_create_label_entry
	movl	%eax, _Entry+4
	movl	_NcentersZmat, %edi
	movl	%eax, %ebx
	testl	%edi, %edi
	jne	L1459
	call	_gtk_entry_get_type
	movl	%ebx, (%esp)
	movl	$LC218, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
L1479:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	movl	_Entry+4, %eax
	xorl	%edi, %edi
	movl	$5, %ebx
	movl	%edi, 4(%esp)
	movl	$80, %edi
	movl	%eax, (%esp)
	call	_gtk_editable_set_editable
	movl	$LC206, (%esp)
	call	_gtk_button_new_with_label
	movl	%eax, -108(%ebp)
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	xorl	%esi, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	$1, %ecx
	movl	%edx, 8(%esp)
	movl	-108(%ebp), %edx
	movl	%ebx, 16(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 4(%esp)
	movl	%ecx, 12(%esp)
	call	_gtk_box_pack_start
	movl	%edi, 4(%esp)
	movl	-108(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	_Entry+4, %edx
	movl	$_SelectAtom, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 20(%esp)
	movl	%edx, 12(%esp)
	movl	$LC147, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	call	_g_signal_connect_data
	movl	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	movl	$0, -92(%ebp)
	movl	%eax, %esi
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	_getListMMTypes
	movl	-92(%ebp), %edx
	movl	%eax, %edi
	testl	%edx, %edx
	je	L1461
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fld	%st(0)
	movl	$1, %eax
	fmull	_entryWidth
	fxch	%st(1)
	movl	%eax, 16(%esp)
	movl	-80(%ebp), %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 4(%esp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	call	_create_label_combo
L1480:
	movl	%eax, _Entry+8
	testl	%edi, %edi
	movl	%eax, %ebx
	je	L1463
	movl	-92(%ebp), %edx
	movl	%edi, %eax
	call	_freeList
	movl	_Entry+8, %ebx
L1463:
	movl	_NcentersZmat, %esi
	testl	%esi, %esi
	jne	L1464
	call	_gtk_entry_get_type
	movl	%ebx, (%esp)
	movl	$LC218, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
L1481:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	movl	-112(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	movl	$0, -96(%ebp)
	movl	%eax, %esi
	leal	-96(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC219, (%esp)
	call	_getListPDBTypes
	movl	-96(%ebp), %edx
	movl	%eax, %edi
	testl	%edx, %edx
	je	L1466
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fld	%st(0)
	movl	$1, %eax
	fmull	_entryWidth
	fxch	%st(1)
	movl	%eax, 16(%esp)
	movl	-76(%ebp), %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 4(%esp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	call	_create_label_combo
L1482:
	movl	%eax, _Entry+12
	movl	_NcentersZmat, %esi
	movl	%eax, %ebx
	testl	%esi, %esi
	jne	L1468
	call	_gtk_entry_get_type
	movl	%ebx, (%esp)
	movl	$LC218, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
L1483:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	testl	%edi, %edi
	je	L1470
	movl	-96(%ebp), %edx
	movl	%edi, %eax
	call	_freeList
L1470:
	movl	-112(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movl	%eax, %esi
	movzwl	-98(%ebp), %eax
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fld	%st(0)
	movl	-72(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-100(%ebp)
	fistpl	12(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	8(%esp)
	fldcw	-98(%ebp)
	call	_create_label_entry
	movl	%eax, _Entry+16
	movl	_NcentersZmat, %esi
	movl	%eax, %ebx
	testl	%esi, %esi
	jne	L1471
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	movl	$LC168, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	call	_get_list_variables
	movl	%eax, %edi
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	jne	L1485
L1489:
	cmpl	$1, %eax
	ja	L1486
L1490:
	cmpl	$2, %eax
	ja	L1487
L1475:
	movl	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	%edi, %eax
	call	_freelistvariables
	movl	-112(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movl	%eax, %esi
	movzwl	-98(%ebp), %eax
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fld	%st(0)
	movl	-44(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-100(%ebp)
	fistpl	12(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	8(%esp)
	fldcw	-98(%ebp)
	call	_create_label_entry
	movl	%eax, _Entry+44
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC221, %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	$16, (%esp)
	call	_g_malloc
	movl	%eax, -116(%ebp)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	$LC99, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	$LC100, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %ecx
	movl	%eax, 8(%ecx)
	movl	$LC101, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	-112(%ebp), %ecx
	movl	%eax, 12(%edx)
	movl	%ecx, (%esp)
	call	_create_hbox_false
	cmpl	$3, _iprogram
	movl	%eax, %esi
	je	L1476
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movl	$4, %edi
	movzwl	-98(%ebp), %eax
	movl	%edi, 12(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	xorl	%eax, %eax
	fld	%st(0)
	movl	%eax, 16(%esp)
	movl	-116(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 8(%esp)
	movl	-40(%ebp), %eax
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry+48
L1476:
	movl	-104(%ebp), %edx
	movl	$LC149, %esi
	xorl	%ebx, %ebx
	movl	%edx, (%esp)
	call	_gtk_widget_realize
	movl	%esi, 4(%esp)
	movl	-104(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_create_button
	movl	%eax, -108(%ebp)
	call	_gtk_box_get_type
	movl	%eax, -120(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %edi
	movl	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-120(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	-108(%ebp), %ecx
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 4(%esp)
	call	_gtk_box_pack_start
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-108(%ebp), %edx
	movl	%eax, %ebx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%ecx, 20(%esp)
	movl	$_delete_child, %ecx
	movl	%edx, 16(%esp)
	movl	$LC147, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	movl	$LC150, %ebx
	movl	%ecx, 8(%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	-108(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	-104(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	$80, %ebx
	movl	%eax, (%esp)
	call	_create_button
	movl	%eax, -108(%ebp)
	movl	-104(%ebp), %edx
	movl	%edi, 4(%esp)
	movl	$1, %edi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	-120(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	xorl	%ecx, %ecx
	movl	%edx, 12(%esp)
	movl	-108(%ebp), %edx
	movl	%ecx, 16(%esp)
	movl	%edi, 8(%esp)
	movl	$_AddAtom, %edi
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, 4(%esp)
	movl	-108(%ebp), %ecx
	movl	$LC147, %ebx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	_Entry+4, %edx
	movl	%ecx, 20(%esp)
	movl	%edi, 8(%esp)
	xorl	%edi, %edi
	movl	%edx, 12(%esp)
	movl	%ebx, 4(%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-108(%ebp), %edx
	movl	%eax, %ebx
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 12(%esp)
	movl	$2, %edx
	movl	$LC147, %ecx
	movl	%edx, 20(%esp)
	movl	$_destroy_dialogue, %ebx
	movl	%edi, 16(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	-108(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_grab_default
	movl	-104(%ebp), %edx
	movl	%edx, (%esp)
	call	_gtk_widget_show_all
	movl	-116(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_free
	call	_set_entry_Zmat
	addl	$140, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1471:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	_NcentersZmat, %ecx
	leal	0(,%ecx,8), %edx
	subl	%ecx, %edx
	movl	_Geom, %ecx
	sall	$3, %edx
	addl	%ecx, %edx
	movl	-40(%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	call	_get_list_variables
	movl	%eax, %edi
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	je	L1489
L1485:
	movl	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	fnstcw	-98(%ebp)
	fildl	_ScreenHeight
	movl	%eax, %esi
	movzwl	-98(%ebp), %eax
	movl	%edi, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	movl	$1, %eax
	fld	%st(0)
	movl	%eax, 16(%esp)
	movl	_NVariables, %eax
	fmull	_entryWidth
	fxch	%st(1)
	incl	%eax
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 12(%esp)
	movl	-68(%ebp), %eax
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movl	-116(%ebp), %edx
	movl	%eax, _Entry+20
	movzwl	-98(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	fld	%st(0)
	movw	%ax, -100(%ebp)
	xorl	%eax, %eax
	movl	%eax, 16(%esp)
	movl	_NcentersZmat, %eax
	fmull	LC220
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 12(%esp)
	movl	-64(%ebp), %eax
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry+24
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	_NcentersZmat, %edx
	movl	-116(%ebp), %ecx
	movl	-4(%ecx,%edx,4), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	_NcentersZmat, %eax
	cmpl	$1, %eax
	jbe	L1490
L1486:
	movl	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	fnstcw	-98(%ebp)
	fildl	_ScreenHeight
	movl	%eax, %esi
	movzwl	-98(%ebp), %eax
	movl	%edi, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	movl	$1, %eax
	fld	%st(0)
	movl	%eax, 16(%esp)
	movl	_NVariables, %eax
	fmull	_entryWidth
	fxch	%st(1)
	incl	%eax
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 12(%esp)
	movl	-60(%ebp), %eax
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movl	-116(%ebp), %edx
	movl	%eax, _Entry+28
	movzwl	-98(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	fld	%st(0)
	movw	%ax, -100(%ebp)
	xorl	%eax, %eax
	movl	%eax, 16(%esp)
	movl	_NcentersZmat, %eax
	fmull	LC220
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry+32
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+24, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-116(%ebp), %ecx
	movl	_NcentersZmat, %edx
	movl	-4(%ecx,%edx,4), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
	movl	_Entry+32, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_NcentersZmat, %edx
	movl	-116(%ebp), %ecx
	movl	-8(%ecx,%edx,4), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	_NcentersZmat, %eax
	cmpl	$2, %eax
	jbe	L1475
L1487:
	movl	-112(%ebp), %eax
	movl	$1, %ebx
	movl	%eax, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movl	%eax, %esi
	movzwl	-98(%ebp), %eax
	movl	%ebx, 16(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	movl	_NVariables, %eax
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	incl	%eax
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 12(%esp)
	movl	-52(%ebp), %eax
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movl	%eax, _Entry+36
	movl	-116(%ebp), %edx
	xorl	%ecx, %ecx
	movzwl	-98(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fld	%st(0)
	movl	_NcentersZmat, %eax
	fmull	LC220
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 12(%esp)
	movl	-48(%ebp), %eax
	fldcw	-100(%ebp)
	fistpl	24(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	20(%esp)
	fldcw	-98(%ebp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry+40
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+24, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-116(%ebp), %ecx
	movl	_NcentersZmat, %edx
	movl	-4(%ecx,%edx,4), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
	movl	_Entry+32, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-116(%ebp), %ecx
	movl	_NcentersZmat, %edx
	movl	-8(%ecx,%edx,4), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
	movl	_Entry+40, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-116(%ebp), %ecx
	movl	_NcentersZmat, %edx
	movl	-12(%ecx,%edx,4), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	jmp	L1475
L1468:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	_NcentersZmat, %ecx
	leal	0(,%ecx,8), %edx
	subl	%ecx, %edx
	movl	_Geom, %ecx
	sall	$3, %edx
	addl	%ecx, %edx
	movl	-44(%edx), %edx
	movl	%edx, 4(%esp)
	jmp	L1483
L1466:
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fld	%st(0)
	movl	-76(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-100(%ebp)
	fistpl	12(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	8(%esp)
	fldcw	-98(%ebp)
	call	_create_label_entry
	jmp	L1482
L1464:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	_NcentersZmat, %ecx
	leal	0(,%ecx,8), %edx
	subl	%ecx, %edx
	movl	_Geom, %ecx
	sall	$3, %edx
	addl	%ecx, %edx
	movl	-48(%edx), %edx
	movl	%edx, 4(%esp)
	jmp	L1481
L1461:
	fildl	_ScreenHeight
	fnstcw	-98(%ebp)
	movzwl	-98(%ebp), %eax
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -100(%ebp)
	fld	%st(0)
	movl	-80(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-100(%ebp)
	fistpl	12(%esp)
	fldcw	-98(%ebp)
	fldcw	-100(%ebp)
	fistpl	8(%esp)
	fldcw	-98(%ebp)
	call	_create_label_entry
	jmp	L1480
L1459:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	_NcentersZmat, %ecx
	leal	0(,%ecx,8), %edx
	subl	%ecx, %edx
	movl	_Geom, %ecx
	sall	$3, %edx
	addl	%ecx, %edx
	movl	-52(%edx), %edx
	movl	%edx, 4(%esp)
	jmp	L1479
	.p2align 4,,15
.globl _put_geom_in_list
	.def	_put_geom_in_list;	.scl	2;	.type	32;	.endef
_put_geom_in_list:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	_Geom, %eax
	testl	%eax, %eax
	jne	L1495
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1496
L1493:
	cmpl	$1, _iprogram
	je	L1497
L1491:
	leave
	ret
	.p2align 4,,7
L1495:
	call	_append_list_geom
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L1493
	.p2align 4,,15
L1496:
	call	_rafresh_drawing
	cmpl	$1, _iprogram
	jne	L1491
	.p2align 4,,15
L1497:
	leave
	jmp	_set_spin_of_electrons
	.p2align 4,,15
.globl _ThisIsNotAnAtom
	.def	_ThisIsNotAnAtom;	.scl	2;	.type	32;	.endef
_ThisIsNotAnAtom:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	call	_get_periodic_table
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, (%esp)
	movl	%eax, %edi
	call	_uppercase
	movl	$0, -16(%ebp)
L1507:
	xorl	%esi, %esi
	.p2align 4,,15
L1506:
	movl	-20(%ebp), %edx
	movl	(%edx,%esi,4), %eax
	movl	-16(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_uppercase
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L1512
	movl	%ebx, (%esp)
	incl	%esi
	call	_g_free
	cmpl	$17, %esi
	jle	L1506
	incl	-16(%ebp)
	cmpl	$9, -16(%ebp)
	jle	L1507
	movl	%edi, (%esp)
	call	_g_free
	movl	$1, %eax
	jmp	L1498
L1512:
	movl	%ebx, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	xorl	%eax, %eax
L1498:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
.globl _Geom_Change_Unit
	.def	_Geom_Change_Unit;	.scl	2;	.type	32;	.endef
_Geom_Change_Unit:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	_NcentersZmat, %edi
	movl	$1, -16(%ebp)
	cmpl	%edi, -16(%ebp)
	jae	L1533
	movl	$56, %esi
	.p2align 4,,15
L1520:
	movl	_Geom, %eax
	movl	24(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1516
	movl	8(%ebp), %eax
	testl	%eax, %eax
	je	L1518
	movl	_Geom, %ebx
	movl	24(%esi,%ebx), %eax
	movl	%eax, (%esp)
	call	_bohr_to_ang
L1539:
	movl	%eax, 24(%esi,%ebx)
L1516:
	incl	-16(%ebp)
	addl	$56, %esi
	movl	_NcentersZmat, %edi
	cmpl	%edi, -16(%ebp)
	jb	L1520
L1533:
	movl	$0, -16(%ebp)
	movl	_NVariables, %eax
	cmpl	%eax, -16(%ebp)
	movl	$0, -32(%ebp)
	movl	%eax, -24(%ebp)
	jae	L1535
	.p2align 4,,15
L1531:
	movl	$1, %esi
	cmpl	%edi, %esi
	jae	L1525
	movl	_Geom, %edx
	movl	$56, %ebx
	movl	_Variables, %ecx
	movl	%edx, -20(%ebp)
	movl	%ecx, -28(%ebp)
	.p2align 4,,15
L1530:
	movl	-32(%ebp), %edx
	movl	-28(%ebp), %ecx
	movl	(%edx,%ecx), %eax
	movl	-20(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	24(%ebx,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L1540
	incl	%esi
	addl	$56, %ebx
	cmpl	%edi, %esi
	jb	L1530
L1525:
	incl	-16(%ebp)
	movl	-24(%ebp), %eax
	addl	$12, -32(%ebp)
	cmpl	%eax, -16(%ebp)
	jae	L1535
	movl	_NcentersZmat, %edi
	jmp	L1531
L1518:
	movl	_Geom, %ebx
	movl	24(%esi,%ebx), %eax
	movl	%eax, (%esp)
	call	_ang_to_bohr
	jmp	L1539
L1535:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1540:
	movl	8(%ebp), %eax
	testl	%eax, %eax
	jne	L1538
	movl	-32(%ebp), %ecx
	movl	-28(%ebp), %edx
	movl	4(%ecx,%edx), %eax
	movl	%eax, (%esp)
	call	_ang_to_bohr
	movl	-32(%ebp), %ecx
	movl	-28(%ebp), %edx
	movl	%eax, 4(%ecx,%edx)
	movl	_NVariables, %ecx
	movl	%ecx, -24(%ebp)
	jmp	L1525
L1538:
	movl	-32(%ebp), %edx
	movl	-28(%ebp), %ecx
	movl	4(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_bohr_to_ang
	movl	-32(%ebp), %edx
	movl	-28(%ebp), %ecx
	movl	%eax, 4(%edx,%ecx)
	movl	_NVariables, %eax
	movl	%eax, -24(%ebp)
	jmp	L1525
	.p2align 4,,15
	.def	_deleteNumericChars;	.scl	3;	.type	32;	.endef
_deleteNumericChars:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$12, %esp
	movl	%eax, (%esp)
	call	_strlen
	testl	%eax, %eax
	movl	%eax, %edi
	jle	L1542
	movsbl	(%esi),%eax
	movl	%eax, (%esp)
	call	_toupper
	movb	%al, (%esi)
L1542:
	movl	$1, %ebx
	cmpl	%edi, %ebx
	jge	L1541
	.p2align 4,,15
L1555:
	movsbl	(%ebx,%esi),%edx
	movl	__imp____mb_cur_max, %eax
	cmpl	$1, (%eax)
	jne	L1547
	movl	__imp___pctype, %eax
	movl	(%eax), %eax
	movzwl	(%eax,%edx,2), %eax
	andl	$4, %eax
	testl	%eax, %eax
	jne	L1554
L1546:
	movsbl	(%ebx,%esi),%eax
	movl	%eax, (%esp)
	call	_tolower
	movb	%al, (%ebx,%esi)
	incl	%ebx
	cmpl	%edi, %ebx
	jl	L1555
L1541:
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1547:
	movl	%edx, (%esp)
	movl	$4, %eax
	movl	%eax, 4(%esp)
	call	__isctype
	testl	%eax, %eax
	je	L1546
L1554:
	movb	$0, (%ebx,%esi)
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC223:
	.ascii "r\0"
LC225:
	.ascii "ZMAT\0"
LC226:
	.ascii "END\0"
LC227:
	.ascii "BASIS\0"
	.align 4
LC228:
	.ascii "Sorry, I cannot read the Z-Matrix from the  %s file\0"
LC229:
	.ascii "MATRIX\0"
LC230:
	.ascii "VARIABLE\0"
LC233:
	.ascii "%s %s %s %s %s %s %s \0"
LC235:
	.ascii "CHARGE\0"
LC236:
	.ascii "ZSPIN\0"
LC231:
	.ascii "%s %s %s \0"
LC232:
	.ascii "%s %s %s %s %s\0"
LC224:
	.ascii "Sorry, I cannot open %s file\0"
	.align 4
LC234:
	.ascii "Sorry\12 I can not read geometry from you Molcas input file\0"
	.text
	.p2align 4,,15
.globl _read_Zmat_from_molcas_input_file
	.def	_read_Zmat_from_molcas_input_file;	.scl	2;	.type	32;	.endef
_read_Zmat_from_molcas_input_file:
	pushl	%ebp
	movl	$4204, %eax
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	call	__alloca
	movl	8(%ebp), %eax
	movl	$LC223, %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_FOpen
	testl	%eax, %eax
	movl	%eax, %esi
	je	L1623
	xorl	%ebx, %ebx
	testb	$16, 12(%eax)
	jne	L1611
	leal	-1080(%ebp), %edi
	.p2align 4,,15
L1564:
	movl	%esi, 8(%esp)
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_fgets
	testl	%eax, %eax
	je	L1611
	movl	%edi, (%esp)
	call	_g_strup
	movl	%edi, (%esp)
	movl	$LC225, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	movl	%edi, (%esp)
	cmpl	$1, %eax
	movl	$LC226, %eax
	movl	%eax, 4(%esp)
	sbbl	$-1, %ebx
	call	_strstr
	testl	%eax, %eax
	je	L1558
	movl	%edi, (%esp)
	movl	$LC227, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	jne	L1624
L1558:
	testb	$16, 12(%esi)
	je	L1564
L1611:
	movl	8(%ebp), %eax
	leal	-3128(%ebp), %ebx
	movl	%eax, 8(%esp)
	movl	$LC228, %eax
	movl	%eax, 4(%esp)
L1620:
	movl	%ebx, (%esp)
	movl	$1, %edi
	movl	$LC48, %esi
	call	_sprintf
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
L1616:
	call	_MessageGeom
	movl	$-1, %eax
L1556:
	addl	$4204, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1624:
	testl	%ebx, %ebx
	jle	L1611
	movl	$1, %ebx
	movl	%ebx, -4156(%ebp)
	xorl	%ebx, %ebx
	.p2align 4,,15
L1569:
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, -56(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$6, %ebx
	jle	L1569
	movl	$56, (%esp)
	leal	-1080(%ebp), %edi
	call	_g_malloc
	movl	%eax, -4160(%ebp)
	movl	$1024, %ecx
	movl	%ecx, 4(%esp)
	movl	%esi, 8(%esp)
	movl	%edi, (%esp)
	call	_fgets
	movl	%edi, (%esp)
	movl	-56(%ebp), %eax
	movl	$LC98, %edx
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	_sscanf
	movl	%eax, %ebx
	decl	%ebx
	je	L1625
	xorl	%eax, %eax
	movl	%eax, -4156(%ebp)
	movl	$-1, %eax
	movl	%eax, -4164(%ebp)
	movl	-4160(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	xorl	%eax, %eax
	movl	%eax, -4160(%ebp)
L1622:
	movl	12(%esi), %eax
	xorl	%edx, %edx
	shrl	$4, %eax
	xorl	$1, %eax
	cmpl	$0, -4156(%ebp)
	setne	%dl
	testl	%edx, %eax
	je	L1573
L1627:
	movl	%esi, 8(%esp)
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_fgets
	movl	%edi, (%esp)
	call	_g_strup
	movl	%edi, (%esp)
	movl	$LC226, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1574
	movl	%edi, (%esp)
	movl	$LC229, %ebx
	movl	%ebx, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	jne	L1573
L1574:
	movl	%edi, (%esp)
	movl	$LC230, %ecx
	movl	%ecx, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	jne	L1573
	incl	-4164(%ebp)
	movl	-4164(%ebp), %ebx
	movl	-4164(%ebp), %edx
	sall	$3, %ebx
	subl	%edx, %ebx
	movl	-4160(%ebp), %edx
	sall	$3, %ebx
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	call	_g_realloc
	cmpl	$2, -4164(%ebp)
	leal	-56(%ebx,%eax), %ebx
	movl	%eax, -4160(%ebp)
	movl	$0, 4(%ebx)
	movl	$0, 8(%ebx)
	movl	$0, 12(%ebx)
	movl	$0, 28(%ebx)
	movl	$0, 24(%ebx)
	movl	$0, 36(%ebx)
	movl	$0, 32(%ebx)
	movl	$0, 44(%ebx)
	movl	$0, 40(%ebx)
	movl	$0, 48(%ebx)
	movl	$0, 52(%ebx)
	je	L1577
	cmpl	$3, -4164(%ebp)
	je	L1580
	movl	%edi, (%esp)
	movl	-32(%ebp), %eax
	movl	$LC233, %ebx
	movl	%ebx, 4(%esp)
	movl	%eax, 32(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	call	_sscanf
	movl	%eax, %ebx
	movl	-56(%ebp), %eax
	call	_deleteNumericChars
	cmpl	$7, %ebx
	je	L1626
L1584:
	decl	-4164(%ebp)
	movl	-4164(%ebp), %eax
	movl	-4164(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	movl	-4160(%ebp), %eax
	movl	%eax, (%esp)
L1617:
	call	_g_realloc
	movl	%eax, -4160(%ebp)
	xorl	%ebx, %ebx
	movl	%ebx, -4156(%ebp)
	movl	12(%esi), %eax
	xorl	%edx, %edx
	shrl	$4, %eax
	xorl	$1, %eax
	cmpl	$0, -4156(%ebp)
	setne	%dl
	testl	%edx, %eax
	jne	L1627
L1573:
	xorl	%ebx, %ebx
	.p2align 4,,15
L1590:
	movl	-56(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$6, %ebx
	jle	L1590
	movl	-4156(%ebp), %ecx
	movl	-4164(%ebp), %edx
	testl	%ecx, %ecx
	sete	%al
	testl	%edx, %edx
	setle	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L1628
	movl	%esi, (%esp)
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	movl	%eax, _TotalCharges
	xorl	%ebx, %ebx
	movl	$1, %edi
	movl	%edi, _SpinMultiplicities
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	call	_fseek
	testb	$16, 12(%esi)
	jne	L1595
	leal	-4152(%ebp), %ebx
L1598:
	movl	%esi, 8(%esp)
	movl	$1024, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, (%esp)
	call	_fgets
	testl	%eax, %eax
	je	L1595
	movl	%ebx, (%esp)
	call	_g_strup
	movl	%ebx, (%esp)
	movl	$LC235, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1596
	movl	%ebx, (%esp)
	movl	$61, %eax
	movl	%eax, 4(%esp)
	call	_strchr
	testl	%eax, %eax
	je	L1596
	incl	%eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, _TotalCharges
L1596:
	movl	%ebx, (%esp)
	movl	$LC236, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1592
	movl	%ebx, (%esp)
	movl	$61, %eax
	movl	%eax, 4(%esp)
	call	_strchr
	testl	%eax, %eax
	je	L1592
	incl	%eax
	movl	%eax, (%esp)
	call	_atoi
	incl	%eax
	movl	%eax, _SpinMultiplicities
L1592:
	testb	$16, 12(%esi)
	je	L1598
L1595:
	movl	%esi, (%esp)
	call	_fclose
	movl	_Geom, %eax
	testl	%eax, %eax
	jne	L1629
L1599:
	movl	_Variables, %eax
	testl	%eax, %eax
	jne	L1630
L1600:
	movl	_Units, %ecx
	xorl	%edi, %edi
	xorl	%esi, %esi
	movl	%edi, _NVariables
	movl	-4160(%ebp), %edx
	movl	$14, %ebx
	movl	%esi, _Variables
	movl	-4164(%ebp), %eax
	testl	%ecx, %ecx
	movl	%edx, _Geom
	movl	%eax, _NcentersZmat
	movl	%ebx, _MethodeGeom
	je	L1631
L1601:
	movl	_GeomIsOpen, %edx
	testl	%edx, %edx
	jne	L1632
L1602:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1633
L1603:
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	_set_last_directory
	xorl	%eax, %eax
	jmp	L1556
L1626:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1584
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1584
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1584
	movl	-4164(%ebp), %eax
	movl	-4164(%ebp), %ecx
	movl	-4160(%ebp), %edx
	sall	$3, %eax
	subl	%ecx, %eax
	leal	(%edx,%eax,8), %eax
	movl	$11, -56(%eax)
	leal	-56(%eax), %ebx
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 16(%ebx)
	movl	-52(%ebp), %eax
	movl	$0, 20(%ebx)
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%ebx)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 24(%ebx)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 36(%ebx)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 32(%ebx)
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 44(%ebx)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 40(%ebx)
L1618:
	movl	$LC221, (%esp)
	call	_g_strdup
	movl	%eax, 48(%ebx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 52(%ebx)
	jmp	L1622
L1577:
	movl	%edi, (%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC231, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	movl	%eax, %ebx
	movl	-56(%ebp), %eax
	call	_deleteNumericChars
	cmpl	$3, %ebx
	je	L1634
L1578:
	movl	$1, %eax
	movl	%eax, -4164(%ebp)
	movl	$56, %eax
L1621:
	movl	%eax, 4(%esp)
	movl	-4160(%ebp), %edx
	movl	%edx, (%esp)
	jmp	L1617
L1580:
	movl	%edi, (%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC232, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	movl	%eax, %ebx
	movl	-56(%ebp), %eax
	call	_deleteNumericChars
	cmpl	$5, %ebx
	je	L1635
L1581:
	movl	$2, %eax
	movl	%eax, -4164(%ebp)
	movl	$112, %eax
	jmp	L1621
L1625:
	movl	-56(%ebp), %eax
	call	_deleteNumericChars
	movl	$56, (%esp)
	movl	$1, %eax
	movl	%eax, -4164(%ebp)
	call	_g_malloc
	movl	$5, (%eax)
	movl	%eax, -4160(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-4160(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-4160(%ebp), %edx
	movl	%eax, 8(%edx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-4160(%ebp), %edx
	movl	%eax, 12(%edx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	-4160(%ebp), %edx
	movl	%eax, 16(%edx)
	movl	$0, 20(%edx)
	movl	$LC221, (%esp)
	call	_g_strdup
	movl	-4160(%ebp), %edx
	movl	%eax, 48(%edx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	-4160(%ebp), %edx
	movl	%eax, 52(%edx)
	jmp	L1622
L1632:
	movl	$43, (%esp)
	call	_create_geom_interface
	jmp	L1602
L1631:
	movl	$0, (%esp)
	call	_Geom_Change_Unit
	jmp	L1601
L1630:
	call	_freeVariables
	jmp	L1600
L1629:
	call	_freeGeom
	jmp	L1599
L1633:
	call	_rafresh_drawing
	jmp	L1603
L1634:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1578
	movl	-4160(%ebp), %eax
	movl	-4160(%ebp), %ebx
	movl	$7, 56(%eax)
	movl	-56(%ebp), %eax
	addl	$56, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 16(%ebx)
	movl	-52(%ebp), %eax
	movl	$0, 20(%ebx)
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%ebx)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 24(%ebx)
	jmp	L1618
L1635:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1581
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1581
	movl	-4160(%ebp), %eax
	movl	-4160(%ebp), %ebx
	movl	$9, 112(%eax)
	movl	-56(%ebp), %eax
	addl	$112, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 16(%ebx)
	movl	-52(%ebp), %eax
	movl	$0, 20(%ebx)
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%ebx)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 24(%ebx)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 36(%ebx)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 32(%ebx)
	jmp	L1618
L1623:
	movl	8(%ebp), %edx
	movl	$LC224, %eax
	leal	-2104(%ebp), %ebx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	L1620
L1628:
	movl	$LC234, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	jmp	L1616
	.section .rdata,"dr"
	.align 4
LC239:
	.ascii "Sorry\12 I can not read geometry in Molpro input file\0"
LC237:
	.ascii "Variables\0"
LC238:
	.ascii "%s %s %s\0"
	.text
	.p2align 4,,15
.globl _read_Zmat_from_molpro_input_file
	.def	_read_Zmat_from_molpro_input_file;	.scl	2;	.type	32;	.endef
_read_Zmat_from_molpro_input_file:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$140, %esp
	xorl	%ebx, %ebx
	movl	$0, -68(%ebp)
	movl	$0, -72(%ebp)
	movl	$0, -76(%ebp)
	movl	$0, -80(%ebp)
	movl	$0, -84(%ebp)
	movl	$0, -88(%ebp)
	.p2align 4,,15
L1640:
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, -56(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$6, %ebx
	jbe	L1640
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, %edi
	movl	$LC223, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_FOpen
	movl	%eax, -64(%ebp)
	testl	%eax, %eax
	movl	$1, -60(%ebp)
	je	L1641
	xorl	%ebx, %ebx
	cmpl	12(%ebp), %ebx
	jge	L1716
	.p2align 4,,15
L1737:
	movl	-64(%ebp), %edx
	movl	$1024, %esi
	movl	%edi, (%esp)
	incl	%ebx
	movl	%esi, 4(%esp)
	movl	%edx, 8(%esp)
	call	_fgets
	cmpl	12(%ebp), %ebx
	jl	L1737
L1716:
	movl	$56, (%esp)
	call	_g_malloc
	movl	%eax, -76(%ebp)
	movl	-64(%ebp), %eax
	movl	$1024, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	%edi, (%esp)
	call	_fgets
	movl	$0, -68(%ebp)
	movl	-64(%ebp), %edx
	movl	%edi, (%esp)
	movl	%edx, 8(%esp)
	movl	$1024, %edx
	movl	%edx, 4(%esp)
	call	_fgets
	cmpb	$125, (%edi)
	je	L1735
	movl	-56(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$LC98, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	movl	%eax, %ebx
	decl	%ebx
	je	L1738
	movl	$0, -60(%ebp)
	movl	-76(%ebp), %eax
	movl	$-1, -80(%ebp)
	movl	%eax, (%esp)
	call	_g_free
	movl	$0, -76(%ebp)
	.p2align 4,,15
L1647:
	movl	-64(%ebp), %edx
	movl	12(%edx), %eax
	xorl	%edx, %edx
	shrl	$4, %eax
	xorl	$1, %eax
	cmpl	$0, -60(%ebp)
	setne	%dl
	testl	%edx, %eax
	je	L1651
L1740:
	movl	-64(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	call	_fgets
	cmpb	$125, (%edi)
	je	L1651
	incl	-80(%ebp)
	movl	-80(%ebp), %ebx
	movl	-80(%ebp), %eax
	sall	$3, %ebx
	subl	%eax, %ebx
	sall	$3, %ebx
	movl	%ebx, 4(%esp)
	movl	-76(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_realloc
	cmpl	$2, -80(%ebp)
	leal	-56(%ebx,%eax), %ebx
	movl	%eax, -76(%ebp)
	movl	$0, 4(%ebx)
	movl	$0, 8(%ebx)
	movl	$0, 12(%ebx)
	movl	$0, 28(%ebx)
	movl	$0, 24(%ebx)
	movl	$0, 36(%ebx)
	movl	$0, 32(%ebx)
	movl	$0, 44(%ebx)
	movl	$0, 40(%ebx)
	movl	$0, 48(%ebx)
	movl	$0, 52(%ebx)
	je	L1654
	cmpl	$3, -80(%ebp)
	je	L1662
	movl	-32(%ebp), %eax
	movl	$LC233, %ebx
	movl	%eax, 32(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	call	_sscanf
	cmpl	$7, %eax
	movl	%eax, %ebx
	jne	L1674
	xorl	%esi, %esi
	.p2align 4,,15
L1678:
	movl	-56(%ebp,%esi,4), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_DeleteLastChar
	cmpl	%esi, %ebx
	jg	L1678
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1739
L1680:
	movl	$1, -72(%ebp)
L1679:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	cmpl	$1, %eax
	movl	-40(%ebp), %eax
	adcl	$0, -68(%ebp)
	movl	%eax, (%esp)
	call	_test
	cmpl	$1, %eax
	movl	-32(%ebp), %eax
	adcl	$0, -68(%ebp)
	movl	%eax, (%esp)
	call	_test
	cmpl	$1, %eax
	movl	-80(%ebp), %eax
	movl	-80(%ebp), %ecx
	adcl	$0, -68(%ebp)
	movl	-76(%ebp), %edx
	sall	$3, %eax
	subl	%ecx, %eax
	leal	(%edx,%eax,8), %eax
	leal	-56(%eax), %ebx
	movl	$11, -56(%eax)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 16(%ebx)
	movl	-52(%ebp), %eax
	movl	$0, 20(%ebx)
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%ebx)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 24(%ebx)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 36(%ebx)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 32(%ebx)
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 44(%ebx)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 40(%ebx)
L1734:
	movl	$LC221, (%esp)
	call	_g_strdup
	movl	%eax, 48(%ebx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 52(%ebx)
	movl	-64(%ebp), %edx
	movl	12(%edx), %eax
	xorl	%edx, %edx
	shrl	$4, %eax
	xorl	$1, %eax
	cmpl	$0, -60(%ebp)
	setne	%dl
	testl	%edx, %eax
	jne	L1740
	.p2align 4,,15
L1651:
	movl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
L1686:
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	setne	%al
	xorl	%edx, %edx
	cmpl	$0, -72(%ebp)
	setne	%dl
	testl	%eax, %edx
	jne	L1741
L1687:
	movl	%edi, (%esp)
	xorl	%ebx, %ebx
	call	_g_free
	.p2align 4,,15
L1703:
	movl	-56(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$6, %ebx
	jbe	L1703
	movl	-60(%ebp), %ecx
	movl	-80(%ebp), %edx
	testl	%ecx, %ecx
	sete	%al
	testl	%edx, %edx
	setle	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L1705
	movl	-68(%ebp), %edx
	cmpl	%edx, -84(%ebp)
	jge	L1704
L1705:
	movl	-84(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-80(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-76(%ebp), %edx
	movl	%edx, (%esp)
	call	_FreeGeom
	movl	$LC239, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	call	_MessageGeom
	addl	$140, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1674:
	decl	-80(%ebp)
	movl	-80(%ebp), %eax
	movl	-80(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	movl	-76(%ebp), %eax
	movl	%eax, (%esp)
L1733:
	call	_g_realloc
	movl	%eax, -76(%ebp)
L1735:
	movl	$0, -60(%ebp)
	jmp	L1647
L1741:
	movl	$0, -84(%ebp)
	movl	$LC223, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	_FOpen
	movl	%eax, -64(%ebp)
	testl	%eax, %eax
	je	L1687
	movl	$LC237, (%esp)
	call	_g_strdup
	movl	%eax, (%esp)
	movl	%eax, %esi
	call	_g_strup
	movl	-64(%ebp), %eax
	testb	$16, 12(%eax)
	jne	L1690
L1742:
	movl	-64(%ebp), %edx
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	movl	%edx, 8(%esp)
	call	_fgets
	movl	%edi, (%esp)
	call	_g_strdup
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_g_strup
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	_strstr
	testl	%eax, %eax
	jne	L1690
	movl	%ebx, (%esp)
	call	_g_free
	movl	-64(%ebp), %eax
	testb	$16, 12(%eax)
	je	L1742
L1690:
	movl	%esi, (%esp)
	call	_g_free
	movl	-64(%ebp), %edx
	testb	$16, 12(%edx)
	jne	L1694
	movl	$0, -92(%ebp)
	movl	$0, -96(%ebp)
	jmp	L1699
L1696:
	movl	-96(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_realloc
L1731:
	movl	%eax, -88(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_DeleteLastChar
	movl	-88(%ebp), %esi
	movl	-92(%ebp), %ebx
	movl	-56(%ebp), %eax
	addl	%esi, %ebx
	leal	-12(%ebx), %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -12(%ebx)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	$1, 8(%esi)
	movl	-64(%ebp), %edx
	movl	%eax, 4(%esi)
	testb	$16, 12(%edx)
	jne	L1694
L1699:
	movl	-64(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	call	_fgets
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$LC238, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	cmpl	$3, %eax
	jne	L1694
	incl	-84(%ebp)
	addl	$12, -96(%ebp)
	addl	$12, -92(%ebp)
	cmpl	$1, -84(%ebp)
	jne	L1696
	movl	$12, (%esp)
	call	_g_malloc
	jmp	L1731
L1704:
	movl	_Geom, %eax
	testl	%eax, %eax
	jne	L1743
L1706:
	movl	_Variables, %eax
	testl	%eax, %eax
	jne	L1744
L1707:
	movl	-76(%ebp), %eax
	movl	$14, %edi
	movl	-80(%ebp), %edx
	movl	%edi, _MethodeGeom
	movl	%eax, _Geom
	movl	-84(%ebp), %eax
	movl	%edx, _NcentersZmat
	movl	-88(%ebp), %edx
	movl	%eax, _NVariables
	movl	20(%ebp), %eax
	movl	%edx, _Variables
	cmpl	$1, %eax
	je	L1745
	testl	%eax, %eax
	jne	L1709
	cmpl	$1, _Units
	je	L1746
L1709:
	movl	_GeomIsOpen, %ebx
	testl	%ebx, %ebx
	jne	L1747
L1711:
	movl	_ZoneDessin, %ecx
	testl	%ecx, %ecx
	jne	L1748
L1712:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_set_last_directory
	addl	$140, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1654:
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$LC231, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	cmpl	$3, %eax
	movl	%eax, %ebx
	jne	L1655
	xorl	%esi, %esi
	.p2align 4,,15
L1659:
	movl	-56(%ebp,%esi,4), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_DeleteLastChar
	cmpl	%esi, %ebx
	jg	L1659
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1660
	incl	-68(%ebp)
	movl	$1, -72(%ebp)
L1660:
	movl	-76(%ebp), %eax
	movl	-76(%ebp), %ebx
	movl	$7, 56(%eax)
	movl	-56(%ebp), %eax
	addl	$56, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 16(%ebx)
	movl	-52(%ebp), %eax
	movl	$0, 20(%ebx)
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%ebx)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 24(%ebx)
	jmp	L1734
L1662:
	movl	-40(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$LC232, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	cmpl	$5, %eax
	movl	%eax, %ebx
	jne	L1663
	xorl	%esi, %esi
	.p2align 4,,15
L1667:
	movl	-56(%ebp,%esi,4), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_DeleteLastChar
	cmpl	%esi, %ebx
	jg	L1667
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1749
L1669:
	movl	$1, -72(%ebp)
L1668:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	cmpl	$1, %eax
	movl	-40(%ebp), %eax
	adcl	$0, -68(%ebp)
	movl	%eax, (%esp)
	call	_test
	cmpl	$1, %eax
	movl	-76(%ebp), %eax
	movl	-76(%ebp), %ebx
	adcl	$0, -68(%ebp)
	movl	$9, 112(%eax)
	movl	-56(%ebp), %eax
	addl	$112, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 16(%ebx)
	movl	-52(%ebp), %eax
	movl	$0, 20(%ebx)
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%ebx)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 24(%ebx)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 36(%ebx)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 32(%ebx)
	jmp	L1734
L1739:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1680
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1679
	jmp	L1680
L1694:
	movl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	jmp	L1687
L1641:
	movl	$0, -60(%ebp)
	jmp	L1686
L1655:
	movl	$1, -80(%ebp)
	movl	$56, %eax
	movl	%eax, 4(%esp)
L1736:
	movl	-76(%ebp), %edx
	movl	%edx, (%esp)
	jmp	L1733
L1663:
	movl	$2, -80(%ebp)
	movl	$112, %esi
	movl	%esi, 4(%esp)
	jmp	L1736
L1738:
	movl	$1, -80(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_DeleteLastChar
	movl	$56, (%esp)
	call	_g_malloc
	movl	%eax, -76(%ebp)
	movl	$5, (%eax)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-76(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-76(%ebp), %edx
	movl	%eax, 8(%edx)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-76(%ebp), %edx
	movl	%eax, 12(%edx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	-76(%ebp), %edx
	movl	%eax, 16(%edx)
	movl	$0, 20(%edx)
	movl	$LC221, (%esp)
	call	_g_strdup
	movl	-76(%ebp), %edx
	movl	%eax, 48(%edx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	-76(%ebp), %edx
	movl	%eax, 52(%edx)
	jmp	L1647
L1748:
	call	_rafresh_drawing
	jmp	L1712
L1747:
	movl	$43, (%esp)
	call	_create_geom_interface
	jmp	L1711
L1744:
	call	_freeVariables
	jmp	L1707
L1743:
	call	_freeGeom
	jmp	L1706
L1745:
	movl	_Units, %esi
	testl	%esi, %esi
	jne	L1709
	movl	$0, (%esp)
	call	_Geom_Change_Unit
	jmp	L1709
L1749:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1668
	jmp	L1669
L1746:
	movl	$1, (%esp)
	call	_Geom_Change_Unit
	jmp	L1709
