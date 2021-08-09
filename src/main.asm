.org $080D
.segment "STARTUP"
.segment "INIT"
.segment "ONCE"
.segment "CODE"


.include "constants.inc"


main:
	jsr init

:	jsr update
	jsr draw
	jmp :-
	
leave:
	rts

	

.include "init.inc"
.include "update.inc"
.include "draw.inc"

;.include "sprites/player_heart.inc"