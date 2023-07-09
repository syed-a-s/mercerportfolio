; NAME          : Syed Saadat
; Assignment    : Matrix Management
; Date          : 11-1-21
; Etc...        :

ROWS: EQU 5
COLS: EQU 7

SECTION .data
MyMatrix:       dw       1,  2,  3,  4,  5,  6,  7
                dw       8,  9, 10, 11, 12, 13, 14
                dw      15, 16, 17, 18, 19, 20, 21
                dw      22, 23, 24, 25, 26, 27, 28
                dw      29, 30, 31, 32, 33, 34, 35
saveECX: dw 0
saveTopCol: dd 0

SECTION .bss
RowSums: RESW ROWS
ColSums: RESW COLS
Sum:     RESW 1

SECTION .text
global _start
_start:

; Storing the sum of each row
mov edx, RowSums
xor ebx, ebx
mov ecx, ROWS
outer:
        mov [saveECX], ecx
        mov ecx, COLS

        inner:
                mov ax, [MyMatrix+ebx]
                add ebx, 2
                add [edx], ax
                loop inner

        add edx, 2
        mov ecx, [saveECX]
        loop outer

; storing the sum of each column
mov edx, ColSums
mov ecx, COLS
outer1:
        mov ebx, MyMatrix
        mov [saveECX], ecx
        mov ecx, ROWS

        inner1:
                mov ax, [ebx]
                add ebx, 2*COLS
                add [edx], ax
                loop inner1

        mov [MyMatrix], ebx
        add ebx, 2
        add edx, 2
        mov ecx, [saveECX]
        loop outer1

; finding the grand sum
mov edx, Sum
mov ebx, MyMatrix
mov ecx, 35
outer2:
        mov ax, [ebx]
        add [edx], ax
        add ebx, 2
        loop outer2

; Normal termination code
mov eax, 1
mov ebx, 0
int 80h
