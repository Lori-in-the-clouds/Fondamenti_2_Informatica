#include "list.h"
Item* Reverse(Item* i) {
	Item* curr = i;
	Item* prev = ListCreateEmpty();
	Item* next = ListCreateEmpty();
	while (!ListIsEmpty(curr)) {
		curr->next = prev;
		next = curr->next;
		prev = curr;
		curr = ListGetTail(curr);
	}
	return prev;
}