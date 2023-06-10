#include "elemtype.h"
#include "list.h"
#include <math.h>
Item* CreaDaInterni(const Item* i, double r) {
	Item* ris = ListCreateEmpty();
	if (ListIsEmpty(i)) return ris;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		const ElemType m = *ListGetHeadValue(tmp);
		if (sqrt(pow(m.x,2)+pow(m.y,2)) < r) {
			ris = ListInsertBack(ris, &m);
		}
	}
	return ris;
}