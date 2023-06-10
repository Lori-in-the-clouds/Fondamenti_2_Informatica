#include "list.h"
#include "remove.h"
#include <stdlib.h>
Item* RemoveDuplicates(Item* i) {
	if (ListIsEmpty(i)) return ListCreateEmpty();
	
	while (ElemCompare(ListGetHeadValue(i), ListGetHeadValue(i->next)) == 0) {
		i = ListGetTail(i);
	}
	bool control = false;
	for (Item* tmp = i; !ListIsEmpty(tmp->next->next); tmp = ListGetTail(tmp)) {
		while ((ElemCompare(ListGetHeadValue(tmp->next), ListGetHeadValue(tmp->next->next)) == 0)) {
			Item* curr = tmp->next;
			tmp->next = tmp->next->next;
			free(curr);
			if (ListIsEmpty(tmp->next->next)) {
				control = true;
				break;
			}
		}
		if (control) break;
	}
	return i;
}