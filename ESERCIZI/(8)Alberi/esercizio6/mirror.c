#include "tree.h"
#include <stdlib.h>
void TreeIsMirrorRec(const Node* tmp1, const Node* tmp2, bool* control) {
	if (TreeIsEmpty(tmp1) && TreeIsEmpty(tmp2)) {
		return;
	}
	if ((TreeIsEmpty(tmp1) && !TreeIsEmpty(tmp2)) || (!TreeIsEmpty(tmp1) && TreeIsEmpty(tmp2))) {
		*control = false;
		return;
	}
	const ElemType* a = TreeGetRootValue(tmp1);
	const ElemType* b = TreeGetRootValue(tmp2);
	if (ElemCompare(a, b) != 0) {
		*control = false;
	}
	TreeIsMirrorRec(TreeLeft(tmp1), TreeRight(tmp2), control);
	TreeIsMirrorRec(TreeRight(tmp1), TreeLeft(tmp2), control);
}
bool TreeIsMirror(const Node* t) {
	const Node* t1 = TreeCreateEmpty();
	t1 = t;
	bool control = true;
	TreeIsMirrorRec(t, t1, &control);
	return control;
}