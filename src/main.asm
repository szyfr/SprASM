;---------------;
; @Szyfr		;
; @2021/8/19	;
;---------------;


.org $080D
.segment "STARTUP"
.segment "INIT"
.segment "ONCE"
.segment "CODE"


.include "constants.inc"
.include "macros.inc"


main:
	jsr init

:	jsr update
	jsr draw
	jmp :-


.include "routines/init.inc"
.include "routines/update.inc"
.include "routines/draw.inc"