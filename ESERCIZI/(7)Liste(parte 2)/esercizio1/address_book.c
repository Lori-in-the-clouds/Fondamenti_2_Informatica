#include "list.h"
#include <stdbool.h>
#include <string.h>
const ElemType* Find(const Item* i, const char* name) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		const ElemType* e = ListGetHeadValue(tmp);
		if (strcmp(e->name,name) == 0) {
			return e;
		}
	}
	return NULL;
	
}
