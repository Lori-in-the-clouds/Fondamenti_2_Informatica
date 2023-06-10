#include "elemtype.h"
#include "list.h"
extern Item* Sum(const Item* i1, const Item* i2);
Item* Taglia_al_presente(Item* i1, ElemType* e);
int main(void) {
	int v1[] = { 1,2,3,4,5,6,7 };
	int v2[] = {7 };
	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();
	for (int j = 0; j < sizeof(v1) / sizeof(int); j++) {
		i1 = ListInsertBack(i1, v1 + j);
	}
	for (int j = 0; j < sizeof(v2) / sizeof(int); j++) {
		i2 = ListInsertBack(i2, v2 + j);
	}
	//Item *ris = Sum(i1, i2);
	ElemType e = 7;
	Item* ris = Taglia_al_presente(i1, &e);
}