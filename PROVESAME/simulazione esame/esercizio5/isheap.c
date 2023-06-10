#include <stdlib.h>
#include <string.h>
#include "minheap.h"
bool IsHeapRec(const Heap* h,int i) {
	if (i >= (int)h->size) return true;
	if (h->data[HeapParent(i)] > h->data[i]) return false;
	return IsHeapRec(h,HeapLeft(i)) && IsHeapRec(h, HeapRight(i));
}
bool IsHeap(const Heap* h) {
	if (HeapIsEmpty(h)) return false;
	return IsHeapRec(h, 0);
}