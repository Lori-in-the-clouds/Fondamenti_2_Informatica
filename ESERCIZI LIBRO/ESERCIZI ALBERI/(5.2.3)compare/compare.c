#include "tree.h"
#include <stdbool.h>
void TreeAreIdenticalRec(const Node* t1, const Node* t2,bool *control) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) return;
	if ((TreeIsEmpty(t1) && !TreeIsEmpty(t2)) || (!TreeIsEmpty(t1) && TreeIsEmpty(t2))) {
		*control = false;
		return;
	}
	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2))!=0) {
		*control = false;
		return;
	}
	TreeAreIdenticalRec(TreeLeft(t1), TreeLeft(t2), control);
	TreeAreIdenticalRec(TreeRight(t1), TreeRight(t2), control);
}
bool TreeAreIdentical(const Node* t1, const Node* t2) {
	bool control = true;
	TreeAreIdenticalRec(t1, t2, &control);
	return control;
}