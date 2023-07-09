SECTION .data
saveEcxOuter: dd 0
saveEcxInner: dd 0
outerS: db "outer"
innerS: db "inner"
lenS1: EQU ($ - outerS)
lenS2: EQU ($ - innerS)

SECTION .text
global _main
_main:

mov ecx, 24
outer:
	mov [saveEcxOuter], ecx
	; print within outer loop
		mov eax, 4 		; syswrite
		mov ebx, 1 		; stdout
		mov ecx, outerS		; starting address of string
		mov edx, lenS1		; length of string
		int 80h
	mov ecx, 80
	inner:
		; print within inner loop
			mov [saveEcxInner], ecx
			mov eax, 4
			mov ebx, 1
			mov ecx, innerS
			mov edx, 1
			int 80h
		mov ecx, [saveEcxInner]
		loop inner
	mov ecx, [saveEcxOuter]
	loop outer

mov eax, 1
mov ebx, 0
int 80h
