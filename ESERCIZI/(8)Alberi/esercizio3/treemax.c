#include "tree.h"
#include <stdlib.h>
const ElemType* BstTreeMax(const Node* n) {
	if (TreeIsEmpty(n)) {
		const ElemType* e = NULL;
		return e;
	}
	const Node* tmp = n;
	const ElemType *max = &n->value;
	while (1) {
		if (TreeIsEmpty(tmp->right)) {
			break;
		}
		const ElemType* e = TreeGetRootValue(tmp->right);
		if (*e > *max) {
			max = e;
		}
		tmp = TreeRight(tmp);
	}
	return max;
}
//RICORSIVA
void TreeMaxRec(const Node* tmp,const ElemType **max) {
	if (TreeIsEmpty(tmp)) {
		return;
	}
	const ElemType* e = TreeGetRootValue(tmp);
	if (ElemCompare(e, *max) > 0) {	
		*max = e;
	}
	TreeMaxRec(tmp->left, max);
	TreeMaxRec(tmp->right, max);
}

 const ElemType* TreeMax(const Node* n) {
	 if (TreeIsEmpty(n)) {
		 const ElemType* e = NULL;
		 return e;
	 }
	const ElemType* ris = TreeGetRootValue(n);
	 TreeMaxRec(n, &ris);
	 return ris;
}
