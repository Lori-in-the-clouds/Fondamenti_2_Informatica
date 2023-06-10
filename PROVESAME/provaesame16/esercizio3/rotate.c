#include "list.h"
Item* Rotate(Item* i, int n) {
	Item* new_item = ListCreateEmpty();
	int j = 0;
	for (Item* tmp = i;!ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j == n) {
			i = tmp; // attenzioen
			break;
		}
		new_item = ListInsertBack(new_item, ListGetHeadValue(tmp));
		j++;
	}
	for (Item* tmp = new_item; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		i = ListInsertBack(i, ListGetHeadValue(tmp));
	}
	Item* ris = i;
	ListDelete(new_item);
	return ris;
}
//1, 3, 4, 7, 8