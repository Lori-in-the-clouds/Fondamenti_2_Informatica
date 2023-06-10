#include "minheap.h"
#include <stdlib.h>
void HeapMinMoveUpRec(Heap* h, int i) {
	if (ElemCompare(&h->data[HeapParent(i)],&h->data[i]) < 0) {
		return;
	}
	if (i % 2 == 0) {
		ElemType e = *HeapGetNodeValue(h, i);
		h->data[i] = *HeapGetNodeValue(h, (i / 2)-1);
		h->data[(i / 2)-1] = e;
	}
	else {
		ElemType e = *HeapGetNodeValue(h, i);
		h->data[i] = *HeapGetNodeValue(h, (i / 2));
		h->data[(i / 2)] = e;
	}
	HeapMinMoveUpRec(h, HeapParent(i));
}
