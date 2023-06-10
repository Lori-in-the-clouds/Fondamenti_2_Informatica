#include "elemtype.h"
#include "list.h"
#include "next_greater.h"
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
ElemType* NextGreater(const Item* list, size_t* answer_size) {
	if (ListIsEmpty(list)) {
		answer_size[0] = 0;
		return NULL;
	}
	//CALCOLIAMO LUNGHEZZA LISTA 
	answer_size[0] = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		answer_size[0]++;
	}
	int* vcurr = calloc(answer_size[0],sizeof(ElemType));
	int i = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {
		for (Item* tmp1 = tmp->next; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp)) > 0) {
				vcurr[i] = *ListGetHeadValue(tmp1);
				i++;
				break;
			}
			if (ListIsEmpty(tmp1->next)) {
				vcurr[i] = INT_MIN;
				i++;
				break;
			}
		}
	}
	vcurr[answer_size[0] - 1] = INT_MIN;
	return vcurr;
}