#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "elemtype.h"

Node *rec(FILE* f) {
	ElemType a = 0;
	size_t turn1 = fscanf(f, " %c",&a);
	if (turn1 == EOF) return TreeCreateEmpty();
	if (a == '.') {
		turn1 = fscanf(f, " %c", &a);
		return TreeCreateRoot(&a, TreeCreateEmpty(), TreeCreateEmpty());
	}
	Node* sx = rec(f);
	Node* dx = rec(f);
	return TreeCreateRoot(&a, sx, dx);
}
Node* TreeRead(const char* filename) {
	if (filename == NULL) return TreeCreateEmpty();
	FILE* f = fopen(filename, "r");
	if (f == NULL) return TreeCreateEmpty();
	Node *ris = rec(f);
	fclose(f);
	return ris;
}