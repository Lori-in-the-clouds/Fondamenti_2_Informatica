#include "tree.h"
#include <stdbool.h>
#include <math.h>
void TreeHeightRec(const Node* t, int* max, int att) {
	if (TreeIsLeaf(t)) {
		if (att > *max) *max = att;
		return;
	}
	TreeHeightRec(TreeLeft(t), max, att + 1);
	TreeHeightRec(TreeRight(t), max, att + 1);
}
int GetBalanceCoeff(const Node* n) {
	if (TreeIsEmpty(n)) return 0;
	int max1 = 0;
	int max2 = 0;
	TreeHeightRec(n->left, &max1, -1);
	TreeHeightRec(n->right, &max2, -1);
	return fabs(max2 - max1);
}
bool TreeIsBalanced(const Node* t) {
	if (GetBalanceCoeff(t) <= 1 && GetBalanceCoeff(t) >= -1) return true;
	return false;
}