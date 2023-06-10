#include "list.h"
Item* Reverse(Item* i) {
	Item* curr = i;
	Item* prev = NULL;
	Item* next = NULL;
	while (!ListIsEmpty(curr)) {
		next = curr->next;
		curr->next = prev; // la più importante 
		prev = curr;
		curr = next;
	}
	return prev;
}