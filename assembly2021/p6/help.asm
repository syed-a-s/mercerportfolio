ROWS: EQU 3
COLS: EQU 2

SECTION .data
MyMatrix: dw 1, 2
          dw 4, -2
          dw -10, 8

saveECX: dw 0
saveTopCol: dd 0

SECTION .bss
RowSums: RESW ROWS
ColSums: RESW COLS
Sum:     RESW 1

SECTION .text
global _main
_main:

mov ecx, COLS
mov edx, ColSums
outer:
    mov ebx, MyMatrix       
    mov [saveECX], ecx
    mov ecx, ROWS
    
    inner:
        mov ax, [ebx]
        add ebx, 2*COLS
        add [edx], ax
        loop inner
    
    mov [MyMatrix], ebx
    add ebx, 2
    add edx, 2
    mov ecx, [saveECX]
    loop outer




mov eax, 1
mov ebx, 0
int 80h
