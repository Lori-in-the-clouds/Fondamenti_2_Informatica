#include "elemtype.h"
#include "tree.h"
#include <stdio.h>
#include <stdbool.h>
bool verifica_level(const Node* t, int level,int i,const ElemType *e) {
	if (TreeIsEmpty(t)) return false;
	if (ElemCompare(TreeGetRootValue(t), e) == 0 && i == level) return true;
	return verifica_level(TreeLeft(t), level, i + 1,e) || verifica_level(TreeRight(t), level, i + 1,e);
}
void rec(const Node *c,const Node* t, int i) {
	if (TreeIsEmpty(t)) return;
	if (verifica_level(c,i,0,TreeGetRootValue(t))) {
		printf("%d ", *TreeGetRootValue(t));
	}
	rec(c,TreeLeft(t),i);
	rec(c,TreeRight(t),i);
}
void levelmax(const Node* t, int i, int* max) {
	if (TreeIsEmpty(t)) return;
	if (i > *max) *max = i;
	levelmax(TreeLeft(t), i + 1, max);
	levelmax(TreeRight(t), i + 1, max);
}
void LevelOrder(const Node* t) {
	if (TreeIsEmpty(t)) return;
	int max = 0;
	levelmax(t, 0, &max);
	for (int j = 0; j <= max; j++) {
		rec(t, t, j);
	}
	return;
}