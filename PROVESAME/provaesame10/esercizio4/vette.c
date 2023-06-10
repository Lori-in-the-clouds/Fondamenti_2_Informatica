#include "list.h"
#include <stdbool.h>
int ContaVette(const Item* i) {
	if (ListIsEmpty(i)) return 0;
	int ris = 0;
	for (Item* tmp1 = i; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		bool control = true;
		for (Item* tmp2 = tmp1->next; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) < 0) {
				control = false;
			}
		}
		if (control) ris++;
	}
	return ris;
}
