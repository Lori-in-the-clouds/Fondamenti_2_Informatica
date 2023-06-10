#include "list.h"
Item* Diff(const Item* i1, const Item* i2) {
	Item* ris = ListCreateEmpty();
	int control = 1;
	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		 const ElemType* e1 = ListGetHeadValue(tmp1);
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			const ElemType* e2 = ListGetHeadValue(tmp2);
			if (*e1 == *e2) {
				control = 0;
				break;
			}
		}
		if (control == 1) {
			ris = ListInsertBack(ris, e1);
			
		}
		control = 1;
	}
	return ris;
}