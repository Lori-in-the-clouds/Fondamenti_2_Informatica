#include "list.h"
#include "elemtype.h"
const Item* CommonTail(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) || ListIsEmpty(i2)) return ListCreateEmpty();
	for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		for (const Item* tmp1 = i2; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			if (tmp1 == tmp) {
				return tmp;
			}
		}
	}
	return ListCreateEmpty();
}