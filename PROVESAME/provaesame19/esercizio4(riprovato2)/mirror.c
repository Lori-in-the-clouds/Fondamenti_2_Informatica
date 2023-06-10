#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
bool rec(Node* sx, Node* dx) {
	if (TreeIsEmpty(sx) && TreeIsEmpty(dx)) return true;
	if ((!TreeIsEmpty(sx) && TreeIsEmpty(dx)) || TreeIsEmpty(sx) && !TreeIsEmpty(dx)) return false;
	if (ElemCompare(TreeGetRootValue(sx), TreeGetRootValue(dx)) != 0) return false;
	return rec(TreeLeft(sx), TreeRight(dx)) && rec(TreeRight(sx), TreeLeft(dx));
}
bool TreeIsMirror(Node* t) {
	if (TreeIsEmpty(t)) return true;
	return rec(TreeLeft(t), TreeRight(t));
}