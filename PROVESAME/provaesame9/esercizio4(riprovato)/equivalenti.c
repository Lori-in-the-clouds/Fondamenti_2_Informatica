#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
bool Equivalenti(const Node* t1, const Node* t2) {
	if(TreeIsEmpty(t1) && TreeIsEmpty(t2)) return true;
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) return false;
	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		if (((*TreeGetRootValue(t1)) % (*TreeGetRootValue(t2)) == 0) || ((*TreeGetRootValue(t2)) % (*TreeGetRootValue(t1)) == 0)) return  true;
		else return false;
	}
	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) return false;
	return Equivalenti(TreeLeft(t1), TreeLeft(t2)) && Equivalenti(TreeRight(t1), TreeRight(t2));
}