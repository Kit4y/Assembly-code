// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int a[14] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,0};
	int obssub = 0;
	int jishu = 0, oushu = 0;
	_asm {
		LEA ECX ,a
		XOR EAX,EAX
		XOR EBX,EBX

		LOOOP1:
		CMP [ECX],0
		JE  LOOOPJiOver

		MOV EDX,[ECX]
		SAL EDX,31

		CMP EDX,0
		JE OushuAdd
       
		ADD EAX, [ECX]
        JMP EXCADD

		OushuAdd:
		ADD EBX, [ECX]
		JMP EXCADD

		EXCADD:
		ADD ECX,4
		JMP LOOOP1

		LOOOPJiOver:
		CMP EAX,EBX
		JAE EAXBIG

	    SUB EBX,EAX
		MOV EAX,EBX

		EAXBIG:
		SUB EAX,EBX

		IBSOVER:
		MOV obssub, EAX

	}
	printf("绝对值差为:%d",obssub);
}

// 判断是否结尾 ECX用来迭代 然后每次判断是否为基数偶数 左移31位，然后和0无符号比较 等于就是偶数 不等于就是基数可以直接加 得到两个值EAX EBX
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
