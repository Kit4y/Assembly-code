// 4-18.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stdio.h>

int main()
{
	char string1[100], string2[100];               //输入字符串
	int location;                            //位置值
	printf("请输出第一个字符串：\n");
	scanf("%s", string1);
	printf("请输入第二个字符串：\n");
	scanf("%s", string2);
	_asm {
		xor ecx, ecx;
		dec ecx;                             //ecx为位置值
		lea esi, string1;
	out_loop:		                             //外层循环扫描string1
		mov al, byte ptr[esi];
		inc ecx;
		inc esi;
		cmp al, 0;
		je no_init;
		lea edi, string2;
	in_loop:                                     //内层循环扫描string2
		mov dl, byte ptr[edi];
		inc edi;
		cmp dl, 0;
		je out_loop;
		cmp dl, al;
		je yes_init;
		jmp in_loop;
	no_init:                                        //未出现
		xor ecx, ecx;
		dec ecx;
		lea ebx, location;
		mov[ebx], ecx;
	yes_init:                                       //出现
		lea ebx, location;
		mov[ebx], ecx;
	}
	printf("位置值：%d\n", location+1);
	return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
