#include "list.h"
Item* IntersectNoRep(const Item* i1, const Item* i2) {
	Item* ris = ListCreateEmpty();
	int control = 0;
	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		const ElemType* e1 = ListGetHeadValue(tmp1);
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			const ElemType* e2 = ListGetHeadValue(tmp2);
			if (*e1 == *e2) {
				for (const Item* tmp3 = ris; !ListIsEmpty(tmp3); tmp3 = ListGetTail(tmp3)) {
					const ElemType* e3 = ListGetHeadValue(tmp3);
					if (*e3 == *e1) {
						control++;
					}

				}
				if (control == 0) {
					ris = ListInsertBack(ris, e1);
					break;
				}
			}
		}
		control = 0;
	}
	return ris;
}
Item* DiffNoRep(const Item* i1, const Item* i2) {
	Item* ris = ListCreateEmpty();
	int control = 1;
	int control2 = 0;
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
			for (const Item* tmp3 = ris; !ListIsEmpty(tmp3); tmp3 = ListGetTail(tmp3)) {
				const ElemType *e3 = ListGetHeadValue(tmp3);
				if (*e3 == *e1) {
					control2++;
				}
			}
			if (control2 == 0) {
				ris = ListInsertBack(ris, e1);
			}

		}
		control = 1;
		control2 = 0;
	}
	return ris;

}