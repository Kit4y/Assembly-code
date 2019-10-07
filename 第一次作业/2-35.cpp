// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>

int main()
{
	char a, b, c, d;
	unsigned short e, f;
	unsigned int g;
	scanf("%c %c %c %c", &a, &b,&c,&d);
	_asm {
		MOV AH, b
		MOV AL,a
		MOV e,AX
		MOV BH,d
		MOV BL,c
		MOV f,BX

		SAL EBX,16
		MOV BX,AX
		MOV g, EBX
	}
	//printf("sum1=%d", e);
	printf("sum1=%d sum2=%d sum3=%d", e,f,g);
	return 0;
}

// 输入aabb得到24929 25186 1650614625
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
