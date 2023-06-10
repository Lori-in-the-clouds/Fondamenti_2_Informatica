#include "elemtype.h"
#include "list.h"
#include <stdlib.h>

Item* ShiftN(Item* list, size_t n) {
	if (n == 0) return list;
	if (ListIsEmpty(list)) return ListCreateEmpty();
	int cont = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) cont++;
	if (cont == 1) return list;
	n = n % (cont - 1);
	if (n == 0) {
		Item* head = list->next;
		Item* new_Item = list;
		Item* prev = list;
		for (Item* tmp = list; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {
			prev = prev->next;
		}
		new_Item->next = NULL;
		prev->next = new_Item;
		return head;
	}
	//elemento da spostare
	Item* new_item = list;
	//prendo la testa della list che poi devo ritornare 
	Item* head = list->next;
	Item* prev = list;
	Item* ultimo = list;
	for (size_t j = 0; j < n;j++) {
		prev = prev->next;
		ultimo = ultimo->next;
	}
	ultimo = ultimo->next;
	new_item->next = ultimo; //devi modificare sempre  da destra a sinistra in questo modo quelli a sinistra sono salvi dalle modifiche 
	prev->next = new_item;
	return head;
}
