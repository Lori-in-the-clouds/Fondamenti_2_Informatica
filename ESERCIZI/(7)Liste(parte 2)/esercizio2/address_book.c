#include "list.h"
#include "string.h"
#include <stdlib.h>
Item* Delete(Item* i, const char* name) {
	if (ListIsEmpty(i)) {
		return i;
	}
	if (strcmp(ListGetHeadValue(i)->name,name)==0) {
		Item* curr = i;
		i = i->next;
		free(curr);
		return i;
	}
	for (Item *tmp = i; !ListIsEmpty(tmp->next);tmp = ListGetTail(tmp)) { 
			const ElemType *e = ListGetHeadValue(tmp->next);
		if (strcmp(e->name, name) == 0) {
			ElemDelete(&tmp->next->value);
			Item* curr = tmp->next;
			tmp->next = tmp->next->next;
			free(curr);
		}
	}
	return i;

}