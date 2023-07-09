; NAME	     :	Syed Saadat
; Assignment :  Program 2 - Adding Integers
; Date	     :  10 - 6 - 21

SECTION .txt
global _main
_main :

; a987 + a987
mov ax, 0a987h
mov bx, ax
add ax, bx

; abcd + ef01
mov ax, 0abcdh
mov bx, 0ef01h
add ax, bx

; fafa + 0505
mov ax, 0fafah
mov bx, 0505h
add ax, bx

; 80f0 + ff00
mov ax, 080f0h
mov bx, 0ff00h
add ax, bx

; 2468 + db98
mov ax, 2468h
mov bx, 0db98h
add ax, bx

; 000f + 7ff1
mov ax, 000fh
mov bx, 7ff1h
add ax, bx

; 1234 + 7654
mov ax, 1234h
mov bx, 7654h
add ax, bx

; 0b0b + a11r
mov ax, 0b0bh
mov bx, 0a11h
add ax, bx

; 7654 + 789a
mov ax, 7654h
mov bx, 789ah
add ax, bx

; 8000 + 8000
mov ax, 8000h
mov bx, 8000h
add ax, bx

mov eax, 1
mov ebx, 0
int 80h
