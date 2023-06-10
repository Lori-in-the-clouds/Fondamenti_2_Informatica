#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
extern int GruppiNoRep(const char* filename, int n);
int main(void) {
	char* filename = "prova.txt";
	GruppiNoRep(filename, 2);
	return 0;
}