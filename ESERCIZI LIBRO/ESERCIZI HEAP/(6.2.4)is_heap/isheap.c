#include "minheap.h"
#include <stdlib.h>
#include <string.h>
void IsHeapRec(const Heap* h, bool* ris,int i) {
	if (i >= h->size) return;
	if (HeapIsEmpty(h)) return;
	if (ElemCompare(&h->data[HeapParent(i)], HeapGetNodeValue(h, i)) > 0) {
		*ris = false;
	}
	IsHeapRec(h, ris,HeapLeft(i));
	IsHeapRec(h, ris,HeapRight(i));
}
bool IsHeapRec2(const Heap* h, int i) {
	if (i >= h->size) return true;
	if (HeapIsEmpty(h)) return true; //questo è un controllo iniziale
	if (ElemCompare(&h->data[HeapParent(i)], HeapGetNodeValue(h, i)) > 0) return false;
	return IsHeapRec2(h, HeapLeft(i)) && IsHeapRec2(h, HeapRight(i));
}
bool IsHeap(const Heap* h) {
	if (HeapIsEmpty(h)) return true;
	bool ris = true;
	IsHeapRec(h,&ris,0);
	return ris;
}