#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
extern int Gruppi(const char* filename, int n);
int main(void) {
	char* filename = "prova.txt";
	Gruppi(filename, 3);
	return 0;
}