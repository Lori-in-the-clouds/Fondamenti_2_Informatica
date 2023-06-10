#include "tree.h"
Node* rec(const ElemType* v, size_t v_size) {
	if (v_size == 0) {//se non c'è niente ci metti il null
		return NULL;
	}
	if (v_size == 1) {
		return TreeCreateRoot(v, NULL, NULL);
	}
	//trovo il minimo 
	ElemType min = v[0];
	int l = 0;
	for (int j = 0; j < v_size; j++) {
		if (v[j] < min) {
			min = v[j];
			l = j;
		}
	}
	Node* sx = rec(v, l);
	Node* dx = rec(v+l+1, v_size-l-1);
	return TreeCreateRoot(v+l, sx, dx);
}
Node* CreateMinBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL) {
		Node* ris = TreeCreateEmpty();
		return ris;
	}
	int min = v[0];
	int l = 0;
	return rec(v, v_size);
}