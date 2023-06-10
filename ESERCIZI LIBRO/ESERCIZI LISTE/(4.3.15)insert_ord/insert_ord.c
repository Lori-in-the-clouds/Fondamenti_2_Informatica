#include "list.h"
#include <stdlib.h>
Item* InsertOrd(const ElemType* e, Item* i) {
	//prev = idirizzo dell'elemento che dovrà prececederlo 
	Item* new_item = ListInsertHead(e, ListCreateEmpty());
	Item* suv = ListCreateEmpty();
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp->next), e) > 0) {
			suv = ListGetTail(tmp);		//per trovare il pezzettino sopra, uso listgettail in modo tale da non dover fare copia incolla
			tmp->next = new_item;
			break;
		}

	}
	new_item->next = suv;
	return i;
}
Item* InsertOrdRec(const ElemType* e, Item* i) {
	if (ListIsEmpty(i) || ElemCompare(ListGetHeadValue(i), e) >= 0) {
		return ListInsertHead(e, i);
		
	}
	return ListInsertHead(ListGetHeadValue(i), InsertOrdRec(e, ListGetTail(i)));
}
//1 2 4 5