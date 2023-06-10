#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "list.h"
Item* Filter(Item* i, ElemType* e) {
	while (ElemCompare(ListGetHeadValue(i), e) == 1) {
		Item* curr = i;
		i = i->next;
		free(curr);
	}
	for (Item* tmp = i; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {
			while (ElemCompare(ListGetHeadValue(tmp->next), e) == 1) {
				ElemDelete(&tmp->next->value);
				Item* curr = tmp->next;
				tmp->next = tmp->next->next;
				free(curr);
			}
	}
	return i;
}