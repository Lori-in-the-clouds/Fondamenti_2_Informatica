#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
//Item* InsertOrd(Item* i, ElemType* e) {
//	if (ListIsEmpty(i)) return ListInsertHead(e, i);
//	Item* prev = ListInsertHead(e, ListCreateEmpty());
//	Item* suv = ListCreateEmpty();
//	ElemType c = 0;
//	if (ElemCompare(ListGetHeadValue(i), e) >= 0)  return ListInsertHead(e, i);
//	for (Item* tmp = i; !ListIsEmpty(tmp) && ElemCompare(ListGetHeadValue(tmp), e) < 0;tmp = ListGetTail(tmp)) {
//		suv = tmp->next;
//		c = *ListGetHeadValue(tmp);
//	}
//	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
//		if (*ListGetHeadValue(tmp) == c) {
//			tmp->next = prev;
//			break;
//		}
//	}
//	prev->next = suv;
//	return i;
//}
//un altra versione migliore di InsertOrd
Item* InsertOrd(Item* i, ElemType* e) {
	if (ListIsEmpty(i)) return ListInsertHead(e, i);
	Item* suv = ListInsertHead(e, ListCreateEmpty());
	Item* prev = ListCreateEmpty();
	Item* head = i;
	while (!ListIsEmpty(i) && ElemCompare(ListGetHeadValue(i), e) < 0) {
		prev = i;
		i = ListGetTail(i);
	}
	prev->next = suv;
	suv->next = i;
	return head;
}

void InsertionSort(Item** i) {
	if (ListIsEmpty(*i)) return;
	Item* ris = ListCreateEmpty();
	for (Item* tmp = *i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		ris = InsertOrd(ris,ListGetHeadValue(tmp));
	}
	*i = ris;
	return;
}

