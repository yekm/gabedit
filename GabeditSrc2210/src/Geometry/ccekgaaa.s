	.file	"GeomXYZ.c"
.lcomm _listv,16
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "  <popup name=\"MenuXYZVariables\">\12    <separator name=\"sepMenuPopNew\" />\12    <menuitem name=\"Edit\" action=\"Edit\" />\12    <menuitem name=\"New\" action=\"New\" />\12    <menuitem name=\"Delete\" action=\"Delete\" />\12    <separator name=\"sepMenuPopAll\" />\12    <menuitem name=\"All\" action=\"All\" />\12    <menuitem name=\"One\" action=\"One\" />\12  </popup>\12\0"
	.data
	.align 4
_uiMenuXYZVariablesInfo:
	.long	LC0
	.align 4
_numberOfGtkActionEntriesXYZVariables:
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
_gtkActionEntriesXYZVariables:
	.long	LC1
	.long	0
	.long	LC2
	.long	0
	.long	LC1
	.long	_activate_action_xyz_variables
	.long	LC3
	.long	LC4
	.long	LC5
	.long	0
	.long	LC3
	.long	_activate_action_xyz_variables
	.long	LC6
	.long	LC7
	.long	LC8
	.long	0
	.long	LC6
	.long	_activate_action_xyz_variables
	.long	LC9
	.long	0
	.long	LC10
	.long	0
	.long	LC11
	.long	_activate_action_xyz_variables
	.long	LC12
	.long	0
	.long	LC13
	.long	0
	.long	LC14
	.long	_activate_action_xyz_variables
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
.lcomm _list,16
	.align 4
_rowInserted:
	.long	-1
	.section .rdata,"dr"
	.align 4
LC15:
	.ascii "  <popup name=\"MenuXYZGeom\">\12    <separator name=\"sepMenuPopNew\" />\12    <menuitem name=\"Edit\" action=\"Edit\" />\12    <menuitem name=\"New\" action=\"New\" />\12    <menuitem name=\"Delete\" action=\"Delete\" />\12    <separator name=\"sepMenuPopDraw\" />\12    <menuitem name=\"Draw\" action=\"Draw\" />\12    <separator name=\"sepMenuPopSave\" />\12    <menuitem name=\"Save\" action=\"Save\" />\12    <separator name=\"sepMenuPopSave\" />\12    <menuitem name=\"Save\" action=\"Save\" />\12    <separator name=\"sepMenuPopAll\" />\12    <menuitem name=\"All\" action=\"All\" />\12    <menuitem name=\"AllX\" action=\"AllX\" />\12    <menuitem name=\"AllY\" action=\"AllY\" />\12    <menuitem name=\"AllZ\" action=\"AllZ\" />\12    <menuitem name=\"One\" action=\"One\" />\12    <separator name=\"sepMenuPopMul\" />\12    <menuitem name=\"MultiplyBya0\" action=\"MultiplyBya0\" />\12    <menuitem name=\"DivideBya0\" action=\"DivideBya0\" />\12    <separator name=\"sepMenuPopCent\" />\12    <menuitem name=\"Center\" action=\"Center\" />\12    <menuitem name=\"Sort\" action=\"Sort\" />\12    <separator name=\"sepMenuPopZmat\" />\12    <menuitem name=\"ToZmat\" action=\"ToZmat\" />\12    <menuitem name=\"ToZmatConn\" action=\"ToZmatConn\" />\12  </popup>\12\0"
	.data
	.align 4
_uiMenuXYZGeomInfo:
	.long	LC15
	.align 4
_numberOfGtkActionEntriesXYZGeom:
	.long	16
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
	.ascii "AllX\0"
LC25:
	.ascii "All _X=>\0"
LC26:
	.ascii "All X=>\0"
LC27:
	.ascii "AllY\0"
LC28:
	.ascii "All _Y=>\0"
LC29:
	.ascii "All Y=>\0"
LC30:
	.ascii "AllZ\0"
LC31:
	.ascii "All _Z=>\0"
LC32:
	.ascii "All Z=>\0"
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
	.ascii "Center\0"
LC43:
	.ascii "_Center\0"
LC44:
	.ascii "Sort\0"
LC45:
	.ascii "_Sort\0"
LC46:
	.ascii "ToZmat\0"
LC47:
	.ascii "to _Zmat\0"
LC48:
	.ascii "ToZmatConn\0"
LC49:
	.ascii "to _Zmat using connections\0"
LC50:
	.ascii "to _Zmat using conn.\0"
	.data
	.align 32
_gtkActionEntriesXYZGeom:
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
	.long	LC42
	.long	_activate_action_xyz_geom
	.long	LC44
	.long	0
	.long	LC45
	.long	0
	.long	LC44
	.long	_activate_action_xyz_geom
	.long	LC46
	.long	0
	.long	LC47
	.long	0
	.long	LC47
	.long	_activate_action_xyz_geom
	.long	LC48
	.long	0
	.long	LC49
	.long	0
	.long	LC50
	.long	_activate_action_xyz_geom
	.section .rdata,"dr"
LC51:
	.ascii "Low\0"
LC52:
	.ascii "Medium\0"
	.text
	.p2align 4,,15
	.def	_get_layer;	.scl	3;	.type	32;	.endef
_get_layer:
	pushl	%ebp
	movl	$LC51, %edx
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	%eax, %ebx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strstr
	xorl	%edx, %edx
	testl	%eax, %eax
	je	L7
	addl	$20, %esp
	movl	%edx, %eax
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L7:
	movl	%ebx, (%esp)
	movl	$LC52, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	cmpl	$1, %eax
	sbbl	%edx, %edx
	addl	$20, %esp
	popl	%ebx
	notl	%edx
	addl	$2, %edx
	movl	%edx, %eax
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_get_number_of_electrons;	.scl	3;	.type	32;	.endef
_get_number_of_electrons:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$332, %esp
	cmpl	_NcentersXYZ, %edi
	movl	%eax, -316(%ebp)
	jae	L21
	xorl	%ebx, %ebx
	jmp	L19
	.p2align 4,,7
L23:
	cmpl	$2, -316(%ebp)
	je	L16
L18:
	movl	-304(%ebp), %ecx
	addl	%ecx, %edi
