#include "minheap.h"
#include <stdlib.h>
void HeapMinMoveDownRec(Heap* h, int i) {
	if (i == 0) {
		if (ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapLeft(i))) < 0 && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapRight(i))) < 0) {
			return;
		}
	}
	if ((ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i))) > 0)) {
		if ((HeapLeft(i) > (int)h->size - 1)) {
			return;
		}
		//se esiste solo il sinistro
		if ((HeapLeft(i) < (int)h->size) && (HeapRight(i) >= (int)h->size)) {
			if (ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapLeft(i))) < 0) {
				return;
			}
		}
		else {
			if (ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapLeft(i))) < 0 && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapRight(i))) < 0) {
				return;
			}
		}
	}
	//esiste solo il figlio sinistro
	if ((HeapLeft(i) < (int)h->size) && (HeapRight(i) >= (int)h->size)) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapLeft(i)));
		 HeapMinMoveDownRec(h, HeapLeft(i));
	}
	else {
		if (ElemCompare(HeapGetNodeValue(h, HeapLeft(i)), HeapGetNodeValue(h, HeapRight(i))) < 0) {
			ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapLeft(i)));
			 HeapMinMoveDownRec(h, HeapLeft(i));
	}
		else {
			ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapRight(i)));
			 HeapMinMoveDownRec(h, HeapRight(i));
		}
	}
}