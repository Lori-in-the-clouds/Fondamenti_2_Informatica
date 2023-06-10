#include "minheap.h"
#include <stdlib.h>
#include <string.h>
void DeleteNode(Heap* h, int k) {
	if (HeapIsEmpty(h)) return;
	if (k < 0 || k >= h->size) return;
	ElemSwap(&h->data[k], &h->data[h->size - 1]);
	ElemDelete(&h->data[h->size - 1]);
	h->data = realloc(h->data,(--h->size)*sizeof(ElemType));
	HeapMinMoveDown(h, k);
	return;
}