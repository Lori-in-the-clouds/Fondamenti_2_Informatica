#include "elemtype.h"
#include "list.h"
#include "reverse.h"
Item* reverse1(Item* i) {
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




Item* Reverse(Item* list, int left) {
	if (left <= 0) return reverse1(list);
	int cont = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) cont++;
	if (left >= cont - 1) return list;
	
	Item* prev = list;
	for (int j = 0; j < left; j++) {
		prev = prev->next;
	}
	Item* curr = prev->next;
	for (int j = 0; j < cont - left-1; j++) {
		Item* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	int s = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (s == left-1) {
			tmp->next = prev;
			break;
		}
		s++;
	}
	s = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (s == cont+1) {
			tmp->next = NULL;
		}
		s++;
	}
	return list;
}