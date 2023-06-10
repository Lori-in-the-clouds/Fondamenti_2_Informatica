#include "elemtype.h"
#include "list.h"
Item* ElementiPari(const Item* i) {
	Item* ris = ListCreateEmpty();
	if (ListIsEmpty(i)) return ris;
	int j = 0;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j % 2 == 0) {
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		}
		j++;
	}
	return ris;
}