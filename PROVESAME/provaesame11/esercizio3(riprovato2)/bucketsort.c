#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
Item* BucketSort(Item* l) {
	int max = 0;
	int min = 0;
	int size = 0;
	GetMinMaxSize(l, &min, &max, &size);
	if (min == max) return l;
	if (size < 2) return l;
	Item** v = calloc(size, sizeof(Item));
	for (Item* tmp = l; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		int index = ((size - 1) * (*ListGetHeadValue(tmp) - min)) / (max - min);
		v[index] = ListInsertBack(v[index],ListGetHeadValue(tmp));
	}
	ListDelete(l);
	for (int j = 0; j < size; j++) {
		v[j] = BucketSort(v[j]);
	}
	Item* ris = ListCreateEmpty();
	for (int j = 0; j < size; j++) {
		ris = ConcatList(ris, v[j]);
	}
	free(v);
	return ris;
}
