; Console Output
; Materials - NASM (32-bit)
; Copyright (c) 2017 Hall & Slonka

; Uses system call information from Chapter 10

SECTION .data
s1: DB "Hello Universe", 10
lenS1: EQU ($ - s1)

cr: db 0ah
saveECX: dd 0

SECTION .text
global _main
_main:

;;; Loop 10 times to print the message 10 times
	mov ecx,10
top:
	mov [saveECX], ecx

print:  mov eax, 4     ; syswrite
	mov ebx, 1     ; stdout
	mov ecx, s1    ; starting address of string
	mov edx, lenS1 ; len of string
	int 80h        ; interrupt 80 hex

	mov ecx, [saveECX]
	loop top

        mov eax, 4     ; syswrite
	mov ebx, 1     ; stdout
	mov ecx, cr    ; starting address of string
	mov edx, 1     ; len of string
	int 80h
done:	
mov eax, 1
mov ebx, 0
int 80h
