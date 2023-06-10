#include "list.h"
Item* Sum(const Item* i1, Item* i2) {
	Item* ris = ListCreateEmpty();
	Item* tmp2 = i2;
	int sumd = 0;
	for (Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		 ElemType e = 0;
		if (!ListIsEmpty(tmp2)) {
			e = *ListGetHeadValue(tmp2);
			tmp2 = ListGetTail(tmp2);
		}
		const ElemType d = *ListGetHeadValue(tmp1);
		int sum = d + e + sumd;
		if (sumd != 0) sumd = 0;
		if ((e + d) / 10 != 0) {
			sumd = (d + e) / 10;
			 sum = sum % 10;
		}
		ris = ListInsertBack(ris, &sum);
	}
	while (!ListIsEmpty(tmp2)) {
		ris = ListInsertBack(ris, ListGetHeadValue(tmp2));
		tmp2 = ListGetTail(tmp2);
	}
	ListDelete(tmp2);
	return ris;
}