#include "remove.h"
#include <stdlib.h>
Item* RemoveDuplicates(Item* i, bool ordered) {
	if (ordered) {
		for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			while (!ListIsEmpty(tmp->next) && ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(tmp->next)) == 0) {
				ElemDelete(&tmp->next->value);
				Item* curr = tmp->next;
				tmp->next = ListGetTail(tmp->next); //cancellazione ma senza salto
				free(curr);
			}
		}
		return i;
	}
	else {
		Item* prev = ListCreateEmpty();
		for (Item* tmp1 = i; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			for (Item* tmp2 = tmp1->next; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
				if (tmp2 == tmp1->next) prev = tmp1;
				if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
					while (!ListIsEmpty(tmp2) && ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
						ElemDelete(&tmp2->value);
						Item* curr = tmp2;
						tmp2 = ListGetTail(tmp2);
						free(curr);
					}
					prev->next = tmp2;
					tmp2 = prev;
					break;
				}
				prev = tmp2;
			}
		}
		return i;
	}
}
//4, 3, 4, 4, 5S