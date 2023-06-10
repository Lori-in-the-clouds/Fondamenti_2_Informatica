#include "elemtype.h"
#include "maxheap.h"
#include <stdlib.h>
void Pop(Heap* h, ElemType* popped) {
	if (h->size == 0) {
		popped = NULL;
		return;
	}
	*popped = ElemCopy(&h->data[0]);
	ElemSwap(&h->data[0], &h->data[h->size - 1]);
	h->size--;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);
	HeapMaxMoveDown(h, 0);
	return;
}
int LastStoneWeight(Heap* h) {
	while (h->size != 0 && h->size != 1) {
		int x = 0;
		int y = 0;
		Pop(h, &y);
		Pop(h, &x);
		if (x == y) continue;
		else {
			y -= x;
			h->size++;
			h->data = realloc(h->data, h->size * sizeof(int));
			h->data[h->size - 1] = y;
			HeapMaxMoveUp(h, h->size - 1);
		}
	}
	if (h->size == 0) return 0;
	else return h->data[0];
}
//int main(void) {
//	Heap* h = HeapCreateEmpty();
//	h->data = malloc(3 * sizeof(int));
//	h->size = 3;
//	h->data[0] = 77;
//	h->data[1] = 21;
//	h->data[2] = 18;
//	LastStoneWeight(h);
//
//}