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
LC88:
	.ascii "%d %d %d %d\12\0"
LC87:
	.ascii "%d %d %d\12\0"
LC86:
	.ascii "%d %d\12\0"
	.text
	.p2align 4,,15
	.def	_selectedCell;	.scl	3;	.type	32;	.endef
_selectedCell:
	pushl	%ebp
	movl	$80, %ecx
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ebx, -12(%ebp)
	movl	16(%ebp), %ebx
	movl	%esi, -8(%ebp)
	movl	%edi, -4(%ebp)
	movl	%ecx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC47, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%ebx, (%esp)
	movl	%eax, %esi
	call	_atoi
	testl	%eax, %eax
	movl	%eax, %edi
	js	L417
	leal	-5(%esi), %eax
	cmpl	$1, %eax
	ja	L417
	testl	%edi, %edi
	jg	L432
	leal	-7(%esi), %eax
	cmpl	$1, %eax
	setbe	%dl
	xorl	%eax, %eax
	cmpl	$1, %edi
	setg	%al
	testl	%edx, %eax
	jne	L433
	leal	-9(%esi), %eax
	cmpl	$1, %eax
	setbe	%dl
	xorl	%eax, %eax
	cmpl	$2, %edi
	setg	%al
	testl	%edx, %eax
	je	L417
	movl	_Geom, %eax
	leal	0(,%edi,8), %ebx
	subl	%edi, %ebx
	sall	$3, %ebx
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -16(%ebp)
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %esi
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	-16(%ebp), %edx
	movl	%eax, 8(%esp)
	leal	1(%edi), %eax
	movl	%edx, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%eax, 4(%esp)
	movl	$LC88, (%esp)
	call	_printf
	movl	%edi, _NSA
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	decl	%eax
	movl	%eax, _NSA+4
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	decl	%eax
	movl	%eax, _NSA+8
	movl	_Geom, %eax
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	decl	%eax
	movl	%eax, _NSA+12
	.p2align 4,,15
L429:
	movl	_ZoneDessin, %esi
	testl	%esi, %esi
	je	L417
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	jmp	_rafresh_drawing
	.p2align 4,,7
L417:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L433:
	movl	_Geom, %eax
	leal	0(,%edi,8), %ebx
	subl	%edi, %ebx
	sall	$3, %ebx
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %esi
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, 8(%esp)
	leal	1(%edi), %eax
	movl	%esi, 12(%esp)
	movl	%eax, 4(%esp)
	movl	$LC87, (%esp)
	call	_printf
	movl	%edi, _NSA
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	decl	%eax
	movl	%eax, _NSA+4
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	decl	%eax
L431:
	movl	%eax, _NSA+8
	movl	$-1, %edi
	movl	%edi, _NSA+12
	jmp	L429
	.p2align 4,,7
L432:
	movl	_Geom, %eax
	leal	0(,%edi,8), %ebx
	subl	%edi, %ebx
	sall	$3, %ebx
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, 8(%esp)
	leal	1(%edi), %eax
	movl	%eax, 4(%esp)
	movl	$LC86, (%esp)
	call	_printf
	movl	%edi, _NSA
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	decl	%eax
	movl	%eax, _NSA+4
	movl	$-1, %eax
	jmp	L431
	.section .rdata,"dr"
LC101:
	.ascii "High\0"
LC102:
	.ascii "Medium\0"
LC103:
	.ascii "Low\0"
	.align 4
LC90:
	.ascii "Sorry\12 %s \12is not a number \12and is not a variable \0"
	.align 4
LC89:
	.ascii "Sorry %s is not a symbol for an atom \12\0"
LC95:
	.ascii "Sorry\12 %s \12is not an integer \0"
	.align 4
LC96:
	.ascii "Sorry\12 %s \12is not an integer between 1 and %d\0"
	.align 4
LC94:
	.ascii "Sorry : The distance can not be <0.01\0"
LC100:
	.ascii "%s\0"
	.align 4
LC92:
	.ascii "Sorry : The distance can not be negative\0"
	.align 4
LC104:
	.ascii "Sorry  The layer should be High, Medium, Low or one space \12\0"
	.align 4
LC99:
	.ascii "Because a multiple references to a center on the same card\12I set NR to %d\12\0"
	.align 4
LC98:
	.ascii "Because a multiple references to a center on the same card\12I set ND to %d\12\0"
	.align 4
LC97:
	.ascii "Because a multiple references to a center on the same card\12I set NA to %d\12\0"
	.align 8
LC93:
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
	je	L434
	movl	16(%ebp), %ecx
	testl	%ecx, %ecx
	je	L434
	cmpl	$1, %eax
	je	L619
	cmpl	$2, %eax
	je	L620
	cmpl	$3, %eax
	je	L621
	cmpl	$4, %eax
	je	L622
	cmpl	$5, %eax
	sete	%al
	cmpl	$7, %edi
	sete	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L468
	cmpl	$9, %edi
	je	L468
	cmpl	$6, %edi
	sete	%al
	cmpl	$8, %edi
	sete	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L484
	cmpl	$10, %edi
	je	L484
	cmpl	$11, %edi
	je	L623
	cmpl	$12, %edi
	jne	L434
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_strlen
	testl	%eax, %eax
	movl	%eax, %esi
	jle	L434
	movl	16(%ebp), %ecx
	movl	$1, %ebx
	movsbl	(%ecx),%eax
	movl	%eax, (%esp)
	call	_toupper
	movl	16(%ebp), %edx
	movb	%al, (%edx)
	jmp	L608
L624:
	movl	16(%ebp), %ecx
	movsbl	(%ebx,%ecx),%eax
	movl	%eax, (%esp)
	call	_tolower
	movl	16(%ebp), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
L608:
	cmpl	%esi, %ebx
	jl	L624
	movl	12(%ebp), %ecx
	movl	$LC101, %edi
	movl	%ecx, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	16(%ebp), %esi
	movl	$5, %ecx
	cld
	repe
	cmpsb
	je	L581
	movl	16(%ebp), %esi
	movl	$LC102, %edi
	movl	$7, %ecx
	repe
	cmpsb
	je	L581
	movl	16(%ebp), %esi
	movl	$LC103, %edi
	movl	$4, %ecx
	repe
	cmpsb
	je	L581
	movl	16(%ebp), %esi
	movl	$LC46, %edi
	movl	$2, %ecx
	repe
	cmpsb
	jne	L625
