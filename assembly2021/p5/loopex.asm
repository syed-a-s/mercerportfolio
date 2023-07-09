; NAME
; Assignment
; Date
; Etc...

SECTION .data
; define data/variables here.  Think DB, DW, DD, DQ
array: 	dw	1,2,3,4,5,6,7,100,200,1,1,1,1,1,1,1,1,1,1,1,1
len:	EQU	($-array)/2 	; gives the num of elements in array

SECTION .bss
; define uninitialized data here
sum:	RESW 1
saveECX: RESD 1

SECTION .text
global _main
_main:
;;;;;;;;;;;;;;;;;;;;;   DO THE 5*6 double loop example before summing arrays

	xor	dx,dx  ; place to sum 5*6

	mov	ecx,6
OUT:	
	mov	[saveECX],ecx
	mov	ecx,5
IN:	
	inc	dx
	loop	IN

	mov	ecx,[saveECX]
	loop 	OUT

break1:










; put your code here.
;
;  Sum the array
	xor	ax,ax	;;;; zero out a place for the sum

;  Let ebx point into the array
	mov	ebx,array

;  Let ecx hold count of array size
	mov	ecx,len

;  Loop through array summing the elements
top:
	add	ax,[ebx]
	inc	ebx
	inc	ebx
	loop	top

;  Store our sum in "sum"
	mov	[sum],ax

lastBreak:


; Normal termination code
mov eax, 1
mov ebx, 0
int 80h












