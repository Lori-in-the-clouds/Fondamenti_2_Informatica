#include "elemtype.h"
#include "list.h"
#include "cc.h"
#include <stdlib.h>
int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (v_size == 0 || v == NULL || ListIsEmpty(i)) return 0;
	int ris = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		for (int j = 0; j < v_size; j++) {
			if (ElemCompare(ListGetHeadValue(tmp), &v[j]) == 0) {
				ris++;
				for (int j = 0; j < v_size; j++) {
					//if (j == no) continue;
					if (ListIsEmpty(tmp->next)) break;
					if (ElemCompare(ListGetHeadValue(tmp->next), &v[j]) == 0) {
						tmp = ListGetTail(tmp);
						if (ListIsEmpty(tmp->next)) break;
						j = -1;
					}
				}
				break;
			}
		}

	}
	return ris;
}