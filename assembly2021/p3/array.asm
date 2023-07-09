; Syed Saadat
; CSC 322 10-11-21
; Program 3 - Summing Arrays
; Adding arrays and storing the total sum

SECTION .data

bArray :	db	-10, -20, -30, -40, -50
wArray :	dw	1,2,3,4,5
dArray : 	dd	322, 322h, 322q, 1833, 1833h
bArraySum :  	db	0
wArraySum : 	dw	0
dArraySum :	dd	0
grandTotal :	dd	0


SECTION .txt
global _main
_main : 

; sum of elements in bArray
mov ax, [bArray]
add ax, [bArray]
mov [bArraySum], ax

; sum of elements in wArray
mov eax, [wArray]
add eax, [wArray]
mov [wArraySum], eax

; sum of elements in dArray
mov ecx, [dArray]
add ecx, [dArray]
mov [dArraySum], ecx

; grand sum 
mov eax, [bArraySum]
add eax, [wArraySum]
add eax, [dArraySum]

lastBreak : 

mov eax, 1
mov ebx, 0
int 80h
