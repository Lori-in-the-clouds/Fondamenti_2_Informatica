#include "elemtype.h"
#include "tree.h"
int MAX(int a, int b) {
	if (a >= b) return a;
	else return b;
}
void level(const Node* t, int* max, int i) {
	if (TreeIsEmpty(t)) {
		if (i > *max) {
			*max = i;
		}
		return;
	}
	level(TreeLeft(t), max, i + 1);
	level(TreeRight(t), max, i + 1);

}
int Diameter(const Node* t) {
	if (TreeIsEmpty(t)) return  0;
	int sx = Diameter(TreeLeft(t));
	int dx = Diameter(TreeRight(t));
	int max1 = 1;
	int max2 = 1;
	level(TreeLeft(t), &max1, 0);
	level(TreeRight(t), &max2, 0);
	return MAX(MAX(sx, dx), max1 + max2 + 1);
}