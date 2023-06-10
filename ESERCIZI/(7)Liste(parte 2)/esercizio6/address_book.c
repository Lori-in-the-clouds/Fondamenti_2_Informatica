#include "list.h"
#include <stdlib.h>
Item* Append(const Item* i1, const Item* i2) {
	Item* ris = ListCreateEmpty();
	if (ListIsEmpty(i1)) {
		for (const Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));

		}
		return ris;
	}

	for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (tmp->next == NULL) {
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
			for (const Item* tmp1 = i2; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
				ris = ListInsertBack(ris, ListGetHeadValue(tmp1));
			}
			break;
		}
		ris = ListInsertBack(ris,ListGetHeadValue(tmp));
	}
	return ris;
}