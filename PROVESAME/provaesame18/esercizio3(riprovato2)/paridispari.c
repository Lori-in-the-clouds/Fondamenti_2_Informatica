#include "list.h"
#include "elemtype.h"
#include <stdlib.h>
Item* PariDispari(Item* i) {
	Item* ultimo = i;
	for (Item* tmp = ultimo; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) ultimo = ultimo->next;
	int cont = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) cont++;
	
	//inseriamo i primi
	while (*ListGetHeadValue(i) % 2 != 0) {
		ultimo->next = i;
		i = ListGetTail(i);
	}
	Item* prev = i;
	int j = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
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
	
	j = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j == cont-1) {
			tmp->next = NULL;
		}
		j++;
	}
	return i;


}



int main(void) {
	int v[] = {1,1,2,4 };
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i = ListInsertBack(i, v + j);
	}
	Item *ris = PariDispari(i);
}