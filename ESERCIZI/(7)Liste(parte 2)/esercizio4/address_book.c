#include "list.h"
#include <string.h>
Item* Filtra(const Item* i, const char* city) {
	Item* ris = ListCreateEmpty();
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		const ElemType* e = ListGetHeadValue(tmp);
		if (strcmp(e->city,city)==0) {
			ris = ListInsertBack(ris,e);
		}
	}
	return ris;
}