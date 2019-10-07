#include "pch.h"
#include <iostream>

int main()
{
	char string1[255];
	int char_count = 0;
	int num_count = 0;
	int other_count = 0;
	scanf("%s", string1);
	_asm {
		lea eax, string1
		mov ebx, 0 // char_count
		mov ecx, 0 // num_count
		mov edx, 0 // other_count
		mov esi, 0 // i
		FOR1:
		cmp[eax + esi], 0
			je OVER
			// 小写字母
			cmp[eax + esi], 'a'
			jb NO_SM_CH
			cmp[eax + esi], 'z'
			ja NO_SM_CH
			inc ebx
			jmp FOR1_END
			NO_SM_CH :
		// 大写字母
		cmp[eax + esi], 'A'
			jb NO_BIG_CH
			cmp[eax + esi], 'Z'
			ja NO_BIG_CH
			inc ebx
			jmp FOR1_END
			NO_BIG_CH :
		// 数字
		cmp[eax + esi], '0'
			jb NO_NUM_CH
			cmp[eax + esi], '9'
			ja NO_NUM_CH
			inc ecx
			jmp FOR1_END
			NO_NUM_CH :
		// 其它
		inc edx
			FOR1_END :
		inc esi
			jmp FOR1
			OVER :
		mov char_count, ebx
			mov num_count, ecx
			mov other_count, edx
	}
	printf("char_count:%d, num_count:%d, other_count:%d\n", char_count, num_count, other_count);
}