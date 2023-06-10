#include "tree.h"
#include <stdlib.h>

Node* Vector2Bst(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size <= 0) return TreeCreateEmpty();
	Node* ris = TreeCreateRoot(&v[0], TreeCreateEmpty(), TreeCreateEmpty());
	
	for (int i = 1; i < v_size; i++) {
		Node* tmp = ris;
		while (true) {
			//sinistra
			if (ElemCompare(&v[i],TreeGetRootValue(tmp)) < 0) {
				if (TreeIsEmpty(tmp->left)) {
					tmp->left = TreeCreateRoot(&v[i],TreeCreateEmpty(), TreeCreateEmpty());
					break;
				}
				else {
					tmp = TreeLeft(tmp);
					continue;
				}
			}
			//destra
			 if (ElemCompare(&v[i],TreeGetRootValue(tmp)) > 0) {
				if (TreeIsEmpty(tmp->right)) {
					tmp->right= TreeCreateRoot(&v[i], TreeCreateEmpty(), TreeCreateEmpty());
					break;
				}
				else {
					tmp = TreeRight(tmp);
					continue;
				}
			}
			 else {
				 break;
			 }
		}
	}
	return ris;
}
//8, 2, 4, 5, 2, 1, 9