#include "minheap.h"
#include <stdlib.h>
void HeapDeleteNode(Heap* h, int k) {
	if (k < 0 || k >= (int)h->size) return;
	ElemSwap(&h->data[k],&h->data[h->size-1]);
	h->data = realloc(h->data, (--h->size) * sizeof(ElemType));
	for (size_t j = 0; j <h->size; j++) {
		HeapMinMoveDown(h, (int)j);
	}
}