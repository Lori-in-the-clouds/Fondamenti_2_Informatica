#include "minheap.h"
#include <stdlib.h> 
void HeapMinHeapsort(Heap* h) {
	size_t e = h->size;
	while (h->size>1) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h,h->size-1));
		h->size--;
		HeapMinMoveDown(h, 0);
	}
	h->size = e;
	return;
}