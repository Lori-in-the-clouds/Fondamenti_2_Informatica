#include "list.h"
Item* CreaDaMinori(const Item* i, int v) {
	if (ListIsEmpty(i)) return ListCreateEmpty();
	Item* ris = ListCreateEmpty();
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), &v) <= 0) {
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		}
	}
	return ris;
 }