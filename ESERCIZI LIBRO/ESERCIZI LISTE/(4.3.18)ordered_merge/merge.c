#include "list.h"
#include "merge.h"
#include <stdlib.h>

Item* OrderedMerge(Item* i1, Item* i2, enum MergeType m) {
	if (ListIsEmpty(i1) && !ListIsEmpty(i2)) return i2;
	if (!ListIsEmpty(i1) && ListIsEmpty(i2)) return i1;
	if (m == kcopy) {
		Item* ris = ListCreateEmpty();
		while (!ListIsEmpty(i1) && !ListIsEmpty(i2)) {
			if (ElemCompare(ListGetHeadValue(i1), ListGetHeadValue(i2)) <= 0) {
				ris = ListInsertBack(ris, ListGetHeadValue(i1));
				i1 = ListGetTail(i1);
			}
			else {
				ris = ListInsertBack(ris, ListGetHeadValue(i2));
				i2 = ListGetTail(i2);
			}
		}
		if (ListIsEmpty(i1) && !ListIsEmpty(i2)) {
			for (Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
				ris = ListInsertBack(ris, ListGetHeadValue(tmp));
			}
		}
		if (!ListIsEmpty(i1) && ListIsEmpty(i2)) {
			for (Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
				ris = ListInsertBack(ris, ListGetHeadValue(tmp));
			}
		}
		return ris;
	}
	else {
		//inserisci il primo elemento 
		while (ElemCompare(ListGetHeadValue(i2), ListGetHeadValue(i1)) < 0) {
			i1 = ListInsertHead(ListGetHeadValue(i2),i1);
			i2 = ListGetTail(i2);
		}
		while (!ListIsEmpty(i2)) {
			Item* new_item = ListInsertBack(ListCreateEmpty(), ListGetHeadValue(i2));
			Item* suv = ListCreateEmpty();
			bool control = false;
			bool control2 = false;
			for (Item* tmp = i1; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {
				
				if (ElemCompare(ListGetHeadValue(i2), ListGetHeadValue(tmp->next)) < 0) {
					suv = ListGetTail(tmp);
					tmp->next = new_item;
					i2 = ListGetTail(i2);
					control = true;
					control2 = true;
				}
				new_item->next = suv;
				if (control == true) break;
			}
			if (control2 == false) {
				i1 = ListInsertBack(i1, ListGetHeadValue(i2));
				i2 = ListGetTail(i2);
			}
		}
		return i1;
	}
}