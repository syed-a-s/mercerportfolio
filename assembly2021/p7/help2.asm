SECTION .data
cr: db 0ah  ;;; carriage return character ;;; presses enter, prints new line
saveEcxOuter : dd 0 ; save outer loop iteration
saveEcxInner : dd 0 ; save inner loop iteration
in : db "x"

SECTION .text
global _main
_main: 	

mov ecx, 4 ; outer loop 'outerLoops' times
outer:
	mov [saveEcxOuter], ecx
	mov ecx, 10 ; inner loop 'innerLoops' times
	inner:
		mov [saveEcxInner], ecx
		; print current pointer to surprise
		mov eax, 4 ; syswrite
		mov ebx, 1 ; stdout
		mov ecx, in ; starting address of string
		mov edx, 1 ; length of string (only want one byte)
		int 80h ; interrupt 80 hex

		; go back to inner
		mov ecx, [saveEcxInner]
		loop inner
	; printing carriage return before next row
	mov eax, 4
	mov ebx, 1
	mov ecx, cr
	mov edx, 1
	int 80h
	
	; go back to outer
	mov ecx, [saveEcxOuter]
	loop outer

mov eax, 1
mov ebx, 0
int 80h
