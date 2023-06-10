#include "elemtype.h"
#include "list.h"
#include <stdbool.h>
int ContaVette(const Item* i) {
	if (ListIsEmpty(i)) return 0;
	int ris = 0;
	for (const Item* tmp1 = i; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		bool control = true;
		for (const Item* tmp2 = tmp1->next; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) < 0) {
				control = false;
				break;
			}
		}
		if (control) ris++;
	}
	return ris;
}

//int main(void) {
//	int v[] = { 7,2,5,4 };
//	Item* i = ListCreateEmpty();
//	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
//		i = ListInsertBack(i, v + j);
//	}
//	int ris = ContaVette(i);
//}