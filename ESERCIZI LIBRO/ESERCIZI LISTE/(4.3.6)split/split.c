#include "list.h"
Item* Split(Item* i) {
	//troviamo la dimensione
	Item* tmp1 = ListCreateEmpty();
	int n = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		n++;
	}
	int splitter = n / 2;
	if (n % 2 != 0) splitter++;
	n = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (n == splitter) {
			tmp1 = tmp;
			break;
		}
		n++;
	}
	n = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (n == splitter-1) {
			tmp->next = NULL;
			break;
		}
		n++;
	}
	return tmp1;
}
//1 2 3 4