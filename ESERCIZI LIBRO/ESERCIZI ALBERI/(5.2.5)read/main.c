#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdio.h>
extern Node* TreeRead(const char* filename);
int main(void) {
	char* filename = "prova.txt";
	TreeRead(filename);
}