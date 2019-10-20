#include<stdio.h>
int main() {
	char str1[100];
	int len = 0;
	printf("input str1: ");
	scanf("%s", str1);
	_asm {
		LEA ESI, str1
		CALL myStrlen
		JMP L3

	myStrlen:
		XOR EAX, EAX
	L2:
		CMP [ESI + EAX], 0
		JZ  L1
		INC EAX
		JMP L2
	L1:
		RET

	L3:
		MOV len, EAX
	}
	printf("len: %#d", len);

	return 0;
}