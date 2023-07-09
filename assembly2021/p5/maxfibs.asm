; NAME 		: Syed Saadat
; Assignment 	: Max Fib
; Date		: 10-20-21

SECTION .bss
MaxFibs		:	RESD 1
FibCount	:	RESW 1
HoldFib		:	RESD 2	;;; used to hold current and previous num

SECTION .text
global _main
_main:

mov ebx, HoldFib
mov dword [ebx], 0
mov dword [ebx+4], 1

;;; the loop
top: 
mov eax, [ebx]		;;; adds previous and current 
add eax, [ebx+4]	;;;

mov edx, [ebx+4]	;;; updates previous and next fib
mov [ebx], edx 		;;; 
mov [ebx+4], eax	;;;

mov [MaxFibs], eax	;;; updates max fib
jnc top
;;;;;;;;;;;;;

lastBreak:

; Standard termination
mov eax, 1
mov ebx, 0
int 80h 
