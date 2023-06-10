#include "list.h"
#include "elemtype.h"
#include "reverse.h"
#include <stdlib.h> 
Item* rev(Item* i) {
	Item* curr = i;
	Item *prev = ListCreateEmpty();
	while (!ListIsEmpty(curr)) {
		Item* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
Item* Reverse(Item* list, int right) {
	if (right <= 1 || ListIsEmpty(list)) return;
	//calcolo lunghezza lista
	int lenght = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		lenght++;
	}
	if (right >= lenght) return rev(list);
	Item* curr = list;
	for (int j = 0; j < right; j++) {
		list = ListGetTail(list);
		
	}
	Item* prev = ListCreateEmpty();
	for (int i = 0; i < right; i++) {
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