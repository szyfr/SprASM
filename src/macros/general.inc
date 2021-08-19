;---------------;
; @Szyfr		;
; @2021/8/19	;
;---------------;


.macro select_bank num
	.scope
	lda num
	sta RAM_BANK
	.endscope
.endmacro

.macro set_cursor cx, cy
	.scope
	lda cx
	rol
	sta CURSOR_X
	lda cy
	sta CURSOR_Y
	.endscope
.endmacro
