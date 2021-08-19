;---------------;
; @Szyfr		;
; @2021/8/19	;
;---------------;


.macro RAM2VRAM ram_addr, vram_addr, num_bytes
	.scope
		stz VERA_CTRL
		lda #($10 | ^vram_addr)
		sta VERA_HIG
		lda #>vram_addr
		sta VERA_MID
		lda #<vram_addr
		sta VERA_LOW

		lda #<ram_addr
		sta ZP_PTR
		lda #>ram_addr
		sta ZP_PTR+1

		ldx #0
		ldy #0
	vram_loop:
		lda (ZP_PTR),y
		sta VERA_DATA0
		iny
		cpx #>num_bytes
		beq check_end
		cpy #0
		bne vram_loop
		inx
		inc ZP_PTR+1
		bra vram_loop
	check_end:
		cpy #<num_bytes
		bne vram_loop
	.endscope
.endmacro


.macro RAM2MAP ram_addr, vram_addr, num_bytes
	.scope
		stz VERA_CTRL
		lda #($10 | ^vram_addr)
		sta VERA_HIG
		lda #>vram_addr
		sta VERA_MID
		lda #<vram_addr
		sta VERA_LOW

		lda #<ram_addr
		sta ZP_PTR
		lda #>ram_addr
		sta ZP_PTR+1

		ldx #0
		ldy #0
	vram_loop:
		lda (ZP_PTR),y
		sta VERA_DATA0
		stz VERA_DATA0
		iny
		cpx #>num_bytes
		beq check_end
		cpy #0
		bne vram_loop
		inx
		inc ZP_PTR+1
		bra vram_loop
	check_end:
		cpy #<num_bytes
		bne vram_loop
	.endscope
.endmacro