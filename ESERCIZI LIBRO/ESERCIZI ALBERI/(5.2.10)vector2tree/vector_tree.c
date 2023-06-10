#include "vector_tree.h"
#include <limits.h>
void Vector2TreeRec(ElemType* v, size_t v_size, Node** ris,int i,enum TreeType type) {
	if (type == kZeroBased) {
		if ((2 * i) + 1 >= v_size) {
			return;
		}
		Node* tmp = *ris;
		if (v[(2 * i) + 1] == INT_MAX) tmp->left = TreeCreateEmpty();
		tmp->left = TreeCreateRoot(&v[(2 * i) + 1], TreeCreateEmpty(), TreeCreateEmpty());
		if (v[(2 * i) + 2] == INT_MAX) tmp->right = TreeCreateEmpty();
		tmp->right = TreeCreateRoot(&v[(2 * i) + 2], TreeCreateEmpty(), TreeCreateEmpty());
		Vector2TreeRec(v, v_size, &(*ris)->left, (2 * i) + 1, type);
		Vector2TreeRec(v, v_size, &(*ris)->right, (2 * i) + 2, type);
	}
	else {
		if (2 * i >= v_size) {
			return;
		}
		Node* tmp = *ris;
		if (v[2 * i] == INT_MAX) tmp->left = TreeCreateEmpty();
		tmp->left = TreeCreateRoot(&v[2 * i], TreeCreateEmpty(), TreeCreateEmpty());
		if (v[(2 * i) + 1] == INT_MAX) tmp->right = TreeCreateEmpty();
		tmp->right = TreeCreateRoot(&v[(2 * i) + 1], TreeCreateEmpty(), TreeCreateEmpty());
		Vector2TreeRec(v, v_size, &(*ris)->left, 2 * i, type);
		Vector2TreeRec(v, v_size, &(*ris)->right, (2 * i) + 1, type);
	}
}
Node* Vector2Tree(const ElemType* v, size_t v_size, enum TreeType type) {
	Node* ris = TreeCreateEmpty();
	if (type == kZeroBased) {
		ris = TreeCreateRoot(&v[0], TreeCreateEmpty(), TreeCreateEmpty());
		Vector2TreeRec(v, v_size, &ris,0,kZeroBased);
	}
	else {
		ris = TreeCreateRoot(&v[1], TreeCreateEmpty(), TreeCreateEmpty());
		Vector2TreeRec(v, v_size, &ris, 1,kOneBased);
	}
	return ris;
}