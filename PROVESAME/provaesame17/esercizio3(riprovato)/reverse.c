#include "elemtype.h"
#include "list.h"
Item* Reverse(Item* i) {
	Item* prev = ListCreateEmpty();
	Item* curr = i;
	while (!ListIsEmpty(curr)) {
		Item* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}