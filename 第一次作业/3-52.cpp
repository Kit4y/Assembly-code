
#include "pch.h"
#include <iostream>

int main()
{
	char str[100]; // A123We56st002345
	int sum = 0;
	scanf("%s", str);
	_asm {
		lea esi, sum 
		lea ebx, str
		FOR1 :
		cmp[ebx], 0
		je FOR1_END
		mov eax, 0 
		cmp[ebx], '1'
		jl NO_NUM
		cmp[ebx], '9'
		jg NO_NUM
		FOR2 :
		mov ecx, 0 
		cmp[ebx], '0'
		jl NO_NUM
		cmp[ebx], '9'
		jg NO_NUM
		mov cl, [ebx]
		sub ecx, '0'
		mov edx, 0
		mov edi, 10
		mul edi 
		add eax, ecx
		inc ebx
		jmp FOR2
		NO_NUM :
		add[esi], eax
		inc ebx
		jmp FOR1
		FOR1_END :
	}
	printf("%d\n", sum);
	return 0;
}
