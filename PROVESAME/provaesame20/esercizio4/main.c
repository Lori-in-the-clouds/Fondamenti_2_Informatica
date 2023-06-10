#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
extern Node* TreeRead(const char* filename);
int main(void) {
	char s[] = { "prova.txt" };
	TreeRead(s);
	return 0;
}