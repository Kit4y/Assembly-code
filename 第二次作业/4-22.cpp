
#include "pch.h"
#include <iostream>
#include<stdio.h>
int main()
{
	char c;                             //输入字符
	int n;                              //输入数值
	char tar_str[100];                      //目标字符串
	printf("请输入字符：\n");
	scanf("%c", &c);
	printf("请输入数值(>0且≤100)：\n");
	scanf("%d", &n);
	_asm {
		mov al, c;
		lea edi, tar_str;
		mov ecx, n;
		call str_grow;
		jmp END_OK;
	str_grow:
		cld;                              //清方向标志，DF=0，地址从高到低
	s_loop:
		stosb;
		dec ecx;
		cmp ecx, 0;
		jne s_loop;
		mov byte ptr[edi], 0;
		ret;
	}
END_OK:
	printf("生成字符串：%s\n", tar_str);
	return 0;
}