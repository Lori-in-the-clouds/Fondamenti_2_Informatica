#include "list.h"
Item* Reverse(const Item* i) {
	Item* ris = ListCreateEmpty();
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		 const ElemType* e = ListGetHeadValue(tmp);
		ris = ListInsertHead(e, ris);
	}
	return ris;
}