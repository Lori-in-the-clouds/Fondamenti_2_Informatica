#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
bool TreeContainsNode(const Node* tree, const Node* node,int *control) {
	if (TreeIsEmpty(tree)) return false;
	if (tree == node) {
		control[0]++;
		return true;
	}
	bool a = TreeContainsNode(TreeLeft(tree),node,control);
	bool b = TreeContainsNode(TreeRight(tree), node, control);
	return a || b;
	
}
void rec(const Node* t, const Node* n1, const Node* n2,Node **ris,int level,int *maxlevel) {
	if (TreeIsEmpty(t)) return;
	rec(TreeLeft(t), n1, n2, ris,level +1,maxlevel);
	int control = 0;
	if (TreeContainsNode(t, n1,&control) && TreeContainsNode(t, n2,&control)) {
		if (level >= maxlevel[0]) {
			if (n1 == n2) {
				*ris = n2;
				return;
			}
			if (control != 0) {
				*ris = t;
			}
			maxlevel[0] = level;
		}
	}
	rec(TreeRight(t),n1, n2,ris,level + 1,maxlevel);
}
const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {
	Node* ris = TreeCreateEmpty();
	int maxlevel = 0;
	rec(t, n1, n2,&ris,0,&maxlevel);
	return ris;
}