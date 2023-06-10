#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
void Push(Heap* h, const ElemType* e) {
	h->size++;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	h->data[h->size - 1] = *e;
	HeapMinMoveUp(h, h->size - 1);
	return;
}