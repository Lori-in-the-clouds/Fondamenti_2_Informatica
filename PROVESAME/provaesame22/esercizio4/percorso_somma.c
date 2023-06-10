#include "tree.h"
#include <stdbool.h>
bool PercorsoSommaRec(Node* t, const ElemType* target,ElemType n) {
	if (TreeIsEmpty(t)) {
		if (n == target[0]) return true;
		else return false;
	}
	return PercorsoSommaRec(TreeLeft(t), target,n + (*TreeGetRootValue(t))) || PercorsoSommaRec(TreeRight(t), target, n + (*TreeGetRootValue(t)));
}
bool PercorsoSomma(Node* t, const ElemType* target) {
	if (TreeIsEmpty(t)) return false;
	return PercorsoSommaRec(t, target, 0);
}