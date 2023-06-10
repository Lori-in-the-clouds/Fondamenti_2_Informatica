#include "tree.h"
#include <stdlib.h>
int comp(const void* a,const void* b) {
	int arg1 = *(const ElemType*)a;
	int arg2 = *(const ElemType*)b;
	return (arg1 > arg2) - (arg1 < arg2);
}
Node* CreateMaxBinTreeRec(const ElemType* v, size_t v_size) {
	if (v_size == NULL) {
		return NULL;
	}
	if (v_size == 1) {
		return TreeCreateRoot(v, NULL, NULL);
	}
	//trovo il max
	ElemType max = v[0];
	int indicemax = 0;
	
	for (size_t j = 0; j < v_size; j++) {
		if (v[j] > max) {
			max = v[j];
			indicemax = j;
		}
	}
	Node* sx = CreateMaxBinTreeRec(v,indicemax);
	Node* dx = CreateMaxBinTreeRec(v+indicemax+1,v_size-1-indicemax);
	return TreeCreateRoot(v + indicemax, sx, dx);
}

Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return NULL;
	}
	return CreateMaxBinTreeRec(v, v_size);
	
}