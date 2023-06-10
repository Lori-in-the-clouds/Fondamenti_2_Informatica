#include "merge.h"
#include "elemtype.h"
#include "list.h"
#include <stdbool.h>
Item* Orderedmerge(Item* i1, Item* i2, enum MergeType m) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) return ListCreateEmpty();
	if (ListIsEmpty(i1)) return i2;
	if (ListIsEmpty(i2)) return i1;
	
	if (m == kNoCopy) {
		//inseriamo gli elementi della seconda lista nella prima
		for (Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			// elemento da inserire 
			Item* suv = ListCreateEmpty();
			Item* new_item = ListInsertHead(ListGetHeadValue(tmp), ListCreateEmpty());
			bool control = false;
			for (Item* tmp2 = i1; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
				if (tmp2->next == NULL) break;
				if (ElemCompare(ListGetHeadValue(tmp2->next), ListGetHeadValue(new_item)) >= 0) {
					suv = ListGetTail(tmp2);
					tmp2->next = new_item;
					new_item->next = suv;
					control = true;
					break;
				}

			}
			if (!control) {
				for (Item* tmp3 = i1; !ListIsEmpty(tmp3); tmp3 = ListGetTail(tmp3)) {
					if (ListIsEmpty(tmp3->next)) {
						tmp3->next = new_item;
						break;
					}
				}
			}
		}
		return i1;
	}
	else {
		Item* ris = ListCreateEmpty();
		while (!ListIsEmpty(i1) && !ListIsEmpty(i2)) {
			if (ElemCompare(ListGetHeadValue(i1), ListGetHeadValue(i2)) < 0) {
				ris = ListInsertBack(ris, ListGetHeadValue(i1));
				i1 = ListGetTail(i1);
			}
			else {
				ris = ListInsertBack(ris, ListGetHeadValue(i2));
				i2 = ListGetTail(i2);
			}
		}
		if (ListIsEmpty(i1)) {
			for (Item* tmp = ris; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
				if (ListIsEmpty(tmp->next)) {
					tmp->next = i2;
					break;
				}
			}
		}
		if (ListIsEmpty(i2)) {
			for (Item* tmp = ris; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
				if (ListIsEmpty(tmp->next)) {
					tmp->next = i1;
					break;
				}
			}
		}
		return ris;
	}
}
//int main(void) {
//	int v1[] = { 1,3,4,6 };
//	int v2[] = { 2,5,7 };
//	Item* i1 = ListCreateEmpty();
//	Item* i2 = ListCreateEmpty();
//	for (int j = 0; j < sizeof(v1) / sizeof(int); j++) {
//		i1 = ListInsertBack(i1, v1 + j);
//	}
//	for (int j = 0; j < sizeof(v2) / sizeof(int); j++) {
//		i2 = ListInsertBack(i2, v2 + j);
//	}
//	Orderedmerge(i1, i2, kCopy);
//}