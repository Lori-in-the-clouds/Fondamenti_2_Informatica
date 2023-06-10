#include "elemtype.h"
#include <stdlib.h>
#include "list.h"
Item* PariDispari(Item* i) {
	if (ListIsEmpty(i)) return ListCreateEmpty();
	int cont = 1;
	Item* ultimo = i;
	Item* prev = i;
	int j = 0;
	//METTIAMO IN ULTIMO L'ULTIMO I
	for (; !ListIsEmpty(ultimo->next); ultimo = ListGetTail(ultimo)) cont++;
	//METTIAMO I VALORI DISPARI IN CODA,(CON UN CICLO MASSIMO DI J)
	for (Item* tmp = i->next; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j == cont) break;
		if (*ListGetHeadValue(tmp) % 2 != 0) {
			ultimo->next = tmp;
			ultimo = ListGetTail(ultimo);
			prev->next = tmp->next;
			tmp = prev;
		}
		prev = tmp;
		j++;
	}

	if (*ListGetHeadValue(i) % 2 != 0) {
		ultimo->next = i;
		i = ListGetTail(i);
	}
	//TAGLIAMO
	j = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j == cont-1) tmp->next = NULL;
		j++;
	}
	return i;
}