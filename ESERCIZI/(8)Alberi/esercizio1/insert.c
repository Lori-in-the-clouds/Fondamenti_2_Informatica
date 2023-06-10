#include "tree.h"
#include <stdlib.h>
//ITERATIVA
Node* BstInsert(const ElemType* e, Node* n) {
	//SE è COMPLETAMENTE NULLO
	if (TreeIsEmpty(n)) {
		n = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
		return n;
	}
	Node* tmp = n;
	while (1) {
		//destra
		if (ElemCompare(e, TreeGetRootValue(tmp)) <= 0) {
			if (TreeIsEmpty(tmp->left)) {
				tmp->left = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
				break;
			}
			tmp = tmp->left;
		}
		//sinistra
		else {
			if (TreeIsEmpty(tmp->right)) {
				tmp->right = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
				break;
			}
			tmp = tmp->right;
		}
	}
	return n;
}

//RICORSIVA
void BstInsertRec2(const ElemType* e, Node* tmp) {
	//sinsitra
	if (ElemCompare(e, TreeGetRootValue(tmp)) <= 0) {
		if (TreeIsEmpty(tmp->left)) {
			tmp->left = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
			return;
		}
		BstInsertRec2(e, tmp->left);
	}
	//destra
	else {
		if (TreeIsEmpty(tmp->right)) {
			tmp->right = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
			return;
		}
		BstInsertRec2(e, tmp->right);
	}
}

Node* BstInsertRec(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n)) {
		n = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
		return n;
	}
	BstInsertRec2(e, n);
	return n;
}



