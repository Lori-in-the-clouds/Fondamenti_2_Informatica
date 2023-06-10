#include "minheap.h"
#include <stdlib.h>
#include <string.h>
extern void DeleteNode(Heap* h, int k);
int main(void) {
	ElemType v[] = { 0,12,4,21,2,18,77,8,9 };
	size_t size = sizeof(v) / sizeof(ElemType);
	Heap* h = HeapCreateEmpty();
	h->size = size;
	h->data = malloc(size * sizeof(ElemType));
	memcpy(h->data, v, h->size * sizeof(ElemType));
	DeleteNode(h, 2);
	HeapWriteStdout(h);
}
