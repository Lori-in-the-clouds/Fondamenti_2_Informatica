#include <stdlib.h>
#include "list.h"
#include "list.h"
#include <stdlib.h>
#include <limits.h>
Item* ConcatenaN(Item** v, size_t v_size) {
	Item* head = ListCreateEmpty();
	Item* last = ListCreateEmpty();
	for (int i = 0; i < v_size; i++) {
		if (!ListIsEmpty(v[i])) {
			if (ListIsEmpty(head)) {
				head = v[i];
			}
			else {
				last->next = v[i];
			}

			while (!ListIsEmpty(ListGetTail(v[i]))) {
				v[i] = ListGetTail(v[i]);
			}
			last = v[i]; //collegamento con head, mantine il punto su quello procedente partendo dall'head
		}
	}
	return head;
}
Item* BucketSort(Item* l) {
	//cerca n
	int n = 0;
	for (Item* tmp = l; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) n++;
	//troviamo il max e il min 
	ElemType min = INT_MAX;
	ElemType max = INT_MIN;
	for (Item* tmp = l; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(&max, ListGetHeadValue(tmp)) < 0) max = *ListGetHeadValue(tmp);
		if (ElemCompare(&min, ListGetHeadValue(tmp)) > 0) min = *ListGetHeadValue(tmp);
	}
	if ((n < 1) || (min == max)) {
		return l;
	}
	//creaiamo il bucket
	Item** v = calloc(n, sizeof(Item));
	//mettiamo gli elementi nel bucket
	for (Item* tmp = l; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		int cont = (n - 1) * ((*ListGetHeadValue(tmp)) - min) / (max - min);
		v[cont] = ListInsertBack(v[cont], ListGetHeadValue(tmp));
	}
	ListDelete(l);
	for (int j = 0; j < n; j++) {
		v[j] = BucketSort(v[j]);
	}
	Item* ris = ConcatenaN(v, n);
	free(v);
	return ris;
}