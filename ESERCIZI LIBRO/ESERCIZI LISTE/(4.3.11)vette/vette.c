#include "list.h"
int ContaVette(const Item* i) {
	if (ListIsEmpty(i)) return 0;
	int sol = 1;
	for (Item* tmp = i; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {
		int cont = 0;
		int j = 0;
		for (Item* tmp1 = tmp->next; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			if (ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(tmp1)) == 1) {
				cont++;
			}
			j++;
		}
		if (cont == j) sol++;
	}
	return sol;
}
