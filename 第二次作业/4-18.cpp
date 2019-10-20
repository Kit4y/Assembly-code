// 4-18.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
	char string1[100], string2[100];                   //输入字符串
	char s[200];                             //输出字符串
	printf("请输入第一个字符串：\n");
	scanf("%s", string1);
	printf("请输入第二个字符串：\n");
	scanf("%s", string2);
	_asm {
		lea ebx, s;
		lea esi, string1;
		lea edi, string2;
	lea_char_1:                                 //在目标字符串上存第一个字符串
		mov al, byte ptr[esi];
		inc esi;
		cmp al, 0;
		je lea_char_2;
		mov byte ptr[ebx], al;
		inc ebx;
		jmp lea_char_1;
	lea_char_2:                                 //在目标字符串上存第二个字符串
		mov al, byte ptr[edi];
		inc edi;
		cmp al, 0;
		je lab_3;
		mov byte ptr[ebx], al;
		inc ebx;
		jmp lea_char_2;
	lab_3:
		mov byte ptr[ebx], 0;
	}
	printf("合并后的字符串为：%s\n", s);
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
