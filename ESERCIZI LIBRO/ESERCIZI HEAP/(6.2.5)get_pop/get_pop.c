#include "minheap.h"
#include <stdlib.h>
#include "get_pop.h"
ElemType* Get(const Heap* h) {
	if (HeapIsEmpty(h)) return NULL;
	return &h->data[0];
}
void Pop(Heap* h) {
	if (HeapIsEmpty(h)) return;
	ElemSwap(&h->data[0], &h->data[h->size - 1]);
	ElemDelete(&h->data[h->size - 1]);
	h->data = realloc(h->data, (h->size-1) * sizeof(ElemType));
	h->size--;
	HeapMinMoveDown(h, 0);
	return;
 }
