#include "next_greater.h"
#include <limits.h>
#include <stdlib.h>
ElemType* NextGreater(const Item* list, size_t* answer_size) {
	if (ListIsEmpty(list)) {
		*answer_size = 0;
		return NULL;
	}
	int n = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) n++;
	*answer_size = n;
	ElemType* ris = calloc(n, sizeof(ElemType));
	int j = 0;
	for (Item* tmp1 = list; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		bool control = false;
		for (Item* tmp2 = tmp1->next; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp2), ListGetHeadValue(tmp1)) > 0) {
				ris[j] = *ListGetHeadValue(tmp2);
				j++;
				control = true;
				break;
			}
		}
		if (!control) {
			ris[j] = INT_MIN;
			j++;
		}
	}
	return ris;
}
