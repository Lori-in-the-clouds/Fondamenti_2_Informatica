#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
void InsertionSort(Item** i) {
	int cont = 0;
	bool control = false;
	Item* prev = ListCreateEmpty();
	for (Item* tmp = (*i); !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (control) {
			tmp = prev;
			control = false;
		}
		prev = tmp;
		if (ListIsEmpty(tmp->next)) break;
		if (ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(tmp->next)) > 0) {
			//dobbiamo cancellare l'elemento
			int val = *ListGetHeadValue(tmp->next);
			ElemDelete(&tmp->next);
			Item* curr = tmp->next;
			tmp->next = tmp->next->next;
			free(curr);
			Item* new_item = ListInsertBack(ListCreateEmpty(), &val);
			Item* suv = ListCreateEmpty();
			//se è il primo
			if (ElemCompare(ListGetHeadValue(*i), &val) > 0) {
				*i = ListInsertHead(&val, *i);
				control = true;
				if (ListIsEmpty(tmp)) break;
				continue;
			}
			for (Item* tmp1 = *i; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
				if (ElemCompare(tmp1->next, &val) > 0) {
					//inseriamo il nuovo elemento
					suv = ListGetTail(tmp1);
					tmp1->next = new_item;
					control = true;
					break;
				}
			}
			new_item->next = suv;
			if (ListIsEmpty(tmp)) break;
		}
	}
	return;
}
int main(void) {
	int v[] = { 9,8,7,6,5,4,3,2,1 };
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i = ListInsertBack(i, v + j);
	}
	InsertionSort(&i);
}