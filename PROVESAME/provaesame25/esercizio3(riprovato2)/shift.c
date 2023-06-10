#include "list.h"
#include "elemtype.h"
Item *ShiftN(Item* list, size_t n) {
	if (ListIsEmpty(list)) return NULL;
	Item* head = list->next;
	Item* ultimo = list;
	Item* prev = list;
	int cont = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) cont++;
	for (int j = 0; j < cont -1; j++) ultimo = ultimo->next;
	for (int i = 0; i < n; i++) prev = prev->next;
	Item* tmp = list;
	tmp->next = ultimo;
	prev->next = tmp;
	return head;
}
//prendi un elemento n_esimo e lo sposti dove dice lui m_esimo
Item* ShiftN_to_M(Item* list, size_t n, size_t m) {
	Item* head = list;
	Item* ultimo = list;
	Item* prev = list;
	Item* new_item = list;
	for (int j = 0; j < m-1; j++) {
		ultimo = ultimo->next;
		prev = prev->next;
	}
	ultimo = ultimo->next;
	int i = 0;
	Item* pov = list;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (i == n) {
			new_item = tmp;
			pov->next = tmp->next;
			tmp = pov;
		}
		i++;
		pov = tmp;
	}
	new_item->next = ultimo;
	prev->next = new_item;

	return head;
}

int main(void) {
	int v[] = { 0,1,2,3,4,5,6 };
	Item *i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i = ListInsertBack(i, v + j);
	}
	/*ShiftN(i, 2);*/
	ShiftN_to_M(i, 3, 5);
}