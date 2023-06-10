#include "list.h"
#include <stdlib.h>
Item* PariDispari(Item* i) {
	if (ListIsEmpty(i)) return ListCreateEmpty();
	//se sono tutti pari o tutti dispari 
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if ((*ListGetHeadValue(tmp)) % 2 != 0) break;
		if (tmp->next == NULL) return i;
	}
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if ((*ListGetHeadValue(tmp)) % 2 == 0) break;
		if (tmp->next == NULL) return i;
	}
	while (1) {
		bool control = true;
		for (Item* tmp1 = i; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			if ((*ListGetHeadValue(tmp1)) % 2 != 0) {
				for (Item* tmp2 = tmp1; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
					if ((*ListGetHeadValue(tmp2)) % 2 == 0) {
						control = false;
						break;
					}
					if (ListIsEmpty(tmp2->next)) return i; //se la lista è apposto ritorna i
				}
				if (!control) break;
			}
		}
		for (Item* tmp1 = i; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			if ((*ListGetHeadValue(tmp1)) % 2 != 0) {
				for (Item* tmp2 = tmp1; !ListIsEmpty(tmp2->next); tmp2 = ListGetTail(tmp2)) {
					if ((*ListGetHeadValue(tmp2->next)) % 2 == 0) {
						Item* curr = tmp2->next;
						i = ListInsertHead(ListGetHeadValue(tmp2->next), i);
						tmp2->next = tmp2->next->next;
						free(curr);
						if (tmp2->next == NULL) break;

					}
				}
			}
		}

	}
}

