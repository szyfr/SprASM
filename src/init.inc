;---------------;
; @Szyfr		;
; @2021/8/8		;
;---------------;

layer0_map	= $00000
;layer1_map	= $01000
;tiles		= $02000
layer1_map	= $00200
vram_tiles	= $00800


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


init:
	stz DC_VIDEO

;	lda #32
;	sta DC_HSCALE
;	sta DC_VSCALE

	lda #$02
	sta L0_CONFIG
	lda #(layer0_map >> 9)
	sta L0_MAPBASE
	lda #(vram_tiles >> 9)
	sta L0_TILEBASE
	stz L0_HSCROLL_L
	stz L0_HSCROLL_H
	stz L0_VSCROLL_L
	stz L0_VSCROLL_H

	RAM2VRAM map, layer0_map, map_size
	RAM2VRAM tiles, vram_tiles, tiles_size

;	lda #$31
;	lda #$21
	lda #$11
	sta DC_VIDEO

	rts


.include "tiles/test.inc"