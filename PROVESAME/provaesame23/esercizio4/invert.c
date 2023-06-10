#include "tree.h"
Node* InvertRec(const Node* t) {
	if (TreeIsLeaf(t)) {
		return TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
	}
	Node* sx = InvertRec(TreeRight(t));
	Node* dx = InvertRec(TreeLeft(t));
	return TreeCreateRoot(TreeGetRootValue(t), sx, dx);
}
Node* Invert(Node* t) {
	if (TreeIsEmpty(t)) return TreeCreateEmpty();
	return InvertRec(t);
}