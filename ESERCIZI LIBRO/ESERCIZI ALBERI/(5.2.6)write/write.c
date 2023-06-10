#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdio.h>
void TreeWriteRec(Node* t, FILE* f,int i) {
	if (TreeIsEmpty(t)) return;
	for (int j = 0; j < i; j++) fprintf(f, "    ");
	if (TreeIsLeaf(t)) fprintf(f, ".%d\n", *TreeGetRootValue(t));
	else fprintf(f, "%d\n", *TreeGetRootValue(t));
	TreeWriteRec(TreeLeft(t), f,i + 1);
	TreeWriteRec(TreeRight(t), f,i + 1);
}
bool TreeWrite(const Node* t, const char* filename) {
	if (TreeIsEmpty(t)) return true;
	FILE* f = fopen(filename, "w");
	if (f == NULL) return false;
	TreeWriteRec(t, f,0);
	fclose(f);
	return true;
}