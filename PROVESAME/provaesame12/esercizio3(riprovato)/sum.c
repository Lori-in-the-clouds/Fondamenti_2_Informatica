#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
Item* Sum(const Item* i1, const Item* i2) {
	Item* ris = ListCreateEmpty();
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) return ris;
	//se la prima lista è vuota 
	if (ListIsEmpty(i1)) {
		for (const Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		}
		return ris;
	}
	//se la seconda lista è vuota 
	if (ListIsEmpty(i2)) {
		for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		}
		return ris;
	}
	const Item* tmp2 = i2;
	const Item* tmp = i1;
	int p = 0;
	for (tmp; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ListIsEmpty(tmp2)) break;
		int som = *ListGetHeadValue(tmp) + *ListGetHeadValue(tmp2);
		if (p == 1) {
			som++;
			p = 0;
		}
		if (som >= 10) {
			som = som % 10;
			p = 1;
			ris = ListInsertBack(ris, &som);
		}
		else ris = ListInsertBack(ris, &som);
		tmp2 = ListGetTail(tmp2);
	}

	for (tmp; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (p == 1) {
			ElemType e = *ListGetHeadValue(tmp) + 1;
			ris = ListInsertBack(ris, &e);
			p--;
		}
		else ris = ListInsertBack(ris,ListGetHeadValue(tmp));
	}
	for (tmp2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
		if (p == 1) {
			ElemType e = *ListGetHeadValue(tmp2) + 1;
			ris = ListInsertBack(ris, &e);
			p--;
		}
		else ris = ListInsertBack(ris, ListGetHeadValue(tmp2));
	}
	if (p == 1) ListInsertBack(ris, &p);
	//controllo se abbiamo degli zeri alla fine
	Item* prev = ris;
	for (Item* tmp3 = ris; !ListIsEmpty(tmp3); tmp3= ListGetTail(tmp3)) {
		while (ListIsEmpty(tmp3->next) && *ListGetHeadValue(tmp3) == 0) {
			ElemDelete(&tmp3->value);
			Item* curr = tmp3;
			prev->next = NULL;
			tmp3 = prev;
			free(curr);
		}
		if (ListIsEmpty(tmp3) == true) break;
		prev = tmp3;
	}
	return ris;
}
Item* Taglia_al_presente(Item* i1, ElemType* e) {
	//NON PUò CANCELLARE IL PRIMO ELELMENTO DELLA LISTA
	Item* prev = i1;
	for (Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), e) == 0) {
			ElemDelete(&tmp->value);
			Item* curr = tmp;
			prev->next = tmp->next;
			free(curr);
			tmp = prev; // PARTE IMPORTANTE
		}
		prev = tmp;
	}
	return i1;
}