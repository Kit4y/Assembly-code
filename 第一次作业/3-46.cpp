
#include "pch.h"
#include <iostream>

int main()
{
		const char source_chs[11] = { "AEIOUaeiou" };
		char str1[256];
		char res[256];
		scanf("%s", str1);
		_asm {
			lea ebx, str1 
			mov edi, 0 
			FOR1:
			cmp[ebx], 0
				je FOR1_END
				lea ecx, source_chs 
				FOR2 :
			cmp[ecx], 0
				je FOR2_END
				mov al, [ecx]
				cmp al, [ebx]
				jne NO_FIND
				inc edi
				jmp FOR2_END
				NO_FIND :
			inc ecx
				jmp FOR2
				FOR2_END :
			inc ebx
				jmp FOR1
				FOR1_END :

			lea eax, res
				push eax
				push edi
				call DEC2OCTSTR
				pop esi
				pop esi
		}
		printf("八进制: O%s\n", res);
		system("pause");
		return 0;
		_asm {
		DEC2OCTSTR:
			push ebp
				mov ebp, esp
				mov ebx, [ebp + 8]
				mov ecx, [ebp + 12] 

				push ebx
				call OCT_LEN 
				pop ebx

				mov[ecx + eax], 0
				dec eax

				mov ebx, [ebp + 8] 
				FOR3:
			cmp ebx, 0
				je FOR3_END
				mov edx, ebx
				and ebx, 111B 

				add bl, '0'
				mov[ecx + eax], bl

				shr edx, 3
				mov ebx, edx
				dec eax
				jmp FOR3
				FOR3_END :
			pop ebp
				ret
		}
		_asm {
		OCT_LEN:
			push ebp
				mov ebp, esp
				mov ebx, [ebp + 8] // 第一个参数，即十进制数
				mov eax, 0 // 返回八进制数的长度
				FOR4 :
				cmp ebx, 0
				je FOR4_END
				shr ebx, 3
				inc eax
				jmp FOR4
				FOR4_END :
			pop ebp
				ret
		}
}