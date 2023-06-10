#include "remove.h"
#include <stdlib.h>
Item* RemoveDuplicates(Item* i) {
	if (ListIsEmpty(i)) return ListCreateEmpty();
	for (Item* tmp = i; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {
		while (!ListIsEmpty(tmp->next) && ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(tmp->next)) == 0) {
			Item* curr = tmp->next;
			ElemDelete(&tmp->next->value);
			tmp->next = tmp->next->next;
			free(curr);
		}
		if (ListIsEmpty(tmp->next)) break;
	}
	return i;
	
}


//int main(void) {
//	int v[] ={9,9,9 };
//	Item* i = ListCreateEmpty();
//	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
//		i = ListInsertBack(i, v + j);
//	}
//	Item* ris = RemoveDuplicates(i);
//}