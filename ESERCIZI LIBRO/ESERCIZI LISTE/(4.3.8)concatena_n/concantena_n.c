#include "list.h"
Item* ConcatenaN(Item** v, size_t v_size) {
	Item* head = ListCreateEmpty();
	Item* last = ListCreateEmpty();
	for (int i = 0; i < v_size; i++) {
		if (!ListIsEmpty(v[i])) {
			if (ListIsEmpty(head)) {
				head = v[i];
			}
			else {
				last->next = v[i];
			}

			while (!ListIsEmpty(ListGetTail(v[i]))) {
				v[i] = ListGetTail(v[i]);
			}
			last = v[i]; //collegamento con head, mantine il punto su quello procedente partendo dall'head
		}
	}
	return head;
}