	.file	"GabeditContoursPlot.c"
.lcomm _parent_class,16
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "  <popup name=\"MenuContoursPlot\">\12    <separator name=\"sepMenuPopSet\" />\12    <menu name=\"Set\" action=\"Set\">\12      <menuitem name=\"SetTicks\" action=\"SetTicks\" />\12      <menuitem name=\"SetRanges\" action=\"SetRanges\" />\12      <menuitem name=\"SetLabels\" action=\"SetLabels\" />\12      <menuitem name=\"SetDigits\" action=\"SetDigits\" />\12      <menuitem name=\"SetFontSize\" action=\"SetFontSize\" />\12      <separator name=\"sepSetAutoRanges\" />\12      <menuitem name=\"SetAutoRanges\" action=\"SetAutoRanges\" />\12    </menu>\12    <separator name=\"sepRender\" />\12    <menu name=\"Render\" action=\"Render\">\12      <menu name=\"RenderGrid\" action=\"RenderGrid\">\12        <menuitem name=\"HGridShowMajor\" action=\"HGridShowMajor\" />\12        <menuitem name=\"HGridShowMinor\" action=\"HGridShowMinor\" />\12        <menuitem name=\"VGridShowMajor\" action=\"VGridShowMajor\" />\12        <menuitem name=\"VGridShowMinor\" action=\"VGridShowMinor\" />\12      </menu>\12      <menu name=\"RenderLegends\" action=\"RenderLegends\">\12        <menuitem name=\"LegendShowLeft\" action=\"LegendShowLeft\" />\12        <menuitem name=\"LegendShowRight\" action=\"LegendShowRight\" />\12        <menuitem name=\"LegendShowTop\" action=\"LegendShowTop\" />\12        <menuitem name=\"LegendShowBottom\" action=\"LegendShowBottom\" />\12      </menu>\12      <menu name=\"RenderDirections\" action=\"RenderDirections\">\12        <menuitem name=\"DirectionReflectX\" action=\"DirectionReflectX\" />\12        <menuitem name=\"DirectionReflectY\" action=\"DirectionReflectY\" />\12      </menu>\12        <separator name=\"sepColorMap\" />\12        <menuitem name=\"ShowColorMap\" action=\"ShowColorMap\" />\12    </menu>\12    <separator name=\"sepData\" />\12    <menu name=\"Data\" action=\"Data\">\12      <menu name=\"DataAdd\" action=\"DataAdd\">\12        <menuitem name=\"DataRead\" action=\"DataRead\" />\12      </menu>\12        <separator name=\"sepDataSaveAll\" />\12        <menuitem name=\"DataSaveAll\" action=\"DataSaveAll\" />\12        <separator name=\"sepDataRemoveAll\" />\12        <menuitem name=\"DataRemoveAll\" action=\"DataRemoveAll\" />\12    <"
	.ascii "/menu>\12    <separator name=\"sepContours\" />\12    <menu name=\"Contours\" action=\"Contours\">\12      <menuitem name=\"ContoursSet\" action=\"ContoursSet\" />\12      <menuitem name=\"ContoursDelete\" action=\"ContoursDelete\" />\12    </menu>\12    <separator name=\"sepColorMaps\" />\12    <menu name=\"ColorMap\" action=\"ColorMap\">\12      <menuitem name=\"ColorMapSet\" action=\"ColorMapSet\" />\12    </menu>\12    <separator name=\"sepScreenCapture\" />\12    <menu name=\"ScreenCapture\" action=\"ScreenCapture\">\12      <menuitem name=\"ScreenCaptureBMP\" action=\"ScreenCaptureBMP\" />\12      <menuitem name=\"ScreenCaptureJPEG\" action=\"ScreenCaptureJPEG\" />\12      <menuitem name=\"ScreenCapturePNG\" action=\"ScreenCapturePNG\" />\12      <menuitem name=\"ScreenCaptureTPNG\" action=\"ScreenCaptureTPNG\" />\12      <menuitem name=\"ScreenCaptureTIF\" action=\"ScreenCaptureTIF\" />\12      <menuitem name=\"ScreenCaptureClipBoard\" action=\"ScreenCaptureClipBoard\" />\12    </menu>\12    <separator name=\"sepExport\" />\12    <menu name=\"Export\" action=\"Export\">\12      <menuitem name=\"ExportSVG\" action=\"ExportSVG\" />\12      <menuitem name=\"ExportPDF\" action=\"ExportPDF\" />\12      <menuitem name=\"ExportPS\" action=\"ExportPS\" />\12      <menuitem name=\"ExportEPS\" action=\"ExportEPS\" />\12    </menu>\12    <separator name=\"sepHelp\" />\12      <menuitem name=\"Help\" action=\"Help\" />\12    <separator name=\"sepClose\" />\12      <menuitem name=\"Close\" action=\"Close\" />\12  </popup>\12  <toolbar action=\"ToolbarContoursPlot\">\12      <toolitem name=\"SetTicks\" action=\"SetTicks\" />\12      <toolitem name=\"SetRanges\" action=\"SetRanges\" />\12      <toolitem name=\"ContoursSet\" action=\"ContoursSet\" />\12      <toolitem name=\"ColorMapSet\" action=\"ColorMapSet\" />\12      <toolitem name=\"ScreenCaptureBMP\" action=\"ScreenCaptureBMP\" />\12      <toolitem name=\"ScreenCaptureJPEG\" action=\"ScreenCaptureJPEG\" />\12      <toolitem name=\"ScreenCapturePNG\" action=\"ScreenCapturePNG\" />\12      <toolitem name=\"ScreenCaptureTPNG\" action=\"ScreenCaptureTPNG\" />\12      <toolitem name=\"ScreenCaptureTIF\" action=\"ScreenCaptu"
	.ascii "reTIF\" />\12      <toolitem name=\"ScreenCaptureClipBoard\" action=\"ScreenCaptureClipBoard\" />\12  </toolbar>\12\0"
	.data
	.align 4
_uiMenuInfo:
	.long	LC0
	.align 4
_numberOfGtkActionToggleEntries:
	.long	11
	.section .rdata,"dr"
LC1:
	.ascii "HGridShowMajor\0"
LC2:
	.ascii "show _H major\0"
LC3:
	.ascii "show H major\0"
LC4:
	.ascii "HGridShowMinor\0"
LC5:
	.ascii "show _H minor\0"
LC6:
	.ascii "show H minor\0"
LC7:
	.ascii "VGridShowMajor\0"
LC8:
	.ascii "show _V major\0"
LC9:
	.ascii "show V major\0"
LC10:
	.ascii "VGridShowMinor\0"
LC11:
	.ascii "show _V minor\0"
LC12:
	.ascii "show V minor\0"
LC13:
	.ascii "LegendShowLeft\0"
LC14:
	.ascii "show _left\0"
LC15:
	.ascii "show left\0"
LC16:
	.ascii "LegendShowRight\0"
LC17:
	.ascii "show _right\0"
LC18:
	.ascii "show right\0"
LC19:
	.ascii "LegendShowTop\0"
LC20:
	.ascii "show _top\0"
LC21:
	.ascii "show top\0"
LC22:
	.ascii "LegendShowBottom\0"
LC23:
	.ascii "show _bottom\0"
LC24:
	.ascii "show bottom\0"
LC25:
	.ascii "DirectionReflectX\0"
LC26:
	.ascii "_X reflect\0"
LC27:
	.ascii "X reflect\0"
LC28:
	.ascii "DirectionReflectY\0"
LC29:
	.ascii "_Y reflect\0"
LC30:
	.ascii "Y reflect\0"
LC31:
	.ascii "ShowColorMap\0"
LC32:
	.ascii "show _colormap\0"
LC33:
	.ascii "show colormap\0"
	.data
	.align 32
_gtkActionToggleEntries:
	.long	LC1
	.long	0
	.long	LC2
	.long	0
	.long	LC3
	.long	_toggle_action
	.long	1
	.long	LC4
	.long	0
	.long	LC5
	.long	0
	.long	LC6
	.long	_toggle_action
	.long	0
	.long	LC7
	.long	0
	.long	LC8
	.long	0
	.long	LC9
	.long	_toggle_action
	.long	1
	.long	LC10
	.long	0
	.long	LC11
	.long	0
	.long	LC12
	.long	_toggle_action
	.long	0
	.long	LC13
	.long	0
	.long	LC14
	.long	0
	.long	LC15
	.long	_toggle_action
	.long	1
	.long	LC16
	.long	0
	.long	LC17
	.long	0
	.long	LC18
	.long	_toggle_action
	.long	1
	.long	LC19
	.long	0
	.long	LC20
	.long	0
	.long	LC21
	.long	_toggle_action
	.long	1
	.long	LC22
	.long	0
	.long	LC23
	.long	0
	.long	LC24
	.long	_toggle_action
	.long	1
	.long	LC25
	.long	0
	.long	LC26
	.long	0
	.long	LC27
	.long	_toggle_action
	.long	0
	.long	LC28
	.long	0
	.long	LC29
	.long	0
	.long	LC30
	.long	_toggle_action
	.long	0
	.long	LC31
	.long	0
	.long	LC32
	.long	0
	.long	LC33
	.long	_toggle_action
	.long	0
	.align 4
_numberOfGtkActionEntries:
	.long	35
	.section .rdata,"dr"
LC34:
	.ascii "Set\0"
LC35:
	.ascii "_Set\0"
LC36:
	.ascii "SetTicks\0"
LC37:
	.ascii "_Ticks\0"
LC38:
	.ascii "Ticks\0"
LC39:
	.ascii "SetRanges\0"
LC40:
	.ascii "_Ranges\0"
LC41:
	.ascii "Ranges\0"
LC42:
	.ascii "SetLabels\0"
LC43:
	.ascii "_Labels\0"
LC44:
	.ascii "Labels\0"
LC45:
	.ascii "SetDigits\0"
LC46:
	.ascii "_Digits\0"
LC47:
	.ascii "Digits\0"
LC48:
	.ascii "SetFontSize\0"
LC49:
	.ascii "_Font size\0"
LC50:
	.ascii "Font size\0"
LC51:
	.ascii "SetAutoRanges\0"
LC52:
	.ascii "_Auto ranges\0"
LC53:
	.ascii "Auto ranges\0"
LC54:
	.ascii "Render\0"
LC55:
	.ascii "_Render\0"
LC56:
	.ascii "RenderGrid\0"
LC57:
	.ascii "_Grid\0"
LC58:
	.ascii "RenderLegends\0"
LC59:
	.ascii "_Legends\0"
LC60:
	.ascii "RenderDirections\0"
LC61:
	.ascii "_Directions\0"
LC62:
	.ascii "Data\0"
LC63:
	.ascii "_Data\0"
LC64:
	.ascii "DataAdd\0"
LC65:
	.ascii "_Add Data\0"
LC66:
	.ascii "DataRead\0"
	.align 4
LC67:
	.ascii "_Read data from an ASCII Contours file\0"
	.align 4
LC68:
	.ascii "Read data from an ASCII Contours file\0"
LC69:
	.ascii "DataSaveAll\0"
	.align 4
LC70:
	.ascii "_Save all data in an ascii Contours file\0"
	.align 4
LC71:
	.ascii "Save all data in an ascii file\0"
LC72:
	.ascii "DataRemoveAll\0"
LC73:
	.ascii "_Remove all data\0"
LC74:
	.ascii "Remove all data\0"
LC75:
	.ascii "Contours\0"
LC76:
	.ascii "_Contours\0"
LC77:
	.ascii "ContoursSet\0"
LC78:
	.ascii "_Set contours values\0"
LC79:
	.ascii "Set contours values\0"
LC80:
	.ascii "ContoursDelete\0"
LC81:
	.ascii "_Delete all\0"
LC82:
	.ascii "Delete all\0"
LC83:
	.ascii "ColorMap\0"
LC84:
	.ascii "Color_Map\0"
LC85:
	.ascii "ColorMapSet\0"
LC86:
	.ascii "_Set colors map\0"
LC87:
	.ascii "Set colors map\0"
LC88:
	.ascii "ScreenCapture\0"
LC89:
	.ascii "_Screen Capture\0"
LC90:
	.ascii "ScreenCaptureBMP\0"
LC91:
	.ascii "_BMP format\0"
LC92:
	.ascii "BMP format\0"
LC93:
	.ascii "ScreenCaptureJPEG\0"
LC94:
	.ascii "_JPEG format\0"
LC95:
	.ascii "JPEG format\0"
LC96:
	.ascii "ScreenCapturePNG\0"
LC97:
	.ascii "_PNG format\0"
LC98:
	.ascii "PNG format\0"
LC99:
	.ascii "ScreenCaptureTPNG\0"
LC100:
	.ascii "_Transparent PNG format\0"
LC101:
	.ascii "Transparent PNG format\0"
LC102:
	.ascii "ScreenCaptureTIF\0"
LC103:
	.ascii "_TIF format\0"
LC104:
	.ascii "TIF format\0"
LC105:
	.ascii "ScreenCaptureClipBoard\0"
LC106:
	.ascii "_Copy to clipboard\0"
LC107:
	.ascii "Copy to clipboard\0"
LC108:
	.ascii "Export\0"
LC109:
	.ascii "_Export\0"
LC110:
	.ascii "ExportSVG\0"
LC111:
	.ascii "Export _SVG format\0"
LC112:
	.ascii "SVG format\0"
LC113:
	.ascii "ExportPDF\0"
LC114:
	.ascii "Export p_df format\0"
LC115:
	.ascii "PDF format\0"
LC116:
	.ascii "ExportPS\0"
LC117:
	.ascii "Export _postscript format\0"
LC118:
	.ascii "PS format\0"
LC119:
	.ascii "ExportEPS\0"
	.align 4
LC120:
	.ascii "Export _Encapsuled postscript format\0"
LC121:
	.ascii "EPS format\0"
LC122:
	.ascii "Help\0"
LC123:
	.ascii "gtk-help\0"
LC124:
	.ascii "_Help\0"
LC125:
	.ascii "Close\0"
LC126:
	.ascii "gtk-close\0"
LC127:
	.ascii "_Close\0"
	.data
	.align 32
_gtkActionEntries:
	.long	LC34
	.long	0
	.long	LC35
	.space 12
	.long	LC36
	.long	0
	.long	LC37
	.long	0
	.long	LC38
	.long	_activate_action
	.long	LC39
	.long	0
	.long	LC40
	.long	0
	.long	LC41
	.long	_activate_action
	.long	LC42
	.long	0
	.long	LC43
	.long	0
	.long	LC44
	.long	_activate_action
	.long	LC45
	.long	0
	.long	LC46
	.long	0
	.long	LC47
	.long	_activate_action
	.long	LC48
	.long	0
	.long	LC49
	.long	0
	.long	LC50
	.long	_activate_action
	.long	LC51
	.long	0
	.long	LC52
	.long	0
	.long	LC53
	.long	_activate_action
	.long	LC54
	.long	0
	.long	LC55
	.space 12
	.long	LC56
	.long	0
	.long	LC57
	.space 12
	.long	LC58
	.long	0
	.long	LC59
	.space 12
	.long	LC60
	.long	0
	.long	LC61
	.space 12
	.long	LC62
	.long	0
	.long	LC63
	.space 12
	.long	LC64
	.long	0
	.long	LC65
	.space 12
	.long	LC66
	.long	0
	.long	LC67
	.long	0
	.long	LC68
	.long	_activate_action
	.long	LC69
	.long	0
	.long	LC70
	.long	0
	.long	LC71
	.long	_activate_action
	.long	LC72
	.long	0
	.long	LC73
	.long	0
	.long	LC74
	.long	_activate_action
	.long	LC75
	.long	0
	.long	LC76
	.space 12
	.long	LC77
	.long	0
	.long	LC78
	.long	0
	.long	LC79
	.long	_activate_action
	.long	LC80
	.long	0
	.long	LC81
	.long	0
	.long	LC82
	.long	_activate_action
	.long	LC83
	.long	0
	.long	LC84
	.space 12
	.long	LC85
	.long	0
	.long	LC86
	.long	0
	.long	LC87
	.long	_activate_action
	.long	LC88
	.long	0
	.long	LC89
	.space 12
	.long	LC90
	.long	0
	.long	LC91
	.long	0
	.long	LC92
	.long	_activate_action
	.long	LC93
	.long	0
	.long	LC94
	.long	0
	.long	LC95
	.long	_activate_action
	.long	LC96
	.long	0
	.long	LC97
	.long	0
	.long	LC98
	.long	_activate_action
	.long	LC99
	.long	0
	.long	LC100
	.long	0
	.long	LC101
	.long	_activate_action
	.long	LC102
	.long	0
	.long	LC103
	.long	0
	.long	LC104
	.long	_activate_action
	.long	LC105
	.long	0
	.long	LC106
	.long	0
	.long	LC107
	.long	_activate_action
	.long	LC108
	.long	0
	.long	LC109
	.space 12
	.long	LC110
	.long	0
	.long	LC111
	.long	0
	.long	LC112
	.long	_activate_action
	.long	LC113
	.long	0
	.long	LC114
	.long	0
	.long	LC115
	.long	_activate_action
	.long	LC116
	.long	0
	.long	LC117
	.long	0
	.long	LC118
	.long	_activate_action
	.long	LC119
	.long	0
	.long	LC120
	.long	0
	.long	LC121
	.long	_activate_action
	.long	LC122
	.long	LC123
	.long	LC124
	.long	0
	.long	LC122
	.long	_activate_action
	.long	LC125
	.long	LC126
	.long	LC127
	.long	0
	.long	LC125
	.long	_activate_action
	.text
	.p2align 4,,15
	.def	_colormap_free;	.scl	3;	.type	32;	.endef
_colormap_free:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$4, %esp
	testl	%eax, %eax
	movl	%eax, %ebx
	je	L1
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	L6
L4:
	movl	$0, (%ebx)
L1:
	popl	%eax
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L6:
	movl	%eax, (%esp)
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
	movl	-12(%ebp), %edx
	movl	%eax, %ebx
	movl	$0, -16(%ebp)
	testl	%edx, %edx
	jne	L17
L8:
	movl	$1, -16(%ebp)
	movl	$32, (%esp)
	call	_g_malloc
	movl	%eax, -12(%ebp)
	xorl	%edx, %edx
	.p2align 4,,15
L14:
	fldl	(%ebx,%edx,8)
	fstpl	(%eax,%edx,8)
	incl	%edx
	cmpl	$2, %edx
	jle	L14
	fldl	8(%ebp)
	movl	-12(%ebp), %edx
	fstpl	24(%eax)
	movl	-16(%ebp), %eax
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
L17:
	leal	-16(%ebp), %eax
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
	subl	$12, %esp
	movl	%eax, -16(%ebp)
	movl	(%eax), %eax
	movl	%edx, -20(%ebp)
	sall	$5, %eax
	addl	$32, %eax
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
	sall	$5, %eax
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
	movl	16(%eax,%ecx), %edx
	movl	%edx, 16(%eax,%ebx)
	movl	20(%eax,%ecx), %edx
	movl	%edx, 20(%eax,%ebx)
	movl	24(%eax,%ecx), %edx
	movl	%edx, 24(%eax,%ebx)
	movl	28(%eax,%ecx), %edx
	movl	%edx, 28(%eax,%ebx)
	jg	L22
L28:
	movl	%edi, %esi
	xorl	%edx, %edx
	sall	$5, %esi
	leal	(%esi,%ebx), %eax
L26:
	movl	-20(%ebp), %edi
	fldl	(%edi,%edx,8)
	incl	%edx
	fstpl	(%eax)
	addl	$8, %eax
	cmpl	$2, %edx
	jle	L26
	fldl	8(%ebp)
	movl	%ecx, (%esp)
	fstpl	24(%esi,%ebx)
	call	_g_free
	movl	-16(%ebp), %eax
	incl	(%eax)
	movl	%ebx, 4(%eax)
	addl	$12, %esp
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
	subl	$60, %esp
	movl	(%eax), %edi
	movl	%eax, -60(%ebp)
	movl	$0, -64(%ebp)
	leal	-1(%edi), %eax
	cmpl	$0, %eax
	jle	L45
	.p2align 4,,15
L51:
	movl	-64(%ebp), %esi
	movl	%esi, %eax
	incl	%eax
	movl	%eax, -68(%ebp)
	cmpl	%eax, %edi
	movl	%eax, %ecx
	jle	L47
	movl	-60(%ebp), %eax
	movl	4(%eax), %ebx
	.p2align 4,,15
L41:
	movl	%esi, %eax
	movl	%ecx, %edx
	sall	$5, %eax
	fldl	24(%eax,%ebx)
	sall	$5, %edx
	fldl	24(%edx,%ebx)
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
	cmpl	-64(%ebp), %esi
	je	L35
	movl	-60(%ebp), %eax
	movl	-64(%ebp), %edx
	movl	4(%eax), %ebx
	sall	$5, %edx
	movl	(%edx,%ebx), %eax
	movl	%eax, -56(%ebp)
	movl	4(%edx,%ebx), %eax
	movl	%eax, -52(%ebp)
	movl	8(%edx,%ebx), %eax
	movl	%eax, -48(%ebp)
	movl	12(%edx,%ebx), %eax
	movl	%eax, -44(%ebp)
	movl	16(%edx,%ebx), %eax
	movl	%eax, -40(%ebp)
	movl	20(%edx,%ebx), %eax
	movl	%eax, -36(%ebp)
	movl	24(%edx,%ebx), %eax
	movl	%eax, -32(%ebp)
	movl	28(%edx,%ebx), %eax
	movl	%eax, -28(%ebp)
	movl	%esi, %eax
	sall	$5, %eax
	movl	(%eax,%ebx), %ecx
	movl	%ecx, (%edx,%ebx)
	movl	4(%eax,%ebx), %ecx
	movl	%ecx, 4(%edx,%ebx)
	movl	8(%eax,%ebx), %ecx
	movl	%ecx, 8(%edx,%ebx)
	movl	12(%eax,%ebx), %ecx
	movl	%ecx, 12(%edx,%ebx)
	movl	16(%eax,%ebx), %ecx
	movl	%ecx, 16(%edx,%ebx)
	movl	20(%eax,%ebx), %ecx
	movl	%ecx, 20(%edx,%ebx)
	movl	24(%eax,%ebx), %ecx
	movl	%ecx, 24(%edx,%ebx)
	movl	28(%eax,%ebx), %ecx
	movl	%ecx, 28(%edx,%ebx)
	movl	-56(%ebp), %edx
	movl	%edx, (%eax,%ebx)
	movl	-52(%ebp), %edx
	movl	%edx, 4(%eax,%ebx)
	movl	-48(%ebp), %edx
	movl	%edx, 8(%eax,%ebx)
	movl	-44(%ebp), %edx
	movl	%edx, 12(%eax,%ebx)
	movl	-40(%ebp), %edx
	movl	%edx, 16(%eax,%ebx)
	movl	-36(%ebp), %edx
	movl	%edx, 20(%eax,%ebx)
	movl	-32(%ebp), %edx
	movl	%edx, 24(%eax,%ebx)
	movl	-28(%ebp), %edx
	movl	%edx, 28(%eax,%ebx)
