#include "elemtype.h"
#include "list.h"
const Item* CommonTail(const Item* i1, const Item* i2) {
	//calcoliamo le lungzza dei due 
	int cont1 = 0;
	int cont2 = 0;
	for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) cont1++;
	for (const Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) cont2++;
	if (cont1 > cont2) {
		for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
				if (tmp2 == tmp) return tmp2;
			}
		}
	}
	else {
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
				if (tmp2 == tmp) return tmp2;
			}
		}
	}
	return ListCreateEmpty();
}