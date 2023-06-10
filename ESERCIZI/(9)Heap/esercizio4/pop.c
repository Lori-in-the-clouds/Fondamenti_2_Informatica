#include "minheap.h"
#include <stdlib.h>
bool HeapMinPop(Heap* h, ElemType* e) {
	if (HeapIsEmpty(h)) return false;
	*e = *HeapGetNodeValue(h, 0);
	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1));
	h->data = realloc(h->data, (--h->size) * sizeof(ElemType));
	HeapMinMoveDown(h, 0);
	return true;
}
