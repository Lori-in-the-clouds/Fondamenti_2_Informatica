#include "elemtype.h"
#include "tree.h"
Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	if (v_size == 0) return TreeCreateEmpty();
	if (v_size == 1) return TreeCreateRoot(v, NULL, NULL);
	ElemType max = v[0];
	int index = 0;
	for (size_t j = 0; j < v_size; j++) {
		if (v[j] > max) {
			max = v[j];
			index = j;
		}
	}
	Node* sx = CreateMaxBinTree(v, index);
	Node* dx = CreateMaxBinTree(v + index + 1, v_size - index - 1);
	return  TreeCreateRoot(&max, sx, dx);
}