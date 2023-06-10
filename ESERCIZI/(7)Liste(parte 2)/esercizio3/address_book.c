#include "list.h"
#include <stdbool.h>

Item* Sort(Item* i) {
		for (Item* tmp1 = i; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			for (Item* tmp = tmp1; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {
				if (ElemCompare(&tmp->value, &tmp->next->value) > 0) {
					const ElemType* e = ListGetHeadValue(tmp);
					ElemType c = *e;
					tmp->value = tmp->next->value;
					tmp->next->value = c;
				}
			}
		}
		return i;
}
