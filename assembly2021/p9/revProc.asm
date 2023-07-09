; NAME       : Syed Saadat
; DATE       : 11-15-21
; ASSIGNMENT : Reverse Array with Proc

SECTION .data
array1: dd      1,2,3,4,5
len1:   EQU     ($-array1)

array2: dd      -10, -9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9
len2:   EQU     ($-array2)

array3: dd  0,10,20,30,40,50,60,70,80,90
        dd  100,110,120,130,140,150,160,170,180,190
        dd  200,210,220,230,240,250,260,270,280,290
        dd  300,310,320,330,340,350,360,370,380,390
        dd  400,410,420,430,440,450,460,470,480,490,500
len3:   EQU ($-array3)

SECTION .text
global _main
_main:

start:
	mov eax, 322
	
	mov ebx, array1
	mov edx, len1 
	call revArray

	mov ebx, array2
	mov edx, len2
	call revArray

	mov ebx, array3
	mov edx, len3
	call revArray

lastBreak:
; standard termination
mov eax, 1
mov ebx, 0
int 80h 

;;; expects ebx to have the array and edx to have the length of the array
;;; reversed array will be stored back into ebx

revArray:
	pusha
	mov ecx, edx 
	shr ecx, 2	
	; push ever element in array on to stack
	pushElement:
		push dword [ebx]
		add ebx, 4
	loop pushElement	
	xor ebx, ebx
	mov ecx, edx
	shr ecx, 2
	; pop every element back onto array
	popElement:
		pop dword [ebx]
		add ebx, 4
	loop popElement
	popa
	ret
