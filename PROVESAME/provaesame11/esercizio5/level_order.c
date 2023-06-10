#include "tree.h"
#include <stdio.h>
//troviam il livello
void maxLevel(const Node* t,int i,int *ris) {
	if (TreeIsEmpty(t)) return;
	if (i > ris[0]) {
		ris[0] = i;
	}
	maxLevel(TreeLeft(t),i + 1,ris);
	maxLevel(TreeRight(t),i + 1,ris);
}
void PrintLevel(const Node* t, int i, int level) {
	if (TreeIsEmpty(t)) return;
	if (i == level) {
		printf("%d ", *TreeGetRootValue(t));
	}
	PrintLevel(TreeLeft(t), i + 1, level);
	PrintLevel(TreeRight(t), i + 1, level);
}
void LevelOrder(const Node* t) {
	int maxlevel = 0;
	maxLevel(t, 0, &maxlevel);
	for (int j = 0; j <= maxlevel; j++) {
		PrintLevel(t, 0, j);
	}
	return;
}
/*      12
	  /  \
	 /    \
	4      21
   / \    / \
  /   \  5  18
 0     2
/ \   /
77  8 9*/