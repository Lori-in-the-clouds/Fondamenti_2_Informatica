#include "tree.h"
void TreeHeightRec(const Node* t, int* max,int att) {
	if (TreeIsEmpty(t)) {
		if (att > *max) *max = att;
		return;
	}
	TreeHeightRec(TreeLeft(t), max,att + 1);
	TreeHeightRec(TreeRight(t), max,att + 1);
}
int TreeHeight(const Node* t) {
	if (TreeIsEmpty(t)) return -1;
	int max = 0;
	TreeHeightRec(t, &max,-1);
	return max;
}