#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>
extern bool Pop(Heap* h, ElemType* e);
int main(void) {
	Heap* h = HeapCreateEmpty();
	h->size = 7;
	int v[] = { 3,5,4,7,8,20,16 };
	h->data = malloc(7 * sizeof(ElemType));
	for (int i = 0; i < h->size; i++) {
		h->data[i] = v[i];
	}
	ElemType e = 0;
	Pop(h, &e);
}