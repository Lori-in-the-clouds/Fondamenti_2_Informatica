#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "tree.h"
#include <stdio.h>

Node* rec(FILE *f) {
	ElemType a = 0;
	size_t turn1 = fscanf(f, " %c", &a);
	if (turn1 == EOF) {
		return TreeCreateEmpty();
	}
	if (a == '.') {
		fscanf(f, " %c", &a);
		return TreeCreateRoot(&a, TreeCreateEmpty(), TreeCreateEmpty());
	}
	Node* sx = rec(f);
	Node* dx = rec(f);
	return TreeCreateRoot(&a, sx, dx);
}
Node* TreeRead(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL)	return TreeCreateEmpty();
	Node *ris = rec(f);
	fclose(f);
	return ris;
}