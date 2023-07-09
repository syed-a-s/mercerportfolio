; NAME		: Syed Saadat
; Assignment	: Program 1 Data Storage
; Date		: 9-22-21
; Etc...

SECTION .data
; define data/variables here.  Think DB, DW, DD, DQ
a1:	DB	2, 4, 6, 8, 10	
b1:	DQ	1, 2, 3, 4, 5
c1:	DD	10, 20, 30, 40
d1:	DQ	10h, 11h, 12h, 13h

a2:	DB	-50
b2:	DW	-45
c2:	DB	-30
d2:	DW	-25
e2:	DB	-20

a3:	DB	"Mercer"
b3:	DB	100
c3:	DB	0
d3:	DB	"Go "
e3:	DB	"Bears!"

a4:	DW	100
b4:	DD	100h
c4:	DB	100b
d4:	DW	100q
e4:	DD	100d

SECTION .bss
; define uninitialized data here

SECTION .text
global _main
_main:

; put your code here.



; Normal termination code
mov eax, 1
mov ebx, 0
int 80h
