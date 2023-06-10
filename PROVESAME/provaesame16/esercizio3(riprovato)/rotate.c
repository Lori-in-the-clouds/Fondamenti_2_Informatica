#include "list.h"
Item* Rotate(Item* i, int n) {
	Item* ultimo = i;
	for (ultimo; !ListIsEmpty(ultimo->next); ultimo = ListGetTail(ultimo));
	Item* primo = i;
	for (int j = 0; j < n; ++j) {
		ultimo->next = primo;
		ultimo = ListGetTail(ultimo);

		primo = ListGetTail(primo);
		ultimo->next = NULL;
	}
	return primo;
}