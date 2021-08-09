sprite_init:
	stz VERA_CTRL
	lda #%00010000
	sta VERA_HIGH
	lda #$40
	sta VERA_MID
	stz VERA_LOW
	
	ldy #0
:	lda player_heart,Y
	sta VERA_DATA0
	iny 
	bne :-

; Initiate Sprite
	lda DC_VIDEO
	ora #%01000000
	sta DC_VIDEO

	lda #%00010001
	sta VERA_HIGH
	lda #$FC
	sta VERA_MID
	stz VERA_LOW

	stz VERA_DATA0	;offset 0
	lda #$82
	sta VERA_DATA0	;offset 1
	stz VERA_DATA0	;offset 2
	stz VERA_DATA0	;offset 3
	stz VERA_DATA0	;offset 4
    stz VERA_DATA0	;offset 5
	lda #%00001100
	sta VERA_DATA0	;offset 6
	lda #%01010000
	sta VERA_DATA0	;offset 7
	rts