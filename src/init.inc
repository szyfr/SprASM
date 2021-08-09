;---------------;
; @Szyfr		;
; @2021/8/8		;
;---------------;

init:
	stz VERA_CTRL
	lda #%00010000
	sta VERA_HIG
	stz VERA_MID
	stz VERA_LOW

clear_loop:	
	lda #$20			;Character to fill
	ldx #$00			;Color to fill
	ldy #$0				;Initialize counter

:	sta VERA_DATA0		;-------
	stx VERA_DATA0		; Loop through line and
	iny					; fill it with the
	cpy #WND_WIDTH		; selected char and color.
	bne	:-				;-------

	lda VERA_MID		;-------
	inc					; Increment the line.
	sta VERA_MID		; keep doing it
	stz VERA_LOW		; until the screen
	cmp #WND_HEIGHT		; is filled.
	bne clear_loop		;-------


	rts