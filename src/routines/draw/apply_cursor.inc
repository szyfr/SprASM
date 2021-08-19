;---------------;
; @Szyfr		;
; @2021/8/7		;
;---------------;


apply_cursor:

	select_bank $01

	;TODO: Make sure to write a new version for different sprite sizes

	lda MENU
	cmp #$00
	bne exit

; Calculate Y
	clc
	lda #$03
	ldx #0

	ldy CURSOR_Y
	cpy #$04
	stz $A010
	bcc begin_loop
	ldy #$01
	sty $A010

begin_loop:
	cpx CURSOR_Y
	beq leave
	inx
	adc #$40
	bra begin_loop
leave:
	adc	CURSOR_X

	sta VERA_LOW
	lda $A010
	sta VERA_MID
	stz VERA_HIG

	lda #$02
	sta VERA_DATA0

exit:
	rts


;begin_loop:
;	cpx CURSOR_Y
;	beq leave
;	inx
;	adc #$40
;	bra begin_loop
;leave:
;	stz $A010
;	bcc carry_clear
;	ldy #$01
;	sty $A010
;	clc
;carry_clear:
;	adc	CURSOR_X
;
;	sta VERA_LOW
;	lda $A010
;	sta VERA_MID
;	stz VERA_HIG
;
;	lda #$02
;	sta VERA_DATA0