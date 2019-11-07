; 程序描述：接收用户从键盘输入的两个十进制整数，然后计算并输出这两个数的和与差

%define SPACE 20H ; 空格
%define ENTER 0DH ; 回车

;---- code segment ----
    section code
    org 100H
start:


    mov dx, prompt
    call printStr ; 打印提示信息
    call getDec
    mov [a], ax
    call getDec
    mov [b], ax
    ; prompt sum
    mov dx, sumStr
    call printStr
    ; 求和
    mov ax, [a]
    add ax, [b]
    call printDec_to_up
    ; 换行
    mov dx, newline
    call printStr
    ; prompt diff
    mov dx, diffStr
    call printStr
    ; 求差
    mov ax, [a]
    cmp ax, [b]
    jle b_sub_a
    sub ax, [b]
    call printDec_to_up
    jmp over
b_sub_a:
    mov ax, [b]
    sub ax, [a]
    call printDec_to_up
over:
    mov ah, 4CH
    int 21H ; 返回操作系统



printDec_to_up:
    push bx
    mov si, 0 ; 十进制数的位数

printDec_to_up_function1:
    cmp ax, 0
    je printDec_to_up_for2
    mov dx, 0
    mov di, 10
    div di ; (dx:ax)/10 = ax...dx
    push dx ; 
    add si, 1 ; 
    jmp printDec_to_up_function1

printDec_to_up_for2:
    cmp si, 0
    je printDec_to_up_return
    pop dx
    add dl, '0'
    call putOutChar
    dec si
    jmp printDec_to_up_for2
printDec_to_up_return:
    pop bx
    ret

getDec:
    push bx
    mov bx, 0 ; sum，最终数
    mov ax, 0
getDec_for1:
    call getChar
    ; 遇到回车
    cmp al, ENTER
    je getDec_return
    ; 遇到空格
    cmp al, SPACE
    je getDec_return
    sub al, '0'
    imul bx, 10 ; sum = sum*10 + num
    mov ah, 0
    add bx, ax
    jmp getDec_for1
getDec_return:
    mov ax, bx
    pop bx
    ret

printStr:
    ; mov ah, 9
    ; int 21H
    ; ret
    push bx
    mov bx, dx
printStr_for1:
    mov dl, [bx]
    cmp dl, '$'
    je printStr_return
    call putOutChar
    inc bx
    jmp printStr_for1
printStr_return:
    pop bx
    ret


putOutChar:
    mov ah, 2
    int 21H ; 显示该字符
    ret

getChar:
    mov ah, 1
    int 21H ; 从键盘读取字符保存到al中
    ret


;---- data segment ----
    section data
prompt  db "please input two nums(when the num is complete, please press Enter or Space):", 0DH, 0AH, '$'
a       dw 0
b       dw 0
sum     dw 0
diff    dw 0
sumStr  db "sum: ", '$'
diffStr db "diff: ", '$'
newline db 0DH, 0AH, '$'