L581:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%ecx, %eax
	leal	0(,%eax,8), %esi
	movl	52(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L626
L582:
	movl	16(%ebp), %eax
	movl	$24, %edi
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
	movl	%edi, 8(%esp)
	movl	$-1, %edx
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	jmp	L613
	.p2align 4,,7
L621:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L434
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
	jne	L630
L449:
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
L671:
	movl	%edx, 12(%esp)
	movl	%ecx, 8(%esp)
L613:
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_list_store_set
	movl	%esi, (%esp)
	call	_gtk_tree_path_free
L614:
	movl	_ZoneDessin, %ebx
	testl	%ebx, %ebx
	je	L434
	call	_rafresh_drawing
	.p2align 4,,15
L434:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L468:
	movl	16(%ebp), %esi
	movl	%esi, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L434
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	%esi, %eax
	call	_testav
	incl	%eax
	jge	L470
	movl	%esi, 4(%esp)
	movl	$LC90, (%esp)
L615:
	call	_g_strdup_printf
L612:
	movl	%eax, (%esp)
	movl	%eax, %ebx
	movl	$1, %edi
	movl	%edi, 8(%esp)
	movl	$LC48, %esi
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	jmp	L434
	.p2align 4,,7
L619:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	testl	%eax, %eax
	movl	%eax, %ebx
	jle	L434
	movl	16(%ebp), %edx
	movsbl	(%edx),%eax
	movl	%eax, (%esp)
	call	_toupper
	movl	16(%ebp), %ecx
	decl	%ebx
	movb	%al, (%ecx)
	jg	L627
L439:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_test_atom_define
	testl	%eax, %eax
	jne	L675
	movl	$LC89, (%esp)
L673:
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	jmp	L615
L620:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L434
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
	jne	L631
L445:
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
	jmp	L671
L675:
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
	jne	L629
L441:
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
	jmp	L671
L631:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L445
L622:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L434
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
	je	L453
	movl	16(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L632
L454:
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
	jle	L456
	movl	%edx, -116(%ebp)
	movl	$0, -120(%ebp)
L459:
	cmpl	%esi, -48(%ebp)
	je	L457
	movl	-120(%ebp), %ecx
	movl	-116(%ebp), %edx
	movl	16(%ecx,%ebx), %eax
	movl	%eax, 4(%esp)
	movl	16(%edx,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L589
L457:
	addl	$56, -120(%ebp)
	incl	%esi
	cmpl	%esi, %edi
	jg	L459
L456:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	sall	$3, %eax
	subl	%esi, %eax
	sall	$3, %eax
	cmpl	$-1, 20(%eax,%ebx)
	je	L633
L453:
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
	jmp	L613
L484:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_strlen
	movl	$-1, -56(%ebp)
	testl	%eax, %eax
	movl	$-1, -60(%ebp)
	movl	$-1, -64(%ebp)
	jle	L434
	movl	12(%ebp), %esi
	movl	%esi, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_isInteger
	testl	%eax, %eax
	jne	L486
	movl	$LC95, (%esp)
	jmp	L673
L627:
	movsbl	1(%ecx),%eax
	movl	%eax, (%esp)
	call	_tolower
	movl	16(%ebp), %esi
	movb	%al, 1(%esi)
	jmp	L439
L470:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L634
L471:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L472
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_atof
	fldz
	fucompp
	fnstsw	%ax
	sahf
	jbe	L472
	cmpl	$5, %edi
	je	L635
L472:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L636
L474:
	cmpl	$5, %edi
	je	L637
L476:
	cmpl	$7, %edi
	je	L638
	cmpl	$9, %edi
	je	L639
L480:
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
	jmp	L613
L630:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L449
L629:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L441
L486:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_atoi
	testl	%eax, %eax
	movl	%eax, %ebx
	jle	L488
	movl	-48(%ebp), %eax
	incl	%eax
	cmpl	%ebx, %eax
	jg	L487
L488:
	movl	$LC96, (%esp)
	movl	-48(%ebp), %esi
	movl	16(%ebp), %eax
	movl	%esi, 8(%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	jmp	L612
L634:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L471
	movl	$LC51, (%esp)
	movl	16(%ebp), %esi
	movl	%esi, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 16(%ebp)
	jmp	L471
L636:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_atof
	fldl	LC93
	fxch	%st(1)
	fabs
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L474
	cmpl	$5, %edi
	jne	L476
	movl	$LC94, (%esp)
	call	_g_strdup_printf
	jmp	L612
	.p2align 4,,7
L637:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%ecx, %eax
	leal	0(,%eax,8), %esi
	movl	24(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L640
L477:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 24(%esi,%ebx)
	jmp	L480
L638:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	32(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L641
L479:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	%eax, 32(%esi,%ebx)
	jmp	L480
L632:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L454
L633:
	movl	_NcentersZmat, %edi
	xorl	%esi, %esi
	cmpl	$0, %edi
	jle	L586
	movl	%edi, -112(%ebp)
	leal	20(%ebx), %ecx
L465:
	movl	(%ecx), %edx
	cmpl	%edx, 20(%eax,%ebx)
	jge	L463
	movl	%edx, 20(%eax,%ebx)
	movl	-112(%ebp), %edi
L463:
	incl	%esi
	addl	$56, %ecx
	cmpl	%esi, %edi
	jg	L465
L586:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	sall	$3, %eax
	subl	%ecx, %eax
	incl	20(%ebx,%eax,8)
	jmp	L453
L623:
	movl	16(%ebp), %esi
	movl	%esi, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L434
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -48(%ebp)
	movl	%esi, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L569
	movl	%esi, 4(%esp)
	movl	$LC50, (%esp)
	jmp	L615
L487:
	cmpl	$6, %edi
	je	L642
	cmpl	$8, %edi
	je	L643
L490:
	cmpl	$10, %edi
	je	L644
L491:
	cmpl	$6, %edi
	je	L645
L493:
	cmpl	$8, %edi
	je	L646
	cmpl	$10, %edi
	je	L647
	cmpl	$6, %edi
	je	L590
	cmpl	$8, %edi
	je	L591
	cmpl	$10, %edi
	je	L592
L548:
	leal	(%edi,%edi), %eax
	movl	16(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%ecx, (%esp)
	call	_set_text_column
	jmp	L614
L639:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	40(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L648
L481:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 40(%esi,%ebx)
	jmp	L480
L589:
	movl	-120(%ebp), %ecx
	movl	-116(%ebp), %esi
	movl	20(%ecx,%ebx), %eax
	movl	%eax, 20(%esi,%ebx)
	jmp	L456
L640:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L477
L641:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L479
L569:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_test
	testl	%eax, %eax
	je	L570
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	je	L649
L570:
	movl	$LC100, (%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
L607:
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
	jne	L650
L572:
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
	jne	L651
L573:
	testl	%edi, %edi
	je	L434
	movl	%edi, (%esp)
	call	_g_free
	jmp	L434
L645:
	cmpl	$1, -48(%ebp)
	movl	%ebx, -56(%ebp)
	jg	L652
L495:
	cmpl	$2, -48(%ebp)
	jle	L590
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	44(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-56(%ebp), %eax
	jne	L590
L494:
	cmpl	$1, -48(%ebp)
	movl	$0, -68(%ebp)
	jg	L653
L496:
	cmpl	$2, -48(%ebp)
	jg	L654
L497:
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
L590:
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
	jle	L511
	movl	-60(%ebp), %eax
	movl	-48(%ebp), %esi
	decl	%eax
	movl	%esi, (%esp)
L601:
	movl	-104(%ebp), %edx
	call	_get_angle_zmatrix
	movl	%eax, -84(%ebp)
L512:
	movl	-64(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L514
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
L602:
	call	_get_dihedral_zmatrix
	movl	%eax, %ebx
L515:
	movl	-80(%ebp), %eax
	testl	%eax, %eax
	je	L517
	movl	-80(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_r_value
	testl	%eax, %eax
	jne	L655
L517:
	movl	-84(%ebp), %eax
	testl	%eax, %eax
	je	L519
	movl	-84(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_angle_value
	testl	%eax, %eax
	jne	L656
L519:
	testl	%ebx, %ebx
	je	L521
	movl	-48(%ebp), %eax
	movl	%ebx, %edx
	call	_reset_dihedral_value
	testl	%eax, %eax
	jne	L657
L521:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	28(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L658
L523:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 28(%esi,%ebx)
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jle	L524
	movl	_Geom, %ebx
	movl	36(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L525
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L525:
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
L524:
	movl	-64(%ebp), %eax
	testl	%eax, %eax
	jle	L548
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	44(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L527
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L527:
	movl	-64(%ebp), %eax
	movl	%eax, 4(%esp)
L611:
	movl	$LC45, (%esp)
	call	_g_strdup_printf
	movl	%eax, 44(%esi,%ebx)
	movl	_Geom, %eax
	movl	$20, %ebx
	movl	%ebx, 4(%esp)
	movl	44(%esi,%eax), %eax
L606:
	movl	%eax, (%esp)
	movl	12(%ebp), %edx
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L548
L648:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L481
L635:
	movl	$LC92, (%esp)
	call	_g_strdup_printf
	jmp	L612
L646:
	movl	%ebx, -60(%ebp)
	movl	-48(%ebp), %esi
	testl	%esi, %esi
	jle	L501
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%ecx, %eax
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-60(%ebp), %eax
	je	L500
L501:
	cmpl	$2, -48(%ebp)
	jle	L591
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	44(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-60(%ebp), %eax
	jne	L591
L500:
	movl	$0, -72(%ebp)
	movl	-48(%ebp), %esi
	testl	%esi, %esi
	jle	L502
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
	je	L659
L502:
	cmpl	$2, -48(%ebp)
	jg	L660
L503:
	movl	-72(%ebp), %esi
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_MessageGeom
	movl	%esi, (%esp)
	call	_g_free
L591:
	movl	$0, -88(%ebp)
	movl	-56(%ebp), %ecx
	xorl	%esi, %esi
	testl	%ecx, %ecx
	jle	L530
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
L603:
	call	_get_angle_zmatrix
	movl	%eax, -92(%ebp)
	movl	-64(%ebp), %eax
	testl	%eax, %eax
	jle	L532
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
L605:
	call	_get_dihedral_zmatrix
	movl	%eax, %esi
L533:
	movl	-88(%ebp), %eax
	testl	%eax, %eax
	je	L537
	movl	-88(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_r_value
	testl	%eax, %eax
	je	L537
	movl	$10, %eax
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
L537:
	movl	-92(%ebp), %eax
	testl	%eax, %eax
	je	L539
	movl	-92(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_angle_value
	testl	%eax, %eax
	je	L539
	movl	-92(%ebp), %edx
	movl	$14, %ebx
	movl	-44(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	12(%ebp), %edx
	call	_set_text_column
L539:
	testl	%esi, %esi
	je	L541
	movl	-48(%ebp), %eax
	movl	%esi, %edx
	call	_reset_dihedral_value
	testl	%eax, %eax
	je	L541
	movl	%esi, (%esp)
	movl	12(%ebp), %edx
	movl	$18, %ecx
	movl	%ecx, 4(%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
L541:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	36(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L543
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L543:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	%eax, 36(%esi,%ebx)
	movl	-56(%ebp), %eax
	testl	%eax, %eax
	jle	L544
	movl	_Geom, %ebx
	movl	28(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L661
L545:
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
L544:
	movl	-64(%ebp), %eax
	testl	%eax, %eax
	jle	L548
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%esi, %eax
	leal	0(,%eax,8), %esi
	movl	44(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L662
L547:
	movl	-64(%ebp), %edx
	movl	%edx, 4(%esp)
	jmp	L611
L647:
	cmpl	$1, -48(%ebp)
	movl	%ebx, -64(%ebp)
	jg	L663
L507:
	movl	-48(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L592
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-64(%ebp), %eax
	jne	L592
L506:
	cmpl	$1, -48(%ebp)
	movl	$0, -76(%ebp)
	jg	L664
L508:
	movl	-48(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L509
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
	je	L665
L509:
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
L592:
	movl	$0, -96(%ebp)
	movl	-56(%ebp), %ecx
	xorl	%esi, %esi
	movl	$0, -100(%ebp)
	testl	%ecx, %ecx
	jle	L550
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
L550:
	movl	-60(%ebp), %ecx
	movl	-56(%ebp), %ebx
	testl	%ecx, %ecx
	setg	%al
	shrl	$31, %ebx
	testl	%eax, %ebx
	je	L551
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
L551:
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jle	L552
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
L552:
	movl	-56(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L553
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
L553:
	movl	-60(%ebp), %eax
	shrl	$31, %eax
	testl	%eax, %ebx
	je	L554
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
L554:
	movl	-96(%ebp), %eax
	testl	%eax, %eax
	je	L555
	movl	-96(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_r_value
	testl	%eax, %eax
	jne	L666
L555:
	movl	-100(%ebp), %eax
	testl	%eax, %eax
	je	L557
	movl	-100(%ebp), %edx
	movl	-48(%ebp), %eax
	call	_reset_angle_value
	testl	%eax, %eax
	jne	L667
L557:
	testl	%esi, %esi
	je	L559
	movl	-48(%ebp), %eax
	movl	%esi, %edx
	call	_reset_dihedral_value
	testl	%eax, %eax
	jne	L668
L559:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	44(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L561
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
L561:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	%eax, 44(%esi,%ebx)
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jle	L562
	movl	_Geom, %ebx
	movl	36(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L669
L563:
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
L562:
	movl	-56(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L548
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	_Geom, %ebx
	sall	$3, %eax
	subl	%edx, %eax
	leal	0(,%eax,8), %esi
	movl	28(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L670
L565:
	movl	$LC45, (%esp)
	movl	-56(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 28(%esi,%ebx)
	movl	$12, %eax
	movl	%eax, 4(%esp)
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	jmp	L606
L626:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L582
L642:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	28(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L490
	jmp	L434
L643:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L491
	jmp	L434
L644:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %ecx
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%ecx, %eax
	movl	44(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	%ebx, %eax
	jne	L493
	jmp	L434
L514:
	cmpl	$2, -48(%ebp)
	jle	L515
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
	jmp	L602
L511:
	cmpl	$1, -48(%ebp)
	jle	L512
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
	jmp	L601
L658:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L523
L532:
	cmpl	$2, -48(%ebp)
	jle	L533
	movl	-56(%ebp), %ecx
	testl	%ecx, %ecx
	jle	L535
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
	jmp	L605
L651:
	call	_rafresh_drawing
	jmp	L573
L650:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L572
L661:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L545
L652:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	_Geom, %edx
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-56(%ebp), %eax
	jne	L495
	jmp	L494
L530:
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
	jmp	L603
L662:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L547
L656:
	movl	-84(%ebp), %eax
	movl	$14, %esi
	movl	12(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L519
L657:
	movl	%ebx, (%esp)
	movl	12(%ebp), %edx
	movl	$18, %ecx
	movl	%ecx, 4(%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L521
L655:
	movl	$10, %eax
	movl	-80(%ebp), %esi
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%esi, (%esp)
	call	_set_text_column
	jmp	L517
L649:
	movl	$LC51, (%esp)
	movl	16(%ebp), %esi
	movl	%esi, 4(%esp)
	jmp	L607
L625:
	movl	$LC104, (%esp)
	call	_g_strdup_printf
	jmp	L612
L670:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L565
L663:
	movl	-48(%ebp), %eax
	movl	-48(%ebp), %esi
	movl	_Geom, %edx
	sall	$3, %eax
	subl	%esi, %eax
	movl	36(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_atoi
	cmpl	-64(%ebp), %eax
	jne	L507
	jmp	L506
	.p2align 4,,7
L666:
	movl	$10, %eax
	movl	12(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L555
L667:
	movl	-100(%ebp), %edx
	movl	$14, %ebx
	movl	-44(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	12(%ebp), %edx
	call	_set_text_column
	jmp	L557
L668:
	movl	%esi, (%esp)
	movl	12(%ebp), %edx
	movl	$18, %ecx
	movl	%ecx, 4(%esp)
	movl	-44(%ebp), %eax
	call	_set_text_column
	jmp	L559
L669:
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %ebx
	jmp	L563
L659:
	movl	_Geom, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -56(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC99, (%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp)
	jmp	L502
L660:
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
	jne	L503
	movl	_Geom, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -64(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC98, (%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp)
	jmp	L503
L535:
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
	jmp	L605
L665:
	movl	_Geom, %eax
	movl	44(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -56(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC99, (%esp)
	call	_g_strdup_printf
	movl	%eax, -76(%ebp)
	jmp	L509
L653:
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
	jne	L496
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -60(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC97, (%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	jmp	L496
L664:
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
	jne	L508
	movl	_Geom, %eax
	movl	44(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -60(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC97, (%esp)
	call	_g_strdup_printf
	movl	%eax, -76(%ebp)
	jmp	L508
L654:
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
	jne	L497
	movl	_Geom, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -64(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC98, (%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	jmp	L497
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
	je	L678
	movl	(%ebx), %edx
	testl	%edx, %edx
	jne	L681
L678:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L676
L680:
	movl	%ebx, (%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gtk_widget_set_sensitive
L676:
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L681:
	cmpl	%eax, (%edx)
	jne	L678
	jmp	L680
	.section .rdata,"dr"
LC107:
	.ascii "/MenuZMatGeom\0"
	.data
	.align 4
menuName.1:
	.long	LC107
	.section .rdata,"dr"
LC108:
	.ascii "destroy\0"
LC109:
	.ascii "GabeditListOfProject\0"
LC111:
	.ascii "MenuName\0"
LC110:
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
	movl	$LC108, %eax
	movl	%edx, 16(%esp)
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_signal_connect_data
	movl	$LC109, (%esp)
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
	je	L684
L683:
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	menuName.1, %edx
	movl	%edx, 8(%esp)
	movl	$LC111, %edx
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
L684:
	movl	-16(%ebp), %eax
	movl	$LC110, %esi
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
	jmp	L683
	.section .rdata,"dr"
LC112:
	.ascii "/MenuZMatVariables\0"
	.data
	.align 4
menuName.0:
	.long	LC112
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
	movl	$LC108, %edx
	movl	%ecx, 8(%esp)
	movl	%eax, %edi
	movl	$2, %eax
	movl	%edx, 4(%esp)
	movl	%eax, 20(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, (%esp)
	call	_g_signal_connect_data
	movl	$LC109, (%esp)
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
	je	L687
L686:
	movl	%edi, (%esp)
	movl	$80, %esi
	movl	$LC111, %ebx
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
L687:
	movl	-16(%ebp), %eax
	movl	8(%eax), %eax
	movl	$0, (%esp)
	movl	%eax, 12(%esp)
	movl	$LC110, %eax
	movl	%eax, 8(%esp)
	movl	$32, %eax
	movl	%eax, 4(%esp)
	call	_g_log
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_error_free
	jmp	L686
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
	jge	L695
	.p2align 4,,15
L698:
	movl	(%edi,%ebx,4), %eax
	testl	%eax, %eax
	jne	L697
	incl	%ebx
L699:
	cmpl	%esi, %ebx
	jl	L698
L695:
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
L697:
	movl	%eax, (%esp)
	incl	%ebx
	call	_g_free
	jmp	L699
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
	je	L720
	xorl	%esi, %esi
	cmpl	%edx, %esi
	jge	L729
	movl	$0, -28(%ebp)
	leal	48(%edi), %ebx
	jmp	L719
	.p2align 4,,7
L705:
	movl	-40(%ebx), %eax
	testl	%eax, %eax
	jne	L732
L706:
	movl	-36(%ebx), %eax
	testl	%eax, %eax
	jne	L733
L707:
	testl	%esi, %esi
	je	L708
	movl	-24(%ebx), %eax
	testl	%eax, %eax
	jne	L734
L709:
	movl	-20(%ebx), %eax
	testl	%eax, %eax
	jne	L735
L708:
	cmpl	$1, %esi
	jbe	L711
	movl	-16(%ebx), %eax
	testl	%eax, %eax
	jne	L736
L712:
	movl	-28(%ebp), %edx
	movl	36(%edx,%edi), %eax
	testl	%eax, %eax
	jne	L737
L711:
	cmpl	$2, %esi
	jbe	L714
	movl	-8(%ebx), %eax
	testl	%eax, %eax
	jne	L738
L715:
	movl	-28(%ebp), %edx
	movl	44(%edx,%edi), %eax
	testl	%eax, %eax
	jne	L739
L714:
	movl	(%ebx), %eax
	testl	%eax, %eax
	jne	L740
L717:
	movl	-28(%ebp), %edx
	movl	52(%edx,%edi), %eax
	testl	%eax, %eax
	jne	L741
	addl	$56, -28(%ebp)
	incl	%esi
	addl	$56, %ebx
	cmpl	-20(%ebp), %esi
	jge	L729
L719:
	movl	-44(%ebx), %eax
	testl	%eax, %eax
	je	L705
	movl	%eax, (%esp)
	call	_g_free
	movl	-40(%ebx), %eax
	testl	%eax, %eax
	je	L706
	.p2align 4,,15
L732:
	movl	%eax, (%esp)
	call	_g_free
	movl	-36(%ebx), %eax
	testl	%eax, %eax
	je	L707
	.p2align 4,,15
L733:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L707
	.p2align 4,,7
L741:
	movl	%eax, (%esp)
	incl	%esi
	call	_g_free
	addl	$56, -28(%ebp)
	addl	$56, %ebx
	cmpl	-20(%ebp), %esi
	jl	L719
	.p2align 4,,15
L729:
	testl	%edi, %edi
	je	L720
	movl	%edi, (%esp)
	call	_g_free
L720:
	movl	-16(%ebp), %eax
	testl	%eax, %eax
	je	L700
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	jg	L742
L731:
	movl	-16(%ebp), %eax
	movl	%eax, 8(%ebp)
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_g_free
	.p2align 4,,7
L740:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L717
	.p2align 4,,7
L735:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L708
	.p2align 4,,7
L734:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L709
	.p2align 4,,7
L739:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L714
	.p2align 4,,7
L738:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L715
	.p2align 4,,7
L737:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L711
	.p2align 4,,7
L736:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L712
L742:
	movl	-24(%ebp), %esi
	xorl	%ebx, %ebx
	jmp	L727
	.p2align 4,,7
L725:
	movl	-16(%ebp), %edx
	movl	4(%ebx,%edx), %eax
	testl	%eax, %eax
	jne	L743
L724:
	addl	$12, %ebx
	decl	%esi
	je	L731
L727:
	movl	-16(%ebp), %edx
	movl	(%ebx,%edx), %eax
	testl	%eax, %eax
	je	L725
	movl	%eax, (%esp)
	call	_g_free
	movl	-16(%ebp), %edx
	movl	4(%ebx,%edx), %eax
	testl	%eax, %eax
	je	L724
	.p2align 4,,15
L743:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L724
L700:
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
	je	L744
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	cmpl	_NcentersZmat, %esi
	jb	L752
	movl	%eax, (%esp)
	call	_g_free
	xorl	%eax, %eax
	movl	%eax, _Geom
	xorl	%eax, %eax
	movl	%eax, _NcentersZmat
	.p2align 4,,15
L744:
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L760:
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$1, %esi
	ja	L757
	.p2align 4,,15
L750:
	cmpl	$2, %esi
	ja	L758
L751:
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
	jae	L759
	movl	_Geom, %eax
L752:
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
	jne	L760
	cmpl	$1, %esi
	jbe	L750
L757:
	movl	_Geom, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$2, %esi
	jbe	L751
	.p2align 4,,15
L758:
	movl	_Geom, %eax
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_Geom, %eax
	movl	44(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	jmp	L751
L759:
	movl	_Geom, %eax
	movl	%eax, (%esp)
	call	_g_free
	xorl	%eax, %eax
	movl	%eax, _Geom
	xorl	%eax, %eax
	movl	%eax, _NcentersZmat
	jmp	L744
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
	je	L761
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	cmpl	_NVariables, %esi
	jb	L766
	movl	%eax, (%esp)
	xorl	%ebx, %ebx
	call	_g_free
	movl	%ebx, _Variables
	xorl	%ecx, %ecx
	movl	%ecx, _NVariables
	.p2align 4,,15
L761:
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L769:
	movl	_Variables, %eax
L766:
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
	jb	L769
	movl	_Variables, %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_free
	movl	%ebx, _Variables
	xorl	%ecx, %ecx
	movl	%ecx, _NVariables
	jmp	L761
	.p2align 4,,15
	.def	_destroy_dialogue;	.scl	3;	.type	32;	.endef
_destroy_dialogue:
	pushl	%ebp
	movl	_DestroyDialog, %eax
	movl	%esp, %ebp
	testl	%eax, %eax
	jne	L772
	popl	%ebp
	ret
	.p2align 4,,7
L772:
	popl	%ebp
	jmp	_delete_child
	.section .rdata,"dr"
LC113:
	.ascii "%s.gzmt\0"
LC114:
	.ascii "w\0"
LC117:
	.ascii "%s\12\0"
LC119:
	.ascii "%s\11%s\11%s\11%s\11%s\12\0"
LC120:
	.ascii "%s\11%s\11%s\11%s\11%s\11%s\11%s\12\0"
LC121:
	.ascii " \12\0"
LC122:
	.ascii "%s\11%s\12\0"
LC118:
	.ascii "%s\11%s\11%s\12\0"
	.align 4
LC115:
	.ascii "Sorry,\12 I can not open %s file\0"
LC116:
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
	movl	$LC113, (%esp)
	call	_g_strdup_printf
	movl	%eax, -16(%ebp)
	movl	%ebx, (%esp)
	call	_g_free
	movl	$LC114, %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_FOpen
	movl	%eax, -24(%ebp)
	testl	%eax, %eax
	je	L818
	movl	_Geom, %eax
	movl	$LC117, %ebx
	movl	4(%eax), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	movl	_NcentersZmat, %edx
	cmpl	$1, %edx
	movl	%edx, -36(%ebp)
	ja	L819
L775:
	cmpl	$2, -36(%ebp)
	jbe	L779
	cmpl	$1, _Units
	je	L781
	movl	_Geom, %eax
	movl	136(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L780
L781:
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
	movl	$LC119, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	movl	_NcentersZmat, %edx
	movl	%edx, -36(%ebp)
L779:
	movl	$3, -20(%ebp)
	movl	-36(%ebp), %edx
	cmpl	%edx, -20(%ebp)
	jae	L805
	movl	$168, %ebx
	jmp	L789
	.p2align 4,,7
L787:
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
	movl	$LC120, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_fprintf
	incl	-20(%ebp)
	movl	-20(%ebp), %edx
	cmpl	_NcentersZmat, %edx
	jae	L805
L789:
	cmpl	$1, _Units
	je	L787
	movl	_Geom, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L787
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
	movl	$LC120, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	incl	-20(%ebp)
	movl	-20(%ebp), %edx
	cmpl	_NcentersZmat, %edx
	jb	L789
L805:
	movl	-24(%ebp), %ecx
	movl	$2, %eax
	movl	%eax, 8(%esp)
	movl	$1, %eax
	movl	%ecx, 12(%esp)
	movl	%eax, 4(%esp)
	movl	$LC121, (%esp)
	call	_fwrite
	movl	$0, -20(%ebp)
	xorl	%eax, %eax
	cmpl	_NVariables, %eax
	jae	L807
	movl	$0, -40(%ebp)
	.p2align 4,,15
L802:
	cmpl	$1, _Units
	je	L820
L793:
	movl	_NcentersZmat, %edx
	movl	$1, %edi
	cmpl	%edx, %edi
	movl	%edx, -36(%ebp)
	jae	L809
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
	je	L810
	.p2align 4,,15
L821:
	incl	%edi
	addl	$56, %ebx
	cmpl	-36(%ebp), %edi
	jae	L800
	movl	-40(%ebp), %edx
	movl	(%edx,%esi), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %ecx
	movl	24(%ebx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L821
L810:
	movl	-40(%ebp), %edx
	movl	4(%edx,%esi), %eax
	movl	%eax, (%esp)
	call	_bohr_to_ang
	movl	%eax, 12(%esp)
	movl	-40(%ebp), %ecx
	movl	_Variables, %eax
L815:
	movl	(%ecx,%eax), %eax
	movl	$LC122, %edi
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	incl	-20(%ebp)
	addl	$12, -40(%ebp)
	movl	-20(%ebp), %eax
	cmpl	_NVariables, %eax
	jb	L802
L807:
	movl	-24(%ebp), %edx
	movl	$1, %ecx
	movl	$2, %ebx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	$LC121, (%esp)
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
	jne	L822
L803:
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
L819:
	cmpl	$1, _Units
	je	L777
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L776
L777:
	movl	_Geom, %edx
	movl	$LC118, %ecx
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
	jmp	L775
L809:
	movl	_Variables, %esi
L800:
	movl	-40(%ebp), %edx
	movl	4(%edx,%esi), %eax
	movl	%eax, 12(%esp)
	movl	(%edx,%esi), %eax
	movl	$LC122, %esi
	movl	%esi, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_fprintf
	incl	-20(%ebp)
	addl	$12, -40(%ebp)
	movl	-20(%ebp), %eax
	cmpl	_NVariables, %eax
	jae	L807
	cmpl	$1, _Units
	jne	L793
L820:
	movl	-40(%ebp), %ecx
	movl	_Variables, %eax
	movl	4(%ecx,%eax), %edx
	movl	%edx, 12(%esp)
	jmp	L815
L818:
	movl	-16(%ebp), %ecx
	movl	$LC115, (%esp)
	movl	$1, %edi
	movl	$LC116, %esi
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
L822:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L803
L776:
	movl	_Geom, %eax
	movl	80(%eax), %eax
	movl	%eax, (%esp)
	call	_bohr_to_ang
	movl	%eax, 16(%esp)
	movl	_Geom, %edx
	movl	84(%edx), %eax
	movl	%eax, 12(%esp)
	movl	60(%edx), %eax
	movl	$LC118, %edx
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_fprintf
	movl	_NcentersZmat, %ecx
	movl	%ecx, -36(%ebp)
	jmp	L775
L780:
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
	movl	$LC119, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_fprintf
	movl	_NcentersZmat, %eax
	movl	%eax, -36(%ebp)
	jmp	L779
	.section .rdata,"dr"
LC123:
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
	je	L827
	leave
	ret
	.p2align 4,,7
L827:
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	testl	%eax, %eax
	je	L826
	cmpb	$0, (%eax)
	jne	L825
L826:
	movl	$LC123, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	call	_Message
	leave
	ret
L825:
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
	je	L828
	cmpb	$0, (%eax)
	jne	L831
L828:
	leave
	ret
	.p2align 4,,7
L831:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_gzmatrix_file
	.section .rdata,"dr"
LC124:
	.ascii "%s.zmt\0"
	.align 4
LC125:
	.ascii "\12\12     MOPAC file created by Gabedit\12\0"
	.align 4
LC130:
	.ascii "%3s %20s %5s %20s %5s %20s %5s %5s %5s %5s\12\0"
LC127:
	.ascii "%20.10f\0"
LC128:
	.ascii "0\0"
	.align 8
LC129:
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
	movl	$LC124, (%esp)
	call	_g_strdup_printf
	movl	%eax, 8(%ebp)
	movl	%ebx, (%esp)
	xorl	%ebx, %ebx
	call	_g_free
	movl	$LC114, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_FOpen
	movl	%eax, -80(%ebp)
	testl	%eax, %eax
	je	L890
	.p2align 4,,15
L837:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$9, %ebx
	jbe	L837
	movl	$LC125, (%esp)
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
	jae	L874
	leal	-72(%ebp), %esi
	xorl	%edi, %edi
L869:
	xorl	%ebx, %ebx
	.p2align 4,,15
L844:
	movl	-72(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$9, %ebx
	jbe	L844
	cmpl	$2, -76(%ebp)
	jg	L859
	cmpl	$1, -76(%ebp)
	je	L849
	jle	L891
	cmpl	$2, -76(%ebp)
	je	L853
	cmpl	$3, -76(%ebp)
	je	L859
L868:
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
	movl	$LC130, %eax
	movl	%eax, 4(%esp)
	movl	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	incl	-76(%ebp)
	movl	-76(%ebp), %eax
	cmpl	_NcentersZmat, %eax
	jb	L869
L874:
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
	jne	L892
L870:
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
L887:
	call	_g_free
	addl	$156, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L892:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L870
	.p2align 4,,7
L859:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L860
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L883:
	fstpl	-96(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L862
	fldl	-96(%ebp)
	fmull	LC129
	fstpl	-96(%ebp)
L862:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L863
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L884:
	fstpl	-104(%ebp)
	movl	_Geom, %eax
	movl	40(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L865
	movl	_Geom, %eax
	movl	40(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L885:
	fstpl	-112(%ebp)
	movl	_Geom, %eax
	movl	4(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	fldl	-96(%ebp)
	movl	%eax, (%esi)
	movl	$LC127, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esi)
	movl	$LC128, (%esp)
	call	_g_strdup
	fldl	-104(%ebp)
	movl	%eax, 8(%esi)
	movl	$LC127, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 12(%esi)
	movl	$LC128, (%esp)
	call	_g_strdup
	fldl	-112(%ebp)
	movl	%eax, 16(%esi)
	movl	$LC127, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 20(%esi)
	movl	$LC128, (%esp)
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
L886:
	call	_g_strdup
	movl	%eax, 36(%esi)
	jmp	L868
L860:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L883
L865:
	movl	_Geom, %eax
	movl	40(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L885
L863:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L884
L891:
	movl	-76(%ebp), %ebx
	testl	%ebx, %ebx
	jne	L868
	movl	_Geom, %eax
	movl	4(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, (%esi)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC127, (%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esi)
	movl	$LC128, (%esp)
	call	_g_strdup
	movl	%eax, 8(%esi)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$LC127, (%esp)
	call	_g_strdup_printf
	movl	%eax, 12(%esi)
	movl	$LC128, (%esp)
	call	_g_strdup
	movl	%eax, 16(%esi)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$LC127, (%esp)
	call	_g_strdup_printf
	movl	%eax, 20(%esi)
	movl	$LC128, (%esp)
	call	_g_strdup
	movl	%eax, 24(%esi)
	movl	$LC128, (%esp)
L888:
	call	_g_strdup
	movl	%eax, 28(%esi)
	movl	$LC128, (%esp)
L889:
	call	_g_strdup
	movl	%eax, 32(%esi)
	movl	$LC128, (%esp)
	jmp	L886
L849:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L850
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableZmat
L880:
	fstpl	-96(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L852
	fldl	-96(%ebp)
	fmull	LC129
	fstpl	-96(%ebp)
L852:
	movl	_Geom, %eax
	xorl	%ebx, %ebx
	movl	4(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	fldl	-96(%ebp)
	movl	%eax, (%esi)
	movl	$LC127, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esi)
	movl	$LC128, (%esp)
	call	_g_strdup
	movl	%eax, 8(%esi)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, 8(%esp)
	movl	$LC127, (%esp)
	call	_g_strdup_printf
	movl	%eax, 12(%esi)
	movl	$LC128, (%esp)
	call	_g_strdup
	movl	%eax, 16(%esi)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC127, (%esp)
	call	_g_strdup_printf
	movl	%eax, 20(%esi)
	movl	$LC128, (%esp)
	call	_g_strdup
	movl	%eax, 24(%esi)
	movl	_Geom, %eax
	movl	28(%edi,%eax), %eax
	movl	%eax, (%esp)
	jmp	L888
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
L881:
	fstpl	-96(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L856
	fldl	-96(%ebp)
	fmull	LC129
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
L882:
	fstpl	-104(%ebp)
	movl	_Geom, %eax
	movl	4(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	fldl	-96(%ebp)
	movl	%eax, (%esi)
	movl	$LC127, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esi)
	movl	$LC128, (%esp)
	call	_g_strdup
	fldl	-104(%ebp)
	movl	%eax, 8(%esi)
	movl	$LC127, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, 12(%esi)
	movl	$LC128, (%esp)
	call	_g_strdup
	movl	%eax, 16(%esi)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$LC127, (%esp)
	call	_g_strdup_printf
	movl	%eax, 20(%esi)
	movl	$LC128, (%esp)
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
	jmp	L889
L850:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L880
L854:
	movl	_Geom, %eax
	movl	24(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L881
L857:
	movl	_Geom, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L882
L890:
	movl	$LC115, (%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC116, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_Message
	movl	%ebx, (%esp)
	jmp	L887
	.p2align 4,,15
.globl _save_geometry_mzmatrix_file
	.def	_save_geometry_mzmatrix_file;	.scl	2;	.type	32;	.endef
_save_geometry_mzmatrix_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$-5, 12(%ebp)
	movl	8(%ebp), %eax
	je	L897
	leave
	ret
	.p2align 4,,7
L897:
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	testl	%eax, %eax
	je	L896
	cmpb	$0, (%eax)
	jne	L895
L896:
	movl	$LC123, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	call	_Message
	leave
	ret
L895:
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
	je	L898
	cmpb	$0, (%eax)
	jne	L901
L898:
	leave
	ret
	.p2align 4,,7
L901:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_mzmatrix_file
	.section .rdata,"dr"
LC133:
	.ascii "ButtonGZmat\0"
LC134:
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
	movl	$LC133, %esi
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
	movl	$LC134, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	call	_gtk_toggle_button_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	testb	$1, 88(%eax)
	je	L903
	movl	%ebx, 8(%ebp)
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	jmp	_save_gzmatrix_file_entry
	.p2align 4,,7
L903:
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
	movl	$LC113, (%esp)
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
	movl	$LC124, (%esp)
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
LC137:
	.ascii "*.gzmt *.zmt\0"
LC138:
	.ascii "*.gzmt\0"
LC139:
	.ascii "*.zmt\0"
LC140:
	.ascii "*\0"
	.data
	.align 4
patterns.2:
	.long	LC137
	.long	LC138
	.long	LC139
	.long	LC140
	.long	0
	.section .rdata,"dr"
LC135:
	.ascii " File  : \0"
LC136:
	.ascii "Save in Z-matrix file\0"
LC143:
	.ascii "%s%s%s.gzmt\0"
LC142:
	.ascii "\\\0"
LC144:
	.ascii " Save Z-matrix \0"
LC145:
	.ascii "delete_event\0"
LC146:
	.ascii "Type of file\0"
LC147:
	.ascii "Gaussian Z-matrix \0"
LC148:
	.ascii "Mopac Z-matrix\0"
LC149:
	.ascii "clicked\0"
LC150:
	.ascii "ButtonMZmat\0"
LC151:
	.ascii "Cancel\0"
LC152:
	.ascii "OK\0"
LC141:
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
	movl	$LC135, (%esp)
	call	_g_strdup
	movl	%eax, -40(%ebp)
	movl	$LC136, (%esp)
	call	_g_strdup
	movl	%eax, %esi
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	je	L910
	movl	-36(%ebp), %ebx
	testl	%ebx, %ebx
	je	L911
L909:
	movl	$LC143, (%esp)
	movl	_fileopen, %eax
	movl	$LC142, %ecx
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
	movl	$LC144, %eax
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
	movl	$LC145, %edx
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
	movl	$LC145, %edx
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
	movl	$LC146, (%esp)
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
	movl	$LC147, %ecx
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
	movl	$LC148, %ecx
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
	movl	$LC134, %edx
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
	movl	$LC149, %edx
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
	movl	$LC149, %edx
	movl	%ecx, 8(%esp)
	movl	$80, %edi
	movl	%esi, 16(%esp)
	movl	$LC133, %esi
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
	movl	$LC134, %esi
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
	movl	$LC150, %edx
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
	movl	$LC151, %ebx
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
	movl	$LC149, %ebx
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
	movl	$LC152, %ecx
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
	movl	$LC149, %edx
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
	movl	$LC149, %edx
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
L910:
	movl	$LC141, (%esp)
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
L911:
	movl	_Fenetre, %edx
	movl	%edx, -36(%ebp)
	jmp	L909
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
	jae	L931
	movl	$0, -32(%ebp)
	movl	_Variables, %edx
	movl	_NcentersZmat, %ecx
	movl	_Geom, %eax
	movl	%edx, -24(%ebp)
	movl	%ecx, -20(%ebp)
	movl	%eax, -28(%ebp)
	.p2align 4,,15
L929:
	xorl	%edi, %edi
	xorl	%esi, %esi
	cmpl	-20(%ebp), %edi
	jae	L917
	movl	-28(%ebp), %ebx
	.p2align 4,,15
L928:
	cmpl	$5, (%ebx)
	jle	L919
	movl	24(%ebx), %eax
	movl	-32(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L933
	testl	%edi, %edi
	jne	L917
L919:
	cmpl	$7, (%ebx)
	jle	L922
	movl	32(%ebx), %eax
	movl	-32(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L933
	testl	%edi, %edi
	jne	L917
L922:
	cmpl	$9, (%ebx)
	jle	L918
	movl	40(%ebx), %eax
	movl	-32(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L933
	testl	%edi, %edi
	jne	L917
L918:
	incl	%esi
	addl	$56, %ebx
	cmpl	-20(%ebp), %esi
	jb	L928
L917:
	incl	-16(%ebp)
	movl	-32(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%edi, 8(%eax,%edx)
	addl	$12, %eax
	cmpl	_NVariables, %ecx
	movl	%eax, -32(%ebp)
	jb	L929
L931:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L933:
	incl	-16(%ebp)
	movl	$1, %edi
	movl	-32(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%edi, 8(%eax,%edx)
	addl	$12, %eax
	cmpl	_NVariables, %ecx
	movl	%eax, -32(%ebp)
	jb	L929
	jmp	L931
	.p2align 4,,15
.globl _AllocationVariable
	.def	_AllocationVariable;	.scl	2;	.type	32;	.endef
_AllocationVariable:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	_Variables, %edx
	testl	%edx, %edx
	je	L935
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
L935:
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
	jne	L940
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L940:
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
LC153:
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
	je	L954
	cmpb	$68, -25(%ebp)
	je	L955
L943:
	movl	-32(%ebp), %eax
	incl	%eax
	movl	%eax, 12(%esp)
	movl	_Geom, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, 8(%esp)
	movsbl	-25(%ebp),%eax
	movl	$LC153, (%esp)
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
	js	L945
	movl	_Variables, %ebx
	leal	(%eax,%eax,2), %eax
	leal	0(,%eax,4), %esi
	movl	4(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L956
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%esi,%ebx)
	movl	8(%ebp), %ebx
	testl	%ebx, %ebx
	jne	L957
L944:
	cmpb	$82, -25(%ebp)
	je	L958
L963:
	cmpb	$65, -25(%ebp)
	je	L959
	cmpb	$68, -25(%ebp)
	je	L960
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L956:
	movl	%eax, (%esp)
	call	_g_free
	movl	-48(%ebp), %eax
	movl	_Variables, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%esi,%ebx)
	movl	8(%ebp), %ebx
	testl	%ebx, %ebx
	je	L944
	.p2align 4,,15
L957:
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
	jne	L963
	.p2align 4,,15
L958:
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
L954:
	movl	_Geom, %eax
	movl	32(%ebx,%eax), %eax
L953:
	movl	%eax, (%esp)
	call	_atof
	fstpl	-40(%ebp)
	jmp	L943
	.p2align 4,,7
L955:
	movl	_Geom, %eax
	movl	40(%ebx,%eax), %eax
	jmp	L953
	.p2align 4,,7
L959:
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
L960:
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
L945:
	movl	8(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	call	_AddVariableZmat
	jmp	L944
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
	jle	L965
	movl	_Geom, %edx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	movl	24(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L968
L965:
	cmpl	$1, %ebx
	jg	L969
L966:
	cmpl	$2, %ebx
	jg	L970
L967:
	popl	%eax
	popl	%ebx
	popl	%ebp
	jmp	_ChangeVariablesUseds
	.p2align 4,,7
L970:
	movl	_Geom, %edx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	movl	40(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L967
	movl	$0, (%esp)
	movl	%ebx, %edx
	movl	$68, %eax
	call	_trans_coord_Zmat
	jmp	L967
	.p2align 4,,7
L969:
	movl	_Geom, %edx
	leal	0(,%ebx,8), %eax
	subl	%ebx, %eax
	movl	32(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L966
	movl	$0, (%esp)
	movl	%ebx, %edx
	movl	$65, %eax
	call	_trans_coord_Zmat
	jmp	L966
	.p2align 4,,7
L968:
	movl	$0, (%esp)
	movl	%ebx, %edx
	movl	$82, %eax
	call	_trans_coord_Zmat
	jmp	L965
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
L975:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jbe	L975
	testl	%esi, %esi
	jne	L984
L976:
	cmpl	$1, %esi
	ja	L985
L977:
	cmpl	$2, %esi
	ja	L986
L978:
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
	jne	L987
L979:
	cmpl	$1, %esi
	ja	L988
L980:
	cmpl	$2, %esi
	ja	L989
L981:
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
L984:
	movl	_Geom, %edx
	leal	0(,%esi,8), %eax
	subl	%esi, %eax
	movl	24(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L976
	movl	12(%ebp), %eax
	testl	%eax, %eax
	je	L976
	movl	$1, (%esp)
	movl	%esi, %edx
	movl	$82, %eax
	call	_trans_coord_Zmat
	jmp	L976
L989:
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
	jmp	L981
L988:
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
	jmp	L980
L987:
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
	jmp	L979
L986:
	movl	_Geom, %edx
	leal	0(,%esi,8), %eax
	subl	%esi, %eax
	movl	40(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L978
	movl	20(%ebp), %eax
	testl	%eax, %eax
	je	L978
	movl	$1, (%esp)
	movl	%esi, %edx
	movl	$68, %eax
	call	_trans_coord_Zmat
	jmp	L978
L985:
	movl	_Geom, %edx
	leal	0(,%esi,8), %eax
	subl	%esi, %eax
	movl	32(%edx,%eax,8), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L977
	movl	16(%ebp), %eax
	testl	%eax, %eax
	je	L977
	movl	$1, (%esp)
	movl	%esi, %edx
	movl	$65, %eax
	call	_trans_coord_Zmat
	jmp	L977
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
	je	L990
	xorl	%ebx, %ebx
	cmpl	%eax, %ebx
	jae	L998
	.p2align 4,,15
L1000:
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
	jb	L1000
L998:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L990
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	jmp	_rafresh_drawing
	.p2align 4,,7
L990:
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
	je	L1008
	cmpb	$65, %dl
	je	L1009
	xorl	%eax, %eax
	cmpb	$68, %dl
	je	L1010
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L1008:
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
	je	L1011
L1007:
	movl	$1, %eax
L1012:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L1009:
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
	jne	L1007
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-20(%ebp), %edx
	movl	%eax, 32(%ebx,%edx)
	movl	$1, %eax
	jmp	L1012
	.p2align 4,,7
L1010:
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
	jne	L1007
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-24(%ebp), %edx
	movl	%eax, 40(%ebx,%edx)
	movl	$1, %eax
	jmp	L1012
L1011:
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-16(%ebp), %edx
	movl	%eax, 24(%ebx,%edx)
	movl	$1, %eax
	jmp	L1012
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
	je	L1013
	xorl	%edi, %edi
	cmpl	_NcentersZmat, %edi
	jae	L1038
	.p2align 4,,15
L1051:
	xorl	%ebx, %ebx
	testl	%edi, %edi
	jne	L1045
	cmpl	$1, %edi
	ja	L1046
L1019:
	cmpl	$2, %edi
	ja	L1047
L1020:
	testl	%ebx, %ebx
	leal	1(%edi), %esi
	je	L1017
	xorl	%ebx, %ebx
	.p2align 4,,15
L1025:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jbe	L1025
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
	jne	L1048
L1026:
	cmpl	$1, %edi
	ja	L1049
L1027:
	cmpl	$2, %edi
	ja	L1050
L1028:
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
L1017:
	movl	%esi, %edi
	cmpl	_NcentersZmat, %edi
	jb	L1051
L1038:
	movl	_NVariables, %ecx
	movl	8(%ebp), %edi
	leal	-1(%ecx), %eax
	cmpl	%edi, %eax
	jbe	L1042
	movl	_Variables, %edx
	leal	(%edi,%edi,2), %eax
	leal	0(,%eax,4), %esi
	.p2align 4,,15
L1034:
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
	ja	L1034
L1042:
	leal	-1(%ecx), %eax
	testl	%eax, %eax
	movl	%eax, _NVariables
	je	L1035
	call	_AllocationVariable
L1036:
	movl	8(%ebp), %edx
	movl	_listv, %eax
	call	_removeFromList
L1013:
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1047:
	movl	%edi, 4(%esp)
	movl	8(%ebp), %eax
	movl	$68, (%esp)
	movl	%eax, 8(%esp)
	call	_ModifyCoord
	addl	%eax, %ebx
	jmp	L1020
L1045:
	movl	%edi, 4(%esp)
	movl	8(%ebp), %eax
	movl	$82, (%esp)
	movl	%eax, 8(%esp)
	call	_ModifyCoord
	cmpl	$1, %edi
	movl	%eax, %ebx
	jbe	L1019
L1046:
	movl	%edi, 4(%esp)
	movl	8(%ebp), %ecx
	movl	$65, (%esp)
	movl	%ecx, 8(%esp)
	call	_ModifyCoord
	addl	%eax, %ebx
	jmp	L1019
L1050:
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
	jmp	L1028
L1049:
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
	jmp	L1027
L1048:
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
	jmp	L1026
L1035:
	call	_freeVariables
	jmp	L1036
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
	jae	L1080
	movl	$0, -40(%ebp)
	movl	_Variables, %esi
	movl	$0, -44(%ebp)
	.p2align 4,,15
L1064:
	movl	-24(%ebp), %edx
	movl	-44(%ebp), %ecx
	movl	$0, (%edx,%edi,4)
	movl	8(%ecx,%esi), %ebx
	testl	%ebx, %ebx
	je	L1055
	xorl	%ebx, %ebx
	cmpl	_NcentersZmat, %ebx
	jb	L1063
	jmp	L1082
	.p2align 4,,7
L1060:
	cmpl	$1, %ebx
	ja	L1089
L1061:
	cmpl	$2, %ebx
	ja	L1090
L1059:
	incl	%ebx
	cmpl	_NcentersZmat, %ebx
	jae	L1091
L1063:
	testl	%ebx, %ebx
	je	L1060
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$82, (%esp)
	call	_ModifyCoord
	cmpl	$1, %ebx
	jbe	L1061
	.p2align 4,,15
L1089:
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$65, (%esp)
	call	_ModifyCoord
	cmpl	$2, %ebx
	jbe	L1059
	.p2align 4,,15
L1090:
	movl	%ebx, 4(%esp)
	incl	%ebx
	movl	%edi, 8(%esp)
	movl	$68, (%esp)
	call	_ModifyCoord
	cmpl	_NcentersZmat, %ebx
	jb	L1063
	.p2align 4,,15
L1091:
	movl	_Variables, %esi
L1082:
	incl	-20(%ebp)
	xorl	%ecx, %ecx
	movl	-24(%ebp), %eax
	movl	-40(%ebp), %edx
	movl	$1, (%eax,%edi,4)
	movl	_NVariables, %eax
	movl	%ecx, 8(%edx,%esi)
L1055:
	addl	$12, -44(%ebp)
	incl	%edi
	addl	$12, -40(%ebp)
	cmpl	%eax, %edi
	jb	L1064
L1080:
	xorl	%edi, %edi
	cmpl	%eax, %edi
	jae	L1084
	movl	_Variables, %esi
	xorl	%ebx, %ebx
	.p2align 4,,15
L1068:
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
	jb	L1068
L1084:
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
	jae	L1086
	movl	$0, -32(%ebp)
	movl	$-12, -36(%ebp)
	jmp	L1073
	.p2align 4,,7
L1071:
	addl	$12, -32(%ebp)
	incl	%edi
	cmpl	-16(%ebp), %edi
	jae	L1086
L1073:
	movl	-24(%ebp), %ecx
	movl	(%ecx,%edi,4), %eax
	testl	%eax, %eax
	jne	L1071
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
	jb	L1073
L1086:
	movl	_listv, %eax
	xorl	%edi, %edi
	call	_clearList
	call	_append_list_variables
	movl	_list, %eax
	call	_clearList
	call	_append_list_geom
	cmpl	_NVariables, %edi
	jae	L1088
	xorl	%ebx, %ebx
	.p2align 4,,15
L1077:
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
	jb	L1077
L1088:
	movl	-28(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_free
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1092
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1092:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_rafresh_drawing
	.section .rdata,"dr"
	.align 8
LC159:
	.long	-1717986918
	.long	1072273817
	.align 8
LC160:
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
	je	L1093
	movl	_InEdit, %ebx
	testl	%ebx, %ebx
	je	L1095
	movl	_LineSelected, %ecx
	testl	%ecx, %ecx
	jle	L1093
L1095:
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
	fmull	LC159
	je	L1102
L1096:
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
	jbe	L1101
	movl	_InEdit, %eax
	testl	%eax, %eax
	je	L1097
	cmpl	$1, _LineSelected
	jle	L1101
L1097:
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
	jbe	L1101
	movl	_InEdit, %esi
	testl	%esi, %esi
	je	L1099
	cmpl	$2, _LineSelected
	jle	L1101
L1099:
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
L1101:
	movl	%ebx, (%esp)
	call	_g_free
L1093:
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L1102:
	fmull	LC160
	jmp	L1096
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
LC162:
	.ascii "Select your atom\0"
LC165:
	.ascii "00\0"
	.align 8
LC163:
	.long	-1717986918
	.long	1071225241
	.align 4
LC164:
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
	movl	$LC162, %ebx
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
	fmull	LC163
	orw	$3072, %dx
	movw	%dx, -16(%ebp)
	fldcw	-16(%ebp)
	fistpl	8(%esp)
	fldcw	-14(%ebp)
	fildl	_ScreenWidth
	fmuls	LC164
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
L1113:
	movl	$0, -28(%ebp)
	movl	-24(%ebp), %ecx
	incl	%ecx
	movl	%ecx, -40(%ebp)
	jmp	L1112
	.p2align 4,,7
L1110:
	movl	%esi, -28(%ebp)
	cmpl	$17, %esi
	ja	L1119
L1112:
	cld
	movl	-28(%ebp), %esi
	movl	$LC165, %edi
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
	je	L1110
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
	movl	$LC149, %edx
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
	jbe	L1112
	.p2align 4,,15
L1119:
	movl	-40(%ebp), %ecx
	cmpl	$8, %ecx
	movl	%ecx, -24(%ebp)
	jbe	L1113
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
	jle	L1121
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
	jne	L1125
	cmpl	$1, _iprogram
	je	L1126
L1124:
	leave
	jmp	_ChangeVariablesUseds
	.p2align 4,,7
L1125:
	call	_rafresh_drawing
	cmpl	$1, _iprogram
	jne	L1124
	.p2align 4,,15
L1126:
	call	_set_spin_of_electrons
	leave
	jmp	_ChangeVariablesUseds
	.p2align 4,,7
L1121:
	call	_freeGeom
	leave
	jmp	_ChangeVariablesUseds
	.section .rdata,"dr"
LC168:
	.ascii "Sorry a Entry text is void !\12\0"
LC167:
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
L1131:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jle	L1131
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
	je	L1127
	cmpb	$0, (%eax)
	je	L1127
	movl	_NcentersZmat, %ecx
	movl	_Geom, %edx
	incl	%ecx
	movl	%ecx, _NcentersZmat
	testl	%edx, %edx
	je	L1200
	movl	%edx, (%esp)
	leal	0(,%ecx,8), %eax
	subl	%ecx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	call	_g_realloc
L1197:
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
	je	L1201
	movl	_Geom, %edi
	leal	0(,%edx,8), %eax
	xorl	%ecx, %ecx
	subl	%edx, %eax
	xorl	%esi, %esi
	movl	%ecx, -36(%edi,%eax,8)
	leal	-1(%edx), %eax
	cmpl	$0, %eax
	jle	L1190
	movl	%edx, -96(%ebp)
	movl	%edx, %ecx
	leal	20(%edi), %ebx
	.p2align 4,,15
L1141:
	leal	0(,%ecx,8), %eax
	subl	%ecx, %eax
	leal	-56(%edi,%eax,8), %edx
	movl	(%ebx), %eax
	cmpl	%eax, 20(%edx)
	jge	L1139
	movl	%eax, 20(%edx)
	movl	-96(%ebp), %ecx
L1139:
	incl	%esi
	leal	-1(%ecx), %eax
	addl	$56, %ebx
	cmpl	%esi, %eax
	jg	L1141
L1183:
	leal	0(,%ecx,8), %eax
	subl	%ecx, %eax
	incl	-36(%edi,%eax,8)
L1136:
	movl	_NcentersZmat, %ecx
	cmpl	$1, %ecx
	ja	L1202
L1142:
	cmpl	$2, %ecx
	seta	%al
	xorl	%edx, %edx
	cmpl	$0, -92(%ebp)
	sete	%dl
	testl	%eax, %edx
	jne	L1203
L1152:
	cmpl	$3, %ecx
	seta	%al
	xorl	%edx, %edx
	cmpl	$0, -92(%ebp)
	sete	%dl
	testl	%eax, %edx
	jne	L1204
L1162:
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
	je	L1172
	movl	%esi, 4(%esp)
	movl	_Entry+48, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
L1198:
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
	je	L1205
	movl	_NcentersZmat, %edx
	decl	%edx
	testl	%edx, %edx
	movl	%edx, _NcentersZmat
	jne	L1206
	xorl	%eax, %eax
L1199:
	movl	%eax, _Geom
L1127:
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1200:
	movl	$56, (%esp)
	call	_g_malloc
	jmp	L1197
L1205:
	movl	$13, (%esp)
	movl	_list, %eax
	leal	-88(%ebp), %edx
	call	_appendToList
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1207
L1175:
	cmpl	$1, _iprogram
	jne	L1127
	call	_set_spin_of_electrons
	jmp	L1127
L1204:
	call	_gtk_entry_get_type
	movl	$9, %ebx
	movl	%eax, %esi
L1166:
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
	jle	L1166
	movl	-52(%ebp), %edx
	testl	%edx, %edx
	je	L1168
	cmpb	$0, (%edx)
	je	L1168
L1167:
	movl	%edx, %eax
	call	_testav
	cmpl	$-1, %eax
	movl	%eax, %ebx
	jle	L1169
	leal	(%eax,%eax,2), %edx
	movl	_Variables, %eax
	movl	$1, %ecx
	movl	%ecx, 8(%eax,%edx,4)
L1169:
	incl	%ebx
	jl	L1208
L1170:
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
	jne	L1209
L1196:
	movl	-52(%ebp), %edx
L1171:
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
	jmp	L1162
L1203:
	call	_gtk_entry_get_type
	movl	$7, %ebx
	movl	%eax, %esi
L1156:
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
	jle	L1156
	movl	-60(%ebp), %edx
	testl	%edx, %edx
	je	L1158
	cmpb	$0, (%edx)
	je	L1158
L1157:
	movl	%edx, %eax
	call	_testav
	cmpl	$-1, %eax
	movl	%eax, %ebx
	jle	L1159
	leal	(%eax,%eax,2), %edx
	movl	_Variables, %eax
	movl	$1, %ecx
	movl	%ecx, 8(%eax,%edx,4)
L1159:
	incl	%ebx
	jl	L1210
L1160:
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
	jne	L1211
L1194:
	movl	-60(%ebp), %edx
L1161:
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
	jmp	L1152
L1202:
	call	_gtk_entry_get_type
	movl	$5, %ebx
	movl	%eax, %esi
L1146:
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
	jle	L1146
	movl	-68(%ebp), %edx
	testl	%edx, %edx
	je	L1148
	cmpb	$0, (%edx)
	je	L1148
L1147:
	movl	%edx, %eax
	call	_testav
	cmpl	$-1, %eax
	movl	%eax, %ebx
	jle	L1149
	leal	(%eax,%eax,2), %edx
	movl	_Variables, %eax
	movl	$1, %ecx
	movl	%ecx, 8(%eax,%edx,4)
L1149:
	incl	%ebx
	jl	L1212
L1150:
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
	jne	L1213
L1192:
	movl	-68(%ebp), %edx
L1151:
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
	jmp	L1142
L1172:
	movl	$LC46, (%esp)
	jmp	L1198
L1201:
	movl	_Geom, %eax
	movl	$0, 20(%eax)
	jmp	L1136
L1206:
	leal	0(,%edx,8), %eax
	subl	%edx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	movl	_Geom, %eax
	movl	%eax, (%esp)
	call	_g_realloc
	jmp	L1199
L1148:
	movl	$LC168, (%esp)
	movl	$1, %edi
	movl	$LC167, %esi
	movl	%edi, 8(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, _DestroyDialog
	movl	-68(%ebp), %edx
	movl	$1, -92(%ebp)
	jmp	L1147
L1158:
	movl	$LC168, (%esp)
	movl	$1, %edi
	movl	$LC167, %esi
	movl	%edi, 8(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, _DestroyDialog
	movl	-60(%ebp), %edx
	movl	$1, -92(%ebp)
	jmp	L1157
L1168:
	movl	$LC168, (%esp)
	movl	$1, %edi
	movl	$LC167, %esi
	movl	%edi, 8(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, _DestroyDialog
	movl	-52(%ebp), %edx
	movl	$1, -92(%ebp)
	jmp	L1167
L1209:
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1196
	movl	$LC51, (%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -52(%ebp)
	movl	%eax, %edx
	jmp	L1171
L1211:
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1194
	movl	$LC51, (%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -60(%ebp)
	movl	%eax, %edx
	jmp	L1161
L1213:
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1192
	movl	$LC51, (%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	movl	%eax, %edx
	jmp	L1151
L1190:
	movl	_NcentersZmat, %ecx
	jmp	L1183
L1208:
	movl	$LC90, (%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC167, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	movl	$1, -92(%ebp)
	xorl	%eax, %eax
	movl	%eax, _DestroyDialog
	jmp	L1170
L1207:
	call	_rafresh_drawing
	jmp	L1175
L1210:
	movl	$LC90, (%esp)
	movl	-60(%ebp), %eax
	movl	$1, %edi
	movl	$LC167, %esi
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
	jmp	L1160
L1212:
	movl	$LC90, (%esp)
	movl	-68(%ebp), %eax
	movl	$1, %edi
	movl	$LC167, %esi
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
	jmp	L1150
	.section .rdata,"dr"
LC169:
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
L1218:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, -88(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$12, %ebx
	jle	L1218
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
	js	L1292
L1219:
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
	je	L1220
	cmpb	$0, (%eax)
	je	L1220
	movl	%edx, -156(%ebp)
	testl	%edx, %edx
	js	L1293
L1221:
	movl	-156(%ebp), %eax
	movl	$LC45, (%esp)
	incl	%eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -88(%ebp)
	movl	-156(%ebp), %eax
	testl	%eax, %eax
	js	L1222
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
	je	L1294
L1223:
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
	jne	L1222
	movl	_NcentersZmat, %edi
	movl	$-1, %esi
	xorl	%ebx, %ebx
	movl	%esi, -132(%ebp)
	cmpl	$0, %edi
	jle	L1226
	movl	_Geom, %eax
	xorl	%esi, %esi
	movl	%eax, -172(%ebp)
L1229:
	cmpl	%ebx, -156(%ebp)
	je	L1227
	movl	-172(%ebp), %edx
	movl	16(%esi,%edx), %eax
	movl	%eax, 4(%esp)
	movl	-136(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L1285
L1227:
	incl	%ebx
	addl	$56, %esi
	cmpl	%ebx, %edi
	jg	L1229
L1226:
	movl	-132(%ebp), %eax
	cmpl	$-1, %eax
	jne	L1222
	cmpl	$0, %edi
	jle	L1275
	movl	_Geom, %ecx
	movl	%edi, %ebx
	addl	$20, %ecx
L1235:
	movl	(%ecx), %edx
	cmpl	%edx, %eax
	jge	L1233
	movl	%edx, -132(%ebp)
	movl	%edx, %eax
L1233:
	addl	$56, %ecx
	decl	%ebx
	jne	L1235
L1275:
	incl	%eax
	movl	%eax, -132(%ebp)
L1222:
	movl	-156(%ebp), %ebx
	testl	%ebx, %ebx
	jle	L1236
	call	_gtk_entry_get_type
	movl	$5, %ebx
	movl	%eax, %esi
L1241:
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
	jl	L1286
	incl	%ebx
	cmpl	$6, %ebx
	jle	L1241
L1238:
	movl	-68(%ebp), %eax
	testl	%eax, %eax
	je	L1263
	cmpb	$0, (%eax)
	jne	L1242
L1263:
	movl	$LC168, (%esp)
	movl	$1, %ebx
	movl	$LC167, %ecx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	call	_MessageGeom
L1290:
	xorl	%eax, %eax
	movl	%eax, _DestroyDialog
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1220:
	movl	$LC169, (%esp)
	movl	$1, %esi
	movl	$LC167, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
L1270:
	call	_ChangeVariablesUseds
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1292:
	movl	_LineSelectedOld, %eax
	movl	%eax, -156(%ebp)
	jmp	L1219
L1294:
	movl	$1, %eax
	movl	%eax, -168(%ebp)
	jmp	L1223
L1242:
	movl	-164(%ebp), %edx
	testl	%edx, %edx
	jne	L1291
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1295
L1280:
	movl	-68(%ebp), %eax
L1245:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -128(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -124(%ebp)
L1236:
	cmpl	$1, -156(%ebp)
	jg	L1296
L1246:
	cmpl	$2, -156(%ebp)
	jle	L1256
	call	_gtk_entry_get_type
	movl	$9, %ebx
	movl	%eax, %esi
L1261:
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
	jl	L1288
	incl	%ebx
	cmpl	$10, %ebx
	jle	L1261
L1258:
	movl	-52(%ebp), %eax
	testl	%eax, %eax
	je	L1263
	cmpb	$0, (%eax)
	je	L1263
	movl	-164(%ebp), %edx
	testl	%edx, %edx
	je	L1264
L1291:
	movl	-160(%ebp), %edx
	movl	-88(%ebp,%edx,4), %eax
	movl	$LC90, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC167, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	jmp	L1290
L1264:
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1297
L1284:
	movl	-52(%ebp), %eax
L1265:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -112(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -108(%ebp)
L1256:
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
	je	L1266
	movl	%ebx, 4(%esp)
	movl	_Entry+48, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
L1289:
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
	jne	L1298
L1268:
	cmpl	$1, _iprogram
	jne	L1270
	call	_set_spin_of_electrons
	jmp	L1270
L1293:
	movl	_LineSelectedOld, %edx
	movl	%edx, -156(%ebp)
	jmp	L1221
L1296:
	call	_gtk_entry_get_type
	movl	$7, %ebx
	movl	%eax, %esi
L1251:
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
	jl	L1287
	incl	%ebx
	cmpl	$8, %ebx
	jle	L1251
L1248:
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	je	L1263
	cmpb	$0, (%eax)
	je	L1263
	movl	-164(%ebp), %edi
	testl	%edi, %edi
	jne	L1291
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1299
L1282:
	movl	-60(%ebp), %eax
L1255:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -120(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -116(%ebp)
	jmp	L1246
L1295:
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1280
	movl	-68(%ebp), %eax
	movl	$LC51, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -68(%ebp)
	jmp	L1245
L1299:
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1282
	movl	-60(%ebp), %eax
	movl	$LC51, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -60(%ebp)
	jmp	L1255
	.p2align 4,,7
L1285:
	movl	-172(%ebp), %edx
	movl	20(%esi,%edx), %eax
	movl	%eax, -132(%ebp)
	jmp	L1226
L1298:
	call	_rafresh_drawing
	jmp	L1268
L1266:
	movl	$LC46, (%esp)
	jmp	L1289
L1286:
	movl	%ebx, -160(%ebp)
	movl	$1, %ecx
	movl	%ecx, -164(%ebp)
	jmp	L1238
L1297:
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1284
	movl	-52(%ebp), %eax
	movl	$LC51, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -52(%ebp)
	jmp	L1265
L1288:
	movl	%ebx, -160(%ebp)
	movl	$1, %esi
	movl	%esi, -164(%ebp)
	jmp	L1258
L1287:
	movl	%ebx, -160(%ebp)
	movl	$1, %eax
	movl	%eax, -164(%ebp)
	jmp	L1248
	.section .rdata,"dr"
LC170:
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
	jae	L1306
	xorl	%esi, %esi
	.p2align 4,,15
L1304:
	movl	_Variables, %eax
	movl	(%esi,%eax), %eax
	addl	$12, %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%edi,%ebx,4)
	incl	%ebx
	cmpl	_NVariables, %ebx
	jb	L1304
L1306:
	movl	$LC170, (%esp)
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
	jne	L1311
L1313:
	movl	%esi, (%esp)
	call	_g_free
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L1311:
	movl	(%esi,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	movl	_NVariables, %eax
	incl	%eax
	cmpl	%ebx, %eax
	jbe	L1313
	movl	(%esi,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	movl	_NVariables, %eax
	incl	%eax
	cmpl	%ebx, %eax
	ja	L1311
	jmp	L1313
	.section .rdata,"dr"
LC171:
	.ascii " Name : \0"
LC172:
	.ascii " Value : \0"
LC175:
	.ascii "Edit Variable\0"
LC176:
	.ascii " Edit variable \0"
LC177:
	.ascii "frame\0"
LC173:
	.ascii "Create variable before \12\0"
LC174:
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
	movl	$LC171, -40(%ebp)
	movl	$LC172, -36(%ebp)
	testl	%edi, %edi
	js	L1321
	call	_gtk_dialog_new
	movl	%eax, -24(%ebp)
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC175, %ecx
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
	movl	$LC176, %eax
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
	movl	$LC145, %ecx
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
	movl	$LC177, %ecx
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
	jne	L1322
L1319:
	movl	-28(%ebp), %edx
	movl	$LC172, %edi
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
	movl	$LC151, %esi
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
	movl	$LC149, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	xorl	%ebx, %ebx
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	movl	$LC152, %edi
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
	movl	$LC149, %edx
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
	movl	$LC149, %edx
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
L1321:
	movl	_NVariables, %eax
	testl	%eax, %eax
	jne	L1317
	movl	$LC173, (%esp)
	movl	$1, %eax
	movl	$LC167, %edi
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	call	_MessageGeom
L1326:
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1317:
	movl	$LC174, (%esp)
	movl	$1, %esi
	movl	$LC167, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
	jmp	L1326
	.p2align 4,,7
L1322:
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	_EntryV, %eax
	movl	%eax, (%esp)
	call	_gtk_editable_set_editable
	jmp	L1319
	.section .rdata,"dr"
LC183:
	.ascii "Delete Variable\0"
LC184:
	.ascii " Delete Variable \0"
LC186:
	.ascii " Question \0"
	.align 4
LC185:
	.ascii "\12 Are you sure to delete the variable\12 %s\12?\0"
LC187:
	.ascii "No\0"
LC188:
	.ascii "Yes\0"
LC179:
	.ascii "New Variable\0"
LC180:
	.ascii " New Variable \0"
	.align 4
LC189:
	.ascii "Tansform all variables to constants\0"
	.align 4
LC190:
	.ascii "\12 Are you sure to transform\12 all variables to constants? \12\0"
LC181:
	.ascii " No Variable to delet !\0"
	.align 4
LC182:
	.ascii "Sorry\12 %s \12 is used in Geometry\0"
LC191:
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
	je	L1350
	cld
	movl	$LC3, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	je	L1351
	cld
	movl	$LC6, %edi
	movl	$7, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1333
	movl	_NVariables, %edx
	testl	%edx, %edx
	je	L1352
	movl	_LineSelectedV, %eax
	testl	%eax, %eax
	js	L1353
L1336:
	movl	_Variables, %edx
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	8(%eax,%edx), %ecx
	testl	%ecx, %ecx
	jne	L1354
	call	_gtk_dialog_new
	movl	%eax, %edi
	call	_gtk_window_get_type
	movl	%eax, -88(%ebp)
	movl	$LC183, %ebx
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
	movl	$LC184, %eax
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
	movl	$LC145, %ecx
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
	movl	$LC177, %ecx
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
	movl	$LC186, %esi
	xorl	%ebx, %ebx
	movl	%edi, (%esp)
	call	_gtk_widget_realize
	movl	_LineSelectedV, %eax
	movl	_Variables, %edx
	leal	(%eax,%eax,2), %eax
	movl	(%edx,%eax,4), %eax
	movl	$LC185, (%esp)
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
	movl	$LC187, %esi
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
	movl	$LC149, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 20(%esp)
	xorl	%ecx, %ecx
	movl	$LC188, %ebx
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
	movl	$LC149, %edx
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
	movl	$LC149, %edx
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	-104(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-80(%ebp), %eax
L1348:
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
L1351:
	movl	$LC171, -40(%ebp)
	movl	$80, %ebx
	movl	$LC172, -36(%ebp)
	call	_gtk_dialog_new
	movl	%eax, %edi
	call	_gtk_window_get_type
	movl	%eax, -44(%ebp)
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC179, %ecx
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
	movl	$LC180, %eax
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
	movl	$LC145, %ecx
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
	movl	$LC177, %ecx
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
	movl	$LC172, %eax
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
	movl	$LC151, %eax
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
	movl	$LC149, %esi
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
	movl	$LC152, %ecx
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
	movl	$LC149, %edx
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
	movl	$LC149, %edx
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
L1350:
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_DialogueEditV
	.p2align 4,,7
L1333:
	cld
	movl	$LC9, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1339
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	je	L1355
	call	_gtk_dialog_new
	movl	%eax, %edi
	call	_gtk_window_get_type
	movl	%eax, -132(%ebp)
	movl	$LC189, %ebx
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
	movl	$LC186, %eax
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
	movl	$LC145, %esi
	movl	%ecx, 12(%esp)
	movl	%ebx, 16(%esp)
	movl	$LC186, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%edi, (%esp)
	call	_gtk_widget_realize
	movl	%ebx, 8(%esp)
	movl	$LC190, %ecx
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
	movl	$LC177, %ecx
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
	movl	$LC187, %esi
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
	movl	$LC149, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 20(%esp)
	xorl	%ecx, %ecx
	movl	$LC188, %ebx
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
	movl	$LC149, %edx
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
	movl	$LC149, %edx
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	-148(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-124(%ebp), %eax
	jmp	L1348
L1339:
	cld
	movl	$LC12, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1327
	movl	_LineSelectedV, %eax
	testl	%eax, %eax
	js	L1356
	movl	%eax, (%esp)
	call	_OneVariableToConst
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L1327
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_rafresh_drawing
L1355:
	movl	$LC141, (%esp)
	movl	$1, %edi
	movl	$LC167, %esi
L1359:
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
L1327:
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1352:
	movl	$LC181, (%esp)
	movl	$1, %esi
	movl	$LC167, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
	jmp	L1327
L1354:
	movl	(%eax,%edx), %eax
	movl	$1, %edi
	movl	$LC182, (%esp)
	movl	$LC167, %esi
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	jmp	L1359
L1353:
	leal	-1(%edx), %eax
	movl	%eax, _LineSelectedV
	jmp	L1336
L1356:
	movl	$LC191, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC167, %eax
	movl	%eax, 4(%esp)
	call	_MessageGeom
	jmp	L1327
	.section .rdata,"dr"
LC193:
	.ascii "Atom Symbol : \0"
LC194:
	.ascii "MM Type : \0"
LC195:
	.ascii "PDB Type : \0"
LC196:
	.ascii "Residue : \0"
LC197:
	.ascii "R : \0"
LC198:
	.ascii "Center : \0"
LC199:
	.ascii "Angle : \0"
LC200:
	.ascii "Dihedral : \0"
LC201:
	.ascii "Charge : \0"
LC202:
	.ascii "Layer : \0"
	.data
	.align 4
LC203:
	.long	LC46
	.long	LC193
	.long	LC194
	.long	LC195
	.long	LC196
	.long	LC197
	.long	LC198
	.long	LC199
	.long	LC198
	.long	LC200
	.long	LC198
	.long	LC201
	.long	LC202
	.section .rdata,"dr"
LC206:
	.ascii " Edit center\0"
LC207:
	.ascii " Edit Center \0"
LC208:
	.ascii " Set \0"
LC204:
	.ascii "Create center before \12\0"
LC205:
	.ascii "Please Select your center \12\0"
	.align 8
LC209:
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
	movl	$LC203, %esi
	rep
	movsl
	movl	$0, -116(%ebp)
	testl	%eax, %eax
	movl	%eax, -124(%ebp)
	jl	L1388
	jle	L1364
	movl	-124(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -116(%ebp)
	movl	-124(%ebp), %ebx
	testl	%ebx, %ebx
	jle	L1364
	movl	$1, %esi
	.p2align 4,,15
L1368:
	movl	%esi, 4(%esp)
	movl	%esi, %ebx
	movl	$LC45, (%esp)
	call	_g_strdup_printf
	movl	-116(%ebp), %edx
	movl	%eax, -4(%edx,%esi,4)
	incl	%esi
	cmpl	-124(%ebp), %ebx
	jl	L1368
L1364:
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
	movl	$LC206, %ecx
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
	movl	$LC207, %eax
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
	movl	$LC145, %edi
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
	movl	$LC177, %edi
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
	movl	$LC208, (%esp)
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
	movl	$LC149, %edx
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
	je	L1369
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
L1383:
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
	je	L1371
	movl	-92(%ebp), %edx
	movl	%esi, %eax
	call	_freeList
L1371:
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
	je	L1372
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
L1384:
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
	je	L1374
	movl	-96(%ebp), %edx
	movl	-128(%ebp), %eax
	call	_freeList
L1374:
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
	jne	L1375
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	$LC170, %edx
L1387:
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	call	_get_list_variables
	movl	%eax, -120(%ebp)
	movl	-124(%ebp), %edi
	testl	%edi, %edi
	jle	L1377
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
	fmull	LC209
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
L1377:
	cmpl	$1, -124(%ebp)
	jg	L1389
L1378:
	cmpl	$2, -124(%ebp)
	jg	L1390
L1379:
	movl	-116(%ebp), %ebx
	testl	%ebx, %ebx
	je	L1380
	movl	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L1380:
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
	movl	$LC101, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	$LC102, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, 8(%edx)
	movl	$LC103, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, 12(%edx)
	movl	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	cmpl	$3, _iprogram
	movl	%eax, %edi
	je	L1381
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
L1381:
	movl	-104(%ebp), %eax
	movl	$LC151, %esi
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
	movl	$LC149, %edx
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
	movl	$LC152, %eax
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
	movl	$LC149, %edx
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
	movl	$LC149, %ebx
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
L1375:
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_Geom, %edx
	movl	16(%ebx,%edx), %edx
	jmp	L1387
	.p2align 4,,7
L1372:
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
	jmp	L1384
	.p2align 4,,7
L1369:
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
	jmp	L1383
L1390:
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
	fmull	LC209
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
	jmp	L1379
L1389:
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
	fmull	LC209
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
	jmp	L1378
L1388:
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	jne	L1362
	movl	$LC204, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC167, %eax
	movl	%eax, 4(%esp)
	call	_MessageGeom
L1394:
	addl	$156, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1362:
	movl	$LC205, (%esp)
	movl	$1, %edi
	movl	$LC167, %esi
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
	jmp	L1394
	.section .rdata,"dr"
LC211:
	.ascii "Geom\0"
LC212:
	.ascii "%s/Edit\0"
LC213:
	.ascii "%s/Delete\0"
LC214:
	.ascii "%s/One\0"
LC215:
	.ascii "%s/All\0"
LC216:
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
	je	L1395
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_bin_window
	cmpl	%eax, 4(%esi)
	je	L1449
L1397:
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
	jne	L1450
L1398:
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
	movl	$LC111, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	movl	$LC211, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1400
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
L1401:
	movl	_ZoneDessin, %ecx
	testl	%ecx, %ecx
	jne	L1451
	movl	(%esi), %eax
	cmpl	$5, %eax
	je	L1452
L1458:
	cmpl	$4, %eax
	je	L1453
L1406:
	movl	8(%ebp), %edx
	movl	(%edx), %eax
	movl	%esi, 4(%esp)
	movl	%edx, (%esp)
	call	*176(%eax)
L1395:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1450:
	movl	-16(%ebp), %edi
	testl	%edi, %edi
	je	L1398
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
	jmp	L1398
	.p2align 4,,7
L1451:
	call	_rafresh_drawing
	movl	(%esi), %eax
	cmpl	$5, %eax
	jne	L1458
	.p2align 4,,15
L1452:
	movl	%ebx, (%esp)
	movl	$LC211, %edx
	movl	%edx, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1404
	call	_DialogueEdit
	movl	(%esi), %eax
L1460:
	cmpl	$4, %eax
	jne	L1406
	.p2align 4,,15
L1453:
	cmpl	$3, 40(%esi)
	jne	L1406
	testl	%ebx, %ebx
	je	L1425
	movl	%ebx, 4(%esp)
	movl	$LC212, (%esp)
	call	_g_strdup_printf
	movl	%eax, -28(%ebp)
	movl	%ebx, 4(%esp)
	movl	$LC213, (%esp)
	call	_g_strdup_printf
	movl	%eax, -32(%ebp)
	movl	%ebx, 4(%esp)
	movl	$LC214, (%esp)
	call	_g_strdup_printf
	movl	%eax, -36(%ebp)
	movl	%ebx, 4(%esp)
	movl	$LC215, (%esp)
	call	_g_strdup_printf
	movl	%eax, -40(%ebp)
	movl	-28(%ebp), %eax
	testl	%eax, %eax
	je	L1411
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	js	L1454
	movl	$1, (%esp)
L1440:
	movl	-28(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
L1411:
	movl	-36(%ebp), %eax
	testl	%eax, %eax
	je	L1414
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	js	L1455
	movl	$1, (%esp)
L1441:
	movl	-36(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L1414:
	movl	-32(%ebp), %eax
	testl	%eax, %eax
	je	L1417
	movl	%ebx, (%esp)
	movl	$LC211, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1418
	movl	_NcentersZmat, %ecx
	testl	%ecx, %ecx
L1446:
	jne	L1423
	movl	$0, (%esp)
L1442:
	movl	-32(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
L1421:
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
L1417:
	movl	-40(%ebp), %eax
	testl	%eax, %eax
	je	L1425
	movl	%ebx, (%esp)
	movl	$LC211, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1426
	movl	_NcentersZmat, %eax
L1448:
	testl	%eax, %eax
	jne	L1431
	movl	$0, (%esp)
L1443:
	movl	-40(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
L1429:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L1425:
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
	je	L1434
	movl	(%ebx), %edx
	testl	%edx, %edx
	je	L1434
	cmpl	%eax, (%edx)
	je	L1437
L1434:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L1406
L1437:
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
	jmp	L1406
	.p2align 4,,7
L1400:
	movl	-24(%ebp), %eax
	movl	%eax, _LineSelectedV
	movl	%eax, _LineSelectedOld
	jmp	L1401
L1449:
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
	jne	L1397
	movl	%ebx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_selection
	movl	%eax, (%esp)
	call	_gtk_tree_selection_unselect_all
	jmp	L1397
L1404:
	call	_DialogueEditV
	movl	(%esi), %eax
	jmp	L1460
L1431:
	movl	$1, (%esp)
	jmp	L1443
L1423:
	movl	$1, (%esp)
	jmp	L1442
L1454:
	movl	$0, (%esp)
	jmp	L1440
L1455:
	movl	$0, (%esp)
	jmp	L1441
L1426:
	movl	%ebx, (%esp)
	movl	$LC216, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1429
	movl	_NVariables, %eax
	jmp	L1448
L1418:
	movl	%ebx, (%esp)
	movl	$LC216, %edx
	movl	%edx, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1421
	movl	_NVariables, %eax
	testl	%eax, %eax
	jmp	L1446
	.section .rdata,"dr"
LC218:
	.ascii "New Center\0"
LC219:
	.ascii " New Center \0"
LC220:
	.ascii "H\0"
LC221:
	.ascii "UNK\0"
LC223:
	.ascii "0.0\0"
	.align 8
LC222:
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
	movl	$LC203, %esi
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
	je	L1485
	movl	$1, %esi
	.p2align 4,,15
L1465:
	movl	%esi, 4(%esp)
	movl	%esi, %ebx
	movl	$LC45, (%esp)
	call	_g_strdup_printf
	movl	-116(%ebp), %edx
	movl	%eax, -4(%edx,%esi,4)
	incl	%esi
	cmpl	_NcentersZmat, %ebx
	jb	L1465
L1485:
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
	movl	$LC218, %ecx
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
	movl	$LC219, %eax
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
	movl	$LC145, %edx
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
	movl	$LC177, %edx
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
	jne	L1466
	call	_gtk_entry_get_type
	movl	%ebx, (%esp)
	movl	$LC220, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
L1486:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	movl	_Entry+4, %eax
	xorl	%edi, %edi
	movl	$5, %ebx
	movl	%edi, 4(%esp)
	movl	$80, %edi
	movl	%eax, (%esp)
	call	_gtk_editable_set_editable
	movl	$LC208, (%esp)
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
	movl	$LC149, %edx
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
	je	L1468
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
L1487:
	movl	%eax, _Entry+8
	testl	%edi, %edi
	movl	%eax, %ebx
	je	L1470
	movl	-92(%ebp), %edx
	movl	%edi, %eax
	call	_freeList
	movl	_Entry+8, %ebx
L1470:
	movl	_NcentersZmat, %esi
	testl	%esi, %esi
	jne	L1471
	call	_gtk_entry_get_type
	movl	%ebx, (%esp)
	movl	$LC220, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
L1488:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	movl	-112(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	movl	$0, -96(%ebp)
	movl	%eax, %esi
	leal	-96(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC221, (%esp)
	call	_getListPDBTypes
	movl	-96(%ebp), %edx
	movl	%eax, %edi
	testl	%edx, %edx
	je	L1473
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
L1489:
	movl	%eax, _Entry+12
	movl	_NcentersZmat, %esi
	movl	%eax, %ebx
	testl	%esi, %esi
	jne	L1475
	call	_gtk_entry_get_type
	movl	%ebx, (%esp)
	movl	$LC220, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
L1490:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	testl	%edi, %edi
	je	L1477
	movl	-96(%ebp), %edx
	movl	%edi, %eax
	call	_freeList
L1477:
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
	jne	L1478
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	movl	$LC170, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	call	_get_list_variables
	movl	%eax, %edi
	movl	_NcentersZmat, %eax
	testl	%eax, %eax
	jne	L1492
L1496:
	cmpl	$1, %eax
	ja	L1493
L1497:
	cmpl	$2, %eax
	ja	L1494
L1482:
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
	movl	$LC223, %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	$16, (%esp)
	call	_g_malloc
	movl	%eax, -116(%ebp)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	$LC101, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	$LC102, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %ecx
	movl	%eax, 8(%ecx)
	movl	$LC103, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	-112(%ebp), %ecx
	movl	%eax, 12(%edx)
	movl	%ecx, (%esp)
	call	_create_hbox_false
	cmpl	$3, _iprogram
	movl	%eax, %esi
	je	L1483
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
L1483:
	movl	-104(%ebp), %edx
	movl	$LC151, %esi
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
	movl	$LC149, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	movl	$LC152, %ebx
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
	movl	$LC149, %ebx
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
	movl	$LC149, %ecx
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
L1478:
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
	je	L1496
L1492:
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
	fmull	LC222
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
	jbe	L1497
L1493:
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
	fmull	LC222
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
	jbe	L1482
L1494:
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
	fmull	LC222
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
	jmp	L1482
L1475:
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
	jmp	L1490
L1473:
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
	jmp	L1489
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
	movl	-48(%edx), %edx
	movl	%edx, 4(%esp)
	jmp	L1488
L1468:
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
	jmp	L1487
L1466:
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
	jmp	L1486
	.p2align 4,,15
.globl _put_geom_in_list
	.def	_put_geom_in_list;	.scl	2;	.type	32;	.endef
_put_geom_in_list:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	_Geom, %eax
	testl	%eax, %eax
	jne	L1502
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1503
L1500:
	cmpl	$1, _iprogram
	je	L1504
L1498:
	leave
	ret
	.p2align 4,,7
L1502:
	call	_append_list_geom
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L1500
	.p2align 4,,15
L1503:
	call	_rafresh_drawing
	cmpl	$1, _iprogram
	jne	L1498
	.p2align 4,,15
L1504:
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
L1514:
	xorl	%esi, %esi
	.p2align 4,,15
L1513:
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
	je	L1519
	movl	%ebx, (%esp)
	incl	%esi
	call	_g_free
	cmpl	$17, %esi
	jle	L1513
	incl	-16(%ebp)
	cmpl	$9, -16(%ebp)
	jle	L1514
	movl	%edi, (%esp)
	call	_g_free
	movl	$1, %eax
	jmp	L1505
L1519:
	movl	%ebx, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	xorl	%eax, %eax
L1505:
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
	jae	L1540
	movl	$56, %esi
	.p2align 4,,15
L1527:
	movl	_Geom, %eax
	movl	24(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1523
	movl	8(%ebp), %eax
	testl	%eax, %eax
	je	L1525
	movl	_Geom, %ebx
	movl	24(%esi,%ebx), %eax
	movl	%eax, (%esp)
	call	_bohr_to_ang
L1546:
	movl	%eax, 24(%esi,%ebx)
L1523:
	incl	-16(%ebp)
	addl	$56, %esi
	movl	_NcentersZmat, %edi
	cmpl	%edi, -16(%ebp)
	jb	L1527
L1540:
	movl	$0, -16(%ebp)
	movl	_NVariables, %eax
	cmpl	%eax, -16(%ebp)
	movl	$0, -32(%ebp)
	movl	%eax, -24(%ebp)
	jae	L1542
	.p2align 4,,15
L1538:
	movl	$1, %esi
	cmpl	%edi, %esi
	jae	L1532
	movl	_Geom, %edx
	movl	$56, %ebx
	movl	_Variables, %ecx
	movl	%edx, -20(%ebp)
	movl	%ecx, -28(%ebp)
	.p2align 4,,15
L1537:
	movl	-32(%ebp), %edx
	movl	-28(%ebp), %ecx
	movl	(%edx,%ecx), %eax
	movl	-20(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	24(%ebx,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L1547
	incl	%esi
	addl	$56, %ebx
	cmpl	%edi, %esi
	jb	L1537
L1532:
	incl	-16(%ebp)
	movl	-24(%ebp), %eax
	addl	$12, -32(%ebp)
	cmpl	%eax, -16(%ebp)
	jae	L1542
	movl	_NcentersZmat, %edi
	jmp	L1538
L1525:
	movl	_Geom, %ebx
	movl	24(%esi,%ebx), %eax
	movl	%eax, (%esp)
	call	_ang_to_bohr
	jmp	L1546
L1542:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1547:
	movl	8(%ebp), %eax
	testl	%eax, %eax
	jne	L1545
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
	jmp	L1532
L1545:
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
	jmp	L1532
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
	jle	L1549
	movsbl	(%esi),%eax
	movl	%eax, (%esp)
	call	_toupper
	movb	%al, (%esi)
L1549:
	movl	$1, %ebx
	cmpl	%edi, %ebx
	jge	L1548
	.p2align 4,,15
L1562:
	movsbl	(%ebx,%esi),%edx
	movl	__imp____mb_cur_max, %eax
	cmpl	$1, (%eax)
	jne	L1554
	movl	__imp___pctype, %eax
	movl	(%eax), %eax
	movzwl	(%eax,%edx,2), %eax
	andl	$4, %eax
	testl	%eax, %eax
	jne	L1561
L1553:
	movsbl	(%ebx,%esi),%eax
	movl	%eax, (%esp)
	call	_tolower
	movb	%al, (%ebx,%esi)
	incl	%ebx
	cmpl	%edi, %ebx
	jl	L1562
L1548:
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1554:
	movl	%edx, (%esp)
	movl	$4, %eax
	movl	%eax, 4(%esp)
	call	__isctype
	testl	%eax, %eax
	je	L1553
L1561:
	movb	$0, (%ebx,%esi)
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC225:
	.ascii "r\0"
LC227:
	.ascii "ZMAT\0"
LC228:
	.ascii "END\0"
LC229:
	.ascii "BASIS\0"
	.align 4
LC230:
	.ascii "Sorry, I cannot read the Z-Matrix from the  %s file\0"
LC231:
	.ascii "MATRIX\0"
LC232:
	.ascii "VARIABLE\0"
LC235:
	.ascii "%s %s %s %s %s %s %s \0"
LC237:
	.ascii "CHARGE\0"
LC238:
	.ascii "ZSPIN\0"
LC233:
	.ascii "%s %s %s \0"
LC234:
	.ascii "%s %s %s %s %s\0"
LC226:
	.ascii "Sorry, I cannot open %s file\0"
	.align 4
LC236:
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
	movl	$LC225, %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_FOpen
	testl	%eax, %eax
	movl	%eax, %esi
	je	L1630
	xorl	%ebx, %ebx
	testb	$16, 12(%eax)
	jne	L1618
	leal	-1080(%ebp), %edi
	.p2align 4,,15
L1571:
	movl	%esi, 8(%esp)
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_fgets
	testl	%eax, %eax
	je	L1618
	movl	%edi, (%esp)
	call	_g_strup
	movl	%edi, (%esp)
	movl	$LC227, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	movl	%edi, (%esp)
	cmpl	$1, %eax
	movl	$LC228, %eax
	movl	%eax, 4(%esp)
	sbbl	$-1, %ebx
	call	_strstr
	testl	%eax, %eax
	je	L1565
	movl	%edi, (%esp)
	movl	$LC229, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	jne	L1631
L1565:
	testb	$16, 12(%esi)
	je	L1571
L1618:
	movl	8(%ebp), %eax
	leal	-3128(%ebp), %ebx
	movl	%eax, 8(%esp)
	movl	$LC230, %eax
	movl	%eax, 4(%esp)
L1627:
	movl	%ebx, (%esp)
	movl	$1, %edi
	movl	$LC48, %esi
	call	_sprintf
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
L1623:
	call	_MessageGeom
	movl	$-1, %eax
L1563:
	addl	$4204, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1631:
	testl	%ebx, %ebx
	jle	L1618
	movl	$1, %ebx
	movl	%ebx, -4156(%ebp)
	xorl	%ebx, %ebx
	.p2align 4,,15
L1576:
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, -56(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$6, %ebx
	jle	L1576
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
	movl	$LC100, %edx
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	_sscanf
	movl	%eax, %ebx
	decl	%ebx
	je	L1632
	xorl	%eax, %eax
	movl	%eax, -4156(%ebp)
	movl	$-1, %eax
	movl	%eax, -4164(%ebp)
	movl	-4160(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	xorl	%eax, %eax
	movl	%eax, -4160(%ebp)
L1629:
	movl	12(%esi), %eax
	xorl	%edx, %edx
	shrl	$4, %eax
	xorl	$1, %eax
	cmpl	$0, -4156(%ebp)
	setne	%dl
	testl	%edx, %eax
	je	L1580
L1634:
	movl	%esi, 8(%esp)
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_fgets
	movl	%edi, (%esp)
	call	_g_strup
	movl	%edi, (%esp)
	movl	$LC228, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1581
	movl	%edi, (%esp)
	movl	$LC231, %ebx
	movl	%ebx, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	jne	L1580
L1581:
	movl	%edi, (%esp)
	movl	$LC232, %ecx
	movl	%ecx, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	jne	L1580
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
	je	L1584
	cmpl	$3, -4164(%ebp)
	je	L1587
	movl	%edi, (%esp)
	movl	-32(%ebp), %eax
	movl	$LC235, %ebx
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
	je	L1633
L1591:
	decl	-4164(%ebp)
	movl	-4164(%ebp), %eax
	movl	-4164(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	movl	-4160(%ebp), %eax
	movl	%eax, (%esp)
L1624:
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
	jne	L1634
L1580:
	xorl	%ebx, %ebx
	.p2align 4,,15
L1597:
	movl	-56(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$6, %ebx
	jle	L1597
	movl	-4156(%ebp), %ecx
	movl	-4164(%ebp), %edx
	testl	%ecx, %ecx
	sete	%al
	testl	%edx, %edx
	setle	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L1635
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
	jne	L1602
	leal	-4152(%ebp), %ebx
L1605:
	movl	%esi, 8(%esp)
	movl	$1024, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, (%esp)
	call	_fgets
	testl	%eax, %eax
	je	L1602
	movl	%ebx, (%esp)
	call	_g_strup
	movl	%ebx, (%esp)
	movl	$LC237, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1603
	movl	%ebx, (%esp)
	movl	$61, %eax
	movl	%eax, 4(%esp)
	call	_strchr
	testl	%eax, %eax
	je	L1603
	incl	%eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, _TotalCharges
L1603:
	movl	%ebx, (%esp)
	movl	$LC238, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1599
	movl	%ebx, (%esp)
	movl	$61, %eax
	movl	%eax, 4(%esp)
	call	_strchr
	testl	%eax, %eax
	je	L1599
	incl	%eax
	movl	%eax, (%esp)
	call	_atoi
	incl	%eax
	movl	%eax, _SpinMultiplicities
L1599:
	testb	$16, 12(%esi)
	je	L1605
L1602:
	movl	%esi, (%esp)
	call	_fclose
	movl	_Geom, %eax
	testl	%eax, %eax
	jne	L1636
L1606:
	movl	_Variables, %eax
	testl	%eax, %eax
	jne	L1637
L1607:
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
	je	L1638
L1608:
	movl	_GeomIsOpen, %edx
	testl	%edx, %edx
	jne	L1639
L1609:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1640
L1610:
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	_set_last_directory
	xorl	%eax, %eax
	jmp	L1563
L1633:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1591
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1591
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1591
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
L1625:
	movl	$LC223, (%esp)
	call	_g_strdup
	movl	%eax, 48(%ebx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 52(%ebx)
	jmp	L1629
L1584:
	movl	%edi, (%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC233, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	movl	%eax, %ebx
	movl	-56(%ebp), %eax
	call	_deleteNumericChars
	cmpl	$3, %ebx
	je	L1641
L1585:
	movl	$1, %eax
	movl	%eax, -4164(%ebp)
	movl	$56, %eax
L1628:
	movl	%eax, 4(%esp)
	movl	-4160(%ebp), %edx
	movl	%edx, (%esp)
	jmp	L1624
L1587:
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
	movl	$LC234, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	movl	%eax, %ebx
	movl	-56(%ebp), %eax
	call	_deleteNumericChars
	cmpl	$5, %ebx
	je	L1642
L1588:
	movl	$2, %eax
	movl	%eax, -4164(%ebp)
	movl	$112, %eax
	jmp	L1628
L1632:
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
	movl	$LC223, (%esp)
	call	_g_strdup
	movl	-4160(%ebp), %edx
	movl	%eax, 48(%edx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	-4160(%ebp), %edx
	movl	%eax, 52(%edx)
	jmp	L1629
L1639:
	movl	$43, (%esp)
	call	_create_geom_interface
	jmp	L1609
L1638:
	movl	$0, (%esp)
	call	_Geom_Change_Unit
	jmp	L1608
L1637:
	call	_freeVariables
	jmp	L1607
L1636:
	call	_freeGeom
	jmp	L1606
L1640:
	call	_rafresh_drawing
	jmp	L1610
L1641:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1585
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
	jmp	L1625
L1642:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1588
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1588
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
	jmp	L1625
L1630:
	movl	8(%ebp), %edx
	movl	$LC226, %eax
	leal	-2104(%ebp), %ebx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	jmp	L1627
L1635:
	movl	$LC236, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC48, %eax
	movl	%eax, 4(%esp)
	jmp	L1623
	.section .rdata,"dr"
	.align 4
LC241:
	.ascii "Sorry\12 I can not read geometry in Molpro input file\0"
LC239:
	.ascii "Variables\0"
LC240:
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
L1647:
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, -56(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$6, %ebx
	jbe	L1647
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, %edi
	movl	$LC225, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_FOpen
	movl	%eax, -64(%ebp)
	testl	%eax, %eax
	movl	$1, -60(%ebp)
	je	L1648
	xorl	%ebx, %ebx
	cmpl	12(%ebp), %ebx
	jge	L1723
	.p2align 4,,15
L1744:
	movl	-64(%ebp), %edx
	movl	$1024, %esi
	movl	%edi, (%esp)
	incl	%ebx
	movl	%esi, 4(%esp)
	movl	%edx, 8(%esp)
	call	_fgets
	cmpl	12(%ebp), %ebx
	jl	L1744
L1723:
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
	je	L1742
	movl	-56(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$LC100, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	movl	%eax, %ebx
	decl	%ebx
	je	L1745
	movl	$0, -60(%ebp)
	movl	-76(%ebp), %eax
	movl	$-1, -80(%ebp)
	movl	%eax, (%esp)
	call	_g_free
	movl	$0, -76(%ebp)
	.p2align 4,,15
L1654:
	movl	-64(%ebp), %edx
	movl	12(%edx), %eax
	xorl	%edx, %edx
	shrl	$4, %eax
	xorl	$1, %eax
	cmpl	$0, -60(%ebp)
	setne	%dl
	testl	%edx, %eax
	je	L1658
L1747:
	movl	-64(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	call	_fgets
	cmpb	$125, (%edi)
	je	L1658
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
	je	L1661
	cmpl	$3, -80(%ebp)
	je	L1669
	movl	-32(%ebp), %eax
	movl	$LC235, %ebx
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
	jne	L1681
	xorl	%esi, %esi
	.p2align 4,,15
L1685:
	movl	-56(%ebp,%esi,4), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_DeleteLastChar
	cmpl	%esi, %ebx
	jg	L1685
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1746
L1687:
	movl	$1, -72(%ebp)
L1686:
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
L1741:
	movl	$LC223, (%esp)
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
	jne	L1747
	.p2align 4,,15
L1658:
	movl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
L1693:
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	setne	%al
	xorl	%edx, %edx
	cmpl	$0, -72(%ebp)
	setne	%dl
	testl	%eax, %edx
	jne	L1748
L1694:
	movl	%edi, (%esp)
	xorl	%ebx, %ebx
	call	_g_free
	.p2align 4,,15
L1710:
	movl	-56(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$6, %ebx
	jbe	L1710
	movl	-60(%ebp), %ecx
	movl	-80(%ebp), %edx
	testl	%ecx, %ecx
	sete	%al
	testl	%edx, %edx
	setle	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L1712
	movl	-68(%ebp), %edx
	cmpl	%edx, -84(%ebp)
	jge	L1711
L1712:
	movl	-84(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-80(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-76(%ebp), %edx
	movl	%edx, (%esp)
	call	_FreeGeom
	movl	$LC241, (%esp)
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
L1681:
	decl	-80(%ebp)
	movl	-80(%ebp), %eax
	movl	-80(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	movl	-76(%ebp), %eax
	movl	%eax, (%esp)
L1740:
	call	_g_realloc
	movl	%eax, -76(%ebp)
L1742:
	movl	$0, -60(%ebp)
	jmp	L1654
L1748:
	movl	$0, -84(%ebp)
	movl	$LC225, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	_FOpen
	movl	%eax, -64(%ebp)
	testl	%eax, %eax
	je	L1694
	movl	$LC239, (%esp)
	call	_g_strdup
	movl	%eax, (%esp)
	movl	%eax, %esi
	call	_g_strup
	movl	-64(%ebp), %eax
	testb	$16, 12(%eax)
	jne	L1697
L1749:
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
	jne	L1697
	movl	%ebx, (%esp)
	call	_g_free
	movl	-64(%ebp), %eax
	testb	$16, 12(%eax)
	je	L1749
L1697:
	movl	%esi, (%esp)
	call	_g_free
	movl	-64(%ebp), %edx
	testb	$16, 12(%edx)
	jne	L1701
	movl	$0, -92(%ebp)
	movl	$0, -96(%ebp)
	jmp	L1706
L1703:
	movl	-96(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_realloc
L1738:
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
	jne	L1701
L1706:
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
	movl	$LC240, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	cmpl	$3, %eax
	jne	L1701
	incl	-84(%ebp)
	addl	$12, -96(%ebp)
	addl	$12, -92(%ebp)
	cmpl	$1, -84(%ebp)
	jne	L1703
	movl	$12, (%esp)
	call	_g_malloc
	jmp	L1738
L1711:
	movl	_Geom, %eax
	testl	%eax, %eax
	jne	L1750
L1713:
	movl	_Variables, %eax
	testl	%eax, %eax
	jne	L1751
L1714:
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
	je	L1752
	testl	%eax, %eax
	jne	L1716
	cmpl	$1, _Units
	je	L1753
L1716:
	movl	_GeomIsOpen, %ebx
	testl	%ebx, %ebx
	jne	L1754
L1718:
	movl	_ZoneDessin, %ecx
	testl	%ecx, %ecx
	jne	L1755
L1719:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_set_last_directory
	addl	$140, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1661:
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$LC233, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	cmpl	$3, %eax
	movl	%eax, %ebx
	jne	L1662
	xorl	%esi, %esi
	.p2align 4,,15
L1666:
	movl	-56(%ebp,%esi,4), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_DeleteLastChar
	cmpl	%esi, %ebx
	jg	L1666
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1667
	incl	-68(%ebp)
	movl	$1, -72(%ebp)
L1667:
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
	jmp	L1741
L1669:
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
	movl	$LC234, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	cmpl	$5, %eax
	movl	%eax, %ebx
	jne	L1670
	xorl	%esi, %esi
	.p2align 4,,15
L1674:
	movl	-56(%ebp,%esi,4), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_DeleteLastChar
	cmpl	%esi, %ebx
	jg	L1674
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1756
L1676:
	movl	$1, -72(%ebp)
L1675:
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
	jmp	L1741
L1746:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1687
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1686
	jmp	L1687
L1701:
	movl	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	jmp	L1694
L1648:
	movl	$0, -60(%ebp)
	jmp	L1693
L1662:
	movl	$1, -80(%ebp)
	movl	$56, %eax
	movl	%eax, 4(%esp)
L1743:
	movl	-76(%ebp), %edx
	movl	%edx, (%esp)
	jmp	L1740
L1670:
	movl	$2, -80(%ebp)
	movl	$112, %esi
	movl	%esi, 4(%esp)
	jmp	L1743
L1745:
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
	movl	$LC223, (%esp)
	call	_g_strdup
	movl	-76(%ebp), %edx
	movl	%eax, 48(%edx)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	-76(%ebp), %edx
	movl	%eax, 52(%edx)
	jmp	L1654
L1755:
	call	_rafresh_drawing
	jmp	L1719
L1754:
	movl	$43, (%esp)
	call	_create_geom_interface
	jmp	L1718
L1751:
	call	_freeVariables
	jmp	L1714
L1750:
	call	_freeGeom
	jmp	L1713
L1752:
	movl	_Units, %esi
	testl	%esi, %esi
	jne	L1716
	movl	$0, (%esp)
	call	_Geom_Change_Unit
	jmp	L1716
L1756:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1675
	jmp	L1676
L1753:
	movl	$1, (%esp)
	call	_Geom_Change_Unit
	jmp	L1716
	.section .rdata,"dr"
LC243:
	.ascii "%s \0"
LC245:
	.ascii "%s %s %s %s %s %s %s\0"
LC242:
	.ascii "DUM\0"
LC246:
	.ascii "%s %s\0"
LC244:
	.ascii "%s %s %s %s %s \0"
	.align 4
LC247:
	.ascii "Sorry\12 I can not read geometry in Gaussian input file\0"
	.text
	.p2align 4,,15
.globl _read_Zmat_from_gauss_input_file
	.def	_read_Zmat_from_gauss_input_file;	.scl	2;	.type	32;	.endef
_read_Zmat_from_gauss_input_file:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$3228, %esp
	movl	%eax, -3140(%ebp)
	xorl	%eax, %eax
	xorl	%ebx, %ebx
	movl	%eax, -3144(%ebp)
	movl	8(%ebp), %eax
	movl	%edi, -3148(%ebp)
	movl	%esi, -3152(%ebp)
	movl	%ebx, -3156(%ebp)
	cmpb	$0, (%eax)
	je	L1757
	xorl	%ebx, %ebx
	.p2align 4,,15
L1762:
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, -56(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$6, %ebx
	jbe	L1762
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, -3180(%ebp)
	movl	$LC225, %ecx
	movl	%ecx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	_FOpen
	movl	%eax, -3136(%ebp)
	movl	$1, %edx
	testl	%eax, %eax
	movl	%edx, -3132(%ebp)
	je	L1763
	movl	12(%ebp), %eax
	xorl	%ebx, %ebx
	decl	%eax
	cmpl	%eax, %ebx
	jge	L1824
L1839:
	movl	-3136(%ebp), %edi
	movl	$1024, %eax
	incl	%ebx
	movl	%eax, 4(%esp)
	movl	%edi, 8(%esp)
	movl	-3180(%ebp), %eax
	movl	%eax, (%esp)
	call	_fgets
	movl	12(%ebp), %eax
	decl	%eax
	cmpl	%eax, %ebx
	jl	L1839
L1824:
	movl	-3136(%ebp), %edx
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	-3180(%ebp), %edi
	movl	%edi, (%esp)
	call	_fgets
	movl	-56(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$LC100, %eax
	movl	%eax, 4(%esp)
	call	_sscanf
	movl	%eax, %ebx
	decl	%ebx
	je	L1768
	xorl	%edi, %edi
	movl	%edi, -3132(%ebp)
L1769:
	movl	-3136(%ebp), %edx
	movl	12(%edx), %ecx
	xorl	%edx, %edx
	movl	%ecx, %eax
	shrl	$4, %eax
	xorl	$1, %eax
	cmpl	$0, -3132(%ebp)
	setne	%dl
	testl	%edx, %eax
	je	L1771
L1841:
	movl	-3136(%ebp), %edi
	movl	$1024, %ebx
	movl	%ebx, 4(%esp)
	movl	%edi, 8(%esp)
	movl	-3180(%ebp), %eax
	movl	%eax, (%esp)
	call	_fgets
	movl	-3180(%ebp), %edx
	cmpb	$10, (%edx)
	je	L1830
	xorl	%ebx, %ebx
	jmp	L1773
	.p2align 4,,7
L1777:
	movl	-3180(%ebp), %edi
	cmpb	$32, (%ebx,%edi)
	jne	L1774
	incl	%ebx
L1773:
	movl	-3180(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	cmpl	%ebx, %eax
	ja	L1777
L1774:
	movl	-3180(%ebp), %edx
	movl	%edx, (%esp)
	call	_strlen
	decl	%eax
	cmpl	%ebx, %eax
	je	L1830
	movl	-56(%ebp), %eax
	movl	$LC243, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-3180(%ebp), %edi
	movl	%edi, (%esp)
	call	_sscanf
	movl	%eax, %ebx
	decl	%ebx
	jne	L1831
	cld
	movl	-56(%ebp), %esi
	movl	$LC239, %eax
	movl	$10, %ecx
	movl	%eax, %edi
	repe
	cmpsb
	je	L1832
	incl	-3148(%ebp)
	movl	-3148(%ebp), %eax
	movl	-3148(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	movl	-3144(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_realloc
	cmpl	$2, -3148(%ebp)
	movl	%eax, -3144(%ebp)
	je	L1782
	cmpl	$3, -3148(%ebp)
	je	L1785
	movl	-32(%ebp), %eax
	movl	$LC245, %edi
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
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-3180(%ebp), %edx
	movl	%edx, (%esp)
	call	_sscanf
	cmpl	$7, %eax
	je	L1790
	decl	-3148(%ebp)
	xorl	%ebx, %ebx
	movl	-3148(%ebp), %eax
	movl	-3148(%ebp), %esi
	sall	$3, %eax
	subl	%esi, %eax
	sall	$3, %eax
	movl	%eax, 4(%esp)
	movl	-3144(%ebp), %edi
	movl	%edi, (%esp)
	call	_g_realloc
	movl	%eax, -3144(%ebp)
	movl	%ebx, -3132(%ebp)
L1790:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1840
L1792:
	movl	$1, %ecx
	movl	%ecx, -3140(%ebp)
L1791:
	movl	-3148(%ebp), %eax
	leal	-3128(%ebp), %edi
	movl	-3148(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	-3144(%ebp), %edx
	leal	(%edx,%eax,8), %eax
	leal	-56(%eax), %ebx
	movl	$11, -56(%eax)
	leal	-1080(%ebp), %edx
	movl	%edi, 12(%esp)
	leal	-2104(%ebp), %eax
	movl	%edx, 4(%esp)
	leal	-1080(%ebp), %edi
	movl	%eax, 8(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_symb_type_charge
	movl	%edi, (%esp)
	leal	-3128(%ebp), %edi
	call	_g_strdup
	movl	%eax, 4(%ebx)
	leal	-2104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	leal	-2104(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	movl	%edi, (%esp)
	call	_g_strdup
	movl	%eax, 48(%ebx)
	movl	$LC242, (%esp)
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
L1836:
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 52(%ebx)
	movl	-3136(%ebp), %eax
	movl	12(%eax), %ecx
	movl	%ecx, %eax
	shrl	$4, %eax
	xorl	%edx, %edx
	xorl	$1, %eax
	cmpl	$0, -3132(%ebp)
	setne	%dl
	testl	%edx, %eax
	jne	L1841
L1771:
	xorl	%eax, %eax
	shrl	$4, %ecx
	xorl	$1, %ecx
	movl	%eax, -3152(%ebp)
	xorl	%eax, %eax
	cmpl	$0, -3140(%ebp)
	setne	%al
	testl	%eax, %ecx
	je	L1795
	movl	-3132(%ebp), %edi
	testl	%edi, %edi
	je	L1795
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	movl	%esi, -3164(%ebp)
	movl	%ebx, -3168(%ebp)
L1807:
	movl	-3136(%ebp), %edi
	movl	$1024, %ecx
	xorl	%ebx, %ebx
	movl	%ecx, 4(%esp)
	movl	%edi, 8(%esp)
	movl	-3180(%ebp), %eax
	movl	%eax, (%esp)
	call	_fgets
	movl	$1, %edx
	movl	%edx, -3132(%ebp)
	jmp	L1796
	.p2align 4,,7
L1800:
	movl	-3180(%ebp), %edx
	xorl	%eax, %eax
	cmpb	$32, (%ebx,%edx)
	sete	%al
	negl	%eax
	andl	%eax, -3132(%ebp)
	incl	%ebx
L1796:
	movl	-3180(%ebp), %edi
	movl	%edi, (%esp)
	call	_strlen
	decl	%eax
	cmpl	%ebx, %eax
	ja	L1800
	movl	-3132(%ebp), %eax
	testl	%eax, %eax
	jne	L1795
	incl	-3152(%ebp)
	addl	$12, -3168(%ebp)
	addl	$12, -3164(%ebp)
	cmpl	$1, -3152(%ebp)
	je	L1842
	movl	-3168(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-3156(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_realloc
L1837:
	movl	%eax, -3156(%ebp)
	movl	-3164(%ebp), %esi
	movl	-3156(%ebp), %eax
	addl	%eax, %esi
	leal	-12(%esi), %edi
	movl	$0, -12(%esi)
	movl	$0, 4(%edi)
	movl	-52(%ebp), %eax
	movl	%edi, -3160(%ebp)
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC246, %eax
	movl	%eax, 4(%esp)
	movl	-3180(%ebp), %eax
	movl	%eax, (%esp)
	call	_sscanf
	movl	%eax, %ebx
	xorl	%eax, %eax
	cmpl	$2, %ebx
	movl	%eax, -3132(%ebp)
	je	L1843
L1794:
	movl	-3136(%ebp), %edx
	movl	12(%edx), %eax
	xorl	%edx, %edx
	shrl	$4, %eax
	xorl	$1, %eax
	cmpl	$0, -3140(%ebp)
	setne	%dl
	testl	%edx, %eax
	je	L1795
	movl	-3132(%ebp), %eax
	testl	%eax, %eax
	jne	L1807
L1795:
	movl	-3136(%ebp), %edi
	movl	%edi, (%esp)
	call	_fclose
L1808:
	movl	-3180(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_free
	.p2align 4,,15
L1812:
	movl	-56(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$6, %ebx
	jbe	L1812
	movl	-3132(%ebp), %esi
	movl	-3148(%ebp), %ebx
	testl	%esi, %esi
	sete	%al
	testl	%ebx, %ebx
	setle	%dl
	orl	%edx, %eax
	testb	$1, %al
	jne	L1844
	movl	_Geom, %eax
	testl	%eax, %eax
	jne	L1845
L1814:
	movl	_Variables, %eax
	testl	%eax, %eax
	jne	L1846
L1815:
	movl	-3148(%ebp), %eax
	movl	-3144(%ebp), %edi
	movl	-3152(%ebp), %edx
	movl	%eax, _NcentersZmat
	movl	$14, %eax
	movl	%eax, _MethodeGeom
	movl	20(%ebp), %eax
	movl	%edi, _Geom
	movl	-3156(%ebp), %edi
	cmpl	$1, %eax
	movl	%edx, _NVariables
	movl	%edi, _Variables
	je	L1847
	testl	%eax, %eax
	jne	L1817
	cmpl	$1, _Units
	je	L1848
L1817:
	movl	_GeomIsOpen, %eax
	testl	%eax, %eax
	jne	L1849
L1819:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1850
L1820:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_set_last_directory
L1757:
	addl	$3228, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1840:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1792
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1791
	jmp	L1792
L1842:
	movl	$12, (%esp)
	call	_g_malloc
	jmp	L1837
L1782:
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC233, %eax
	movl	%eax, 4(%esp)
	movl	-3180(%ebp), %edx
	movl	%edx, (%esp)
	call	_sscanf
	cmpl	$3, %eax
	je	L1783
	movl	$1, %edi
	movl	$56, %esi
	xorl	%ebx, %ebx
	movl	%edi, -3148(%ebp)
	movl	%esi, 4(%esp)
	movl	-3144(%ebp), %edi
	movl	%edi, (%esp)
	call	_g_realloc
	movl	%eax, -3144(%ebp)
	movl	%ebx, -3132(%ebp)
L1783:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1784
	movl	$1, %ecx
	movl	%ecx, -3140(%ebp)
L1784:
	movl	-3148(%ebp), %eax
	leal	-3128(%ebp), %edi
	movl	-3148(%ebp), %edx
	sall	$3, %eax
	subl	%edx, %eax
	movl	-3144(%ebp), %edx
	leal	(%edx,%eax,8), %eax
	leal	-56(%eax), %ebx
	movl	$7, -56(%eax)
	leal	-1080(%ebp), %edx
	movl	%edi, 12(%esp)
	leal	-2104(%ebp), %eax
	movl	%edx, 4(%esp)
	leal	-1080(%ebp), %edi
	movl	%eax, 8(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_symb_type_charge
	movl	%edi, (%esp)
	leal	-3128(%ebp), %edi
	call	_g_strdup
	movl	%eax, 4(%ebx)
	leal	-2104(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	leal	-2104(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	movl	%edi, (%esp)
	call	_g_strdup
	movl	%eax, 48(%ebx)
	movl	$LC242, (%esp)
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
	jmp	L1836
L1785:
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
	movl	$LC244, %eax
	movl	%eax, 4(%esp)
	movl	-3180(%ebp), %eax
	movl	%eax, (%esp)
	call	_sscanf
	cmpl	$5, %eax
	je	L1786
	movl	$2, %edi
	movl	$112, %esi
	xorl	%ebx, %ebx
	movl	%edi, -3148(%ebp)
	movl	%esi, 4(%esp)
	movl	-3144(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_realloc
	movl	%eax, -3144(%ebp)
	movl	%ebx, -3132(%ebp)
L1786:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1851
L1788:
	movl	$1, %ecx
	movl	%ecx, -3140(%ebp)
L1787:
	movl	-3148(%ebp), %eax
	movl	-3148(%ebp), %edx
	movl	-3144(%ebp), %edi
	sall	$3, %eax
	subl	%edx, %eax
	leal	(%edi,%eax,8), %eax
	movl	$9, -56(%eax)
	leal	-56(%eax), %ebx
	leal	-2104(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-1080(%ebp), %edi
	leal	-3128(%ebp), %eax
	movl	%edi, 4(%esp)
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_symb_type_charge
	movl	%edi, (%esp)
	leal	-2104(%ebp), %edi
	call	_g_strdup
	movl	%eax, 4(%ebx)
	leal	-2104(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	movl	%edi, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	leal	-3128(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 48(%ebx)
	movl	$LC242, (%esp)
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
	jmp	L1836
L1844:
	movl	-3152(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	-3148(%ebp), %edi
	movl	%edi, 8(%esp)
	movl	-3156(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-3144(%ebp), %edx
	movl	%edx, (%esp)
	call	_FreeGeom
	movl	$LC247, (%esp)
	movl	$1, %ecx
	movl	$LC48, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_MessageGeom
	addl	$3228, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1843:
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -12(%esi)
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%edi)
	movl	$1, %eax
	movl	$1, 8(%edi)
	movl	%eax, -3132(%ebp)
	jmp	L1794
L1850:
	call	_rafresh_drawing
	jmp	L1820
L1849:
	movl	$43, (%esp)
	call	_create_geom_interface
	jmp	L1819
L1846:
	movl	%eax, (%esp)
	call	_freeVariables
	jmp	L1815
L1845:
	call	_freeGeom
	jmp	L1814
L1847:
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L1817
	movl	$0, (%esp)
	call	_Geom_Change_Unit
	jmp	L1817
L1763:
	xorl	%edi, %edi
	movl	%edi, -3132(%ebp)
	jmp	L1808
L1768:
	movl	$1, %esi
	leal	-1080(%ebp), %ebx
	movl	%esi, -3148(%ebp)
	leal	-2104(%ebp), %esi
	movl	$56, (%esp)
	call	_g_malloc
	movl	%eax, -3144(%ebp)
	movl	$5, (%eax)
	leal	-3128(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_symb_type_charge
	movl	%ebx, (%esp)
	call	_g_strdup
	movl	-3144(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	%esi, (%esp)
	call	_g_strdup
	movl	-3144(%ebp), %edi
	movl	%eax, 8(%edi)
	movl	%esi, (%esp)
	call	_g_strdup
	movl	%eax, 12(%edi)
	leal	-3128(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 48(%edi)
	movl	$LC242, (%esp)
	call	_g_strdup
	movl	%eax, 16(%edi)
	movl	$0, 20(%edi)
	movl	$LC46, (%esp)
	call	_g_strdup
	movl	%eax, 52(%edi)
	jmp	L1769
L1830:
	movl	-3136(%ebp), %edx
	movl	12(%edx), %ecx
	jmp	L1771
L1851:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1787
	jmp	L1788
L1832:
	movl	$1, %eax
	movl	%eax, -3140(%ebp)
	movl	-3136(%ebp), %eax
	movl	12(%eax), %ecx
	jmp	L1771
L1831:
	movl	-3136(%ebp), %edi
	xorl	%eax, %eax
	movl	%eax, -3132(%ebp)
	movl	12(%edi), %ecx
	jmp	L1771
L1848:
	movl	$1, (%esp)
	call	_Geom_Change_Unit
	jmp	L1817
