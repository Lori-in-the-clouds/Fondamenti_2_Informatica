#include "list.h"
 int ListOccorrenze(const Item* i, const ElemType* e) {
	 int som = 0;
	 for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		 const ElemType* t = ListGetHeadValue(tmp);
		 if (ElemCompare(t,e) == 0) som++;
	 }
	 return som;
}
