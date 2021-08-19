;---------------;
; @Szyfr		;
; @2021/8/19	;
;---------------;


;=	bbp mode (0-2)
BBP_MODE		= $A000

;=	Sprite size
;=		$00 : 8x8
;=		$01 : 8x16
;=		$10 : 16x8
;=		$11 : 16x16
SIZE_MODE		= $A001

;=	Tiling mode
TILING_MODE		= $A002

;=	Meta Mode
META_MODE		= $A003

;=	Menu
;=		$00 : Edit
;=		$01 : Menu
;=		$02 : Palette
MENU			= $A004

;=	Cursor X
CURSOR_X		= $A005
;=	Cursor Y
CURSOR_Y		= $A006
;=	Selected menu option
OPTION			= $A007