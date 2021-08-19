;---------------;
; @Szyfr		;
; @2021/8/19	;
;---------------;

;=  Zero page pointer
ZP_PTR			= $30


;=  Low byte of VRAM address
VERA_LOW		= $9F20
;=  Middle byte of VRAM address
VERA_MID		= $9F21
;=  bit 7-4: Address increment
;=  bit   3: Decrement sign
;=  bit   0: High bit of VRAM address
VERA_HIG		= $9F22

;=  VRAM Data port 0
VERA_DATA0		= $9f23
;=  VRAM Data port 1
VERA_DATA1		= $9f24

;=  bit 7: Reset
;=  bit 1: DCSEL			???
;=  bit 0: ADDRSEL			???
VERA_CTRL		= $9f25

;=  bit 7: IRQ line (8)		???
;=  bit 3: AFLOW			???
;=  bit 2: SPRCOL			???
;=  bit 1: Line				???
;=  bit 0: VSYNC
VERA_IEN		= $9f26

;=  bit 7-4: Sprite Collisions
;=  bit 3: AFLOW			???
;=  bit 2: SPRCOL			???
;=  bit 1: Line				???
;=  bit 0: VSYNC 
VERA_ISR		= $9f27

;=  IRQ line (7:0)
VERA_IRQ		= $9f28

;=  bit   7: Current field
;=  bit   6: Sprite enable
;=  bit   5: Layer 1 enable
;=  bit   4: Layer 0 enable
;=  bit   2: Monochrome
;=  bit 1-0: Output mode
DC_VIDEO		= $9F29

;=  Horizontal scale
DC_HSCALE		= $9F2A

;=  Vertical scale
DC_VSCALE		= $9F2B

;=  Border Color
DC_BORDER		= $9F2C


;=  bit 7-6: Map height
;=  bit 5-4: Map width
;=  bit   3: T256C			???
;=  bit   2: Bitmap mode
;=  bit 1-0: Color Depth
L0_CONFIG		= $9F2D

;=  Map base address
L0_MAPBASE		= $9F2E

;=  bit 7-2: Tile base address
;=  bit   1: Tile height
;=  bit   0: Tile width
L0_TILEBASE		= $9F2F

;=  Horizontal scrolling low
L0_HSCROLL_L	= $9F30
;=  Horizontal scrolling high
L0_HSCROLL_H	= $9F31

;=  Vertical scrolling low
L0_VSCROLL_L	= $9F32
;=  Vertical scrolling high
L0_VSCROLL_H	= $9F33


;=  bit 7-6: Map height
;=  bit 5-4: Map width
;=  bit   3: T256C			???
;=  bit   2: Bitmap mode
;=  bit 1-0: Color Depth
L1_CONFIG		= $9F34

;=  Map base address
L1_MAPBASE		= $9F35

;=  bit 7-2: Tile base address
;=  bit   1: Tile height
;=  bit   0: Tile width
L1_TILEBASE		= $9F36

;=  Horizontal scrolling low
L1_HSCROLL_L	= $9F37
;=  Horizontal scrolling high
L1_HSCROLL_H	= $9F38

;=  Vertical scrolling low
L1_VSCROLL_L	= $9F39
;=  Vertical scrolling high
L1_VSCROLL_H	= $9F3A


;=  bit   7: FIFO Full / FIFO reset	???
;=  bit   5: 16-bit
;=  bit   4: Stereo
;=  bit 3-0: PCM Volume
AUDIO_CTRL		= $9F3B

;=  PCM Sample rate
AUDIO_RATE		= $9F3C

;=  Audoi FIFO data (write-only)
AUDIO_DATA		= $9F3D

;=  Data							???
SPI_DATA		= $9F3E

;=  bit 7: Busy
;=  bit 1: Slow clock
;=  bit 0: Select
SPI_CTRL		= $9F3F


;;=  RAM bank
RAM_BANK		= $0000


WND_WIDTH		= 80
WND_HEIGHT		= 60