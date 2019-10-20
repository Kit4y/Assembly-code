#include "pch.h"
#include <iostream>
#include<stdio.h>

int main()
{
	char s[100];                         //输入字符串
	char string1[100];                       //过滤后的字符串
	printf("请输入一个字符串：\n");
	scanf("%s", s);
	_asm {
		lea esi, s;
		lea edi, string1;
	s_loop:
		mov dl, byte ptr[esi];
		inc esi;
		cmp dl, 0;
		je s_end;
		call charge_chr;
		cmp eax, 1;
		je s_loop;
		mov byte ptr[edi], dl;
		inc edi;
		jmp s_loop;
	s_end:
		mov byte ptr[edi], 0;
		jmp OK;
	charge_chr:
		xor eax, eax;
		inc eax;              //初始化eax
		cmp dl, 30h;          //判断字符是否是数字字符
		jb lab_end;
		cmp dl, 39h;
		ja lab_1;
		dec eax;
		jmp lab_end;
	lab_1:                        //判断字符是否是大写字母
		cmp dl, 41h;
		jb lab_end;
		cmp dl, 5ah;
		ja lab_2;
		dec eax;
		jmp lab_end;
	lab_2:                        //判断字符是否是小写字母
		cmp dl, 61h;
		jb lab_end;
		cmp dl, 7ah;
		ja lab_end
			dec eax;
	lab_end:
		ret;
	}
OK:
	printf("过滤后的字符串:%s\n", string1);
	return 0;
}