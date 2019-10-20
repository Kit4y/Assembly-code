#include "pch.h"
#include <iostream>
#include<stdio.h>
int main() {
	char str1[100];
	char str2[100];
	int index = -1;
	printf("input str1: ");
	scanf("%s", str1);
	printf("input str2: ");
	scanf("%s", str2);
	_asm {
		LEA ESI, str1
		LEA EDI, str2
		XOR EAX, EAX
		CALL myStrlen
		MOV EBX, ECX
		L5 :
		CMP[ESI], 0
			JZ  L0
			LODSW
			REPNZ SCASB
			JZ  L4
			LEA EDI, str2
			MOV ECX, EBX
			JMP L5

			myStrlen :
		XOR ECX, ECX
			L2 :
		CMP[EDI + ECX], 0
			JZ  L1
			INC ECX
			JMP L2

			L1 :
		RET


			L0 :
		MOV index, -1
			JMP L3
			L4 :
		SUB EBX, ECX
			MOV index, EBX
			L3 :
	}
	printf("index: %d", index);

	return 0;
}