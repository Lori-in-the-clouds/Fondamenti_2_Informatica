#include <stdlib.h>
#include <string.h>
#include "minheap.h"
ElemType* KthLeast(const Heap* h, int k) {
	if (HeapIsEmpty(h)) return NULL;
	Heap* tmp = HeapCreateEmpty();
	tmp->size = h->size;
	tmp->data = malloc(h->size * sizeof(ElemType));
	for (int i = 0; i < h->size; i++) {
		tmp->data[i] = ElemCopy(HeapGetNodeValue(h, i));
	}
	for (int i = 0; i < k-1; i++) {
		ElemSwap(&tmp->data[0], &tmp->data[tmp->size - 1]);
		tmp->size--;
		HeapMinMoveDown(tmp, 0);
	}
	ElemType wanted = ElemCopy(&tmp->data[0]);
	tmp->size = h->size;
	HeapDelete(tmp);
	return wanted;
}