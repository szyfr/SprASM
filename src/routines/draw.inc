;---------------;
; @Szyfr		;
; @2021/8/7		;
;---------------;


draw:

	; Go though and copy tiles from memory into field

	; Replace tile with cursor if not in menu
	jsr apply_cursor

	rts


.include "draw/apply_cursor.inc"
.include "draw/copy_sprite.inc"
