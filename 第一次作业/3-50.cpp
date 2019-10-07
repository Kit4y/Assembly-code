
#include "pch.h"
#include <iostream>

int main()
{
	int a, b;
	char sum[50], sub[50], mul[50];
	scanf("%d%d", &a, &b);
	_asm {
		lea esi, sum
		push esi // 第二个参数
		mov edi, a
		mov esi, b
		add edi, esi
		push edi // 第一个参数
		call DEC2STR
		pop edi
		pop edi

		lea esi, sub
		push esi
		mov edi, a
		mov esi, b
		sub edi, esi
		push edi
		call DEC2STR
		pop edi
		pop edi

		lea esi, mul
		push esi
		mov eax, a
		mov edi, b
		mov edx, 0
		mul edi
		push eax
		call DEC2STR
		pop edi
		pop edi
	}
	printf("sum:%s, sub:%s, mul:%s\n", sum, sub, mul);
	system("pause");
	return 0;
	_asm {	
	DEC2STR:
		push ebp
			mov ebp, esp
			mov ebx, [ebp + 8] 
			mov ecx, [ebp + 12] 
			push ebx
			call DEC_LEN 
			pop ebx
			mov[ecx + eax], 0
			dec eax
			mov esi, eax 
			mov eax, [ebp + 8] // 十进制数
			mov edi, 10 // 除数
			FOR2:
		cmp eax, 0
			jle FOR2_END
			mov edx, 0
			div edi 
			add edx, '0'
			mov[ecx + esi], dl 
			dec esi
			jmp FOR2
			FOR2_END :
		pop ebp
			ret
	}
	_asm {
	DEC_LEN:
		push ebp
			mov ebp, esp
			mov eax, [ebp + 8] // 十进制数
			mov ebx, 0 // 十进制数长度
			mov edi, 10 // 除数
			FOR1 :
			cmp eax, 0
			jle FOR1_END
			mov edx, 0
			div edi // EDX:EAX / EDI
			inc ebx
			jmp FOR1
			FOR1_END :
		mov eax, ebx
			pop ebp
			ret
	}
}