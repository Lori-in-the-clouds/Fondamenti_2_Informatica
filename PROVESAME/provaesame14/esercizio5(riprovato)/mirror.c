#include "tree.h"
#include "elemtype.h"
#include <stdbool.h>
bool rec(Node* t1, Node* t2) {
	if ((TreeIsEmpty(t1) && !TreeIsEmpty(t2)) || (!TreeIsEmpty(t1) && TreeIsEmpty(t2)))  return false;
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) return true;
	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) return false;
	return rec(TreeLeft(t1), TreeRight(t2)) && rec(TreeRight(t1), TreeLeft(t2));
}
bool TreeIsMirror(Node* t) {
	if (TreeIsEmpty(t)) return true;
	return rec(TreeLeft(t), TreeRight(t));
}