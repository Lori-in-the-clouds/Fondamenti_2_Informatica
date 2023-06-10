#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <string.h>
ElemType KthLeast(const Heap* h, int k) {
	Heap* tmp = HeapCreateEmpty();
	tmp->size = h->size;
	tmp->data = calloc(tmp->size, sizeof(ElemType));
	memcpy(tmp->data, h->data, tmp->size * sizeof(ElemType));
	ElemType min = tmp->data[tmp->size-1];
	ElemType index = 0;
	for (int i = 0; i < k; i++) {
		min = tmp->data[tmp->size - 1];
		for (int j = 0; j < tmp->size; j++) {
			if (tmp->data[j] < min) {
				min = tmp->data[j];
				index = j;
			}
		}
		ElemSwap(&tmp->data[index], &tmp->data[tmp->size - 1]);
		ElemDelete(&tmp->data[tmp->size - 1]);
		tmp->size--;
		tmp->data = realloc(tmp->data, tmp->size*sizeof(ElemType));
		HeapMinMoveDown(tmp, index);
	}
	HeapDelete(tmp);
	return min;
}

//int main(void) {
//	Heap* h = HeapCreateEmpty();
//	h->size = 9;
//	h->data = malloc(h->size * sizeof(ElemType));
//	h->data[0] = 0;
//	h->data[1] = 2;
//	h->data[2] = 4;
//	h->data[3] = 8;
//	h->data[4] = 12;
//	h->data[5] = 18;
//	h->data[6] = 77;
//	h->data[7] = 21;
//	h->data[8] = 9;
//	KthLeast(h, 6);
//}


