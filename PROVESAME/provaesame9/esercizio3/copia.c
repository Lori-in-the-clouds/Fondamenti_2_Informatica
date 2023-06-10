#include "list.h"
Item* CopiaDaN(const Item* i, int n) {
	if (ListIsEmpty(i)) return ListCreateEmpty();
	int m = 0;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		m++;
	}
	if (m < n) return ListCreateEmpty();
	Item* ris = ListCreateEmpty();
	m = 1;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (m == n) {
			for (const Item* tmp1 = tmp; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
				ris = ListInsertBack(ris, ListGetHeadValue(tmp1));
			}
			break;
		}
		m++;
	}
	return ris;

}