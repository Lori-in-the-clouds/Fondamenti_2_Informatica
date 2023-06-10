#include "list.h"
#include <stdlib.h>
Item* AppendMod(Item* i1,Item* i2) {
	if (ListIsEmpty(i1)) {
		return i2;
	}
	for (Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (tmp->next == NULL) {
			tmp->next = i2;
			break;
		}
	}
	return i1;
}