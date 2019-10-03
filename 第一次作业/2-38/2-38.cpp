// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
	char s[21] = { 140,140,'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',0 };
	int word_num = 0, douword_num = 0;
	_asm {
		XOR EAX,EAX
		LEA EBX,s
		XOR ECX,ECX
		XOR EDX,EDX
		LOOOP:
			CMP [EBX],0
			JE LOOOPMOVTEN
            
			MOV CX,[EBX]
			CMP CX,0
            JLE INCRIG
			INC EAX

		INCRIG:
			INC EBX
			INC EBX
			JMP LOOOP

		LOOOPMOVTEN:
			MOV word_num,EAX

		XOR EAX, EAX
		LEA EBX, s
		XOR ECX, ECX
		XOR EDX, EDX
		LOOOP1:
			CMP [EBX], 0
			JE LOOOPMOVFIVE
			MOV ECX, [EBX]
			CMP ECX, 0
			JLE INCDOURIG 
			INC EAX

		INCDOURIG:
			INC EBX
			INC EBX
			INC EBX
			INC EBX
			JMP LOOOP1

		LOOOPMOVFIVE:
			MOV douword_num, EAX


	}
	printf("十个字数据整数中正数有%d个，五个双字数据整数中正数有%d个",word_num,douword_num);
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
