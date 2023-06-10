#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdio.h>
Node* TreeReadRec(FILE *f) {
	ElemType n = 0;
	size_t turn1 = fscanf(f, " %c", &n);
	if (turn1 == EOF) return TreeCreateEmpty();
	if (n == '.') {
		fscanf(f, " %c", &n);
		return TreeCreateRoot(&n, TreeCreateEmpty(), TreeCreateEmpty());
	}
	Node* sx = TreeReadRec(f);
	Node* dx = TreeReadRec(f);
	return TreeCreateRoot(&n, sx, dx);
}

Node* TreeRead(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) return TreeCreateEmpty();
	Node* ris = TreeReadRec(f);
	fclose(f);
	return ris;
}