L35:
	movl	-68(%ebp), %eax
	movl	%eax, -64(%ebp)
	leal	-1(%edi), %eax
	cmpl	-64(%ebp), %eax
	jg	L51
L45:
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_set_Color_From_colorMap;	.scl	3;	.type	32;	.endef
_set_Color_From_colorMap:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	%esi, -8(%ebp)
	movl	%edx, %esi
	movl	%ebx, -12(%ebp)
	movl	%edi, -4(%ebp)
	movl	(%eax), %ecx
	fldl	8(%ebp)
	testl	%ecx, %ecx
	jle	L101
	movl	4(%eax), %edx
	fldl	24(%edx)
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	jb	L58
	fstp	%st(0)
	xorl	%ecx, %ecx
	movl	%edx, %eax
	.p2align 4,,15
L63:
	fldl	(%eax)
	addl	$8, %eax
	fstpl	(%esi,%ecx,8)
	incl	%ecx
	cmpl	$2, %ecx
	jle	L63
L106:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L58:
	leal	-1(%ecx), %ebx
	sall	$5, %ebx
	fldl	24(%ebx,%edx)
	fxch	%st(1)
	fucom	%st(1)
	fnstsw	%ax
	fstp	%st(1)
	sahf
	jae	L102
	leal	-1(%ecx), %eax
	xorl	%edi, %edi
	cmpl	$1, %eax
	movl	$1, %ebx
	jle	L71
	movl	$32, -16(%ebp)
	movl	%eax, %ecx
	.p2align 4,,15
L76:
	movl	-16(%ebp), %eax
	fldl	24(%eax,%edx)
	fxch	%st(1)
	fucom	%st(1)
	fnstsw	%ax
	fstp	%st(1)
	sahf
	jb	L72
	movl	-16(%ebp), %eax
	fldl	56(%eax,%edx)
	fucomp	%st(1)
	fnstsw	%ax
	sahf
	jae	L100
L72:
	addl	$32, -16(%ebp)
	incl	%ebx
	cmpl	%ebx, %ecx
	jg	L76
L71:
	movl	%edi, %eax
	sall	$5, %eax
	leal	(%eax,%edx), %ebx
	fldl	24(%eax,%edx)
	fldl	56(%ebx)
	fxch	%st(2)
	fsub	%st(1), %st
	fxch	%st(2)
	fsubp	%st, %st(1)
	fldz
	fld	%st(1)
	fsub	%st(3), %st
	fxch	%st(2)
	fucom	%st(1)
	fnstsw	%ax
	sahf
	jbe	L104
	fxch	%st(3)
	fucom	%st(1)
	fnstsw	%ax
	sahf
	jb	L104
	fxch	%st(2)
	fucom	%st(1)
	fnstsw	%ax
	fstp	%st(1)
	sahf
	jb	L105
	fxch	%st(1)
	fdiv	%st(2), %st
	fxch	%st(1)
	xorl	%ecx, %ecx
	movl	%ebx, %eax
	fdivp	%st, %st(2)
L84:
	fldl	(%eax)
	fldl	32(%eax)
	fxch	%st(1)
	addl	$8, %eax
	fmul	%st(3), %st
	fxch	%st(1)
	fmul	%st(2), %st
	faddp	%st, %st(1)
	fstpl	(%esi,%ecx,8)
	incl	%ecx
	cmpl	$2, %ecx
	jle	L84
	fstp	%st(0)
	fstp	%st(0)
	jmp	L106
	.p2align 4,,7
L101:
	fstp	%st(0)
	xorl	%ecx, %ecx
L57:
	movl	$0, (%esi,%ecx,8)
	movl	$1071644672, %ebx
	movl	%ebx, 4(%esi,%ecx,8)
	incl	%ecx
	cmpl	$2, %ecx
	jle	L57
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L102:
	fstp	%st(0)
	xorl	%ecx, %ecx
	leal	(%ebx,%edx), %eax
L69:
	fldl	(%eax)
	addl	$8, %eax
	fstpl	(%esi,%ecx,8)
	incl	%ecx
	cmpl	$2, %ecx
	jle	L69
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L104:
	fstp	%st(0)
L105:
	fstp	%st(0)
	fstp	%st(0)
	fstp	%st(0)
	sall	$5, %edi
	xorl	%ecx, %ecx
	leal	(%edi,%edx), %eax
L89:
	fldl	(%eax)
	addl	$8, %eax
	fstpl	(%esi,%ecx,8)
	incl	%ecx
	cmpl	$2, %ecx
	jle	L89
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L100:
	movl	%ebx, %edi
	jmp	L71
	.p2align 4,,15
	.def	_gabedit_contoursplot_cairo_string;	.scl	3;	.type	32;	.endef
_gabedit_contoursplot_cairo_string:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$188, %esp
	movl	24(%edx), %eax
	movl	%edx, -140(%ebp)
	movl	516(%eax), %ebx
	movl	%ebx, (%esp)
	call	_pango_font_description_get_style
	movl	%eax, -144(%ebp)
	xorl	%eax, %eax
	movl	%eax, -148(%ebp)
	movl	%ebx, (%esp)
	call	_pango_font_description_get_family
	movl	%eax, -152(%ebp)
	movl	%ebx, (%esp)
	call	_pango_font_description_get_weight
	movl	%ebx, (%esp)
	movl	%eax, %edi
	movl	$400, %eax
	movl	%eax, -156(%ebp)
	call	_pango_font_description_get_size
	testl	%eax, %eax
	js	L131
