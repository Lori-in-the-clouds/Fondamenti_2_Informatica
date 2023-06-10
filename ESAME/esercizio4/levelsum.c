#include "elemtype.h"
#include "tree.h"
void rec(const Node* t, size_t level, int* ris,int i) {
	if (TreeIsEmpty(t)) return;
	
	rec(TreeLeft(t), level, ris, i + 1);
	if (i == (int)level) {
		ris[0] += *TreeGetRootValue(t);
	}
	rec(TreeRight(t), level, ris, i + 1);
}
int LevelSum(const Node* t, size_t level) {
	if (TreeIsEmpty(t)) return 0;
	int  ris = 0;
	rec(t, level, &ris,0);
	return ris;
}