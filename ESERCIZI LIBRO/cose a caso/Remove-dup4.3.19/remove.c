#include "list.h"
#include <stdbool.h>
Item* RemoveDuplicates(Item* i, bool ordered) {
	if (ordered) {
		int ord = 0;
		for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			const ElemType* e = ListGetHeadValue(tmp);
			for (Item* tmp2 = i; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
				ElemType* c = ListGetHeadValue(tmp2);
				if (*c == *e) {
					if (ord != 0) {
						tmp2->next = tmp2->next->next;
					}
					ord++;
				}
			}
		}
		return i;
	}
	else {

	}
}