L108:
	movl	%esi, (%esp)
	movl	%eax, %ebx
	sarl	$10, %ebx
	call	_cairo_save
	leal	-120(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_gdk_gc_get_values
	movl	-140(%ebp), %edx
	movl	52(%edx), %eax
	movl	%eax, (%esp)
	call	_gdk_drawable_get_colormap
	movl	%eax, (%esp)
	leal	-136(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-120(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gdk_colormap_query_color
	cmpl	$1, -144(%ebp)
	je	L111
	jae	L132
L109:
	cmpl	$600, %edi
	je	L120
	ja	L121
	cmpl	$300, %edi
	je	L116
	jbe	L133
	cmpl	$400, %edi
L129:
	jne	L113
L116:
	movl	$400, %edi
	movl	%edi, -156(%ebp)
	jmp	L113
	.p2align 4,,7
L132:
	cmpl	$2, -144(%ebp)
	jne	L109
	movl	$1, %eax
	jmp	L130
	.p2align 4,,7
L121:
	cmpl	$800, %edi
	je	L120
	jbe	L134
	cmpl	$900, %edi
L128:
	jne	L113
	.p2align 4,,15
L120:
	movl	$1, %ecx
	movl	%ecx, -156(%ebp)
L113:
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	24(%ebp), %edx
	imull	%ebx, %eax
	testl	%edx, %edx
	je	L124
	testl	%eax, %eax
	js	L135
L125:
	sarl	$2, %eax
	subl	%eax, 12(%ebp)
L124:
	movl	28(%ebp), %edi
	testl	%edi, %edi
	je	L126
	testl	%ebx, %ebx
	movl	%ebx, %eax
	js	L136
L127:
	sarl	$2, %eax
	addl	%eax, 16(%ebp)
L126:
	movl	%esi, (%esp)
	movl	-156(%ebp), %edx
	movl	-148(%ebp), %eax
	movl	%edx, 12(%esp)
	movl	-152(%ebp), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	call	_cairo_select_font_face
	movl	%esi, (%esp)
	leal	-136(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gdk_cairo_set_source_color
	pushl	%ebx
	fildl	(%esp)
	addl	$4, %esp
	movl	%esi, (%esp)
	fstpl	4(%esp)
	call	_cairo_set_font_size
	fildl	16(%ebp)
	movl	%esi, (%esp)
	fstpl	12(%esp)
	fildl	12(%ebp)
	fstpl	4(%esp)
	call	_cairo_move_to
	fldl	32(%ebp)
	movl	%esi, (%esp)
	fstpl	4(%esp)
	call	_cairo_rotate
	movl	%esi, (%esp)
	movl	20(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_cairo_show_text
	movl	%esi, (%esp)
	call	_cairo_stroke
	movl	%esi, (%esp)
	call	_cairo_restore
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L111:
	movl	$2, %eax
L130:
	movl	%eax, -148(%ebp)
	jmp	L109
	.p2align 4,,7
L131:
	addl	$1023, %eax
	jmp	L108
	.p2align 4,,7
L134:
	cmpl	$700, %edi
	jmp	L128
	.p2align 4,,7
L133:
	cmpl	$200, %edi
	jmp	L129
	.p2align 4,,7
L136:
	leal	3(%ebx), %eax
	jmp	L127
	.p2align 4,,7
L135:
	addl	$3, %eax
	jmp	L125
	.section .rdata,"dr"
	.align 4
LC136:
	.long	1084227584
	.align 4
LC139:
	.long	1199570688
	.text
	.p2align 4,,15
	.def	_gabedit_contoursplot_cairo_line;	.scl	3;	.type	32;	.endef
_gabedit_contoursplot_cairo_line:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$4, %edi
	pushl	%esi
	pushl	%ebx
	subl	$220, %esp
	movl	%eax, %ebx
	flds	LC136
	xorl	%eax, %eax
	testl	%ebx, %ebx
	movl	%eax, -152(%ebp)
	movl	$1076101120, %eax
	movl	8(%ebp), %esi
	movl	%edx, -172(%ebp)
	fstl	-168(%ebp)
	fstl	-160(%ebp)
	movl	%eax, -148(%ebp)
	fstpl	-144(%ebp)
	je	L137
	testl	%esi, %esi
	je	L137
	movl	%ebx, (%esp)
	call	_cairo_save
	movl	%esi, (%esp)
	leal	-120(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gdk_gc_get_values
	movl	-40(%ebp), %eax
	cmpl	$1, %eax
	je	L145
	jb	L145
	cmpl	$2, %eax
	je	L143
	cmpl	$3, %eax
	je	L144
L145:
	xorl	%eax, %eax
L160:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_cairo_set_line_cap
	movl	-36(%ebp), %eax
	cmpl	$1, %eax
	je	L148
	jb	L150
	cmpl	$2, %eax
	je	L149
L150:
	xorl	%edx, %edx
	movl	%edx, 4(%esp)
L159:
	movl	%ebx, (%esp)
	call	_cairo_set_line_join
	movl	-44(%ebp), %eax
	cmpl	$1, %eax
	je	L153
	jae	L161
L155:
	xorl	%edi, %edi
L151:
	movl	-172(%ebp), %edx
	movl	52(%edx), %eax
	movl	%eax, (%esp)
	call	_gdk_drawable_get_colormap
	movl	%eax, (%esp)
	leal	-136(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-120(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gdk_colormap_query_color
	testl	%edi, %edi
	jne	L162
L156:
	movzwl	-132(%ebp), %eax
	flds	LC139
	pushl	%eax
	movzwl	-130(%ebp), %eax
	fildl	(%esp)
	movl	%eax, (%esp)
	movzwl	-128(%ebp), %eax
	fildl	(%esp)
	fxch	%st(1)
	fdiv	%st(2), %st
	fxch	%st(1)
	movl	%eax, (%esp)
	fdiv	%st(2), %st
	fildl	(%esp)
	fxch	%st(1)
	addl	$4, %esp
	fstpl	12(%esp)
	fxch	%st(1)
	fstpl	4(%esp)
	movl	%ebx, (%esp)
	fdivp	%st, %st(1)
	fld1
	fxch	%st(1)
	fstpl	20(%esp)
	fstpl	28(%esp)
	call	_cairo_set_source_rgba
	movl	-48(%ebp), %eax
	testl	%eax, %eax
	jle	L163
L157:
	pushl	%eax
	fildl	(%esp)
	addl	$4, %esp
	movl	%ebx, (%esp)
	fstpl	4(%esp)
	call	_cairo_set_line_width
	fldl	20(%ebp)
	movl	%ebx, (%esp)
	fstpl	12(%esp)
	fldl	12(%ebp)
	fstpl	4(%esp)
	call	_cairo_move_to
	fldl	36(%ebp)
	movl	%ebx, (%esp)
	fstpl	12(%esp)
	fldl	28(%ebp)
	fstpl	4(%esp)
	call	_cairo_line_to
	movl	%ebx, (%esp)
	call	_cairo_stroke
	movl	%ebx, (%esp)
	call	_cairo_restore
L137:
	addl	$220, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L161:
	cmpl	$2, %eax
	jne	L155
	jmp	L151
	.p2align 4,,7
L162:
	movl	%edi, 8(%esp)
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	movl	$-1072431104, %eax
	movl	%eax, 16(%esp)
	leal	-168(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_cairo_set_dash
	jmp	L156
	.p2align 4,,7
L153:
	movl	$2, %edi
	jmp	L151
	.p2align 4,,7
L163:
	movl	$1, -48(%ebp)
	movl	$1, %eax
	jmp	L157
L148:
	movl	$1, %esi
	movl	%esi, 4(%esp)
	jmp	L159
L144:
	movl	$2, %eax
	jmp	L160
L149:
	movl	$2, %ecx
	movl	%ecx, 4(%esp)
	jmp	L159
L143:
	movl	$1, %eax
	jmp	L160
	.p2align 4,,15
	.def	_gabedit_contoursplot_cairo_lines;	.scl	3;	.type	32;	.endef
_gabedit_contoursplot_cairo_lines:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	xorl	%ebx, %ebx
	movl	%eax, -16(%ebp)
	movl	16(%ebp), %edi
	movl	12(%ebp), %esi
	movl	%edx, -20(%ebp)
	decl	%edi
	cmpl	$0, %edi
	jmp	L171
	.p2align 4,,7
L172:
	fildl	12(%esi,%ebx,8)
	movl	8(%ebp), %eax
	movl	-20(%ebp), %edx
	fstpl	28(%esp)
	fildl	8(%esi,%ebx,8)
	fstpl	20(%esp)
	fildl	4(%esi,%ebx,8)
	fstpl	12(%esp)
	fildl	(%esi,%ebx,8)
	incl	%ebx
	movl	%eax, (%esp)
	movl	-16(%ebp), %eax
	fstpl	4(%esp)
	call	_gabedit_contoursplot_cairo_line
	cmpl	%ebx, %edi
L171:
	jg	L172
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
	.align 4
LC144:
	.long	1084227584
	.align 4
LC147:
	.long	1199570688
	.text
	.p2align 4,,15
	.def	_gabedit_contoursplot_cairo_rectangle;	.scl	3;	.type	32;	.endef
_gabedit_contoursplot_cairo_rectangle:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$4, %edi
	pushl	%esi
	pushl	%ebx
	subl	$220, %esp
	movl	%eax, %ebx
	flds	LC144
	xorl	%eax, %eax
	testl	%ebx, %ebx
	movl	%eax, -152(%ebp)
	movl	$1076101120, %eax
	movl	8(%ebp), %esi
	movl	%edx, -172(%ebp)
	fstl	-168(%ebp)
	fstl	-160(%ebp)
	movl	%eax, -148(%ebp)
	fstpl	-144(%ebp)
	je	L173
	testl	%esi, %esi
	je	L173
	movl	%ebx, (%esp)
	call	_cairo_save
	movl	%esi, (%esp)
	leal	-120(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gdk_gc_get_values
	movl	-40(%ebp), %eax
	cmpl	$1, %eax
	je	L181
	jb	L181
	cmpl	$2, %eax
	je	L179
	cmpl	$3, %eax
	je	L180
L181:
	xorl	%esi, %esi
	movl	%esi, 4(%esp)
L196:
	movl	%ebx, (%esp)
	call	_cairo_set_line_cap
	movl	-36(%ebp), %eax
	cmpl	$1, %eax
	je	L184
	jb	L186
	cmpl	$2, %eax
	je	L185
L186:
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
L197:
	movl	%ebx, (%esp)
	call	_cairo_set_line_join
	movl	-44(%ebp), %eax
	cmpl	$1, %eax
	je	L189
	jae	L199
L191:
	xorl	%edi, %edi
L187:
	movl	-172(%ebp), %edx
	movl	52(%edx), %eax
	movl	%eax, (%esp)
	call	_gdk_drawable_get_colormap
	movl	%eax, (%esp)
	leal	-136(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-120(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gdk_colormap_query_color
	testl	%edi, %edi
	jne	L200
L192:
	movzwl	-132(%ebp), %eax
	xorl	%edi, %edi
	xorl	%esi, %esi
	flds	LC147
	pushl	%eax
	movzwl	-130(%ebp), %eax
	fildl	(%esp)
	movl	%eax, (%esp)
	movzwl	-128(%ebp), %eax
	fildl	(%esp)
	fxch	%st(1)
	fdiv	%st(2), %st
	fxch	%st(1)
	movl	%eax, (%esp)
	fdiv	%st(2), %st
	fildl	(%esp)
	fxch	%st(1)
	addl	$4, %esp
	fstpl	12(%esp)
	fxch	%st(1)
	fstpl	4(%esp)
	movl	%ebx, (%esp)
	fdivp	%st, %st(1)
	fld1
	fxch	%st(1)
	fstpl	20(%esp)
	fstpl	28(%esp)
	call	_cairo_set_source_rgba
	fldl	24(%ebp)
	movl	%ebx, (%esp)
	fstpl	12(%esp)
	fldl	16(%ebp)
	fstpl	4(%esp)
	call	_cairo_move_to
	fldl	32(%ebp)
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 16(%esp)
	fstpl	4(%esp)
	movl	%ebx, (%esp)
	call	_cairo_rel_line_to
	fldl	40(%ebp)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	%edi, 8(%esp)
	movl	%ebx, (%esp)
	fstpl	12(%esp)
	call	_cairo_rel_line_to
	xorb	$-128, 39(%ebp)
	xorl	%ecx, %ecx
	movl	%ecx, 16(%esp)
	movl	%esi, 12(%esp)
	fldl	32(%ebp)
	movl	%ebx, (%esp)
	fstpl	4(%esp)
	call	_cairo_rel_line_to
	movl	%ebx, (%esp)
	call	_cairo_close_path
	movl	-48(%ebp), %edx
	testl	%edx, %edx
	jle	L201
L193:
	movl	12(%ebp), %eax
	testl	%eax, %eax
	je	L194
	movl	%ebx, (%esp)
	call	_cairo_fill
L195:
	movl	%ebx, (%esp)
	call	_cairo_stroke
	movl	%ebx, (%esp)
	call	_cairo_restore
L173:
	addl	$220, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L199:
	cmpl	$2, %eax
	jne	L191
	jmp	L187
	.p2align 4,,7
L194:
	fildl	-48(%ebp)
	movl	%ebx, (%esp)
	fstpl	4(%esp)
	call	_cairo_set_line_width
	jmp	L195
	.p2align 4,,7
L200:
	movl	%edi, 8(%esp)
	xorl	%eax, %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 16(%esp)
	leal	-168(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_cairo_set_dash
	jmp	L192
	.p2align 4,,7
L189:
	movl	$2, %edi
	jmp	L187
	.p2align 4,,7
L201:
	movl	$1, -48(%ebp)
	jmp	L193
L184:
	movl	$1, %ecx
	movl	%ecx, 4(%esp)
	jmp	L197
L179:
	movl	$1, %eax
	movl	%eax, 4(%esp)
	jmp	L196
L185:
	movl	$2, %edx
	movl	%edx, 4(%esp)
	jmp	L197
L180:
	movl	$2, %eax
	movl	%eax, 4(%esp)
	jmp	L196
	.p2align 4,,15
	.def	_gabedit_contoursplot_cairo_layout;	.scl	3;	.type	32;	.endef
_gabedit_contoursplot_cairo_layout:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	movl	%esi, -8(%ebp)
	movl	28(%ebp), %esi
	movl	%edi, -4(%ebp)
	movl	32(%ebp), %edi
	movl	%ebx, -12(%ebp)
	movl	%eax, %ebx
	movl	%eax, (%esp)
	call	_cairo_save
	movl	%esi, %eax
	orl	%edi, %eax
	jne	L211
L204:
	fldl	16(%ebp)
	movl	%ebx, (%esp)
	fstpl	12(%esp)
	fldl	8(%ebp)
	fstpl	4(%esp)
	call	_cairo_move_to
	fldl	36(%ebp)
	movl	%ebx, (%esp)
	fstpl	4(%esp)
	call	_cairo_rotate
	movl	%ebx, (%esp)
	movl	24(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_pango_cairo_show_layout
	movl	%ebx, (%esp)
	call	_cairo_stroke
	movl	%ebx, (%esp)
	call	_cairo_restore
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L211:
	leal	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	24(%ebp), %eax
	movl	%eax, (%esp)
	call	_pango_layout_get_size
	testl	%esi, %esi
	jne	L212
L205:
	testl	%edi, %edi
	je	L204
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	js	L213
L209:
	sarl	$11, %eax
	pushl	%eax
	fildl	(%esp)
	addl	$4, %esp
	fstpl	-48(%ebp)
	fldl	36(%ebp)
	fstpl	(%esp)
	call	_sin
	fmull	-48(%ebp)
	movl	-20(%ebp), %eax
	testl	%eax, %eax
	fstpl	-48(%ebp)
	js	L214
L210:
	sarl	$11, %eax
	pushl	%eax
	fildl	(%esp)
	addl	$4, %esp
	fstpl	-56(%ebp)
	fldl	36(%ebp)
	fstpl	(%esp)
	call	_cos
	fmull	-56(%ebp)
	fstpl	-56(%ebp)
	fldl	-48(%ebp)
	faddl	-56(%ebp)
	fstpl	-48(%ebp)
	fldl	16(%ebp)
	fsubl	-48(%ebp)
	fstpl	16(%ebp)
	jmp	L204
	.p2align 4,,7
L212:
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	js	L215
L206:
	sarl	$11, %eax
	pushl	%eax
	fildl	(%esp)
	addl	$4, %esp
	fstpl	-32(%ebp)
	fldl	36(%ebp)
	fstpl	(%esp)
	call	_cos
	fmull	-32(%ebp)
	movl	-20(%ebp), %eax
	testl	%eax, %eax
	fstpl	-32(%ebp)
	js	L216
L207:
	sarl	$11, %eax
	pushl	%eax
	fildl	(%esp)
	addl	$4, %esp
	fstpl	-40(%ebp)
	fldl	36(%ebp)
	fstpl	(%esp)
	call	_sin
	fmull	-40(%ebp)
	fstpl	-40(%ebp)
	fldl	-32(%ebp)
	fsubl	-40(%ebp)
	fstpl	-32(%ebp)
	fldl	8(%ebp)
	fsubl	-32(%ebp)
	fstpl	8(%ebp)
	jmp	L205
L213:
	addl	$2047, %eax
	jmp	L209
L216:
	addl	$2047, %eax
	jmp	L207
L215:
	addl	$2047, %eax
	jmp	L206
L214:
	addl	$2047, %eax
	jmp	L210
	.p2align 4,,15
	.def	_contoursplot_cairo_string;	.scl	3;	.type	32;	.endef
_contoursplot_cairo_string:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	movl	%eax, -20(%ebp)
	movl	%edx, %eax
	movl	8(%ebp), %edx
	fldl	36(%ebp)
	movl	%ebx, -12(%ebp)
	movl	24(%ebp), %ebx
	movl	%edx, -24(%ebp)
	movl	12(%ebp), %edx
	movl	%esi, -8(%ebp)
	movl	32(%ebp), %esi
	movl	%edx, -28(%ebp)
	movl	16(%ebp), %edx
	movl	%edi, -4(%ebp)
	movl	28(%ebp), %edi
	movl	%edx, -32(%ebp)
	movl	20(%ebp), %edx
	fstl	-48(%ebp)
	movl	%edx, -36(%ebp)
	fstpl	24(%esp)
	movl	%esi, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	-24(%ebp), %edx
	call	_gabedit_contoursplot_cairo_string
	movl	-20(%ebp), %edx
	movl	200(%edx), %eax
	testl	%eax, %eax
	jne	L219
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L219:
	fldl	-48(%ebp)
	movl	%esi, 28(%ebp)
	movl	-36(%ebp), %edx
	movl	%edi, 24(%ebp)
	movl	-8(%ebp), %esi
	movl	%ebx, 20(%ebp)
	movl	-4(%ebp), %edi
	movl	-12(%ebp), %ebx
	movl	%edx, 16(%ebp)
	movl	-32(%ebp), %edx
	fstpl	32(%ebp)
	movl	%edx, 12(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, 8(%ebp)
	movl	-24(%ebp), %edx
	movl	%ebp, %esp
	popl	%ebp
	jmp	_gabedit_contoursplot_cairo_string
	.p2align 4,,15
	.def	_contoursplot_cairo_line;	.scl	3;	.type	32;	.endef
_contoursplot_cairo_line:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	fldl	16(%ebp)
	movl	%ebx, -12(%ebp)
	movl	%eax, %ebx
	movl	%edx, %eax
	fstpl	-24(%ebp)
	fldl	24(%ebp)
	movl	%esi, -8(%ebp)
	movl	12(%ebp), %esi
	movl	%edi, -4(%ebp)
	movl	8(%ebp), %edi
	fstpl	-32(%ebp)
	fldl	32(%ebp)
	movl	%edi, %edx
	fstpl	-40(%ebp)
	fldl	40(%ebp)
	fstl	-48(%ebp)
	fstpl	28(%esp)
	fldl	-40(%ebp)
	fstpl	20(%esp)
	fldl	-32(%ebp)
	fstpl	12(%esp)
	fldl	-24(%ebp)
	movl	%esi, (%esp)
	fstpl	4(%esp)
	call	_gabedit_contoursplot_cairo_line
	movl	200(%ebx), %eax
	testl	%eax, %eax
	jne	L222
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L222:
	fldl	-48(%ebp)
	movl	%esi, 8(%ebp)
	movl	%edi, %edx
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	fstpl	36(%ebp)
	fldl	-40(%ebp)
	fstpl	28(%ebp)
	fldl	-32(%ebp)
	fstpl	20(%ebp)
	fldl	-24(%ebp)
	fstpl	12(%ebp)
	movl	%ebp, %esp
	popl	%ebp
	jmp	_gabedit_contoursplot_cairo_line
	.p2align 4,,15
	.def	_contoursplot_cairo_rectangle;	.scl	3;	.type	32;	.endef
_contoursplot_cairo_rectangle:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$104, %esp
	fldl	20(%ebp)
	movl	%ebx, -12(%ebp)
	movl	%eax, %ebx
	movl	%edx, %eax
	fstpl	-32(%ebp)
	movl	8(%ebp), %edx
	fldl	28(%ebp)
	movl	%esi, -8(%ebp)
	movl	16(%ebp), %esi
	movl	%edi, -4(%ebp)
	movl	12(%ebp), %edi
	fstpl	-40(%ebp)
	fldl	36(%ebp)
	movl	%edx, -20(%ebp)
	fstpl	-48(%ebp)
	fldl	44(%ebp)
	fstl	-56(%ebp)
	fstpl	32(%esp)
	fldl	-48(%ebp)
	fstpl	24(%esp)
	fldl	-40(%ebp)
	fstpl	16(%esp)
	fldl	-32(%ebp)
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	fstpl	8(%esp)
	call	_gabedit_contoursplot_cairo_rectangle
	movl	200(%ebx), %eax
	testl	%eax, %eax
	jne	L225
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L225:
	fldl	-56(%ebp)
	movl	%esi, 12(%ebp)
	movl	-20(%ebp), %edx
	movl	%edi, 8(%ebp)
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	fstpl	40(%ebp)
	movl	-4(%ebp), %edi
	fldl	-48(%ebp)
	fstpl	32(%ebp)
	fldl	-40(%ebp)
	fstpl	24(%ebp)
	fldl	-32(%ebp)
	fstpl	16(%ebp)
	movl	%ebp, %esp
	popl	%ebp
	jmp	_gabedit_contoursplot_cairo_rectangle
	.p2align 4,,15
	.def	_contoursplot_cairo_layout;	.scl	3;	.type	32;	.endef
_contoursplot_cairo_layout:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$120, %esp
	fldl	8(%ebp)
	fldl	16(%ebp)
	fldl	36(%ebp)
	movl	%ebx, -12(%ebp)
	movl	%eax, %ebx
	movl	24(%ebp), %eax
	movl	%esi, -8(%ebp)
	movl	%edx, %esi
	movl	28(%ebp), %edx
	movl	%edi, -4(%ebp)
	movl	32(%ebp), %edi
	movl	%eax, -28(%ebp)
	movl	%edx, -32(%ebp)
	fstl	-40(%ebp)
	fxch	%st(1)
	movl	%eax, 16(%esp)
	movl	%esi, %eax
	fstl	8(%esp)
	fxch	%st(2)
	fstl	(%esp)
	fxch	%st(1)
	fstpl	28(%esp)
	fxch	%st(1)
	movl	%edi, 24(%esp)
	movl	%edx, 20(%esp)
	fstpl	-56(%ebp)
	fstpl	-72(%ebp)
	call	_gabedit_contoursplot_cairo_layout
	fldl	-56(%ebp)
	movl	200(%ebx), %eax
	fldl	-72(%ebp)
	testl	%eax, %eax
	je	L226
	cmpl	%esi, 196(%ebx)
	je	L229
L228:
	fldl	-40(%ebp)
	fxch	%st(2)
	movl	%edi, 32(%ebp)
	movl	-32(%ebp), %edx
	fstpl	16(%ebp)
	movl	-12(%ebp), %ebx
	fstpl	8(%ebp)
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%edx, 28(%ebp)
	movl	-28(%ebp), %edx
	fstpl	36(%ebp)
	movl	%edx, 24(%ebp)
	movl	%ebp, %esp
	popl	%ebp
	jmp	_gabedit_contoursplot_cairo_layout
	.p2align 4,,7
L226:
	fstp	%st(0)
	fstp	%st(0)
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L229:
	fildl	204(%ebx)
	faddp	%st, %st(1)
	fildl	208(%ebx)
	faddp	%st, %st(2)
	jmp	L228
	.p2align 4,,15
	.def	_get_parent_window;	.scl	3;	.type	32;	.endef
_get_parent_window:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$16, %esp
	.p2align 4,,15
L231:
	movl	%esi, (%esp)
	call	_gtk_widget_get_parent
	testl	%eax, %eax
	movl	%eax, %ebx
	movl	%eax, %esi
	je	L232
	call	_gtk_window_get_type
	movl	(%ebx), %edx
	testl	%edx, %edx
	je	L234
	cmpl	%eax, (%edx)
	je	L232
L234:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L231
L232:
	addl	$16, %esp
	movl	%ebx, %eax
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_destroy_data_dialog;	.scl	3;	.type	32;	.endef
_destroy_data_dialog:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 8(%ebp)
	leave
	jmp	_gtk_object_destroy
	.section .rdata,"dr"
__PRETTY_FUNCTION__.55:
	.ascii "file_chooser_set_filters\0"
	.align 4
LC158:
	.ascii "GTK_IS_FILE_CHOOSER(fileChooser)\0"
LC157:
	.ascii "fileChooser != NULL\0"
LC159:
	.ascii "patterns != NULL\0"
	.text
	.p2align 4,,15
	.def	_file_chooser_set_filters;	.scl	3;	.type	32;	.endef
_file_chooser_set_filters:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	movl	%edx, %esi
	pushl	%ebx
	subl	$28, %esp
	testl	%eax, %eax
	movl	%eax, -16(%ebp)
	movl	$0, -20(%ebp)
	je	L267
	call	_gtk_file_chooser_get_type
	movl	-16(%ebp), %ecx
	movl	(%ecx), %edx
	testl	%edx, %edx
	jne	L268
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L269
L260:
	testl	%esi, %esi
	je	L270
	movl	(%esi), %edx
	testl	%edx, %edx
	jne	L255
L237:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L255:
	call	_gtk_file_filter_new
	movl	%eax, %ebx
	movl	(%esi,%edi,4), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_gtk_file_filter_set_name
	movl	(%esi,%edi,4), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_gtk_file_filter_add_pattern
	call	_gtk_file_chooser_get_type
	movl	%eax, -24(%ebp)
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_file_chooser_add_filter
	testl	%edi, %edi
	jne	L254
	movl	%ebx, -20(%ebp)
L254:
	incl	%edi
	movl	(%esi,%edi,4), %eax
	testl	%eax, %eax
	jne	L255
	movl	-20(%ebp), %eax
	testl	%eax, %eax
	je	L237
	movl	-24(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	-20(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_gtk_file_chooser_set_filter
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L268:
	cmpl	%eax, (%edx)
	je	L260
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L260
	.p2align 4,,15
L269:
	movl	$LC158, %esi
	movl	%esi, 8(%esp)
L266:
	movl	$0, (%esp)
	movl	$__PRETTY_FUNCTION__.55, %ecx
	movl	%ecx, 4(%esp)
	call	_g_return_if_fail_warning
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L267:
	movl	$LC157, %edi
	movl	%edi, 8(%esp)
	jmp	L266
L270:
	movl	$LC159, %ebx
	movl	%ebx, 8(%esp)
	jmp	L266
	.p2align 4,,15
	.def	_get_interpolatedValueData;	.scl	3;	.type	32;	.endef
_get_interpolatedValueData:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$252, %esp
	movl	8(%eax), %edx
	fldl	16(%eax)
	fldl	24(%eax)
	movl	%edx, -164(%ebp)
	movl	4(%eax), %edx
	fsub	%st(1), %st
	fldl	8(%ebp)
	decl	%edx
	pushl	%edx
	movl	-164(%ebp), %edx
	fildl	(%esp)
	fldl	32(%eax)
	decl	%edx
	fldl	40(%eax)
	movl	%edx, (%esp)
	fnstcw	-154(%ebp)
	fsub	%st(1), %st
	fxch	%st(4)
	movzwl	-154(%ebp), %edx
	fdivp	%st, %st(2)
	cld
	orw	$3072, %dx
	movw	%dx, -156(%ebp)
	fildl	(%esp)
	fldl	16(%ebp)
	fxch	%st(5)
	fdivp	%st, %st(1)
	fld	%st(3)
	fsub	%st(6), %st
	fdiv	%st(3), %st
	fldcw	-156(%ebp)
	fistpl	-160(%ebp)
	fldcw	-154(%ebp)
	fld	%st(4)
	fsub	%st(2), %st
	movl	-160(%ebp), %esi
	fdiv	%st(1), %st
	leal	1(%esi), %edx
	movl	%esi, (%esp)
	fildl	(%esp)
	fxch	%st(1)
	movl	%edx, (%esp)
	fldcw	-156(%ebp)
	fistpl	-160(%ebp)
	fldcw	-154(%ebp)
	fildl	(%esp)
	fxch	%st(1)
	movl	-160(%ebp), %ebx
	fmul	%st(4), %st
	fxch	%st(1)
	movl	%ebx, (%esp)
	leal	1(%ebx), %edi
	fmulp	%st, %st(4)
	fildl	(%esp)
	fxch	%st(1)
	movl	%edi, (%esp)
	fadd	%st(7), %st
	fxch	%st(7)
	movl	(%eax), %eax
	faddp	%st, %st(4)
	fildl	(%esp)
	fxch	%st(1)
	addl	$4, %esp
	movl	%eax, -168(%ebp)
	movl	-164(%ebp), %eax
	fmul	%st(2), %st
	fxch	%st(1)
	movl	-168(%ebp), %ecx
	imull	%eax, %esi
	fmulp	%st, %st(2)
	leal	(%ebx,%esi), %eax
	fadd	%st(2), %st
	fxch	%st(2)
	faddp	%st, %st(1)
	fldl	(%ecx,%eax,8)
	movl	-164(%ebp), %eax
	imull	%eax, %edx
	fstpl	-88(%ebp)
	movl	-88(%ebp), %eax
	addl	%edx, %ebx
	fldl	(%ecx,%ebx,8)
	leal	(%edi,%edx), %edx
	addl	%esi, %edi
	fstpl	-80(%ebp)
	fldl	(%ecx,%edx,8)
	xorl	%edx, %edx
	fstpl	-72(%ebp)
	fldl	(%ecx,%edi,8)
	leal	-88(%ebp), %edi
	movl	%eax, -56(%ebp)
	movl	-84(%ebp), %eax
	movl	$8, %ecx
	fstpl	-64(%ebp)
	fldz
	movl	%eax, -52(%ebp)
	movl	-80(%ebp), %eax
	movl	%eax, -48(%ebp)
	movl	-76(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	-72(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	-68(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, -28(%ebp)
	xorl	%eax, %eax
	rep
	stosl
	leal	-120(%ebp), %edi
	movl	$8, %ecx
	rep
	stosl
	leal	-152(%ebp), %edi
	movl	$8, %ecx
	rep
	stosl
	movl	24(%ebp), %eax
	xorl	%ecx, %ecx
	fstpl	(%eax)
	fxch	%st(4)
	movl	%eax, 64(%esp)
	leal	-152(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-120(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-88(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-56(%ebp), %eax
	movl	%ecx, 72(%esp)
	movl	%edx, 68(%esp)
	fstpl	56(%esp)
	fxch	%st(2)
	fstpl	48(%esp)
	fxch	%st(2)
	fstpl	40(%esp)
	fstpl	32(%esp)
	fstpl	24(%esp)
	fstpl	16(%esp)
	movl	%eax, (%esp)
	call	_biCubicInterpolation
	addl	$252, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC163:
	.ascii "sans %d\0"
	.text
	.p2align 4,,15
	.def	_contoursplot_build_points_contour;	.scl	3;	.type	32;	.endef
_contoursplot_build_points_contour:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$168, %esp
	movl	%ebx, -12(%ebp)
	testl	%eax, %eax
	movl	%eax, %ebx
	movl	%esi, -8(%ebp)
	movl	%edx, %esi
	movl	%edi, -4(%ebp)
	je	L272
	movl	432(%eax), %eax
	testl	%eax, %eax
	jne	L281
L272:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L281:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %ebx
	movl	124(%esi), %eax
	testl	%eax, %eax
	jne	L282
L275:
	movl	%ebx, (%esp)
	leal	24(%esi), %edi
	movl	%edi, 4(%esp)
	call	_gtk_widget_create_pango_layout
	movl	%eax, 124(%esi)
	testl	%eax, %eax
	je	L272
	movl	%eax, (%esp)
	movl	$1, %ecx
	leal	-152(%ebp), %ebx
	movl	%ecx, 4(%esp)
	call	_pango_layout_set_justify
	movl	124(%esi), %eax
	movl	$1, %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_pango_layout_set_alignment
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	124(%esi), %eax
	movl	%eax, (%esp)
	call	_pango_layout_set_alignment
	movl	%edi, 4(%esp)
	movl	$-1, %eax
	movl	%eax, 8(%esp)
	movl	124(%esi), %eax
	movl	%eax, (%esp)
	call	_pango_layout_set_markup
	movl	%ebx, (%esp)
	movl	128(%esi), %eax
	leal	2(%eax,%eax), %eax
	movl	%eax, 8(%esp)
	movl	$LC163, %eax
	movl	%eax, 4(%esp)
	call	_sprintf
	movl	%ebx, (%esp)
	call	_pango_font_description_from_string
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	124(%esi), %eax
	movl	%eax, (%esp)
	call	_pango_layout_set_font_description
	movl	124(%esi), %eax
	movl	%eax, (%esp)
	call	_pango_layout_context_changed
	leal	-40(%ebp), %eax
	movl	%eax, 8(%esp)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	movl	124(%esi), %eax
	movl	%eax, (%esp)
	call	_pango_layout_get_pixel_extents
	leal	136(%esi), %eax
	movl	%eax, 8(%esp)
	leal	132(%esi), %eax
	movl	%eax, 4(%esp)
	movl	124(%esi), %eax
	movl	%eax, (%esp)
	call	_pango_layout_get_size
	movl	%ebx, (%esp)
	movl	-32(%ebp), %eax
	movl	%eax, 132(%esi)
	movl	-28(%ebp), %eax
	movl	%eax, 136(%esi)
	call	_pango_font_description_free
	movl	124(%esi), %eax
	movl	%eax, (%esp)
	call	_pango_layout_get_attributes
	testl	%eax, %eax
	movl	%eax, %ebx
	je	L283
	movl	%eax, (%esp)
	call	_pango_attr_list_ref
L280:
	movzwl	152(%esi), %eax
	movl	%eax, 8(%esp)
	movzwl	150(%esi), %eax
	movl	%eax, 4(%esp)
	movzwl	148(%esi), %eax
	movl	%eax, (%esp)
	call	_pango_attr_foreground_new
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_pango_attr_list_insert
	movl	%ebx, 4(%esp)
	movl	124(%esi), %eax
	movl	%eax, (%esp)
	call	_pango_layout_set_attributes
	movl	%ebx, (%esp)
	call	_pango_attr_list_unref
	jmp	L272
L282:
	movl	%eax, (%esp)
	movl	$80, %edi
	movl	%edi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_g_object_unref
	jmp	L275
L283:
	call	_pango_attr_list_new
	movl	%eax, %ebx
	jmp	L280
	.p2align 4,,15
	.def	_get_one_point;	.scl	3;	.type	32;	.endef
_get_one_point:
	pushl	%ebp
	fldz
	movl	%esp, %ebp
	fldl	8(%ebp)
	movl	56(%ebp), %ecx
	movl	60(%ebp), %edx
	fucom	%st(1)
	fnstsw	%ax
	fldl	16(%ebp)
	sahf
	fldl	24(%ebp)
	fldl	32(%ebp)
	fldl	40(%ebp)
	fldl	48(%ebp)
	jne	L285
	jp	L285
	fstp	%st(1)
L291:
	fxch	%st(4)
	fucom	%st(5)
	fnstsw	%ax
	fstp	%st(5)
	fxch	%st(1)
	fstpl	(%ecx)
	sahf
	jne	L288
	jp	L288
	fstp	%st(1)
	fstp	%st(1)
	fstp	%st(1)
	fstpl	(%edx)
	popl	%ebp
	ret
	.p2align 4,,7
L288:
	fsubr	%st, %st(2)
	fxch	%st(1)
	fsub	%st(3), %st
	fxch	%st(2)
	fmulp	%st, %st(3)
	fxch	%st(2)
	fdivp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	(%edx)
	popl	%ebp
	ret
	.p2align 4,,7
L285:
	fxch	%st(1)
	fsub	%st(3), %st
	fld	%st(4)
	fsub	%st(6), %st
	fxch	%st(1)
	fmul	%st(6), %st
	fdivp	%st, %st(1)
	fsubrp	%st, %st(3)
	jmp	L291
	.p2align 4,,15
	.def	_free_one_contour;	.scl	3;	.type	32;	.endef
_free_one_contour:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	%eax, %ebx
	movl	12(%eax), %eax
	testl	%eax, %eax
	jne	L299
	movl	16(%ebx), %eax
	testl	%eax, %eax
	jne	L300
L296:
	movl	20(%ebx), %eax
	testl	%eax, %eax
	jne	L301
L297:
	movl	124(%ebx), %eax
	testl	%eax, %eax
	jne	L302
L298:
	movl	$0, 12(%ebx)
	movl	$0, 16(%ebx)
	movl	$0, 20(%ebx)
	movl	$0, 124(%ebx)
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L299:
	movl	%eax, (%esp)
	call	_g_free
	movl	16(%ebx), %eax
	testl	%eax, %eax
	je	L296
	.p2align 4,,15
L300:
	movl	%eax, (%esp)
	call	_g_free
	movl	20(%ebx), %eax
	testl	%eax, %eax
	je	L297
	.p2align 4,,15
L301:
	movl	%eax, (%esp)
	call	_g_free
	movl	124(%ebx), %eax
	testl	%eax, %eax
	je	L298
	.p2align 4,,15
L302:
	movl	%eax, (%esp)
	movl	$80, %edx
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_g_object_unref
	movl	$0, 12(%ebx)
	movl	$0, 16(%ebx)
	movl	$0, 20(%ebx)
	movl	$0, 124(%ebx)
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.section .rdata,"dr"
LC167:
	.ascii "Error\0"
	.text
	.p2align 4,,15
	.def	_Message;	.scl	3;	.type	32;	.endef
_Message:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	testl	%eax, %eax
	movl	%eax, %ebx
	je	L303
	testl	%edx, %edx
	je	L303
	movl	%edx, (%esp)
	movl	$LC167, %eax
	movl	%eax, 4(%esp)
	call	_strstr
	testl	%eax, %eax
	je	L306
	movl	%ebx, 16(%esp)
	movl	$1, %eax
	movl	%eax, 12(%esp)
	movl	$3, %eax
	movl	%eax, 8(%esp)
L309:
	movl	$0, (%esp)
	movl	$2, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_message_dialog_new_with_markup
	testl	%eax, %eax
	movl	%eax, %ebx
	je	L303
	call	_gtk_dialog_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_dialog_run
	movl	%ebx, (%esp)
	call	_gtk_widget_destroy
L303:
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L306:
	movl	%ebx, 16(%esp)
	movl	$1, %eax
	xorl	%ebx, %ebx
	movl	%eax, 12(%esp)
	movl	%ebx, 8(%esp)
	jmp	L309
	.p2align 4,,15
	.def	_get_a_float;	.scl	3;	.type	32;	.endef
_get_a_float:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	%eax, %ebx
	movl	%edx, -16(%ebp)
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	movl	%eax, -20(%ebp)
	testl	%eax, %eax
	je	L311
	cmpb	$0, (%eax)
	jne	L368
L311:
	movl	8(%ebp), %eax
	movl	$LC167, %edx
	call	_Message
L367:
	xorl	%eax, %eax
L310:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L368:
	movl	%eax, (%esp)
	call	_g_strdup
	xorl	%edi, %edi
	testl	%eax, %eax
	movl	%eax, %esi
	je	L363
	cmpb	$0, (%eax)
	movl	%eax, %ebx
	jne	L315
L313:
	testl	%esi, %esi
	je	L363
	cmpb	$0, (%esi)
	je	L336
	movl	%esi, (%esp)
	call	_strlen
	leal	-1(%eax,%esi), %ebx
	jmp	L329
	.p2align 4,,7
L369:
	movl	__imp___pctype, %eax
	movl	(%eax), %eax
	movzwl	(%eax,%edx,2), %eax
	andl	$8, %eax
L334:
	testl	%eax, %eax
	je	L336
	movb	$0, (%ebx)
	decl	%ebx
L329:
	cmpl	%esi, %ebx
	jb	L336
	movzbl	(%ebx), %edx
	movl	__imp____mb_cur_max, %eax
	cmpl	$1, (%eax)
	je	L369
	movl	%edx, (%esp)
	movl	$8, %eax
	movl	%eax, 4(%esp)
	call	__isctype
	jmp	L334
	.p2align 4,,7
L370:
	movl	__imp___pctype, %eax
	movl	(%eax), %eax
	movzwl	(%eax,%edx,2), %eax
	andl	$8, %eax
L320:
	testl	%eax, %eax
	je	L316
	incl	%edi
	incl	%ebx
L315:
	movzbl	(%ebx), %eax
	testb	%al, %al
	je	L316
	movsbl	%al,%edx
	movl	__imp____mb_cur_max, %eax
	cmpl	$1, (%eax)
	je	L370
	movl	%edx, (%esp)
	movl	$8, %eax
	movl	%eax, 4(%esp)
	call	__isctype
	jmp	L320
	.p2align 4,,7
L336:
	xorl	%ebx, %ebx
L338:
	movl	%esi, (%esp)
	call	_strlen
	cmpl	%ebx, %eax
	jbe	L371
	movsbl	(%ebx,%esi),%eax
	subl	$43, %eax
	cmpl	$58, %eax
	ja	L366
	jmp	*L359(,%eax,4)
	.section .rdata,"dr"
	.align 4
L359:
	.long	L357
	.long	L366
	.long	L357
	.long	L357
	.long	L366
	.long	L357
	.long	L357
	.long	L357
	.long	L357
	.long	L357
	.long	L357
	.long	L357
	.long	L357
	.long	L357
	.long	L357
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L357
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L366
	.long	L357
	.text
L371:
	movzbl	(%esi), %eax
	cmpb	$101, %al
	sete	%dl
	cmpb	$69, %al
	sete	%al
	orl	%edx, %eax
	testb	$1, %al
	jne	L366
	movl	%esi, (%esp)
	call	_g_free
L363:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_atof
	movl	-16(%ebp), %eax
	fstpl	(%eax)
	movl	$1, %eax
	jmp	L310
	.p2align 4,,7
L366:
	movl	8(%ebp), %eax
	movl	$LC167, %edx
	call	_Message
	movl	%esi, (%esp)
	call	_g_free
	jmp	L367
	.p2align 4,,7
L357:
	incl	%ebx
	jmp	L338
L316:
	xorl	%ebx, %ebx
	jmp	L322
	.p2align 4,,7
L325:
	leal	(%esi,%ebx), %edx
	incl	%ebx
	movzbl	(%edx,%edi), %eax
	movb	%al, (%edx)
L322:
	movl	%esi, (%esp)
	call	_strlen
	subl	%edi, %eax
	cmpl	%ebx, %eax
	jg	L325
	movb	$0, (%esi,%eax)
	jmp	L313
	.p2align 4,,15
	.def	_add_widget_table;	.scl	3;	.type	32;	.endef
_add_widget_table:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	%esi, -8(%ebp)
	movzwl	8(%ebp), %esi
	movl	%edx, -16(%ebp)
	movl	%ebx, -12(%ebp)
	movl	%eax, %ebx
	movl	%edi, -4(%ebp)
	call	_gtk_table_get_type
	movzwl	12(%ebp), %edi
	movl	%ebx, (%esp)
	movl	$3, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$3, %edx
	movl	$6, %ecx
	movl	%edx, 36(%esp)
	movl	$6, %edx
	movl	%edx, 24(%esp)
	leal	1(%esi), %edx
	movl	%edx, 20(%esp)
	leal	1(%edi), %edx
	movl	%edx, 12(%esp)
	movl	-16(%ebp), %edx
	movl	%ebx, 32(%esp)
	movl	%esi, 16(%esp)
	movl	%edi, 8(%esp)
	movl	%ecx, 28(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_table_attach
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_add_label_at_table;	.scl	3;	.type	32;	.endef
_add_label_at_table:
	pushl	%ebp
	xorl	%ecx, %ecx
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	movl	%eax, -16(%ebp)
	movl	%edx, %ebx
	movzwl	8(%ebp), %eax
	movl	16(%ebp), %esi
	movl	%ecx, 4(%esp)
	movl	$0, (%esp)
	movl	%eax, -20(%ebp)
	movzwl	12(%ebp), %eax
	movl	%eax, -24(%ebp)
	call	_gtk_hbox_new
	movl	%ebx, (%esp)
	movl	%eax, %edi
	call	_gtk_label_new
	movl	%eax, %ebx
	call	_gtk_label_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_label_set_justify
	cmpl	$2, %esi
	je	L378
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	xorl	%esi, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 12(%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
L377:
	movl	%ecx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_box_pack_start
	movl	-24(%ebp), %eax
	movl	%edi, %edx
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	movl	-16(%ebp), %eax
	call	_add_widget_table
	addl	$44, %esp
	movl	%ebx, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L378:
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	$1, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 12(%esp)
	xorl	%edx, %edx
	movl	$1, %ecx
	movl	%edx, 16(%esp)
	jmp	L377
	.section .rdata,"dr"
LC169:
	.ascii "CurentData\0"
LC170:
	.ascii "w\0"
LC171:
	.ascii "%d %f %f\12\0"
LC172:
	.ascii "%f\12\0"
	.text
	.p2align 4,,15
	.def	_save_data;	.scl	3;	.type	32;	.endef
_save_data:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	subl	$40, %esp
	cmpl	$-5, 12(%ebp)
	movl	%ebx, -12(%ebp)
	movl	8(%ebp), %ebx
	movl	%esi, -8(%ebp)
	movl	%edi, -4(%ebp)
	je	L389
L379:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L389:
	movl	%ebx, (%esp)
	call	_gtk_file_chooser_get_filename_utf8
	movl	%ebx, (%esp)
	movl	$80, %ecx
	movl	%eax, %esi
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC169, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	xorl	%eax, %eax
	testl	%ebx, %ebx
	je	L379
	movl	%esi, (%esp)
	movl	$LC170, %edi
	movl	$LC171, %esi
	movl	%edi, 4(%esp)
	call	_fopen
	fldl	24(%ebx)
	movl	%eax, %edi
	fstpl	20(%esp)
	fldl	16(%ebx)
	fstpl	12(%esp)
	movl	4(%ebx), %eax
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	movl	%eax, 8(%esp)
	movl	%edi, (%esp)
	call	_fprintf
	fldl	40(%ebx)
	movl	$LC171, %ecx
	fstpl	20(%esp)
	fldl	32(%ebx)
	fstpl	12(%esp)
	movl	8(%ebx), %eax
	movl	%ecx, 4(%esp)
	movl	%edi, (%esp)
	movl	%eax, 8(%esp)
	call	_fprintf
	movl	8(%ebx), %eax
	movl	4(%ebx), %edx
	imull	%edx, %eax
	cmpl	%eax, %esi
	jae	L387
	.p2align 4,,15
L392:
	movl	(%ebx), %eax
	fldl	(%eax,%esi,8)
	movl	$LC172, %eax
	movl	%edi, (%esp)
	incl	%esi
	movl	%eax, 4(%esp)
	fstpl	8(%esp)
	call	_fprintf
	movl	8(%ebx), %eax
	movl	4(%ebx), %edx
	imull	%edx, %eax
	cmpl	%eax, %esi
	jb	L392
L387:
	movl	%edi, (%esp)
	call	_fclose
	movl	$1, %eax
	jmp	L379
	.section .rdata,"dr"
LC174:
	.ascii "*.txt\0"
LC177:
	.ascii "select-multiple\0"
LC175:
	.ascii "*\0"
LC178:
	.ascii "gtk+\0"
LC179:
	.ascii "file-system-backend\0"
LC180:
	.ascii "action\0"
	.align 4
LC176:
	.ascii "Save data in an ASCII Contours file(xsize, xmin, xmax, ysize, ymin, ymax, Zvalues\0"
LC181:
	.ascii "gtk-save\0"
LC182:
	.ascii "gtk-cancel\0"
LC183:
	.ascii "response\0"
LC185:
	.ascii "\\\0"
LC184:
	.ascii "contoursplotData.txt\0"
LC186:
	.ascii "%s%s%s\0"
	.text
	.p2align 4,,15
	.def	_save_data_dlg;	.scl	3;	.type	32;	.endef
_save_data_dlg:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	xorl	%edi, %edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$76, %esp
	movl	$LC174, -40(%ebp)
	movl	$LC177, %ebx
	movl	$LC175, -36(%ebp)
	movl	$0, -32(%ebp)
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	call	_get_parent_window
	movl	%eax, -44(%ebp)
	call	_gtk_file_chooser_dialog_get_type
	movl	%edi, 28(%esp)
	movl	$LC178, %ecx
	movl	$LC179, %edx
	movl	%esi, 24(%esp)
	movl	$1, %edi
	movl	$LC180, %esi
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%ebx, 20(%esp)
	movl	$LC176, %ebx
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_object_new
	movl	%eax, %esi
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %edi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_title
	call	_gtk_dialog_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$-5, %edx
	movl	%ecx, 20(%esp)
	movl	$LC181, %ecx
	movl	%edx, 16(%esp)
	movl	$-6, %edx
	movl	%ecx, 12(%esp)
	movl	$LC182, %ecx
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	call	_gtk_dialog_add_buttons
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$-5, %edx
	movl	%edx, 4(%esp)
	call	_gtk_dialog_set_default_response
	movl	-44(%ebp), %eax
	testl	%eax, %eax
	je	L394
	movl	%edi, 4(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_transient_for
L394:
	movl	%edi, 4(%esp)
	movl	$1, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_modal
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 12(%esp)
	movl	$_save_data, %eax
	xorl	%ecx, %ecx
	movl	%eax, 8(%esp)
	xorl	%edx, %edx
	movl	$LC183, %eax
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_signal_connect_data
	movl	%ebx, 4(%esp)
	movl	$1, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 12(%esp)
	movl	$_gtk_widget_destroy, %eax
	movl	$1, %ecx
	movl	%eax, 8(%esp)
	xorl	%edx, %edx
	movl	$LC183, %eax
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_signal_connect_data
	call	_gtk_file_chooser_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	leal	-40(%ebp), %edx
	call	_file_chooser_set_filters
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	%edi, 4(%esp)
	movl	$80, %edi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_modal
	movl	8(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC169, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%edi, 4(%esp)
	movl	%eax, %ebx
	movl	$LC185, %edi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC169, %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, 8(%esp)
	call	_g_object_set_data
	call	_g_get_current_dir_utf8
	movl	%eax, 4(%esp)
	movl	$LC184, %edx
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	$LC186, (%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_gtk_file_chooser_set_filename_utf8
	testl	%ebx, %ebx
	je	L396
	movl	%ebx, (%esp)
	call	_g_free
L396:
	movl	%esi, (%esp)
	movl	$LC184, %ebx
	movl	%ebx, 4(%esp)
	call	_gtk_file_chooser_set_current_name
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
	.align 4
LC187:
	.ascii "Are you sure to delete this data ?\0"
	.text
	.p2align 4,,15
	.def	_remove_data_dlg;	.scl	3;	.type	32;	.endef
_remove_data_dlg:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	$4, %esi
	pushl	%ebx
	subl	$28, %esp
	movl	8(%ebp), %edi
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	call	_get_parent_window
	movl	%eax, %ebx
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	movl	$2, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %ecx
	movl	$LC187, %edx
	movl	%ecx, 4(%esp)
	movl	%edx, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	call	_gtk_message_dialog_new
	movl	%eax, %ebx
	call	_gtk_dialog_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$-9, %edx
	movl	%edx, 4(%esp)
	call	_gtk_dialog_set_default_response
	movl	%edi, 12(%esp)
	movl	$2, %eax
	movl	%eax, 20(%esp)
	xorl	%eax, %eax
	movl	%eax, 16(%esp)
	movl	$_remove_data, %eax
	movl	%eax, 8(%esp)
	movl	$LC183, %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_dialog_run
	movl	%ebx, 8(%ebp)
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_destroy
	.p2align 4,,15
	.def	_Waiting;	.scl	3;	.type	32;	.endef
_Waiting:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	leal	-12(%ebp), %esi
	pushl	%ebx
	subl	$16, %esp
	call	_g_timer_new
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_g_timer_start
	movl	%ebx, (%esp)
	call	_g_timer_reset
	.p2align 4,,15
L399:
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_timer_elapsed
	fldl	8(%ebp)
	fucompp
	fnstsw	%ax
	sahf
	ja	L399
	movl	%ebx, (%esp)
	call	_g_timer_destroy
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC189:
	.ascii "Save Contours plot\0"
LC190:
	.ascii "*.%s\0"
LC191:
	.ascii "ImageType\0"
LC192:
	.ascii "tpng\0"
LC193:
	.ascii "contoursplot.png\0"
LC195:
	.ascii "ContoursPLOT\0"
LC194:
	.ascii "contoursplot.%s\0"
	.text
	.p2align 4,,15
	.def	_saveImageDlg;	.scl	3;	.type	32;	.endef
_saveImageDlg:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$LC178, %edi
	pushl	%esi
	movl	$LC179, %esi
	pushl	%ebx
	subl	$44, %esp
	xorl	%ebx, %ebx
	movl	%edx, -20(%ebp)
	movl	%eax, -16(%ebp)
	call	_gtk_file_chooser_dialog_get_type
	movl	%ebx, 28(%esp)
	xorl	%ecx, %ecx
	movl	$LC177, %edx
	movl	%ecx, 24(%esp)
	movl	$1, %ebx
	movl	$LC180, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	xorl	%edi, %edi
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$-5, %ebx
	movl	%eax, (%esp)
	call	_g_object_new
	movl	%eax, -24(%ebp)
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC189, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_title
	call	_gtk_dialog_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%eax, %esi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 20(%esp)
	movl	$LC181, %ecx
	movl	$-6, %edx
	movl	%ecx, 12(%esp)
	movl	$LC182, %edi
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_dialog_add_buttons
	call	_gtk_file_filter_new
	movl	$LC190, (%esp)
	movl	%eax, %ebx
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esp)
	movl	%eax, %edi
	movl	%ebx, (%esp)
	call	_gtk_file_filter_set_name
	movl	%edi, 4(%esp)
	movl	%ebx, (%esp)
	call	_gtk_file_filter_add_pattern
	call	_gtk_file_chooser_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	movl	$-5, %ebx
	call	_gtk_file_chooser_add_filter
	movl	%edi, (%esp)
	movl	$_saveImage, %edi
	call	_g_free
	movl	%esi, 4(%esp)
	movl	-24(%ebp), %eax
	movl	$LC183, %esi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_dialog_set_default_response
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%eax, %ebx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 12(%esp)
	movl	-24(%ebp), %eax
	xorl	%ecx, %ecx
	movl	%ecx, 20(%esp)
	xorl	%edx, %edx
	movl	%edx, 16(%esp)
	movl	%edi, 8(%esp)
	movl	$LC191, %edi
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%ebx, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 12(%esp)
	movl	$_gtk_widget_destroy, %eax
	xorl	%ecx, %ecx
	movl	%eax, 8(%esp)
	movl	$LC183, %eax
	xorl	%edx, %edx
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	-24(%ebp), %edx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-20(%ebp), %edx
	movl	%edi, 4(%esp)
	movl	$LC192, %edi
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	cld
	movl	-20(%ebp), %esi
	movl	$5, %ecx
	repe
	cmpsb
	jne	L404
	movl	$LC193, (%esp)
	call	_g_strdup_printf
L407:
	movl	%eax, %edi
	call	_gtk_file_chooser_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	$80, %esi
	movl	$LC195, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_file_chooser_set_current_name
	movl	%edi, (%esp)
	call	_g_free
	movl	%esi, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-16(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_window_set_modal
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	call	_get_parent_window
	testl	%eax, %eax
	je	L403
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 4(%esp)
	movl	%eax, %ebx
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_transient_for
L403:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L404:
	movl	$LC194, (%esp)
	movl	-20(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_strdup_printf
	jmp	L407
	.p2align 4,,15
	.def	_force_expose;	.scl	3;	.type	32;	.endef
_force_expose:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$4, %esp
	movl	%eax, %ebx
	movl	%eax, (%esp)
	call	_gtk_widget_hide
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	jmp	L409
	.p2align 4,,7
L411:
	call	_gtk_main_iteration
L409:
	call	_gtk_events_pending
	testl	%eax, %eax
	jne	L411
	popl	%eax
	popl	%ebx
	popl	%ebp
	ret
	.section .rdata,"dr"
LC196:
	.ascii "Export Contours plot\0"
LC197:
	.ascii "gabeditExport.%s\0"
	.text
	.p2align 4,,15
	.def	_exportImageDlg;	.scl	3;	.type	32;	.endef
_exportImageDlg:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$LC178, %edi
	pushl	%esi
	movl	$LC179, %esi
	pushl	%ebx
	subl	$60, %esp
	xorl	%ebx, %ebx
	movl	%edx, -20(%ebp)
	movl	%eax, -16(%ebp)
	call	_gtk_file_chooser_dialog_get_type
	movl	%ebx, 28(%esp)
	xorl	%ecx, %ecx
	movl	$LC177, %edx
	movl	%ecx, 24(%esp)
	movl	$1, %ebx
	movl	$LC180, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	xorl	%esi, %esi
	movl	%ebx, 8(%esp)
	movl	$-5, %ebx
	movl	%eax, (%esp)
	call	_g_object_new
	movl	%eax, %edi
	call	_gtk_window_get_type
	movl	%eax, -24(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC196, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_title
	call	_gtk_dialog_get_type
	movl	%eax, -28(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	movl	$LC181, %ecx
	movl	$-6, %edx
	movl	%ecx, 12(%esp)
	movl	$LC182, %esi
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_dialog_add_buttons
	call	_gtk_file_filter_new
	movl	$LC190, (%esp)
	movl	%eax, %esi
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_gtk_file_filter_set_name
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	call	_gtk_file_filter_add_pattern
	call	_gtk_file_chooser_get_type
	movl	%eax, -32(%ebp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	movl	$LC183, %esi
	call	_gtk_file_chooser_add_filter
	movl	%ebx, (%esp)
	movl	$-5, %ebx
	call	_g_free
	movl	%edi, (%esp)
	movl	-28(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_dialog_set_default_response
	call	_gtk_object_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 12(%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	$_exportImage, %eax
	movl	%edx, 16(%esp)
	movl	%esi, 4(%esp)
	movl	$LC191, %esi
	movl	%eax, 8(%esp)
	movl	%edi, (%esp)
	call	_g_signal_connect_data
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 12(%esp)
	movl	$_gtk_widget_destroy, %eax
	xorl	%ecx, %ecx
	movl	%eax, 8(%esp)
	xorl	%edx, %edx
	movl	$LC183, %eax
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_signal_connect_data
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-20(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$LC197, (%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_strdup_printf
	movl	%edi, (%esp)
	movl	-32(%ebp), %edx
	movl	%eax, %ebx
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_file_chooser_set_current_name
	movl	%ebx, (%esp)
	movl	$80, %ebx
	call	_g_free
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-16(%ebp), %edx
	movl	$LC195, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	%edi, (%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_modal
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	call	_get_parent_window
	testl	%eax, %eax
	je	L412
	movl	%eax, (%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	%eax, %ebx
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_transient_for
L412:
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_evaluate_formula;	.scl	3;	.type	32;	.endef
_evaluate_formula:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	%eax, %esi
	movl	$47, %eax
	pushl	%ebx
	subl	$32, %esp
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_strchr
	testl	%eax, %eax
	movl	%eax, %ebx
	je	L415
	cmpb	$0, 1(%eax)
	jne	L419
L415:
	movl	%esi, (%esp)
	movl	$42, %eax
	movl	%eax, 4(%esp)
	call	_strchr
	testl	%eax, %eax
	movl	%eax, %ebx
	je	L417
	cmpb	$0, 1(%eax)
	jne	L420
L417:
	movl	%esi, (%esp)
	call	_atof
	addl	$32, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L420:
	movl	%esi, (%esp)
	call	_atof
	leal	1(%ebx), %eax
	fstpl	-24(%ebp)
	movl	%eax, (%esp)
	call	_atof
	fmull	-24(%ebp)
	addl	$32, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.p2align 4,,7
L419:
	movl	%esi, (%esp)
	call	_atof
	leal	1(%ebx), %eax
	fstpl	-16(%ebp)
	movl	%eax, (%esp)
	call	_atof
	fdivrl	-16(%ebp)
	addl	$32, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC201:
	.ascii "Set data options\0"
LC202:
	.ascii "delete_event\0"
LC203:
	.ascii "Set line type\0"
LC204:
	.ascii "Line width :\0"
LC208:
	.ascii "SpinLineWidth\0"
LC209:
	.ascii "Line type :\0"
LC210:
	.ascii "Solid\0"
LC211:
	.ascii "On-Off dashed\0"
LC212:
	.ascii "Double dashed\0"
LC213:
	.ascii "text\0"
LC214:
	.ascii "ComboLineType\0"
LC215:
	.ascii "Line color :\0"
LC216:
	.ascii "ColorButton\0"
LC217:
	.ascii "Set point type\0"
LC218:
	.ascii "point size :\0"
LC220:
	.ascii "SpinPointWidth\0"
LC221:
	.ascii "Point type :\0"
LC222:
	.ascii "<span>&#9733;</span>\0"
LC223:
	.ascii "+\0"
LC224:
	.ascii "x\0"
LC225:
	.ascii "<span>&#9675;</span>\0"
LC226:
	.ascii "<span>&#9679;</span>\0"
LC227:
	.ascii "<span>&#9688;</span>\0"
LC228:
	.ascii "<span>&#9689;</span>\0"
LC229:
	.ascii "<span>&#9670;</span>\0"
LC230:
	.ascii "<span>&#9674;</span>\0"
LC231:
	.ascii "<span>&#8226;</span>\0"
LC232:
	.ascii "<span><b>&#9788;</b></span>\0"
LC233:
	.ascii "<span>&#9651;</span>\0"
LC234:
	.ascii "<span>&#9650;</span>\0"
	.data
	.align 4
LC235:
	.long	LC222
	.long	LC223
	.long	LC224
	.long	LC225
	.long	LC226
	.long	LC227
	.long	LC228
	.long	LC229
	.long	LC230
	.long	LC231
	.long	LC232
	.long	LC233
	.long	LC234
	.section .rdata,"dr"
LC236:
	.ascii "markup\0"
LC237:
	.ascii "ComboPointType\0"
LC238:
	.ascii "Point color :\0"
LC239:
	.ascii "CurentContour\0"
LC240:
	.ascii "value-changed\0"
LC241:
	.ascii "color-set\0"
LC242:
	.ascii "changed\0"
LC243:
	.ascii "Scale X : \0"
LC244:
	.ascii "1.0\0"
LC245:
	.ascii "Scale Y : \0"
LC246:
	.ascii "Scale Z : \0"
LC247:
	.ascii "Shift  X : \0"
LC248:
	.ascii "0.0\0"
LC249:
	.ascii "Shift  Y : \0"
LC250:
	.ascii "Shift  Z : \0"
LC251:
	.ascii "Auto ranges all\0"
LC252:
	.ascii "Save\0"
LC253:
	.ascii "Remove\0"
LC254:
	.ascii "clicked\0"
LC255:
	.ascii "Window\0"
LC256:
	.ascii "activate\0"
	.text
	.p2align 4,,15
	.def	_set_data_dialog;	.scl	3;	.type	32;	.endef
_set_data_dialog:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$80, %edi
	pushl	%esi
	movl	$LC201, %esi
	pushl	%ebx
	subl	$252, %esp
	movl	$0, (%esp)
	movl	%edx, -128(%ebp)
	movl	%eax, -124(%ebp)
	call	_gtk_window_new
	movl	%eax, -132(%ebp)
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	call	_gtk_window_set_title
	call	_gtk_container_get_type
	movl	%eax, -176(%ebp)
	movl	-132(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_container_set_border_width
	movl	%ebx, 4(%esp)
	movl	-132(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_modal
	movl	%edi, 4(%esp)
	movl	$LC202, %edi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	movl	-124(%ebp), %esi
	xorl	%ecx, %ecx
	movl	%ecx, 16(%esp)
	movl	$_destroy_data_dialog, %edx
	movl	%edx, 8(%esp)
	movl	%esi, 12(%esp)
	xorl	%esi, %esi
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	$0, (%esp)
	call	_gtk_vbox_new
	movl	%eax, -148(%ebp)
	movl	-176(%ebp), %edi
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-148(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_add
	movl	-148(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	8(%ebp), %ebx
	testl	%ebx, %ebx
	je	L424
	movl	$0, (%esp)
	xorl	%ecx, %ecx
	xorl	%edi, %edi
	movl	%ecx, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, %ebx
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	-148(%ebp), %esi
	movl	%eax, -196(%ebp)
	movl	%esi, (%esp)
	movl	$1, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	%edx, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	$LC203, (%esp)
	call	_gtk_frame_new
	movl	%ebx, (%esp)
	movl	-196(%ebp), %edi
	movl	%eax, %esi
	movl	$2, %ebx
	movl	%edi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, -180(%ebp)
	movl	-176(%ebp), %eax
	movl	%esi, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-180(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_add
	movl	-180(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	$LC204, (%esp)
	call	_gtk_label_new
	movl	%edi, 4(%esp)
	movl	%eax, %esi
	movl	$2, %edi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%edi, 16(%esp)
	xorl	%edi, %edi
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	movl	$1076101120, %esi
	call	_gtk_widget_show
	movl	%edi, 8(%esp)
	fld1
	movl	%esi, 12(%esp)
	fstpl	16(%esp)
	fldz
	fstpl	(%esp)
	call	_gtk_spin_button_new_with_range
	movl	%eax, -184(%ebp)
	call	_gtk_spin_button_get_type
	movl	%eax, 4(%esp)
	movl	-184(%ebp), %esi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	8(%ebp), %edi
	xorl	%ecx, %ecx
	movl	140(%edi), %edx
	pushl	%ecx
	movl	$80, %edi
	pushl	%edx
	fildq	(%esp)
	addl	$8, %esp
	movl	%eax, (%esp)
	fstpl	4(%esp)
	call	_gtk_spin_button_set_value
	movl	%ebx, (%esp)
	movl	-196(%ebp), %eax
	movl	$2, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	%edi, 4(%esp)
	movl	-132(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 8(%esp)
	movl	$LC208, %esi
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_object_set_data
	movl	$LC209, (%esp)
	call	_gtk_label_new
	movl	-180(%ebp), %edi
	movl	%eax, %esi
	movl	-196(%ebp), %ebx
	movl	%edi, (%esp)
	movl	%ebx, 4(%esp)
	movl	$2, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	leal	-40(%ebp), %esi
	call	_gtk_widget_show
	movl	$1, (%esp)
	movl	$64, %eax
	movl	%eax, 4(%esp)
	call	_gtk_tree_store_new
	movl	%esi, 4(%esp)
	movl	%eax, %ebx
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	%ebx, (%esp)
	call	_gtk_tree_store_append
	movl	%esi, 4(%esp)
	movl	$-1, %eax
	movl	%eax, 16(%esp)
	movl	$LC210, %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	%ebx, (%esp)
	call	_gtk_tree_store_set
	movl	%esi, 4(%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 8(%esp)
	movl	%ebx, (%esp)
	call	_gtk_tree_store_append
	movl	%esi, 4(%esp)
	movl	$LC211, %eax
	movl	$-1, %edx
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%edx, 16(%esp)
	movl	%eax, 8(%esp)
	movl	%ebx, (%esp)
	call	_gtk_tree_store_set
	movl	%esi, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	%ebx, (%esp)
	call	_gtk_tree_store_append
	movl	%esi, 4(%esp)
	movl	$-1, %eax
	movl	$1, %esi
	movl	%eax, 16(%esp)
	movl	$LC212, %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	%ebx, (%esp)
	call	_gtk_tree_store_set
	call	_gtk_tree_model_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_gtk_combo_box_new_with_model
	movl	%eax, -200(%ebp)
	movl	%ebx, (%esp)
	movl	$1, %ebx
	call	_g_object_unref
	movl	%edi, (%esp)
	movl	-196(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-200(%ebp), %edx
	movl	$1, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 16(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	call	_gtk_box_pack_start
	call	_gtk_cell_renderer_text_new
	movl	%eax, %esi
	call	_gtk_cell_layout_get_type
	movl	%eax, 4(%esp)
	movl	-200(%ebp), %edi
	movl	%eax, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_cell_layout_pack_start
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC213, %edx
	xorl	%ecx, %ecx
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_cell_layout_set_attributes
	call	_gtk_combo_box_get_type
	movl	%eax, 4(%esp)
	xorl	%esi, %esi
	movl	%eax, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_combo_box_set_active
	movl	8(%ebp), %edx
	movl	168(%edx), %eax
	testl	%eax, %eax
	je	L441
	cmpl	$1, %eax
	je	L442
	cmpl	$2, %eax
	je	L443
L427:
	movl	-200(%ebp), %edi
	movl	$80, %esi
	movl	$LC214, %ebx
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	%esi, 4(%esp)
	movl	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 8(%esp)
	movl	$1, %edi
	movl	%ebx, 4(%esp)
	call	_g_object_set_data
	movl	$LC215, (%esp)
	call	_gtk_label_new
	movl	%eax, %esi
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	-180(%ebp), %edx
	movl	%eax, %ebx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	8(%ebp), %eax
	addl	$156, %eax
	movl	%eax, (%esp)
	call	_gtk_color_button_new_with_color
	movl	%eax, -188(%ebp)
	movl	-180(%ebp), %esi
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	movl	$2, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-188(%ebp), %edi
	xorl	%ecx, %ecx
	movl	%ecx, 12(%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%esi, 16(%esp)
	movl	$LC216, %esi
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 8(%esp)
	movl	$1, %edi
	movl	%esi, 4(%esp)
	call	_g_object_set_data
	movl	$LC217, (%esp)
	call	_gtk_frame_new
	movl	%ebx, 4(%esp)
	movl	-148(%ebp), %edx
	movl	%eax, %esi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%edx, 12(%esp)
	movl	%ecx, 16(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, -180(%ebp)
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-180(%ebp), %esi
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$LC218, (%esp)
	call	_gtk_label_new
	movl	%ebx, 4(%esp)
	movl	-180(%ebp), %edi
	movl	%eax, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	fld1
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$1077805056, %eax
	fstpl	16(%esp)
	fldz
	movl	%eax, 12(%esp)
	fstpl	(%esp)
	call	_gtk_spin_button_new_with_range
	movl	%eax, -192(%ebp)
	call	_gtk_spin_button_get_type
	movl	%eax, 4(%esp)
	movl	-192(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	8(%ebp), %esi
	xorl	%ecx, %ecx
	movl	128(%esi), %edx
	pushl	%ecx
	movl	$2, %esi
	pushl	%edx
	fildq	(%esp)
	addl	$8, %esp
	movl	%eax, (%esp)
	fstpl	4(%esp)
	call	_gtk_spin_button_set_value
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-192(%ebp), %edi
	xorl	%ecx, %ecx
	movl	%ecx, 12(%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%esi, 16(%esp)
	movl	$LC220, %esi
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-132(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_g_object_set_data
	movl	$LC221, (%esp)
	call	_gtk_label_new
	movl	%ebx, 4(%esp)
	movl	-180(%ebp), %edx
	movl	%eax, %esi
	movl	$2, %ebx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	movl	$LC235, %esi
	call	_gtk_widget_show
	cld
	xorl	%eax, %eax
	movl	$13, %ecx
	movl	%eax, -208(%ebp)
	leal	-120(%ebp), %eax
	movl	%eax, %edi
	rep
	movsl
	movl	$1, (%esp)
	movl	$64, %eax
	movl	%eax, 4(%esp)
	call	_gtk_tree_store_new
	movl	%eax, %esi
	movl	8(%ebp), %eax
	movl	-208(%ebp), %ebx
	leal	24(%eax), %edi
	.p2align 4,,15
L435:
	movl	%esi, (%esp)
	xorl	%eax, %eax
	leal	-56(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, 8(%esp)
	call	_gtk_tree_store_append
	movl	%esi, (%esp)
	movl	$-1, %eax
	movl	%eax, 16(%esp)
	movl	-120(%ebp,%ebx,4), %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gtk_tree_store_set
	movl	%edi, 4(%esp)
	movl	-120(%ebp,%ebx,4), %eax
	movl	%eax, (%esp)
	call	_strcmp
	testl	%eax, %eax
	jne	L433
	movl	%ebx, -208(%ebp)
L433:
	incl	%ebx
	cmpl	$13, %ebx
	jb	L435
	call	_gtk_tree_model_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	movl	$1, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%eax, %ebx
	call	_gtk_combo_box_new_with_model
	movl	%eax, -204(%ebp)
	movl	%ebx, (%esp)
	movl	$1, %ebx
	call	_g_object_unref
	call	_gtk_box_get_type
	movl	%eax, -212(%ebp)
	movl	-180(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 12(%esp)
	movl	-204(%ebp), %ebx
	movl	$1, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_box_pack_start
	call	_gtk_cell_renderer_text_new
	movl	%eax, %esi
	call	_gtk_cell_layout_get_type
	movl	%eax, 4(%esp)
	movl	-204(%ebp), %edi
	movl	%eax, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_cell_layout_pack_start
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$LC236, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	$80, %ebx
	movl	%esi, 4(%esp)
	call	_gtk_cell_layout_set_attributes
	movl	%edi, (%esp)
	call	_gtk_widget_show
	call	_gtk_combo_box_get_type
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-208(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_combo_box_set_active
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	%ebx, 4(%esp)
	movl	-132(%ebp), %ebx
	movl	%ebx, (%esp)
	xorl	%ebx, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC237, %ecx
	movl	%ecx, 4(%esp)
	movl	%edi, 8(%esp)
	call	_g_object_set_data
	movl	$LC238, (%esp)
	call	_gtk_label_new
	movl	%eax, %esi
	movl	-212(%ebp), %edi
	movl	-180(%ebp), %eax
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %ecx
	movl	$2, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	movl	$1, %esi
	call	_gtk_widget_show
	movl	8(%ebp), %eax
	addl	$144, %eax
	movl	%eax, (%esp)
	call	_gtk_color_button_new_with_color
	movl	%edi, 4(%esp)
	movl	-180(%ebp), %edx
	movl	%eax, %ebx
	xorl	%edi, %edi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	%edx, 16(%esp)
	movl	%edi, 12(%esp)
	movl	$80, %edi
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	-132(%ebp), %esi
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC216, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 8(%esp)
	call	_g_object_set_data
	movl	%esi, (%esp)
	movl	$LC169, %esi
	call	_gtk_widget_show
	movl	%edi, 4(%esp)
	movl	-184(%ebp), %edi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-128(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	8(%ebp), %esi
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 8(%esp)
	xorl	%esi, %esi
	call	_g_object_set_data
	movl	%edi, (%esp)
	movl	$80, %eax
	xorl	%edi, %edi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 20(%esp)
	movl	-124(%ebp), %edi
	movl	$_spin_line_width_changed_value, %ecx
	movl	%ecx, 8(%esp)
	movl	$LC240, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 16(%esp)
	movl	$LC169, %esi
	movl	%edi, 12(%esp)
	movl	$80, %edi
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%edi, 4(%esp)
	movl	-188(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-128(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	-188(%ebp), %esi
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	8(%ebp), %edi
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	movl	%edi, 8(%esp)
	movl	$80, %edi
	call	_g_object_set_data
	movl	%edi, 4(%esp)
	movl	$_spin_line_color_changed_value, %edi
	movl	%esi, (%esp)
	movl	$LC241, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	-124(%ebp), %edx
	movl	%ecx, 20(%esp)
	movl	%edi, 8(%esp)
	xorl	%edi, %edi
	movl	%edx, 12(%esp)
	movl	%esi, 4(%esp)
	call	_g_signal_connect_data
	movl	-200(%ebp), %esi
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 16(%esp)
	movl	-124(%ebp), %edi
	xorl	%edx, %edx
	movl	%edx, 20(%esp)
	movl	$_combo_line_style_changed_value, %ecx
	movl	$LC242, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edi, 12(%esp)
	movl	$LC169, %edi
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-128(%ebp), %edx
	movl	%edi, 4(%esp)
	movl	$80, %edi
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	%esi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	8(%ebp), %esi
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 8(%esp)
	xorl	%esi, %esi
	call	_g_object_set_data
	movl	%edi, 4(%esp)
	movl	-204(%ebp), %edi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	movl	-124(%ebp), %edx
	xorl	%ecx, %ecx
	movl	%ecx, 16(%esp)
	movl	$LC242, %esi
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	$_combo_point_style_changed_value, %edx
	movl	%edx, 8(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-128(%ebp), %esi
	movl	$LC169, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 8(%esp)
	call	_g_object_set_data
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	8(%ebp), %edi
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	movl	%edi, 8(%esp)
	call	_g_object_set_data
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-192(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 8(%esp)
	movl	$LC169, %esi
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_object_set_data
	movl	-192(%ebp), %edx
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	movl	%edi, 8(%esp)
	xorl	%edi, %edi
	call	_g_object_set_data
	movl	-192(%ebp), %esi
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	xorl	%esi, %esi
	call	_g_type_check_instance_cast
	movl	%edi, 20(%esp)
	movl	-124(%ebp), %edi
	movl	$_spin_point_size_changed_value, %ecx
	movl	%ecx, 8(%esp)
	movl	$LC240, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 16(%esp)
	movl	$LC169, %esi
	movl	%edi, 12(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%ebx, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-128(%ebp), %edx
	movl	%esi, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	%ebx, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	8(%ebp), %esi
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 8(%esp)
	movl	$80, %esi
	call	_g_object_set_data
	movl	%esi, 4(%esp)
	movl	$_spin_point_color_changed_value, %esi
	movl	%ebx, (%esp)
	movl	$LC241, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_g_signal_connect_data
L424:
	movl	$0, (%esp)
	call	_gtk_frame_new
	movl	%eax, %esi
	call	_gtk_box_get_type
	movl	%eax, -216(%ebp)
	movl	-148(%ebp), %edi
	xorl	%ebx, %ebx
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	movl	$1, %edi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%edx, 12(%esp)
	movl	%ecx, 16(%esp)
	movl	%edi, 8(%esp)
	xorl	%edi, %edi
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	%ebx, 4(%esp)
	movl	$0, (%esp)
	call	_gtk_vbox_new
	movl	%eax, %ebx
	call	_gtk_container_get_type
	movl	%eax, -220(%ebp)
	movl	%esi, (%esp)
	movl	$1, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_container_add
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, -136(%ebp)
	movl	-216(%ebp), %eax
	movl	%ebx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	%edx, 16(%esp)
	movl	-136(%ebp), %edx
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-136(%ebp), %esi
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$LC243, (%esp)
	call	_gtk_label_new
	movl	%esi, (%esp)
	movl	%eax, %edi
	movl	-216(%ebp), %eax
	xorl	%esi, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$LC244, %edi
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, -152(%ebp)
	movl	$-1, %ecx
	movl	$50, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_widget_set_size_request
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	-152(%ebp), %edx
	movl	%eax, %esi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_entry_set_text
	movl	-216(%ebp), %edi
	movl	-136(%ebp), %eax
	movl	%edi, 4(%esp)
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%edx, 12(%esp)
	movl	-152(%ebp), %edx
	movl	%ecx, 16(%esp)
	movl	%edi, 8(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-152(%ebp), %edi
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$LC245, (%esp)
	call	_gtk_label_new
	movl	%eax, %edi
	movl	-136(%ebp), %edx
	movl	-216(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %ecx
	xorl	%edx, %edx
	movl	%ecx, 16(%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$50, %edi
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, -156(%ebp)
	movl	$-1, %edx
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_widget_set_size_request
	movl	%esi, 4(%esp)
	movl	-156(%ebp), %edi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC244, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-136(%ebp), %edx
	movl	-216(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	xorl	%edx, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$LC246, (%esp)
	call	_gtk_label_new
	movl	%eax, %edi
	movl	-136(%ebp), %edx
	movl	-216(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %ecx
	xorl	%edx, %edx
	movl	%ecx, 16(%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$50, %edi
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, -160(%ebp)
	movl	$-1, %edx
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_widget_set_size_request
	movl	%esi, 4(%esp)
	movl	-160(%ebp), %edi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC244, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-136(%ebp), %edx
	movl	-216(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	xorl	%edx, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, -136(%ebp)
	movl	-216(%ebp), %edi
	movl	%ebx, (%esp)
	movl	%edi, 4(%esp)
	movl	$2, %edi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-136(%ebp), %edx
	movl	$1, %ecx
	movl	%ecx, 8(%esp)
	xorl	%ebx, %ebx
	movl	%edi, 16(%esp)
	movl	%edx, 4(%esp)
	movl	%ebx, 12(%esp)
	call	_gtk_box_pack_start
	movl	-136(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	$LC247, (%esp)
	call	_gtk_label_new
	movl	%ebx, (%esp)
	movl	%eax, %edi
	movl	-216(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$2, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	$LC248, %ebx
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$50, %edi
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, -164(%ebp)
	movl	$-1, %edx
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_widget_set_size_request
	movl	%esi, 4(%esp)
	movl	-164(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-216(%ebp), %ebx
	movl	-136(%ebp), %edi
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	xorl	%edi, %edi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%edx, 12(%esp)
	movl	-164(%ebp), %edx
	movl	%ecx, 16(%esp)
	movl	%edi, 8(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-164(%ebp), %ebx
	movl	%ebx, (%esp)
	movl	$2, %ebx
	call	_gtk_widget_show
	movl	$LC249, (%esp)
	call	_gtk_label_new
	movl	%eax, %edi
	movl	-136(%ebp), %edx
	movl	-216(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	movl	%ebx, 16(%esp)
	movl	$50, %ebx
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$-1, %edi
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, -168(%ebp)
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_widget_set_size_request
	movl	%esi, 4(%esp)
	movl	-168(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC248, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_entry_set_text
	movl	-216(%ebp), %edi
	movl	-136(%ebp), %eax
	movl	%edi, 4(%esp)
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$2, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	$LC250, (%esp)
	call	_gtk_label_new
	movl	-136(%ebp), %ebx
	movl	%eax, %edi
	movl	-216(%ebp), %edx
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	xorl	%edx, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$LC248, %edi
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, -172(%ebp)
	movl	$-1, %ecx
	movl	$50, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_widget_set_size_request
	movl	%esi, 4(%esp)
	movl	-172(%ebp), %esi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_entry_set_text
	movl	%ebx, (%esp)
	movl	-216(%ebp), %edi
	movl	$2, %ebx
	movl	%edi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	$2, %ebx
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	call	_gtk_frame_new
	movl	%edi, 4(%esp)
	movl	%eax, %esi
	movl	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, -136(%ebp)
	movl	-220(%ebp), %edx
	movl	%esi, (%esp)
	movl	$4, %esi
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-136(%ebp), %ebx
	movl	%ebx, 4(%esp)
	call	_gtk_container_add
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	$LC53, (%esp)
	call	_gtk_button_new_with_label
	movl	%eax, -140(%ebp)
	movl	%edi, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 16(%esp)
	movl	-140(%ebp), %esi
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	$1, %ecx
	movl	%ecx, 12(%esp)
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	movl	$4, %esi
	call	_gtk_widget_show
	movl	$LC251, (%esp)
	call	_gtk_button_new_with_label
	movl	%eax, -144(%ebp)
	movl	%edi, 4(%esp)
	movl	%ebx, (%esp)
	movl	$1, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-144(%ebp), %edi
	movl	$1, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 16(%esp)
	movl	$1, %esi
	movl	%ebx, 12(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$1, %edi
	call	_gtk_widget_show
	movl	$LC252, (%esp)
	call	_gtk_button_new_with_label
	movl	%eax, %ebx
	movl	-136(%ebp), %edx
	movl	-216(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$4, %edx
	movl	%edx, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	$LC253, (%esp)
	call	_gtk_button_new_with_label
	movl	%eax, %esi
	movl	-216(%ebp), %edi
	movl	-136(%ebp), %eax
	movl	%edi, 4(%esp)
	movl	$1, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$4, %ecx
	movl	$1, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	-132(%ebp), %edx
	movl	%edx, (%esp)
	call	_gtk_widget_show
	movl	%ebx, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-128(%ebp), %edi
	movl	$LC169, %edx
	movl	%edx, 4(%esp)
	movl	%edi, 8(%esp)
	call	_g_object_set_data
	movl	%ebx, (%esp)
	movl	$80, %eax
	xorl	%ebx, %ebx
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 20(%esp)
	movl	-124(%ebp), %edx
	xorl	%ecx, %ecx
	movl	%ecx, 16(%esp)
	movl	$LC254, %ebx
	movl	%ebx, 4(%esp)
	movl	%edx, 12(%esp)
	movl	$_save_data_dlg, %edx
	movl	%edx, 8(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 8(%esp)
	movl	$LC169, %edx
	movl	$80, %edi
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_object_set_data
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-132(%ebp), %ebx
	movl	%ebx, 8(%esp)
	movl	$LC255, %ebx
	movl	%ebx, 4(%esp)
	movl	$80, %ebx
	call	_g_object_set_data
	movl	%esi, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-124(%ebp), %edi
	movl	$LC195, %edx
	movl	%edx, 4(%esp)
	movl	%edi, 8(%esp)
	call	_g_object_set_data
	movl	%ebx, 4(%esp)
	movl	$LC254, %ebx
	movl	%esi, (%esp)
	movl	$_remove_data_dlg, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	%ecx, 20(%esp)
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	$80, %esi
	movl	%ebx, 4(%esp)
	call	_g_signal_connect_data
	movl	-140(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-128(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$LC169, %edx
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	movl	%esi, 4(%esp)
	movl	-140(%ebp), %ebx
	movl	$LC254, %esi
	movl	%ebx, (%esp)
	xorl	%ebx, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$_auto_range_activate, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 20(%esp)
	movl	$80, %ebx
	movl	%edi, 12(%esp)
	movl	%esi, 4(%esp)
	call	_g_signal_connect_data
	movl	%ebx, 4(%esp)
	movl	-144(%ebp), %esi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$LC169, %edx
	movl	%ecx, 8(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	movl	%esi, (%esp)
	movl	$80, %eax
	movl	$80, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 12(%esp)
	xorl	%ecx, %ecx
	movl	$_auto_range_activate, %edx
	movl	%ecx, 16(%esp)
	movl	$LC254, %edi
	movl	%edx, 8(%esp)
	movl	%ebx, 20(%esp)
	movl	$LC169, %ebx
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	-152(%ebp), %edi
	movl	%edi, (%esp)
	movl	$80, %edi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-128(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	movl	-156(%ebp), %ebx
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%ebx, (%esp)
	movl	$LC169, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-128(%ebp), %esi
	movl	$LC169, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 8(%esp)
	call	_g_object_set_data
	movl	%edi, 4(%esp)
	movl	-164(%ebp), %edi
	movl	%edi, (%esp)
	movl	$80, %edi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	call	_g_object_set_data
	movl	-168(%ebp), %eax
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC169, %edx
	movl	%esi, 8(%esp)
	xorl	%esi, %esi
	movl	%edx, 4(%esp)
	call	_g_object_set_data
	movl	%edi, 4(%esp)
	movl	-152(%ebp), %edx
	xorl	%edi, %edi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 16(%esp)
	movl	-124(%ebp), %ebx
	movl	$_activate_entry_scale_x, %ecx
	movl	%ecx, 8(%esp)
	movl	$LC256, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 12(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	-156(%ebp), %esi
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	xorl	%esi, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_activate_entry_scale_y, %ecx
	movl	$LC256, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	xorl	%esi, %esi
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	movl	-160(%ebp), %edi
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	xorl	%edi, %edi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_activate_entry_scale_z, %ecx
	movl	$LC256, %edx
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
	movl	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_activate_entry_shift_x, %ecx
	movl	$LC256, %edx
	movl	%ecx, 8(%esp)
	movl	%edi, 20(%esp)
	xorl	%edi, %edi
	movl	%esi, 16(%esp)
	xorl	%esi, %esi
	movl	%ebx, 12(%esp)
	movl	%edx, 4(%esp)
	call	_g_signal_connect_data
	movl	-168(%ebp), %edx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$_activate_entry_shift_y, %ecx
	movl	$LC256, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%edi, 20(%esp)
	movl	$80, %edi
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	call	_g_signal_connect_data
	movl	%edi, 4(%esp)
	movl	-172(%ebp), %ebx
	xorl	%esi, %esi
	movl	%ebx, (%esp)
	xorl	%ebx, %ebx
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	movl	-124(%ebp), %esi
	movl	$_activate_entry_shift_z, %ecx
	movl	%ecx, 8(%esp)
	movl	$LC256, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 16(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	call	_get_parent_window
	testl	%eax, %eax
	movl	%eax, %esi
	je	L422
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
	movl	-132(%ebp), %edi
	movl	%eax, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_window_set_transient_for
L422:
	addl	$252, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L441:
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	xorl	%ecx, %ecx
	movl	%ecx, 4(%esp)
L440:
	movl	%eax, (%esp)
	call	_gtk_combo_box_set_active
	jmp	L427
L442:
	movl	%ebx, 4(%esp)
	movl	-200(%ebp), %ebx
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	$1, %edx
	movl	%edx, 4(%esp)
	jmp	L440
L443:
	movl	%ebx, 4(%esp)
	movl	-200(%ebp), %esi
	movl	$2, %edi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 4(%esp)
	jmp	L440
	.section .rdata,"dr"
LC261:
	.ascii "Type\0"
	.text
	.p2align 4,,15
	.def	_addRadioButtonColorMapToATable;	.scl	3;	.type	32;	.endef
_addRadioButtonColorMapToATable:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	subl	$44, %esp
	testl	%edx, %edx
	movl	%edx, %ebx
	movl	8(%ebp), %edi
	je	L445
	call	_gtk_radio_button_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_radio_button_get_group
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
L447:
	call	_gtk_radio_button_new_with_label
	movl	%eax, %ebx
	call	_gtk_table_get_type
	movl	%eax, 4(%esp)
	movl	$5, %edi
	movl	%esi, (%esp)
	movl	$3, %esi
	call	_g_type_check_instance_cast
	movl	%esi, 36(%esp)
	movl	$5, %edx
	movl	20(%ebp), %esi
	movl	%edx, 28(%esp)
	movl	12(%ebp), %edx
	movl	$3, %ecx
	movl	%ecx, 32(%esp)
	incl	%edx
	movl	%edx, 20(%esp)
	movl	12(%ebp), %edx
	movl	%edi, 24(%esp)
	movl	$LC261, %edi
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	addl	%esi, %edx
	movl	%edx, 12(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	call	_gtk_table_attach
	movl	%ebx, (%esp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	%edi, 4(%esp)
	movl	%edx, 8(%esp)
	call	_g_object_set_data
	addl	$44, %esp
	movl	%ebx, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L445:
	movl	%edi, 4(%esp)
	movl	$0, (%esp)
	jmp	L447
	.p2align 4,,15
	.def	_add_widget;	.scl	3;	.type	32;	.endef
_add_widget:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	movl	16(%ebp), %eax
	movl	12(%ebp), %esi
	movl	%eax, -16(%ebp)
	call	_gtk_toolbar_get_type
	testl	%esi, %esi
	je	L450
	movl	(%esi), %edx
	testl	%edx, %edx
	jne	L457
L450:
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L448
L455:
	call	_gtk_handle_box_new
	movl	%eax, (%esp)
	movl	%eax, %edi
	call	_g_object_ref
	call	_gtk_handle_box_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_handle_box_set_handle_position
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	%edx, 4(%esp)
	call	_gtk_handle_box_set_shadow_type
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	call	_gtk_toolbar_get_type
	testl	%esi, %esi
	je	L453
	movl	(%esi), %edx
	testl	%edx, %edx
	je	L453
	cmpl	%eax, (%edx)
	je	L456
	.p2align 4,,15
L453:
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L456
L452:
	movl	%esi, (%esp)
	call	_gtk_widget_show
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%edi, 8(%ebp)
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_show
	.p2align 4,,7
L457:
	cmpl	%eax, (%edx)
	je	L455
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L455
	.p2align 4,,15
L448:
	addl	$28, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L456:
	call	_gtk_toolbar_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %ebx
	movl	$1, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_gtk_toolbar_set_show_arrow
	movl	%ebx, (%esp)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	call	_gtk_toolbar_set_style
	movl	%ebx, (%esp)
	movl	$1, %eax
	movl	%eax, 4(%esp)
	call	_gtk_toolbar_set_orientation
	jmp	L452
.lcomm contoursplot_type.32,16
	.section .rdata,"dr"
	.align 32
contoursplot_info.33:
	.word	364
	.space 2
	.long	0
	.long	0
	.long	_gabedit_contoursplot_class_init
	.long	0
	.long	0
	.word	560
	.word	0
	.long	_gabedit_contoursplot_init
	.space 4
LC262:
	.ascii "GabeditContoursPlot\0"
	.text
	.p2align 4,,15
.globl _gabedit_contoursplot_get_type
	.def	_gabedit_contoursplot_get_type;	.scl	2;	.type	32;	.endef
_gabedit_contoursplot_get_type:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	contoursplot_type.32, %eax
	testl	%eax, %eax
	je	L460
	leave
	ret
	.p2align 4,,7
L460:
	call	_gtk_widget_get_type
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$contoursplot_info.33, %ecx
	movl	%edx, 12(%esp)
	movl	$LC262, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_g_type_register_static
	movl	%eax, contoursplot_type.32
	leave
	ret
	.section .rdata,"dr"
	.align 4
__PRETTY_FUNCTION__.29:
	.ascii "gabedit_contoursplot_get_range\0"
	.align 4
LC264:
	.ascii "GABEDIT_IS_ContoursPLOT (contoursplot)\0"
LC263:
	.ascii "contoursplot != NULL\0"
	.text
	.p2align 4,,15
.globl _gabedit_contoursplot_get_range
	.def	_gabedit_contoursplot_get_range;	.scl	2;	.type	32;	.endef
_gabedit_contoursplot_get_range:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ebx, -12(%ebp)
	movl	20(%ebp), %eax
	movl	8(%ebp), %ebx
	movl	%esi, -8(%ebp)
	movl	12(%ebp), %esi
	testl	%ebx, %ebx
	movl	%eax, -16(%ebp)
	movl	24(%ebp), %eax
	movl	%edi, -4(%ebp)
	movl	16(%ebp), %edi
	movl	%eax, -20(%ebp)
	je	L481
	call	_gabedit_contoursplot_get_type
	movl	(%ebx), %edx
	testl	%edx, %edx
	jne	L482
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L483
L477:
	testl	%esi, %esi
	je	L472
	fldl	64(%ebx)
	fstpl	(%esi)
L472:
	testl	%edi, %edi
	je	L473
	fldl	72(%ebx)
	fstpl	(%edi)
L473:
	movl	-20(%ebp), %esi
	testl	%esi, %esi
	je	L474
	fldl	88(%ebx)
	movl	-20(%ebp), %eax
	fstpl	(%eax)
L474:
	movl	-16(%ebp), %ecx
	testl	%ecx, %ecx
	je	L461
	fldl	80(%ebx)
	movl	-16(%ebp), %eax
	fstpl	(%eax)
L461:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L482:
	cmpl	%eax, (%edx)
	je	L477
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L477
	.p2align 4,,15
L483:
	movl	$LC264, 16(%ebp)
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	$__PRETTY_FUNCTION__.29, 12(%ebp)
	movl	-4(%ebp), %edi
	movl	$0, 8(%ebp)
	movl	%ebp, %esp
	popl	%ebp
	jmp	_g_return_if_fail_warning
	.p2align 4,,7
L481:
	movl	$LC263, 16(%ebp)
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	$__PRETTY_FUNCTION__.29, 12(%ebp)
	movl	-4(%ebp), %edi
	movl	$0, 8(%ebp)
	movl	%ebp, %esp
	popl	%ebp
	jmp	_g_return_if_fail_warning
	.section .rdata,"dr"
	.align 4
__PRETTY_FUNCTION__.43:
	.ascii "spin_point_color_changed_value\0"
	.text
	.p2align 4,,15
	.def	_spin_point_color_changed_value;	.scl	3;	.type	32;	.endef
_spin_point_color_changed_value:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	%ebx, -12(%ebp)
	movl	12(%ebp), %ebx
	movl	%edi, -4(%ebp)
	movl	8(%ebp), %edi
	testl	%ebx, %ebx
	movl	%esi, -8(%ebp)
	je	L486
	movl	(%ebx), %eax
	testl	%eax, %eax
	jne	L500
L488:
	movl	%ebx, (%esp)
	movl	$80, %esi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L486
L497:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%eax, %esi
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	call	_gabedit_contoursplot_get_type
	testl	%esi, %esi
	je	L492
	movl	(%esi), %edx
	testl	%edx, %edx
	jne	L501
L492:
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L502
L498:
	movl	%edi, (%esp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gtk_color_button_get_color
	testl	%ebx, %ebx
	je	L496
	movl	-40(%ebp), %eax
	movl	%eax, 144(%ebx)
	movl	-36(%ebp), %eax
	movl	%eax, 148(%ebx)
	movl	-32(%ebp), %eax
	movl	%eax, 152(%ebx)
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, %edx
	call	_contoursplot_build_points_contour
L496:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_widget_queue_draw
L486:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L500:
	cmpl	$80, (%eax)
	jne	L488
	jmp	L497
	.p2align 4,,7
L501:
	cmpl	%eax, (%edx)
	je	L498
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L498
	.p2align 4,,15
L502:
	movl	$0, (%esp)
	movl	$LC264, %eax
	movl	$__PRETTY_FUNCTION__.43, %edi
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	_g_return_if_fail_warning
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.section .rdata,"dr"
__PRETTY_FUNCTION__.44:
	.ascii "spin_point_size_changed_value\0"
	.text
	.p2align 4,,15
	.def	_spin_point_size_changed_value;	.scl	3;	.type	32;	.endef
_spin_point_size_changed_value:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	%ebx, -12(%ebp)
	movl	12(%ebp), %ebx
	movl	%edi, -4(%ebp)
	movl	8(%ebp), %edi
	testl	%ebx, %ebx
	movl	%esi, -8(%ebp)
	je	L522
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L523
	cmpl	$80, (%eax)
	je	L514
	movl	%ebx, (%esp)
	movl	$80, %esi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L522
	.p2align 4,,15
L514:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%eax, %ebx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %esi
	call	_gabedit_contoursplot_get_type
	testl	%ebx, %ebx
	je	L509
	movl	(%ebx), %edx
	testl	%edx, %edx
	jne	L518
L509:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L519
L515:
	testl	%esi, %esi
	je	L513
	movl	%edi, (%esp)
	call	_gtk_spin_button_get_value
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -20(%ebp)
	fldcw	-20(%ebp)
	fistpq	-32(%ebp)
	fldcw	-18(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 128(%esi)
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, %edx
	call	_contoursplot_build_points_contour
L513:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 8(%ebp)
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	jmp	_gtk_widget_queue_draw
	.p2align 4,,7
L523:
	movl	%ebx, (%esp)
	movl	$80, %esi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L514
L522:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L518:
	cmpl	%eax, (%edx)
	je	L515
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L515
	.p2align 4,,15
L519:
	movl	$0, (%esp)
	movl	$LC264, %eax
	movl	$__PRETTY_FUNCTION__.44, %edi
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	_g_return_if_fail_warning
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.section .rdata,"dr"
	.align 32
__PRETTY_FUNCTION__.45:
	.ascii "combo_point_style_changed_value\0"
	.text
	.p2align 4,,15
	.def	_combo_point_style_changed_value;	.scl	3;	.type	32;	.endef
_combo_point_style_changed_value:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	movl	%ebx, -12(%ebp)
	movl	8(%ebp), %ebx
	movl	%edi, -4(%ebp)
	leal	-40(%ebp), %edi
	movl	%esi, -8(%ebp)
	movl	$0, -44(%ebp)
	movl	%edi, 4(%esp)
	movl	%ebx, (%esp)
	call	_gtk_combo_box_get_active_iter
	testl	%eax, %eax
	jne	L536
L524:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L536:
	movl	%ebx, (%esp)
	call	_gtk_combo_box_get_model
	movl	%eax, -48(%ebp)
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, (%esp)
	movl	$80, %ecx
	movl	%eax, %esi
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	call	_gabedit_contoursplot_get_type
	testl	%esi, %esi
	je	L528
	movl	(%esi), %edx
	testl	%edx, %edx
	jne	L537
L528:
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L538
L534:
	movl	%edi, 4(%esp)
	movl	$-1, %eax
	movl	%eax, 16(%esp)
	leal	-44(%ebp), %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_tree_model_get
	movl	-44(%ebp), %eax
	testl	%eax, %eax
	je	L524
	testl	%ebx, %ebx
	je	L533
	movl	%eax, 4(%esp)
	leal	24(%ebx), %eax
	movl	%eax, (%esp)
	call	_sprintf
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, %edx
	call	_contoursplot_build_points_contour
L533:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_widget_queue_draw
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L537:
	cmpl	%eax, (%edx)
	jne	L528
	jmp	L534
L538:
	movl	$0, (%esp)
	movl	$LC264, %eax
	movl	%eax, 8(%esp)
	movl	$__PRETTY_FUNCTION__.45, %eax
	movl	%eax, 4(%esp)
	call	_g_return_if_fail_warning
	jmp	L524
	.section .rdata,"dr"
	.align 4
__PRETTY_FUNCTION__.46:
	.ascii "combo_line_style_changed_value\0"
	.text
	.p2align 4,,15
	.def	_combo_line_style_changed_value;	.scl	3;	.type	32;	.endef
_combo_line_style_changed_value:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$104, %esp
	movl	%esi, -8(%ebp)
	movl	8(%ebp), %esi
	movl	%edi, -4(%ebp)
	leal	-40(%ebp), %edi
	movl	%ebx, -12(%ebp)
	movl	$0, -44(%ebp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	_gtk_combo_box_get_active_iter
	testl	%eax, %eax
	jne	L556
L539:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L556:
	movl	%esi, (%esp)
	call	_gtk_combo_box_get_model
	movl	%eax, -48(%ebp)
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, (%esp)
	movl	$80, %ecx
	movl	%eax, %ebx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, -52(%ebp)
	call	_gabedit_contoursplot_get_type
	testl	%ebx, %ebx
	je	L543
	movl	(%ebx), %edx
	testl	%edx, %edx
	jne	L557
L543:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L558
L554:
	movl	%edi, 4(%esp)
	movl	$-1, %eax
	movl	%eax, 16(%esp)
	leal	-44(%ebp), %eax
	movl	%eax, 12(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_tree_model_get
	movl	-44(%ebp), %ecx
	testl	%ecx, %ecx
	movl	%ecx, -60(%ebp)
	je	L539
	movl	-52(%ebp), %esi
	testl	%esi, %esi
	je	L548
	cld
	movl	$6, %eax
	movl	%ecx, %esi
	movl	$LC210, %edi
	movl	%eax, %ecx
	repe
	cmpsb
	je	L559
	cld
	movl	-60(%ebp), %esi
	movl	$14, %eax
	movl	$LC211, %edi
	movl	%eax, %ecx
	repe
	cmpsb
	jne	L551
	movl	-52(%ebp), %eax
	movl	$1, %edi
	movl	%edi, 168(%eax)
	.p2align 4,,15
L548:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_widget_queue_draw
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L557:
	cmpl	%eax, (%edx)
	jne	L543
	jmp	L554
L558:
	movl	$0, (%esp)
	movl	$LC264, %eax
	movl	%eax, 8(%esp)
	movl	$__PRETTY_FUNCTION__.46, %eax
	movl	%eax, 4(%esp)
	call	_g_return_if_fail_warning
	jmp	L539
L559:
	movl	-52(%ebp), %eax
	xorl	%edx, %edx
	movl	%edx, 168(%eax)
	jmp	L548
L551:
	cld
	movl	-60(%ebp), %esi
	movl	$14, %eax
	movl	$LC212, %edi
	movl	%eax, %ecx
	repe
	cmpsb
	jne	L548
	movl	-52(%ebp), %eax
	movl	$2, %esi
	movl	%esi, 168(%eax)
	jmp	L548
	.section .rdata,"dr"
__PRETTY_FUNCTION__.47:
	.ascii "spin_line_color_changed_value\0"
	.text
	.p2align 4,,15
	.def	_spin_line_color_changed_value;	.scl	3;	.type	32;	.endef
_spin_line_color_changed_value:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	%ebx, -12(%ebp)
	movl	12(%ebp), %ebx
	movl	%edi, -4(%ebp)
	movl	8(%ebp), %edi
	testl	%ebx, %ebx
	movl	%esi, -8(%ebp)
	je	L560
	movl	(%ebx), %eax
	testl	%eax, %eax
	jne	L574
L562:
	movl	%ebx, (%esp)
	movl	$80, %esi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L560
L571:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%eax, %esi
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%edi, (%esp)
	movl	%eax, %ebx
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_gtk_color_button_get_color
	call	_gabedit_contoursplot_get_type
	testl	%esi, %esi
	je	L566
	movl	(%esi), %edx
	testl	%edx, %edx
	jne	L575
L566:
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L576
L572:
	testl	%ebx, %ebx
	je	L570
	movl	-40(%ebp), %eax
	movl	%eax, 156(%ebx)
	movl	-36(%ebp), %eax
	movl	%eax, 160(%ebx)
	movl	-32(%ebp), %eax
	movl	%eax, 164(%ebx)
L570:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_widget_queue_draw
L560:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L574:
	cmpl	$80, (%eax)
	jne	L562
	jmp	L571
	.p2align 4,,7
L575:
	cmpl	%eax, (%edx)
	je	L572
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L572
	.p2align 4,,15
L576:
	movl	$0, (%esp)
	movl	$LC264, %esi
	movl	$__PRETTY_FUNCTION__.47, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_g_return_if_fail_warning
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.section .rdata,"dr"
__PRETTY_FUNCTION__.48:
	.ascii "spin_line_width_changed_value\0"
	.text
	.p2align 4,,15
	.def	_spin_line_width_changed_value;	.scl	3;	.type	32;	.endef
_spin_line_width_changed_value:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	%ebx, -12(%ebp)
	movl	12(%ebp), %ebx
	movl	%edi, -4(%ebp)
	movl	8(%ebp), %edi
	testl	%ebx, %ebx
	movl	%esi, -8(%ebp)
	je	L596
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L597
	cmpl	$80, (%eax)
	je	L588
	movl	%ebx, (%esp)
	movl	$80, %esi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L596
	.p2align 4,,15
L588:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, (%esp)
	movl	$80, %ecx
	movl	%eax, %ebx
	movl	%ecx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC239, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %esi
	call	_gabedit_contoursplot_get_type
	testl	%ebx, %ebx
	je	L583
	movl	(%ebx), %edx
	testl	%edx, %edx
	jne	L592
L583:
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L593
L589:
	testl	%esi, %esi
	je	L587
	movl	%edi, (%esp)
	call	_gtk_spin_button_get_value
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -20(%ebp)
	fldcw	-20(%ebp)
	fistpq	-32(%ebp)
	fldcw	-18(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 140(%esi)
L587:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 8(%ebp)
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	jmp	_gtk_widget_queue_draw
	.p2align 4,,7
L597:
	movl	%ebx, (%esp)
	movl	$80, %esi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L588
L596:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L592:
	cmpl	%eax, (%edx)
	je	L589
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L589
	.p2align 4,,15
L593:
	movl	$0, (%esp)
	movl	$LC264, %eax
	movl	$__PRETTY_FUNCTION__.48, %edi
	movl	%edi, 4(%esp)
	movl	%eax, 8(%esp)
	call	_g_return_if_fail_warning
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.section .rdata,"dr"
__PRETTY_FUNCTION__.50:
	.ascii "activate_entry_shift_y\0"
	.text
	.p2align 4,,15
	.def	_activate_entry_shift_y;	.scl	3;	.type	32;	.endef
_activate_entry_shift_y:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	movl	12(%ebp), %ebx
	movl	8(%ebp), %eax
	testl	%ebx, %ebx
	movl	%eax, -20(%ebp)
	je	L649
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L650
	cmpl	$80, (%eax)
	je	L640
	movl	%ebx, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L649
L640:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	$LC169, %edi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -24(%ebp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	call	_gabedit_contoursplot_get_type
	movl	-24(%ebp), %esi
	testl	%esi, %esi
	je	L604
	movl	-24(%ebp), %ecx
	movl	(%ecx), %edx
	testl	%edx, %edx
	jne	L645
L604:
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L646
L641:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	testl	%eax, %eax
	je	L649
	call	_evaluate_formula
	testl	%ebx, %ebx
	fstl	-32(%ebp)
	je	L609
	faddl	32(%ebx)
	movl	64(%ebx), %edx
	cmpl	$0, %edx
	fstpl	32(%ebx)
	fldl	-32(%ebp)
	faddl	40(%ebx)
	fstpl	40(%ebx)
	jle	L618
	movl	68(%ebx), %edi
	xorl	%esi, %esi
	movl	%edx, %ebx
	.p2align 4,,15
L617:
	movl	8(%esi,%edi), %eax
	xorl	%edx, %edx
	cmpl	$0, %eax
	jle	L634
	movl	16(%esi,%edi), %ecx
	.p2align 4,,15
L616:
	fldl	-32(%ebp)
	faddl	(%ecx,%edx,8)
	fstpl	(%ecx,%edx,8)
	incl	%edx
	cmpl	%edx, %eax
	jg	L616
L634:
	addl	$176, %esi
	decl	%ebx
	jne	L617
L618:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	$3, %edi
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC248, %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	call	_gtk_editable_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_editable_set_position
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 8(%ebp)
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_queue_draw
L650:
	movl	%ebx, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L640
L649:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L645:
	cmpl	%eax, (%edx)
	je	L641
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L641
L646:
	movl	$0, (%esp)
	movl	$LC264, %ebx
	movl	$__PRETTY_FUNCTION__.50, %ecx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	call	_g_return_if_fail_warning
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L609:
	fstp	%st(0)
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	432(%eax), %eax
	movl	%eax, (%esp)
	call	_g_list_first
L643:
	movl	%eax, -36(%ebp)
	testl	%eax, %eax
	je	L618
	fldl	-32(%ebp)
	movl	-36(%ebp), %ecx
	movl	(%ecx), %ebx
	faddl	32(%ebx)
	movl	64(%ebx), %edx
	cmpl	$0, %edx
	fstpl	32(%ebx)
	fldl	-32(%ebp)
	faddl	40(%ebx)
	fstpl	40(%ebx)
	jle	L637
	movl	68(%ebx), %edi
	xorl	%esi, %esi
	movl	%edx, %ebx
	.p2align 4,,15
L629:
	movl	8(%esi,%edi), %eax
	xorl	%edx, %edx
	cmpl	$0, %eax
	jle	L639
	movl	16(%esi,%edi), %ecx
	.p2align 4,,15
L628:
	fldl	-32(%ebp)
	faddl	(%ecx,%edx,8)
	fstpl	(%ecx,%edx,8)
	incl	%edx
	cmpl	%edx, %eax
	jg	L628
L639:
	addl	$176, %esi
	decl	%ebx
	jne	L629
L637:
	movl	-36(%ebp), %eax
	movl	4(%eax), %eax
	jmp	L643
	.section .rdata,"dr"
__PRETTY_FUNCTION__.51:
	.ascii "activate_entry_shift_x\0"
	.text
	.p2align 4,,15
	.def	_activate_entry_shift_x;	.scl	3;	.type	32;	.endef
_activate_entry_shift_x:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	movl	12(%ebp), %ebx
	movl	8(%ebp), %eax
	testl	%ebx, %ebx
	movl	%eax, -20(%ebp)
	je	L702
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L703
	cmpl	$80, (%eax)
	je	L693
	movl	%ebx, (%esp)
	movl	$80, %esi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L702
L693:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -24(%ebp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC169, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	call	_gabedit_contoursplot_get_type
	movl	-24(%ebp), %edi
	testl	%edi, %edi
	je	L657
	movl	-24(%ebp), %ecx
	movl	(%ecx), %edx
	testl	%edx, %edx
	jne	L698
L657:
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L699
L694:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	testl	%eax, %eax
	je	L702
	call	_evaluate_formula
	testl	%ebx, %ebx
	fstl	-32(%ebp)
	je	L662
	faddl	16(%ebx)
	movl	64(%ebx), %edx
	cmpl	$0, %edx
	fstpl	16(%ebx)
	fldl	-32(%ebp)
	faddl	24(%ebx)
	fstpl	24(%ebx)
	jle	L671
	movl	68(%ebx), %edi
	xorl	%esi, %esi
	movl	%edx, %ebx
	.p2align 4,,15
L670:
	movl	8(%esi,%edi), %eax
	xorl	%edx, %edx
	cmpl	$0, %eax
	jle	L687
	movl	12(%esi,%edi), %ecx
	.p2align 4,,15
L669:
	fldl	-32(%ebp)
	faddl	(%ecx,%edx,8)
	fstpl	(%ecx,%edx,8)
	incl	%edx
	cmpl	%edx, %eax
	jg	L669
L687:
	addl	$176, %esi
	decl	%ebx
	jne	L670
L671:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC248, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_entry_set_text
	call	_gtk_editable_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$3, %edx
	movl	%edx, 4(%esp)
	call	_gtk_editable_set_position
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 8(%ebp)
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_queue_draw
L703:
	movl	%ebx, (%esp)
	movl	$80, %esi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L693
L702:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L698:
	cmpl	%eax, (%edx)
	je	L694
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L694
L699:
	movl	$0, (%esp)
	movl	$LC264, %esi
	movl	$__PRETTY_FUNCTION__.51, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_g_return_if_fail_warning
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L662:
	fstp	%st(0)
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	432(%eax), %eax
	movl	%eax, (%esp)
	call	_g_list_first
L696:
	movl	%eax, -36(%ebp)
	testl	%eax, %eax
	je	L671
	fldl	-32(%ebp)
	movl	-36(%ebp), %ecx
	movl	(%ecx), %ebx
	faddl	16(%ebx)
	movl	64(%ebx), %edx
	cmpl	$0, %edx
	fstpl	16(%ebx)
	fldl	-32(%ebp)
	faddl	24(%ebx)
	fstpl	24(%ebx)
	jle	L690
	movl	68(%ebx), %edi
	xorl	%esi, %esi
	movl	%edx, %ebx
	.p2align 4,,15
L682:
	movl	8(%esi,%edi), %eax
	xorl	%edx, %edx
	cmpl	$0, %eax
	jle	L692
	movl	12(%esi,%edi), %ecx
	.p2align 4,,15
L681:
	fldl	-32(%ebp)
	faddl	(%ecx,%edx,8)
	fstpl	(%ecx,%edx,8)
	incl	%edx
	cmpl	%edx, %eax
	jg	L681
L692:
	addl	$176, %esi
	decl	%ebx
	jne	L682
L690:
	movl	-36(%ebp), %eax
	movl	4(%eax), %eax
	jmp	L696
	.section .rdata,"dr"
__PRETTY_FUNCTION__.53:
	.ascii "activate_entry_scale_y\0"
	.text
	.p2align 4,,15
	.def	_activate_entry_scale_y;	.scl	3;	.type	32;	.endef
_activate_entry_scale_y:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	movl	12(%ebp), %ebx
	movl	8(%ebp), %eax
	testl	%ebx, %ebx
	movl	%eax, -20(%ebp)
	je	L755
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L756
	cmpl	$80, (%eax)
	je	L746
	movl	%ebx, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L755
L746:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	$LC169, %edi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -24(%ebp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	call	_gabedit_contoursplot_get_type
	movl	-24(%ebp), %esi
	testl	%esi, %esi
	je	L710
	movl	-24(%ebp), %ecx
	movl	(%ecx), %edx
	testl	%edx, %edx
	jne	L751
L710:
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L752
L747:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	testl	%eax, %eax
	je	L755
	call	_evaluate_formula
	testl	%ebx, %ebx
	fstl	-32(%ebp)
	je	L715
	fmull	32(%ebx)
	movl	64(%ebx), %edx
	cmpl	$0, %edx
	fstpl	32(%ebx)
	fldl	-32(%ebp)
	fmull	40(%ebx)
	fstpl	40(%ebx)
	jle	L724
	movl	68(%ebx), %edi
	xorl	%esi, %esi
	movl	%edx, %ebx
	.p2align 4,,15
L723:
	movl	8(%esi,%edi), %eax
	xorl	%edx, %edx
	cmpl	$0, %eax
	jle	L740
	movl	16(%esi,%edi), %ecx
	.p2align 4,,15
L722:
	fldl	-32(%ebp)
	fmull	(%ecx,%edx,8)
	fstpl	(%ecx,%edx,8)
	incl	%edx
	cmpl	%edx, %eax
	jg	L722
L740:
	addl	$176, %esi
	decl	%ebx
	jne	L723
L724:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	$3, %edi
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC244, %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	call	_gtk_editable_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_editable_set_position
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 8(%ebp)
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_queue_draw
L756:
	movl	%ebx, (%esp)
	movl	$80, %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L746
L755:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L751:
	cmpl	%eax, (%edx)
	je	L747
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L747
L752:
	movl	$0, (%esp)
	movl	$LC264, %ebx
	movl	$__PRETTY_FUNCTION__.53, %ecx
	movl	%ebx, 8(%esp)
	movl	%ecx, 4(%esp)
	call	_g_return_if_fail_warning
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L715:
	fstp	%st(0)
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	432(%eax), %eax
	movl	%eax, (%esp)
	call	_g_list_first
L749:
	movl	%eax, -36(%ebp)
	testl	%eax, %eax
	je	L724
	fldl	-32(%ebp)
	movl	-36(%ebp), %ecx
	movl	(%ecx), %ebx
	fmull	32(%ebx)
	movl	64(%ebx), %edx
	cmpl	$0, %edx
	fstpl	32(%ebx)
	fldl	-32(%ebp)
	fmull	40(%ebx)
	fstpl	40(%ebx)
	jle	L743
	movl	68(%ebx), %edi
	xorl	%esi, %esi
	movl	%edx, %ebx
	.p2align 4,,15
L735:
	movl	8(%esi,%edi), %eax
	xorl	%edx, %edx
	cmpl	$0, %eax
	jle	L745
	movl	16(%esi,%edi), %ecx
	.p2align 4,,15
L734:
	fldl	-32(%ebp)
	fmull	(%ecx,%edx,8)
	fstpl	(%ecx,%edx,8)
	incl	%edx
	cmpl	%edx, %eax
	jg	L734
L745:
	addl	$176, %esi
	decl	%ebx
	jne	L735
L743:
	movl	-36(%ebp), %eax
	movl	4(%eax), %eax
	jmp	L749
	.section .rdata,"dr"
__PRETTY_FUNCTION__.54:
	.ascii "activate_entry_scale_x\0"
	.text
	.p2align 4,,15
	.def	_activate_entry_scale_x;	.scl	3;	.type	32;	.endef
_activate_entry_scale_x:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	movl	12(%ebp), %ebx
	movl	8(%ebp), %eax
	testl	%ebx, %ebx
	movl	%eax, -20(%ebp)
	je	L808
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L809
	cmpl	$80, (%eax)
	je	L799
	movl	%ebx, (%esp)
	movl	$80, %esi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L808
L799:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, -24(%ebp)
	movl	$80, %ecx
	movl	%ecx, 4(%esp)
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC169, %edx
	movl	%edx, 4(%esp)
	call	_g_object_get_data
	movl	%eax, %ebx
	call	_gabedit_contoursplot_get_type
	movl	-24(%ebp), %edi
	testl	%edi, %edi
	je	L763
	movl	-24(%ebp), %ecx
	movl	(%ecx), %edx
	testl	%edx, %edx
	jne	L804
L763:
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	je	L805
L800:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_entry_get_text
	testl	%eax, %eax
	je	L808
	call	_evaluate_formula
	testl	%ebx, %ebx
	fstl	-32(%ebp)
	je	L768
	fmull	16(%ebx)
	movl	64(%ebx), %edx
	cmpl	$0, %edx
	fstpl	16(%ebx)
	fldl	-32(%ebp)
	fmull	24(%ebx)
	fstpl	24(%ebx)
	jle	L777
	movl	68(%ebx), %edi
	xorl	%esi, %esi
	movl	%edx, %ebx
	.p2align 4,,15
L776:
	movl	8(%esi,%edi), %eax
	xorl	%edx, %edx
	cmpl	$0, %eax
	jle	L793
	movl	12(%esi,%edi), %ecx
	.p2align 4,,15
L775:
	fldl	-32(%ebp)
	fmull	(%ecx,%edx,8)
	fstpl	(%ecx,%edx,8)
	incl	%edx
	cmpl	%edx, %eax
	jg	L775
L793:
	addl	$176, %esi
	decl	%ebx
	jne	L776
L777:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$LC244, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_entry_set_text
	call	_gtk_editable_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$3, %edx
	movl	%edx, 4(%esp)
	call	_gtk_editable_set_position
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, 8(%ebp)
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	jmp	_gtk_widget_queue_draw
L809:
	movl	%ebx, (%esp)
	movl	$80, %esi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L799
L808:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L804:
	cmpl	%eax, (%edx)
	je	L800
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_is_a
	testl	%eax, %eax
	jne	L800
L805:
	movl	$0, (%esp)
	movl	$LC264, %esi
	movl	$__PRETTY_FUNCTION__.54, %ebx
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_g_return_if_fail_warning
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L768:
	fstp	%st(0)
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	432(%eax), %eax
	movl	%eax, (%esp)
	call	_g_list_first
L802:
	movl	%eax, -36(%ebp)
	testl	%eax, %eax
	je	L777
	fldl	-32(%ebp)
	movl	-36(%ebp), %ecx
	movl	(%ecx), %ebx
	fmull	16(%ebx)
	movl	64(%ebx), %edx
	cmpl	$0, %edx
	fstpl	16(%ebx)
	fldl	-32(%ebp)
	fmull	24(%ebx)
	fstpl	24(%ebx)
	jle	L796
	movl	68(%ebx), %edi
	xorl	%esi, %esi
	movl	%edx, %ebx
	.p2align 4,,15
L788:
	movl	8(%esi,%edi), %eax
	xorl	%edx, %edx
	cmpl	$0, %eax
	jle	L798
	movl	12(%esi,%edi), %ecx
	.p2align 4,,15
L787:
	fldl	-32(%ebp)
	fmull	(%ecx,%edx,8)
	fstpl	(%ecx,%edx,8)
	incl	%edx
	cmpl	%edx, %eax
	jg	L787
L798:
	addl	$176, %esi
	decl	%ebx
	jne	L788
L796:
	movl	-36(%ebp), %eax
	movl	4(%eax), %eax
	jmp	L802
	.section .rdata,"dr"
LC272:
	.ascii "Set ticks\0"
LC273:
	.ascii "X Major: \0"
LC277:
	.ascii "Y Major: \0"
LC278:
	.ascii "X Minor: \0"
LC279:
	.ascii "Y Minor: \0"
	.text
	.p2align 4,,15
	.def	_set_ticks_dialog;	.scl	3;	.type	32;	.endef
_set_ticks_dialog:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$80, %edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$92, %esp
	movl	%eax, -20(%ebp)
	movl	$LC272, %ebx
	movl	$0, (%esp)
	call	_gtk_window_new
	movl	%eax, -24(%ebp)
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, -44(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	call	_gtk_window_set_title
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%eax, -48(%ebp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_container_set_border_width
	movl	-24(%ebp), %edx
	movl	-44(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_modal
	movl	%edi, 4(%esp)
	movl	-24(%ebp), %eax
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-20(%ebp), %edx
	movl	$_gtk_widget_destroy, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 20(%esp)
	movl	%edx, 12(%esp)
	movl	$LC202, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	call	_g_signal_connect_data
	movl	%edi, 4(%esp)
	movl	$0, (%esp)
	call	_gtk_hbox_new
	movl	%eax, %esi
	movl	-24(%ebp), %edx
	movl	-48(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$LC272, (%esp)
	call	_gtk_frame_new
	movl	%esi, (%esp)
	movl	%eax, %ebx
	movl	-48(%ebp), %eax
	xorl	%esi, %esi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_container_add
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	%esi, 4(%esp)
	movl	$0, (%esp)
	call	_gtk_hbox_new
	movl	%eax, -28(%ebp)
	movl	-48(%ebp), %edx
	movl	%ebx, (%esp)
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-28(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_add
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, %esi
	movl	-48(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$LC273, (%esp)
	call	_gtk_label_new
	movl	%eax, %edi
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$1077805056, %edi
	call	_gtk_widget_show
	movl	%edi, 12(%esp)
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	movl	%eax, 16(%esp)
	movl	$1072693248, %eax
	xorl	%edi, %edi
	movl	%eax, 20(%esp)
	xorl	%eax, %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	$0, (%esp)
	call	_gtk_spin_button_new_with_range
	movl	%eax, -32(%ebp)
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	movl	$1, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	%edx, 16(%esp)
	movl	-32(%ebp), %edx
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, %esi
	movl	-48(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$LC277, (%esp)
	call	_gtk_label_new
	movl	%ebx, 4(%esp)
	movl	%eax, %edi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$1077805056, %edi
	call	_gtk_widget_show
	movl	%edi, 12(%esp)
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	movl	%eax, 16(%esp)
	movl	$1072693248, %eax
	xorl	%edi, %edi
	movl	%eax, 20(%esp)
	xorl	%eax, %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	$0, (%esp)
	call	_gtk_spin_button_new_with_range
	movl	%eax, -40(%ebp)
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	movl	$1, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	%edx, 16(%esp)
	movl	-40(%ebp), %edx
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, %esi
	movl	-48(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$LC278, (%esp)
	call	_gtk_label_new
	movl	%ebx, 4(%esp)
	movl	%eax, %edi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	movl	$1077805056, %edi
	call	_gtk_widget_show
	movl	%edi, 12(%esp)
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	movl	%eax, 16(%esp)
	movl	$1072693248, %eax
	xorl	%edi, %edi
	movl	%eax, 20(%esp)
	xorl	%eax, %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	$0, (%esp)
	call	_gtk_spin_button_new_with_range
	movl	%eax, -36(%ebp)
	movl	%ebx, 4(%esp)
	movl	%esi, (%esp)
	movl	$1, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	%edx, 16(%esp)
	movl	-36(%ebp), %edx
	movl	%edi, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, %esi
	movl	-48(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$LC279, (%esp)
	call	_gtk_label_new
	movl	%ebx, 4(%esp)
	movl	%eax, %edi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	xorl	%edi, %edi
	call	_gtk_widget_show
	movl	%edi, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 16(%esp)
	movl	$1072693248, %eax
	movl	%eax, 20(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$1077805056, %eax
	movl	%eax, 12(%esp)
	movl	$0, (%esp)
	call	_gtk_spin_button_new_with_range
	movl	%ebx, 4(%esp)
	movl	%eax, %edi
	movl	$2, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	call	_gtk_widget_show
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %edx
	xorl	%esi, %esi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	228(%eax), %eax
	xorl	%edx, %edx
	pushl	%edx
	pushl	%eax
	fildq	(%esp)
	addl	$8, %esp
	fstpl	-56(%ebp)
	call	_gtk_spin_button_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	fldl	-56(%ebp)
	movl	%eax, (%esp)
	fstpl	4(%esp)
	call	_gtk_spin_button_set_value
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	232(%eax), %eax
	xorl	%edx, %edx
	pushl	%edx
	pushl	%eax
	movl	-36(%ebp), %eax
	fildq	(%esp)
	addl	$8, %esp
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	fstpl	-64(%ebp)
	call	_g_type_check_instance_cast
	fldl	-64(%ebp)
	movl	%eax, (%esp)
	fstpl	4(%esp)
	call	_gtk_spin_button_set_value
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	236(%eax), %eax
	xorl	%edx, %edx
	pushl	%edx
	pushl	%eax
	movl	-40(%ebp), %eax
	fildq	(%esp)
	addl	$8, %esp
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	fstpl	-72(%ebp)
	call	_g_type_check_instance_cast
	fldl	-72(%ebp)
	movl	%eax, (%esp)
	fstpl	4(%esp)
	call	_gtk_spin_button_set_value
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	240(%eax), %eax
	xorl	%edx, %edx
	pushl	%edx
	pushl	%eax
	fildq	(%esp)
	addl	$8, %esp
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%edi, (%esp)
	fstpl	-80(%ebp)
	call	_g_type_check_instance_cast
	fldl	-80(%ebp)
	movl	%eax, (%esp)
	fstpl	4(%esp)
	call	_gtk_spin_button_set_value
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	-32(%ebp), %edx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-20(%ebp), %edx
	movl	$_spin_hmajor_changed_value, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 20(%esp)
	movl	%edx, 12(%esp)
	movl	$LC240, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	call	_g_signal_connect_data
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-20(%ebp), %edx
	xorl	%esi, %esi
	movl	%esi, 20(%esp)
	movl	$_spin_hminor_changed_value, %ecx
	xorl	%ebx, %ebx
	movl	%ecx, 8(%esp)
	xorl	%esi, %esi
	movl	%edx, 12(%esp)
	movl	$LC240, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	xorl	%ebx, %ebx
	call	_g_signal_connect_data
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	movl	-20(%ebp), %edx
	movl	$_spin_vmajor_changed_value, %ecx
	movl	%ecx, 8(%esp)
	movl	$80, %esi
	movl	%ebx, 16(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 12(%esp)
	movl	$LC240, %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%edi, (%esp)
	movl	$LC240, %edi
	movl	%esi, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-20(%ebp), %edx
	xorl	%ecx, %ecx
	movl	%ecx, 16(%esp)
	movl	%ebx, 20(%esp)
	movl	%edx, 12(%esp)
	movl	$_spin_vminor_changed_value, %edx
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	call	_g_signal_connect_data
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	call	_get_parent_window
	testl	%eax, %eax
	je	L810
	movl	%eax, (%esp)
	movl	-44(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %ebx
	movl	-24(%ebp), %edx
	movl	-44(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_transient_for
L810:
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC283:
	.ascii "Set ranges\0"
LC284:
	.ascii "X Min: \0"
LC285:
	.ascii "%0.3f\0"
LC286:
	.ascii "X Max: \0"
LC287:
	.ascii "Y Min: \0"
LC288:
	.ascii "Y Max: \0"
	.text
	.p2align 4,,15
	.def	_set_ranges_dialog;	.scl	3;	.type	32;	.endef
_set_ranges_dialog:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$188, %esp
	movl	%eax, -140(%ebp)
	movl	$LC283, %ebx
	movl	$0, (%esp)
	call	_gtk_window_new
	movl	%eax, -144(%ebp)
	call	_gtk_window_get_type
	movl	%eax, -164(%ebp)
	movl	%eax, 4(%esp)
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	call	_gtk_window_set_title
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	-144(%ebp), %edx
	movl	%eax, %edi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_container_set_border_width
	movl	-144(%ebp), %edx
	movl	-164(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_modal
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	movl	-140(%ebp), %edx
	movl	$_gtk_widget_destroy, %ecx
	movl	%ecx, 8(%esp)
	xorl	%esi, %esi
	movl	%ebx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	$LC202, %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	$0, (%esp)
	call	_gtk_hbox_new
	movl	%edi, 4(%esp)
	movl	%eax, %ebx
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_container_add
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	$LC283, (%esp)
	call	_gtk_frame_new
	movl	%eax, -148(%ebp)
	movl	%edi, 4(%esp)
	movl	%ebx, (%esp)
	xorl	%ebx, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-148(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_add
	movl	-148(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	%ebx, 4(%esp)
	movl	$0, (%esp)
	call	_gtk_hbox_new
	movl	%edi, 4(%esp)
	movl	-148(%ebp), %edx
	movl	%eax, %esi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$LC284, (%esp)
	call	_gtk_label_new
	movl	%eax, %ebx
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %edi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %ecx
	xorl	%edx, %edx
	movl	%ecx, 16(%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 12(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	movl	$50, %ebx
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, -152(%ebp)
	movl	$-1, %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_gtk_widget_set_size_request
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	fldl	64(%eax)
	movl	$LC285, %ecx
	leal	-136(%ebp), %edx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	fstpl	8(%esp)
	call	_sprintf
	call	_gtk_entry_get_type
	movl	%eax, -168(%ebp)
	movl	%eax, 4(%esp)
	movl	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	leal	-136(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	$1, %ecx
	movl	%edx, 16(%esp)
	movl	-152(%ebp), %edx
	movl	%ecx, 8(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	$LC286, (%esp)
	call	_gtk_label_new
	movl	%edi, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	xorl	%edx, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	movl	$LC285, %ebx
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, -156(%ebp)
	movl	$-1, %ecx
	movl	$50, %edx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_gtk_widget_set_size_request
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-140(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	fldl	72(%eax)
	leal	-136(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	$1, %ebx
	fstpl	8(%esp)
	movl	%eax, (%esp)
	call	_sprintf
	movl	-168(%ebp), %edx
	movl	-156(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	leal	-136(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	movl	$2, %ecx
	movl	%edx, 12(%esp)
	movl	-156(%ebp), %edx
	movl	%ecx, 16(%esp)
	movl	%ebx, 8(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	$LC287, (%esp)
	call	_gtk_label_new
	movl	%edi, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %ecx
	xorl	%edx, %edx
	movl	%ecx, 16(%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 12(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	movl	$50, %ebx
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, -160(%ebp)
	movl	$-1, %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_gtk_widget_set_size_request
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-140(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	fldl	80(%eax)
	movl	$LC285, %ecx
	leal	-136(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	fstpl	8(%esp)
	call	_sprintf
	movl	-168(%ebp), %edx
	movl	-160(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	leal	-136(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	$1, %ecx
	movl	%edx, 16(%esp)
	movl	-160(%ebp), %edx
	movl	%ecx, 8(%esp)
	movl	%ebx, 12(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-160(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	$LC288, (%esp)
	call	_gtk_label_new
	movl	%edi, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	xorl	%edx, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, %ebx
	movl	$-1, %eax
	movl	%eax, 8(%esp)
	movl	$50, %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_gtk_widget_set_size_request
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-140(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	fldl	88(%eax)
	movl	$LC285, %eax
	movl	%eax, 4(%esp)
	leal	-136(%ebp), %eax
	fstpl	8(%esp)
	movl	%eax, (%esp)
	call	_sprintf
	movl	%ebx, (%esp)
	movl	-168(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	leal	-136(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_entry_set_text
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	movl	$2, %esi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	-152(%ebp), %edx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-140(%ebp), %edx
	movl	$_activate_entry_xmin, %ecx
	movl	%ecx, 8(%esp)
	xorl	%edi, %edi
	xorl	%esi, %esi
	movl	%edi, 20(%esp)
	xorl	%edi, %edi
	movl	%edx, 12(%esp)
	movl	$LC256, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 16(%esp)
	xorl	%esi, %esi
	call	_g_signal_connect_data
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-140(%ebp), %edx
	movl	$_activate_entry_xmax, %ecx
	movl	%ecx, 8(%esp)
	movl	%edi, 20(%esp)
	movl	$80, %edi
	movl	%edx, 12(%esp)
	movl	$LC256, %edx
	movl	%edx, 4(%esp)
	movl	%esi, 16(%esp)
	xorl	%esi, %esi
	call	_g_signal_connect_data
	movl	%edi, 4(%esp)
	movl	-160(%ebp), %eax
	movl	$LC256, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%esi, 20(%esp)
	movl	-140(%ebp), %edx
	xorl	%ecx, %ecx
	movl	%ecx, 16(%esp)
	movl	$80, %esi
	movl	%edi, 4(%esp)
	movl	$_activate_entry_ymax, %edi
	movl	%edx, 12(%esp)
	movl	$_activate_entry_ymin, %edx
	movl	%edx, 8(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, 4(%esp)
	movl	$LC256, %esi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	-140(%ebp), %edx
	movl	%ecx, 20(%esp)
	movl	%edi, 8(%esp)
	movl	%edx, 12(%esp)
	movl	%esi, 4(%esp)
	call	_g_signal_connect_data
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	call	_get_parent_window
	testl	%eax, %eax
	je	L812
	movl	%eax, (%esp)
	movl	-164(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %ebx
	movl	-144(%ebp), %edx
	movl	-164(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_transient_for
L812:
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC290:
	.ascii "Set labels\0"
LC291:
	.ascii "X : \0"
LC293:
	.ascii "Y : \0"
LC292:
	.ascii "\0"
	.text
	.p2align 4,,15
	.def	_set_labels_dialog;	.scl	3;	.type	32;	.endef
_set_labels_dialog:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	$LC290, %esi
	pushl	%ebx
	subl	$44, %esp
	movl	$0, (%esp)
	movl	%eax, -16(%ebp)
	call	_gtk_window_new
	movl	%eax, -20(%ebp)
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	xorl	%esi, %esi
	call	_gtk_window_set_title
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%eax, %edi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_container_set_border_width
	movl	%ebx, 4(%esp)
	movl	-20(%ebp), %eax
	xorl	%ebx, %ebx
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_modal
	movl	-20(%ebp), %edx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-16(%ebp), %edx
	movl	$_gtk_widget_destroy, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 20(%esp)
	movl	%edx, 12(%esp)
	movl	$LC202, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	call	_g_signal_connect_data
	movl	$0, (%esp)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	call	_gtk_hbox_new
	movl	%edi, 4(%esp)
	movl	%eax, %ebx
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_container_add
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	$LC290, (%esp)
	call	_gtk_frame_new
	movl	%edi, 4(%esp)
	movl	%eax, %esi
	movl	%ebx, (%esp)
	movl	$2, %ebx
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%eax, %eax
	movl	%eax, 4(%esp)
	call	_gtk_hbox_new
	movl	%eax, -24(%ebp)
	movl	%edi, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_gtk_container_add
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	$LC291, (%esp)
	call	_gtk_label_new
	movl	%eax, %esi
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%ebx, 16(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%eax, %edi
	movl	$-1, %eax
	movl	%eax, 8(%esp)
	movl	$100, %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_gtk_widget_set_size_request
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	324(%eax), %esi
	testl	%esi, %esi
	je	L815
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	324(%ebx), %edx
	movl	%edx, 4(%esp)
L820:
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-24(%ebp), %eax
	xorl	%esi, %esi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %ecx
	xorl	%edx, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$LC293, (%esp)
	call	_gtk_label_new
	movl	%ebx, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%eax, %esi
	movl	$2, %ebx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	$100, %ebx
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	call	_gtk_entry_new
	movl	%ebx, 4(%esp)
	movl	%eax, %esi
	movl	$-1, %eax
	movl	%eax, 8(%esp)
	movl	%esi, (%esp)
	call	_gtk_widget_set_size_request
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	328(%eax), %ecx
	testl	%ecx, %ecx
	je	L817
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %ebx
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	328(%ebx), %edx
L822:
	movl	%edx, 4(%esp)
	movl	$2, %ebx
	movl	%eax, (%esp)
	call	_gtk_entry_set_text
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	xorl	%ebx, %ebx
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	call	_gtk_widget_show
	movl	%edi, (%esp)
	movl	$80, %eax
	movl	$LC256, %edi
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 20(%esp)
	movl	-16(%ebp), %edx
	xorl	%ecx, %ecx
	movl	%ecx, 16(%esp)
	movl	$80, %ebx
	movl	%edi, 4(%esp)
	movl	$_activate_entry_ylabel, %edi
	movl	%edx, 12(%esp)
	movl	$_activate_entry_xlabel, %edx
	movl	%edx, 8(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%esi, (%esp)
	movl	$LC256, %esi
	movl	%ebx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	-16(%ebp), %edx
	movl	%ecx, 20(%esp)
	movl	%esi, 4(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	call	_g_signal_connect_data
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	call	_get_parent_window
	testl	%eax, %eax
	movl	%eax, %esi
	je	L814
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%eax, %esi
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_window_set_transient_for
L814:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,7
L815:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	$LC292, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%ebx, 4(%esp)
	jmp	L820
	.p2align 4,,7
L817:
	call	_gtk_entry_get_type
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	$LC292, %edx
	jmp	L822
	.section .rdata,"dr"
LC294:
	.ascii "Set digits\0"
LC295:
	.ascii " X \0"
LC299:
	.ascii " Y \0"
	.text
	.p2align 4,,15
	.def	_set_digits_dialog;	.scl	3;	.type	32;	.endef
_set_digits_dialog:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$80, %edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$76, %esp
	movl	%eax, -20(%ebp)
	movl	$LC294, %ebx
	movl	$0, (%esp)
	call	_gtk_window_new
	movl	%eax, -24(%ebp)
	call	_gtk_window_get_type
	movl	%eax, 4(%esp)
	movl	%eax, -32(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	call	_gtk_window_set_title
	call	_gtk_container_get_type
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%eax, -36(%ebp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_container_set_border_width
	movl	-24(%ebp), %edx
	movl	-32(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_modal
	movl	%edi, 4(%esp)
	movl	-24(%ebp), %eax
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-20(%ebp), %edx
	movl	$_gtk_widget_destroy, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 20(%esp)
	xorl	%esi, %esi
	movl	%edx, 12(%esp)
	movl	$LC202, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	call	_g_signal_connect_data
	movl	%edi, 4(%esp)
	movl	$0, (%esp)
	call	_gtk_hbox_new
	movl	%eax, %edi
	movl	-24(%ebp), %edx
	movl	-36(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_container_add
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$LC294, (%esp)
	call	_gtk_frame_new
	movl	%edi, (%esp)
	movl	%eax, %ebx
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_container_add
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	%esi, 4(%esp)
	movl	$0, (%esp)
	call	_gtk_hbox_new
	movl	%ebx, (%esp)
	movl	-36(%ebp), %edx
	movl	%eax, %esi
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_hbox_new
	movl	%esi, (%esp)
	movl	%eax, %edi
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_container_add
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$LC295, (%esp)
	call	_gtk_label_new
	movl	%eax, %esi
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	$1, %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 12(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	movl	$1077805056, %esi
	call	_gtk_widget_show
	movl	%esi, 12(%esp)
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	movl	%eax, 16(%esp)
	movl	$1072693248, %eax
	xorl	%esi, %esi
	movl	%eax, 20(%esp)
	xorl	%eax, %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 8(%esp)
	movl	$0, (%esp)
	call	_gtk_spin_button_new_with_range
	movl	%eax, -28(%ebp)
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	movl	$1, %ecx
	movl	%edx, 16(%esp)
	movl	-28(%ebp), %edx
	movl	%ecx, 8(%esp)
	movl	%esi, 12(%esp)
	movl	%edx, 4(%esp)
	call	_gtk_box_pack_start
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	$LC299, (%esp)
	call	_gtk_label_new
	movl	%ebx, 4(%esp)
	movl	%eax, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	xorl	%esi, %esi
	call	_gtk_widget_show
	movl	%esi, 4(%esp)
	xorl	%eax, %eax
	movl	%eax, 16(%esp)
	movl	$1072693248, %eax
	movl	%eax, 20(%esp)
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$1077805056, %eax
	movl	%eax, 12(%esp)
	movl	$0, (%esp)
	call	_gtk_spin_button_new_with_range
	movl	%ebx, 4(%esp)
	movl	%eax, %esi
	movl	$2, %ebx
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%ecx, %ecx
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 16(%esp)
	movl	%esi, 4(%esp)
	call	_gtk_box_pack_start
	movl	%esi, (%esp)
	call	_gtk_widget_show
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	220(%eax), %eax
	xorl	%edx, %edx
	pushl	%edx
	pushl	%eax
	fildq	(%esp)
	addl	$8, %esp
	fstpl	-48(%ebp)
	call	_gtk_spin_button_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	fldl	-48(%ebp)
	movl	%eax, (%esp)
	fstpl	4(%esp)
	call	_gtk_spin_button_set_value
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	224(%eax), %eax
	xorl	%edx, %edx
	pushl	%edx
	pushl	%eax
	fildq	(%esp)
	addl	$8, %esp
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	movl	%esi, (%esp)
	fstpl	-56(%ebp)
	call	_g_type_check_instance_cast
	fldl	-56(%ebp)
	movl	%eax, (%esp)
	fstpl	4(%esp)
	call	_gtk_spin_button_set_value
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	-28(%ebp), %edx
	movl	$80, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%edi, 20(%esp)
	movl	-20(%ebp), %edx
	movl	$_spin_x_digits_changed_value, %ecx
	movl	%ecx, 8(%esp)
	movl	$80, %edi
	movl	%ebx, 16(%esp)
	xorl	%ebx, %ebx
	movl	%edx, 12(%esp)
	movl	$LC240, %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_g_signal_connect_data
	movl	%edi, 4(%esp)
	movl	$LC240, %edi
	movl	%esi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-20(%ebp), %edx
	xorl	%ecx, %ecx
	movl	%ecx, 16(%esp)
	movl	%ebx, 20(%esp)
	movl	%edx, 12(%esp)
	movl	$_spin_y_digits_changed_value, %edx
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	call	_g_signal_connect_data
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	call	_get_parent_window
	testl	%eax, %eax
	je	L823
	movl	%eax, (%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %ebx
	movl	-24(%ebp), %edx
	movl	-32(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_transient_for
L823:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC303:
	.ascii "Set font size\0"
LC304:
	.ascii " \0"
	.text
	.p2align 4,,15
	.def	_set_font_size_dialog;	.scl	3;	.type	32;	.endef
_set_font_size_dialog:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$80, %edi
	pushl	%esi
	xorl	%esi, %esi
	pushl	%ebx
	subl	$60, %esp
	movl	%eax, -20(%ebp)
	movl	$LC303, %ebx
	movl	$0, (%esp)
	call	_gtk_window_new
	movl	%eax, -24(%ebp)
	call	_gtk_window_get_type
	movl	%eax, -28(%ebp)
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	xorl	%ebx, %ebx
	call	_gtk_window_set_title
	call	_gtk_container_get_type
	movl	%eax, -32(%ebp)
	movl	-24(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$10, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_container_set_border_width
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$1, %edx
	movl	%edx, 4(%esp)
	call	_gtk_window_set_modal
	movl	%edi, 4(%esp)
	movl	-24(%ebp), %eax
	xorl	%edi, %edi
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	-20(%ebp), %edx
	movl	$_gtk_widget_destroy, %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, 20(%esp)
	xorl	%esi, %esi
	movl	%edx, 12(%esp)
	movl	$LC202, %edx
	movl	%edx, 4(%esp)
	movl	%ebx, 16(%esp)
	call	_g_signal_connect_data
	movl	%edi, 4(%esp)
	movl	$0, (%esp)
	call	_gtk_hbox_new
	movl	%eax, %edi
	movl	-24(%ebp), %edx
	movl	-32(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_container_add
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$LC303, (%esp)
	call	_gtk_frame_new
	movl	%edi, (%esp)
	movl	%eax, %ebx
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_container_add
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	movl	%esi, 4(%esp)
	movl	$0, (%esp)
	call	_gtk_hbox_new
	movl	%ebx, (%esp)
	movl	-32(%ebp), %edx
	movl	%eax, %esi
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%esi, 4(%esp)
	call	_gtk_container_add
	movl	%esi, (%esp)
	call	_gtk_widget_show
	movl	$0, (%esp)
	xorl	%ecx, %ecx
	movl	%ecx, 4(%esp)
	call	_gtk_hbox_new
	movl	%esi, (%esp)
	movl	%eax, %edi
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%edi, 4(%esp)
	call	_gtk_container_add
	movl	%edi, (%esp)
	call	_gtk_widget_show
	movl	$LC304, (%esp)
	call	_gtk_label_new
	movl	%eax, %ebx
	call	_gtk_box_get_type
	movl	%eax, 4(%esp)
	movl	%eax, %esi
	movl	%edi, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	$1, %edx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	movl	$1075838976, %ebx
	call	_gtk_widget_show
	movl	%ebx, 4(%esp)
	fld1
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	$1077805056, %eax
	fstpl	16(%esp)
	movl	%eax, 12(%esp)
	movl	$0, (%esp)
	call	_gtk_spin_button_new_with_range
	movl	%esi, 4(%esp)
	movl	%eax, %ebx
	movl	$80, %esi
	movl	%edi, (%esp)
	movl	$1, %edi
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	$2, %ecx
	xorl	%edx, %edx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	$_spin_font_changed_value, %edi
	movl	%ebx, 4(%esp)
	call	_gtk_box_pack_start
	movl	%ebx, (%esp)
	call	_gtk_widget_show
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	call	_g_type_check_instance_cast
	fildl	544(%eax)
	fstpl	-40(%ebp)
	call	_gtk_spin_button_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	fldl	-40(%ebp)
	movl	%eax, (%esp)
	fstpl	4(%esp)
	call	_gtk_spin_button_set_value
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_gtk_widget_show
	movl	%esi, 4(%esp)
	movl	$LC240, %esi
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	movl	%edx, 16(%esp)
	movl	-20(%ebp), %edx
	movl	%ecx, 20(%esp)
	movl	%edi, 8(%esp)
	movl	%edx, 12(%esp)
	movl	%esi, 4(%esp)
	call	_g_signal_connect_data
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_g_type_check_instance_cast
	call	_get_parent_window
	testl	%eax, %eax
	je	L825
	movl	%eax, (%esp)
	movl	-28(%ebp), %edx
	movl	%edx, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, %ebx
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 4(%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	movl	%ebx, 4(%esp)
	call	_gtk_window_set_transient_for
L825:
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.def	_remove_all_data;	.scl	3;	.type	32;	.endef
_remove_all_data:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	8(%ebp), %ebx
	cmpl	$-8, 12(%ebp)
	je	L831
L827:
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.p2align 4,,7
L831:
	testl	%ebx, %ebx
	je	L827
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	432(%eax), %ecx
	testl	%ecx, %ecx
	jne	L832
L830:
	call	_gtk_widget_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	%eax, (%esp)
	call	_gtk_widget_queue_draw
	addl	$20, %esp
	movl	$1, %eax
	popl	%ebx
	popl	%ebp
	ret
L832:
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	xorl	%edx, %edx
	movl	$_g_free, %ecx
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	432(%eax), %eax
	movl	%eax, (%esp)
	call	_g_list_foreach
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	movl	432(%eax), %eax
	movl	%eax, (%esp)
	call	_g_list_free
	call	_gabedit_contoursplot_get_type
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_g_type_check_instance_cast
	xorl	%edx, %edx
	movl	%edx, 432(%eax)
	jmp	L830
	.section .rdata,"dr"
__PRETTY_FUNCTION__.63:
	.ascii "create_contours\0"
