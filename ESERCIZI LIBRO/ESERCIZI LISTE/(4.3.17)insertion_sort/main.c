#include "list.h"
extern void InsertionSort(Item** i);
extern Item* InsertOrd(Item* i, ElemType* e);
int main(void) {
	Item* p = ListCreateEmpty();
	int v[] = {1,2,4,5};
	for (int i = 0; i < 4; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	ElemType e = 3;
	InsertOrd(p,&e);
	//InsertionSort(&p);
	return 0;
}