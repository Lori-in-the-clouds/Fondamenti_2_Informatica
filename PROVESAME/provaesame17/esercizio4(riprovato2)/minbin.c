#include "elemtype.h"
#include "tree.h"
Node* CreateMinBinTree(const ElemType* v, size_t v_size) {
	if (v_size == 0) return TreeCreateEmpty();
	if (v_size == 1) return TreeCreateRoot(v, NULL, NULL);
	//troviamo il min 
	int min = v[0];
	int index = 0;
	for (int j = 0; j < v_size; j++) {
		if (v[j] < min) {
			min = v[j];
			index = j;
		}
	}
	Node* sx = CreateMinBinTree(v, index);
	Node* dx = CreateMinBinTree(v + index + 1, v_size - index - 1);
	return TreeCreateRoot(&min, sx, dx);
}



int main(void) {
	int v[] = { 3,2,1,6,8,5 };
	Node* ris = CreateMinBinTree(v, sizeof(v) / sizeof(int));
}