#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
int trova_padre(const Node* t, int c) {
    if (TreeIsEmpty(t) || TreeIsLeaf(t)) return 0;
    if (!TreeIsEmpty(TreeLeft(t)) && ElemCompare(TreeGetRootValue(TreeLeft(t)), &c) == 0) return *TreeGetRootValue(t);
    if (!TreeIsEmpty(TreeRight(t)) && ElemCompare(TreeGetRootValue(TreeRight(t)), &c) == 0) return *TreeGetRootValue(t);
    return trova_padre(TreeLeft(t),c) + trova_padre(TreeRight(t),c);
}
int profondita(const Node* t, int i,int c) {
	if (TreeIsEmpty(t)) return 0;
	if (ElemCompare(TreeGetRootValue(t), &c) == 0) return i;
	return profondita(TreeLeft(t), i + 1, c) + profondita(TreeRight(t), i + 1, c);
}
bool Cugini(const Node* t, int a, int b) {
    if (profondita(t, 0, a) != profondita(t, 0, b)) return false;
    if (trova_padre(t, a) == trova_padre(t, b)) return false;
    return true;
}

//int main(void) {
// const ElemType e[] = { 12,4,21,0,2,77,8,9,21,5,18 };
// Node* t = TreeCreateEmpty();
// t = TreeCreateRoot(
//     e,
//     TreeCreateRoot(e + 1, TreeCreateRoot(e + 3, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 6, NULL, NULL)), TreeCreateRoot(e + 4, TreeCreateRoot(e + 7, NULL, NULL), NULL)),
//     TreeCreateRoot(e + 8, TreeCreateRoot(e + 9, NULL, NULL), TreeCreateRoot(e + 10, NULL, NULL))
// );
// Cugini(t, 0, 5);
 /*    12
      /  \
     /    \
    4      21
   / \    / \
  /   \  5  18
 0     2
/ \   /
77  8 9*/
