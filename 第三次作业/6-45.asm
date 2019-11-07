;---- code segement ----
    section code
start:
    org 100H ; 
    mov ax, 0F000H
    mov es, ax
    mov bx, 0FFF0H ; es:bx = 0FFFF0H
    mov di, 0
function1:
    cmp di, 8
    je over_function1
    mov al, BYTE [es:bx+di]
    shr al, 4
    call toHexAscii_func ; 
    call print_Char

    mov al, BYTE [es:bx+di]
    and al, 0FH
    call toHexAscii_func ; 
    call print_Char

    inc di
    jmp function1
over_function1:
    ; mov [param1], bp
    ; mov WORD [param2], 8
    ; call printStr
    mov ah, 4CH
    int 21H ; 

toHexAscii_func:
    cmp al, 9
    ja toHexAscii_func_aboveNine
    add al, '0'
    jmp toHexAscii_func_return
toHexAscii_func_aboveNine:
    sub al, 10
    add al, 'A'
toHexAscii_func_return:
    ret
print_Char:
    mov dl, al ; 待显示的字符
    mov ah, 2
    int 21H ; 显示该字符
    ret
