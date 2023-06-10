#include "list.h"
Item* Sum(const Item* i1, const Item* i2) {
	Item* ris = ListCreateEmpty();
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) return ris;
	if (!ListIsEmpty(i1) && ListIsEmpty(i2)) {
		for (Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		return ris;
	}
	if (ListIsEmpty(i1) && !ListIsEmpty(i2)) {
		for (Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		return ris;
	}
	Item* tmp2 = i2;
	int rest = 0;
	Item* tmp = i1;
	for (tmp; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ListIsEmpty(tmp2)) break; // contrno
		int som = *ListGetHeadValue(tmp) + *ListGetHeadValue(tmp2);
		if (rest != 0) {
			som += rest;
			rest = 0;
		}
		if (som >= 10) {
			rest = som / 10;
			som = som % 10;
		}
		ris = ListInsertBack(ris, &som);
		tmp2 = ListGetTail(tmp2);
	}
	while (!ListIsEmpty(tmp)) {
		if (rest != 0) {
			int sum = *ListGetHeadValue(tmp) + rest;
			ris = ListInsertBack(ris, &sum);
			rest = 0;
		} else ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		tmp = ListGetTail(tmp);
	}
	while (!ListIsEmpty(tmp2)) {
		if (rest != 0) {
			int sum = *ListGetHeadValue(tmp2) + rest;
			ris = ListInsertBack(ris, &sum);
			rest = 0;
		} else ris = ListInsertBack(ris, ListGetHeadValue(tmp2));
		tmp2 = ListGetTail(tmp2);
	}
	if (rest != 0) {
		ris = ListInsertBack(ris, &rest);
	}
	return ris;
}
