#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <math.h>
Node* rec(const ElemType* v, size_t v_size) {
	//controllo prima
	if (v_size == 0) return TreeCreateEmpty();
	if (v_size == 1) {
		return TreeCreateRoot(v, TreeCreateEmpty(), TreeCreateEmpty());
	}
	size_t max = v[0];
	size_t index = 0;
	for (int j = 0; j < v_size; j++) {
		if (v[j] > max) {
			max = v[j];
			index = j;
		}
	}
	Node* sx = rec(v,index);
	Node* dx = rec(v + index + 1, v_size-1-index);
	return TreeCreateRoot(v + index, sx, dx);

}
//Node* rec(const ElemType* v, size_t v_size,size_t starter,size_t finisher) {
//	if (finisher == starter) {
//		return TreeCreateEmpty();
//	}
//	if (abs(finisher - starter) == 1) {
//		return TreeCreateRoot(&v[starter], NULL, NULL);
//	}
//
//	size_t max = v[starter];
//	size_t index = 0;
//	for (int j = starter; j < finisher; j++) {
//		if (v[j] > max) {
//			max = v[j];
//			index = j;
//		}
//	}
//	Node* sx = rec(v, v_size, starter, index);
//	Node* dx = rec(v, v_size, index + 1, finisher-1);
//	return TreeCreateRoot(&max, sx, dx);
//}
Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	if (v_size <= 0) return TreeCreateEmpty();
	return rec(v, v_size,0,v_size);
}