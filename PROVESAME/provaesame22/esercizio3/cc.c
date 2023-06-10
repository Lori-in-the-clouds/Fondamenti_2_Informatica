#include "cc.h"
#include <stdlib.h>
#include <stdbool.h>
int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (ListIsEmpty(i) || v == NULL) return 0;
	int ris = 0;
	bool control = false;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		for (int j = 0; j < (int)v_size; j++) {
			while (ElemCompare(ListGetHeadValue(tmp), &v[j]) == 0) {
				if (ListIsEmpty(tmp->next)) {
					ris++;
					return ris;
				}
				tmp = ListGetTail(tmp);
				control = true;
				for (int j = 0; j < (int)v_size; j++) {
					if (ElemCompare(ListGetHeadValue(tmp), &v[j]) == 0) {
						if (ListIsEmpty(tmp->next)) {
							ris++;
							return ris;
						}
						tmp = ListGetTail(tmp);
					}
				}
			}
			if (control) {
				control = false;
				ris++;
			}
		}
	}
	return ris;
}