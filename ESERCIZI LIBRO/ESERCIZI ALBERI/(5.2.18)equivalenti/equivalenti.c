#include "tree.h"
void EquivalentiRec(const Node* t1, const Node* t2,bool *ris) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) return;
	if ((TreeIsEmpty(t1) && !TreeIsEmpty(t2)) || (!TreeIsEmpty(t1) && TreeIsEmpty(t2))) {
		*ris = false;
		return;
	}
	if (!TreeIsLeaf(t1) && !TreeIsLeaf(t2)) {
		if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) *ris = false;
	}
	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) >= 0) {
			if ((*TreeGetRootValue(t1)) % (*TreeGetRootValue(t2)) != 0) *ris = false;
		}
		else {
			if ((*TreeGetRootValue(t2)) % (*TreeGetRootValue(t1)) != 0) *ris = false;
		}
	}
	EquivalentiRec(TreeLeft(t1), TreeLeft(t2),ris);
	EquivalentiRec(TreeRight(t1), TreeRight(t2), ris);
}
bool Equivalenti(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) return true;
	if ((TreeIsEmpty(t1) && !TreeIsEmpty(t2)) || (!TreeIsEmpty(t1) && TreeIsEmpty(t2))) return false;
	bool* ris = true;
	EquivalentiRec(t1, t2,&ris);
	return ris;
}