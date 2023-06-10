#include "tree.h"
#include "elemtype.h"

Node* Invert(Node* t) {
	if (TreeIsEmpty(t)) return TreeCreateEmpty();
	Node* sx = Invert(TreeRight(t));
	Node* dx = Invert(TreeLeft(t));
	return TreeCreateRoot(TreeGetRootValue(t), sx, dx);
}