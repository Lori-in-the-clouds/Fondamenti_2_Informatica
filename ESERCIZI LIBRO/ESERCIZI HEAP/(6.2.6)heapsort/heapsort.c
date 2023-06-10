#include <stdlib.h>
#include <string.h>
#include "minheap.h"
void HeapMinHeapSort(Heap* h) {
	if (HeapIsEmpty(h)) return;
	int prev = h->size;
	while (h->size > 1) {
		ElemSwap(&h->data[0], &h->data[h->size - 1]);
		--h->size;
		HeapMinMoveDown(h, 0);
	}
	h->size = prev;
	return;
}