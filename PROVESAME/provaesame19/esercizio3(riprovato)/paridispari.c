#include "elemtype.h"
#include "list.h"
Item* PariDispari(Item* i) {
	if (ListIsEmpty(i)) return ListCreateEmpty();
	Item* ultimo = i;
	int cont = 0;
	int j = 0;
	for (; !ListIsEmpty(ultimo->next); ultimo = ListGetTail(ultimo)) cont++;
	//fin quando i primi nuemri sono dispari 
	while (*ListGetHeadValue(i) % 2 != 0) {
		ultimo->next = i;
		i = ListGetTail(i);
		ultimo = ultimo->next;
		ultimo->next = NULL;
	}
	Item* prev = i;
	for (Item* tmp = i; !ListIsEmpty(tmp) && j < cont;tmp = ListGetTail(tmp)) {
		if (*ListGetHeadValue(tmp) % 2 != 0) {
			ultimo->next = tmp;
			ultimo = ultimo->next;
			prev->next = tmp->next;
			tmp->next = NULL;
			tmp = prev;
		}
		prev = tmp;
		j++;
	}
	return i;
}