L12:
	movl	-312(%ebp), %eax
	incl	%esi
	addl	$48, %ebx
	movl	%eax, (%esp)
	call	_g_free
	movl	-308(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	cmpl	_NcentersXYZ, %esi
	jae	L21
L19:
	movl	_GeomXYZ, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, 4(%esp)
	leal	-312(%ebp), %eax
	movl	%eax, (%esp)
	call	_prop_atom_get
	subl	$4, %esp
	cmpl	$1, -316(%ebp)
	jne	L23
	movl	_GeomXYZ, %eax
	movl	40(%ebx,%eax), %eax
	call	_get_layer
	cmpl	$2, %eax
	je	L18
	decl	%eax
L22:
	jne	L12
	jmp	L18
	.p2align 4,,7
L16:
	movl	_GeomXYZ, %eax
	movl	40(%ebx,%eax), %eax
	call	_get_layer
	cmpl	$2, %eax
	jmp	L22
	.p2align 4,,7
L21:
	leal	-12(%ebp), %esp
	movl	%edi, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_get_number_of_model_connections;	.scl	3;	.type	32;	.endef
_get_number_of_model_connections:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	_NcentersXYZ, %edi
	movl	$0, -20(%ebp)
	testl	%edi, %edi
	je	L24
	movl	$0, -16(%ebp)
	cmpl	%edi, %eax
	jge	L41
	movl	$0, -28(%ebp)
	movl	_GeomXYZ, %eax
	movl	%eax, -24(%ebp)
	.p2align 4,,15
L39:
	movl	-28(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	40(%edx,%ecx), %eax
	call	_get_layer
	cmpl	$1, %eax
	je	L28
	testl	%eax, %eax
	je	L28
	xorl	%ebx, %ebx
	cmpl	%edi, %ebx
	jge	L28
	xorl	%esi, %esi
	.p2align 4,,15
L38:
	cmpl	%ebx, -16(%ebp)
	je	L33
	movl	-24(%ebp), %edx
	movl	40(%esi,%edx), %eax
	call	_get_layer
	cmpl	$1, %eax
	je	L33
	testl	%eax, %eax
	je	L33
	movl	-28(%ebp), %ecx
	movl	-24(%ebp), %edx
	movl	44(%ecx,%edx), %eax
	movl	(%eax,%ebx,4), %eax
	testl	%eax, %eax
	setg	%al
	movzbl	%al, %eax
	addl	%eax, -20(%ebp)
	.p2align 4,,15
L33:
	incl	%ebx
	addl	$48, %esi
	cmpl	%edi, %ebx
	jl	L38
	.p2align 4,,15
L28:
	incl	-16(%ebp)
	addl	$48, -28(%ebp)
	cmpl	%edi, -16(%ebp)
	jl	L39
L41:
	movl	-20(%ebp), %eax
L24:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
	.align 8
LC54:
	.long	1189750086
	.long	1073626193
	.align 8
LC55:
	.long	877762123
	.long	1074025768
	.text
	.p2align 4,,15
.globl _compute_dipole_using_charges_of_xyz_geom
	.def	_compute_dipole_using_charges_of_xyz_geom;	.scl	2;	.type	32;	.endef
_compute_dipole_using_charges_of_xyz_geom:
	pushl	%ebp
	fldz
	movl	%esp, %ebp
	pushl	%esi
	xorl	%esi, %esi
	movl	$1, %eax
	pushl	%ebx
	subl	$32, %esp
	cmpl	_NcentersXYZ, %esi
	movl	%eax, _Dipole
	fstl	_Dipole+8
	fstl	_Dipole+16
	fstpl	_Dipole+24
	jae	L64
	xorl	%ebx, %ebx
	jmp	L53
	.p2align 4,,7
L77:
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	-24(%ebp)
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L49
L78:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	-32(%ebp)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L51
L79:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
L52:
	fldl	-16(%ebp)
	incl	%esi
	addl	$48, %ebx
	fmull	-24(%ebp)
	fxch	%st(1)
	cmpl	_NcentersXYZ, %esi
	fmull	-16(%ebp)
	fxch	%st(1)
	faddl	_Dipole+8
	fxch	%st(1)
	faddl	_Dipole+24
	fxch	%st(1)
	fstpl	_Dipole+8
	fldl	-16(%ebp)
	fmull	-32(%ebp)
	fxch	%st(1)
	fstpl	_Dipole+24
	faddl	_Dipole+16
	fstpl	_Dipole+16
	jae	L64
L53:
	movl	_GeomXYZ, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	-16(%ebp)
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L77
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	-24(%ebp)
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L78
L49:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	-32(%ebp)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L79
L51:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L52
	.p2align 4,,7
L64:
	cmpl	$1, _Units
	je	L74
L54:
	fldl	LC55
	xorl	%esi, %esi
L62:
	fldl	_Dipole+8(,%esi,8)
	fmul	%st(1), %st
	fstpl	_Dipole+8(,%esi,8)
	incl	%esi
	cmpl	$2, %esi
	jle	L62
	fstp	%st(0)
	addl	$32, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
L74:
	fldl	LC54
	xorl	%esi, %esi
	.p2align 4,,15
L58:
	fldl	_Dipole+8(,%esi,8)
	fmul	%st(1), %st
	fstpl	_Dipole+8(,%esi,8)
	incl	%esi
	cmpl	$2, %esi
	jle	L58
	fstp	%st(0)
	jmp	L54
	.section .rdata,"dr"
LC58:
	.ascii "%f\0"
	.text
	.p2align 4,,15
	.def	_calculMMTypes;	.scl	3;	.type	32;	.endef
_calculMMTypes:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	%eax, -16(%ebp)
	movl	$10, %eax
	movl	%eax, _MethodeGeom
	call	_define_geometry
	call	_reset_all_connections
	movl	_NcentersXYZ, %eax
	movl	%eax, 4(%esp)
	movl	_geometry, %eax
	movl	%eax, (%esp)
	call	_calculTypesAmber
	movl	$0, -20(%ebp)
	movl	_NcentersXYZ, %eax
	testl	%eax, %eax
	jle	L87
	xorl	%edi, %edi
	jmp	L85
	.p2align 4,,7
L83:
	incl	-20(%ebp)
	addl	$384, %edi
	movl	-20(%ebp), %eax
	cmpl	%eax, _NcentersXYZ
	jle	L87
L85:
	movl	_geometry, %edx
	movl	_GeomXYZ, %ebx
	movl	360(%edi,%edx), %eax
	decl	%eax
	leal	(%eax,%eax,2), %esi
	movl	320(%edi,%edx), %eax
	sall	$4, %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%esi,%ebx)
	movl	-16(%ebp), %eax
	testl	%eax, %eax
	je	L83
	movl	_geometry, %eax
	movl	_GeomXYZ, %ebx
	fldl	24(%edi,%eax)
	addl	$384, %edi
	movl	$LC58, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	incl	-20(%ebp)
	movl	%eax, 24(%esi,%ebx)
	movl	-20(%ebp), %eax
	cmpl	%eax, _NcentersXYZ
	jg	L85
	.p2align 4,,15
L87:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
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
	je	L91
	movl	(%ebx), %edx
	testl	%edx, %edx
	jne	L94
L91:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L89
L93:
	movl	%ebx, (%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gtk_widget_set_sensitive
L89:
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L94:
	cmpl	%eax, (%edx)
	jne	L91
	jmp	L93
	.section .rdata,"dr"
LC60:
	.ascii "/MenuXYZGeom\0"
	.data
	.align 4
menuName.1:
	.long	LC60
	.section .rdata,"dr"
LC61:
	.ascii "destroy\0"
LC62:
	.ascii "GabeditListOfProject\0"
LC64:
	.ascii "MenuName\0"
LC63:
	.ascii "building menus failed: %s\0"
	.text
	.p2align 4,,15
	.def	_newMenuXYZGeom;	.scl	3;	.type	32;	.endef
_newMenuXYZGeom:
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
	movl	$LC61, %eax
	movl	%edx, 16(%esp)
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_signal_connect_data
	movl	$LC62, (%esp)
	call	_gtk_action_group_new
	movl	%eax, %ebx
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	movl	_numberOfGtkActionEntriesXYZGeom, %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	$_gtkActionEntriesXYZGeom, %eax
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
	movl	_uiMenuXYZGeomInfo, %eax
	movl	%eax, 4(%esp)
	call	_gtk_ui_manager_add_ui_from_string
	testl	%eax, %eax
	je	L97
L96:
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	menuName.1, %edx
	movl	%edx, 8(%esp)
	movl	$LC64, %edx
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
L97:
	movl	-16(%ebp), %eax
	movl	$LC63, %esi
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
	jmp	L96
	.section .rdata,"dr"
LC65:
	.ascii "/MenuXYZVariables\0"
	.data
	.align 4
menuName.0:
	.long	LC65
	.text
	.p2align 4,,15
	.def	_newMenuXYZVariables;	.scl	3;	.type	32;	.endef
_newMenuXYZVariables:
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
	movl	$LC61, %edx
	movl	%ecx, 8(%esp)
	movl	%eax, %edi
	movl	$2, %eax
	movl	%edx, 4(%esp)
	movl	%eax, 20(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, (%esp)
	call	_g_signal_connect_data
	movl	$LC62, (%esp)
	call	_gtk_action_group_new
	movl	%eax, %ebx
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	movl	_numberOfGtkActionEntriesXYZVariables, %eax
	movl	%ebx, (%esp)
	movl	%eax, 8(%esp)
	movl	$_gtkActionEntriesXYZVariables, %eax
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
	movl	_uiMenuXYZVariablesInfo, %eax
	movl	%eax, 4(%esp)
	call	_gtk_ui_manager_add_ui_from_string
	testl	%eax, %eax
	je	L100
L99:
	movl	%edi, (%esp)
	movl	$80, %esi
	movl	$LC64, %ebx
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
L100:
	movl	-16(%ebp), %eax
	movl	8(%eax), %eax
	movl	$0, (%esp)
	movl	%eax, 12(%esp)
	movl	$LC63, %eax
	movl	%eax, 8(%esp)
	movl	$32, %eax
	movl	%eax, 4(%esp)
	call	_g_log
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_error_free
	jmp	L99
	.p2align 4,,15
	.def	_row_inserted;	.scl	3;	.type	32;	.endef
_row_inserted:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_tree_path_to_string
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, _rowInserted
	leave
	ret
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
	jge	L109
	.p2align 4,,15
L112:
	movl	(%edi,%ebx,4), %eax
	testl	%eax, %eax
	jne	L111
	incl	%ebx
L113:
	cmpl	%esi, %ebx
	jl	L112
L109:
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
L111:
	movl	%eax, (%esp)
	incl	%ebx
	call	_g_free
	jmp	L113
	.section .rdata,"dr"
	.align 8
LC66:
	.long	640652440
	.long	1071705861
	.text
	.p2align 4,,15
.globl _set_coord
	.def	_set_coord;	.scl	2;	.type	32;	.endef
_set_coord:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$12, %esp
	movl	8(%ebp), %esi
	movl	_GeomXYZ, %eax
	movl	12(%ebp), %edi
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L115
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	(%edi)
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L117
L133:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	8(%edi)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L119
L134:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	cmpl	$1, _Units
	je	L126
L135:
	fstpl	16(%edi)
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L115:
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	(%edi)
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L133
L117:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	8(%edi)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L134
L119:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	cmpl	$1, _Units
	jne	L135
L126:
	fldl	LC66
	fldl	(%edi)
	fxch	%st(2)
	fdiv	%st(1), %st
	fxch	%st(2)
	fdiv	%st(1), %st
	fxch	%st(2)
	fstpl	16(%edi)
	fxch	%st(1)
	fstpl	(%edi)
	fldl	8(%edi)
	fdivp	%st, %st(1)
	fstpl	8(%edi)
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_set_multiple_bonds;	.scl	3;	.type	32;	.endef
_set_multiple_bonds:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$636, %esp
	movl	_NcentersXYZ, %eax
	testl	%eax, %eax
	jne	L194
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L194:
	sall	$2, %eax
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -604(%ebp)
	movl	_NcentersXYZ, %eax
	testl	%eax, %eax
	jle	L186
	.p2align 4,,15
L141:
	movl	-604(%ebp), %eax
	movl	$0, (%eax,%edi,4)
	movl	_NcentersXYZ, %edx
	incl	%edi
	cmpl	%edi, %edx
	jg	L141
	xorl	%edi, %edi
	cmpl	$0, %edx
	jle	L186
	movl	_GeomXYZ, %ecx
	.p2align 4,,15
L150:
	leal	1(%edi), %eax
	cmpl	%eax, %edx
	movl	%eax, -616(%ebp)
	movl	%eax, %ebx
	jle	L180
	leal	(%edi,%edi,2), %eax
	sall	$4, %eax
	movl	44(%eax,%ecx), %eax
	.p2align 4,,15
L149:
	testl	%eax, %eax
	je	L147
	movl	(%eax,%ebx,4), %esi
	testl	%esi, %esi
	je	L147
	movl	-604(%ebp), %edx
	incl	(%edx,%edi,4)
	incl	(%edx,%ebx,4)
	movl	_NcentersXYZ, %edx
	.p2align 4,,15
L147:
	incl	%ebx
	cmpl	%ebx, %edx
	jg	L149
L180:
	movl	-616(%ebp), %edi
	cmpl	%edi, %edx
	jg	L150
	xorl	%edi, %edi
	cmpl	$0, %edx
	jg	L162
	jmp	L186
	.p2align 4,,7
L153:
	movl	-616(%ebp), %edi
	movl	_NcentersXYZ, %edx
	cmpl	%edi, %edx
	jle	L195
L162:
	movl	_GeomXYZ, %eax
	leal	(%edi,%edi,2), %esi
	sall	$4, %esi
	leal	-312(%ebp), %ecx
	movl	4(%esi,%eax), %eax
	movl	%ecx, (%esp)
	movl	%eax, 4(%esp)
	call	_prop_atom_get
	movl	_GeomXYZ, %ecx
	subl	$4, %esp
	leal	1(%edi), %eax
	movl	%eax, -616(%ebp)
	movl	44(%esi,%ecx), %edx
	testl	%edx, %edx
	je	L153
	movl	_NcentersXYZ, %edx
	movl	%eax, %ebx
	cmpl	%eax, %edx
	jle	L184
	movl	%esi, -608(%ebp)
	leal	(%eax,%eax,2), %esi
	sall	$4, %esi
	jmp	L161
	.p2align 4,,7
L157:
	incl	%ebx
	addl	$48, %esi
	cmpl	%ebx, %edx
	jle	L184
L190:
	movl	_GeomXYZ, %ecx
L161:
	movl	-608(%ebp), %eax
	movl	44(%eax,%ecx), %eax
	movl	(%eax,%ebx,4), %eax
	testl	%eax, %eax
	je	L157
	movl	4(%esi,%ecx), %eax
	leal	-600(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_prop_atom_get
	movl	-604(%ebp), %ecx
	subl	$4, %esp
	movl	-264(%ebp), %eax
	cmpl	%eax, (%ecx,%edi,4)
	jae	L159
	movl	-552(%ebp), %eax
	cmpl	%eax, (%ecx,%ebx,4)
	jae	L159
	movl	_GeomXYZ, %edx
	movl	-608(%ebp), %ecx
	movl	44(%ecx,%edx), %eax
	movl	$2, (%eax,%ebx,4)
	movl	44(%esi,%edx), %eax
	testl	%eax, %eax
	je	L160
	movl	$2, (%eax,%edi,4)
L160:
	movl	-604(%ebp), %eax
	incl	(%eax,%edi,4)
	incl	(%eax,%ebx,4)
	.p2align 4,,15
L159:
	movl	-600(%ebp), %eax
	incl	%ebx
	addl	$48, %esi
	movl	%eax, (%esp)
	call	_g_free
	movl	-596(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_NcentersXYZ, %edx
	cmpl	%ebx, %edx
	jg	L190
L184:
	movl	-312(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-308(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-616(%ebp), %edi
	movl	_NcentersXYZ, %edx
	cmpl	%edi, %edx
	jg	L162
L195:
	xorl	%edi, %edi
	cmpl	$0, %edx
	jmp	L193
	.p2align 4,,7
L165:
	movl	-616(%ebp), %edi
	cmpl	%edi, _NcentersXYZ
L193:
	jle	L186
	movl	_GeomXYZ, %eax
	leal	(%edi,%edi,2), %esi
	sall	$4, %esi
	leal	-600(%ebp), %edx
	movl	4(%esi,%eax), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_prop_atom_get
	movl	_GeomXYZ, %ecx
	subl	$4, %esp
	leal	1(%edi), %eax
	movl	%eax, -616(%ebp)
	movl	44(%esi,%ecx), %edx
	testl	%edx, %edx
	je	L165
	movl	_NcentersXYZ, %edx
	movl	%eax, %ebx
	cmpl	%eax, %edx
	jle	L188
	movl	%esi, -612(%ebp)
	leal	(%eax,%eax,2), %esi
	sall	$4, %esi
	jmp	L173
	.p2align 4,,7
L169:
	incl	%ebx
	addl	$48, %esi
	cmpl	%ebx, %edx
	jle	L188
L192:
	movl	_GeomXYZ, %ecx
L173:
	movl	-612(%ebp), %eax
	movl	44(%eax,%ecx), %eax
	movl	(%eax,%ebx,4), %eax
	testl	%eax, %eax
	je	L169
	movl	4(%esi,%ecx), %eax
	leal	-312(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_prop_atom_get
	movl	-604(%ebp), %ecx
	subl	$4, %esp
	movl	-552(%ebp), %eax
	cmpl	%eax, (%ecx,%edi,4)
	jae	L171
	movl	-264(%ebp), %eax
	cmpl	%eax, (%ecx,%ebx,4)
	jae	L171
	movl	_GeomXYZ, %edx
	movl	-612(%ebp), %ecx
	movl	44(%ecx,%edx), %eax
	movl	$3, (%eax,%ebx,4)
	movl	44(%esi,%edx), %eax
	testl	%eax, %eax
	je	L172
	movl	$3, (%eax,%edi,4)
L172:
	movl	-604(%ebp), %eax
	incl	(%eax,%edi,4)
	incl	(%eax,%ebx,4)
L171:
	movl	-312(%ebp), %eax
	incl	%ebx
	addl	$48, %esi
	movl	%eax, (%esp)
	call	_g_free
	movl	-308(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_NcentersXYZ, %edx
	cmpl	%ebx, %edx
	jg	L192
L188:
	movl	-600(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-596(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	jmp	L165
L186:
	movl	-604(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
.globl _connecteds
	.def	_connecteds;	.scl	2;	.type	32;	.endef
_connecteds:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$456, %esp
	movl	%esi, -8(%ebp)
	movl	8(%ebp), %esi
	movl	_GeomXYZ, %edx
	movl	%edi, -4(%ebp)
	leal	(%esi,%esi,2), %eax
	movl	%ebx, -12(%ebp)
	sall	$4, %eax
	movl	12(%ebp), %edi
	movl	44(%eax,%edx), %eax
	testl	%eax, %eax
	je	L197
	movl	(%eax,%edi,4), %eax
L216:
	testl	%eax, %eax
	setg	%al
	movzbl	%al, %eax
L196:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L197:
	leal	(%edi,%edi,2), %eax
	sall	$4, %eax
	movl	44(%eax,%edx), %eax
	testl	%eax, %eax
	je	L200
	movl	(%eax,%esi,4), %eax
	jmp	L216
	.p2align 4,,7
L200:
	movl	%esi, (%esp)
	leal	-88(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_set_coord
	movl	%edi, (%esp)
	leal	-120(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_set_coord
	fldl	-120(%ebp)
	xorl	%eax, %eax
	fldz
	fxch	%st(1)
	fsubrl	-88(%ebp)
	fstpl	-56(%ebp)
	fldl	-112(%ebp)
	fsubrl	-80(%ebp)
	fstpl	-48(%ebp)
	fldl	-104(%ebp)
	fsubrl	-72(%ebp)
	fstpl	-40(%ebp)
L206:
	fldl	-56(%ebp,%eax,8)
	incl	%eax
	cmpl	$2, %eax
	fmul	%st(0), %st
	faddp	%st, %st(1)
	jbe	L206
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	fstpl	-432(%ebp)
	sahf
	jp	L214
	jne	L214
	fstp	%st(0)
L207:
	movl	_GeomXYZ, %edx
	leal	(%esi,%esi,2), %eax
	sall	$4, %eax
	leal	-408(%ebp), %ebx
	movl	4(%eax,%edx), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_prop_atom_get
	fldl	-392(%ebp)
	subl	$4, %esp
	movl	-404(%ebp), %eax
	fstpl	-416(%ebp)
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %edx
	leal	(%edi,%edi,2), %eax
	sall	$4, %eax
	movl	4(%eax,%edx), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_prop_atom_get
	fldl	-392(%ebp)
	subl	$4, %esp
	movl	-408(%ebp), %eax
	fstpl	-424(%ebp)
	movl	%eax, (%esp)
	call	_g_free
	movl	-404(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	fldl	-416(%ebp)
	faddl	-424(%ebp)
	fldl	-432(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L208
	movl	$1, %eax
	jmp	L196
L208:
	xorl	%eax, %eax
	jmp	L196
L214:
	fstpl	(%esp)
	call	_sqrt
	fstpl	-432(%ebp)
	jmp	L207
	.section .rdata,"dr"
LC71:
	.ascii "row_deleted\0"
	.text
	.p2align 4,,15
	.def	_clearList;	.scl	3;	.type	32;	.endef
_clearList:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ebx, -12(%ebp)
	movl	%eax, %ebx
	movl	%esi, -8(%ebp)
	movl	%edi, -4(%ebp)
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, %esi
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	cmpl	_list, %ebx
	movl	%eax, %edi
	je	L220
L218:
	movl	%edi, (%esp)
	call	_gtk_list_store_clear
	cmpl	_list, %ebx
	je	L221
L217:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L220:
	movl	%esi, (%esp)
	movl	$_row_deleted, %eax
	xorl	%edx, %edx
	movl	%eax, 20(%esp)
	xorl	%eax, %eax
	movl	%eax, 16(%esp)
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$24, %eax
	movl	%edx, 24(%esp)
	movl	%eax, 4(%esp)
	call	_g_signal_handlers_disconnect_matched
	jmp	L218
L221:
	movl	%esi, (%esp)
	movl	$80, %eax
	movl	$1, %edi
	movl	%eax, 4(%esp)
	xorl	%esi, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ebx, %ebx
	movl	$_row_deleted, %ecx
	movl	%edi, 20(%esp)
	movl	$LC71, %edx
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	jmp	L217
	.section .rdata,"dr"
LC72:
	.ascii "%d\0"
	.text
	.p2align 4,,15
	.def	_removeFromList;	.scl	3;	.type	32;	.endef
_removeFromList:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	movl	%ebx, -12(%ebp)
	testl	%edx, %edx
	movl	%eax, %ebx
	movl	%esi, -8(%ebp)
	movl	%edi, -4(%ebp)
	js	L222
	movl	%edx, 4(%esp)
	movl	$LC72, (%esp)
	call	_g_strdup_printf
	movl	%eax, -48(%ebp)
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, %esi
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	cmpl	_list, %ebx
	movl	%eax, -44(%ebp)
	je	L227
L224:
	movl	%esi, (%esp)
	movl	-48(%ebp), %eax
	leal	-40(%ebp), %edi
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	_gtk_tree_model_get_iter_from_string
	testl	%eax, %eax
	jne	L228
L225:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	cmpl	_list, %ebx
	je	L229
L222:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L228:
	movl	%edi, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_list_store_remove
	jmp	L225
L229:
	movl	%esi, (%esp)
	movl	$80, %ecx
	xorl	%edi, %edi
	movl	%ecx, 4(%esp)
	xorl	%esi, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	$_row_deleted, %ebx
	movl	%edx, 20(%esp)
	movl	$LC71, %ecx
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	call	_g_signal_connect_data
	jmp	L222
L227:
	movl	%esi, (%esp)
	xorl	%eax, %eax
	movl	$24, %edi
	movl	%eax, 24(%esp)
	movl	$_row_deleted, %eax
	movl	%eax, 20(%esp)
	xorl	%eax, %eax
	movl	%eax, 16(%esp)
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	call	_g_signal_handlers_disconnect_matched
	jmp	L224
	.p2align 4,,15
	.def	_TestVariablesXYZCreated;	.scl	3;	.type	32;	.endef
_TestVariablesXYZCreated:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	xorl	%ebx, %ebx
	movl	%eax, -16(%ebp)
	movl	_NVariablesXYZ, %edi
	movl	%edx, -20(%ebp)
	movl	$0, -24(%ebp)
	cmpl	$0, %edi
	jle	L232
	movl	_VariablesXYZ, %eax
	xorl	%esi, %esi
	movl	%eax, -28(%ebp)
	.p2align 4,,15
L236:
	cmpl	%ebx, -20(%ebp)
	je	L233
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-28(%ebp), %edx
	movl	(%esi,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L238
L233:
	incl	%ebx
	addl	$12, %esi
	cmpl	%ebx, %edi
	jg	L236
L232:
	movl	-24(%ebp), %eax
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L238:
	movl	$1, -24(%ebp)
	movl	-24(%ebp), %eax
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_testav;	.scl	3;	.type	32;	.endef
_testav:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$28, %esp
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	movl	$-1, %edx
	jne	L239
	movl	$0, -16(%ebp)
	movl	_NVariablesXYZ, %eax
	cmpl	%eax, -16(%ebp)
	movl	%eax, -24(%ebp)
	jae	L249
	movl	_VariablesXYZ, %eax
	xorl	%edi, %edi
	movl	%eax, -28(%ebp)
	leal	1(%esi), %eax
	movl	%eax, -20(%ebp)
	jmp	L246
	.p2align 4,,7
L243:
	incl	-16(%ebp)
	addl	$12, %edi
	movl	-24(%ebp), %eax
	cmpl	%eax, -16(%ebp)
	jae	L249
L246:
	movl	-28(%ebp), %eax
	movl	(%edi,%eax), %ebx
	movl	%esi, (%esp)
	movl	%ebx, 4(%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L245
	cmpb	$45, (%esi)
	jne	L243
	movl	%ebx, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L243
L245:
	movl	-16(%ebp), %edx
L239:
	addl	$28, %esp
	movl	%edx, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L249:
	addl	$28, %esp
	movl	$-2, %edx
	movl	%edx, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC73:
	.ascii "row_inserted\0"
	.text
	.p2align 4,,15
	.def	_insertToList;	.scl	3;	.type	32;	.endef
_insertToList:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	%eax, %edi
	movl	%edx, %eax
	pushl	%esi
	notl	%eax
	sarl	$31, %eax
	pushl	%ebx
	subl	$76, %esp
	movl	%edx, %ebx
	andl	%eax, %ebx
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, -44(%ebp)
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	cmpl	_list, %edi
	movl	%eax, %esi
	je	L261
L252:
	movl	%ebx, 8(%esp)
	leal	-40(%ebp), %ecx
	xorl	%ebx, %ebx
	movl	%ecx, 4(%esp)
	movl	%esi, (%esp)
	call	_gtk_list_store_insert
	cmpl	12(%ebp), %ebx
	jge	L259
	.p2align 4,,15
L262:
	movl	$-1, %eax
	leal	(%ebx,%ebx), %edx
	movl	8(%ebp), %ecx
	movl	%eax, 24(%esp)
	movl	$1, %eax
	movl	%eax, 20(%esp)
	leal	1(%edx), %eax
	movl	%eax, 16(%esp)
	movl	(%ecx,%ebx,4), %eax
	movl	%edx, 8(%esp)
	movl	%esi, (%esp)
	movl	%eax, 12(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gtk_list_store_set
	movl	8(%ebp), %edx
	movl	(%edx,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	12(%ebp), %ebx
	jl	L262
L259:
	cmpl	_list, %edi
	je	L263
L250:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L263:
	movl	-44(%ebp), %ecx
	movl	$80, %eax
	movl	$1, %edi
	movl	%eax, 4(%esp)
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_row_inserted, %ecx
	movl	$LC73, %edx
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	jmp	L250
L261:
	xorl	%eax, %eax
	xorl	%edx, %edx
	movl	$_row_inserted, %ecx
	movl	%eax, 24(%esp)
	xorl	%eax, %eax
	movl	%edx, 16(%esp)
	movl	-44(%ebp), %edx
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$24, %eax
	movl	%ecx, 20(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_signal_handlers_disconnect_matched
	jmp	L252
	.p2align 4,,15
	.def	_append_list;	.scl	3;	.type	32;	.endef
_append_list:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	pushl	%ebx
	subl	$124, %esp
	xorl	%ebx, %ebx
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	_list, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, -92(%ebp)
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %esi
	call	_gtk_tree_model_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 12(%esp)
	xorl	%ecx, %ecx
	movl	$_row_inserted, %edx
	movl	%ecx, 24(%esp)
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
	movl	%edx, 20(%esp)
	movl	$24, %edx
	movl	%eax, -92(%ebp)
	movl	%edi, 16(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_handlers_disconnect_matched
	cmpl	_NcentersXYZ, %ebx
	jae	L274
	leal	-88(%ebp), %edi
L272:
	movl	$LC72, (%esp)
	leal	1(%ebx), %eax
	leal	(%ebx,%ebx,2), %ebx
	movl	%eax, -96(%ebp)
	sall	$4, %ebx
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp)
	movl	_GeomXYZ, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -68(%ebp)
	movl	_GeomXYZ, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -56(%ebp)
	movl	_GeomXYZ, %eax
	movl	8(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -64(%ebp)
	movl	_GeomXYZ, %eax
	movl	12(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -60(%ebp)
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -52(%ebp)
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -48(%ebp)
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -44(%ebp)
	movl	_GeomXYZ, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -40(%ebp)
	movl	_GeomXYZ, %eax
	movl	40(%ebx,%eax), %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -36(%ebp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	_gtk_list_store_append
	.p2align 4,,15
L271:
	movl	%edi, 4(%esp)
	movl	$-1, %eax
	leal	(%ebx,%ebx), %edx
	movl	%eax, 24(%esp)
	movl	$1, %eax
	movl	%eax, 20(%esp)
	leal	1(%edx), %eax
	movl	%eax, 16(%esp)
	movl	-72(%ebp,%ebx,4), %eax
	movl	%edx, 8(%esp)
	movl	%esi, (%esp)
	movl	%eax, 12(%esp)
	call	_gtk_list_store_set
	movl	-72(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$9, %ebx
	jle	L271
	movl	-96(%ebp), %ebx
	cmpl	_NcentersXYZ, %ebx
	jb	L272
L274:
	movl	$80, %eax
	movl	$1, %edi
	xorl	%esi, %esi
	movl	%eax, 4(%esp)
	movl	-92(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_row_inserted, %ecx
	movl	$LC73, %edx
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	addl	$124, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_row_deleted;	.scl	3;	.type	32;	.endef
_row_deleted:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	12(%ebp), %esi
	movl	%esi, (%esp)
	call	_gtk_tree_path_to_string
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -16(%ebp)
	movl	_NcentersXYZ, %ecx
	movl	_rowInserted, %ebx
	movl	$0, -20(%ebp)
	cmpl	%ebx, %ecx
	jl	L277
	cmpl	%eax, %ecx
	jl	L277
	orl	%ebx, %eax
	js	L277
	cmpl	-16(%ebp), %ebx
	je	L277
	xorl	%esi, %esi
	cmpl	%ecx, %esi
	jb	L283
L303:
	movl	-16(%ebp), %eax
	xorl	%edx, %edx
	addl	%ecx, %eax
	cmpl	-16(%ebp), %ebx
	movl	%ebx, 8(%esp)
	setl	%dl
	subl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_list_insert
	movl	%eax, -20(%ebp)
	movl	_rowInserted, %ebx
	cmpl	-16(%ebp), %ebx
	jl	L312
L285:
	cmpl	-16(%ebp), %ebx
	jg	L313
L286:
	movl	_NcentersXYZ, %eax
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -28(%ebp)
	movl	-20(%ebp), %edx
	testl	%edx, %edx
	movl	%edx, -24(%ebp)
	je	L305
	movl	_NcentersXYZ, %ecx
	movl	%eax, %edi
	addl	$44, %edi
	.p2align 4,,15
L294:
	movl	-24(%ebp), %edx
	movl	(%edx), %eax
	cmpl	%ecx, %eax
	jb	L289
	subl	%ecx, %eax
L289:
	leal	(%eax,%eax,2), %ebx
	movl	_GeomXYZ, %eax
	sall	$4, %ebx
	movl	4(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -40(%edi)
	movl	_GeomXYZ, %eax
	movl	8(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -36(%edi)
	movl	_GeomXYZ, %eax
	movl	12(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -32(%edi)
	movl	_GeomXYZ, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -28(%edi)
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -16(%edi)
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -12(%edi)
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -8(%edi)
	movl	_GeomXYZ, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -20(%edi)
	movl	_GeomXYZ, %eax
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -4(%edi)
	movl	_NcentersXYZ, %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, (%edi)
	movl	_NcentersXYZ, %ecx
	xorl	%edx, %edx
	cmpl	%ecx, %edx
	jae	L307
	movl	_GeomXYZ, %ecx
	movl	%eax, %esi
	movl	44(%ebx,%ecx), %ebx
	.p2align 4,,15
L293:
	movl	(%ebx,%edx,4), %eax
	movl	%eax, (%esi,%edx,4)
	movl	_NcentersXYZ, %ecx
	incl	%edx
	cmpl	%ecx, %edx
	jb	L293
L307:
	movl	-24(%ebp), %eax
	addl	$48, %edi
	movl	4(%eax), %eax
	movl	%eax, -24(%ebp)
	testl	%eax, %eax
	jne	L294
L305:
	movl	-20(%ebp), %edx
	xorl	%esi, %esi
	movl	%edx, (%esp)
	call	_g_list_free
	cmpl	_NcentersXYZ, %esi
	jae	L310
	movl	_GeomXYZ, %ecx
	xorl	%ebx, %ebx
	jmp	L299
	.p2align 4,,7
L297:
	incl	%esi
	addl	$48, %ebx
	cmpl	_NcentersXYZ, %esi
	jae	L309
L299:
	movl	4(%ebx,%ecx), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	8(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	12(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %ecx
	movl	44(%ebx,%ecx), %eax
	testl	%eax, %eax
	je	L297
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %ecx
	jmp	L297
	.p2align 4,,7
L277:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L310:
	movl	_GeomXYZ, %ecx
L309:
	movl	%ecx, (%esp)
	call	_g_free
	movl	-28(%ebp), %eax
	movl	%eax, _GeomXYZ
	movl	_list, %eax
	call	_clearList
	call	_append_list
	movl	_rowInserted, %eax
	cmpl	-16(%ebp), %eax
	jg	L314
L311:
	movl	%eax, _LineSelected
	movl	$-1, %edi
	movl	%eax, 4(%esp)
	movl	$LC72, (%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_gtk_tree_path_new_from_string
	movl	%ebx, (%esp)
	movl	%eax, %esi
	call	_g_free
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	_list, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_selection
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_tree_selection_select_path
	movl	%esi, (%esp)
	movl	$-1, %esi
	call	_gtk_tree_path_free
	movl	%edi, _NSA+8
	movl	_LineSelected, %eax
	movl	_ZoneDessin, %ebx
	movl	%esi, _NSA+4
	incl	%eax
	testl	%ebx, %ebx
	movl	%eax, _NSA
	movl	$-1, %eax
	movl	%eax, _NSA+12
	je	L277
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_rafresh_drawing
L283:
	movl	%esi, 4(%esp)
	movl	-20(%ebp), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_g_list_append
	movl	%eax, -20(%ebp)
	movl	_NcentersXYZ, %ecx
	cmpl	%ecx, %esi
	jb	L283
	movl	_rowInserted, %ebx
	jmp	L303
L314:
	decl	%eax
	jmp	L311
L312:
	movl	-16(%ebp), %eax
	decl	%eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_list_remove
	movl	%eax, -20(%ebp)
	movl	_rowInserted, %ebx
	jmp	L285
L313:
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_list_remove
	movl	%eax, -20(%ebp)
	jmp	L286
	.section .rdata,"dr"
LC74:
	.ascii "NumColumn\0"
	.align 4
LC76:
	.ascii "Sorry a other variable have any Name !\12\0"
LC75:
	.ascii " Error \0"
LC78:
	.ascii "%s.0\0"
LC77:
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
	subl	$92, %esp
	movl	$-1, %ebx
	call	_gtk_tree_model_get_type
	movl	%eax, 4(%esp)
	movl	20(%ebp), %eax
	movl	16(%ebp), %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -44(%ebp)
	movl	8(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC74, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -48(%ebp)
	testl	%eax, %eax
	movl	$0, -52(%ebp)
	je	L346
	cmpl	$1, -48(%ebp)
	je	L347
L320:
	testl	%ebx, %ebx
	js	L315
	movl	-48(%ebp), %ecx
	testl	%ecx, %ecx
	je	L348
	cmpl	$1, -48(%ebp)
	je	L349
L326:
	movl	12(%ebp), %eax
	leal	-40(%ebp), %ebx
	movl	%eax, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	%eax, %esi
	movl	-44(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$-1, %edx
	movl	%edx, 16(%esp)
	movl	-48(%ebp), %edx
	movl	%edi, 12(%esp)
	movl	%ebx, 4(%esp)
	addl	%edx, %edx
	movl	%edx, 8(%esp)
	call	_gtk_list_store_set
	movl	%esi, (%esp)
	call	_gtk_tree_path_free
	movl	-48(%ebp), %eax
	testl	%eax, %eax
	sete	%dl
	xorl	%eax, %eax
	cmpl	$0, -52(%ebp)
	setne	%al
	testl	%edx, %eax
	je	L328
	movl	$-1, -60(%ebp)
	xorl	%eax, %eax
	cmpl	_NcentersXYZ, %eax
	movl	$0, -56(%ebp)
	jae	L340
	xorl	%esi, %esi
	jmp	L338
	.p2align 4,,7
L333:
	movl	%edi, (%esp)
	call	_g_strdup
	movl	%eax, 28(%esi,%ebx)
	movl	_GeomXYZ, %ebx
	movl	$0, -60(%ebp)
L332:
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	32(%esi,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L334
	movl	32(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L350
L335:
	movl	%edi, (%esp)
	call	_g_strdup
	movl	%eax, 32(%esi,%ebx)
	movl	_GeomXYZ, %ebx
	movl	$0, -60(%ebp)
L334:
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	36(%esi,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L331
	movl	36(%esi,%ebx), %eax
	testl	%eax, %eax
	jne	L351
L337:
	movl	%edi, (%esp)
	call	_g_strdup
	movl	%eax, 36(%esi,%ebx)
	movl	$0, -60(%ebp)
L331:
	incl	-56(%ebp)
	addl	$48, %esi
	movl	-56(%ebp), %eax
	cmpl	_NcentersXYZ, %eax
	jae	L352
L338:
	movl	-52(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, 4(%esp)
	movl	28(%esi,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L332
	movl	28(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L333
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %ebx
	jmp	L333
	.p2align 4,,7
L352:
	movl	-60(%ebp), %eax
	testl	%eax, %eax
	jne	L340
	movl	_list, %eax
	call	_clearList
	call	_append_list
	.p2align 4,,15
L340:
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L328:
	cmpl	$1, -48(%ebp)
	jne	L315
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L315
	call	_rafresh_drawing
	.p2align 4,,15
L315:
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L346:
	movl	%edi, (%esp)
	call	_variable_name_valid
	testl	%eax, %eax
	je	L353
	cmpb	$0, (%edi)
	je	L315
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %edx
	movl	%eax, %ebx
	movl	%edi, %eax
	call	_TestVariablesXYZCreated
	testl	%eax, %eax
	je	L320
	movl	$LC76, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC75, %eax
	movl	%eax, 4(%esp)
	call	_MessageGeom
	jmp	L315
	.p2align 4,,7
L348:
	movl	_VariablesXYZ, %esi
	leal	(%ebx,%ebx,2), %ebx
	sall	$2, %ebx
	movl	(%ebx,%esi), %eax
	movl	%edi, (%esp)
	movl	%eax, -52(%ebp)
	call	_g_strdup
	movl	%eax, (%ebx,%esi)
	jmp	L326
	.p2align 4,,7
L350:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %ebx
	jmp	L335
	.p2align 4,,7
L351:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %ebx
	jmp	L337
L349:
	movl	_VariablesXYZ, %esi
	leal	(%ebx,%ebx,2), %eax
	leal	0(,%eax,4), %ebx
	movl	4(%ebx,%esi), %eax
	testl	%eax, %eax
	jne	L354
L327:
	movl	%edi, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx,%esi)
	jmp	L326
L347:
	movl	%edi, (%esp)
	call	_test
	testl	%eax, %eax
	je	L355
	cmpb	$0, (%edi)
	je	L315
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%edi, (%esp)
	movl	%eax, %ebx
	call	_test
	testl	%eax, %eax
	je	L320
	movl	%edi, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L320
	movl	%edi, 4(%esp)
	movl	$LC78, (%esp)
	call	_g_strdup_printf
	movl	%eax, %edi
	jmp	L320
	.p2align 4,,7
L353:
	call	_show_forbidden_characters
	jmp	L315
L354:
	movl	%eax, (%esp)
	call	_g_free
	movl	_VariablesXYZ, %esi
	jmp	L327
L355:
	movl	%edi, 4(%esp)
	movl	$LC75, %esi
	movl	$1, %edi
	movl	$LC77, (%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	%eax, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	jmp	L315
	.section .rdata,"dr"
	.align 4
LC80:
	.ascii "Sorry\12 %s \12is not a number \12and is not a variable \0"
LC82:
	.ascii "High\0"
LC83:
	.ascii " \0"
	.align 4
LC79:
	.ascii "Sorry %s is not a symbol for an atom \12\0"
LC81:
	.ascii "%s\0"
	.align 4
LC84:
	.ascii "Sorry  The layer should be High, Medium, Low or one space \12\0"
	.text
	.p2align 4,,15
	.def	_editedGeom;	.scl	3;	.type	32;	.endef
_editedGeom:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$156, %esp
	call	_gtk_tree_model_get_type
	movl	%eax, 4(%esp)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -92(%ebp)
	movl	16(%ebp), %ebx
	testl	%ebx, %ebx
	je	L356
	movl	8(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC74, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	testl	%eax, %eax
	movl	%eax, %esi
	je	L445
	cmpl	$1, %eax
	je	L446
	cmpl	$2, %eax
	je	L447
	cmpl	$3, %eax
	je	L448
	cmpl	$4, %eax
	je	L449
	leal	-5(%eax), %eax
	cmpl	$2, %eax
	ja	L398
	movl	16(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L356
	movl	12(%ebp), %edi
	movl	%edi, (%esp)
	call	_atoi
	movl	%eax, -96(%ebp)
	movl	%ebx, %eax
	call	_testav
	incl	%eax
	jge	L400
	movl	%ebx, 4(%esp)
	movl	$LC80, (%esp)
L440:
	call	_g_strdup_printf
L438:
	movl	%eax, (%esp)
	movl	%eax, %ebx
	movl	$LC75, %ecx
	movl	%ecx, 4(%esp)
	movl	$1, %esi
	movl	%esi, 8(%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	.p2align 4,,15
L356:
	addl	$156, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L445:
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -100(%ebp)
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_atoi
	decl	%eax
	movl	%eax, -104(%ebp)
	js	L356
	cmpl	_NcentersXYZ, %eax
	jae	L356
	movl	-100(%ebp), %ecx
	cmpl	%ecx, %eax
	je	L356
	cld
	movl	_GeomXYZ, %ebx
	leal	(%ecx,%ecx,2), %edx
	sall	$4, %edx
	leal	-88(%ebp), %eax
	movl	%ebx, -116(%ebp)
	leal	(%edx,%ebx), %esi
	movl	$12, %ebx
	movl	%eax, %edi
	movl	%ebx, %ecx
	rep
	movsl
	movl	-104(%ebp), %ecx
	leal	(%ecx,%ecx,2), %eax
	movl	-116(%ebp), %ecx
	sall	$4, %eax
	leal	(%eax,%ecx), %esi
	leal	(%edx,%ecx), %edi
	movl	%ebx, %ecx
	rep
	movsl
	movl	-116(%ebp), %edi
	leal	-88(%ebp), %esi
	movl	%ebx, %ecx
	addl	%edi, %eax
	movl	%eax, %edi
	rep
	movsl
	xorl	%esi, %esi
	movl	_NcentersXYZ, %edi
	cmpl	$0, %edi
	jle	L427
	movl	-116(%ebp), %ebx
	addl	$44, %ebx
	.p2align 4,,15
L366:
	movl	(%ebx), %ecx
	testl	%ecx, %ecx
	je	L364
	movl	-100(%ebp), %eax
	movl	-104(%ebp), %edi
	movl	(%ecx,%eax,4), %edx
	movl	(%ecx,%edi,4), %eax
	movl	-100(%ebp), %edi
	movl	%eax, (%ecx,%edi,4)
	movl	-104(%ebp), %eax
	movl	%edx, (%ecx,%eax,4)
	movl	_NcentersXYZ, %edi
L364:
	incl	%esi
	addl	$48, %ebx
	cmpl	%esi, %edi
	jg	L366
L427:
	movl	_list, %eax
	call	_clearList
	call	_append_list
	.p2align 4,,15
L439:
	movl	_ZoneDessin, %ebx
	testl	%ebx, %ebx
	je	L356
	call	_rafresh_drawing
	jmp	L356
L448:
	movl	16(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L356
	movl	12(%ebp), %edi
	movl	%edi, (%esp)
	call	_atoi
	movl	%eax, -96(%ebp)
	movl	-96(%ebp), %edx
	movl	_GeomXYZ, %eax
	leal	(%edx,%edx,2), %ebx
	sall	$4, %ebx
	movl	%eax, -116(%ebp)
	movl	12(%ebx,%eax), %eax
	testl	%eax, %eax
	jne	L450
L380:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%eax, 12(%ebx,%edx)
	leal	-40(%ebp), %ebx
	movl	%ecx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	%eax, %edi
	movl	-92(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	$-1, %ecx
	movl	$6, %edx
	movl	%ecx, 16(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 12(%esp)
L444:
	movl	%edx, 8(%esp)
	.p2align 4,,15
L441:
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_list_store_set
	movl	%edi, (%esp)
	call	_gtk_tree_path_free
	jmp	L439
	.p2align 4,,7
L446:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_strlen
	testl	%eax, %eax
	movl	%eax, %ebx
	jle	L356
	movl	16(%ebp), %ecx
	movsbl	(%ecx),%eax
	movl	%eax, (%esp)
	call	_toupper
	movl	16(%ebp), %edi
	decl	%ebx
	movb	%al, (%edi)
	jg	L451
L370:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_test_atom_define
	testl	%eax, %eax
	je	L452
	movl	12(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_atoi
	movl	%eax, -96(%ebp)
	movl	_GeomXYZ, %ebx
	movl	%ebx, -116(%ebp)
	movl	-116(%ebp), %edi
	leal	(%eax,%eax,2), %ebx
	sall	$4, %ebx
	movl	4(%ebx,%edi), %eax
	testl	%eax, %eax
	jne	L453
L372:
	movl	16(%ebp), %edx
	movl	$-1, %esi
	movl	%edx, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %ecx
	movl	%eax, 4(%ebx,%ecx)
	movl	12(%ebp), %ebx
	movl	%ebx, (%esp)
	leal	-40(%ebp), %ebx
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	%eax, %edi
	movl	-92(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 16(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	$2, %ecx
	movl	%ecx, 8(%esp)
	jmp	L441
L447:
	movl	16(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L356
	movl	12(%ebp), %edi
	movl	%edi, (%esp)
	call	_atoi
	movl	%eax, -96(%ebp)
	movl	-96(%ebp), %edx
	movl	_GeomXYZ, %eax
	leal	(%edx,%edx,2), %ebx
	sall	$4, %ebx
	movl	%eax, -116(%ebp)
	movl	8(%ebx,%eax), %eax
	testl	%eax, %eax
	jne	L454
L376:
	movl	16(%ebp), %eax
	movl	$4, %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%eax, 8(%ebx,%edx)
	leal	-40(%ebp), %ebx
	movl	%ecx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	%eax, %edi
	movl	-92(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 8(%esp)
	movl	16(%ebp), %ecx
	movl	$-1, %edx
	movl	%edx, 16(%esp)
	movl	%ecx, 12(%esp)
	jmp	L441
L398:
	cmpl	$8, %esi
	je	L455
	cmpl	$9, %esi
	jne	L356
	movl	16(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_strlen
	testl	%eax, %eax
	movl	%eax, %esi
	jle	L356
	movsbl	(%ebx),%eax
	movl	%eax, (%esp)
	call	_toupper
	movb	%al, (%ebx)
	movl	$1, %ebx
	cmpl	%esi, %ebx
	jge	L432
L456:
	movl	16(%ebp), %edi
	movsbl	(%ebx,%edi),%eax
	movl	%eax, (%esp)
	call	_tolower
	movb	%al, (%ebx,%edi)
	incl	%ebx
	cmpl	%esi, %ebx
	jl	L456
L432:
	movl	12(%ebp), %eax
	movl	$LC82, %edi
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -96(%ebp)
	movl	16(%ebp), %esi
	movl	$5, %ecx
	cld
	repe
	cmpsb
	je	L423
	movl	16(%ebp), %esi
	movl	$LC52, %edi
	movl	$7, %ecx
	repe
	cmpsb
	je	L423
	movl	16(%ebp), %esi
	movl	$LC51, %edi
	movl	$4, %ecx
	repe
	cmpsb
	je	L423
	movl	16(%ebp), %esi
	movl	$LC83, %edi
	movl	$2, %ecx
	repe
	cmpsb
	jne	L457
L423:
	movl	-96(%ebp), %ecx
	movl	_GeomXYZ, %edx
	leal	(%ecx,%ecx,2), %ebx
	movl	%edx, -116(%ebp)
	sall	$4, %ebx
	movl	40(%ebx,%edx), %eax
	testl	%eax, %eax
	jne	L458
L424:
	movl	16(%ebp), %eax
	movl	$18, %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%eax, 40(%ebx,%edx)
	leal	-40(%ebp), %ebx
	movl	%ecx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	%eax, %edi
	movl	-92(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 8(%esp)
	movl	16(%ebp), %ecx
	movl	$-1, %edx
	movl	%edx, 16(%esp)
	movl	%ecx, 12(%esp)
	jmp	L441
L452:
	movl	$LC79, (%esp)
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	jmp	L440
L454:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %edi
	movl	%edi, -116(%ebp)
	jmp	L376
L455:
	movl	16(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L356
	movl	12(%ebp), %edi
	movl	%edi, (%esp)
	call	_atoi
	movl	%eax, -96(%ebp)
	movl	%ebx, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L411
	movl	%ebx, 4(%esp)
	movl	$LC77, (%esp)
	jmp	L440
L449:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_strlen
	testl	%eax, %eax
	jle	L356
	movl	12(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_atoi
	movl	%eax, -96(%ebp)
	leal	(%eax,%eax,2), %ebx
	movl	16(%ebp), %eax
	movl	_GeomXYZ, %edi
	sall	$4, %ebx
	movl	%eax, 4(%esp)
	movl	16(%ebx,%edi), %eax
	movl	%edi, -116(%ebp)
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L384
	movl	16(%ebx,%edi), %eax
	testl	%eax, %eax
	jne	L459
L385:
	movl	16(%ebp), %ecx
	xorl	%esi, %esi
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edi
	movl	%eax, 16(%ebx,%edi)
	movl	_GeomXYZ, %eax
	movl	$-1, %edi
	movl	%edi, 20(%ebx,%eax)
	movl	_NcentersXYZ, %edi
	movl	%eax, -116(%ebp)
	cmpl	$0, %edi
	jle	L387
	movl	%ebx, -120(%ebp)
	xorl	%ebx, %ebx
L390:
	cmpl	%esi, -96(%ebp)
	je	L388
	movl	-116(%ebp), %edx
	movl	-120(%ebp), %ecx
	movl	16(%ebx,%edx), %eax
	movl	%eax, 4(%esp)
	movl	16(%ecx,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L433
L388:
	incl	%esi
	addl	$48, %ebx
	cmpl	%esi, %edi
	jg	L390
L387:
	movl	-96(%ebp), %ebx
	movl	-116(%ebp), %edi
	leal	(%ebx,%ebx,2), %eax
	sall	$4, %eax
	cmpl	$-1, 20(%eax,%edi)
	je	L460
L384:
	movl	12(%ebp), %ecx
	leal	-40(%ebp), %ebx
	movl	$-1, %esi
	movl	%ecx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	%eax, %edi
	movl	-92(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 16(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	$8, %ecx
	movl	%ecx, 8(%esp)
	jmp	L441
L451:
	movsbl	1(%edi),%eax
	movl	%eax, (%esp)
	call	_tolower
	movb	%al, 1(%edi)
	jmp	L370
L400:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L461
L401:
	cmpl	$5, %esi
	je	L462
	cmpl	$6, %esi
	je	L463
	cmpl	$7, %esi
	je	L464
L406:
	movl	12(%ebp), %ecx
	leal	-40(%ebp), %ebx
	movl	%ecx, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	%eax, %edi
	movl	-92(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	16(%ebp), %ecx
	movl	$-1, %edx
	movl	%edx, 16(%esp)
	leal	(%esi,%esi), %edx
	movl	%ecx, 12(%esp)
	jmp	L444
L450:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %edi
	movl	%edi, -116(%ebp)
	jmp	L380
L453:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	%eax, -116(%ebp)
	jmp	L372
L461:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L401
	movl	$LC78, (%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 16(%ebp)
	jmp	L401
L462:
	movl	_GeomXYZ, %ebx
	movl	-96(%ebp), %edi
	movl	%ebx, -116(%ebp)
	movl	-116(%ebp), %edx
	leal	(%edi,%edi,2), %ebx
	sall	$4, %ebx
	movl	28(%ebx,%edx), %eax
	testl	%eax, %eax
	jne	L465
L403:
	movl	16(%ebp), %edi
	movl	%edi, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, 28(%ebx,%edx)
	jmp	L406
L411:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L412
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	je	L466
L412:
	movl	$LC81, (%esp)
	movl	16(%ebp), %ebx
	movl	%ebx, 4(%esp)
L434:
	call	_g_strdup_printf
	movl	%eax, %esi
	movl	-96(%ebp), %eax
	movl	_GeomXYZ, %edi
	leal	(%eax,%eax,2), %ebx
	sall	$4, %ebx
	movl	24(%ebx,%edi), %eax
	movl	%edi, -116(%ebp)
	testl	%eax, %eax
	jne	L467
L414:
	movl	16(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edi
	movl	%eax, 24(%ebx,%edi)
	movl	12(%ebp), %eax
	leal	-40(%ebp), %ebx
	movl	%eax, (%esp)
	call	_gtk_tree_path_new_from_string
	movl	%eax, 8(%esp)
	movl	-92(%ebp), %edx
	movl	%eax, %edi
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	call	_gtk_tree_model_get_iter
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-92(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$-1, %ecx
	movl	$16, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_list_store_set
	movl	%edi, (%esp)
	call	_gtk_tree_path_free
	movl	_ZoneDessin, %edi
	testl	%edi, %edi
	jne	L468
L415:
	testl	%esi, %esi
	je	L356
	movl	%esi, (%esp)
	call	_g_free
	jmp	L356
L459:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %edx
	movl	%edx, -116(%ebp)
	jmp	L385
L460:
	movl	_NcentersXYZ, %edi
	xorl	%esi, %esi
	cmpl	$0, %edi
	jle	L430
	movl	%edi, -124(%ebp)
	movl	-116(%ebp), %edx
	movl	%eax, %ecx
	addl	$20, %edx
L396:
	movl	-116(%ebp), %ebx
	movl	(%edx), %eax
	cmpl	%eax, 20(%ecx,%ebx)
	jge	L394
	movl	%eax, 20(%ecx,%ebx)
	movl	-124(%ebp), %edi
L394:
	incl	%esi
	addl	$48, %edx
	cmpl	%esi, %edi
	jg	L396
L430:
	movl	-96(%ebp), %edi
	movl	-116(%ebp), %edx
	leal	(%edi,%edi,2), %eax
	sall	$4, %eax
	incl	20(%eax,%edx)
	jmp	L384
L463:
	movl	-96(%ebp), %edi
	movl	_GeomXYZ, %ecx
	leal	(%edi,%edi,2), %ebx
	movl	%ecx, -116(%ebp)
	sall	$4, %ebx
	movl	32(%ebx,%ecx), %eax
	testl	%eax, %eax
	jne	L469
L405:
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %ecx
	movl	%eax, 32(%ebx,%ecx)
	jmp	L406
L433:
	movl	-116(%ebp), %edi
	movl	-120(%ebp), %edx
	movl	20(%ebx,%edi), %eax
	movl	%eax, 20(%edx,%edi)
	jmp	L387
L464:
	movl	_GeomXYZ, %ebx
	movl	-96(%ebp), %edi
	movl	%ebx, -116(%ebp)
	movl	-116(%ebp), %edx
	leal	(%edi,%edi,2), %ebx
	sall	$4, %ebx
	movl	36(%ebx,%edx), %eax
	testl	%eax, %eax
	jne	L470
L407:
	movl	16(%ebp), %edi
	movl	%edi, (%esp)
	call	_g_strdup
	movl	-116(%ebp), %edx
	movl	%eax, 36(%ebx,%edx)
	jmp	L406
L458:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %edi
	movl	%edi, -116(%ebp)
	jmp	L424
L465:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %ecx
	movl	%ecx, -116(%ebp)
	jmp	L403
L468:
	call	_rafresh_drawing
	jmp	L415
L467:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %edx
	movl	%edx, -116(%ebp)
	jmp	L414
L469:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	%eax, -116(%ebp)
	jmp	L405
L466:
	movl	$LC78, (%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 4(%esp)
	jmp	L434
L470:
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %ecx
	movl	%ecx, -116(%ebp)
	jmp	L407
L457:
	movl	$LC84, (%esp)
	call	_g_strdup_printf
	jmp	L438
	.p2align 4,,15
	.def	_appendToList;	.scl	3;	.type	32;	.endef
_appendToList:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	%edx, %esi
	pushl	%ebx
	subl	$76, %esp
	movl	%eax, -44(%ebp)
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_model
	movl	%eax, -48(%ebp)
	call	_gtk_list_store_get_type
	movl	%eax, 4(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %edi
	movl	-44(%ebp), %eax
	cmpl	_list, %eax
	je	L481
L472:
	movl	%edi, (%esp)
	leal	-40(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, 4(%esp)
	call	_gtk_list_store_append
	cmpl	8(%ebp), %ebx
	jge	L479
	.p2align 4,,15
L482:
	movl	$-1, %eax
	leal	(%ebx,%ebx), %edx
	movl	%eax, 24(%esp)
	movl	$1, %eax
	movl	%eax, 20(%esp)
	leal	1(%edx), %eax
	movl	%eax, 16(%esp)
	movl	(%esi,%ebx,4), %eax
	movl	%edx, 8(%esp)
	movl	%edi, (%esp)
	movl	%eax, 12(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gtk_list_store_set
	movl	(%esi,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	8(%ebp), %ebx
	jl	L482
L479:
	movl	-44(%ebp), %eax
	cmpl	_list, %eax
	je	L483
L471:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L483:
	movl	-48(%ebp), %eax
	movl	$80, %esi
	movl	$1, %ebx
	movl	%esi, 4(%esp)
	movl	$_row_inserted, %edi
	movl	$LC73, %esi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ebx, 20(%esp)
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_g_signal_connect_data
	jmp	L471
L481:
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	movl	$_row_inserted, %edx
	movl	%eax, 16(%esp)
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$24, %eax
	movl	%eax, 4(%esp)
	movl	-48(%ebp), %eax
	movl	%ecx, 24(%esp)
	movl	%edx, 20(%esp)
	movl	%eax, (%esp)
	call	_g_signal_handlers_disconnect_matched
	jmp	L472
	.p2align 4,,15
	.def	_get_position;	.scl	3;	.type	32;	.endef
_get_position:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	%edx, %edi
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$12, %esp
	leal	(%eax,%eax,2), %ebx
	movl	_GeomXYZ, %eax
	sall	$4, %ebx
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L485
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	(%edi)
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L487
L499:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	8(%edi)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L489
L500:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	fstpl	16(%edi)
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L485:
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	(%edi)
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L499
L487:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	8(%edi)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L500
L489:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	fstpl	16(%edi)
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
	.align 8
LC87:
	.long	640652440
	.long	1071705861
	.text
	.p2align 4,,15
	.def	_connected;	.scl	3;	.type	32;	.endef
_connected:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	%edx, %edi
	leal	-88(%ebp), %edx
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$444, %esp
	call	_get_position
	movl	%edi, %eax
	leal	-120(%ebp), %edx
	call	_get_position
	xorl	%eax, %eax
	.p2align 4,,15
L505:
	fldl	-120(%ebp,%eax,8)
	fsubrl	-88(%ebp,%eax,8)
	fstpl	-56(%ebp,%eax,8)
	incl	%eax
	cmpl	$2, %eax
	jbe	L505
	fldz
	xorl	%eax, %eax
	.p2align 4,,15
L509:
	fldl	-56(%ebp,%eax,8)
	incl	%eax
	cmpl	$2, %eax
	fmul	%st(0), %st
	faddp	%st, %st(1)
	jbe	L509
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	fstpl	-416(%ebp)
	sahf
	jp	L520
	jne	L520
	fstp	%st(0)
L510:
	movl	_GeomXYZ, %edx
	leal	(%esi,%esi,2), %eax
	sall	$4, %eax
	leal	-408(%ebp), %ebx
	movl	4(%eax,%edx), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_prop_atom_get
	fldl	-392(%ebp)
	subl	$4, %esp
	movl	_GeomXYZ, %edx
	leal	(%edi,%edi,2), %eax
	sall	$4, %eax
	movl	4(%eax,%edx), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	fstpl	-440(%ebp)
	call	_prop_atom_get
	fldl	-440(%ebp)
	subl	$4, %esp
	cmpl	$1, _Units
	faddl	-392(%ebp)
	je	L521
L511:
	fldl	-416(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L512
	leal	-12(%ebp), %esp
	movl	$1, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L512:
	leal	-12(%ebp), %esp
	xorl	%eax, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L521:
	fmull	LC87
	jmp	L511
L520:
	fstpl	(%esp)
	call	_sqrt
	fstpl	-416(%ebp)
	jmp	L510
	.p2align 4,,15
.globl _reset_connections_XYZ
	.def	_reset_connections_XYZ;	.scl	2;	.type	32;	.endef
_reset_connections_XYZ:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$12, %esp
	movl	_NcentersXYZ, %eax
	movl	$0, -16(%ebp)
	cmpl	%eax, -16(%ebp)
	jae	L538
	xorl	%edi, %edi
	.p2align 4,,15
L536:
	movl	_GeomXYZ, %esi
	movl	44(%edi,%esi), %edx
	testl	%edx, %edx
	jne	L544
L527:
	sall	$2, %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, 44(%edi,%esi)
	movl	_NcentersXYZ, %eax
	cmpl	%eax, %ebx
	jae	L542
	movl	_GeomXYZ, %esi
	movl	44(%edi,%esi), %edx
	.p2align 4,,15
L531:
	movl	$0, (%edx,%ebx,4)
	movl	_NcentersXYZ, %eax
	incl	%ebx
	cmpl	%eax, %ebx
	jb	L531
	xorl	%ebx, %ebx
	cmpl	%eax, %ebx
	jae	L542
	.p2align 4,,15
L545:
	movl	-16(%ebp), %eax
	movl	%ebx, %edx
	call	_connected
	movl	_GeomXYZ, %edx
	movl	44(%edi,%edx), %edx
	movl	%eax, (%edx,%ebx,4)
	movl	_NcentersXYZ, %eax
	incl	%ebx
	cmpl	%eax, %ebx
	jb	L545
L542:
	incl	-16(%ebp)
	addl	$48, %edi
	cmpl	%eax, -16(%ebp)
	jb	L536
L538:
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_set_multiple_bonds
L544:
	movl	%edx, (%esp)
	call	_g_free
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %esi
	jmp	L527
	.section .rdata,"dr"
	.align 4
LC90:
	.long	-998637568
	.text
	.p2align 4,,15
	.def	_get_distance_xyz;	.scl	3;	.type	32;	.endef
_get_distance_xyz:
	pushl	%ebp
	movl	%eax, %ecx
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$176, %esp
	movl	%edx, %ebx
	movl	_NcentersXYZ, %eax
	cmpl	%ecx, %eax
	jle	L548
	xorl	%edx, %edx
	cmpl	%ebx, %eax
	movl	%ecx, %eax
	setle	%dl
	shrl	$31, %eax
	orl	%eax, %edx
	jne	L548
	testl	%ebx, %ebx
	js	L548
	leal	-104(%ebp), %esi
	movl	%ecx, %eax
	movl	%esi, %edx
	call	_get_position
	xorl	%eax, %eax
L552:
	fldl	-104(%ebp,%eax,8)
	fstpl	-40(%ebp,%eax,8)
	incl	%eax
	cmpl	$2, %eax
	jbe	L552
	movl	%ebx, %eax
	movl	%esi, %edx
	call	_get_position
	xorl	%eax, %eax
L556:
	fldl	-104(%ebp,%eax,8)
	fstpl	-72(%ebp,%eax,8)
	incl	%eax
	cmpl	$2, %eax
	jbe	L556
	xorl	%ebx, %ebx
	movl	%ebx, 48(%esp)
	movl	-72(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-64(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 20(%esp)
	call	_get_distance_points
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_atof
	fstpl	-112(%ebp)
	movl	%ebx, (%esp)
	call	_g_free
	fldl	-112(%ebp)
	addl	$176, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L548:
	flds	LC90
	addl	$176, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_sortGeomXYZByResidueNumber;	.scl	3;	.type	32;	.endef
_sortGeomXYZByResidueNumber:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	movl	_NcentersXYZ, %eax
	testl	%eax, %eax
	jne	L615
L562:
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L615:
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -80(%ebp)
	movl	_NcentersXYZ, %esi
	movl	$0, -76(%ebp)
	cmpl	$0, %esi
	jmp	L612
	.p2align 4,,7
L616:
	movl	-76(%ebp), %eax
	movl	-80(%ebp), %edx
	movl	%eax, (%edx,%eax,4)
	movl	_NcentersXYZ, %esi
	incl	%eax
	movl	%eax, -76(%ebp)
	cmpl	%eax, %esi
L612:
	jg	L616
	leal	0(,%esi,4), %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -84(%ebp)
	movl	_NcentersXYZ, %esi
	movl	$0, -76(%ebp)
	cmpl	$0, %esi
	jmp	L613
	.p2align 4,,7
L617:
	movl	-76(%ebp), %ecx
	movl	-84(%ebp), %esi
	movl	$0, (%esi,%ecx,4)
	movl	_NcentersXYZ, %esi
	incl	%ecx
	movl	%ecx, -76(%ebp)
	cmpl	%ecx, %esi
L613:
	jg	L617
	movl	$0, -76(%ebp)
	leal	-1(%esi), %eax
	cmpl	$0, %eax
	jle	L604
	.p2align 4,,15
L618:
	movl	-76(%ebp), %ebx
	movl	%ebx, %edi
	incl	%edi
	movl	%edi, -92(%ebp)
	cmpl	%edi, %esi
	movl	%edi, %edx
	jle	L606
	movl	_GeomXYZ, %eax
	movl	%eax, -88(%ebp)
	leal	(%edi,%edi,2), %eax
	movl	-88(%ebp), %edi
	sall	$4, %eax
	leal	20(%eax,%edi), %ecx
	.p2align 4,,15
L579:
	movl	-88(%ebp), %edi
	leal	(%ebx,%ebx,2), %eax
	sall	$4, %eax
	movl	20(%eax,%edi), %eax
	cmpl	%eax, (%ecx)
	jge	L577
	movl	%edx, %ebx
L577:
	incl	%edx
	addl	$48, %ecx
	cmpl	%edx, %esi
	jg	L579
L606:
	cmpl	-76(%ebp), %ebx
	je	L574
	cld
	movl	_GeomXYZ, %eax
	movl	-76(%ebp), %ecx
	movl	%eax, -88(%ebp)
	movl	-88(%ebp), %edi
	leal	(%ecx,%ecx,2), %edx
	sall	$4, %edx
	movl	$12, %ecx
	leal	-72(%ebp), %eax
	leal	(%edx,%edi), %esi
	movl	%eax, %edi
	leal	(%ebx,%ebx,2), %eax
	rep
	movsl
	movl	-88(%ebp), %ecx
	sall	$4, %eax
	leal	(%edx,%ecx), %edi
	movl	-88(%ebp), %edx
	leal	(%eax,%ecx), %esi
	movl	$12, %ecx
	rep
	movsl
	addl	%edx, %eax
	leal	-72(%ebp), %esi
	movl	%eax, %edi
	movl	$12, %ecx
	movl	-76(%ebp), %eax
	rep
	movsl
	movl	-80(%ebp), %ecx
	movl	-76(%ebp), %esi
	movl	(%ecx,%eax,4), %edx
	movl	(%ecx,%ebx,4), %eax
	movl	%eax, (%ecx,%esi,4)
	movl	%edx, (%ecx,%ebx,4)
	movl	_NcentersXYZ, %esi
L574:
	movl	-92(%ebp), %edi
	leal	-1(%esi), %eax
	cmpl	%edi, %eax
	movl	%edi, -76(%ebp)
	jg	L618
L604:
	movl	$0, -76(%ebp)
	cmpl	$0, %esi
	jle	L608
	movl	_GeomXYZ, %ebx
	addl	$44, %ebx
	jmp	L594
	.p2align 4,,7
L584:
	incl	-76(%ebp)
	addl	$48, %ebx
	cmpl	-76(%ebp), %esi
	jle	L608
L594:
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L584
	xorl	%edx, %edx
	cmpl	$0, %esi
	jle	L584
	movl	%eax, %ecx
	.p2align 4,,15
L589:
	movl	(%ecx,%edx,4), %eax
	movl	-84(%ebp), %esi
	movl	%eax, (%esi,%edx,4)
	movl	_NcentersXYZ, %esi
	incl	%edx
	cmpl	%edx, %esi
	jg	L589
	xorl	%edx, %edx
	cmpl	$0, %esi
	jle	L584
	movl	(%ebx), %ecx
	.p2align 4,,15
L593:
	movl	-80(%ebp), %edi
	movl	-84(%ebp), %esi
	movl	(%edi,%edx,4), %eax
	movl	(%esi,%eax,4), %eax
	movl	%eax, (%ecx,%edx,4)
	movl	_NcentersXYZ, %esi
	incl	%edx
	cmpl	%edx, %esi
	jg	L593
	incl	-76(%ebp)
	addl	$48, %ebx
	cmpl	-76(%ebp), %esi
	jg	L594
L608:
	movl	-84(%ebp), %eax
	testl	%eax, %eax
	je	L595
	movl	-84(%ebp), %edi
	movl	%edi, (%esp)
	call	_g_free
L595:
	movl	-80(%ebp), %eax
	testl	%eax, %eax
	je	L596
	movl	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L596:
	movl	_GeomIsOpen, %eax
	testl	%eax, %eax
	jne	L619
L597:
	movl	_ZoneDessin, %edi
	testl	%edi, %edi
	je	L562
	movl	$0, (%esp)
	xorl	%esi, %esi
	movl	%esi, 4(%esp)
	call	_draw_geometry
	jmp	L562
L619:
	movl	_list, %eax
	call	_clearList
	call	_append_list
	jmp	L597
	.p2align 4,,15
.globl _append_VariablesXYZ_in_list
	.def	_append_VariablesXYZ_in_list;	.scl	2;	.type	32;	.endef
_append_VariablesXYZ_in_list:
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
	cmpl	_NVariablesXYZ, %eax
	jae	L630
	movl	$0, -56(%ebp)
	.p2align 4,,15
L628:
	movl	-56(%ebp), %edx
	xorl	%esi, %esi
	movl	_VariablesXYZ, %eax
	movl	(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -48(%ebp)
	movl	-56(%ebp), %edx
	movl	_VariablesXYZ, %eax
	movl	4(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -44(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_gtk_list_store_append
L627:
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
	jle	L627
	incl	-52(%ebp)
	addl	$12, -56(%ebp)
	movl	-52(%ebp), %eax
	cmpl	_NVariablesXYZ, %eax
	jb	L628
L630:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
.globl _FreeGeomXYZ
	.def	_FreeGeomXYZ;	.scl	2;	.type	32;	.endef
_FreeGeomXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$12, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %edi
	movl	16(%ebp), %eax
	testl	%edx, %edx
	je	L634
	testl	%eax, %eax
	jle	L654
	movl	8(%ebp), %ebx
	movl	%eax, %esi
	addl	$44, %ebx
	jmp	L647
	.p2align 4,,7
L638:
	movl	-36(%ebx), %eax
	testl	%eax, %eax
	jne	L657
L639:
	movl	-32(%ebx), %eax
	testl	%eax, %eax
	jne	L658
L640:
	movl	-16(%ebx), %eax
	testl	%eax, %eax
	jne	L659
L641:
	movl	-12(%ebx), %eax
	testl	%eax, %eax
	jne	L660
L642:
	movl	-8(%ebx), %eax
	testl	%eax, %eax
	jne	L661
L643:
	movl	-20(%ebx), %eax
	testl	%eax, %eax
	jne	L662
L644:
	movl	-4(%ebx), %eax
	testl	%eax, %eax
	jne	L663
L645:
	movl	(%ebx), %eax
	testl	%eax, %eax
	jne	L664
L637:
	addl	$48, %ebx
	decl	%esi
	je	L654
L647:
	movl	-40(%ebx), %eax
	testl	%eax, %eax
	je	L638
	movl	%eax, (%esp)
	call	_g_free
	movl	-36(%ebx), %eax
	testl	%eax, %eax
	je	L639
	.p2align 4,,15
L657:
	movl	%eax, (%esp)
	call	_g_free
	movl	-32(%ebx), %eax
	testl	%eax, %eax
	je	L640
	.p2align 4,,15
L658:
	movl	%eax, (%esp)
	call	_g_free
	movl	-16(%ebx), %eax
	testl	%eax, %eax
	je	L641
	.p2align 4,,15
L659:
	movl	%eax, (%esp)
	call	_g_free
	movl	-12(%ebx), %eax
	testl	%eax, %eax
	je	L642
	.p2align 4,,15
L660:
	movl	%eax, (%esp)
	call	_g_free
	movl	-8(%ebx), %eax
	testl	%eax, %eax
	je	L643
	.p2align 4,,15
L661:
	movl	%eax, (%esp)
	call	_g_free
	movl	-20(%ebx), %eax
	testl	%eax, %eax
	je	L644
	.p2align 4,,15
L662:
	movl	%eax, (%esp)
	call	_g_free
	movl	-4(%ebx), %eax
	testl	%eax, %eax
	je	L645
	.p2align 4,,15
L663:
	movl	%eax, (%esp)
	call	_g_free
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L637
	.p2align 4,,15
L664:
	movl	%eax, (%esp)
	addl	$48, %ebx
	call	_g_free
	decl	%esi
	jne	L647
	.p2align 4,,15
L654:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L634:
	testl	%edi, %edi
	je	L648
	movl	20(%ebp), %eax
	testl	%eax, %eax
	jle	L656
	movl	20(%ebp), %esi
	xorl	%ebx, %ebx
	.p2align 4,,15
L652:
	movl	(%ebx,%edi), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	4(%ebx,%edi), %eax
	addl	$12, %ebx
	movl	%eax, (%esp)
	call	_g_free
	decl	%esi
	jne	L652
L656:
	movl	%edi, (%esp)
	call	_g_free
L648:
	xorl	%esi, %esi
	movl	%esi, _Dipole
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
.globl _freeGeomXYZ
	.def	_freeGeomXYZ;	.scl	2;	.type	32;	.endef
_freeGeomXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$16, %esp
	cmpl	_NcentersXYZ, %esi
	jae	L673
	movl	_GeomXYZ, %edx
	xorl	%ebx, %ebx
	jmp	L670
	.p2align 4,,7
L668:
	incl	%esi
	addl	$48, %ebx
	cmpl	_NcentersXYZ, %esi
	jae	L672
L670:
	movl	4(%ebx,%edx), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	8(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	12(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %eax
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_GeomXYZ, %edx
	movl	44(%ebx,%edx), %eax
	testl	%eax, %eax
	je	L668
	movl	%eax, (%esp)
	incl	%esi
	call	_g_free
	addl	$48, %ebx
	cmpl	_NcentersXYZ, %esi
	movl	_GeomXYZ, %edx
	jb	L670
	.p2align 4,,15
L672:
	movl	%edx, (%esp)
	xorl	%esi, %esi
	call	_g_free
	movl	%esi, _GeomXYZ
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
	movl	%ebx, _NcentersXYZ
	movl	%ecx, _Dipole
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
L673:
	movl	_GeomXYZ, %edx
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	movl	%edx, (%esp)
	call	_g_free
	movl	%esi, _GeomXYZ
	xorl	%ecx, %ecx
	movl	%ebx, _NcentersXYZ
	movl	%ecx, _Dipole
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,15
.globl _freeVariablesXYZ
	.def	_freeVariablesXYZ;	.scl	2;	.type	32;	.endef
_freeVariablesXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$16, %esp
	cmpl	_NVariablesXYZ, %esi
	jae	L680
	xorl	%ebx, %ebx
	.p2align 4,,15
L678:
	movl	_VariablesXYZ, %eax
	incl	%esi
	movl	(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_VariablesXYZ, %eax
	movl	4(%ebx,%eax), %eax
	addl	$12, %ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	_NVariablesXYZ, %esi
	jb	L678
L680:
	movl	_VariablesXYZ, %eax
	movl	%eax, (%esp)
	call	_g_free
	xorl	%eax, %eax
	movl	%eax, _VariablesXYZ
	xorl	%eax, %eax
	movl	%eax, _NVariablesXYZ
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_destroy_dialogue;	.scl	3;	.type	32;	.endef
_destroy_dialogue:
	pushl	%ebp
	movl	_DestroyDialog, %eax
	movl	%esp, %ebp
	testl	%eax, %eax
	jne	L683
	popl	%ebp
	ret
	.p2align 4,,7
L683:
	popl	%ebp
	jmp	_delete_child
	.section .rdata,"dr"
LC92:
	.ascii "%s.xyz\0"
LC93:
	.ascii "w\0"
LC96:
	.ascii "%d\12\0"
	.align 4
LC97:
	.ascii "XYZ file generated by gabedit : coordinates in Angstrom\12\0"
	.align 4
LC99:
	.ascii "%s  %20.10f  %20.10f  %20.10f\12\0"
LC95:
	.ascii "Error\0"
	.align 4
LC94:
	.ascii "Sorry,\12 I can not open %s file\0"
	.align 8
LC98:
	.long	640652440
	.long	1071705861
	.text
	.p2align 4,,15
.globl _save_xyz_file_no_add_list
	.def	_save_xyz_file_no_add_list;	.scl	2;	.type	32;	.endef
_save_xyz_file_no_add_list:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	$LC92, (%esp)
	call	_g_strdup_printf
	movl	%ebx, (%esp)
	movl	%eax, %esi
	call	_g_free
	movl	%esi, (%esp)
	movl	$LC93, %eax
	movl	%eax, 4(%esp)
	call	_FOpen
	testl	%eax, %eax
	movl	%eax, %edi
	je	L702
	movl	%edi, (%esp)
	movl	_NcentersXYZ, %eax
	movl	$LC96, %ecx
	movl	%ecx, 4(%esp)
	xorl	%esi, %esi
	movl	%eax, 8(%esp)
	call	_fprintf
	movl	%edi, 12(%esp)
	movl	$56, %edx
	movl	$1, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC97, (%esp)
	call	_fwrite
	cmpl	_NcentersXYZ, %esi
	jae	L698
	xorl	%ebx, %ebx
	jmp	L696
	.p2align 4,,7
L708:
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	-24(%ebp)
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L691
L709:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	-32(%ebp)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L693
L710:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
L701:
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L695
	fldl	LC98
	fldl	-24(%ebp)
	fxch	%st(2)
	fmul	%st(1), %st
	fxch	%st(2)
	fmul	%st(1), %st
	fstpl	-24(%ebp)
	fldl	-32(%ebp)
	fmulp	%st, %st(1)
	fstpl	-32(%ebp)
L695:
	fstpl	28(%esp)
	movl	_GeomXYZ, %eax
	incl	%esi
	fldl	-32(%ebp)
	fstpl	20(%esp)
	fldl	-24(%ebp)
	fstpl	12(%esp)
	movl	4(%ebx,%eax), %eax
	addl	$48, %ebx
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	movl	$LC99, %eax
	movl	%eax, 4(%esp)
	call	_fprintf
	cmpl	_NcentersXYZ, %esi
	jae	L698
L696:
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L708
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	-24(%ebp)
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L709
L691:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	-32(%ebp)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L710
L693:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L701
	.p2align 4,,7
L698:
	movl	%edi, 8(%ebp)
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_fclose
L702:
	movl	%esi, 4(%esp)
	movl	$1, %edi
	movl	$LC95, %esi
	movl	$LC94, (%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	%eax, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_Message
	movl	%ebx, 8(%ebp)
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_g_free
	.section .rdata,"dr"
LC102:
	.ascii " \12\0"
	.align 8
LC101:
	.long	640652440
	.long	1071705861
	.text
	.p2align 4,,15
.globl _save_xyz_file
	.def	_save_xyz_file;	.scl	2;	.type	32;	.endef
_save_xyz_file:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	movl	8(%ebp), %eax
	movl	$0, -44(%ebp)
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	$LC92, (%esp)
	call	_g_strdup_printf
	movl	%eax, -20(%ebp)
	movl	%ebx, (%esp)
	call	_g_free
	movl	$LC93, %ecx
	movl	%ecx, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_FOpen
	testl	%eax, %eax
	movl	%eax, %esi
	je	L731
	movl	%esi, (%esp)
	movl	_NcentersXYZ, %eax
	xorl	%edi, %edi
	movl	%eax, 8(%esp)
	movl	$LC96, %eax
	movl	%eax, 4(%esp)
	call	_fprintf
	movl	%esi, 12(%esp)
	movl	$56, %eax
	movl	%eax, 8(%esp)
	movl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$LC97, (%esp)
	call	_fwrite
	movl	-44(%ebp), %eax
	cmpl	_NcentersXYZ, %eax
	jae	L726
	xorl	%ebx, %ebx
	jmp	L723
	.p2align 4,,7
L739:
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	-32(%ebp)
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L718
L740:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	-40(%ebp)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L720
L741:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
L729:
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L722
	fldl	LC101
	fldl	-32(%ebp)
	fxch	%st(2)
	fmul	%st(1), %st
	fxch	%st(2)
	fmul	%st(1), %st
	fstpl	-32(%ebp)
	fldl	-40(%ebp)
	fmulp	%st, %st(1)
	fstpl	-40(%ebp)
L722:
	fstpl	28(%esp)
	movl	_GeomXYZ, %eax
	incl	%edi
	fldl	-40(%ebp)
	fstpl	20(%esp)
	fldl	-32(%ebp)
	fstpl	12(%esp)
	movl	4(%ebx,%eax), %eax
	addl	$48, %ebx
	movl	%esi, (%esp)
	movl	%eax, 8(%esp)
	movl	$LC99, %eax
	movl	%eax, 4(%esp)
	call	_g_fprintf
	cmpl	_NcentersXYZ, %edi
	jae	L726
L723:
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L739
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	-32(%ebp)
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L740
L718:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	-40(%ebp)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L741
L720:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L729
	.p2align 4,,7
L726:
	movl	%esi, 12(%esp)
	movl	$1, %ecx
	movl	$2, %ebx
	movl	%ecx, 4(%esp)
	movl	%ebx, 8(%esp)
	movl	$LC102, (%esp)
	call	_fwrite
	movl	%esi, (%esp)
	call	_fclose
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_name_file
	movl	%eax, %edi
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_get_name_file
	movl	%ebx, (%esp)
	movl	%eax, %esi
	call	_get_name_dir
	movl	%eax, -44(%ebp)
	movl	_lastdirectory, %eax
	testl	%eax, %eax
	jne	L735
L724:
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, _lastdirectory
	movl	_defaultNetWorkProtocol, %eax
	xorl	%edx, %edx
	movl	%edx, 40(%esp)
	movl	%eax, 44(%esp)
	movl	$10, %eax
	movl	%eax, 36(%esp)
	xorl	%eax, %eax
	movl	%eax, 32(%esp)
	xorl	%eax, %eax
	movl	%eax, 28(%esp)
	xorl	%eax, %eax
	movl	%eax, 24(%esp)
	xorl	%eax, %eax
	movl	%eax, 20(%esp)
	movl	-44(%ebp), %eax
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%eax, 16(%esp)
	movl	_noeud+40, %eax
	movl	%eax, 4(%esp)
	movl	_treeViewProjects, %eax
	movl	%eax, (%esp)
	call	_CreeFeuille
	movl	%ebx, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	movl	%esi, (%esp)
	call	_g_free
	movl	-44(%ebp), %eax
	movl	%eax, 8(%ebp)
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_g_free
L731:
	movl	-20(%ebp), %eax
	movl	$LC94, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	movl	$1, %edx
	movl	$LC95, %eax
	movl	%ebx, (%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	call	_Message
	movl	%ebx, 8(%ebp)
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_g_free
L735:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L724
	.section .rdata,"dr"
LC104:
	.ascii "Sorry\12 No selected file\0"
	.text
	.p2align 4,,15
.globl _save_geometry_xyz_file
	.def	_save_geometry_xyz_file;	.scl	2;	.type	32;	.endef
_save_geometry_xyz_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$-5, 12(%ebp)
	movl	8(%ebp), %eax
	je	L746
	leave
	ret
	.p2align 4,,7
L746:
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	testl	%eax, %eax
	je	L745
	cmpb	$0, (%eax)
	jne	L744
L745:
	movl	$LC104, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC75, %eax
	movl	%eax, 4(%esp)
	call	_Message
	leave
	ret
L744:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_xyz_file
	.p2align 4,,15
.globl _save_xyz_file_entry
	.def	_save_xyz_file_entry;	.scl	2;	.type	32;	.endef
_save_xyz_file_entry:
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
	je	L747
	cmpb	$0, (%eax)
	jne	L750
L747:
	leave
	ret
	.p2align 4,,7
L750:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_xyz_file
	.section .rdata,"dr"
LC105:
	.ascii "%s.mol2\0"
LC106:
	.ascii "@<TRIPOS>MOLECULE\12\0"
LC107:
	.ascii " Gabedit generated mol2\12\0"
LC108:
	.ascii " %10d %10d %10d\12\0"
LC109:
	.ascii " SMALL\12\0"
LC110:
	.ascii " NO_CHARGES\12\0"
LC111:
	.ascii " ****\12\0"
LC112:
	.ascii "@<TRIPOS>ATOM\12\0"
	.align 4
LC114:
	.ascii " %5d %3s  %20.10f  %20.10f  %20.10f %3s %d %s %f\12\0"
LC115:
	.ascii "@<TRIPOS>BOND\12\0"
LC116:
	.ascii " %5d %5d  %5d %5d\12\0"
LC117:
	.ascii "@<TRIPOS>SUBSTRUCTURE\12\0"
LC118:
	.ascii "    1 RES1       1\12\0"
	.align 8
LC113:
	.long	640652440
	.long	1071705861
	.text
	.p2align 4,,15
.globl _save_mol2_file
	.def	_save_mol2_file;	.scl	2;	.type	32;	.endef
_save_mol2_file:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$LC93, %edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$140, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	$LC105, (%esp)
	call	_g_strdup_printf
	movl	%eax, -28(%ebp)
	movl	%ebx, (%esp)
	call	_g_free
	movl	%edi, 4(%esp)
	movl	-28(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_FOpen
	movl	%eax, -36(%ebp)
	testl	%eax, %eax
	je	L802
	movl	$0, -32(%ebp)
	movl	_NcentersXYZ, %ecx
	xorl	%ebx, %ebx
	cmpl	%ecx, %esi
	jae	L786
	movl	_GeomXYZ, %esi
	.p2align 4,,15
L762:
	leal	(%ebx,%ebx,2), %eax
	sall	$4, %eax
	movl	44(%eax,%esi), %eax
	leal	1(%ebx), %edi
	testl	%eax, %eax
	je	L755
	cmpl	%ecx, %edi
	movl	%edi, %edx
	jae	L755
	movl	%eax, %ebx
	.p2align 4,,15
L761:
	movl	(%ebx,%edx,4), %eax
	cmpl	$1, %eax
	sbbl	$-1, -32(%ebp)
	incl	%edx
	cmpl	%ecx, %edx
	jb	L761
	.p2align 4,,15
L755:
	cmpl	%ecx, %edi
	movl	%edi, %ebx
	jb	L762
L786:
	movl	-36(%ebp), %eax
	movl	$18, %edx
	movl	$LC106, (%esp)
	movl	$1, %edi
	movl	%edx, 8(%esp)
	movl	$12, %esi
	movl	%eax, 12(%esp)
	movl	$1, %eax
	movl	%eax, 4(%esp)
	call	_fwrite
	movl	-36(%ebp), %ebx
	movl	$24, %eax
	movl	%eax, 8(%esp)
	movl	$1, %eax
	movl	%ebx, 12(%esp)
	movl	%eax, 4(%esp)
	movl	$LC107, (%esp)
	call	_fwrite
	movl	$1, %eax
	movl	%eax, 16(%esp)
	movl	-32(%ebp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 12(%esp)
	movl	_NcentersXYZ, %eax
	movl	%eax, 8(%esp)
	movl	$LC108, %eax
	movl	%eax, 4(%esp)
	call	_fprintf
	movl	%ebx, 12(%esp)
	movl	$7, %eax
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	movl	$LC109, (%esp)
	call	_fwrite
	movl	%ebx, 12(%esp)
	movl	$1, %ecx
	movl	%ecx, 4(%esp)
	movl	%esi, 8(%esp)
	movl	$LC110, (%esp)
	call	_fwrite
	movl	%ebx, 12(%esp)
	movl	$6, %edx
	movl	$1, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC111, (%esp)
	call	_fwrite
	movl	%ebx, 12(%esp)
	movl	$6, %eax
	movl	%eax, 8(%esp)
	movl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$LC111, (%esp)
	call	_fwrite
	movl	%ebx, 12(%esp)
	movl	$14, %eax
	xorl	%ebx, %ebx
	movl	%eax, 8(%esp)
	movl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$LC112, (%esp)
	call	_fwrite
	cmpl	_NcentersXYZ, %ebx
	jae	L789
	xorl	%esi, %esi
	jmp	L773
	.p2align 4,,7
L813:
	movl	_GeomXYZ, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	-48(%ebp)
	movl	32(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L768
L814:
	movl	_GeomXYZ, %eax
	movl	32(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	-56(%ebp)
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L770
L815:
	movl	_GeomXYZ, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
L799:
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L772
	fldl	LC113
	fldl	-48(%ebp)
	fxch	%st(2)
	fmul	%st(1), %st
	fxch	%st(2)
	fmul	%st(1), %st
	fstpl	-48(%ebp)
	fldl	-56(%ebp)
	fmulp	%st, %st(1)
	fstpl	-56(%ebp)
L772:
	movl	_GeomXYZ, %eax
	incl	%ebx
	movl	$LC114, %edi
	movl	24(%esi,%eax), %eax
	movl	%eax, (%esp)
	fstpl	-88(%ebp)
	call	_atof
	movl	_GeomXYZ, %edx
	fstpl	52(%esp)
	movl	16(%esi,%edx), %eax
	movl	%eax, 48(%esp)
	movl	20(%esi,%edx), %eax
	incl	%eax
	movl	%eax, 44(%esp)
	movl	8(%esi,%edx), %eax
	movl	%eax, 40(%esp)
	fldl	-88(%ebp)
	fstpl	32(%esp)
	fldl	-56(%ebp)
	fstpl	24(%esp)
	fldl	-48(%ebp)
	fstpl	16(%esp)
	movl	4(%esi,%edx), %eax
	addl	$48, %esi
	movl	%ebx, 8(%esp)
	movl	%eax, 12(%esp)
	movl	%edi, 4(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	cmpl	_NcentersXYZ, %ebx
	jae	L789
L773:
	movl	_GeomXYZ, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L813
	movl	_GeomXYZ, %eax
	movl	28(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	-48(%ebp)
	movl	32(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L814
L768:
	movl	_GeomXYZ, %eax
	movl	32(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	-56(%ebp)
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L815
L770:
	movl	_GeomXYZ, %eax
	movl	36(%esi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L799
L789:
	movl	-36(%ebp), %ebx
	movl	$1, %ecx
	movl	%ecx, 4(%esp)
	movl	$LC115, (%esp)
	movl	%ebx, 12(%esp)
	movl	$14, %ebx
	movl	%ebx, 8(%esp)
	xorl	%ebx, %ebx
	call	_fwrite
	movl	$0, -32(%ebp)
	movl	_NcentersXYZ, %ecx
	cmpl	%ecx, %ebx
	jae	L791
	.p2align 4,,15
L817:
	movl	_GeomXYZ, %esi
	leal	(%ebx,%ebx,2), %eax
	sall	$4, %eax
	leal	1(%ebx), %edi
	movl	44(%eax,%esi), %edx
	testl	%edx, %edx
	je	L776
	movl	%eax, -64(%ebp)
	cmpl	%ecx, %edi
	movl	%edi, %edx
	jb	L782
	jmp	L776
	.p2align 4,,7
L780:
	cmpl	%ecx, %esi
	movl	%esi, %edx
	jae	L776
L816:
	movl	_GeomXYZ, %esi
L782:
	movl	-64(%ebp), %ebx
	movl	44(%ebx,%esi), %eax
	leal	1(%edx), %esi
	movl	(%eax,%edx,4), %eax
	testl	%eax, %eax
	je	L780
	movl	%eax, 20(%esp)
	movl	$LC116, %eax
	movl	%esi, 16(%esp)
	movl	%edi, 12(%esp)
	movl	-32(%ebp), %ebx
	movl	%eax, 4(%esp)
	incl	%ebx
	movl	%ebx, 8(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	movl	%ebx, -32(%ebp)
	movl	_NcentersXYZ, %ecx
	movl	%esi, %edx
	cmpl	%ecx, %esi
	jb	L816
	.p2align 4,,15
L776:
	movl	%edi, %ebx
	cmpl	%ecx, %ebx
	jb	L817
L791:
	movl	-36(%ebp), %ebx
	movl	$22, %eax
	movl	$19, %edi
	movl	%eax, 8(%esp)
	movl	$1, %esi
	movl	$1, %eax
	movl	%ebx, 12(%esp)
	movl	%eax, 4(%esp)
	movl	$LC117, (%esp)
	call	_fwrite
	movl	%ebx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC118, (%esp)
	call	_fwrite
	movl	%ebx, (%esp)
	call	_fclose
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_name_file
	movl	%eax, -60(%ebp)
	movl	-28(%ebp), %ebx
	movl	%ebx, (%esp)
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
	jne	L807
L784:
	movl	%esi, (%esp)
	call	_g_strdup
	movl	%eax, _lastdirectory
	movl	_defaultNetWorkProtocol, %eax
	xorl	%ecx, %ecx
	movl	%ecx, 40(%esp)
	movl	$11, %edx
	movl	%edx, 36(%esp)
	movl	%eax, 44(%esp)
	xorl	%eax, %eax
	movl	%eax, 32(%esp)
	xorl	%eax, %eax
	movl	%eax, 28(%esp)
	xorl	%eax, %eax
	movl	%eax, 24(%esp)
	xorl	%eax, %eax
	movl	%esi, 16(%esp)
	movl	%eax, 20(%esp)
	movl	-60(%ebp), %eax
	movl	%edi, 8(%esp)
	movl	%eax, 12(%esp)
	movl	_noeud+44, %eax
	movl	%eax, 4(%esp)
	movl	_treeViewProjects, %eax
	movl	%eax, (%esp)
	call	_CreeFeuille
	movl	%ebx, (%esp)
	call	_g_free
	movl	-60(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	movl	%esi, 8(%ebp)
	addl	$140, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_g_free
L807:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L784
L802:
	movl	%ebx, 4(%esp)
	movl	$1, %esi
	movl	$LC94, (%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	%eax, %ebx
	movl	$LC95, %ecx
	movl	%esi, 8(%esp)
	movl	%ecx, 4(%esp)
	call	_Message
	movl	%ebx, 8(%ebp)
	addl	$140, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_g_free
	.p2align 4,,15
.globl _save_geometry_mol2_file
	.def	_save_geometry_mol2_file;	.scl	2;	.type	32;	.endef
_save_geometry_mol2_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$-5, 12(%ebp)
	movl	8(%ebp), %eax
	je	L822
	leave
	ret
	.p2align 4,,7
L822:
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	testl	%eax, %eax
	je	L821
	cmpb	$0, (%eax)
	jne	L820
L821:
	movl	$LC104, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC75, %eax
	movl	%eax, 4(%esp)
	call	_Message
	leave
	ret
L820:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_mol2_file
	.p2align 4,,15
.globl _save_mol2_file_entry
	.def	_save_mol2_file_entry;	.scl	2;	.type	32;	.endef
_save_mol2_file_entry:
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
	je	L823
	cmpb	$0, (%eax)
	jne	L826
L823:
	leave
	ret
	.p2align 4,,7
L826:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_mol2_file
	.p2align 4,,15
	.def	_ChangeVariablesXYZUseds;	.scl	3;	.type	32;	.endef
_ChangeVariablesXYZUseds:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	cmpl	_NVariablesXYZ, %eax
	movl	$0, -16(%ebp)
	jae	L843
	movl	$0, -36(%ebp)
	movl	_NcentersXYZ, %edx
	movl	_GeomXYZ, %eax
	movl	$0, -40(%ebp)
	movl	_VariablesXYZ, %esi
	movl	%edx, -28(%ebp)
	movl	%eax, -32(%ebp)
	movl	$0, -44(%ebp)
	movl	$0, -48(%ebp)
	.p2align 4,,15
L841:
	movl	$0, -24(%ebp)
	movl	-28(%ebp), %edx
	cmpl	%edx, -24(%ebp)
	movl	$0, -20(%ebp)
	jae	L832
	xorl	%edi, %edi
	jmp	L840
	.p2align 4,,7
L834:
	movl	-32(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	32(%edi,%eax), %ebx
	movl	%ebx, 4(%esp)
	movl	(%edx,%esi), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L839
	cmpb	$45, (%ebx)
	je	L845
L836:
	movl	-32(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	36(%edi,%eax), %ebx
	movl	%ebx, 4(%esp)
	movl	(%edx,%esi), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L839
	cmpb	$45, (%ebx)
	je	L846
L833:
	incl	-20(%ebp)
	addl	$48, %edi
	movl	-28(%ebp), %eax
	cmpl	%eax, -20(%ebp)
	jae	L832
L840:
	movl	-32(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	28(%edi,%eax), %ebx
	movl	%ebx, 4(%esp)
	movl	(%edx,%esi), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L839
	cmpb	$45, (%ebx)
	jne	L834
	movl	-36(%ebp), %edx
	leal	1(%ebx), %eax
	movl	%eax, 4(%esp)
	movl	(%edx,%esi), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L834
L839:
	movl	$1, -24(%ebp)
	.p2align 4,,15
L832:
	incl	-16(%ebp)
	movl	-40(%ebp), %edx
	movl	-24(%ebp), %eax
	addl	$12, -48(%ebp)
	addl	$12, -44(%ebp)
	movl	%eax, 8(%esi,%edx,4)
	addl	$3, %edx
	movl	%edx, -40(%ebp)
	movl	-16(%ebp), %edx
	addl	$12, -36(%ebp)
	cmpl	_NVariablesXYZ, %edx
	jb	L841
L843:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L845:
	movl	-48(%ebp), %edx
	leal	1(%ebx), %eax
	movl	%eax, 4(%esp)
	movl	(%edx,%esi), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L836
	jmp	L839
	.p2align 4,,7
L846:
	movl	-44(%ebp), %edx
	leal	1(%ebx), %eax
	movl	%eax, 4(%esp)
	movl	(%edx,%esi), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L833
	jmp	L839
	.p2align 4,,15
.globl _AllocationVariableXYZ
	.def	_AllocationVariableXYZ;	.scl	2;	.type	32;	.endef
_AllocationVariableXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	_VariablesXYZ, %edx
	testl	%edx, %edx
	je	L848
	movl	_NVariablesXYZ, %eax
	movl	%edx, (%esp)
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	%eax, 4(%esp)
	call	_g_realloc
	movl	%eax, _VariablesXYZ
	leave
	ret
	.p2align 4,,7
L848:
	movl	_NVariablesXYZ, %eax
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, _VariablesXYZ
	leave
	ret
	.p2align 4,,15
.globl _show_geom_in_list
	.def	_show_geom_in_list;	.scl	2;	.type	32;	.endef
_show_geom_in_list:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$64, %esp
	movl	8(%ebp), %esi
	movl	$LC72, (%esp)
	leal	1(%esi), %eax
	leal	(%esi,%esi,2), %ebx
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -56(%ebp)
	movl	_GeomXYZ, %eax
	sall	$4, %ebx
	movl	4(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -52(%ebp)
	movl	_GeomXYZ, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -40(%ebp)
	movl	_GeomXYZ, %eax
	movl	8(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -48(%ebp)
	movl	_GeomXYZ, %eax
	movl	12(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -44(%ebp)
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -36(%ebp)
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -32(%ebp)
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -28(%ebp)
	movl	_GeomXYZ, %eax
	movl	24(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -24(%ebp)
	movl	_GeomXYZ, %eax
	movl	40(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -20(%ebp)
	movl	_list, %eax
	movl	%esi, %edx
	call	_removeFromList
	movl	$10, %eax
	movl	%esi, %edx
	movl	%eax, 4(%esp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	_list, %eax
	call	_insertToList
	addl	$64, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,15
.globl _ModifyCoordXYZ
	.def	_ModifyCoordXYZ;	.scl	2;	.type	32;	.endef
_ModifyCoordXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movzbl	8(%ebp), %edx
	movl	%ebx, -12(%ebp)
	movl	16(%ebp), %ecx
	movl	%esi, -8(%ebp)
	movl	12(%ebp), %ebx
	movl	%edi, -4(%ebp)
	cmpb	$88, %dl
	je	L859
	cmpb	$89, %dl
	je	L860
	xorl	%eax, %eax
	cmpb	$90, %dl
	je	L861
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L859:
	leal	(%ecx,%ecx,2), %eax
	movl	_VariablesXYZ, %edi
	leal	0(,%eax,4), %esi
	movl	_GeomXYZ, %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	movl	%eax, -16(%ebp)
	movl	(%esi,%edi), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	28(%ebx,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L862
L858:
	movl	$1, %eax
L863:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L860:
	leal	(%ecx,%ecx,2), %eax
	movl	_VariablesXYZ, %edi
	leal	0(,%eax,4), %esi
	movl	_GeomXYZ, %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	movl	%eax, -20(%ebp)
	movl	(%esi,%edi), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %edx
	movl	32(%ebx,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L858
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-20(%ebp), %edx
	movl	%eax, 32(%ebx,%edx)
	movl	$1, %eax
	jmp	L863
	.p2align 4,,7
L861:
	leal	(%ecx,%ecx,2), %eax
	movl	_VariablesXYZ, %edi
	leal	0(,%eax,4), %esi
	movl	_GeomXYZ, %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	movl	%eax, -24(%ebp)
	movl	(%esi,%edi), %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	36(%ebx,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L858
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-24(%ebp), %edx
	movl	%eax, 36(%ebx,%edx)
	movl	$1, %eax
	jmp	L863
L862:
	movl	4(%esi,%edi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-16(%ebp), %edx
	movl	%eax, 28(%ebx,%edx)
	movl	$1, %eax
	jmp	L863
	.p2align 4,,15
.globl _OneVariableToConstXYZ
	.def	_OneVariableToConstXYZ;	.scl	2;	.type	32;	.endef
_OneVariableToConstXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	8(%ebp), %eax
	movl	_VariablesXYZ, %edx
	movl	%eax, -16(%ebp)
	leal	(%eax,%eax,2), %eax
	movl	8(%edx,%eax,4), %eax
	testl	%eax, %eax
	je	L864
	xorl	%edi, %edi
	cmpl	_NcentersXYZ, %edi
	jae	L878
	.p2align 4,,15
L883:
	movl	-16(%ebp), %ecx
	movl	%edi, 4(%esp)
	movl	$88, (%esp)
	movl	%ecx, 8(%esp)
	call	_ModifyCoordXYZ
	movl	%eax, %ebx
	movl	-16(%ebp), %eax
	movl	%edi, 4(%esp)
	movl	$89, (%esp)
	movl	%eax, 8(%esp)
	call	_ModifyCoordXYZ
	movl	-16(%ebp), %ecx
	addl	%eax, %ebx
	movl	%edi, 4(%esp)
	movl	$90, (%esp)
	movl	%ecx, 8(%esp)
	call	_ModifyCoordXYZ
	addl	%eax, %ebx
	testl	%ebx, %ebx
	jne	L882
	incl	%edi
L884:
	cmpl	_NcentersXYZ, %edi
	jb	L883
L878:
	movl	_NVariablesXYZ, %ecx
	movl	-16(%ebp), %edi
	leal	-1(%ecx), %eax
	cmpl	%edi, %eax
	jbe	L880
	movl	_VariablesXYZ, %edx
	leal	(%edi,%edi,2), %eax
	leal	0(,%eax,4), %esi
	.p2align 4,,15
L874:
	leal	(%esi,%edx), %ebx
	incl	%edi
	movl	12(%ebx), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, (%ebx)
	movl	_VariablesXYZ, %ebx
	movl	16(%ebx,%esi), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%esi,%ebx)
	movl	_VariablesXYZ, %edx
	movl	_NVariablesXYZ, %ecx
	movl	20(%edx,%esi), %eax
	movl	%eax, 8(%esi,%edx)
	leal	-1(%ecx), %eax
	addl	$12, %esi
	cmpl	%edi, %eax
	ja	L874
L880:
	leal	-1(%ecx), %eax
	testl	%eax, %eax
	movl	%eax, _NVariablesXYZ
	je	L875
	call	_AllocationVariableXYZ
	movl	-16(%ebp), %edx
	movl	_listv, %eax
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_removeFromList
	.p2align 4,,7
L864:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L882:
	movl	%edi, (%esp)
	incl	%edi
	call	_show_geom_in_list
	jmp	L884
L875:
	call	_freeVariablesXYZ
	movl	-16(%ebp), %edx
	movl	_listv, %eax
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_removeFromList
	.p2align 4,,15
.globl _trans_allVariables_to_Constants
	.def	_trans_allVariables_to_Constants;	.scl	2;	.type	32;	.endef
_trans_allVariables_to_Constants:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$44, %esp
	movl	_NVariablesXYZ, %eax
	movl	$0, -20(%ebp)
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -24(%ebp)
	movl	_NVariablesXYZ, %eax
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -28(%ebp)
	movl	_NVariablesXYZ, %eax
	cmpl	%eax, %esi
	jae	L910
	movl	$0, -40(%ebp)
	movl	_VariablesXYZ, %edi
	movl	$0, -44(%ebp)
	jmp	L894
	.p2align 4,,7
L912:
	incl	-20(%ebp)
	xorl	%ecx, %ecx
	movl	-24(%ebp), %eax
	movl	-40(%ebp), %edx
	movl	$1, (%eax,%esi,4)
	movl	_NVariablesXYZ, %eax
	movl	%ecx, 8(%edx,%edi)
L888:
	addl	$12, -44(%ebp)
	incl	%esi
	addl	$12, -40(%ebp)
	cmpl	%eax, %esi
	jae	L910
L894:
	movl	-24(%ebp), %edx
	movl	-44(%ebp), %ecx
	movl	$0, (%edx,%esi,4)
	movl	8(%ecx,%edi), %ebx
	testl	%ebx, %ebx
	je	L888
	xorl	%ebx, %ebx
	cmpl	_NcentersXYZ, %ebx
	jae	L912
	.p2align 4,,15
L893:
	movl	%ebx, 4(%esp)
	movl	%esi, 8(%esp)
	movl	$88, (%esp)
	call	_ModifyCoordXYZ
	movl	%ebx, 4(%esp)
	movl	%esi, 8(%esp)
	movl	$89, (%esp)
	call	_ModifyCoordXYZ
	movl	%ebx, 4(%esp)
	incl	%ebx
	movl	%esi, 8(%esp)
	movl	$90, (%esp)
	call	_ModifyCoordXYZ
	cmpl	_NcentersXYZ, %ebx
	jb	L893
	movl	_VariablesXYZ, %edi
	jmp	L912
L910:
	xorl	%esi, %esi
	cmpl	%eax, %esi
	jae	L914
	movl	_VariablesXYZ, %edi
	xorl	%ebx, %ebx
	.p2align 4,,15
L898:
	movl	(%ebx,%edi), %eax
	incl	%esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-28(%ebp), %ecx
	movl	%eax, (%ebx,%ecx)
	movl	_VariablesXYZ, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-28(%ebp), %edx
	movl	_VariablesXYZ, %edi
	movl	%eax, 4(%ebx,%edx)
	movl	8(%ebx,%edi), %eax
	movl	%eax, 8(%ebx,%edx)
	movl	_NVariablesXYZ, %eax
	addl	$12, %ebx
	cmpl	%eax, %esi
	jb	L898
L914:
	movl	%eax, -16(%ebp)
	xorl	%esi, %esi
	call	_freeVariablesXYZ
	movl	-16(%ebp), %eax
	movl	-20(%ebp), %edx
	subl	%edx, %eax
	movl	%eax, _NVariablesXYZ
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	cmpl	-16(%ebp), %esi
	movl	%eax, %edi
	movl	%eax, _VariablesXYZ
	jae	L916
	movl	$0, -32(%ebp)
	movl	$-12, -36(%ebp)
	jmp	L903
	.p2align 4,,7
L901:
	addl	$12, -32(%ebp)
	incl	%esi
	cmpl	-16(%ebp), %esi
	jae	L916
L903:
	movl	-24(%ebp), %ecx
	movl	(%ecx,%esi,4), %eax
	testl	%eax, %eax
	jne	L901
	addl	$12, -36(%ebp)
	incl	%esi
	movl	-32(%ebp), %edx
	movl	-28(%ebp), %ecx
	movl	(%edx,%ecx), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-36(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	_VariablesXYZ, %ebx
	movl	%eax, (%edx,%edi)
	movl	-28(%ebp), %edx
	movl	4(%ecx,%edx), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-36(%ebp), %ecx
	movl	-32(%ebp), %edx
	movl	_VariablesXYZ, %edi
	movl	%eax, 4(%ecx,%ebx)
	movl	-28(%ebp), %ecx
	addl	$12, -32(%ebp)
	cmpl	-16(%ebp), %esi
	movl	8(%edx,%ecx), %eax
	movl	-36(%ebp), %edx
	movl	%eax, 8(%edx,%edi)
	jb	L903
L916:
	movl	_listv, %eax
	xorl	%esi, %esi
	call	_clearList
	call	_append_VariablesXYZ_in_list
	movl	_list, %eax
	call	_clearList
	call	_append_list
	cmpl	_NVariablesXYZ, %esi
	jae	L918
	xorl	%ebx, %ebx
	.p2align 4,,15
L907:
	movl	-28(%ebp), %ecx
	incl	%esi
	movl	(%ebx,%ecx), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-28(%ebp), %edx
	movl	4(%ebx,%edx), %eax
	addl	$12, %ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	_NVariablesXYZ, %esi
	jb	L907
L918:
	movl	-28(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_free
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L919
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L919:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_rafresh_drawing
	.p2align 4,,15
.globl _AddVariableXYZ
	.def	_AddVariableXYZ;	.scl	2;	.type	32;	.endef
_AddVariableXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ebx, -12(%ebp)
	movl	%esi, -8(%ebp)
	movl	8(%ebp), %esi
	movl	%edi, -4(%ebp)
	movl	12(%ebp), %edi
	incl	_NVariablesXYZ
	call	_AllocationVariableXYZ
	movl	_NVariablesXYZ, %ebx
	movl	_VariablesXYZ, %eax
	movl	%esi, (%esp)
	leal	(%ebx,%ebx,2), %ebx
	sall	$2, %ebx
	addl	%eax, %ebx
	call	_g_strdup
	movl	%eax, -12(%ebx)
	movl	_NVariablesXYZ, %ebx
	movl	_VariablesXYZ, %eax
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
	movl	16(%ebp), %esi
	testl	%esi, %esi
	jne	L922
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L922:
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
LC120:
	.ascii "%c%s%d\0"
	.text
	.p2align 4,,15
.globl _trans_coordXYZ
	.def	_trans_coordXYZ;	.scl	2;	.type	32;	.endef
_trans_coordXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	12(%ebp), %edx
	movzbl	8(%ebp), %eax
	leal	(%edx,%edx,2), %ebx
	sall	$4, %ebx
	movb	%al, -25(%ebp)
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	cmpb	$89, -25(%ebp)
	fstpl	-40(%ebp)
	je	L949
	cmpb	$90, -25(%ebp)
	je	L950
L925:
	movl	12(%ebp), %eax
	incl	%eax
	movl	%eax, 12(%esp)
	movl	_GeomXYZ, %eax
	movl	4(%ebx,%eax), %eax
	movl	%eax, 8(%esp)
	movsbl	-25(%ebp),%eax
	movl	%eax, -56(%ebp)
	movl	%eax, 4(%esp)
	movl	$LC120, (%esp)
	call	_g_strdup_printf
	movl	%eax, -44(%ebp)
	movl	12(%ebp), %eax
	movl	12(%ebp), %edx
	leal	(%eax,%eax,2), %eax
	addl	$2, %edx
	sall	$4, %eax
	movl	%edx, -52(%ebp)
	movl	%eax, -64(%ebp)
L933:
	movl	_NVariablesXYZ, %edx
	xorl	%esi, %esi
	cmpl	$0, %edx
	movl	%edx, -60(%ebp)
	jle	L945
	movl	_VariablesXYZ, %edi
	xorl	%ebx, %ebx
	.p2align 4,,15
L932:
	movl	(%ebx,%edi), %eax
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L951
	incl	%esi
	addl	$12, %ebx
	cmpl	%esi, -60(%ebp)
	jg	L932
L945:
	fldl	-40(%ebp)
	movl	$LC58, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, -48(%ebp)
	movl	-44(%ebp), %eax
	call	_testav
	testl	%eax, %eax
	movl	%eax, %esi
	js	L935
	movl	_VariablesXYZ, %edi
	leal	(%eax,%eax,2), %eax
	leal	0(,%eax,4), %ebx
	movl	4(%ebx,%edi), %eax
	testl	%eax, %eax
	jne	L952
L936:
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx,%edi)
	movl	16(%ebp), %eax
	testl	%eax, %eax
	jne	L953
L934:
	cmpb	$88, -25(%ebp)
	je	L954
L958:
	cmpb	$89, -25(%ebp)
	je	L955
	cmpb	$90, -25(%ebp)
	je	L956
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L951:
	movl	-52(%ebp), %edx
	movl	_GeomXYZ, %eax
	movl	%edx, 12(%esp)
	movl	-64(%ebp), %edx
	movl	4(%edx,%eax), %eax
	movl	%eax, 8(%esp)
	movl	-56(%ebp), %eax
	movl	$LC120, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	incl	-52(%ebp)
	movl	%eax, -44(%ebp)
	jmp	L933
L953:
	movl	_VariablesXYZ, %edx
	movl	(%ebx,%edx), %eax
	movl	%eax, -24(%ebp)
	movl	4(%ebx,%edx), %eax
	movl	%esi, %edx
	movl	%eax, -20(%ebp)
	movl	_listv, %eax
	call	_removeFromList
	movl	$2, %eax
	movl	%esi, %edx
	movl	%eax, 4(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	_listv, %eax
	call	_insertToList
	cmpb	$88, -25(%ebp)
	jne	L958
L954:
	movl	12(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	_GeomXYZ, %esi
	leal	(%eax,%eax,2), %ebx
	sall	$4, %ebx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 28(%ebx,%esi)
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L952:
	movl	%eax, (%esp)
	call	_g_free
	movl	_VariablesXYZ, %edi
	jmp	L936
L949:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
L948:
	movl	%eax, (%esp)
	call	_atof
	fstpl	-40(%ebp)
	jmp	L925
L950:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	jmp	L948
L955:
	movl	12(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	_GeomXYZ, %esi
	leal	(%eax,%eax,2), %ebx
	sall	$4, %ebx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 32(%ebx,%esi)
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L956:
	movl	12(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	_GeomXYZ, %esi
	leal	(%eax,%eax,2), %ebx
	sall	$4, %ebx
	movl	%edx, (%esp)
	call	_g_strdup
	movl	%eax, 36(%ebx,%esi)
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L935:
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	call	_AddVariableXYZ
	jmp	L934
	.p2align 4,,15
.globl _set_variable_one_atom_in_GeomXYZ
	.def	_set_variable_one_atom_in_GeomXYZ;	.scl	2;	.type	32;	.endef
_set_variable_one_atom_in_GeomXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	8(%ebp), %esi
	movl	_GeomXYZ, %eax
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L963
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L964
L961:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L965
L962:
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	jmp	_ChangeVariablesXYZUseds
	.p2align 4,,7
L963:
	movl	%esi, 4(%esp)
	xorl	%edx, %edx
	movl	%edx, 8(%esp)
	movl	$88, (%esp)
	call	_trans_coordXYZ
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L961
	.p2align 4,,15
L964:
	movl	%esi, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$89, (%esp)
	call	_trans_coordXYZ
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L962
	.p2align 4,,15
L965:
	movl	%esi, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$90, (%esp)
	call	_trans_coordXYZ
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	jmp	_ChangeVariablesXYZUseds
	.p2align 4,,15
.globl _trans_OneGeomXYZ_to_variables
	.def	_trans_OneGeomXYZ_to_variables;	.scl	2;	.type	32;	.endef
_trans_OneGeomXYZ_to_variables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	8(%ebp), %esi
	movl	_GeomXYZ, %eax
	leal	(%esi,%esi,2), %ebx
	sall	$4, %ebx
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L970
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L971
L968:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L972
L969:
	movl	%esi, (%esp)
	call	_show_geom_in_list
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	jmp	_ChangeVariablesXYZUseds
	.p2align 4,,7
L970:
	movl	%esi, 4(%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$88, (%esp)
	call	_trans_coordXYZ
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L968
	.p2align 4,,15
L971:
	movl	%esi, 4(%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$89, (%esp)
	call	_trans_coordXYZ
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L969
	.p2align 4,,15
L972:
	movl	%esi, 4(%esp)
	movl	$1, %ecx
	movl	%ecx, 8(%esp)
	movl	$90, (%esp)
	call	_trans_coordXYZ
	movl	%esi, (%esp)
	call	_show_geom_in_list
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	jmp	_ChangeVariablesXYZUseds
	.p2align 4,,15
.globl _trans_allGeomXYZ_to_variables
	.def	_trans_allGeomXYZ_to_variables;	.scl	2;	.type	32;	.endef
_trans_allGeomXYZ_to_variables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$4, %esp
	movl	_NcentersXYZ, %eax
	testl	%eax, %eax
	je	L973
	xorl	%ebx, %ebx
	cmpl	%eax, %ebx
	jae	L981
	.p2align 4,,15
L983:
	movl	%ebx, (%esp)
	incl	%ebx
	call	_trans_OneGeomXYZ_to_variables
	cmpl	_NcentersXYZ, %ebx
	jb	L983
L981:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L973
	popl	%eax
	popl	%ebx
	popl	%ebp
	jmp	_rafresh_drawing
	.p2align 4,,7
L973:
	popl	%eax
	popl	%ebx
	popl	%ebp
	ret
	.section .rdata,"dr"
LC126:
	.ascii "0.0\0"
	.align 8
LC125:
	.long	-1433277178
	.long	1066524486
	.align 8
LC127:
	.long	-1717986918
	.long	1072273817
	.align 8
LC128:
	.long	640652440
	.long	1071705861
	.align 8
LC129:
	.long	0
	.long	1088421824
	.align 8
LC130:
	.long	0
	.long	1078853632
	.text
	.p2align 4,,15
	.def	_set_entry_XYZ;	.scl	3;	.type	32;	.endef
_set_entry_XYZ:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$1008, %esp
	call	_rand
	pushl	%eax
	fildl	(%esp)
	addl	$4, %esp
	fstpl	-920(%ebp)
	fldl	LC129
	fdivrl	-920(%ebp)
	fstpl	-920(%ebp)
	fldl	LC130
	fmull	-920(%ebp)
	fstpl	-920(%ebp)
	fldl	LC125
	fmull	-920(%ebp)
	fstpl	-920(%ebp)
	call	_rand
	pushl	%eax
	movl	_NcentersXYZ, %ecx
	fildl	(%esp)
	addl	$4, %esp
	testl	%ecx, %ecx
	fstpl	-928(%ebp)
	fldl	LC129
	fdivrl	-928(%ebp)
	fstpl	-928(%ebp)
	fldl	LC130
	fmull	-928(%ebp)
	fstpl	-928(%ebp)
	fldl	LC125
	fmull	-928(%ebp)
	fstpl	-928(%ebp)
	jne	L985
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	$LC126, %esi
	movl	_Entry+20, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC126, %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
	movl	_Entry+24, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
	movl	_Entry+28, %eax
	movl	$LC126, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L985:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	_Entry+4, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, 4(%esp)
	leal	-872(%ebp), %edx
	movl	%edx, (%esp)
	call	_prop_atom_get
	movl	_NcentersXYZ, %eax
	subl	$4, %esp
	leal	-584(%ebp), %edx
	movl	_GeomXYZ, %ecx
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%ecx, %eax
	movl	-44(%eax), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_prop_atom_get
	fldl	-568(%ebp)
	subl	$4, %esp
	faddl	-856(%ebp)
	cmpl	$1, _Units
	fmull	LC127
	fstl	-912(%ebp)
	je	L997
	fstp	%st(0)
L987:
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %edx
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%edx, %eax
	movl	-20(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L988
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %esi
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%esi, %eax
	movl	-20(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	fstpl	-936(%ebp)
	fldl	-920(%ebp)
	fstpl	(%esp)
	call	_sin
	fmull	-912(%ebp)
	fldl	-928(%ebp)
	fstpl	(%esp)
	fstpl	-1000(%ebp)
	call	_cos
	fldl	-1000(%ebp)
	fmulp	%st, %st(1)
	faddl	-936(%ebp)
L994:
	fstpl	-904(%ebp)
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %ecx
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%ecx, %eax
	movl	-16(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L990
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %edx
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%edx, %eax
	movl	-16(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	fstpl	-952(%ebp)
	fldl	-920(%ebp)
	fstpl	(%esp)
	call	_sin
	fmull	-912(%ebp)
	fldl	-928(%ebp)
	fstpl	(%esp)
	fstpl	-1000(%ebp)
	call	_sin
	fldl	-1000(%ebp)
	fmulp	%st, %st(1)
	faddl	-952(%ebp)
L995:
	fstpl	-896(%ebp)
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %ebx
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%ebx, %eax
	movl	-12(%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L992
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %ecx
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%ecx, %eax
	movl	-12(%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	fstpl	-968(%ebp)
	fldl	-920(%ebp)
	fstpl	(%esp)
	call	_cos
	fmull	-912(%ebp)
	fstpl	-912(%ebp)
	fldl	-968(%ebp)
L996:
	faddl	-912(%ebp)
	fstpl	-888(%ebp)
	fldl	-904(%ebp)
	movl	$LC58, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	_Entry+20, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	fldl	-896(%ebp)
	movl	$LC58, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%esi, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+24, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	fldl	-888(%ebp)
	movl	$LC58, (%esp)
	fstpl	4(%esp)
	call	_g_strdup_printf
	movl	%esi, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+28, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, (%esp)
	call	_g_free
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L992:
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %edx
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%edx, %eax
	movl	-12(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	fstpl	-976(%ebp)
	fldl	-920(%ebp)
	fstpl	(%esp)
	call	_cos
	fmull	-912(%ebp)
	fstpl	-912(%ebp)
	fldl	-976(%ebp)
	jmp	L996
	.p2align 4,,7
L990:
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %esi
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%esi, %eax
	movl	-16(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	fstpl	-960(%ebp)
	fldl	-920(%ebp)
	fstpl	(%esp)
	call	_sin
	fmull	-912(%ebp)
	fldl	-928(%ebp)
	fstpl	(%esp)
	fstpl	-1000(%ebp)
	call	_sin
	fldl	-1000(%ebp)
	fmulp	%st, %st(1)
	faddl	-960(%ebp)
	jmp	L995
	.p2align 4,,7
L988:
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %ebx
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%ebx, %eax
	movl	-20(%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	fstpl	-944(%ebp)
	fldl	-920(%ebp)
	fstpl	(%esp)
	call	_sin
	fmull	-912(%ebp)
	fldl	-928(%ebp)
	fstpl	(%esp)
	fstpl	-1000(%ebp)
	call	_cos
	fldl	-1000(%ebp)
	fmulp	%st, %st(1)
	faddl	-944(%ebp)
	jmp	L994
	.p2align 4,,7
L997:
	fmull	LC128
	fstpl	-912(%ebp)
	jmp	L987
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
	movl	_Entry+4, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
	movl	_Entry+8, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
	movl	_Entry+12, %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, 4(%esp)
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
	jmp	_set_entry_XYZ
	.section .rdata,"dr"
LC132:
	.ascii "Select your atom\0"
LC135:
	.ascii "00\0"
LC136:
	.ascii "clicked\0"
	.align 8
LC133:
	.long	-1717986918
	.long	1071225241
	.align 4
LC134:
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
	movl	$LC132, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	movl	$18, %edi
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
	fmull	LC133
	orw	$3072, %dx
	movw	%dx, -16(%ebp)
	fldcw	-16(%ebp)
	fistpl	8(%esp)
	fldcw	-14(%ebp)
	fildl	_ScreenWidth
	fmuls	LC134
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
	movl	%edi, 4(%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$9, (%esp)
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
L1009:
	movl	$0, -28(%ebp)
	movl	-24(%ebp), %ecx
	incl	%ecx
	movl	%ecx, -40(%ebp)
	jmp	L1008
	.p2align 4,,7
L1006:
	movl	%esi, -28(%ebp)
	cmpl	$17, %esi
	ja	L1015
L1008:
	cld
	movl	-28(%ebp), %esi
	movl	$LC135, %edi
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
	je	L1006
	movl	%ebx, (%esp)
	call	_gtk_button_new_with_label
	movl	-36(%ebp), %edx
	movl	%eax, %ebx
	movl	$_SetAtom, %edi
	movl	-28(%ebp), %esi
	movl	-24(%ebp), %ecx
	movl	(%edx,%esi,4), %eax
	movl	(%eax,%ecx,4), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-32(%ebp), %esi
	movl	%esi, (%esp)
	movl	$80, %esi
	call	_set_button_style
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	-28(%ebp), %ecx
	movl	-36(%ebp), %esi
	movl	(%esi,%ecx,4), %edx
	movl	-24(%ebp), %ecx
	movl	$LC136, %esi
	movl	(%edx,%ecx,4), %edx
	movl	%edi, 8(%esp)
	movl	$5, %edi
	movl	%edx, 12(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	call	_gtk_table_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %esi
	movl	%esi, (%esp)
	movl	$5, %esi
	call	_g_type_check_instance_cast
	movl	%edi, 28(%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 36(%esp)
	movl	%edx, 32(%esp)
	movl	%esi, 24(%esp)
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
	jbe	L1008
	.p2align 4,,15
L1015:
	movl	-40(%ebp), %ecx
	cmpl	$8, %ecx
	movl	%ecx, -24(%ebp)
	jbe	L1009
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
	movl	_NcentersXYZ, %eax
	decl	%eax
	cmpl	$-1, %eax
	movl	%eax, _NcentersXYZ
	jle	L1017
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	movl	%eax, 4(%esp)
	movl	_GeomXYZ, %eax
	movl	%eax, (%esp)
	call	_g_realloc
	movl	%eax, _GeomXYZ
	movl	_NcentersXYZ, %edx
	movl	_list, %eax
	call	_removeFromList
L1018:
	call	_ChangeVariablesXYZUseds
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1021
	cmpl	$1, _iprogram
	je	L1022
L1016:
	leave
	ret
	.p2align 4,,7
L1021:
	call	_rafresh_drawing
	cmpl	$1, _iprogram
	jne	L1016
	.p2align 4,,15
L1022:
	leave
	jmp	_set_spin_of_electrons
	.p2align 4,,7
L1017:
	call	_freeGeomXYZ
	jmp	L1018
	.section .rdata,"dr"
LC138:
	.ascii "Sorry a Entry text is void !\12\0"
	.text
	.p2align 4,,15
	.def	_AddAtom;	.scl	3;	.type	32;	.endef
_AddAtom:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	$1, %esi
	pushl	%ebx
	subl	$92, %esp
	movl	_NcentersXYZ, %eax
	movl	%esi, _DestroyDialog
	movl	$5, %esi
	incl	%eax
	movl	%eax, 4(%esp)
	movl	$LC72, (%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp)
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
	movl	%eax, -68(%ebp)
	movl	_Entry+8, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -64(%ebp)
	movl	_Entry+12, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -60(%ebp)
	movl	_Entry+16, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -56(%ebp)
	call	_gtk_entry_get_type
L1030:
	movl	%ebx, 4(%esp)
	movl	_Entry(,%esi,4), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp,%esi,4)
	testl	%eax, %eax
	je	L1028
	cmpb	$0, (%eax)
	je	L1028
	call	_testav
	incl	%eax
	jl	L1062
	incl	%esi
	cmpl	$7, %esi
	jle	L1030
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+32, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	cmpl	$3, _iprogram
	movl	%eax, -40(%ebp)
	je	L1066
	movl	%ebx, 4(%esp)
	movl	_Entry+36, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
L1063:
	call	_g_strdup
	movl	%eax, -36(%ebp)
	movl	_NcentersXYZ, %edx
	movl	_GeomXYZ, %ecx
	incl	%edx
	testl	%ecx, %ecx
	movl	%edx, _NcentersXYZ
	jne	L1033
	movl	$48, (%esp)
	call	_g_malloc
L1064:
	movl	%eax, _GeomXYZ
	movl	_NcentersXYZ, %edx
	testl	%edx, %edx
	je	L1056
	leal	44(%eax), %eax
	movl	%edx, %esi
	.p2align 4,,15
L1038:
	movl	$0, (%eax)
	addl	$48, %eax
	decl	%esi
	jne	L1038
L1056:
	movl	$5, %esi
L1043:
	movl	-72(%ebp,%esi,4), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1067
L1041:
	incl	%esi
	cmpl	$7, %esi
	jle	L1043
	movl	_NcentersXYZ, %eax
	movl	_GeomXYZ, %edx
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	addl	%edx, %eax
	leal	-48(%eax), %ebx
	movl	$10, -48(%eax)
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%ebx)
	movl	_NcentersXYZ, %ebx
	movl	_GeomXYZ, %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	addl	%eax, %ebx
	movl	-64(%ebp), %eax
	subl	$48, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%ebx)
	movl	_NcentersXYZ, %ebx
	movl	_GeomXYZ, %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	addl	%eax, %ebx
	movl	-60(%ebp), %eax
	subl	$48, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 12(%ebx)
	movl	_NcentersXYZ, %ebx
	movl	_GeomXYZ, %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	addl	%eax, %ebx
	movl	-56(%ebp), %eax
	subl	$48, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 16(%ebx)
	movl	_NcentersXYZ, %ebx
	movl	_GeomXYZ, %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	addl	%eax, %ebx
	movl	-52(%ebp), %eax
	subl	$48, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%ebx)
	movl	_NcentersXYZ, %ebx
	movl	_GeomXYZ, %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	addl	%eax, %ebx
	movl	-48(%ebp), %eax
	subl	$48, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 32(%ebx)
	movl	_NcentersXYZ, %ebx
	movl	_GeomXYZ, %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	addl	%eax, %ebx
	movl	-44(%ebp), %eax
	subl	$48, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 36(%ebx)
	movl	_NcentersXYZ, %ebx
	movl	_GeomXYZ, %edi
	movl	-40(%ebp), %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	addl	%edi, %ebx
	subl	$48, %ebx
	call	_g_strdup
	movl	%eax, 24(%ebx)
	movl	_NcentersXYZ, %ebx
	movl	_GeomXYZ, %esi
	movl	-36(%ebp), %eax
	leal	(%ebx,%ebx,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	addl	%esi, %ebx
	subl	$48, %ebx
	call	_g_strdup
	movl	%eax, 40(%ebx)
	movl	_NcentersXYZ, %edx
	movl	_GeomXYZ, %esi
	leal	(%edx,%edx,2), %eax
	sall	$4, %eax
	leal	-48(%eax,%esi), %eax
	movl	$0, 44(%eax)
	cmpl	$1, %edx
	je	L1068
	movl	$0, 20(%eax)
	leal	-1(%edx), %eax
	xorl	%edi, %edi
	cmpl	$0, %eax
	jle	L1061
	movl	%edx, -76(%ebp)
	leal	20(%esi), %ebx
	.p2align 4,,15
L1050:
	leal	(%edx,%edx,2), %eax
	sall	$4, %eax
	leal	-48(%eax,%esi), %ecx
	movl	(%ebx), %eax
	cmpl	%eax, 20(%ecx)
	jge	L1048
	movl	%eax, 20(%ecx)
	movl	-76(%ebp), %edx
L1048:
	incl	%edi
	leal	-1(%edx), %eax
	addl	$48, %ebx
	cmpl	%edi, %eax
	jg	L1050
L1060:
	leal	(%edx,%edx,2), %eax
	sall	$4, %eax
	incl	-28(%esi,%eax)
	call	_ChangeVariablesXYZUseds
	movl	$10, (%esp)
	movl	_list, %eax
	leal	-72(%ebp), %edx
	call	_appendToList
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L1051
L1069:
	call	_rafresh_drawing
	cmpl	$1, _iprogram
	jne	L1023
L1070:
	call	_set_spin_of_electrons
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1067:
	movl	-72(%ebp,%esi,4), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1041
	movl	-72(%ebp,%esi,4), %eax
	movl	$LC78, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp,%esi,4)
	jmp	L1041
L1033:
	movl	%ecx, (%esp)
	leal	(%edx,%edx,2), %eax
	sall	$4, %eax
	movl	%eax, 4(%esp)
	call	_g_realloc
	jmp	L1064
L1068:
	movl	$0, 20(%esi)
	call	_ChangeVariablesXYZUseds
	movl	$10, (%esp)
	movl	_list, %eax
	leal	-72(%ebp), %edx
	call	_appendToList
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1069
	.p2align 4,,15
L1051:
	cmpl	$1, _iprogram
	je	L1070
L1023:
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1066:
	movl	$LC83, (%esp)
	jmp	L1063
L1028:
	movl	$LC138, (%esp)
	movl	$1, %ebx
	movl	$LC75, %ecx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
L1065:
	call	_MessageGeom
	xorl	%eax, %eax
	movl	%eax, _DestroyDialog
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1061:
	movl	_NcentersXYZ, %edx
	jmp	L1060
L1062:
	movl	-72(%ebp,%esi,4), %eax
	movl	$LC80, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$LC75, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	jmp	L1065
	.section .rdata,"dr"
LC139:
	.ascii "Sorry\12 a entry is void \0"
LC140:
	.ascii "Sorry No line selected\0"
	.text
	.p2align 4,,15
	.def	_EditAtom;	.scl	3;	.type	32;	.endef
_EditAtom:
	pushl	%ebp
	movl	$1, %eax
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	movl	%eax, _DestroyDialog
	movl	_LineSelected, %eax
	testl	%eax, %eax
	movl	%eax, -76(%ebp)
	js	L1118
L1072:
	movl	-76(%ebp), %eax
	movl	$LC72, (%esp)
	movl	$5, %esi
	incl	%eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp)
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
	movl	%eax, -68(%ebp)
	movl	_Entry+16, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -56(%ebp)
	movl	_Entry+8, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -64(%ebp)
	movl	_Entry+12, %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -60(%ebp)
	call	_gtk_entry_get_type
L1079:
	movl	%ebx, 4(%esp)
	movl	_Entry(,%esi,4), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -72(%ebp,%esi,4)
	testl	%eax, %eax
	je	L1077
	cmpb	$0, (%eax)
	je	L1077
	call	_testav
	incl	%eax
	jl	L1113
	incl	%esi
	cmpl	$7, %esi
	jle	L1079
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	_Entry+32, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	cmpl	$3, _iprogram
	movl	%eax, -40(%ebp)
	je	L1080
	movl	%ebx, 4(%esp)
	movl	_Entry+36, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, -36(%ebp)
	movl	_LineSelected, %eax
	testl	%eax, %eax
	movl	%eax, -76(%ebp)
	js	L1119
L1082:
	cmpl	$-1, -76(%ebp)
	jle	L1083
	movl	$5, %esi
	.p2align 4,,15
L1088:
	movl	-72(%ebp,%esi,4), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1120
L1086:
	incl	%esi
	cmpl	$7, %esi
	jle	L1088
	movl	-76(%ebp), %ecx
	movl	-56(%ebp), %eax
	movl	_GeomXYZ, %ebx
	leal	(%ecx,%ecx,2), %esi
	sall	$4, %esi
	movl	%eax, 4(%esp)
	movl	16(%esi,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L1089
	movl	$1, %edi
L1089:
	movl	$10, (%esi,%ebx)
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%esi,%ebx)
	movl	-64(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 8(%esi,%ebx)
	movl	-60(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 12(%esi,%ebx)
	movl	-56(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 16(%esi,%ebx)
	movl	-52(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%esi,%ebx)
	movl	-48(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 32(%esi,%ebx)
	movl	-44(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 36(%esi,%ebx)
	movl	-40(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 24(%esi,%ebx)
	movl	-36(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 40(%esi,%ebx)
	testl	%edi, %edi
	jne	L1090
	movl	_GeomXYZ, %eax
	movl	$-1, %edi
	xorl	%ebx, %ebx
	movl	%edi, 20(%esi,%eax)
	movl	_NcentersXYZ, %edi
	movl	%eax, -80(%ebp)
	cmpl	$0, %edi
	jle	L1092
	movl	%esi, -84(%ebp)
	xorl	%esi, %esi
	.p2align 4,,15
L1095:
	cmpl	%ebx, -76(%ebp)
	je	L1093
	movl	-80(%ebp), %edx
	movl	16(%esi,%edx), %eax
	movl	%eax, 4(%esp)
	movl	-84(%ebp), %ecx
	movl	16(%ecx,%edx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	je	L1114
L1093:
	incl	%ebx
	addl	$48, %esi
	cmpl	%ebx, %edi
	jg	L1095
L1092:
	movl	-76(%ebp), %esi
	movl	-80(%ebp), %edx
	leal	(%esi,%esi,2), %eax
	sall	$4, %eax
	cmpl	$-1, 20(%eax,%edx)
	jne	L1090
	movl	_NcentersXYZ, %edi
	xorl	%ebx, %ebx
	cmpl	$0, %edi
	jle	L1112
	movl	%edi, -92(%ebp)
	movl	%eax, %ecx
	addl	$20, %edx
	.p2align 4,,15
L1101:
	movl	-80(%ebp), %esi
	movl	(%edx), %eax
	cmpl	%eax, 20(%ecx,%esi)
	jge	L1099
	movl	%eax, 20(%ecx,%esi)
	movl	-92(%ebp), %edi
L1099:
	incl	%ebx
	addl	$48, %edx
	cmpl	%ebx, %edi
	jg	L1101
L1112:
	movl	-76(%ebp), %edx
	movl	-80(%ebp), %ecx
	leal	(%edx,%edx,2), %eax
	sall	$4, %eax
	incl	20(%eax,%ecx)
	.p2align 4,,15
L1090:
	movl	-76(%ebp), %edx
	movl	$10, %esi
	movl	_list, %eax
	call	_removeFromList
	movl	%esi, 4(%esp)
	leal	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	-76(%ebp), %edx
	movl	_list, %eax
	call	_insertToList
	call	_ChangeVariablesXYZUseds
	movl	_ZoneDessin, %ebx
	testl	%ebx, %ebx
	jne	L1121
	cmpl	$1, _iprogram
	je	L1122
L1071:
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1120:
	movl	-72(%ebp,%esi,4), %eax
	movl	%eax, (%esp)
	call	_testpointeE
	testl	%eax, %eax
	jne	L1086
	movl	-72(%ebp,%esi,4), %eax
	movl	$LC78, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, -72(%ebp,%esi,4)
	jmp	L1086
L1080:
	movl	$LC83, (%esp)
	call	_g_strdup
	movl	%eax, -36(%ebp)
	movl	_LineSelected, %eax
	testl	%eax, %eax
	movl	%eax, -76(%ebp)
	jns	L1082
L1119:
	movl	_LineSelectedOld, %edx
	movl	%edx, -76(%ebp)
	jmp	L1082
L1121:
	call	_rafresh_drawing
	cmpl	$1, _iprogram
	jne	L1071
L1122:
	call	_set_spin_of_electrons
L1116:
	movl	_iprogram, %eax
	decl	%eax
	jne	L1071
	call	_set_spin_of_electrons
	jmp	L1071
L1118:
	movl	_LineSelectedOld, %edx
	movl	%edx, -76(%ebp)
	jmp	L1072
L1077:
	movl	$LC139, (%esp)
	call	_g_strdup_printf
L1117:
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$LC75, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_MessageGeom
	xorl	%eax, %eax
	movl	%eax, _DestroyDialog
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1083:
	movl	$LC140, (%esp)
	movl	$1, %eax
	movl	$LC75, %edi
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	call	_MessageGeom
	jmp	L1116
L1114:
	movl	-80(%ebp), %ecx
	movl	20(%esi,%ecx), %eax
	movl	-84(%ebp), %esi
	movl	%eax, 20(%esi,%ecx)
	jmp	L1092
L1113:
	movl	-72(%ebp,%esi,4), %eax
	movl	$LC80, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	jmp	L1117
	.section .rdata,"dr"
LC141:
	.ascii "\0"
LC142:
	.ascii "-%s\0"
	.text
	.p2align 4,,15
	.def	_get_list_variablesXYZ;	.scl	3;	.type	32;	.endef
_get_list_variablesXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$12, %esp
	xorl	%ebx, %ebx
	movl	_NVariablesXYZ, %eax
	leal	4(,%eax,8), %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	$LC141, (%esp)
	movl	%eax, %edi
	call	_g_strdup
	movl	%eax, (%edi)
	movl	_NVariablesXYZ, %eax
	cmpl	%eax, %ebx
	jae	L1133
	xorl	%esi, %esi
	.p2align 4,,15
L1127:
	movl	_VariablesXYZ, %eax
	movl	(%esi,%eax), %eax
	addl	$12, %esi
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 4(%edi,%ebx,4)
	movl	_NVariablesXYZ, %eax
	incl	%ebx
	cmpl	%eax, %ebx
	jb	L1127
L1133:
	movl	%eax, %ebx
	movl	%eax, %edx
	leal	(%eax,%eax), %eax
	cmpl	%ebx, %eax
	jbe	L1135
	.p2align 4,,15
L1137:
	movl	%ebx, %eax
	subl	%edx, %eax
	movl	_VariablesXYZ, %edx
	leal	(%eax,%eax,2), %eax
	movl	(%edx,%eax,4), %eax
	movl	$LC142, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%edi,%ebx,4)
	movl	_NVariablesXYZ, %edx
	incl	%ebx
	leal	(%edx,%edx), %eax
	cmpl	%ebx, %eax
	ja	L1137
L1135:
	addl	$12, %esp
	movl	%edi, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_freelistvariablesXYZ;	.scl	3;	.type	32;	.endef
_freelistvariablesXYZ:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%edi, -4(%ebp)
	movl	%eax, %edi
	movl	_NVariablesXYZ, %eax
	movl	%ebx, -12(%ebp)
	xorl	%ebx, %ebx
	movl	%esi, -8(%ebp)
	leal	1(%eax,%eax), %esi
	cmpl	%esi, %ebx
	jae	L1144
	.p2align 4,,15
L1146:
	movl	(%edi,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	%esi, %ebx
	jb	L1146
L1144:
	movl	%edi, (%esp)
	call	_g_free
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.section .rdata,"dr"
LC143:
	.ascii " Name : \0"
LC144:
	.ascii " Value : \0"
LC148:
	.ascii "Edit Variable\0"
LC149:
	.ascii " Edit Variable \0"
LC150:
	.ascii "delete_event\0"
LC151:
	.ascii "frame\0"
LC152:
	.ascii "Cancel\0"
LC153:
	.ascii "OK\0"
LC146:
	.ascii "Create variable before \12\0"
LC145:
	.ascii " Warning \0"
LC147:
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
	movl	_LineSelectedV, %eax
	movl	$LC143, -40(%ebp)
	movl	$LC144, -36(%ebp)
	testl	%eax, %eax
	movl	%eax, -28(%ebp)
	js	L1153
	call	_gtk_dialog_new
	movl	%eax, -24(%ebp)
	xorl	%edi, %edi
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC148, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_title
	movl	%ebx, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_position
	movl	%ebx, 4(%esp)
	movl	_Fenetre, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
	movl	%eax, %esi
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_window_set_transient_for
	movl	%ebx, 4(%esp)
	movl	_WindowGeom, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
	movl	%eax, %esi
	movl	-24(%ebp), %edx
	xorl	%ebx, %ebx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	call	_gtk_window_set_transient_for
	movl	$LC149, %eax
	movl	%eax, 12(%esp)
	movl	$_gtk_widget_destroy, %eax
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %ecx
	movl	_WindowGeom, %eax
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_add_child
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_delete_child, %ecx
	movl	$LC150, %edx
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
	movl	-24(%ebp), %edx
	xorl	%esi, %esi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC151, %edx
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
	movl	%eax, -44(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, -48(%ebp)
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
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
	movl	%eax, (%esp)
	movl	%eax, %edi
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
	movl	-40(%ebp), %ecx
	movl	%edx, (%esp)
	movl	%ecx, 4(%esp)
	call	_create_label_entry
	movl	%eax, _EntryV
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	-28(%ebp), %ecx
	leal	(%ecx,%ecx,2), %edx
	leal	0(,%edx,4), %ebx
	movl	_VariablesXYZ, %edx
	movl	(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	_VariablesXYZ, %eax
	movl	8(%ebx,%eax), %eax
	testl	%eax, %eax
	jne	L1154
L1151:
	movl	%edi, (%esp)
	movl	$LC144, %edi
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
	movl	$LC152, %esi
	movl	%eax, _EntryV+4
	call	_g_type_check_instance_cast
	movl	_VariablesXYZ, %edx
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
	movl	-48(%ebp), %ecx
	movl	%eax, %edi
	movl	%ecx, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-44(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	$1, %ecx
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	movl	%ebx, 16(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
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
	movl	$LC136, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	xorl	%ebx, %ebx
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	movl	$LC153, %edi
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	%edi, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_button
	movl	-48(%ebp), %edx
	movl	%eax, %edi
	movl	%edx, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
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
	movl	$LC136, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
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
	movl	$LC136, %edx
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
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show_all
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1153:
	movl	_NVariablesXYZ, %eax
	testl	%eax, %eax
	jne	L1149
	movl	$LC146, (%esp)
	movl	$1, %eax
	movl	$LC145, %edi
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	call	_MessageGeom
L1158:
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1149:
	movl	$LC147, (%esp)
	movl	$1, %esi
	movl	$LC145, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
	jmp	L1158
	.p2align 4,,7
L1154:
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	_EntryV, %eax
	movl	%eax, (%esp)
	call	_gtk_editable_set_editable
	jmp	L1151
	.section .rdata,"dr"
LC159:
	.ascii "Delete Variable\0"
LC160:
	.ascii " Delete Variable \0"
LC162:
	.ascii " Question \0"
	.align 4
LC161:
	.ascii "\12Are you sure to delete the variable\12 %s\12?\0"
LC163:
	.ascii "No\0"
LC164:
	.ascii "Yes\0"
LC155:
	.ascii "New Variable\0"
LC156:
	.ascii " New Variable \0"
	.align 4
LC167:
	.ascii "Tansform all variables in constants \0"
	.align 4
LC168:
	.ascii "\12Are you sure to transform\12all variables in constants? \12\0"
LC166:
	.ascii " Sorry No Center  !\0"
LC165:
	.ascii "i Error \0"
LC157:
	.ascii " No Variable to delet !\0"
	.align 4
LC158:
	.ascii "Sorry\12 %s \12 is used in Geometry\0"
LC169:
	.ascii "Sorry\12 No variable selected\0"
	.text
	.p2align 4,,15
	.def	_activate_action_xyz_variables;	.scl	3;	.type	32;	.endef
_activate_action_xyz_variables:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$LC1, %edi
	pushl	%esi
	pushl	%ebx
	subl	$188, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_action_get_name
	cld
	movl	$5, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	je	L1182
	cld
	movl	$LC3, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	je	L1183
	cld
	movl	$LC6, %edi
	movl	$7, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1165
	movl	_NVariablesXYZ, %edx
	testl	%edx, %edx
	je	L1184
	movl	_LineSelectedV, %eax
	testl	%eax, %eax
	js	L1185
L1168:
	movl	_VariablesXYZ, %edx
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	8(%eax,%edx), %ecx
	testl	%ecx, %ecx
	jne	L1186
	call	_gtk_dialog_new
	movl	$0, (%esp)
	movl	%eax, %edi
	call	_gtk_frame_new
	movl	%eax, -84(%ebp)
	movl	$4, %esi
	movl	$1, %ebx
	call	_gtk_frame_get_type
	movl	%eax, 4(%esp)
	movl	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_frame_set_shadow_type
	call	_gtk_window_get_type
	movl	%eax, -92(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	movl	$_gtk_widget_destroy, %ebx
	call	_gtk_window_set_position
	movl	-92(%ebp), %edx
	movl	%edi, (%esp)
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC159, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_title
	movl	-92(%ebp), %esi
	movl	_WindowGeom, %eax
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -96(%ebp)
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	-96(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_window_set_transient_for
	movl	%esi, 4(%esp)
	movl	$LC160, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_modal
	movl	%esi, 12(%esp)
	movl	_WindowGeom, %eax
	xorl	%esi, %esi
	movl	%ebx, 8(%esp)
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_add_child
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$_delete_child, %ecx
	movl	%edx, 20(%esp)
	movl	$LC150, %edx
	movl	%edx, 4(%esp)
	movl	%ecx, 8(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$_g_object_unref, %ebx
	call	_g_signal_connect_data
	movl	-84(%ebp), %esi
	movl	%esi, (%esp)
	call	_g_object_ref
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC151, %ecx
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
	movl	%eax, -100(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, -104(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	-100(%ebp), %edx
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
	movl	%eax, -88(%ebp)
	movl	$LC162, %esi
	xorl	%ebx, %ebx
	movl	%edi, (%esp)
	call	_gtk_widget_realize
	movl	_LineSelectedV, %eax
	movl	_VariablesXYZ, %edx
	leal	(%eax,%eax,2), %eax
	movl	(%edx,%eax,4), %eax
	movl	$LC161, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esp)
	movl	%esi, 8(%esp)
	movl	%edi, (%esp)
	call	_create_label_with_pixmap
	movl	%eax, -76(%ebp)
	movl	-100(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-88(%ebp), %eax
	movl	$LC163, %esi
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
	movl	-104(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-100(%ebp), %edx
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
	movl	%eax, -108(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -112(%ebp)
	movl	$80, %eax
	movl	%esi, (%esp)
	movl	$LC136, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 20(%esp)
	xorl	%ecx, %ecx
	movl	$LC164, %ebx
	movl	%ecx, 16(%esp)
	movl	-112(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	movl	%edx, 12(%esp)
	movl	$_delete_child, %edx
	movl	%edx, 8(%esp)
	call	_g_signal_connect_data
	movl	-108(%ebp), %esi
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
	movl	-104(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	movl	$1, %esi
	call	_g_type_check_instance_cast
	movl	-100(%ebp), %edx
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
	movl	$LC136, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	movl	-108(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -116(%ebp)
	movl	$80, %eax
	movl	%esi, (%esp)
	movl	$2, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	xorl	%ebx, %ebx
	movl	$_delete_child, %ecx
	movl	%ebx, 16(%esp)
	movl	-116(%ebp), %edx
	movl	%ecx, 8(%esp)
	movl	%eax, (%esp)
	movl	%edx, 12(%esp)
	movl	$LC136, %edx
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	-108(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-80(%ebp), %eax
L1180:
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	%edi, 8(%ebp)
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_show_all
	.p2align 4,,7
L1183:
	movl	$LC143, -40(%ebp)
	movl	$80, %ebx
	movl	$LC144, -36(%ebp)
	call	_gtk_dialog_new
	movl	%eax, %edi
	call	_gtk_window_get_type
	movl	%eax, -44(%ebp)
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC155, %ecx
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
	movl	$LC156, %eax
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
	movl	$LC150, %ecx
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
	movl	$LC151, %ecx
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
	movl	$LC144, %eax
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
	movl	$LC152, %eax
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
	movl	$LC136, %esi
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
	movl	$LC153, %ecx
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
	movl	$LC136, %edx
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
	movl	$LC136, %edx
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
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_show_all
	.p2align 4,,7
L1182:
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_DialogueEditV
	.p2align 4,,7
L1165:
	cld
	movl	$LC9, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1171
	movl	_NcentersXYZ, %eax
	testl	%eax, %eax
	je	L1187
	call	_gtk_dialog_new
	movl	%eax, %edi
	call	_gtk_window_get_type
	movl	%eax, -136(%ebp)
	movl	$LC167, %ebx
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	call	_gtk_window_set_title
	movl	-136(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_position
	movl	-136(%ebp), %edx
	movl	_WindowGeom, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -140(%ebp)
	movl	-136(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-140(%ebp), %edx
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
	movl	$LC162, %eax
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
	movl	$LC150, %esi
	movl	%ecx, 12(%esp)
	movl	%ebx, 16(%esp)
	movl	$LC162, %ebx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%edi, (%esp)
	call	_gtk_widget_realize
	movl	%ebx, 8(%esp)
	movl	$LC168, %ecx
	movl	$_g_object_unref, %ebx
	movl	%ecx, 4(%esp)
	movl	%edi, (%esp)
	call	_create_label_with_pixmap
	movl	%eax, -124(%ebp)
	movl	$0, (%esp)
	call	_gtk_frame_new
	movl	%eax, -132(%ebp)
	call	_gtk_frame_get_type
	movl	%eax, 4(%esp)
	movl	-132(%ebp), %esi
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
	movl	$LC151, %ecx
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
	movl	%eax, -144(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, -148(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	-144(%ebp), %edx
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
	movl	-144(%ebp), %esi
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	movl	$LC163, %esi
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 8(%esp)
	movl	-124(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	_create_button
	movl	%eax, -128(%ebp)
	movl	-148(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-144(%ebp), %edx
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
	movl	-128(%ebp), %esi
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	call	_gtk_object_get_type
	movl	%eax, -152(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -156(%ebp)
	movl	$80, %eax
	movl	%esi, (%esp)
	movl	$LC136, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 20(%esp)
	xorl	%ecx, %ecx
	movl	$LC164, %ebx
	movl	%ecx, 16(%esp)
	movl	-156(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	movl	%edx, 12(%esp)
	movl	$_delete_child, %edx
	movl	%edx, 8(%esp)
	call	_g_signal_connect_data
	movl	-152(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-128(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	-128(%ebp), %edx
	movl	%edx, (%esp)
	call	_gtk_widget_grab_default
	movl	%ebx, 4(%esp)
	movl	$80, %ebx
	movl	%edi, (%esp)
	call	_create_button
	movl	%eax, -128(%ebp)
	movl	-148(%ebp), %esi
	movl	%edi, (%esp)
	movl	%esi, 4(%esp)
	movl	$1, %esi
	call	_g_type_check_instance_cast
	movl	-144(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 8(%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	-128(%ebp), %esi
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
	movl	$LC136, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	xorl	%ebx, %ebx
	call	_g_signal_connect_data
	movl	-152(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -160(%ebp)
	movl	$80, %eax
	movl	%esi, (%esp)
	movl	$2, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	movl	$_delete_child, %ecx
	movl	%ebx, 16(%esp)
	movl	-160(%ebp), %edx
	movl	%ecx, 8(%esp)
	movl	%eax, (%esp)
	movl	%edx, 12(%esp)
	movl	$LC136, %edx
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	-152(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	-128(%ebp), %eax
	jmp	L1180
L1171:
	cld
	movl	$LC12, %edi
	movl	$4, %ecx
	movl	%eax, %esi
	repe
	cmpsb
	jne	L1159
	movl	_LineSelectedV, %eax
	testl	%eax, %eax
	js	L1188
	movl	%eax, (%esp)
	call	_OneVariableToConstXYZ
	movl	$-1, %eax
	movl	%eax, _LineSelectedV
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L1159
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_rafresh_drawing
L1187:
	movl	$LC166, (%esp)
	movl	$1, %edi
	movl	$LC165, %esi
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_MessageGeom
	.p2align 4,,15
L1159:
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1184:
	movl	$LC157, (%esp)
	movl	$1, %esi
	movl	$LC75, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
	jmp	L1159
L1186:
	movl	(%eax,%edx), %eax
	movl	$LC75, %edi
	movl	$LC158, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	call	_MessageGeom
	jmp	L1159
L1185:
	leal	-1(%edx), %eax
	movl	%eax, _LineSelectedV
	jmp	L1168
L1188:
	movl	$LC169, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC75, %eax
	movl	%eax, 4(%esp)
	call	_MessageGeom
	jmp	L1159
	.section .rdata,"dr"
LC171:
	.ascii "Atom Symbol : \0"
LC172:
	.ascii "MM Type : \0"
LC173:
	.ascii "PDB Type : \0"
LC174:
	.ascii "Residue Type : \0"
LC175:
	.ascii " X : \0"
LC176:
	.ascii " Y : \0"
LC177:
	.ascii " Z : \0"
LC178:
	.ascii " Charge : \0"
LC179:
	.ascii " Layer : \0"
LC182:
	.ascii "Edit Center\0"
LC183:
	.ascii " Edit Center \0"
LC184:
	.ascii " Set \0"
LC180:
	.ascii "Create center before \12\0"
LC181:
	.ascii "Please Select your center \12\0"
	.text
	.p2align 4,,15
	.def	_DialogueEdit;	.scl	3;	.type	32;	.endef
_DialogueEdit:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$156, %esp
	movl	_LineSelected, %eax
	movl	$LC83, -72(%ebp)
	movl	$LC171, -68(%ebp)
	testl	%eax, %eax
	movl	$LC172, -64(%ebp)
	movl	$LC173, -60(%ebp)
	movl	$LC174, -56(%ebp)
	movl	$LC175, -52(%ebp)
	movl	$LC176, -48(%ebp)
	movl	$LC177, -44(%ebp)
	movl	$LC178, -40(%ebp)
	movl	$LC179, -36(%ebp)
	movl	%eax, -100(%ebp)
	js	L1220
	call	_gtk_dialog_new
	movl	%eax, -88(%ebp)
	xorl	%esi, %esi
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-88(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC182, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_title
	movl	%ebx, 4(%esp)
	movl	-88(%ebp), %ecx
	movl	%ecx, (%esp)
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
	movl	%eax, %edi
	movl	-88(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	xorl	%edi, %edi
	call	_gtk_window_set_transient_for
	movl	$LC183, %eax
	movl	%eax, 12(%esp)
	movl	$_gtk_widget_destroy, %eax
	movl	%eax, 8(%esp)
	movl	-88(%ebp), %edx
	movl	_WindowGeom, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_add_child
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-88(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_delete_child, %ecx
	movl	$LC150, %edx
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
	movl	-88(%ebp), %eax
	xorl	%esi, %esi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_g_object_unref, %ecx
	movl	$LC151, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
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
	movl	%eax, -104(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, 4(%esp)
	movl	-88(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	-104(%ebp), %ecx
	movl	%ecx, 4(%esp)
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
	movl	%eax, -92(%ebp)
	movl	%eax, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	movl	%eax, %esi
	xorl	%edi, %edi
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	12(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	8(%esp)
	fldcw	-82(%ebp)
	movl	-68(%ebp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	movl	%eax, _Entry+4
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	movl	$5, %ebx
	call	_g_type_check_instance_cast
	movl	-100(%ebp), %ecx
	leal	(%ecx,%ecx,2), %edx
	movl	_GeomXYZ, %ecx
	sall	$4, %edx
	movl	4(%edx,%ecx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%edi, 4(%esp)
	movl	_Entry+4, %eax
	movl	%eax, (%esp)
	call	_gtk_editable_set_editable
	movl	$LC184, (%esp)
	call	_gtk_button_new_with_label
	movl	%eax, %edi
	movl	-104(%ebp), %eax
	movl	%esi, (%esp)
	xorl	%esi, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	xorl	%ebx, %ebx
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	_Entry+4, %edx
	movl	$_SelectAtom, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 20(%esp)
	movl	%edx, 12(%esp)
	movl	$LC136, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	call	_g_signal_connect_data
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	movl	$0, -76(%ebp)
	movl	%eax, %esi
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	_getListMMTypes
	movl	-76(%ebp), %edx
	movl	%eax, %edi
	testl	%edx, %edx
	jne	L1221
	fildl	_ScreenHeight
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	12(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	8(%esp)
	fldcw	-82(%ebp)
	movl	-64(%ebp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
L1214:
	movl	%eax, _Entry+8
	testl	%edi, %edi
	movl	%eax, %ebx
	je	L1197
	movl	-76(%ebp), %edx
	movl	%edi, %eax
	call	_freeList
	movl	_Entry+8, %ebx
L1197:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	-100(%ebp), %ecx
	movl	_GeomXYZ, %edx
	leal	(%ecx,%ecx,2), %ebx
	sall	$4, %ebx
	movl	8(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	movl	$0, -80(%ebp)
	movl	%eax, %esi
	leal	-80(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	_GeomXYZ, %eax
	movl	16(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_getListPDBTypes
	movl	-80(%ebp), %edx
	movl	%eax, %edi
	testl	%edx, %edx
	je	L1198
	fildl	_ScreenHeight
	movl	$1, %ebx
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	24(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	20(%esp)
	fldcw	-82(%ebp)
	movl	%ebx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	-60(%ebp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
L1215:
	movl	%eax, _Entry+12
	testl	%edi, %edi
	movl	%eax, %ebx
	je	L1200
	movl	-80(%ebp), %edx
	movl	%edi, %eax
	call	_freeList
	movl	_Entry+12, %ebx
L1200:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %edi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	-100(%ebp), %edx
	leal	(%edx,%edx,2), %ebx
	movl	_GeomXYZ, %edx
	sall	$4, %ebx
	movl	12(%ebx,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-92(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	movl	%eax, %esi
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	12(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	8(%esp)
	fldcw	-82(%ebp)
	movl	-56(%ebp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	movl	%eax, _Entry+16
	movl	_NcentersXYZ, %ecx
	testl	%ecx, %ecx
	jne	L1201
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	$LC83, %edx
L1219:
	movl	%edx, 4(%esp)
	movl	$5, %ebx
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	call	_get_list_variablesXYZ
	movl	%eax, %edi
	movl	-100(%ebp), %eax
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	movl	%eax, -108(%ebp)
L1209:
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	cmpl	$5, %ebx
	movl	%eax, %esi
	je	L1222
	cmpl	$6, %ebx
	je	L1223
	cmpl	$7, %ebx
	je	L1224
L1208:
	fildl	_ScreenHeight
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	movl	$1, %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	24(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	20(%esp)
	fldcw	-82(%ebp)
	movl	%eax, 16(%esp)
	movl	_NVariablesXYZ, %eax
	movl	%edi, 8(%esp)
	leal	1(%eax,%eax), %eax
	movl	%eax, 12(%esp)
	movl	-72(%ebp,%ebx,4), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry(,%ebx,4)
	incl	%ebx
	cmpl	$7, %ebx
	jle	L1209
	movl	%edi, %eax
	xorl	%ebx, %ebx
	call	_freelistvariablesXYZ
	call	_gtk_entry_get_type
	movl	%eax, -112(%ebp)
	movl	%eax, 4(%esp)
	movl	_Entry+20, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-100(%ebp), %edx
	leal	(%edx,%edx,2), %edi
	movl	_GeomXYZ, %edx
	sall	$4, %edi
	movl	28(%edi,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-112(%ebp), %ecx
	movl	_Entry+24, %eax
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_GeomXYZ, %edx
	movl	32(%edi,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-112(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	_Entry+28, %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_GeomXYZ, %edx
	movl	36(%edi,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	movl	%eax, %esi
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	12(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	8(%esp)
	fldcw	-82(%ebp)
	movl	-40(%ebp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	movl	%eax, _Entry+32
	movl	-112(%ebp), %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	_GeomXYZ, %edx
	movl	24(%edi,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	$16, (%esp)
	call	_g_malloc
	movl	%eax, -96(%ebp)
	movl	$LC83, (%esp)
	call	_g_strdup
	movl	-96(%ebp), %edx
	movl	%eax, (%edx)
	movl	$LC82, (%esp)
	call	_g_strdup
	movl	-96(%ebp), %ecx
	movl	%eax, 4(%ecx)
	movl	$LC52, (%esp)
	call	_g_strdup
	movl	-96(%ebp), %edx
	movl	%eax, 8(%edx)
	movl	$LC51, (%esp)
	call	_g_strdup
	cmpl	$2, _LineSelected
	movl	-96(%ebp), %ecx
	setg	%bl
	movl	%eax, 12(%ecx)
	movl	-92(%ebp), %eax
	leal	1(%ebx,%ebx,2), %ebx
	movl	%eax, (%esp)
	call	_create_hbox_false
	cmpl	$3, _iprogram
	movl	%eax, %esi
	je	L1211
	fildl	_ScreenHeight
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	xorl	%eax, %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	24(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	20(%esp)
	fldcw	-82(%ebp)
	movl	%eax, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	-96(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-36(%ebp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry+36
	movl	-112(%ebp), %ecx
	movl	%eax, (%esp)
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	_GeomXYZ, %edx
	movl	40(%edi,%edx), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
L1211:
	movl	-88(%ebp), %eax
	movl	$1, %esi
	movl	$1, %ebx
	movl	%eax, (%esp)
	call	_gtk_widget_realize
	movl	$LC152, %ecx
	movl	%ecx, 4(%esp)
	movl	-88(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_button
	movl	%eax, %edi
	call	_gtk_box_get_type
	movl	%eax, -116(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, -120(%ebp)
	movl	%eax, 4(%esp)
	movl	-88(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	-116(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	%edx, 16(%esp)
	movl	%esi, 12(%esp)
	xorl	%esi, %esi
	movl	%ebx, 8(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	call	_gtk_object_get_type
	movl	%eax, -124(%ebp)
	movl	%eax, 4(%esp)
	movl	-88(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%eax, %ebx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	$_delete_child, %ecx
	movl	%edx, 20(%esp)
	movl	$LC136, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%esi, 16(%esp)
	movl	$LC153, %esi
	movl	%ebx, 12(%esp)
	xorl	%ebx, %ebx
	call	_g_signal_connect_data
	movl	-124(%ebp), %eax
	movl	%edi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	%esi, 4(%esp)
	movl	-88(%ebp), %edx
	xorl	%esi, %esi
	movl	%edx, (%esp)
	call	_create_button
	movl	-120(%ebp), %ecx
	movl	%eax, %edi
	movl	%ecx, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-116(%ebp), %edx
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
	xorl	%ebx, %ebx
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	_Entry+4, %edx
	movl	$_EditAtom, %ecx
	movl	%esi, 20(%esp)
	movl	$80, %esi
	movl	%edx, 12(%esp)
	movl	$LC136, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 8(%esp)
	call	_g_signal_connect_data
	movl	-124(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 4(%esp)
	movl	%eax, %ebx
	movl	$_destroy_dialogue, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 12(%esp)
	movl	$2, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$LC136, %ebx
	movl	%edx, 16(%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	-124(%ebp), %edx
	movl	%edi, (%esp)
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	%edi, (%esp)
	call	_gtk_widget_grab_default
	movl	-88(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_gtk_widget_show_all
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	addl	$156, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1221:
	fildl	_ScreenHeight
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	movl	$1, %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	24(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	20(%esp)
	fldcw	-82(%ebp)
	movl	%eax, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	-64(%ebp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	jmp	L1214
	.p2align 4,,7
L1220:
	movl	_NcentersXYZ, %eax
	testl	%eax, %eax
	jne	L1193
	movl	$LC180, (%esp)
	movl	$1, %eax
	movl	$LC75, %edi
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	call	_MessageGeom
L1228:
	addl	$156, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1201:
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	_GeomXYZ, %edx
	movl	16(%ebx,%edx), %edx
	jmp	L1219
	.p2align 4,,7
L1198:
	fildl	_ScreenHeight
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	12(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	8(%esp)
	fldcw	-82(%ebp)
	movl	-60(%ebp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_create_label_entry
	jmp	L1215
	.p2align 4,,7
L1193:
	movl	$LC181, (%esp)
	movl	$1, %esi
	movl	$LC145, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_MessageGeom
	jmp	L1228
	.p2align 4,,7
L1222:
	movl	_GeomXYZ, %eax
	movl	-108(%ebp), %ecx
	movl	28(%ecx,%eax), %eax
L1217:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, (%edi)
	jmp	L1208
	.p2align 4,,7
L1223:
	movl	_GeomXYZ, %eax
	movl	-108(%ebp), %edx
	movl	32(%edx,%eax), %eax
	jmp	L1217
	.p2align 4,,7
L1224:
	movl	_GeomXYZ, %eax
	movl	-108(%ebp), %ecx
	movl	36(%ecx,%eax), %eax
	jmp	L1217
	.section .rdata,"dr"
LC186:
	.ascii "Geom\0"
LC187:
	.ascii "%s/Edit\0"
LC188:
	.ascii "%s/Delete\0"
LC189:
	.ascii "%s/One\0"
LC190:
	.ascii "%s/All\0"
LC191:
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
	je	L1229
	call	_gtk_tree_view_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_bin_window
	cmpl	%eax, 4(%esi)
	je	L1283
L1231:
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
	jne	L1284
L1232:
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
	movl	$LC64, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	movl	$LC186, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1234
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
L1235:
	movl	_ZoneDessin, %ecx
	testl	%ecx, %ecx
	jne	L1285
	movl	(%esi), %eax
	cmpl	$5, %eax
	je	L1286
L1292:
	cmpl	$4, %eax
	je	L1287
L1240:
	movl	8(%ebp), %edx
	movl	(%edx), %eax
	movl	%esi, 4(%esp)
	movl	%edx, (%esp)
	call	*176(%eax)
L1229:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1284:
	movl	-16(%ebp), %edi
	testl	%edi, %edi
	je	L1232
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
	jmp	L1232
	.p2align 4,,7
L1285:
	call	_rafresh_drawing
	movl	(%esi), %eax
	cmpl	$5, %eax
	jne	L1292
	.p2align 4,,15
L1286:
	movl	%ebx, (%esp)
	movl	$LC186, %edx
	movl	%edx, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1238
	call	_DialogueEdit
	movl	(%esi), %eax
L1294:
	cmpl	$4, %eax
	jne	L1240
	.p2align 4,,15
L1287:
	cmpl	$3, 40(%esi)
	jne	L1240
	testl	%ebx, %ebx
	je	L1259
	movl	%ebx, 4(%esp)
	movl	$LC187, (%esp)
	call	_g_strdup_printf
	movl	%eax, -28(%ebp)
	movl	%ebx, 4(%esp)
	movl	$LC188, (%esp)
	call	_g_strdup_printf
	movl	%eax, -32(%ebp)
	movl	%ebx, 4(%esp)
	movl	$LC189, (%esp)
	call	_g_strdup_printf
	movl	%eax, -36(%ebp)
	movl	%ebx, 4(%esp)
	movl	$LC190, (%esp)
	call	_g_strdup_printf
	movl	%eax, -40(%ebp)
	movl	-28(%ebp), %eax
	testl	%eax, %eax
	je	L1245
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	js	L1288
	movl	$1, (%esp)
L1274:
	movl	-28(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
L1245:
	movl	-36(%ebp), %eax
	testl	%eax, %eax
	je	L1248
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	js	L1289
	movl	$1, (%esp)
L1275:
	movl	-36(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L1248:
	movl	-32(%ebp), %eax
	testl	%eax, %eax
	je	L1251
	movl	%ebx, (%esp)
	movl	$LC186, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1252
	movl	_NcentersXYZ, %ecx
	testl	%ecx, %ecx
L1280:
	jne	L1257
	movl	$0, (%esp)
L1276:
	movl	-32(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
L1255:
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
L1251:
	movl	-40(%ebp), %eax
	testl	%eax, %eax
	je	L1259
	movl	%ebx, (%esp)
	movl	$LC186, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1260
	movl	_NcentersXYZ, %eax
L1282:
	testl	%eax, %eax
	jne	L1265
	movl	$0, (%esp)
L1277:
	movl	-40(%ebp), %edx
	movl	%edi, %eax
	call	_set_sensitive_option
L1263:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
L1259:
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
	je	L1268
	movl	(%ebx), %edx
	testl	%edx, %edx
	je	L1268
	cmpl	%eax, (%edx)
	je	L1271
L1268:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L1240
L1271:
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
	jmp	L1240
	.p2align 4,,7
L1234:
	movl	-24(%ebp), %eax
	movl	%eax, _LineSelectedV
	movl	%eax, _LineSelectedOld
	jmp	L1235
L1283:
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
	jne	L1231
	movl	%ebx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_tree_view_get_selection
	movl	%eax, (%esp)
	call	_gtk_tree_selection_unselect_all
	jmp	L1231
L1238:
	call	_DialogueEditV
	movl	(%esi), %eax
	jmp	L1294
L1265:
	movl	$1, (%esp)
	jmp	L1277
L1257:
	movl	$1, (%esp)
	jmp	L1276
L1288:
	movl	$0, (%esp)
	jmp	L1274
L1289:
	movl	$0, (%esp)
	jmp	L1275
L1260:
	movl	%ebx, (%esp)
	movl	$LC191, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1263
	movl	_NVariablesXYZ, %eax
	jmp	L1282
L1252:
	movl	%ebx, (%esp)
	movl	$LC191, %edx
	movl	%edx, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1255
	movl	_NVariablesXYZ, %eax
	testl	%eax, %eax
	jmp	L1280
	.section .rdata,"dr"
LC193:
	.ascii "New Center\0"
LC194:
	.ascii " New Center \0"
LC195:
	.ascii "H\0"
LC196:
	.ascii "UNK\0"
	.text
	.p2align 4,,15
	.def	_DialogueAdd;	.scl	3;	.type	32;	.endef
_DialogueAdd:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	pushl	%ebx
	subl	$124, %esp
	movl	$LC83, -72(%ebp)
	movl	$LC171, -68(%ebp)
	movl	$LC172, -64(%ebp)
	movl	$LC173, -60(%ebp)
	movl	$LC174, -56(%ebp)
	movl	$LC175, -52(%ebp)
	movl	$LC176, -48(%ebp)
	movl	$LC177, -44(%ebp)
	movl	$LC178, -40(%ebp)
	movl	$LC179, -36(%ebp)
	call	_gtk_dialog_new
	movl	%eax, -88(%ebp)
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC193, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_title
	movl	%ebx, 4(%esp)
	movl	-88(%ebp), %edx
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
	movl	-88(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	call	_gtk_window_set_transient_for
	movl	$LC194, %eax
	movl	-88(%ebp), %edx
	movl	%eax, 12(%esp)
	movl	$_gtk_widget_destroy, %eax
	movl	%eax, 8(%esp)
	movl	_WindowGeom, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_add_child
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_delete_child, %ecx
	movl	$LC150, %edx
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
	movl	-88(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_g_object_unref, %ecx
	movl	$LC151, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 4(%esp)
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
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
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
	movl	%eax, -92(%ebp)
	movl	%eax, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	fnstcw	-82(%ebp)
	movl	%eax, %esi
	movzwl	-82(%ebp), %eax
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fld	%st(0)
	movl	-68(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-84(%ebp)
	fistpl	12(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	8(%esp)
	fldcw	-82(%ebp)
	call	_create_label_entry
	movl	%eax, _Entry+4
	movl	_NcentersXYZ, %edi
	movl	%eax, %ebx
	testl	%edi, %edi
	jne	L1296
	call	_gtk_entry_get_type
	movl	%ebx, (%esp)
	movl	$LC195, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
L1318:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	movl	_Entry+4, %eax
	xorl	%edi, %edi
	movl	$5, %ebx
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_editable_set_editable
	movl	$LC184, (%esp)
	call	_gtk_button_new_with_label
	movl	%eax, %edi
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	xorl	%esi, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	xorl	%ebx, %ebx
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	_Entry+4, %edx
	movl	$_SelectAtom, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 20(%esp)
	movl	%edx, 12(%esp)
	movl	$LC136, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	call	_g_signal_connect_data
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	movl	$0, -76(%ebp)
	movl	%eax, %esi
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	_getListMMTypes
	movl	-76(%ebp), %edx
	movl	%eax, %edi
	testl	%edx, %edx
	je	L1298
	fildl	_ScreenHeight
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fld	%st(0)
	movl	$1, %eax
	fmull	_entryWidth
	fxch	%st(1)
	movl	%eax, 16(%esp)
	movl	-64(%ebp), %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	24(%esp)
	fldcw	-82(%ebp)
	movl	%eax, 4(%esp)
	fldcw	-84(%ebp)
	fistpl	20(%esp)
	fldcw	-82(%ebp)
	call	_create_label_combo
L1319:
	movl	%eax, _Entry+8
	testl	%edi, %edi
	movl	%eax, %ebx
	je	L1300
	movl	-76(%ebp), %edx
	movl	%edi, %eax
	call	_freeList
	movl	_Entry+8, %ebx
L1300:
	movl	_NcentersXYZ, %esi
	testl	%esi, %esi
	jne	L1301
	call	_gtk_entry_get_type
	movl	%ebx, (%esp)
	movl	$LC195, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
L1320:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	movl	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	movl	$0, -80(%ebp)
	movl	%eax, %esi
	leal	-80(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC196, (%esp)
	call	_getListPDBTypes
	movl	-80(%ebp), %edx
	movl	%eax, %edi
	testl	%edx, %edx
	je	L1303
	fildl	_ScreenHeight
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fld	%st(0)
	movl	$1, %eax
	fmull	_entryWidth
	fxch	%st(1)
	movl	%eax, 16(%esp)
	movl	-60(%ebp), %eax
	fmull	_labelWidth
	fxch	%st(1)
	fldcw	-84(%ebp)
	fistpl	24(%esp)
	fldcw	-82(%ebp)
	movl	%eax, 4(%esp)
	fldcw	-84(%ebp)
	fistpl	20(%esp)
	fldcw	-82(%ebp)
	call	_create_label_combo
L1321:
	movl	%eax, _Entry+12
	testl	%edi, %edi
	movl	%eax, %ebx
	je	L1305
	movl	-80(%ebp), %edx
	movl	%edi, %eax
	call	_freeList
	movl	_Entry+12, %ebx
L1305:
	movl	_NcentersXYZ, %esi
	testl	%esi, %esi
	jne	L1306
	call	_gtk_entry_get_type
	movl	%ebx, (%esp)
	movl	$LC195, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
L1322:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	fnstcw	-82(%ebp)
	movl	%eax, %esi
	movzwl	-82(%ebp), %eax
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fld	%st(0)
	movl	-56(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-84(%ebp)
	fistpl	12(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	8(%esp)
	fldcw	-82(%ebp)
	call	_create_label_entry
	movl	%eax, _Entry+16
	movl	_NcentersXYZ, %edi
	movl	%eax, %ebx
	testl	%edi, %edi
	jne	L1308
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	$LC83, %esi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 4(%esp)
L1323:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	call	_get_list_variablesXYZ
	movl	%eax, %edi
	movl	$5, %ebx
L1313:
	movl	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	fnstcw	-82(%ebp)
	movl	%eax, %esi
	movl	$1, %ecx
	movzwl	-82(%ebp), %eax
	movl	%ecx, 16(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	movl	_NVariablesXYZ, %eax
	fld	%st(0)
	fmull	_entryWidth
	fxch	%st(1)
	leal	1(%eax,%eax), %eax
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 12(%esp)
	movl	-72(%ebp,%ebx,4), %eax
	fldcw	-84(%ebp)
	fistpl	24(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	20(%esp)
	fldcw	-82(%ebp)
	movl	%eax, 4(%esp)
	call	_create_label_combo
	movl	%eax, _Entry(,%ebx,4)
	incl	%ebx
	cmpl	$7, %ebx
	jle	L1313
	movl	%edi, %eax
	call	_freelistvariablesXYZ
	call	_set_entry_XYZ
	movl	-92(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_hbox_false
	fildl	_ScreenHeight
	fnstcw	-82(%ebp)
	movl	%eax, %esi
	movzwl	-82(%ebp), %eax
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fld	%st(0)
	movl	-40(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-84(%ebp)
	fistpl	12(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	8(%esp)
	fldcw	-82(%ebp)
	call	_create_label_entry
	movl	%eax, _Entry+32
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC126, %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	$16, (%esp)
	call	_g_malloc
	movl	%eax, -96(%ebp)
	movl	$LC83, (%esp)
	call	_g_strdup
	movl	-96(%ebp), %edx
	movl	%eax, (%edx)
	movl	$LC82, (%esp)
	call	_g_strdup
	movl	-96(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	$LC52, (%esp)
	call	_g_strdup
	movl	-96(%ebp), %edx
	movl	%eax, 8(%edx)
	movl	$LC51, (%esp)
	call	_g_strdup
	cmpl	$3, _NcentersXYZ
	movl	-96(%ebp), %edx
	sbbl	%ebx, %ebx
	movl	%eax, 12(%edx)
	movl	-92(%ebp), %eax
	andl	$-3, %ebx
	addl	$4, %ebx
	movl	%eax, (%esp)
	call	_create_hbox_false
	cmpl	$3, _iprogram
	movl	%eax, %esi
	je	L1315
	fildl	_ScreenHeight
	fnstcw	-82(%ebp)
	xorl	%edi, %edi
	movl	-96(%ebp), %edx
	movzwl	-82(%ebp), %eax
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fld	%st(0)
	movl	-36(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	movl	%esi, (%esp)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-84(%ebp)
	fistpl	24(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	20(%esp)
	fldcw	-82(%ebp)
	call	_create_label_combo
	movl	%eax, _Entry+36
L1315:
	movl	-88(%ebp), %eax
	movl	$LC152, %esi
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_gtk_widget_realize
	movl	%esi, 4(%esp)
	movl	-88(%ebp), %edx
	movl	%edx, (%esp)
	call	_create_button
	movl	%eax, %edi
	call	_gtk_box_get_type
	movl	%eax, -100(%ebp)
	call	_gtk_dialog_get_type
	movl	%eax, -104(%ebp)
	movl	%eax, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-100(%ebp), %edx
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
	movl	-88(%ebp), %eax
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
	movl	$LC136, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	movl	$LC153, %ebx
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	-88(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	$1, %ebx
	movl	%edx, (%esp)
	call	_create_button
	movl	%eax, %edi
	movl	-88(%ebp), %edx
	movl	-104(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	-100(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	152(%eax), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%edx, 12(%esp)
	movl	%ecx, 16(%esp)
	movl	%ebx, 8(%esp)
	xorl	%ebx, %ebx
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$_AddAtom, %ecx
	movl	%edx, 20(%esp)
	movl	_Entry+4, %edx
	movl	%ecx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	$LC136, %edx
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	%eax, %ebx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 12(%esp)
	movl	$2, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$_destroy_dialogue, %ebx
	movl	$LC136, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, 16(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	orl	$8192, 12(%eax)
	movl	%edi, (%esp)
	call	_gtk_widget_grab_default
	movl	-88(%ebp), %edx
	movl	%edx, (%esp)
	call	_gtk_widget_show_all
	movl	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	addl	$124, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1296:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	_NcentersXYZ, %edx
	movl	_GeomXYZ, %ecx
	leal	(%edx,%edx,2), %edx
	sall	$4, %edx
	addl	%ecx, %edx
	movl	-44(%edx), %edx
	movl	%edx, 4(%esp)
	jmp	L1318
	.p2align 4,,7
L1308:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	_NcentersXYZ, %edx
	movl	_GeomXYZ, %ebx
	leal	(%edx,%edx,2), %edx
	sall	$4, %edx
	addl	%ebx, %edx
	movl	-32(%edx), %edx
	movl	%edx, 4(%esp)
	jmp	L1323
	.p2align 4,,7
L1306:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	_NcentersXYZ, %edx
	movl	_GeomXYZ, %ecx
	leal	(%edx,%edx,2), %edx
	sall	$4, %edx
	addl	%ecx, %edx
	movl	-36(%edx), %edx
	movl	%edx, 4(%esp)
	jmp	L1322
	.p2align 4,,7
L1303:
	fildl	_ScreenHeight
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fld	%st(0)
	movl	-60(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-84(%ebp)
	fistpl	12(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	8(%esp)
	fldcw	-82(%ebp)
	call	_create_label_entry
	jmp	L1321
	.p2align 4,,7
L1301:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	_NcentersXYZ, %edx
	movl	_GeomXYZ, %ecx
	leal	(%edx,%edx,2), %edx
	sall	$4, %edx
	addl	%ecx, %edx
	movl	-40(%edx), %edx
	movl	%edx, 4(%esp)
	jmp	L1320
	.p2align 4,,7
L1298:
	fildl	_ScreenHeight
	fnstcw	-82(%ebp)
	movzwl	-82(%ebp), %eax
	movl	%esi, (%esp)
	orw	$3072, %ax
	movw	%ax, -84(%ebp)
	fld	%st(0)
	movl	-64(%ebp), %eax
	fmull	_entryWidth
	fxch	%st(1)
	fmull	_labelWidth
	fxch	%st(1)
	movl	%eax, 4(%esp)
	fldcw	-84(%ebp)
	fistpl	12(%esp)
	fldcw	-82(%ebp)
	fldcw	-84(%ebp)
	fistpl	8(%esp)
	fldcw	-82(%ebp)
	call	_create_label_entry
	jmp	L1319
	.section .rdata,"dr"
LC198:
	.ascii "%c%c\0"
LC199:
	.ascii "%c\0"
	.text
	.p2align 4,,15
	.def	_get_symb_atom;	.scl	3;	.type	32;	.endef
_get_symb_atom:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$32, %esp
	movl	%eax, (%esp)
	movb	$48, -24(%ebp)
	movb	$49, -23(%ebp)
	movb	$50, -22(%ebp)
	movb	$51, -21(%ebp)
	movb	$52, -20(%ebp)
	movb	$53, -19(%ebp)
	movb	$54, -18(%ebp)
	movb	$55, -17(%ebp)
	movb	$56, -16(%ebp)
	movb	$57, -15(%ebp)
	call	_strlen
	decl	%eax
	je	L1340
	movzbl	1(%esi), %edx
	xorl	%eax, %eax
	.p2align 4,,15
L1331:
	cmpb	-24(%eax,%ebp), %dl
	je	L1337
	incl	%eax
	cmpl	$9, %eax
	jle	L1331
	movsbl	(%esi),%eax
	movl	%eax, (%esp)
	call	_toupper
	movsbl	1(%esi),%edx
	movl	%eax, 4(%esp)
	movl	$LC198, (%esp)
	movl	%edx, 8(%esp)
	call	_g_strdup_printf
L1339:
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_test_atom_define
	testl	%eax, %eax
	je	L1341
L1334:
	addl	$32, %esp
	movl	%ebx, %eax
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
L1341:
	movsbl	(%esi),%eax
	movl	%eax, (%esp)
	call	_toupper
	movl	%eax, 4(%esp)
	movl	$LC199, (%esp)
	call	_g_strdup_printf
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_test_atom_define
	testl	%eax, %eax
	jne	L1334
	movl	$LC195, (%esp)
	call	_g_strdup
	movl	%eax, %ebx
	jmp	L1334
L1337:
	movsbl	(%esi),%eax
	movl	%eax, (%esp)
	call	_toupper
	movl	%eax, 4(%esp)
	movl	$LC199, (%esp)
	call	_g_strdup_printf
	jmp	L1339
L1340:
	movl	%esi, (%esp)
	call	_g_strdup
	jmp	L1339
	.section .rdata,"dr"
LC200:
	.ascii "U\0"
	.space 1022
LC201:
	.ascii "r\0"
LC203:
	.ascii "ATOM\0"
LC204:
	.ascii "RES\0"
LC206:
	.ascii "%s %s %s\0"
LC208:
	.ascii "Unknown\0"
LC207:
	.ascii "%s %s %s %s %s %s %s %s %s %s\0"
LC209:
	.ascii "-\0"
LC210:
	.ascii "**\0"
	.align 4
LC202:
	.ascii "Sorry\12 I can not open \"%s\" file\0"
LC205:
	.ascii "Sorry\12 I can read \"%s\" file\0"
	.text
	.p2align 4,,15
.globl _read_hin_file_no_add_list
	.def	_read_hin_file_no_add_list;	.scl	2;	.type	32;	.endef
_read_hin_file_no_add_list:
	pushl	%ebp
	movl	$1022, %ecx
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edx, %edx
	pushl	%esi
	pushl	%ebx
	subl	$3244, %esp
	movzwl	LC200, %eax
	movw	%ax, -1080(%ebp)
	leal	-1078(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_memset
	xorl	%eax, %eax
	movl	%eax, -3156(%ebp)
	xorl	%eax, %eax
	movl	%eax, -3148(%ebp)
	.p2align 4,,15
L1346:
	movl	$1024, (%esp)
	call	_g_malloc
	movl	-3148(%ebp), %edx
	movl	%eax, -56(%ebp,%edx,4)
	incl	%edx
	cmpl	$7, %edx
	movl	%edx, -3148(%ebp)
	jle	L1346
	movl	$LC201, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %edi
	movl	%edi, (%esp)
	call	_FOpen
	movl	%eax, -3144(%ebp)
	testl	%eax, %eax
	je	L1455
	xorl	%ecx, %ecx
	xorl	%edi, %edi
	xorl	%esi, %esi
	movl	%edi, -3132(%ebp)
	xorl	%ebx, %ebx
	movl	%esi, -3136(%ebp)
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	-3144(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	movl	-3144(%ebp), %edx
	testb	$16, 12(%edx)
	jne	L1349
	leal	-2104(%ebp), %ebx
	.p2align 4,,15
L1353:
	movl	-3144(%ebp), %edi
	movl	$1024, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, (%esp)
	movl	%edi, 8(%esp)
	call	_fgets
	testl	%eax, %eax
	je	L1349
	leal	-3128(%ebp), %eax
	movl	$LC203, %edi
	movl	%eax, -3176(%ebp)
	movl	%eax, 8(%esp)
	movl	$LC81, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_sscanf
	movl	-3176(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_strup
	cld
	movl	-3176(%ebp), %esi
	movl	$5, %ecx
	repe
	cmpsb
	jne	L1351
	incl	-3132(%ebp)
L1351:
	cld
	movl	-3176(%ebp), %esi
	movl	$LC204, %edi
	movl	$4, %ecx
	repe
	cmpsb
	jne	L1348
	incl	-3136(%ebp)
L1348:
	movl	-3144(%ebp), %edi
	testb	$16, 12(%edi)
	je	L1353
L1349:
	movl	-3132(%ebp), %eax
	testl	%eax, %eax
	jle	L1456
	movl	_GeomXYZ, %eax
	testl	%eax, %eax
	jne	L1457
L1356:
	movl	_VariablesXYZ, %eax
	testl	%eax, %eax
	jne	L1458
L1357:
	xorl	%eax, %eax
	xorl	%esi, %esi
	xorl	%edi, %edi
	movl	%eax, _Dipole
	movl	-3132(%ebp), %eax
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, _GeomXYZ
	movl	-3132(%ebp), %edx
	movl	%eax, %ebx
	movl	%edi, -3148(%ebp)
	cmpl	%edx, %esi
	movl	%edx, -3196(%ebp)
	jl	L1361
	jmp	L1428
	.p2align 4,,7
L1441:
	movl	_GeomXYZ, %ebx
L1361:
	movl	-3196(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	incl	-3148(%ebp)
	movl	-3132(%ebp), %edi
	movl	%eax, 44(%esi,%ebx)
	addl	$48, %esi
	cmpl	%edi, -3148(%ebp)
	movl	%edi, -3196(%ebp)
	jl	L1441
L1428:
	xorl	%ecx, %ecx
	xorl	%ebx, %ebx
	movl	-3196(%ebp), %eax
	movl	%ebx, 8(%esp)
	xorl	%esi, %esi
	movl	%ecx, 4(%esp)
	movl	-3144(%ebp), %edx
	movl	%eax, _NcentersXYZ
	movl	%esi, _NVariablesXYZ
	movl	%edx, (%esp)
	call	_fseek
	movl	-3144(%ebp), %edi
	xorl	%edx, %edx
	movl	$-1, %eax
	movl	%edx, -3152(%ebp)
	movl	%eax, -3148(%ebp)
	testb	$16, 12(%edi)
	jne	L1442
	movl	-3132(%ebp), %edx
	leal	-3128(%ebp), %eax
	movl	%eax, -3176(%ebp)
	xorl	%eax, %eax
	movl	%edx, -3196(%ebp)
	movl	%eax, -3180(%ebp)
	jmp	L1402
	.p2align 4,,7
L1443:
	movl	-3132(%ebp), %edx
	movl	%edx, -3196(%ebp)
L1362:
	movl	-3144(%ebp), %edi
	testb	$16, 12(%edi)
	jne	L1363
L1402:
	xorl	%eax, %eax
	movl	-3180(%ebp), %edi
	movl	%eax, -3140(%ebp)
	movl	_GeomXYZ, %eax
	movl	44(%edi,%eax), %eax
	movl	%eax, -3160(%ebp)
	movl	-3144(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	movl	-3176(%ebp), %edx
	movl	%edx, (%esp)
	call	_fgets
	testl	%eax, %eax
	je	L1443
	leal	-2104(%ebp), %edi
	movl	$LC81, %eax
	movl	%edi, %esi
	movl	%edi, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-3176(%ebp), %eax
	movl	%eax, (%esp)
	call	_sscanf
	movl	%edi, (%esp)
	call	_g_strup
	cld
	movl	$LC203, %eax
	movl	$5, %ecx
	movl	%eax, %edi
	repe
	cmpsb
	je	L1367
	movl	$LC204, %edi
	movl	$4, %ecx
	leal	-2104(%ebp), %esi
	repe
	cmpsb
	jne	L1443
	movl	-52(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-2104(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$LC206, %eax
	movl	%eax, 4(%esp)
	movl	-3176(%ebp), %edi
	movl	%edi, (%esp)
	call	_sscanf
	movl	-56(%ebp), %eax
	movl	$1852534357, (%eax)
	movl	$7239535, 4(%eax)
L1370:
	xorl	%ebx, %ebx
	.p2align 4,,15
L1393:
	movl	-56(%ebp,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_delete_last_spaces
	movl	-56(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_delete_first_spaces
	cmpl	$5, %ebx
	jle	L1393
	cld
	movl	-56(%ebp), %esi
	movl	$LC208, %edi
	movl	$8, %ecx
	repe
	cmpsb
	jne	L1394
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-1080(%ebp), %eax
	movl	%eax, (%esp)
	call	_sprintf
	incl	-3148(%ebp)
	movl	-3132(%ebp), %edi
	movl	%edi, -3196(%ebp)
	jmp	L1362
L1367:
	movl	-32(%ebp), %eax
	leal	-2104(%ebp), %edx
	movl	$LC207, %edi
	xorl	%ebx, %ebx
	movl	%eax, 44(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 32(%esp)
	leal	-2104(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-56(%ebp), %eax
	movl	%edx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 16(%esp)
	movl	%edi, 4(%esp)
	movl	-3176(%ebp), %eax
	movl	%eax, (%esp)
	call	_sscanf
	movl	-3196(%ebp), %esi
	testl	%esi, %esi
	jle	L1431
	.p2align 4,,15
L1374:
	movl	-3160(%ebp), %edx
	movl	$0, (%edx,%ebx,4)
	incl	%ebx
	cmpl	-3196(%ebp), %ebx
	jl	L1374
L1431:
	movl	-3176(%ebp), %edi
	movl	%edi, (%esp)
	call	_gab_split
	movl	%eax, %esi
	xorl	%eax, %eax
	testl	%esi, %esi
	je	L1444
	movl	(%esi), %ebx
	testl	%ebx, %ebx
	je	L1444
	.p2align 4,,15
L1377:
	incl	%eax
	movl	(%esi,%eax,4), %ecx
	testl	%ecx, %ecx
	jne	L1377
	cmpl	$10, %eax
	jg	L1378
L1444:
	movl	%esi, (%esp)
	call	_g_strfreev
	xorl	%eax, %eax
L1379:
	movl	%eax, -3140(%ebp)
	jmp	L1370
L1442:
	movl	-3132(%ebp), %eax
	movl	%eax, -3196(%ebp)
L1363:
	movl	-3152(%ebp), %edx
	cmpl	%edx, -3196(%ebp)
	je	L1403
	movl	_GeomXYZ, %eax
	testl	%eax, %eax
	jne	L1459
L1404:
	movl	_VariablesXYZ, %eax
	testl	%eax, %eax
	jne	L1460
L1405:
	xorl	%eax, %eax
	movl	%eax, _NcentersXYZ
	xorl	%eax, %eax
	movl	%eax, _NVariablesXYZ
L1403:
	movl	-3144(%ebp), %edi
	movl	%edi, (%esp)
	call	_fclose
	xorl	%eax, %eax
	movl	%eax, -3148(%ebp)
	.p2align 4,,15
L1409:
	movl	-3148(%ebp), %edx
	movl	-56(%ebp,%edx,4), %eax
	movl	%eax, (%esp)
	call	_g_free
	incl	-3148(%ebp)
	cmpl	$7, -3148(%ebp)
	jle	L1409
	movl	-3156(%ebp), %eax
	testl	%eax, %eax
	jne	L1410
	xorl	%edi, %edi
	movl	%edi, -3148(%ebp)
	movl	-3132(%ebp), %edi
	cmpl	%edi, -3148(%ebp)
	movl	%edi, -3196(%ebp)
	jge	L1410
	xorl	%esi, %esi
	jmp	L1415
	.p2align 4,,7
L1413:
	incl	-3148(%ebp)
	addl	$48, %esi
	movl	-3196(%ebp), %edx
	cmpl	%edx, -3148(%ebp)
	jge	L1461
L1415:
	movl	_GeomXYZ, %ebx
	movl	44(%esi,%ebx), %eax
	testl	%eax, %eax
	je	L1413
	movl	%eax, (%esp)
	call	_g_free
	incl	-3148(%ebp)
	addl	$48, %esi
	movl	-3132(%ebp), %eax
	movl	%eax, -3196(%ebp)
	movl	-3196(%ebp), %edx
	cmpl	%edx, -3148(%ebp)
	jl	L1415
L1461:
	testl	%edx, %edx
	jle	L1410
	movl	%edx, -3148(%ebp)
	movl	_GeomXYZ, %eax
	addl	$44, %eax
	.p2align 4,,15
L1419:
	movl	$0, (%eax)
	addl	$48, %eax
	decl	-3148(%ebp)
	jne	L1419
L1410:
	movl	_GeomIsOpen, %esi
	testl	%esi, %esi
	jne	L1462
	movl	_ZoneDessin, %ebx
	testl	%ebx, %ebx
	je	L1463
L1448:
	call	_rafresh_drawing
	addl	$3244, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1458:
	movl	%eax, (%esp)
	call	_freeVariablesXYZ
	jmp	L1357
L1457:
	call	_freeGeomXYZ
	jmp	L1356
L1463:
	call	_create_window_drawing
L1452:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1448
	addl	$3244, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1394:
	movl	-3140(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	-3180(%ebp), %edx
	addl	%eax, -3156(%ebp)
	movl	-52(%ebp), %eax
	movl	$10, (%edx,%ebx)
	movl	%eax, (%esp)
	call	_g_strdup
	cld
	movl	-3180(%ebp), %edi
	movl	$2, %ecx
	movl	%eax, 4(%edi,%ebx)
	movl	-56(%ebp), %esi
	movl	$LC209, %edi
	repe
	cmpsb
	jne	L1395
	movl	-52(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-3180(%ebp), %edx
	movl	%eax, 12(%edx,%ebx)
L1396:
	cld
	movl	-48(%ebp), %eax
	movl	$LC210, %edi
	movl	$3, %ecx
	movl	%eax, %esi
	movl	%eax, -3172(%ebp)
	repe
	cmpsb
	jne	L1397
	movl	-52(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
L1450:
	call	_g_strdup
	movl	-3180(%ebp), %edx
	movl	%eax, 8(%edx,%ebx)
	leal	-1080(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	cmpl	$1, _Units
	movl	-3180(%ebp), %edi
	movl	%eax, 16(%edi,%ebx)
	movl	_GeomXYZ, %ebx
	movl	-3148(%ebp), %eax
	movl	%eax, 20(%edi,%ebx)
	je	L1464
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_ang_to_bohr
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-3180(%ebp), %edx
	movl	%eax, 28(%edx,%ebx)
	movl	-36(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_ang_to_bohr
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-3180(%ebp), %edi
	movl	%eax, 32(%edi,%ebx)
	movl	-32(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_ang_to_bohr
L1451:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 36(%edi,%ebx)
	movl	-44(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-3180(%ebp), %edx
	movl	%eax, 24(%edx,%ebx)
	movl	_GeomXYZ, %ebx
	movl	$LC83, (%esp)
	call	_g_strdup
	incl	-3152(%ebp)
	movl	-3180(%ebp), %edi
	movl	%eax, 40(%edi,%ebx)
	movl	-3132(%ebp), %eax
	addl	$48, %edi
	cmpl	%eax, -3152(%ebp)
	movl	%edi, -3180(%ebp)
	movl	%eax, -3196(%ebp)
	jl	L1362
	jmp	L1363
	.p2align 4,,7
L1462:
	movl	$44, (%esp)
	call	_create_geomXYZ_interface
	jmp	L1452
L1455:
	movl	%edi, 4(%esp)
	movl	$LC202, (%esp)
L1453:
	call	_g_strdup_printf
	movl	%eax, %ebx
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC75, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_MessageGeom
	movl	%ebx, (%esp)
	call	_g_free
	addl	$3244, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1460:
	movl	%eax, (%esp)
	call	_freeVariablesXYZ
	jmp	L1405
L1459:
	call	_freeGeomXYZ
	jmp	L1404
L1397:
	movl	-3172(%ebp), %edi
	movl	_GeomXYZ, %ebx
	movl	%edi, (%esp)
	jmp	L1450
L1395:
	movl	-52(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-3180(%ebp), %edi
	movl	%eax, 12(%edi,%ebx)
	jmp	L1396
L1456:
	movl	8(%ebp), %eax
	movl	$LC205, (%esp)
	movl	%eax, 4(%esp)
	jmp	L1453
L1464:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 28(%edi,%ebx)
	movl	-36(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	%eax, 32(%edi,%ebx)
	movl	-32(%ebp), %eax
	movl	_GeomXYZ, %ebx
	jmp	L1451
L1378:
	movl	40(%esi), %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -3164(%ebp)
	addl	%eax, %eax
	cmpl	$0, %eax
	jmp	L1449
L1465:
	movl	44(%esi,%ebx,4), %eax
	testl	%eax, %eax
	je	L1381
	movl	48(%esi,%ebx,4), %edx
	testl	%edx, %edx
	je	L1381
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, -3168(%ebp)
	movl	$100, %eax
	movl	$1, %edi
	movl	%eax, 4(%esp)
	movl	48(%esi,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_strchr
	testl	%eax, %eax
	je	L1385
	movl	$2, %edi
L1385:
	movl	$68, %ecx
	movl	%ecx, 4(%esp)
	movl	48(%esi,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_strchr
	testl	%eax, %eax
	je	L1386
	movl	$2, %edi
L1386:
	movl	$116, %edx
	movl	%edx, 4(%esp)
	movl	48(%esi,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_strchr
	testl	%eax, %eax
	je	L1387
	movl	$3, %edi
L1387:
	movl	$84, %eax
	movl	%eax, 4(%esp)
	movl	48(%esi,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_strchr
	testl	%eax, %eax
	je	L1388
	movl	$3, %edi
L1388:
	movl	-3168(%ebp), %eax
	addl	$2, %ebx
	movl	-3160(%ebp), %edx
	movl	%edi, -4(%edx,%eax,4)
	movl	-3164(%ebp), %eax
	addl	%eax, %eax
	cmpl	%ebx, %eax
L1449:
	jg	L1465
L1381:
	movl	%esi, (%esp)
	call	_g_strfreev
	movl	$1, %eax
	jmp	L1379
	.section .rdata,"dr"
LC211:
	.ascii "Sorry\12 No file selected\0"
	.text
	.p2align 4,,15
.globl _read_hin_file
	.def	_read_hin_file;	.scl	2;	.type	32;	.endef
_read_hin_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$72, %esp
	cmpl	$-5, 12(%ebp)
	movl	%ebx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%esi, -8(%ebp)
	movl	%edi, -4(%ebp)
	je	L1471
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L1471:
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	testl	%eax, %eax
	movl	%eax, %ebx
	je	L1469
	cmpb	$0, (%eax)
	jne	L1468
L1469:
	movl	$LC211, (%esp)
	movl	$1, %ecx
	movl	$LC75, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_MessageGeom
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L1468:
	movl	%eax, (%esp)
	call	_read_hin_file_no_add_list
	movl	%ebx, (%esp)
	call	_get_name_file
	movl	%eax, -16(%ebp)
	movl	%ebx, (%esp)
	call	_get_suffix_name_file
	movl	%eax, (%esp)
	movl	%eax, %esi
	call	_get_name_file
	movl	%esi, (%esp)
	movl	%eax, %edi
	call	_get_name_dir
	movl	%eax, %ebx
	movl	_lastdirectory, %eax
	testl	%eax, %eax
	jne	L1472
L1470:
	movl	%ebx, (%esp)
	call	_g_strdup
	movl	%eax, _lastdirectory
	movl	_defaultNetWorkProtocol, %eax
	movl	%ebx, 16(%esp)
	movl	%eax, 44(%esp)
	xorl	%eax, %eax
	movl	%eax, 40(%esp)
	movl	$16, %eax
	movl	%eax, 36(%esp)
	xorl	%eax, %eax
	movl	%eax, 32(%esp)
	xorl	%eax, %eax
	movl	%eax, 28(%esp)
	xorl	%eax, %eax
	movl	%eax, 24(%esp)
	xorl	%eax, %eax
	movl	%eax, 20(%esp)
	movl	-16(%ebp), %eax
	movl	%edi, 8(%esp)
	movl	%eax, 12(%esp)
	movl	_noeud+64, %eax
	movl	%eax, 4(%esp)
	movl	_treeViewProjects, %eax
	movl	%eax, (%esp)
	call	_CreeFeuille
	movl	%esi, (%esp)
	call	_g_free
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	movl	%ebx, 8(%ebp)
	movl	-8(%ebp), %esi
	movl	-12(%ebp), %ebx
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	jmp	_g_free
L1472:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L1470
	.p2align 4,,15
	.def	_add_gabedit_file_to_list;	.scl	3;	.type	32;	.endef
_add_gabedit_file_to_list:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	movl	%eax, %ebx
	movl	%eax, (%esp)
	call	_get_name_file
	movl	%eax, -16(%ebp)
	movl	%ebx, (%esp)
	call	_get_suffix_name_file
	movl	%eax, (%esp)
	movl	%eax, %esi
	call	_get_name_file
	movl	%esi, (%esp)
	movl	%eax, %edi
	call	_get_name_dir
	movl	%eax, %ebx
	movl	_lastdirectory, %eax
	testl	%eax, %eax
	jne	L1475
L1474:
	movl	%ebx, (%esp)
	call	_g_strdup
	movl	%eax, _lastdirectory
	movl	_defaultNetWorkProtocol, %eax
	movl	%ebx, 16(%esp)
	movl	%edi, 8(%esp)
	movl	%eax, 44(%esp)
	xorl	%eax, %eax
	movl	%eax, 40(%esp)
	movl	$9, %eax
	movl	%eax, 36(%esp)
	xorl	%eax, %eax
	movl	%eax, 32(%esp)
	xorl	%eax, %eax
	movl	%eax, 28(%esp)
	xorl	%eax, %eax
	movl	%eax, 24(%esp)
	xorl	%eax, %eax
	movl	%eax, 20(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	_noeud+36, %eax
	movl	%eax, 4(%esp)
	movl	_treeViewProjects, %eax
	movl	%eax, (%esp)
	call	_CreeFeuille
	movl	%esi, (%esp)
	call	_g_free
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	movl	%ebx, (%esp)
	call	_g_free
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1475:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L1474
	.section .rdata,"dr"
LC212:
	.ascii "\\\0"
LC213:
	.ascii "%s%stmp%sfout\0"
LC214:
	.ascii "%s%stmp%sferr\0"
LC215:
	.ascii "%s%stmp%sgeom.xyz\0"
LC216:
	.ascii "xyz\0"
LC217:
	.ascii "EntryFileName\0"
LC218:
	.ascii "EntryCombo\0"
LC219:
	.ascii "Automatic\0"
LC221:
	.ascii "Info\0"
LC220:
	.ascii "%s -i%s %s -o%s %s\0"
	.text
	.p2align 4,,15
	.def	_save_in_xyz_and_conversion;	.scl	3;	.type	32;	.endef
_save_in_xyz_and_conversion:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$LC212, %edi
	pushl	%esi
	movl	$LC212, %esi
	pushl	%ebx
	subl	$188, %esp
	movl	12(%ebp), %ebx
	call	_gabedit_directory
	movl	%eax, 4(%esp)
	movl	%edi, 12(%esp)
	movl	$LC212, %edi
	movl	%esi, 8(%esp)
	movl	$LC212, %esi
	movl	$LC213, (%esp)
	call	_g_strdup_printf
	movl	%eax, -144(%ebp)
	call	_gabedit_directory
	movl	%eax, 4(%esp)
	movl	$LC212, %ecx
	movl	$LC212, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	$LC214, (%esp)
	call	_g_strdup_printf
	movl	%eax, -148(%ebp)
	call	_gabedit_directory
	movl	%eax, 4(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC215, (%esp)
	call	_g_strdup_printf
	movl	%ebx, (%esp)
	movl	%eax, %edi
	movl	LC216, %eax
	movl	%eax, -140(%ebp)
	call	_this_is_an_object
	testl	%eax, %eax
	jne	L1485
L1476:
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1485:
	movl	%ebx, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC217, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%ebx, (%esp)
	movl	%eax, %esi
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC218, %ecx
	movl	%ecx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -152(%ebp)
	movl	%esi, (%esp)
	call	_this_is_an_object
	testl	%eax, %eax
	je	L1476
	movl	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	_this_is_an_object
	testl	%eax, %eax
	je	L1476
	movl	%edi, (%esp)
	call	_save_xyz_file_no_add_list
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%ebx, 4(%esp)
	movl	%eax, %esi
	movl	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, %ebx
	movl	$LC81, %edx
	leal	-136(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	%ebx, (%esp)
	call	_sscanf
	movl	%ebx, (%esp)
	movl	$LC219, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1480
	movl	%esi, 12(%esp)
	movl	_babelCommand, %eax
	movl	%edi, 8(%esp)
	movl	$LC206, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
L1484:
	movl	%eax, -156(%ebp)
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	movl	-156(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_run_local_command
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_cat_file
	movl	%eax, %ebx
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	_cat_file
	testl	%ebx, %ebx
	movl	%eax, %esi
	je	L1482
	movl	%ebx, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC221, %eax
	movl	%eax, 4(%esp)
	call	_Message
	movl	%ebx, (%esp)
	call	_g_free
L1482:
	testl	%esi, %esi
	je	L1483
	movl	%esi, (%esp)
	movl	$1, %ecx
	movl	$LC95, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_Message
	movl	%esi, (%esp)
	call	_g_free
L1483:
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_unlink
	movl	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	_unlink
	movl	%edi, (%esp)
	call	_unlink
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	jmp	L1476
L1480:
	movl	%esi, 20(%esp)
	leal	-136(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-140(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	_babelCommand, %eax
	movl	%edi, 12(%esp)
	movl	$LC220, (%esp)
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	jmp	L1484
	.section .rdata,"dr"
LC222:
	.ascii "Window\0"
	.text
	.p2align 4,,15
.globl _create_babel_save_dialogue
	.def	_create_babel_save_dialogue;	.scl	2;	.type	32;	.endef
_create_babel_save_dialogue:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$32, %esp
	movl	$0, (%esp)
	call	_create_babel_read_save_dialogue
	movl	%eax, (%esp)
	movl	$80, %ecx
	movl	%eax, %ebx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC222, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%ebx, (%esp)
	movl	%eax, %esi
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$_save_in_xyz_and_conversion, %ecx
	movl	%edx, 16(%esp)
	movl	$LC136, %edx
	movl	%edx, 4(%esp)
	movl	%ecx, 8(%esp)
	movl	%esi, 12(%esp)
	call	_g_signal_connect_data
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, (%esp)
	movl	$80, %ecx
	movl	%eax, %esi
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ebx, %ebx
	movl	%edx, 20(%esp)
	movl	$_delete_child, %ecx
	movl	$LC136, %edx
	movl	%ebx, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	addl	$32, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC223:
	.ascii "%s.hin\0"
LC224:
	.ascii "forcefield Amber99\12\0"
LC225:
	.ascii "sys 0 0 1\12\0"
	.align 4
LC226:
	.ascii "view 40 0.1272 55 15 0.247224 0.3713666 0.8949677 -0.8641704 0.5022867 0.0302929 -0.4382806 -0.7808937 0.4451014 6.191 0.64575 -54.754\12\0"
LC227:
	.ascii "seed -1108\12\0"
LC228:
	.ascii "mol 1\12\0"
LC236:
	.ascii "%s %d \0"
LC237:
	.ascii "%s \0"
LC238:
	.ascii "%s - \0"
LC239:
	.ascii "%f \0"
LC240:
	.ascii "%d \0"
LC243:
	.ascii "%d s \0"
LC229:
	.ascii "U\0"
LC244:
	.ascii "endmol 1\12\0"
LC230:
	.ascii "res 1 %s 1 - - \12\0"
LC242:
	.ascii "%d d \0"
LC241:
	.ascii "%d t \0"
LC231:
	.ascii "endres %d\12\0"
LC232:
	.ascii "res %d %s %d - - \12\0"
	.align 8
LC233:
	.long	640652440
	.long	1071705861
	.text
	.p2align 4,,15
.globl _save_hin_file
	.def	_save_hin_file;	.scl	2;	.type	32;	.endef
_save_hin_file:
	pushl	%ebp
	movl	$1, %eax
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$140, %esp
	movl	_NcentersXYZ, %edx
	testl	%edx, %edx
	jne	L1534
L1487:
	addl	$140, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1534:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	$LC223, (%esp)
	call	_g_strdup_printf
	movl	%eax, 8(%ebp)
	movl	%ebx, (%esp)
	call	_g_free
	movl	$LC93, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	_FOpen
	movl	%eax, -24(%ebp)
	testl	%eax, %eax
	je	L1535
	call	_sortGeomXYZByResidueNumber
	movl	-24(%ebp), %ebx
	movl	$19, %eax
	movl	$10, %edi
	movl	%eax, 8(%esp)
	movl	$1, %esi
	movl	$1, %eax
	movl	%ebx, 12(%esp)
	movl	%eax, 4(%esp)
	movl	$LC224, (%esp)
	call	_fwrite
	movl	%ebx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	$LC225, (%esp)
	call	_fwrite
	movl	%ebx, 12(%esp)
	movl	$135, %ecx
	movl	$1, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	$LC226, (%esp)
	call	_fwrite
	movl	%ebx, 12(%esp)
	movl	$11, %eax
	movl	%eax, 8(%esp)
	movl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$LC227, (%esp)
	call	_fwrite
	movl	%ebx, 12(%esp)
	movl	$6, %eax
	movl	%eax, 8(%esp)
	movl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$LC228, (%esp)
	call	_fwrite
	movl	_NcentersXYZ, %ebx
	testl	%ebx, %ebx
	jne	L1536
L1490:
	leal	0(,%ebx,4), %eax
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -56(%ebp)
	movl	_NcentersXYZ, %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -60(%ebp)
	movl	_NcentersXYZ, %ebx
	movl	$1, -20(%ebp)
	cmpl	$0, %ebx
	jle	L1523
	.p2align 4,,15
L1548:
	movl	$0, -64(%ebp)
	movl	_GeomXYZ, %edx
	movl	%edx, -88(%ebp)
	movl	-88(%ebp), %ecx
	leal	(%edi,%edi,2), %edx
	sall	$4, %edx
	movl	44(%edx,%ecx), %eax
	testl	%eax, %eax
	je	L1494
	xorl	%eax, %eax
	cmpl	$0, %ebx
	jle	L1494
	movl	%edx, -92(%ebp)
	.p2align 4,,15
L1500:
	cmpl	%eax, %edi
	leal	1(%edi), %edx
	je	L1497
	movl	-92(%ebp), %esi
	movl	-88(%ebp), %edx
	movl	44(%esi,%edx), %ecx
	leal	1(%eax), %edx
	movl	(%ecx,%eax,4), %esi
	testl	%esi, %esi
	jle	L1497
	movl	-64(%ebp), %ebx
	movl	-56(%ebp), %esi
	movl	%edx, (%esi,%ebx,4)
	movl	(%ecx,%eax,4), %eax
	movl	-60(%ebp), %ecx
	movl	%eax, (%ecx,%ebx,4)
	incl	%ebx
	movl	%ebx, -64(%ebp)
	movl	_NcentersXYZ, %ebx
L1497:
	cmpl	%edx, %ebx
	movl	%edx, %eax
	jg	L1500
L1494:
	testl	%edi, %edi
	jle	L1501
	movl	-88(%ebp), %ebx
	leal	(%edi,%edi,2), %esi
	sall	$4, %esi
	movl	-32(%ebx,%esi), %eax
	movl	%eax, 4(%esp)
	movl	16(%esi,%ebx), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L1537
L1501:
	movl	-88(%ebp), %esi
	leal	(%edi,%edi,2), %ebx
	sall	$4, %ebx
	movl	28(%ebx,%esi), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1502
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
L1529:
	fstpl	-32(%ebp)
	movl	_GeomXYZ, %eax
	leal	(%edi,%edi,2), %ebx
	sall	$4, %ebx
	movl	32(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1504
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	leal	(%edi,%edi,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
	movl	_GeomXYZ, %eax
	fstpl	-40(%ebp)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1506
L1549:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
L1531:
	fstpl	-48(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L1508
	fldl	LC233
	fldl	-32(%ebp)
	fmul	%st(1), %st
	fstpl	-32(%ebp)
	fldl	-40(%ebp)
	fmul	%st(1), %st
	fxch	%st(1)
	fmull	-48(%ebp)
	fxch	%st(1)
	fstpl	-40(%ebp)
	fstpl	-48(%ebp)
L1508:
	movl	_GeomXYZ, %edx
	leal	1(%edi), %eax
	movl	%eax, -84(%ebp)
	leal	(%edi,%edi,2), %eax
	sall	$4, %eax
	movl	12(%eax,%edx), %ebx
	movl	4(%eax,%edx), %esi
	movl	8(%eax,%edx), %edi
	movl	24(%eax,%edx), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	-84(%ebp), %edx
	movl	$LC203, %eax
	fstpl	-80(%ebp)
	movl	%eax, 8(%esp)
	movl	$LC236, %eax
	movl	%edx, 12(%esp)
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_fprintf
	movl	%ebx, 8(%esp)
	movl	$LC237, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_fprintf
	movl	%esi, 8(%esp)
	movl	$LC237, %eax
	movl	$LC238, %esi
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_fprintf
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	_fprintf
	fldl	-80(%ebp)
	movl	$LC239, %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	fstpl	8(%esp)
	call	_fprintf
	fldl	-32(%ebp)
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, (%esp)
	fstpl	8(%esp)
	call	_fprintf
	fldl	-40(%ebp)
	movl	$LC239, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	fstpl	8(%esp)
	call	_fprintf
	fldl	-48(%ebp)
	movl	$LC239, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	fstpl	8(%esp)
	call	_fprintf
	movl	-64(%ebp), %eax
	testl	%eax, %eax
	jle	L1509
	movl	-64(%ebp), %eax
	movl	%ebx, (%esp)
	xorl	%ebx, %ebx
	movl	%eax, 8(%esp)
	movl	$LC240, %eax
	movl	%eax, 4(%esp)
	call	_fprintf
	jmp	L1532
	.p2align 4,,7
L1540:
	movl	-60(%ebp), %edx
	movl	(%edx,%ebx,4), %eax
	cmpl	$3, %eax
	je	L1538
	cmpl	$2, %eax
	je	L1539
	movl	-56(%ebp), %esi
	movl	$LC243, %edi
	movl	(%esi,%ebx,4), %eax
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
L1533:
	call	_fprintf
	incl	%ebx
L1532:
	cmpl	-64(%ebp), %ebx
	jl	L1540
L1509:
	movl	-24(%ebp), %edx
	movl	$10, (%esp)
	movl	%edx, 4(%esp)
	call	_fputc
	movl	-84(%ebp), %edi
	movl	_NcentersXYZ, %ebx
	cmpl	%edi, %ebx
	jg	L1548
L1523:
	testl	%ebx, %ebx
	je	L1520
	cld
	movl	_GeomXYZ, %esi
	movl	$LC229, %edi
	leal	(%ebx,%ebx,2), %eax
	movl	$2, %ecx
	sall	$4, %eax
	addl	%esi, %eax
	movl	-32(%eax), %esi
	repe
	cmpsb
	jne	L1542
L1520:
	movl	-24(%ebp), %esi
	movl	$9, %ecx
	movl	$1, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%esi, 12(%esp)
	movl	$LC244, (%esp)
	call	_fwrite
	movl	%esi, (%esp)
	call	_fclose
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-60(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	8(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_get_name_file
	movl	%eax, -52(%ebp)
	movl	8(%ebp), %ebx
	movl	%ebx, (%esp)
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
	jne	L1543
L1521:
	movl	%esi, (%esp)
	call	_g_strdup
	movl	%eax, _lastdirectory
	movl	_defaultNetWorkProtocol, %eax
	movl	%esi, 16(%esp)
	movl	%eax, 44(%esp)
	xorl	%eax, %eax
	movl	%eax, 40(%esp)
	movl	$16, %eax
	movl	%eax, 36(%esp)
	xorl	%eax, %eax
	movl	%eax, 32(%esp)
	xorl	%eax, %eax
	movl	%eax, 28(%esp)
	xorl	%eax, %eax
	movl	%eax, 24(%esp)
	xorl	%eax, %eax
	movl	%eax, 20(%esp)
	movl	-52(%ebp), %eax
	movl	%edi, 8(%esp)
	movl	%eax, 12(%esp)
	movl	_noeud+64, %eax
	movl	%eax, 4(%esp)
	movl	_treeViewProjects, %eax
	movl	%eax, (%esp)
	call	_CreeFeuille
	movl	%ebx, (%esp)
	call	_g_free
	movl	-52(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	movl	%esi, (%esp)
	call	_g_free
	addl	$140, %esp
	movl	$1, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1536:
	cld
	movl	_GeomXYZ, %eax
	movl	$LC229, %edi
	movl	$2, %ecx
	movl	16(%eax), %eax
	movl	%eax, %esi
	movl	%eax, -68(%ebp)
	repe
	cmpsb
	je	L1490
	movl	-68(%ebp), %esi
	movl	$LC230, %eax
	movl	%eax, 4(%esp)
	movl	%esi, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	movl	_NcentersXYZ, %ebx
	jmp	L1490
	.p2align 4,,7
L1539:
	movl	-56(%ebp), %edx
	movl	(%edx,%ebx,4), %eax
	movl	%eax, 8(%esp)
	movl	$LC242, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	jmp	L1533
	.p2align 4,,7
L1538:
	movl	-56(%ebp), %ecx
	movl	(%ecx,%ebx,4), %eax
	movl	%eax, 8(%esp)
	movl	$LC241, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %esi
	movl	%esi, (%esp)
	jmp	L1533
	.p2align 4,,7
L1504:
	movl	_GeomXYZ, %eax
	movl	32(%ebx,%eax), %eax
	leal	(%edi,%edi,2), %ebx
	sall	$4, %ebx
	movl	%eax, (%esp)
	call	_atof
	movl	_GeomXYZ, %eax
	fstpl	-40(%ebp)
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	je	L1549
L1506:
	movl	_GeomXYZ, %eax
	movl	36(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L1531
	.p2align 4,,7
L1502:
	movl	_GeomXYZ, %eax
	movl	28(%ebx,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L1529
L1537:
	movl	-20(%ebp), %eax
	movl	$LC231, %edx
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_fprintf
	movl	-20(%ebp), %ebx
	movl	_GeomXYZ, %eax
	incl	%ebx
	movl	%ebx, 16(%esp)
	movl	16(%esi,%eax), %eax
	movl	%ebx, 8(%esp)
	movl	%eax, 12(%esp)
	movl	$LC232, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_fprintf
	movl	%ebx, -20(%ebp)
	movl	_GeomXYZ, %ebx
	movl	%ebx, -88(%ebp)
	jmp	L1501
L1543:
	movl	%eax, (%esp)
	call	_g_free
	jmp	L1521
L1535:
	movl	8(%ebp), %ecx
	movl	$LC94, (%esp)
	movl	%ecx, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC95, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_Message
	movl	%ebx, (%esp)
	call	_g_free
	xorl	%eax, %eax
	jmp	L1487
L1542:
	movl	-20(%ebp), %ecx
	movl	$LC231, %ebx
	movl	%ebx, 4(%esp)
	movl	%ecx, 8(%esp)
	movl	-24(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_fprintf
	jmp	L1520
	.p2align 4,,15
.globl _save_geometry_hin_file
	.def	_save_geometry_hin_file;	.scl	2;	.type	32;	.endef
_save_geometry_hin_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$-5, 12(%ebp)
	movl	8(%ebp), %eax
	je	L1554
	leave
	ret
	.p2align 4,,7
L1554:
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	testl	%eax, %eax
	je	L1553
	cmpb	$0, (%eax)
	jne	L1552
L1553:
	movl	$LC104, (%esp)
	movl	$1, %eax
	movl	$LC75, %ecx
	movl	%eax, 8(%esp)
	movl	%ecx, 4(%esp)
	call	_Message
	leave
	ret
L1552:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_hin_file
	.p2align 4,,15
.globl _save_hin_file_entry
	.def	_save_hin_file_entry;	.scl	2;	.type	32;	.endef
_save_hin_file_entry:
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
	je	L1555
	cmpb	$0, (%eax)
	jne	L1558
L1555:
	leave
	ret
	.p2align 4,,7
L1558:
	movl	%eax, 8(%ebp)
	leave
	jmp	_save_hin_file
	.section .rdata,"dr"
LC246:
	.ascii "[Gabedit Format]\12\0"
LC247:
	.ascii "[GEOMS]\12\0"
LC248:
	.ascii "1 1\12\0"
LC249:
	.ascii "ENERGY UNK 1\12\0"
LC250:
	.ascii "0.0\12\0"
LC251:
	.ascii "%d %d %d\12\0"
	.align 4
LC253:
	.ascii " %s %s %s %s %d %f %d %f %f %f \0"
LC254:
	.ascii " %d \0"
LC255:
	.ascii " %d %d\0"
	.align 8
LC252:
	.long	640652440
	.long	1071705861
	.text
	.p2align 4,,15
.globl _save_geometry_gabedit_file
	.def	_save_geometry_gabedit_file;	.scl	2;	.type	32;	.endef
_save_geometry_gabedit_file:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$136, %esp
	cmpl	$-5, 12(%ebp)
	movl	%ebx, -12(%ebp)
	movl	%esi, -8(%ebp)
	movl	%edi, -4(%ebp)
	je	L1601
L1559:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L1601:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_gabedit_file_chooser_get_current_file
	movl	%eax, -20(%ebp)
	testl	%eax, %eax
	je	L1562
	cmpb	$0, (%eax)
	jne	L1561
L1562:
	movl	$LC104, (%esp)
	movl	$LC75, %edi
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	call	_Message
	jmp	L1559
L1561:
	movl	_NcentersXYZ, %esi
	testl	%esi, %esi
	je	L1559
	movl	_GeomXYZ, %ebx
	testl	%ebx, %ebx
	je	L1559
	movl	-20(%ebp), %eax
	movl	$LC93, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_fopen
	movl	%eax, -24(%ebp)
	testl	%eax, %eax
	je	L1559
	movl	%eax, 12(%esp)
	movl	$17, %edx
	movl	$1, %eax
	movl	%edx, 8(%esp)
	movl	$1, %edi
	movl	$4, %esi
	movl	%eax, 4(%esp)
	movl	$LC246, (%esp)
	call	_fwrite
	movl	$LC247, (%esp)
	movl	-24(%ebp), %edx
	movl	$8, %eax
	movl	%eax, 8(%esp)
	movl	$1, %eax
	movl	%edx, 12(%esp)
	movl	%eax, 4(%esp)
	call	_fwrite
	movl	$LC248, (%esp)
	movl	-24(%ebp), %ecx
	movl	$4, %eax
	movl	%eax, 8(%esp)
	movl	$1, %eax
	movl	%ecx, 12(%esp)
	movl	%eax, 4(%esp)
	call	_fwrite
	movl	%edi, 4(%esp)
	movl	-24(%ebp), %ebx
	movl	$13, %eax
	movl	%eax, 8(%esp)
	movl	$LC249, (%esp)
	movl	%ebx, 12(%esp)
	call	_fwrite
	movl	%ebx, 12(%esp)
	movl	$1, %ecx
	movl	%ecx, 4(%esp)
	movl	%esi, 8(%esp)
	movl	$LC250, (%esp)
	call	_fwrite
	movl	%ebx, (%esp)
	movl	_SpinMultiplicities, %eax
	movl	$LC251, %edx
	movl	%edx, 4(%esp)
	movl	%eax, 16(%esp)
	movl	_TotalCharges, %eax
	movl	%eax, 12(%esp)
	movl	_Natoms, %eax
	movl	%eax, 8(%esp)
	call	_fprintf
	movl	_NcentersXYZ, %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -64(%ebp)
	movl	_NcentersXYZ, %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, -68(%ebp)
	xorl	%eax, %eax
	cmpl	_NcentersXYZ, %eax
	movl	$0, -28(%ebp)
	jae	L1590
	xorl	%edi, %edi
L1588:
	movl	_GeomXYZ, %eax
	movl	28(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1570
	movl	_GeomXYZ, %eax
	movl	28(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
L1596:
	fstpl	-40(%ebp)
	movl	_GeomXYZ, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1572
	movl	_GeomXYZ, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
L1597:
	fstpl	-48(%ebp)
	movl	_GeomXYZ, %eax
	movl	36(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_test
	testl	%eax, %eax
	jne	L1574
	movl	_GeomXYZ, %eax
	movl	36(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_get_value_variableXYZ
L1598:
	fstpl	-56(%ebp)
	movl	_Units, %eax
	testl	%eax, %eax
	jne	L1576
	fldl	LC252
	fldl	-40(%ebp)
	fmul	%st(1), %st
	fstpl	-40(%ebp)
	fldl	-48(%ebp)
	fmul	%st(1), %st
	fxch	%st(1)
	fmull	-56(%ebp)
	fxch	%st(1)
	fstpl	-48(%ebp)
	fstpl	-56(%ebp)
L1576:
	movl	$0, -60(%ebp)
	movl	_GeomXYZ, %esi
	movl	44(%edi,%esi), %eax
	testl	%eax, %eax
	je	L1577
	movl	_NcentersXYZ, %ecx
	xorl	%ebx, %ebx
	cmpl	$0, %ecx
	.p2align 4,,15
L1599:
	jle	L1577
	movl	-28(%ebp), %edx
	cmpl	%ebx, %edx
	leal	1(%edx), %eax
	je	L1580
	movl	44(%edi,%esi), %eax
	movl	(%eax,%ebx,4), %edx
	leal	1(%ebx), %eax
	testl	%edx, %edx
	je	L1580
	movl	-60(%ebp), %ecx
	movl	-64(%ebp), %ebx
	movl	%eax, (%ebx,%ecx,4)
	movl	-68(%ebp), %ebx
	movl	%edx, (%ebx,%ecx,4)
	incl	%ecx
	movl	%ecx, -60(%ebp)
	movl	_NcentersXYZ, %ecx
	.p2align 4,,15
L1580:
	movl	%eax, %ebx
	cmpl	%eax, %ecx
	jmp	L1599
L1577:
	movl	40(%edi,%esi), %eax
	call	_get_layer
	movl	%eax, %ebx
	movl	24(%edi,%esi), %eax
	movl	%eax, (%esp)
	call	_atof
	fldl	-56(%ebp)
	fxch	%st(1)
	movl	%ebx, 36(%esp)
	movl	_GeomXYZ, %edx
	fstpl	28(%esp)
	xorl	%ebx, %ebx
	fstpl	56(%esp)
	fldl	-48(%ebp)
	fstpl	48(%esp)
	fldl	-40(%ebp)
	fstpl	40(%esp)
	movl	20(%edi,%edx), %eax
	movl	%eax, 24(%esp)
	movl	16(%edi,%edx), %eax
	movl	%eax, 20(%esp)
	movl	12(%edi,%edx), %eax
	movl	%eax, 16(%esp)
	movl	8(%edi,%edx), %eax
	movl	%eax, 12(%esp)
	movl	4(%edi,%edx), %eax
	movl	%eax, 8(%esp)
	movl	$LC253, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	movl	-60(%ebp), %edx
	movl	$LC254, %eax
	movl	-24(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%ecx, (%esp)
	call	_fprintf
	cmpl	-60(%ebp), %ebx
	jge	L1593
	.p2align 4,,15
L1604:
	movl	-68(%ebp), %edx
	movl	-64(%ebp), %ecx
	movl	(%edx,%ebx,4), %eax
	movl	%eax, 12(%esp)
	movl	(%ecx,%ebx,4), %eax
	incl	%ebx
	movl	%eax, 8(%esp)
	movl	$LC255, %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_fprintf
	cmpl	-60(%ebp), %ebx
	jl	L1604
L1593:
	movl	$10, (%esp)
	movl	-24(%ebp), %edx
	addl	$48, %edi
	movl	%edx, 4(%esp)
	call	_fputc
	incl	-28(%ebp)
	movl	-28(%ebp), %ecx
	cmpl	_NcentersXYZ, %ecx
	jb	L1588
L1590:
	movl	-24(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_fclose
	movl	-20(%ebp), %eax
	call	_add_gabedit_file_to_list
	jmp	L1559
L1574:
	movl	_GeomXYZ, %eax
	movl	36(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L1598
L1570:
	movl	_GeomXYZ, %eax
	movl	28(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L1596
L1572:
	movl	_GeomXYZ, %eax
	movl	32(%edi,%eax), %eax
	movl	%eax, (%esp)
	call	_atof
	jmp	L1597
	.section .rdata,"dr"
LC258:
	.ascii "%s %s %s %s\0"
LC257:
	.ascii "Sorry\12 this is not a XYZ file\0"
	.text
	.p2align 4,,15
.globl _read_XYZ_file_no_add_list
	.def	_read_XYZ_file_no_add_list;	.scl	2;	.type	32;	.endef
_read_XYZ_file_no_add_list:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	xorl	%ebx, %ebx
	.p2align 4,,15
L1609:
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, -56(%ebp,%ebx,4)
	incl	%ebx
	cmpl	$4, %ebx
	jbe	L1609
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, -60(%ebp)
	movl	$LC201, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_FOpen
	movl	%eax, -64(%ebp)
	testl	%eax, %eax
	je	L1610
	movl	%eax, 8(%esp)
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	_fgets
	movl	-60(%ebp), %edx
	movl	%edx, (%esp)
	call	_atoi
	testl	%eax, %eax
	movl	%eax, %ebx
	jle	L1646
	movl	_GeomXYZ, %ecx
	xorl	%esi, %esi
	movl	%esi, _Dipole
	testl	%ecx, %ecx
	jne	L1647
L1613:
	movl	_VariablesXYZ, %eax
	testl	%eax, %eax
	jne	L1648
L1614:
	movl	%ebx, _NcentersXYZ
	leal	(%ebx,%ebx,2), %eax
	sall	$4, %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	%eax, _GeomXYZ
	movl	_NcentersXYZ, %edx
	testl	%edx, %edx
	je	L1612
	addl	$44, %eax
	movl	%edx, %edi
	.p2align 4,,15
L1618:
	movl	$0, (%eax)
	addl	$48, %eax
	decl	%edi
	jne	L1618
L1612:
	movl	-64(%ebp), %eax
	movl	$1024, %edx
	movl	$-1, %edi
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-60(%ebp), %edx
	movl	%edx, (%esp)
	call	_fgets
	movl	-64(%ebp), %eax
	testb	$16, 12(%eax)
	jne	L1620
	movl	_NcentersXYZ, %eax
	cmpl	$-1, %eax
	jle	L1620
	movl	$-48, -68(%ebp)
	jmp	L1627
	.p2align 4,,7
L1625:
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_ang_to_bohr
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 28(%edx,%ebx)
	movl	-48(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_ang_to_bohr
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 32(%edx,%ebx)
	movl	-44(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_ang_to_bohr
L1643:
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 36(%edx,%ebx)
	movl	_GeomXYZ, %ebx
	movl	$LC126, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 24(%edx,%ebx)
	movl	_GeomXYZ, %ebx
	movl	$LC83, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 40(%edx,%ebx)
	movl	-64(%ebp), %eax
	testb	$16, 12(%eax)
	jne	L1620
	movl	_NcentersXYZ, %eax
	cmpl	%edi, %eax
	jle	L1620
L1627:
	addl	$48, -68(%ebp)
	incl	%edi
	cmpl	%edi, %eax
	jle	L1620
	movl	-64(%ebp), %edx
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	_fgets
	testl	%eax, %eax
	je	L1649
	movl	-44(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC258, %eax
	movl	%eax, 4(%esp)
	movl	-60(%ebp), %edx
	movl	%edx, (%esp)
	call	_sscanf
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_delete_first_spaces
	movl	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	_delete_last_spaces
	movl	-56(%ebp), %ebx
	movsbl	(%ebx),%eax
	movl	%eax, (%esp)
	call	_toupper
	movb	%al, (%ebx)
	movl	-56(%ebp), %esi
	movl	%esi, (%esp)
	call	_strlen
	cmpl	$2, %eax
	je	L1650
L1624:
	movl	_GeomXYZ, %ebx
	movl	-68(%ebp), %eax
	movl	$10, (%eax,%ebx)
	movl	%esi, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 4(%edx,%ebx)
	movl	-56(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 8(%edx,%ebx)
	movl	-56(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 12(%edx,%ebx)
	movl	-56(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 16(%edx,%ebx)
	xorl	%eax, %eax
	cmpl	$1, _Units
	movl	_GeomXYZ, %ebx
	movl	%eax, 20(%edx,%ebx)
	jne	L1625
	movl	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 28(%edx,%ebx)
	movl	-48(%ebp), %eax
	movl	_GeomXYZ, %ebx
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-68(%ebp), %edx
	movl	%eax, 32(%edx,%ebx)
	movl	-44(%ebp), %eax
	movl	_GeomXYZ, %ebx
	jmp	L1643
L1649:
	leal	-1(%edi), %eax
	cmpl	_NcentersXYZ, %eax
	je	L1620
	movl	%eax, _NcentersXYZ
	.p2align 4,,15
L1620:
	movl	-64(%ebp), %edx
	movl	%edx, (%esp)
	call	_fclose
L1610:
	movl	-60(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_free
	xorl	%eax, %eax
	call	_calculMMTypes
	.p2align 4,,15
L1631:
	movl	-56(%ebp,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_g_free
	cmpl	$4, %ebx
	jbe	L1631
	movl	_GeomIsOpen, %eax
	testl	%eax, %eax
	jne	L1651
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	je	L1652
L1642:
	call	_rafresh_drawing
L1605:
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1651:
	movl	$44, (%esp)
	call	_create_geomXYZ_interface
L1644:
	movl	_ZoneDessin, %eax
	testl	%eax, %eax
	jne	L1642
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1648:
	movl	%eax, (%esp)
	call	_freeVariablesXYZ
	jmp	L1614
L1647:
	call	_freeGeomXYZ
	jmp	L1613
L1652:
	call	_create_window_drawing
	jmp	L1644
L1650:
	movsbl	1(%esi),%eax
	movl	%eax, (%esp)
	call	_tolower
	movb	%al, 1(%esi)
	movl	-56(%ebp), %esi
	jmp	L1624
L1646:
	movl	$LC257, (%esp)
	movl	$1, %eax
	movl	$LC75, %edi
	movl	%eax, 8(%esp)
	movl	%edi, 4(%esp)
	call	_MessageGeom
	jmp	L1605
	.p2align 4,,15
	.def	_conversion_to_xyz_and_read;	.scl	3;	.type	32;	.endef
_conversion_to_xyz_and_read:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$LC212, %edi
	pushl	%esi
	movl	$LC212, %esi
	pushl	%ebx
	subl	$172, %esp
	movl	12(%ebp), %ebx
	call	_gabedit_directory
	movl	%eax, 4(%esp)
	movl	$LC212, %ecx
	movl	$LC212, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	$LC213, (%esp)
	call	_g_strdup_printf
	movl	%eax, -144(%ebp)
	call	_gabedit_directory
	movl	%eax, 4(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$LC214, (%esp)
	call	_g_strdup_printf
	movl	%eax, -148(%ebp)
	call	_gabedit_directory
	movl	%eax, 4(%esp)
	movl	$LC212, %ecx
	movl	$LC212, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	$LC215, (%esp)
	call	_g_strdup_printf
	movl	%eax, -152(%ebp)
	movl	LC216, %eax
	movl	%ebx, (%esp)
	movl	%eax, -140(%ebp)
	call	_this_is_an_object
	testl	%eax, %eax
	jne	L1663
L1653:
	addl	$172, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L1663:
	movl	%ebx, (%esp)
	movl	$80, %edi
	movl	$LC217, %esi
	movl	%edi, 4(%esp)
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
	movl	$LC218, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%esi, (%esp)
	movl	%eax, %edi
	call	_this_is_an_object
	testl	%eax, %eax
	je	L1653
	movl	%edi, (%esp)
	call	_this_is_an_object
	testl	%eax, %eax
	je	L1653
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%ebx, 4(%esp)
	movl	%eax, %esi
	movl	%edi, (%esp)
	leal	-136(%ebp), %edi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%edi, 8(%esp)
	movl	%eax, %ebx
	movl	$LC81, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_sscanf
	movl	%ebx, (%esp)
	movl	$LC219, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1657
	movl	%esi, 8(%esp)
	movl	-152(%ebp), %eax
	movl	$LC206, (%esp)
	movl	%eax, 12(%esp)
	movl	_babelCommand, %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
L1662:
	movl	%eax, %edi
	movl	-144(%ebp), %eax
	xorl	%esi, %esi
	movl	%eax, (%esp)
	call	_unlink
	movl	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	_unlink
	movl	%edi, 8(%esp)
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	movl	-148(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_run_local_command
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_cat_file
	movl	%esi, 4(%esp)
	movl	%eax, %ebx
	movl	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	_cat_file
	testl	%ebx, %ebx
	movl	%eax, %esi
	je	L1659
	movl	%ebx, (%esp)
	movl	$1, %ecx
	movl	$LC221, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_Message
	movl	%ebx, (%esp)
	call	_g_free
L1659:
	testl	%esi, %esi
	je	L1660
	movl	%esi, (%esp)
	movl	$1, %eax
	movl	%eax, 8(%esp)
	movl	$LC95, %eax
	movl	%eax, 4(%esp)
	call	_Message
	movl	%esi, (%esp)
	call	_g_free
L1661:
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_unlink
	movl	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	_unlink
	movl	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	_unlink
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	movl	%edi, (%esp)
	call	_g_free
	movl	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_free
	jmp	L1653
L1657:
	movl	%esi, 12(%esp)
	movl	-152(%ebp), %eax
	movl	%edi, 8(%esp)
	movl	$LC220, (%esp)
	movl	%eax, 20(%esp)
	leal	-140(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	_babelCommand, %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	jmp	L1662
L1660:
	movl	$10, %eax
	movl	%eax, _MethodeGeom
	movl	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	_read_XYZ_file_no_add_list
	jmp	L1661
	.p2align 4,,15
.globl _create_babel_read_dialogue
	.def	_create_babel_read_dialogue;	.scl	2;	.type	32;	.endef
_create_babel_read_dialogue:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$32, %esp
	movl	$1, (%esp)
	call	_create_babel_read_save_dialogue
	movl	%eax, (%esp)
	movl	$80, %ecx
	movl	%eax, %ebx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC222, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%ebx, (%esp)
	movl	%eax, %esi
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$_conversion_to_xyz_and_read, %ecx
	movl	%edx, 16(%esp)
	movl	$LC136, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%esi, 12(%esp)
	call	_g_signal_connect_data
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, (%esp)
	movl	%eax, %esi
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	$LC136, %ebx
	call	_g_type_check_instance_cast
	movl	%esi, 12(%esp)
	movl	$2, %ecx
	xorl	%edx, %edx
	movl	%ebx, 4(%esp)
	movl	$_delete_child, %esi
	movl	%esi, 8(%esp)
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	addl	$32, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC259:
	.ascii "%s.top\0"
LC260:
	.ascii "[ atoms ]\0"
	.text
	.p2align 4,,15
.globl _read_charges_from_gromacs_topology_file
	.def	_read_charges_from_gromacs_topology_file;	.scl	2;	.type	32;	.endef
_read_charges_from_gromacs_topology_file:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_get_suffix_name_file
	movl	%eax, 4(%esp)
	movl	$LC259, (%esp)
	call	_g_strdup_printf
	movl	%eax, %ebx
	movl	$LC201, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_FOpen
	testl	%ebx, %ebx
	movl	%eax, %edi
	je	L1666
	movl	%ebx, (%esp)
	call	_g_free
L1666:
	testl	%edi, %edi
	je	L1665
	movl	$1024, (%esp)
	call	_g_malloc
	movl	%eax, -16(%ebp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_fseek
	.p2align 4,,15
L1697:
	movl	12(%edi), %eax
	testb	$16, %al
	jne	L1669
	movl	%edi, 8(%esp)
	movl	$1024, %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fgets
	testl	%eax, %eax
	je	L1693
	movl	$LC260, %esi
	movl	%esi, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_strstr
	testl	%eax, %eax
	je	L1697
L1693:
	movl	12(%edi), %eax
	.p2align 4,,15
L1669:
	movl	$-1, -20(%ebp)
	testb	$16, %al
	je	L1698
L1674:
	movl	%edi, 8(%ebp)
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_fclose
L1665:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1698:
	movl	$-48, -24(%ebp)
	.p2align 4,,15
L1688:
	movl	%edi, 8(%esp)
	movl	$1024, %ebx
	movl	%ebx, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fgets
	testl	%eax, %eax
	je	L1674
	movl	-16(%ebp), %edx
	cmpb	$59, (%edx)
	je	L1673
	movl	%edx, (%esp)
	movl	$91, %ecx
	movl	%ecx, 4(%esp)
	call	_strchr
	testl	%eax, %eax
	jne	L1674
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_gab_split
	movl	%eax, %esi
	xorl	%eax, %eax
	testl	%esi, %esi
	jne	L1684
	jmp	L1686
	.p2align 4,,7
L1681:
	incl	%eax
	cmpl	$7, %eax
	jg	L1678
L1684:
	movl	(%esi,%eax,4), %edx
	testl	%edx, %edx
	je	L1678
	cmpl	$6, %eax
	jne	L1681
	movl	24(%esi), %ebx
	testl	%ebx, %ebx
	je	L1681
L1694:
	incl	-20(%ebp)
	movl	24(%esi), %eax
	movl	_GeomXYZ, %ebx
	addl	$48, -24(%ebp)
	movl	%eax, (%esp)
	call	_g_strdup
	movl	-24(%ebp), %edx
	movl	%eax, 24(%edx,%ebx)
	.p2align 4,,15
L1685:
	testl	%esi, %esi
	je	L1686
	movl	%esi, (%esp)
	call	_g_strfreev
L1686:
	movl	-20(%ebp), %eax
	cmpl	_NcentersXYZ, %eax
	jae	L1674
L1673:
	testb	$16, 12(%edi)
	je	L1688
	movl	%edi, 8(%ebp)
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_fclose
	.p2align 4,,7
L1678:
	cmpl	$6, %eax
	jne	L1685
	jmp	L1694
	.p2align 4,,15
	.def	_read_atom_pdb_file;	.scl	3;	.type	32;	.endef
_read_atom_pdb_file:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	%eax, %edi
	pushl	%esi
	movl	%edx, %esi
	pushl	%ebx
	subl	$12, %esp
	movl	%eax, (%esp)
	call	_strlen
	xorl	%edx, %edx
	cmpl	$53, %eax
	jbe	L1699
	xorl	%ebx, %ebx
	.p2align 4,,15
L1704:
	movzbl	12(%edi,%ebx), %eax
	movl	(%esi), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
	cmpl	$3, %ebx
	jle	L1704
	movl	(%esi), %eax
	movb	$0, 4(%eax)
	movl	(%esi), %eax
	movsbl	(%eax),%edx
	movl	__imp____mb_cur_max, %eax
	cmpl	$1, (%eax)
	jne	L1706
	movl	__imp___pctype, %eax
	movl	(%eax), %eax
	movzwl	(%eax,%edx,2), %eax
	andl	$4, %eax
L1708:
	testl	%eax, %eax
	je	L1705
	movl	(%esi), %edx
	xorl	%ebx, %ebx
	movzbl	1(%edx,%ebx), %eax
	movzbl	(%edx), %ecx
	movb	%al, (%ebx,%edx)
	incl	%ebx
	cmpl	$2, %ebx
	jg	L1772
L1770:
	movl	(%esi), %edx
	movzbl	1(%edx,%ebx), %eax
	movb	%al, (%ebx,%edx)
	incl	%ebx
	cmpl	$2, %ebx
	jle	L1770
L1772:
	movl	(%esi), %eax
	movb	%cl, 3(%eax)
L1705:
	xorl	%ebx, %ebx
	.p2align 4,,15
L1716:
	movzbl	16(%edi,%ebx), %eax
	movl	4(%esi), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
	cmpl	$3, %ebx
	jle	L1716
	movl	4(%esi), %eax
	xorl	%ebx, %ebx
	movb	$0, 4(%eax)
	.p2align 4,,15
L1720:
	movzbl	22(%edi,%ebx), %eax
	movl	8(%esi), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
	cmpl	$3, %ebx
	jle	L1720
	movl	8(%esi), %eax
	xorl	%ebx, %ebx
	movb	$0, 4(%eax)
	.p2align 4,,15
L1724:
	movzbl	30(%edi,%ebx), %eax
	movl	12(%esi), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
	cmpl	$7, %ebx
	jle	L1724
	movl	12(%esi), %eax
	xorl	%ebx, %ebx
	movb	$0, 8(%eax)
	.p2align 4,,15
L1728:
	movzbl	38(%edi,%ebx), %eax
	movl	16(%esi), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
	cmpl	$7, %ebx
	jle	L1728
	movl	16(%esi), %eax
	xorl	%ebx, %ebx
	movb	$0, 8(%eax)
	.p2align 4,,15
L1732:
	movzbl	46(%edi,%ebx), %eax
	movl	20(%esi), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
	cmpl	$7, %ebx
	jle	L1732
	movl	20(%esi), %eax
	movb	$0, 8(%eax)
	movl	%edi, (%esp)
	call	_strlen
	cmpl	$77, %eax
	jbe	L1733
	xorl	%ebx, %ebx
L1737:
	movzbl	76(%edi,%ebx), %eax
	movl	24(%esi), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
	cmpl	$1, %ebx
	jle	L1737
	movl	24(%esi), %eax
	movb	$0, 2(%eax)
	movl	24(%esi), %eax
	cmpb	$32, 1(%eax)
	je	L1773
L1738:
	cmpb	$32, (%eax)
	je	L1771
L1740:
	movl	%edi, (%esp)
	xorl	%ebx, %ebx
	call	_strlen
	cmpl	$79, %eax
	ja	L1742
	movl	28(%esi), %eax
	movb	$0, (%eax)
L1747:
	xorl	%ebx, %ebx
	.p2align 4,,15
L1751:
	movl	(%esi,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_delete_last_spaces
	movl	(%esi,%ebx,4), %eax
	incl	%ebx
	movl	%eax, (%esp)
	call	_delete_first_spaces
	cmpl	$7, %ebx
	jle	L1751
	movl	$1, %edx
L1699:
	addl	$12, %esp
	movl	%edx, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L1706:
	movl	%edx, (%esp)
	movl	$4, %eax
	movl	%eax, 4(%esp)
	call	__isctype
	jmp	L1708
	.p2align 4,,7
L1745:
	movzbl	78(%edi,%ebx), %eax
	movl	28(%esi), %edx
	movb	%al, (%ebx,%edx)
	incl	%ebx
L1742:
	movl	%edi, (%esp)
	call	_strlen
	movl	%eax, %edx
	leal	-78(%eax), %eax
	cmpl	%ebx, %eax
	jg	L1745
	movl	28(%esi), %eax
	movb	$0, -78(%eax,%edx)
	movl	%edi, (%esp)
	call	_strlen
	movl	28(%esi), %edx
	cmpb	$10, -79(%edx,%eax)
	jne	L1747
	movb	$0, -79(%edx,%eax)
	jmp	L1747
L1733:
	movl	24(%esi), %eax
L1771:
	movb	$0, (%eax)
	jmp	L1740
L1773:
	movb	$0, 1(%eax)
	movl	24(%esi), %eax
	jmp	L1738
	.p2align 4,,15
.globl _get_connections_one_connect_pdb
	.def	_get_connections_one_connect_pdb;	.scl	2;	.type	32;	.endef
_get_connections_one_connect_pdb:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%esi, -8(%ebp)
	movl	8(%ebp), %eax
	movl	%edi, -4(%ebp)
	xorl	%edi, %edi
	movl	%ebx, -12(%ebp)
	movl	%eax, (%esp)
	call	_gab_split
	testl	%eax, %eax
	movl	%eax, %esi
	je	L1780
	movl	(%eax), %edx
	testl	%edx, %edx
	je	L1780
	.p2align 4,,15
L1777:
	incl	%edi
	movl	(%esi,%edi,4), %eax
	testl	%eax, %eax
	jne	L1777
	cmpl	$2, %edi
	jg	L1799
L1780:
	movl	%esi, (%esp)
	call	_g_strfreev
	xorl	%eax, %eax
L1774:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L1799:
	movl	4(%esi), %eax
	movl	%eax, (%esp)
	call	_atoi
	decl	%eax
	movl	%eax, -16(%ebp)
	js	L1780
	movl	_NcentersXYZ, %edx
	leal	-1(%edx), %eax
	cmpl	%eax, -16(%ebp)
	ja	L1780
	movl	-16(%ebp), %eax
	movl	_GeomXYZ, %ebx
	leal	(%eax,%eax,2), %eax
	sall	$4, %eax
	movl	%eax, -20(%ebp)
	leal	0(,%edx,4), %eax
	movl	%eax, (%esp)
	call	_g_malloc
	movl	-20(%ebp), %edx
	movl	%eax, 44(%edx,%ebx)
	xorl	%ebx, %ebx
	cmpl	_NcentersXYZ, %ebx
	jae	L1794
	movl	_GeomXYZ, %eax
	movl	44(%edx,%eax), %eax
L1784:
	movl	$0, (%eax,%ebx,4)
	incl	%ebx
	cmpl	_NcentersXYZ, %ebx
	jb	L1784
L1794:
	subl	$2, %edi
	xorl	%ebx, %ebx
	cmpl	$0, %edi
	movl	%edi, -24(%ebp)
	jle	L1786
	movl	-16(%ebp), %eax
	leal	(%eax,%eax,2), %edi
	sall	$4, %edi
L1791:
	movl	8(%esi,%ebx,4), %eax
	testl	%eax, %eax
	je	L1786
	movl	%eax, (%esp)
	call	_atoi
	movl	%eax, %edx
	decl	%edx
	js	L1787
	movl	_NcentersXYZ, %eax
	decl	%eax
	cmpl	%eax, %edx
	ja	L1787
	movl	_GeomXYZ, %eax
	movl	44(%edi,%eax), %eax
	movl	$1, (%eax,%edx,4)
L1787:
	incl	%ebx
	cmpl	%ebx, -24(%ebp)
	jg	L1791
L1786:
	movl	%esi, (%esp)
	call	_g_strfreev
	movl	$1, %eax
	jmp	L1774
