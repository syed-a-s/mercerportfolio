; NAME		:	Syed Saadat
; Assignmetnt	:	Program 4 Fibonacci Sequence
; Date		:	10-15-21

SECTION .data
fib		:	DD	0 ; num1
previousNum	:	DD	1 ; num2
temp		:	DD	0 ; num3
	
SECTION .bss
Fibs:	RESD	16

SECTION .text
global _main
_main:

mov ecx, 16
mov ebx, Fibs
top: 

; store fib and shift array
mov dword[Fibs], fib
add ebx, 4

; swap
mov eax, [temp]
add eax, [fib]
add eax, [previousNum] ; num3
mov eax, previousNum
; mov ax to fibs
mov [fib], ax
mov [previousNum], eax

loop top

lastBreak:
	
; standard termination
mov eax, 1
mov ebx, 0
int 80h
