#include "tree.h"
#include <stdio.h>
void PrintLevel(Node *t,int i,int n) {
	if (TreeIsEmpty(t)) return;
	if (i == n) {
		printf("%d ", t->value);
		return;
	}
	PrintLevel(TreeLeft(t), i + 1, n);
	PrintLevel(TreeRight(t), i + 1, n);
}
void Height(Node* t,int *level,int att) {
	if (TreeIsEmpty(t)) {
		if (att > *level) *level = att;
		return;
	}
	Height(TreeLeft(t), level,att+1);
	Height(TreeRight(t), level,att+1);
}
void LevelOrder(const Node* t) {
	if (TreeIsEmpty(t)) return;
	int level = 0;
	Height(t, &level,0);
	for (int n = 0; n < level; n++) {
		PrintLevel(t, 0,n);
	}
	return;
}
