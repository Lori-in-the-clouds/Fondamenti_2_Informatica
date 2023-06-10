#include "elemtype.h"
#include "tree.h"
int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}
void level_max(const Node* t,int i,int *max) {
	if (TreeIsEmpty(t)) {
		if (i > *max) {
			*max = i;
		}
		return;
	}
	level_max(TreeLeft(t), i + 1, max);
	level_max(TreeRight(t), i + 1, max);
}

int Diameter(const Node* t) {
	if (TreeIsEmpty(t)) return 0;
	int sx = Diameter(TreeLeft(t));
	int dx = Diameter(TreeRight(t));

	int max1 = 1;
	int max2 = 1;
	level_max(TreeLeft(t),0, &max1);
	level_max(TreeLeft(t),0, &max2);
	return max(max(sx, dx), max1 + max2 + 1);
}

//int main(void) {
//	const ElemType e[] = { 12,4,21,0,2,77,8,9,21,5,18 };
//	Node* t = TreeCreateEmpty();
//	t = TreeCreateRoot(
//		e,
//		TreeCreateRoot(e + 1, TreeCreateRoot(e + 3, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 6, NULL, NULL)), TreeCreateRoot(e + 4, TreeCreateRoot(e + 7, NULL, NULL), NULL)),
//		TreeCreateRoot(e + 8, TreeCreateRoot(e + 9, NULL, NULL), TreeCreateRoot(e + 10, NULL, NULL))
//	);
	/*      12
		 /  \
		/    \
	   4      21
	  / \    / \
	 /   \  5  18
	0     2
   / \   /
  77  8 9*/
//	Diameter(t);
//}