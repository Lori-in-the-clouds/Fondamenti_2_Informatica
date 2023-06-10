#include "tree.h"
#include <limits.h>
const ElemType* BstTreeMin(const Node* n) {
	if (TreeIsEmpty(n)) {
		const ElemType* e = NULL;
		return e;
	}
	const Node* tmp = n;
	const ElemType* min = &n->value;
	while (1) {
		if (TreeIsEmpty(tmp->left)) {
			break;
		}
		const ElemType* e = TreeGetRootValue(tmp->left);
		if (ElemCompare(e,min) <= 0) {
			min = e;
		}
		tmp = TreeLeft(tmp);
	}
	return min;
}
//RICORSIVA
void TreeMinRec(const Node* tmp, const ElemType** min,int i,int *icurr) {
	if (TreeIsEmpty(tmp)) {
		return;
	}
	const ElemType* e = TreeGetRootValue(tmp);
	if (ElemCompare(e, *min) <= 0) {
		if (ElemCompare(e, *min) == 0) {
			if (i <= *icurr) {
				return;
			}
		}
		*min = e;
		*icurr = i;
	}
	TreeMinRec(tmp->right, min,i+1,icurr);
	TreeMinRec(tmp->left, min,i+1,icurr);
}

const ElemType* TreeMin(const Node* n) {
	if (TreeIsEmpty(n)) {
		const ElemType* e = NULL;
		return e;
	}
	int icurr = 0;
	const ElemType c = INT_MAX;
	const ElemType *ris = &c;
	TreeMinRec(n, &ris,0,&icurr);
	return ris;
}
