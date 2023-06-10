#define CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "elemtype.h"
#include "tree.h"

Node* rec(FILE* f) {
	char val = 0;
	size_t turn1 = fscanf(f, " %c", &val);
	if (turn1 == EOF) {
		return TreeCreateEmpty();
	}
	if (val == '.') {
		fscanf(f, " %c", &val);
		return TreeCreateRoot(&val, TreeCreateEmpty(), TreeCreateEmpty());
	}
	Node* sx = rec(f);
	Node* dx = rec(f);
	return TreeCreateRoot(&val, sx, dx);
}
Node* TreeRead(const char* filename) {
	if (filename == NULL) return  TreeCreateEmpty();
	FILE* f = fopen(filename, "r");
	if (f == NULL) return TreeCreateEmpty();
	Node* ris = rec(f);
	fclose(f);
	return ris;
}