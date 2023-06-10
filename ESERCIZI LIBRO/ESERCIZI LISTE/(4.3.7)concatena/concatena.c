#include "concatena.h"
#include "list.h"
Item* Concatena(Item* i1, Item* i2, enum ConcType c) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) return ListCreateEmpty();
	if (ListIsEmpty(i1) && !ListIsEmpty(i2)) return i1;
	if (!ListIsEmpty(i1) && ListIsEmpty(i2)) return i2;
	if (c == kNoCopy) {
		for (Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			if (ListIsEmpty(tmp->next)) {
				tmp->next = i2;
				break;
			}
		}
		return i1;
	}
	else {
		Item* ris = i1;
		for (Item* tmp = ris; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			if (ListIsEmpty(tmp->next)) {
				tmp->next = i2;
				break;
			}
		}
		return ris;
	}
}