#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>

bool Pop(Heap* h, ElemType* e) {
	if (h->size < 1) {
		return false;
	}
	*e = *HeapGetNodeValue(h, 0);
	ElemSwap(HeapGetNodeValue(h, 0),HeapGetNodeValue(h, (int)h->size - 1));
	h->data = realloc(h->data, (--h->size) * sizeof(ElemType));
	HeapMinMoveDown(h, 0);
	return true;

}