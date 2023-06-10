#include "elemtype.h"
#include "list.h"
#include "differenza.h"
Item* Differenza(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) return ListCreateEmpty();
	Item* ris = ListCreateEmpty();
	if (ListIsEmpty(i2)) {
		for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			ris = ListInsertBack(ris,ListGetHeadValue(tmp));
		}
		for (Item* tmp = ris; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			char c = *ListGetHeadValue(tmp) + '0';
			tmp->value = c;
		}
		return ris;
	}
	ElemType p = 0;
	Item* tmp2 = i2;
	Item* tmp1 = i1;
	for (tmp1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		if (ListIsEmpty(tmp2)) break;
		if (p == 1) {
			ElemType e = *ListGetHeadValue(tmp1);
			e--;
			tmp1->value = e;
			p = 0;
		}
		if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2))>0) {
			ElemType m = *ListGetHeadValue(tmp1) - *ListGetHeadValue(tmp2);
			ris = ListInsertBack(ris,&m);
		}
		if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
			ris = ListInsertBack(ris, &p); //controlla poi,devo fare in modo che qui il rest osa sempre zero
		}
		if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) < 0) {
			ElemType e = *ListGetHeadValue(tmp1);
			e += 10;
			e -= *ListGetHeadValue(tmp2);
			ris = ListInsertBack(ris, &e);
			p = 1;
		}
		tmp2 = ListGetTail(tmp2);
	}
	if (p == 1) {
		ElemType e = *ListGetHeadValue(tmp1);
		e--;
		tmp1->value = e;
	}
	for (Item* tmp = ris; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		char c = *ListGetHeadValue(tmp) + '0';
		tmp->value = c;
	}
	return ris;
}