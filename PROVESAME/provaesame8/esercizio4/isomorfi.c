#include "tree.h"
#include <stdbool.h>
bool Isomorfi(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) return true;
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) return false;
	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) return false;
	return (Isomorfi(TreeLeft(t1), TreeLeft(t2)) && Isomorfi(TreeRight(t1), TreeRight(t2))) || (Isomorfi(TreeLeft(t1), TreeRight(t2)) && Isomorfi(TreeRight(t1), TreeLeft(t2)));
}