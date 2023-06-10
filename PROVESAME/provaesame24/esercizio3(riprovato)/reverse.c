#include "elemtype.h"
#include "list.h"
Item* Reverse(Item* list, int right) {
	if (ListIsEmpty(list)) return ListCreateEmpty();
	int cont = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) cont++;
	if (cont == 1 || right == 0) return list;
	if (right >= cont) right = cont;
	Item* prev = ListCreateEmpty();
	Item* curr = list;
	for (int j = 0; j < right; j++) {
		Item* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	for (Item* tmp = prev; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ListIsEmpty(tmp->next)) {
			tmp->next = curr;
			break;
		}
	}
	return prev;
}
//int main(void) {
//	int v[] = { 0,1,2,3,4,5,6,7,8 };
//	Item* i = ListCreateEmpty();
//	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
//		i = ListInsertBack(i, v + j);
//	}
//	Item *ris = Reverse(i,12);
//}