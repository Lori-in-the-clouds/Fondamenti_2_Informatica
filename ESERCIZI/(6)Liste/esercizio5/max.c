#include "list.h"
#include <limits.h>
const ElemType* MaxElement(const Item* i) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	const ElemType* max = &i->value; //lindirizzo cambia ma non ciò a cui punta 
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		const ElemType* e = ListGetHeadValue(tmp);
		if (*e > *max) {
			max = e;
		}
	}
	return max;
}