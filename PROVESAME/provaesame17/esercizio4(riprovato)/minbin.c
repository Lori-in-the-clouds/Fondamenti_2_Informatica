#include "elemtype.h"
#include "tree.h"
Node* rec(const ElemType* v, size_t v_size) {
	if (v_size == 0) return TreeCreateEmpty();
	if (v_size == 1) {
		return TreeCreateRoot(&v[0], NULL, NULL);
	}
	//troviamo il valore minimo 
	int min = v[0];
	int index = 0;
	for (int j = 0; j < v_size; j++) {
		if (v[j] < min) {
			min = v[j];
			index = j;
		}
	}
	Node* sx = rec(v, index);
	Node* dx = rec(v + index + 1, v_size - index - 1);
	return TreeCreateRoot(v+index, sx, dx);
}
Node* CreateMinBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0) return TreeCreateEmpty();
	return rec(v, v_size);
}

//int main(void) {
//	int v[] = { 3,2,1,6,8,5 };
//	Node *ris = CreateMinBinTree(v, 6);
// }