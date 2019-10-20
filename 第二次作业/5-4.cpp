
#include "pch.h"
#include <iostream>
#include<stdio.h>
int main() {
	char c;
	int len = 0;
	char buf[100];
	printf("input char: ");
	c = getchar();
	getchar();
	printf("length: ");
	scanf("%d", &len);
	_asm {
		LEA EDI, buf
		MOV AL, c
		MOV ECX, len
		REP STOSB
		MOV[EDI], 0
	}
	printf("buf: %s", buf);

	return 0;
}