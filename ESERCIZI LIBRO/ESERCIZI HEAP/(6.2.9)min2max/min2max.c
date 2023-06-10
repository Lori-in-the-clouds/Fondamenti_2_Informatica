#include <stdlib.h>
#include <string.h>
#include "minheap.h"
void HeapMinMoveUpMax(Heap* h, int i) {
    while (i != 0 && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i))) > 0) {
        ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i)));
        i = HeapParent(i);
    }
}
void HeapMin2HeapMax(Heap* h) {
	if (HeapIsEmpty(h)) return;
    Heap* tmp = HeapCreateEmpty();
    tmp->size = h->size;
    tmp->data = malloc(tmp->size * sizeof(ElemType));
    for (int i = 0; i < h->size; i++) {
        tmp->data[i] = ElemCopy(&h->data[i]);
        HeapMinMoveUpMax(tmp, i);
    }
    memcpy(h->data, tmp->data, h->size * sizeof(ElemType));
    HeapDelete(tmp);
}
//oppure usavo minmovedown anche senza tmp ma con il for invertito 