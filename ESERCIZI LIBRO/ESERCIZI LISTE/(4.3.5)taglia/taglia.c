#include "list.h"
Item* Taglia(Item* i, int n) {
	int j = 0;
	if (n < 0) return ListCreateEmpty();
	if (n == 0) return i;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j + 1 == n) {
			ListDelete(ListGetTail(tmp)); //IMPORTANTE, devi cancellare la memoria della lista che viene dopo e poi bisogna far puntare a NULL
			tmp->next = NULL;
			break;
		}
		j++;
	}
	return i;
}