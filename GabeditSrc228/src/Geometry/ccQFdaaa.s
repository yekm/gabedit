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
	movl	$80, %eax
	movl	%esp, %ebp
	pushl	%esi
	movl	$LC47, %esi
	pushl	%ebx
	subl	$32, %esp
	movl	%eax, 4(%esp)
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
	movl	%eax, %ebx
	js	L417
	leal	-5(%esi), %eax
	cmpl	$1, %eax
	jbe	L426
L419:
	cmpl	$7, %esi
	je	L423
	cmpl	$8, %esi
	sete	%al
	xorl	%edx, %edx
	cmpl	$1, %ebx
	setg	%dl
	testl	%eax, %edx
	je	L422
L423:
	movl	_Geom, %ecx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	sall	$3, %eax
	movl	36(%eax,%ecx), %edx
	movl	%edx, 12(%esp)
	movl	28(%eax,%ecx), %eax
	movl	$LC86, (%esp)
	movl	%eax, 8(%esp)
	leal	1(%ebx), %eax
	movl	%eax, 4(%esp)
	call	_printf
L422:
	cmpl	$9, %esi
	je	L425
	cmpl	$10, %esi
	sete	%al
	xorl	%edx, %edx
	cmpl	$2, %ebx
	setg	%dl
	testl	%eax, %edx
	je	L417
L425:
	movl	_Geom, %ecx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	sall	$3, %eax
	movl	44(%eax,%ecx), %edx
	movl	%edx, 16(%esp)
	movl	36(%eax,%ecx), %edx
	movl	%edx, 12(%esp)
	movl	28(%eax,%ecx), %eax
	movl	$LC86, (%esp)
	movl	%eax, 8(%esp)
	leal	1(%ebx), %eax
	movl	%eax, 4(%esp)
	call	_printf
L417:
	addl	$32, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L426:
	cmpl	$5, %esi
	je	L421
	cmpl	$6, %esi
	sete	%al
	xorl	%edx, %edx
	testl	%ebx, %ebx
	setg	%dl
	testl	%eax, %edx
	je	L419
L421:
	movl	_Geom, %edx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	movl	28(%edx,%eax,8), %eax
	movl	$LC86, (%esp)
	movl	%eax, 8(%esp)
	leal	1(%ebx), %eax
	movl	%eax, 4(%esp)
	call	_printf
	jmp	L419
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
	je	L427
	movl	16(%ebp), %ecx
	testl	%ecx, %ecx
	je	L427
	cmpl	$1, %eax
	je	L612
	cmpl	$2, %eax
	je	L613
	cmpl	$3, %eax
	je	L614
	cmpl	$4, %eax
	je	L615
	cmpl	$5, %eax
	sete	%al
	cmpl	$7, %edi
	sete	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L461
	cmpl	$9, %edi
	je	L461
	cmpl	$6, %edi
	sete	%al
	cmpl	$8, %edi
	sete	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L477
	cmpl	$10, %edi
	je	L477
	cmpl	$11, %edi
	je	L616
	cmpl	$12, %edi
	jne	L427
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_strlen
	testl	%eax, %eax
	movl	%eax, %esi
	jle	L427
	movl	16(%ebp), %ecx
	movl	$1, %ebx
	movsbl	(%ecx),%eax
	movl	%eax, (%esp)
	call	_toupper
	movl	16(%ebp), %edx
	movb	%al, (%edx)
	jmp	L601
L617:
	movl	16(%ebp), %ecx
	movsbl	(%ebx,%ecx),%eax
	movl	%eax, (%esp)
	call	_tolower
	movl	16(%ebp), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
L601:
	cmpl	%esi, %ebx
	jl	L617
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
	je	L574
	movl	16(%ebp), %esi
	movl	$LC100, %edi
	movl	$7, %ecx
	repe
	cmpsb
	je	L574
	movl	16(%ebp), %esi
	movl	$LC101, %edi
	movl	$4, %ecx
	repe
	cmpsb
	je	L574
	movl	16(%ebp), %esi
	movl	$LC46, %edi
	movl	$2, %ecx
	repe
	cmpsb
	jne	L618
