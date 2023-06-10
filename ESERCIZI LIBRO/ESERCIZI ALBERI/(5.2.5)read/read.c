#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
Node* TreeReadRec(FILE *f) {
	ElemType e = 0;
	size_t turn1 = fscanf(f, " %c", &e);
	if (turn1 != 1) {
		return TreeCreateEmpty();
	}
	if (e == '.') {
		fscanf(f, " %c", &e);
		return TreeCreateRoot(&e, TreeCreateEmpty(), TreeCreateEmpty());
	}
	Node* l = TreeReadRec(f);
	Node* r = TreeReadRec(f);
	return TreeCreateRoot(&e, l, r);
}
Node* TreeRead(const char* filename) {
	if (filename == NULL) return NULL;
	FILE* f = fopen(filename, "r");
	if (f == NULL) return NULL;
	Node *ris = TreeReadRec(f);
}
