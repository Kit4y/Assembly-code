
#include "pch.h"
#include <iostream>
int main()
{
	int data = 0;
	char str1[256];
	scanf("%d", &data);
	_asm {
		lea eax, data
		mov eax, [data] // 整型数
		lea ebx, str1 // 字符串位置
		push ebx
		push eax
		call FUNCTION
		pop ebx
		pop eax
	}
	printf("%s\n", str1);
	return 0;
	_asm {
	FUNCTION:
		push ebp
			mov ebp, esp
			mov eax, [ebp + 8] // 整型数
			mov ebx, [ebp + 12] // 字符串位置
			mov ecx, 0 // 十进制数的长度
			mov edi, 10
			FOR1:
		cmp eax, 0
			je NEXT1
			mov edx, 0
			div edi // EDX:EAX / edi，商放在EAX，余数放在EDX
			add dl, '0'
			mov[ebx + ecx], dl
			inc ecx
			jmp FOR1

			NEXT1 :
		mov[ebx + ecx], 0
			mov eax, ecx
			mov edx, 0
			mov edi, 2
			div edi 
			mov esi, eax
			dec esi
			dec ecx
			FOR2 :
		cmp esi, 0
			jl RET1
			mov edi, ecx // 保存ecx
			sub ecx, esi
			mov dl, [ebx + ecx]
			mov al, [ebx + esi]
			mov[ebx + esi], dl
			mov ecx, edi
			sub ecx, esi
			mov[ebx + ecx], al
			mov ecx, edi 
			dec esi
			jmp FOR2
			RET1 :
		pop ebp
			ret
	}
}