L574:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	52(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L619
L575:
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
	jmp	L606
	.p2align 4,,7
L614:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L427
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
	jne	L623
L442:
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
L664:
	movl	%edx, 12(%esp)
	movl	%ecx, 8(%esp)
L606:
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_list_store_set
	movl	%esi, (%esp)
	call	_gtk_tree_path_free
L607:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L427
	call	_rafresh_drawing
	.p2align 4,,15
L427:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L461:
	movl	16(%ebp), %esi
	movl	%esi, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L427
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	%esi, %eax
	call	_testav
	incl	%eax
	jge	L463
	movl	%esi, 4(%esp)
	movl	$LC88, (%esp)
L608:
	call	_g_strdup_printf
L605:
	movl	%eax, %ebx
	movl	$LC48, %edi
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%ebx, (%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	jmp	L427
	.p2align 4,,7
L612:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	testl	%eax, %eax
	movl	%eax, %ebx
	jle	L427
	movl	16(%ebp), %edx
	movsbl	(%edx),%eax
	movl	%eax, (%esp)
	call	_toupper
	movl	16(%ebp), %ecx
	decl	%ebx
	movb	%al, (%ecx)
	jg	L620
L432:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_test_atom_define
	testl	%eax, %eax
	jne	L669
	movl	$LC87, (%esp)
L667:
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	jmp	L608
L613:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L427
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
	jne	L624
L438:
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
	jmp	L664
L669:
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
	jne	L622
L434:
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
	jmp	L664
L624:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L438
L615:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L427
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
	je	L446
	movl	16(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L625
L447:
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
	jle	L449
	movl	%edx, -116(%ebp)
	movl	$0, -120(%ebp)
L452:
	cmpl	%esi, -48(%ebp)
	je	L450
	movl	-120(%ebp), %ecx
	movl	-116(%ebp), %edx
	movl	16(%ecx,%ebx), %eax
	movl	%eax, 4(%esp)
	movl	16(%edx,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L582
L450:
	addl	$56, -120(%ebp)
	incl	%esi
	cmpl	%esi, %edi
	jg	L452
L449:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	sall	$3, %eax
	subl	%esi, %eax
	sall	$3, %eax
	cmpl	$-1, 20(%eax,%ebx)
	je	L626
L446:
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
	jmp	L606
L477:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_strlen
	movl	$-1, -56(%ebp)
	testl	%eax, %eax
	movl	$-1, -60(%ebp)
	movl	$-1, -64(%ebp)
	jle	L427
	movl	12(%ebp), %esi
	movl	%esi, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_isInteger
	testl	%eax, %eax
	jne	L479
	movl	$LC93, (%esp)
	jmp	L667
L620:
	movsbl	1(%ecx),%eax
	movl	%eax, (%esp)
	call	_tolower
	movl	16(%ebp), %esi
	movb	%al, 1(%esi)
	jmp	L432
L463:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L627
L464:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L465
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_atof
	fldz
	fucompp
	fnstsw	%ax
	sahf
	jbe	L465
	cmpl	$5, %edi
	je	L628
L465:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L629
L467:
	cmpl	$5, %edi
	je	L630
L469:
	cmpl	$7, %edi
	je	L631
	cmpl	$9, %edi
	je	L632
L473:
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
	jmp	L606
L623:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L442
L622:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L434
L479:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_atoi
	testl	%eax, %eax
	movl	%eax, %ebx
	jle	L481
	movl	-48(%ebp), %eax
	incl	%eax
	cmpl	%ebx, %eax
	jg	L480
L481:
	movl	$LC94, (%esp)
	movl	-48(%ebp), %esi
	movl	16(%ebp), %eax
	movl	%esi, 8(%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	jmp	L605
L627:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L464
	movl	$LC51, (%esp)
	movl	16(%ebp), %esi
	movl	%esi, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 16(%ebp)
	jmp	L464
L629:
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
	jbe	L467
	cmpl	$5, %edi
	jne	L469
	movl	$LC92, (%esp)
	call	_g_strdup_printf
	jmp	L605
	.p2align 4,,7
L630:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%ecx, %eax
	leal	0(,%eax,8), %esi
	movl	24(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L633
L470:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 24(%esi,%ebx)
	jmp	L473
L631:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	32(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L634
L472:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	%eax, 32(%esi,%ebx)
	jmp	L473
L625:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L447
L626:
	movl	_NcentersZmat, %edi
	xorl	%esi, %esi
	cmpl	$0, %edi
	jle	L579
	movl	%edi, -112(%ebp)
	leal	20(%ebx), %ecx
L458:
	movl	(%ecx), %edx
	cmpl	%edx, 20(%eax,%ebx)
	jge	L456
	movl	%edx, 20(%eax,%ebx)
	movl	-112(%ebp), %edi
L456:
	incl	%esi
	addl	$56, %ecx
	cmpl	%esi, %edi
	jg	L458
L579:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	sall	$3, %eax
	subl	%ecx, %eax
	incl	20(%ebx,%eax,8)
	jmp	L446
L616:
	movl	16(%ebp), %esi
	movl	%esi, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L427
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	%esi, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L562
	movl	%esi, 4(%esp)
	movl	$LC50, (%esp)
	jmp	L608
L480:
	cmpl	$6, %edi
	je	L635
	cmpl	$8, %edi
	je	L636
L483:
	cmpl	$10, %edi
	je	L637
L484:
	cmpl	$6, %edi
	je	L638
L486:
	cmpl	$8, %edi
	je	L639
	cmpl	$10, %edi
	je	L640
	cmpl	$6, %edi
	je	L583
	cmpl	$8, %edi
	je	L584
	cmpl	$10, %edi
	je	L585
L541:
	leal	(%edi,%edi), %eax
	movl	16(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%ecx, (%esp)
	call	_set_text_column
	jmp	L607
L632:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	40(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L641
L474:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 40(%esi,%ebx)
	jmp	L473
L582:
	movl	-120(%ebp), %ecx
	movl	-116(%ebp), %esi
	movl	20(%ecx,%ebx), %eax
	movl	%eax, 20(%esi,%ebx)
	jmp	L449
L633:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L470
L634:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L472
L562:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	je	L563
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	je	L642
L563:
	movl	$LC98, (%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
L600:
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
	jne	L643
L565:
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
	jne	L644
L566:
	testl	%edi, %edi
	je	L427
	movl	%edi, (%esp)
	call	_g_free
	jmp	L427
L638:
	cmpl	$1, -48(%ebp)
	movl	%ebx, -56(%ebp)
	jg	L645
L488:
	cmpl	$2, -48(%ebp)
	jle	L583
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	44(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-56(%ebp), %eax
	jne	L583
L487:
	cmpl	$1, -48(%ebp)
	movl	$0, -68(%ebp)
	jg	L646
L489:
	cmpl	$2, -48(%ebp)
	jg	L647
L490:
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
L583:
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
	jle	L504
	movl	-60(%ebp), %eax
	movl	-48(%ebp), %esi
	decl	%eax
	movl	%esi, (%esp)
L594:
	movl	-104(%ebp), %edx
	call	_get_angle_zmatrix
	movl	%eax, -84(%ebp)
L505:
	movl	-64(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L507
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
L595:
	call	_get_dihedral_zmatrix
	movl	%eax, %ebx
L508:
	movl	-80(%ebp), %eax
	testl	%eax, %eax
	je	L510
	movl	-80(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_r_value
	testl	%eax, %eax
	jne	L648
L510:
	movl	-84(%ebp), %eax
	testl	%eax, %eax
	je	L512
	movl	-84(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_angle_value
	testl	%eax, %eax
	jne	L649
L512:
	testl	%ebx, %ebx
	je	L514
	movl	-48(%ebp), %eax
	movl	%ebx, %edx
	call	_reset_dihedral_value
	testl	%eax, %eax
	jne	L650
L514:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	28(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L651
L516:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 28(%esi,%ebx)
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jle	L517
	movl	_Geom, %ebx
	movl	36(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L518
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L518:
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
L517:
	movl	-64(%ebp), %eax
	testl	%eax, %eax
	jle	L541
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	44(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L520
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L520:
	movl	-64(%ebp), %eax
	movl	%eax, 4(%esp)
L604:
	movl	$LC45, (%esp)
	call	_g_strdup_printf
	movl	%eax, 44(%esi,%ebx)
	movl	_Geom, %eax
	movl	$20, %ebx
	movl	%ebx, 4(%esp)
	movl	44(%esi,%eax), %eax
L599:
	movl	%eax, (%esp)
	movl	12(%ebp), %edx
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L541
L641:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L474
L628:
	movl	$LC90, (%esp)
	call	_g_strdup_printf
	jmp	L605
L639:
	movl	%ebx, -60(%ebp)
	movl	-48(%ebp), %esi
	testl	%esi, %esi
	jle	L494
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%ecx, %eax
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-60(%ebp), %eax
	je	L493
L494:
	cmpl	$2, -48(%ebp)
	jle	L584
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	44(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-60(%ebp), %eax
	jne	L584
L493:
	movl	$0, -72(%ebp)
	movl	-48(%ebp), %esi
	testl	%esi, %esi
	jle	L495
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
	je	L652
L495:
	cmpl	$2, -48(%ebp)
	jg	L653
L496:
	movl	-72(%ebp), %esi
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_MessageGeom
	movl	%esi, (%esp)
	call	_g_free
L584:
	movl	$0, -88(%ebp)
	movl	-56(%ebp), %ecx
	xorl	%esi, %esi
	testl	%ecx, %ecx
	jle	L523
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
L596:
	call	_get_angle_zmatrix
	movl	%eax, -92(%ebp)
	movl	-64(%ebp), %eax
	testl	%eax, %eax
	jle	L525
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
L598:
	call	_get_dihedral_zmatrix
	movl	%eax, %esi
L526:
	movl	-88(%ebp), %eax
	testl	%eax, %eax
	je	L530
	movl	-88(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_r_value
	testl	%eax, %eax
	je	L530
	movl	$10, %eax
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
L530:
	movl	-92(%ebp), %eax
	testl	%eax, %eax
	je	L532
	movl	-92(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_angle_value
	testl	%eax, %eax
	je	L532
	movl	-92(%ebp), %edx
	movl	$14, %ebx
	movl	-44(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	12(%ebp), %edx
	call	_set_text_column
L532:
	testl	%esi, %esi
	je	L534
	movl	-48(%ebp), %eax
	movl	%esi, %edx
	call	_reset_dihedral_value
	testl	%eax, %eax
	je	L534
	movl	%esi, (%esp)
	movl	12(%ebp), %edx
	movl	$18, %ecx
	movl	%ecx, 4(%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
L534:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	36(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L536
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L536:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	%eax, 36(%esi,%ebx)
	movl	-56(%ebp), %eax
	testl	%eax, %eax
	jle	L537
	movl	_Geom, %ebx
	movl	28(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L654
L538:
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
L537:
	movl	-64(%ebp), %eax
	testl	%eax, %eax
	jle	L541
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	44(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L655
L540:
	movl	-64(%ebp), %edx
	movl	%edx, 4(%esp)
	jmp	L604
L640:
	cmpl	$1, -48(%ebp)
	movl	%ebx, -64(%ebp)
	jg	L656
L500:
	movl	-48(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L585
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-64(%ebp), %eax
	jne	L585
L499:
	cmpl	$1, -48(%ebp)
	movl	$0, -76(%ebp)
	jg	L657
L501:
	movl	-48(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L502
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
	je	L658
L502:
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
L585:
	movl	$0, -96(%ebp)
	movl	-56(%ebp), %ecx
	xorl	%esi, %esi
	movl	$0, -100(%ebp)
	testl	%ecx, %ecx
	jle	L543
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
L543:
	movl	-60(%ebp), %ecx
	movl	-56(%ebp), %ebx
	testl	%ecx, %ecx
	setg	%al
	shrl	$31, %ebx
	testl	%eax, %ebx
	je	L544
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
L544:
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jle	L545
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
L545:
	movl	-56(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L546
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
L546:
	movl	-60(%ebp), %eax
	shrl	$31, %eax
	testl	%eax, %ebx
	je	L547
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
L547:
	movl	-96(%ebp), %eax
	testl	%eax, %eax
	je	L548
	movl	-96(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_r_value
	testl	%eax, %eax
	jne	L659
L548:
	movl	-100(%ebp), %eax
	testl	%eax, %eax
	je	L550
	movl	-100(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_angle_value
	testl	%eax, %eax
	jne	L660
L550:
	testl	%esi, %esi
	je	L552
	movl	-48(%ebp), %eax
	movl	%esi, %edx
	call	_reset_dihedral_value
	testl	%eax, %eax
	jne	L661
L552:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	44(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L554
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L554:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	%eax, 44(%esi,%ebx)
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jle	L555
	movl	_Geom, %ebx
	movl	36(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L662
L556:
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
L555:
	movl	-56(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L541
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	28(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L663
L558:
	movl	$LC45, (%esp)
	movl	-56(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 28(%esi,%ebx)
	movl	$12, %eax
	movl	%eax, 4(%esp)
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	jmp	L599
L619:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L575
L635:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L483
	jmp	L427
L636:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L484
	jmp	L427
L637:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%ecx, %eax
	movl	44(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L486
	jmp	L427
L507:
	cmpl	$2, -48(%ebp)
	jle	L508
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
	jmp	L595
L504:
	cmpl	$1, -48(%ebp)
	jle	L505
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
	jmp	L594
L651:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L516
L525:
	cmpl	$2, -48(%ebp)
	jle	L526
	movl	-56(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L528
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
	jmp	L598
L644:
	call	_rafresh_drawing
	jmp	L566
L643:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L565
L654:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L538
L645:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-56(%ebp), %eax
	jne	L488
	jmp	L487
L523:
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
	jmp	L596
L655:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L540
L649:
	movl	-84(%ebp), %eax
	movl	$14, %esi
	movl	12(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L512
L650:
	movl	%ebx, (%esp)
	movl	12(%ebp), %edx
	movl	$18, %ecx
	movl	%ecx, 4(%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L514
L648:
	movl	$10, %eax
	movl	-80(%ebp), %esi
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%esi, (%esp)
	call	_set_text_column
	jmp	L510
L642:
	movl	$LC51, (%esp)
	movl	16(%ebp), %esi
	movl	%esi, 4(%esp)
	jmp	L600
L618:
	movl	$LC102, (%esp)
	call	_g_strdup_printf
	jmp	L605
L663:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L558
L656:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-64(%ebp), %eax
	jne	L500
	jmp	L499
	.p2align 4,,7
L659:
	movl	$10, %eax
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L548
L660:
	movl	-100(%ebp), %edx
	movl	$14, %ebx
	movl	-44(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	12(%ebp), %edx
	call	_set_text_column
	jmp	L550
L661:
	movl	%esi, (%esp)
	movl	12(%ebp), %edx
	movl	$18, %ecx
	movl	%ecx, 4(%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L552
L662:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L556
L652:
	movl	_Geom, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -56(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC97, (%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp)
	jmp	L495
L653:
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
	jne	L496
	movl	_Geom, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -64(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC96, (%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp)
	jmp	L496
L528:
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
	jmp	L598
L658:
	movl	_Geom, %eax
	movl	44(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -56(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC97, (%esp)
	call	_g_strdup_printf
	movl	%eax, -76(%ebp)
	jmp	L502
L646:
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
	jne	L489
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -60(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC95, (%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	jmp	L489
L657:
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
	jne	L501
	movl	_Geom, %eax
	movl	44(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -60(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC95, (%esp)
	call	_g_strdup_printf
	movl	%eax, -76(%ebp)
	jmp	L501
L647:
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
	jne	L490
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -64(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC96, (%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	jmp	L490
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
	je	L672
	movl	(%ebx), %edx
	testl	%edx, %edx
	jne	L675
L672:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L670
L674:
	movl	%ebx, (%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gtk_widget_set_sensitive
L670:
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L675:
	cmpl	%eax, (%edx)
	jne	L672
	jmp	L674
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
	je	L678
L677:
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
L678:
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
	jmp	L677
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
	je	L681
L680:
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
L681:
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
	jmp	L680
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
	jge	L689
	.p2align 4,,15
L692:
	movl	(%edi,%ebx,4), %eax
	testl	%eax, %eax
	jne	L691
	incl	%ebx
L693:
	cmpl	%esi, %ebx
	jl	L692
L689:
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
L691:
	movl	%eax, (%esp)
	incl	%ebx
	call	_g_free
	jmp	L693
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
	je	L714
	xorl	%esi, %esi
	cmpl	%edx, %esi
	jge	L723
	movl	$0, -28(%ebp)
	leal	48(%edi), %ebx
	jmp	L713
	.p2align 4,,7
L699:
	movl	-40(%ebx), %eax
	testl	%eax, %eax
	jne	L726
L700:
	movl	-36(%ebx), %eax
	testl	%eax, %eax
	jne	L727
L701:
	testl	%esi, %esi
	je	L702
	movl	-24(%ebx), %eax
	testl	%eax, %eax
	jne	L728
L703:
	movl	-20(%ebx), %eax
	testl	%eax, %eax
	jne	L729
L702:
	cmpl	$1, %esi
	jbe	L705
	movl	-16(%ebx), %eax
	testl	%eax, %eax
	jne	L730
L706:
	movl	-28(%ebp), %edx
	movl	36(%edx,%edi), %eax
	testl	%eax, %eax
	jne	L731
L705:
	cmpl	$2, %esi
	jbe	L708
	movl	-8(%ebx), %eax
	testl	%eax, %eax
	jne	L732
L709:
	movl	-28(%ebp), %edx
	movl	44(%edx,%edi), %eax
	testl	%eax, %eax
	jne	L733
L708:
	movl	(%ebx), %eax
	testl	%eax, %eax
	jne	L734
L711:
	movl	-28(%ebp), %edx
	movl	52(%edx,%edi), %eax
	testl	%eax, %eax
	jne	L735
	addl	$56, -28(%ebp)
	incl	%esi
	addl	$56, %ebx
	cmpl	-20(%ebp), %esi
	jge	L723
L713:
	movl	-44(%ebx), %eax
	testl	%eax, %eax
	je	L699
	movl	%eax, (%esp)
	call	_g_free
	movl	-40(%ebx), %eax
	testl	%eax, %eax
	je	L700
	.p2align 4,,15
L726:
	movl	%eax, (%esp)
	call	_g_free
	movl	-36(%ebx), %eax
	testl	%eax, %eax
	je	L701
	.p2align 4,,15
L727:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L701
	.p2align 4,,7
L735:
	movl	%eax, (%esp)
	incl	%esi
	call	_g_free
	addl	$56, -28(%ebp)
	addl	$56, %ebx
	cmpl	-20(%ebp), %esi
	jl	L713
	.p2align 4,,15
L723:
	testl	%edi, %edi
	je	L714
	movl	%edi, (%esp)
	call	_g_free
L714:
	movl	-16(%ebp), %eax
	testl	%eax, %eax
	je	L694
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	jg	L736
L725:
	movl	-16(%ebp), %eax
	movl	%eax, 8(%ebp)
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_g_free
	.p2align 4,,7
L734:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L711
	.p2align 4,,7
L729:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L702
	.p2align 4,,7
L728:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L703
	.p2align 4,,7
L733:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L708
	.p2align 4,,7
L732:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L709
	.p2align 4,,7
L731:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L705
	.p2align 4,,7
L730:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L706
L736:
	movl	-24(%ebp), %esi
	xorl	%ebx, %ebx
	jmp	L721
	.p2align 4,,7
L719:
	movl	-16(%ebp), %edx
	movl	4(%ebx,%edx), %eax
	testl	%eax, %eax
	jne	L737
L718:
	addl	$12, %ebx
	decl	%esi
	je	L725
L721:
	movl	-16(%ebp), %edx
	movl	(%ebx,%edx), %eax
	testl	%eax, %eax
	je	L719
	movl	%eax, (%esp)
	call	_g_free
	movl	-16(%ebp), %edx
	movl	4(%ebx,%edx), %eax
	testl	%eax, %eax
	je	L718
	.p2align 4,,15
L737:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L718
L694:
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
	je	L738
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	cmpl	_NcentersZmat, %esi
	jb	L746
	movl	%eax, (%esp)
	call	_g_free
	xorl	%eax, %eax
	movl	%eax, _Geom
	xorl	%eax, %eax
	movl	%eax, _NcentersZmat
	.p2align 4,,15
L738:
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L754:
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$1, %esi
	ja	L751
	.p2align 4,,15
L744:
	cmpl	$2, %esi
	ja	L752
L745:
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
	jae	L753
	movl	_Geom, %eax
L746:
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
	jne	L754
	cmpl	$1, %esi
	jbe	L744
L751:
	movl	_Geom, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$2, %esi
	jbe	L745
	.p2align 4,,15
L752:
	movl	_Geom, %eax
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	jmp	L745
L753:
	movl	_Geom, %eax
	movl	%eax, (%esp)
	call	_g_free
	xorl	%eax, %eax
	movl	%eax, _Geom
	xorl	%eax, %eax
	movl	%eax, _NcentersZmat
	jmp	L738
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
	je	L755
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	cmpl	_NVariables, %esi
	jb	L760
	movl	%eax, (%esp)
	xorl	%ebx, %ebx
	call	_g_free
	movl	%ebx, _Variables
	xorl	%ecx, %ecx
	movl	%ecx, _NVariables
	.p2align 4,,15
L755:
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L763:
	movl	_Variables, %eax
L760:
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
	jb	L763
	movl	_Variables, %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_free
	movl	%ebx, _Variables
	xorl	%ecx, %ecx
	movl	%ecx, _NVariables
	jmp	L755
	.p2align 4,,15
	.def	_destroy_dialogue;	.scl	3;	.type	32;	.endef
_destroy_dialogue:
	pushl	%ebp
	movl	_DestroyDialog, %eax
	movl	%esp, %ebp
	testl	%eax, %eax
	jne	L766
	popl	%ebp
	ret
	.p2align 4,,7
L766:
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
	je	L812
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
	ja	L813
L769:
	cmpl	$2, -36(%ebp)
	jbe	L773
	cmpl	$1, _Units
	je	L775
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L774
L775:
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
L773:
	movl	$3, -20(%ebp)
	movl	-36(%ebp), %edx
	cmpl	%edx, -20(%ebp)
	jae	L799
	movl	$168, %ebx
	jmp	L783
	.p2align 4,,7
L781:
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
	jae	L799
L783:
	cmpl	$1, _Units
	je	L781
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L781
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
	jb	L783
L799:
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
	jae	L801
	movl	$0, -40(%ebp)
	.p2align 4,,15
L796:
	cmpl	$1, _Units
	je	L814
L787:
	movl	_NcentersZmat, %edx
	movl	$1, %edi
	cmpl	%edx, %edi
	movl	%edx, -36(%ebp)
	jae	L803
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
	je	L804
	.p2align 4,,15
L815:
	incl	%edi
	addl	$56, %ebx
	cmpl	-36(%ebp), %edi
	jae	L794
	movl	-40(%ebp), %edx
	movl	(%edx,%esi), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %ecx
	movl	24(%ebx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L815
L804:
	movl	-40(%ebp), %edx
	movl	4(%edx,%esi), %eax
	movl	%eax, (%esp)
	call	_bohr_to_ang
	movl	%eax, 12(%esp)
	movl	-40(%ebp), %ecx
	movl	_Variables, %eax
L809:
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
	jb	L796
L801:
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
	jne	L816
L797:
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
L813:
	cmpl	$1, _Units
	je	L771
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L770
L771:
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
	jmp	L769
L803:
	movl	_Variables, %esi
L794:
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
	jae	L801
	cmpl	$1, _Units
	jne	L787
L814:
	movl	-40(%ebp), %ecx
	movl	_Variables, %eax
	movl	4(%ecx,%eax), %edx
	movl	%edx, 12(%esp)
	jmp	L809
L812:
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
L816:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L797
L770:
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
	jmp	L769
L774:
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
	jmp	L773
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
	je	L821
	leave
	ret
	.p2align 4,,7
L821:
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	testl	%eax, %eax
	je	L820
	cmpb	$0, (%eax)
	jne	L819
L820:
	movl	$LC121, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	call	_Message
	leave
	ret
L819:
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
	je	L822
	cmpb	$0, (%eax)
	jne	L825
L822:
	leave
	ret
	.p2align 4,,7
L825:
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
	je	L884
	.p2align 4,,15
L831:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$9, %ebx
	jbe	L831
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
	jae	L868
	leal	-72(%ebp), %esi
	xorl	%edi, %edi
L863:
	xorl	%ebx, %ebx
	.p2align 4,,15
L838:
	movl	-72(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$9, %ebx
	jbe	L838
	cmpl	$2, -76(%ebp)
	jg	L853
	cmpl	$1, -76(%ebp)
	je	L843
	jle	L885
	cmpl	$2, -76(%ebp)
	je	L847
	cmpl	$3, -76(%ebp)
	je	L853
L862:
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
	jb	L863
L868:
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
	jne	L886
L864:
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
L881:
	call	_g_free
	addl	$156, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L886:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L864
	.p2align 4,,7
L853:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L854
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L877:
	fstpl	-96(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L856
	fldl	-96(%ebp)
	fmull	LC127
	fstpl	-96(%ebp)
L856:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L857
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L878:
	fstpl	-104(%ebp)
	movl	_Geom, %eax
	movl	40(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L859
	movl	_Geom, %eax
	movl	40(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L879:
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
L880:
	call	_g_strdup
	movl	%eax, 36(%esi)
	jmp	L862
L854:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L877
L859:
	movl	_Geom, %eax
	movl	40(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L879
L857:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L878
L885:
	movl	-76(%ebp), %ebx
	testl	%ebx, %ebx
	jne	L862
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
L882:
	call	_g_strdup
	movl	%eax, 28(%esi)
	movl	$LC126, (%esp)
L883:
	call	_g_strdup
	movl	%eax, 32(%esi)
	movl	$LC126, (%esp)
	jmp	L880
L843:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L844
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L874:
	fstpl	-96(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L846
	fldl	-96(%ebp)
	fmull	LC127
	fstpl	-96(%ebp)
L846:
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
	jmp	L882
L847:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L848
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L875:
	fstpl	-96(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L850
	fldl	-96(%ebp)
	fmull	LC127
	fstpl	-96(%ebp)
L850:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L851
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L876:
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
	jmp	L883
L844:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L874
L848:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L875
L851:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L876
L884:
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
	jmp	L881
	.p2align 4,,15
.globl _save_geometry_mzmatrix_file
	.def	_save_geometry_mzmatrix_file;	.scl	2;	.type	32;	.endef
_save_geometry_mzmatrix_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$-5, 12(%ebp)
	movl	8(%ebp), %eax
	je	L891
	leave
	ret
	.p2align 4,,7
L891:
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	testl	%eax, %eax
	je	L890
	cmpb	$0, (%eax)
	jne	L889
L890:
	movl	$LC121, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	call	_Message
	leave
	ret
L889:
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
	je	L892
	cmpb	$0, (%eax)
	jne	L895
L892:
	leave
	ret
	.p2align 4,,7
L895:
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
	je	L897
	movl	%ebx, 8(%ebp)
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	jmp	_save_gzmatrix_file_entry
	.p2align 4,,7
L897:
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
	je	L904
	movl	-36(%ebp), %ebx
	testl	%ebx, %ebx
	je	L905
L903:
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
L904:
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
L905:
	movl	_Fenetre, %edx
	movl	%edx, -36(%ebp)
	jmp	L903
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
	jae	L925
	movl	$0, -32(%ebp)
	movl	_Variables, %edx
	movl	_NcentersZmat, %ecx
	movl	_Geom, %eax
	movl	%edx, -24(%ebp)
	movl	%ecx, -20(%ebp)
	movl	%eax, -28(%ebp)
	.p2align 4,,15
L923:
	xorl	%edi, %edi
	xorl	%esi, %esi
	cmpl	-20(%ebp), %edi
	jae	L911
	movl	-28(%ebp), %ebx
	.p2align 4,,15
L922:
	cmpl	$5, (%ebx)
	jle	L913
	movl	24(%ebx), %eax
	movl	-32(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L927
	testl	%edi, %edi
	jne	L911
L913:
	cmpl	$7, (%ebx)
	jle	L916
	movl	32(%ebx), %eax
	movl	-32(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L927
	testl	%edi, %edi
	jne	L911
L916:
	cmpl	$9, (%ebx)
	jle	L912
	movl	40(%ebx), %eax
	movl	-32(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L927
	testl	%edi, %edi
	jne	L911
L912:
	incl	%esi
	addl	$56, %ebx
	cmpl	-20(%ebp), %esi
	jb	L922
L911:
	incl	-16(%ebp)
	movl	-32(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%edi, 8(%eax,%edx)
	addl	$12, %eax
	cmpl	_NVariables, %ecx
	movl	%eax, -32(%ebp)
	jb	L923
L925:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L927:
	incl	-16(%ebp)
	movl	$1, %edi
	movl	-32(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%edi, 8(%eax,%edx)
	addl	$12, %eax
	cmpl	_NVariables, %ecx
	movl	%eax, -32(%ebp)
	jb	L923
	jmp	L925
	.p2align 4,,15
.globl _AllocationVariable
	.def	_AllocationVariable;	.scl	2;	.type	32;	.endef
_AllocationVariable:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	_Variables, %edx
	testl	%edx, %edx
	je	L929
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
L929:
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
	jne	L934
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L934:
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
	je	L948
	cmpb	$68, -25(%ebp)
	je	L949
L937:
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
	js	L939
	movl	_Variables, %ebx
	leal	(%eax,%eax,2), %eax
	leal	0(,%eax,4), %esi
	movl	4(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L950
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%esi,%ebx)
	movl	8(%ebp), %ebx
	testl	%ebx, %ebx
	jne	L951
L938:
	cmpb	$82, -25(%ebp)
	je	L952
L957:
	cmpb	$65, -25(%ebp)
	je	L953
	cmpb	$68, -25(%ebp)
	je	L954
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L950:
	movl	%eax, (%esp)
	call	_g_free
	movl	-48(%ebp), %eax
	movl	_Variables, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%esi,%ebx)
	movl	8(%ebp), %ebx
	testl	%ebx, %ebx
	je	L938
	.p2align 4,,15
L951:
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
	jne	L957
	.p2align 4,,15
L952:
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
L948:
	movl	_Geom, %eax
	movl	32(%ebx,%eax), %eax
L947:
	movl	%eax, (%esp)
	call	_atof
	fstpl	-40(%ebp)
	jmp	L937
	.p2align 4,,7
L949:
	movl	_Geom, %eax
	movl	40(%ebx,%eax), %eax
	jmp	L947
	.p2align 4,,7
L953:
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
L954:
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
L939:
	movl	8(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	call	_AddVariableZmat
	jmp	L938
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
	jle	L959
	movl	_Geom, %edx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	movl	24(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L962
L959:
	cmpl	$1, %ebx
	jg	L963
L960:
	cmpl	$2, %ebx
	jg	L964
L961:
	popl	%eax
	popl	%ebx
	popl	%ebp
	jmp	_ChangeVariablesUseds
	.p2align 4,,7
L964:
	movl	_Geom, %edx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	movl	40(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L961
	movl	$0, (%esp)
	movl	%ebx, %edx
	movl	$68, %eax
	call	_trans_coord_Zmat
	jmp	L961
	.p2align 4,,7
L963:
	movl	_Geom, %edx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	movl	32(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L960
	movl	$0, (%esp)
	movl	%ebx, %edx
	movl	$65, %eax
	call	_trans_coord_Zmat
	jmp	L960
	.p2align 4,,7
L962:
	movl	$0, (%esp)
	movl	%ebx, %edx
	movl	$82, %eax
	call	_trans_coord_Zmat
	jmp	L959
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
L969:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jbe	L969
	testl	%esi, %esi
	jne	L978
L970:
	cmpl	$1, %esi
	ja	L979
L971:
	cmpl	$2, %esi
	ja	L980
L972:
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
	jne	L981
L973:
	cmpl	$1, %esi
	ja	L982
L974:
	cmpl	$2, %esi
	ja	L983
L975:
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
L978:
	movl	_Geom, %edx
	leal	0(,%esi,8), %eax
	subl	%esi, %eax
	movl	24(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L970
	movl	12(%ebp), %eax
	testl	%eax, %eax
	je	L970
	movl	$1, (%esp)
	movl	%esi, %edx
	movl	$82, %eax
	call	_trans_coord_Zmat
	jmp	L970
L983:
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
	jmp	L975
L982:
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
	jmp	L974
L981:
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
	jmp	L973
L980:
	movl	_Geom, %edx
	leal	0(,%esi,8), %eax
	subl	%esi, %eax
	movl	40(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L972
	movl	20(%ebp), %eax
	testl	%eax, %eax
	je	L972
	movl	$1, (%esp)
	movl	%esi, %edx
	movl	$68, %eax
	call	_trans_coord_Zmat
	jmp	L972
L979:
	movl	_Geom, %edx
	leal	0(,%esi,8), %eax
	subl	%esi, %eax
	movl	32(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L971
	movl	16(%ebp), %eax
	testl	%eax, %eax
	je	L971
	movl	$1, (%esp)
	movl	%esi, %edx
	movl	$65, %eax
	call	_trans_coord_Zmat
	jmp	L971
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
	je	L984
	xorl	%ebx, %ebx
	cmpl	%eax, %ebx
	jae	L992
	.p2align 4,,15
L994:
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
	jb	L994
L992:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L984
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	jmp	_rafresh_drawing
	.p2align 4,,7
L984:
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
	je	L1002
	cmpb	$65, %dl
	je	L1003
	xorl	%eax, %eax
	cmpb	$68, %dl
	je	L1004
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
	je	L1005
L1001:
	movl	$1, %eax
L1006:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L1003:
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
	jne	L1001
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-20(%ebp), %edx
	movl	%eax, 32(%ebx,%edx)
	movl	$1, %eax
	jmp	L1006
	.p2align 4,,7
L1004:
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
	jne	L1001
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-24(%ebp), %edx
	movl	%eax, 40(%ebx,%edx)
	movl	$1, %eax
	jmp	L1006
L1005:
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-16(%ebp), %edx
	movl	%eax, 24(%ebx,%edx)
	movl	$1, %eax
	jmp	L1006
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
	je	L1007
	xorl	%edi, %edi
	cmpl	_NcentersZmat, %edi
	jae	L1032
	.p2align 4,,15
L1045:
	xorl	%ebx, %ebx
	testl	%edi, %edi
	jne	L1039
	cmpl	$1, %edi
	ja	L1040
L1013:
	cmpl	$2, %edi
	ja	L1041
L1014:
	testl	%ebx, %ebx
	leal	1(%edi), %esi
	je	L1011
	xorl	%ebx, %ebx
	.p2align 4,,15
L1019:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jbe	L1019
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
	jne	L1042
L1020:
	cmpl	$1, %edi
	ja	L1043
L1021:
	cmpl	$2, %edi
	ja	L1044
L1022:
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
L1011:
	movl	%esi, %edi
	cmpl	_NcentersZmat, %edi
	jb	L1045
L1032:
	movl	_NVariables, %ecx
	movl	8(%ebp), %edi
	leal	-1(%ecx), %eax
	cmpl	%edi, %eax
	jbe	L1036
	movl	_Variables, %edx
	leal	(%edi,%edi,2), %eax
	leal	0(,%eax,4), %esi
	.p2align 4,,15
L1028:
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
	ja	L1028
L1036:
	leal	-1(%ecx), %eax
	testl	%eax, %eax
	movl	%eax, _NVariables
	je	L1029
	call	_AllocationVariable
L1030:
	movl	8(%ebp), %edx
	movl	_listv, %eax
	call	_removeFromList
L1007:
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1041:
	movl	%edi, 4(%esp)
	movl	8(%ebp), %eax
	movl	$68, (%esp)
	movl	%eax, 8(%esp)
	call	_ModifyCoord
	addl	%eax, %ebx
	jmp	L1014
L1039:
	movl	%edi, 4(%esp)
	movl	8(%ebp), %eax
	movl	$82, (%esp)
	movl	%eax, 8(%esp)
	call	_ModifyCoord
	cmpl	$1, %edi
	movl	%eax, %ebx
	jbe	L1013
L1040:
	movl	%edi, 4(%esp)
	movl	8(%ebp), %ecx
	movl	$65, (%esp)
	movl	%ecx, 8(%esp)
	call	_ModifyCoord
	addl	%eax, %ebx
	jmp	L1013
L1044:
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
	jmp	L1022
L1043:
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
	jmp	L1021
L1042:
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
	jmp	L1020
L1029:
	call	_freeVariables
	jmp	L1030
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
	jae	L1074
	movl	$0, -40(%ebp)
	movl	_Variables, %esi
	movl	$0, -44(%ebp)
	.p2align 4,,15
L1058:
	movl	-24(%ebp), %edx
	movl	-44(%ebp), %ecx
	movl	$0, (%edx,%edi,4)
	movl	8(%ecx,%esi), %ebx
	testl	%ebx, %ebx
	je	L1049
	xorl	%ebx, %ebx
	cmpl	_NcentersZmat, %ebx
	jb	L1057
	jmp	L1076
	.p2align 4,,7
L1054:
	cmpl	$1, %ebx
	ja	L1083
L1055:
	cmpl	$2, %ebx
	ja	L1084
L1053:
	incl	%ebx
	cmpl	_NcentersZmat, %ebx
	jae	L1085
L1057:
	testl	%ebx, %ebx
	je	L1054
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$82, (%esp)
	call	_ModifyCoord
	cmpl	$1, %ebx
	jbe	L1055
	.p2align 4,,15
L1083:
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$65, (%esp)
	call	_ModifyCoord
	cmpl	$2, %ebx
	jbe	L1053
	.p2align 4,,15
L1084:
	movl	%ebx, 4(%esp)
	incl	%ebx
	movl	%edi, 8(%esp)
	movl	$68, (%esp)
	call	_ModifyCoord
	cmpl	_NcentersZmat, %ebx
	jb	L1057
	.p2align 4,,15
L1085:
	movl	_Variables, %esi
L1076:
	incl	-20(%ebp)
	xorl	%ecx, %ecx
	movl	-24(%ebp), %eax
	movl	-40(%ebp), %edx
	movl	$1, (%eax,%edi,4)
	movl	_NVariables, %eax
	movl	%ecx, 8(%edx,%esi)
L1049:
	addl	$12, -44(%ebp)
	incl	%edi
	addl	$12, -40(%ebp)
	cmpl	%eax, %edi
	jb	L1058
L1074:
	xorl	%edi, %edi
	cmpl	%eax, %edi
	jae	L1078
	movl	_Variables, %esi
	xorl	%ebx, %ebx
	.p2align 4,,15
L1062:
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
	jb	L1062
L1078:
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
	jae	L1080
	movl	$0, -32(%ebp)
	movl	$-12, -36(%ebp)
	jmp	L1067
	.p2align 4,,7
L1065:
	addl	$12, -32(%ebp)
	incl	%edi
	cmpl	-16(%ebp), %edi
	jae	L1080
L1067:
	movl	-24(%ebp), %ecx
	movl	(%ecx,%edi,4), %eax
	testl	%eax, %eax
	jne	L1065
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
	jb	L1067
L1080:
	movl	_listv, %eax
	xorl	%edi, %edi
	call	_clearList
	call	_append_list_variables
	movl	_list, %eax
	call	_clearList
	call	_append_list_geom
	cmpl	_NVariables, %edi
	jae	L1082
	xorl	%ebx, %ebx
	.p2align 4,,15
L1071:
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
	jb	L1071
L1082:
	movl	-28(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_free
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1086
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1086:
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
	je	L1087
	movl	_InEdit, %ebx
	testl	%ebx, %ebx
	je	L1089
	movl	_LineSelected, %ecx
	testl	%ecx, %ecx
	jle	L1087
L1089:
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
	je	L1096
L1090:
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
	jbe	L1095
	movl	_InEdit, %eax
	testl	%eax, %eax
	je	L1091
	cmpl	$1, _LineSelected
	jle	L1095
L1091:
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
	jbe	L1095
	movl	_InEdit, %esi
	testl	%esi, %esi
	je	L1093
	cmpl	$2, _LineSelected
	jle	L1095
L1093:
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
L1095:
	movl	%ebx, (%esp)
	call	_g_free
L1087:
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L1096:
	fmull	LC158
	jmp	L1090
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
L1107:
	movl	$0, -28(%ebp)
	movl	-24(%ebp), %ecx
	incl	%ecx
	movl	%ecx, -40(%ebp)
	jmp	L1106
	.p2align 4,,7
L1104:
	movl	%esi, -28(%ebp)
	cmpl	$17, %esi
	ja	L1113
L1106:
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
	je	L1104
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
	jbe	L1106
	.p2align 4,,15
L1113:
	movl	-40(%ebp), %ecx
	cmpl	$8, %ecx
	movl	%ecx, -24(%ebp)
	jbe	L1107
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
	jle	L1115
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
	jne	L1119
	cmpl	$1, _iprogram
	je	L1120
L1118:
	leave
	jmp	_ChangeVariablesUseds
	.p2align 4,,7
L1119:
	call	_rafresh_drawing
	cmpl	$1, _iprogram
	jne	L1118
	.p2align 4,,15
L1120:
	call	_set_spin_of_electrons
	leave
	jmp	_ChangeVariablesUseds
	.p2align 4,,7
L1115:
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
L1125:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jle	L1125
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
	je	L1121
	cmpb	$0, (%eax)
	je	L1121
	movl	_NcentersZmat, %ecx
	movl	_Geom, %edx
	incl	%ecx
	movl	%ecx, _NcentersZmat
	testl	%edx, %edx
	je	L1194
	movl	%edx, (%esp)
	leal	0(,%ecx,8), %eax
	subl	%ecx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	call	_g_realloc
L1191:
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
	je	L1195
	movl	_Geom, %edi
	leal	0(,%edx,8), %eax
	xorl	%ecx, %ecx
	subl	%edx, %eax
	xorl	%esi, %esi
	movl	%ecx, -36(%edi,%eax,8)
	leal	-1(%edx), %eax
	cmpl	$0, %eax
	jle	L1184
	movl	%edx, -96(%ebp)
	movl	%edx, %ecx
	leal	20(%edi), %ebx
	.p2align 4,,15
L1135:
	leal	0(,%ecx,8), %eax
	subl	%ecx, %eax
	leal	-56(%edi,%eax,8), %edx
	movl	(%ebx), %eax
	cmpl	%eax, 20(%edx)
	jge	L1133
	movl	%eax, 20(%edx)
	movl	-96(%ebp), %ecx
L1133:
	incl	%esi
	leal	-1(%ecx), %eax
	addl	$56, %ebx
	cmpl	%esi, %eax
	jg	L1135
L1177:
	leal	0(,%ecx,8), %eax
	subl	%ecx, %eax
	incl	-36(%edi,%eax,8)
L1130:
	movl	_NcentersZmat, %ecx
	cmpl	$1, %ecx
	ja	L1196
L1136:
	cmpl	$2, %ecx
	seta	%al
	xorl	%edx, %edx
	cmpl	$0, -92(%ebp)
	sete	%dl
	testl	%eax, %edx
	jne	L1197
L1146:
	cmpl	$3, %ecx
	seta	%al
	xorl	%edx, %edx
	cmpl	$0, -92(%ebp)
	sete	%dl
	testl	%eax, %edx
	jne	L1198
L1156:
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
	je	L1166
	movl	%esi, 4(%esp)
	movl	_Entry+48, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
L1192:
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
	je	L1199
	movl	_NcentersZmat, %edx
	decl	%edx
	testl	%edx, %edx
	movl	%edx, _NcentersZmat
	jne	L1200
	xorl	%eax, %eax
L1193:
	movl	%eax, _Geom
L1121:
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1194:
	movl	$56, (%esp)
	call	_g_malloc
	jmp	L1191
L1199:
	movl	$13, (%esp)
	movl	_list, %eax
	leal	-88(%ebp), %edx
	call	_appendToList
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1201
L1169:
	cmpl	$1, _iprogram
	jne	L1121
	call	_set_spin_of_electrons
	jmp	L1121
L1198:
	call	_gtk_entry_get_type
	movl	$9, %ebx
	movl	%eax, %esi
L1160:
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
	jle	L1160
	movl	-52(%ebp), %edx
	testl	%edx, %edx
	je	L1162
	cmpb	$0, (%edx)
	je	L1162
L1161:
	movl	%edx, %eax
	call	_testav
	cmpl	$-1, %eax
	movl	%eax, %ebx
	jle	L1163
	leal	(%eax,%eax,2), %edx
	movl	_Variables, %eax
	movl	$1, %ecx
	movl	%ecx, 8(%eax,%edx,4)
L1163:
	incl	%ebx
	jl	L1202
L1164:
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
	jne	L1203
L1190:
	movl	-52(%ebp), %edx
L1165:
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
	jmp	L1156
L1197:
	call	_gtk_entry_get_type
	movl	$7, %ebx
	movl	%eax, %esi
L1150:
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
	jle	L1150
	movl	-60(%ebp), %edx
	testl	%edx, %edx
	je	L1152
	cmpb	$0, (%edx)
	je	L1152
L1151:
	movl	%edx, %eax
	call	_testav
	cmpl	$-1, %eax
	movl	%eax, %ebx
	jle	L1153
	leal	(%eax,%eax,2), %edx
	movl	_Variables, %eax
	movl	$1, %ecx
	movl	%ecx, 8(%eax,%edx,4)
L1153:
	incl	%ebx
	jl	L1204
L1154:
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
	jne	L1205
L1188:
	movl	-60(%ebp), %edx
L1155:
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
	jmp	L1146
L1196:
	call	_gtk_entry_get_type
	movl	$5, %ebx
	movl	%eax, %esi
L1140:
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
	jle	L1140
	movl	-68(%ebp), %edx
	testl	%edx, %edx
	je	L1142
	cmpb	$0, (%edx)
	je	L1142
L1141:
	movl	%edx, %eax
	call	_testav
	cmpl	$-1, %eax
	movl	%eax, %ebx
	jle	L1143
	leal	(%eax,%eax,2), %edx
	movl	_Variables, %eax
	movl	$1, %ecx
	movl	%ecx, 8(%eax,%edx,4)
L1143:
	incl	%ebx
	jl	L1206
L1144:
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
	jne	L1207
L1186:
	movl	-68(%ebp), %edx
L1145:
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
	jmp	L1136
L1166:
	movl	$LC46, (%esp)
	jmp	L1192
L1195:
	movl	_Geom, %eax
	movl	$0, 20(%eax)
	jmp	L1130
L1200:
	leal	0(,%edx,8), %eax
	subl	%edx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	movl	_Geom, %eax
	movl	%eax, (%esp)
	call	_g_realloc
	jmp	L1193
L1142:
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
	jmp	L1141
L1152:
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
	jmp	L1151
L1162:
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
	jmp	L1161
L1203:
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1190
	movl	$LC51, (%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -52(%ebp)
	movl	%eax, %edx
	jmp	L1165
L1205:
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1188
	movl	$LC51, (%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -60(%ebp)
	movl	%eax, %edx
	jmp	L1155
L1207:
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1186
	movl	$LC51, (%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	movl	%eax, %edx
	jmp	L1145
L1184:
	movl	_NcentersZmat, %ecx
	jmp	L1177
L1202:
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
	jmp	L1164
L1201:
	call	_rafresh_drawing
	jmp	L1169
L1204:
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
	jmp	L1154
L1206:
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
	jmp	L1144
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
L1212:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jle	L1212
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
	js	L1286
L1213:
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
	je	L1214
	cmpb	$0, (%eax)
	je	L1214
	movl	%edx, -156(%ebp)
	testl	%edx, %edx
	js	L1287
L1215:
	movl	-156(%ebp), %eax
	movl	$LC45, (%esp)
	incl	%eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -88(%ebp)
	movl	-156(%ebp), %eax
	testl	%eax, %eax
	js	L1216
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
	je	L1288
L1217:
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
	jne	L1216
	movl	_NcentersZmat, %edi
	movl	$-1, %esi
	xorl	%ebx, %ebx
	movl	%esi, -132(%ebp)
	cmpl	$0, %edi
	jle	L1220
	movl	_Geom, %eax
	xorl	%esi, %esi
	movl	%eax, -172(%ebp)
L1223:
	cmpl	%ebx, -156(%ebp)
	je	L1221
	movl	-172(%ebp), %edx
	movl	16(%esi,%edx), %eax
	movl	%eax, 4(%esp)
	movl	-136(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L1279
L1221:
	incl	%ebx
	addl	$56, %esi
	cmpl	%ebx, %edi
	jg	L1223
L1220:
	movl	-132(%ebp), %eax
	cmpl	$-1, %eax
	jne	L1216
	cmpl	$0, %edi
	jle	L1269
	movl	_Geom, %ecx
	movl	%edi, %ebx
	addl	$20, %ecx
L1229:
	movl	(%ecx), %edx
	cmpl	%edx, %eax
	jge	L1227
	movl	%edx, -132(%ebp)
	movl	%edx, %eax
L1227:
	addl	$56, %ecx
	decl	%ebx
	jne	L1229
L1269:
	incl	%eax
	movl	%eax, -132(%ebp)
L1216:
	movl	-156(%ebp), %ebx
	testl	%ebx, %ebx
	jle	L1230
	call	_gtk_entry_get_type
	movl	$5, %ebx
	movl	%eax, %esi
L1235:
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
	cmpl	$6, %ebx
	jle	L1235
L1232:
	movl	-68(%ebp), %eax
	testl	%eax, %eax
	je	L1257
	cmpb	$0, (%eax)
	jne	L1236
L1257:
	movl	$LC166, (%esp)
	movl	$1, %ebx
	movl	$LC165, %ecx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	call	_MessageGeom
L1284:
	xorl	%eax, %eax
	movl	%eax, _DestroyDialog
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1214:
	movl	$LC167, (%esp)
	movl	$1, %esi
	movl	$LC165, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
L1264:
	call	_ChangeVariablesUseds
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1286:
	movl	_LineSelectedOld, %eax
	movl	%eax, -156(%ebp)
	jmp	L1213
L1288:
	movl	$1, %eax
	movl	%eax, -168(%ebp)
	jmp	L1217
L1236:
	movl	-164(%ebp), %edx
	testl	%edx, %edx
	jne	L1285
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1289
L1274:
	movl	-68(%ebp), %eax
L1239:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -128(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -124(%ebp)
L1230:
	cmpl	$1, -156(%ebp)
	jg	L1290
L1240:
	cmpl	$2, -156(%ebp)
	jle	L1250
	call	_gtk_entry_get_type
	movl	$9, %ebx
	movl	%eax, %esi
L1255:
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
	jl	L1282
	incl	%ebx
	cmpl	$10, %ebx
	jle	L1255
L1252:
	movl	-52(%ebp), %eax
	testl	%eax, %eax
	je	L1257
	cmpb	$0, (%eax)
	je	L1257
	movl	-164(%ebp), %edx
	testl	%edx, %edx
	je	L1258
L1285:
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
	jmp	L1284
L1258:
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1291
L1278:
	movl	-52(%ebp), %eax
L1259:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -112(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -108(%ebp)
L1250:
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
	je	L1260
	movl	%ebx, 4(%esp)
	movl	_Entry+48, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
L1283:
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
	jne	L1292
L1262:
	cmpl	$1, _iprogram
	jne	L1264
	call	_set_spin_of_electrons
	jmp	L1264
L1287:
	movl	_LineSelectedOld, %edx
	movl	%edx, -156(%ebp)
	jmp	L1215
L1290:
	call	_gtk_entry_get_type
	movl	$7, %ebx
	movl	%eax, %esi
L1245:
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
	cmpl	$8, %ebx
	jle	L1245
L1242:
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	je	L1257
	cmpb	$0, (%eax)
	je	L1257
	movl	-164(%ebp), %edi
	testl	%edi, %edi
	jne	L1285
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1293
L1276:
	movl	-60(%ebp), %eax
L1249:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -120(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -116(%ebp)
	jmp	L1240
L1289:
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1274
	movl	-68(%ebp), %eax
	movl	$LC51, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	jmp	L1239
L1293:
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1276
	movl	-60(%ebp), %eax
	movl	$LC51, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -60(%ebp)
	jmp	L1249
	.p2align 4,,7
L1279:
	movl	-172(%ebp), %edx
	movl	20(%esi,%edx), %eax
	movl	%eax, -132(%ebp)
	jmp	L1220
L1292:
	call	_rafresh_drawing
	jmp	L1262
L1260:
	movl	$LC46, (%esp)
	jmp	L1283
L1280:
	movl	%ebx, -160(%ebp)
	movl	$1, %ecx
	movl	%ecx, -164(%ebp)
	jmp	L1232
L1291:
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1278
	movl	-52(%ebp), %eax
	movl	$LC51, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -52(%ebp)
	jmp	L1259
L1282:
	movl	%ebx, -160(%ebp)
	movl	$1, %esi
	movl	%esi, -164(%ebp)
	jmp	L1252
L1281:
	movl	%ebx, -160(%ebp)
	movl	$1, %eax
	movl	%eax, -164(%ebp)
	jmp	L1242
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
	jae	L1300
	xorl	%esi, %esi
	.p2align 4,,15
L1298:
	movl	_Variables, %eax
	movl	(%esi,%eax), %eax
	addl	$12, %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%edi,%ebx,4)
	incl	%ebx
	cmpl	_NVariables, %ebx
	jb	L1298
L1300:
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
	jne	L1305
L1307:
	movl	%esi, (%esp)
	call	_g_free
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L1305:
	movl	(%esi,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	movl	_NVariables, %eax
	incl	%eax
	cmpl	%ebx, %eax
	jbe	L1307
	movl	(%esi,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	movl	_NVariables, %eax
	incl	%eax
	cmpl	%ebx, %eax
	ja	L1305
	jmp	L1307
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
	js	L1315
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
	jne	L1316
L1313:
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
L1315:
	movl	_NVariables, %eax
	testl	%eax, %eax
	jne	L1311
	movl	$LC171, (%esp)
	movl	$1, %eax
	movl	$LC165, %edi
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	call	_MessageGeom
L1320:
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1311:
	movl	$LC172, (%esp)
	movl	$1, %esi
	movl	$LC165, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
	jmp	L1320
	.p2align 4,,7
L1316:
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	_EntryV, %eax
	movl	%eax, (%esp)
	call	_gtk_editable_set_editable
	jmp	L1313
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
	je	L1344
	cld
	movl	$LC3, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	je	L1345
	cld
	movl	$LC6, %edi
	movl	$7, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1327
	movl	_NVariables, %edx
	testl	%edx, %edx
	je	L1346
	movl	_LineSelectedV, %eax
	testl	%eax, %eax
	js	L1347
L1330:
	movl	_Variables, %edx
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	8(%eax,%edx), %ecx
	testl	%ecx, %ecx
	jne	L1348
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
L1342:
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
L1345:
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
L1344:
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_DialogueEditV
	.p2align 4,,7
L1327:
	cld
	movl	$LC9, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1333
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	je	L1349
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
	jmp	L1342
L1333:
	cld
	movl	$LC12, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1321
	movl	_LineSelectedV, %eax
	testl	%eax, %eax
	js	L1350
	movl	%eax, (%esp)
	call	_OneVariableToConst
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L1321
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_rafresh_drawing
L1349:
	movl	$LC139, (%esp)
	movl	$1, %edi
	movl	$LC165, %esi
L1353:
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
L1321:
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1346:
	movl	$LC179, (%esp)
	movl	$1, %esi
	movl	$LC165, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
	jmp	L1321
L1348:
	movl	(%eax,%edx), %eax
	movl	$1, %edi
	movl	$LC180, (%esp)
	movl	$LC165, %esi
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	jmp	L1353
L1347:
	leal	-1(%edx), %eax
	movl	%eax, _LineSelectedV
	jmp	L1330
L1350:
	movl	$LC189, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC165, %eax
	movl	%eax, 4(%esp)
	call	_MessageGeom
	jmp	L1321
