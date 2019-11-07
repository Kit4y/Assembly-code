; 程序描述：以十六进制形式显示对应指令的机器码

;---- code segment ----
    section code
    org 100H ; 不加时输出会乱码
start:

    mov di, target
for1:
    cmp di, ok
    je over_function
    mov al, BYTE [di]
    shr al, 4
    call print_toHexAscii
    call putChar
    mov al, BYTE [di]
    and al, 0FH
    call print_toHexAscii
    call putChar
    inc di
    jmp for1
over_function:
    mov ah, 4CH
    int 21H ;
target:
    jmp short $+2
    jnz next
    jz next
    jmp ok
    jmp short ok
    or ax, ax
next:
    jmp 1234H:5678H
    jmp far [1234H]
    jmp dword [1234H]
    call 1234H:5678H
    call far [5678H]
    call dword [1234H]
ok:
print_toHexAscii:
    and al, 0FH
    cmp al, 9
    ja print_toHexAscii_aboveNine
    add al, '0'
    jmp print_toHexAscii_return
print_toHexAscii_aboveNine:
    sub al, 10
    add al, 'A'
print_toHexAscii_return:
    mov dl, al
    ret
printStr:
    push bx
    mov bx, dx
printStr_for1:
    mov dl, [bx]
    cmp dl, '$'
    je printStr_return
    call putChar
    inc bx
    jmp printStr_for1
printStr_return:
    pop bx
    ret
putChar:
    mov ah, 2
    int 21H ; 显示该字符
    ret
getChar:
    mov ah, 1
    int 21H ; 从键盘读取字符保存到al中
    ret
;---- data segment ----
    section data
