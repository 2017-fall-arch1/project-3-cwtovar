	.file	"checkButton.c"
.text
	.balign 2
	.global	checkButton
	.section
	.word	checkButton
	.text
	

	.extern state
	
checkButton:
; chekcs if state is 1 
; framesize_regs:     24
; framesize_locals:   0
; framesize_outgoing: 0
; framesize:          24
; elim ap -> fp       26
; elim fp -> sp       0
	; start of prologue
	PUSH	R15
	PUSH	R14
	PUSH	R13			; end of prologue
	mov &state,r(15)
	CALL	#chckButton
	; start of epilogue
	POP	R13
	POP	R14
	POP	R15
chckButton:
	cmp #1, &state
	jz #s1
s1:
	mov #1, r(15)
	and #2, r(15)
	pop r(0)
