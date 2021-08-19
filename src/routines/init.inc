;---------------;
; @Szyfr		;
; @2021/8/19	;
;---------------;


init:
	select_bank $01

	stz BBP_MODE
	stz SIZE_MODE
	stz TILING_MODE
	stz META_MODE
	stz MENU
	stz CURSOR_X
	stz CURSOR_Y
;	set_cursor #$07,#$07
	stz OPTION


	jsr setup_video

	rts


setup_video:
	stz DC_VIDEO

	lda #32
	sta DC_HSCALE
	sta DC_VSCALE

	lda #%00000010
	sta L0_CONFIG
	lda #(layer0_map >> 9)
	sta L0_MAPBASE
	lda #(vram_tiles >> 9)
	sta L0_TILEBASE
	lda #$F4
	sta L0_VSCROLL_L
	lda #$FF
	sta L0_VSCROLL_H
	lda #04
	sta L0_HSCROLL_L

	RAM2MAP map, layer0_map, map_size
	RAM2VRAM tiles, vram_tiles, tiles_size

	lda #$11
	sta DC_VIDEO

	rts


.include "tiles/test.inc"