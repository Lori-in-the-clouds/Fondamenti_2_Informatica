#include "list.h"
#include <stdlib.h>
void Back2Front(Item** i) {
	if (ListIsEmpty(i[0]) || ListIsEmpty(i[0])) return;
	ElemType e = 0;
	for (Item* tmp = i[0]; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ListIsEmpty(tmp->next->next)) {
			e = *ListGetHeadValue(tmp->next);
			ListDelete(tmp->next);
			tmp->next = NULL;
			break;
		}
	}
	i[0] = ListInsertHead(&e, i[0]);
}