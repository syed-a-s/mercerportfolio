; NAME 		: Syed Saadat
; Assignment 	: Max Fib
; Date		: 10-20-21

SECTION .data

SECTION .bss
MaxFibs		:	RESD 1
FibCount	:	RESW 1
hold		:	RESD 1

SECTION .text
global _main
_main:

mov ebx, hold
mov dword [ebx], 1
break1:





mov eax, 1
mov ebx, 0
int 80h 
