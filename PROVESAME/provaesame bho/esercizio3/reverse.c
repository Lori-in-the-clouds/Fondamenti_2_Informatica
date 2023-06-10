#include "list.h"
Item* reverseRec(Item* i) {
	Item* curr = i;
	Item* prev = ListCreateEmpty();
	while (!ListIsEmpty(curr)) {
		Item* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
Item* Reverse(Item* list,int right) {
	if (right == 0) return list;
	int len = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		len++;
	}
	if (right >= len) return reverseRec(list);
	Item* curr = list;
	int i = 0;
	for (int i = 0; i < right; i++) {
		//Item* curr = list;
		list = ListGetTail(list);
		//free(list);
	}
	Item* prev = ListCreateEmpty();
	for(int i=0;i<right;i++) {
		Item* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	for (Item* tmp = prev; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ListIsEmpty(tmp->next)) {
			tmp->next = list;
			break;
		}
	}
	
	return prev;
	
}
