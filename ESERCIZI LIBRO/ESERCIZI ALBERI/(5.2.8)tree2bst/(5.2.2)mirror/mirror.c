#include "tree.h"
#include <stdbool.h>
void TreeIsMirrorRec(Node* t1, Node* t2,bool *control) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) return;
	if ((TreeIsEmpty(t1) && !TreeIsEmpty(t2)) || (!TreeIsEmpty(t1) && TreeIsEmpty(t2))) {
		*control = false;
		return;
	}
	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
		*control = false;
		return;
	}
	TreeIsMirrorRec(TreeLeft(t1), TreeRight(t2),control);
	TreeIsMirrorRec(TreeRight(t1), TreeLeft(t2),control);
}
bool TreeIsMirror(Node* t) {
	if (TreeIsEmpty(t) || (TreeIsEmpty(t->left) && TreeIsEmpty(t->right))) return true;
	bool control = true;
	TreeIsMirrorRec(TreeLeft(t),TreeRight(t),&control);
	return control;
}