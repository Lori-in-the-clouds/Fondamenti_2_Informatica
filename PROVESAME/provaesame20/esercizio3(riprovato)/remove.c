#include "elemtype.h"
#include "list.h"
#include "remove.h"
#include <stdlib.h>

Item* RemoveDuplicates(Item* i) {
	if (ListIsEmpty(i)) return ListCreateEmpty();
	for (Item* tmp = i; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {
		while (ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(tmp->next)) == 0) {
			ElemDelete(&tmp->next->value);
			Item* curr = tmp->next;
			tmp->next = tmp->next->next;
			free(curr);
			if (ListIsEmpty(tmp->next)) break;
		}
		if (ListIsEmpty(tmp->next)) break;
	}
	return i;
}

