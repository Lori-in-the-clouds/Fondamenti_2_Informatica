#include "list.h"
const Item* CommonTail(const Item* i1, const Item* i2) {
	for (Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (tmp1 == tmp2) {
				return tmp1;
			}
		}
	}
	return ListCreateEmpty();
}