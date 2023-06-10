#include "elemtype.h"
#include "tree.h"
void max_level(const Node* t, int* max, int i) {
	if (TreeIsEmpty(t)) return;
	if (i > *max) *max = i;
	max_level(TreeLeft(t),max, i + 1);
	max_level(TreeRight(t),max, i + 1);
}
void print_level(const Node* t, int level, int i) {
	if (TreeIsEmpty(t)) return;
	if (i == level) printf("%d ",  (int)*TreeGetRootValue(t));
	print_level(TreeLeft(t), level, i + 1);
	print_level(TreeRight(t), level, i + 1);
}
void LevelOrder(const Node* t) {
	if (TreeIsEmpty(t)) return;
	int max = 0;
	max_level(t, &max, 0);
	max++;
	for (int j = 0; j < max; j++) {
		print_level(t, j, 0);
	}
	return;
}