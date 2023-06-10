#include "minheap.h"
#include <stdlib.h>
extern void Push(Heap* h, const ElemType* e);
int main(void) {
	int v[] = { 3,5,4,7,8,20,16 };
	Heap* h = HeapCreateEmpty();
	h->size = 7;
	h->data = malloc(h->size * sizeof(ElemType));
	for (size_t i = 0; i < h->size; i++) {
		h->data[i] = v[i];
	}
	ElemType e = 0;
	Push(h, &e);


}