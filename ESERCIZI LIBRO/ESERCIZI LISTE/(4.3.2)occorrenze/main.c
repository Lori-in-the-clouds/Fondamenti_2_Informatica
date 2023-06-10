#include "list.h"
extern int ListOccorrenze(const Item* i, const ElemType* e);
int main(void) {
	Item* p = ListCreateEmpty();
	/*int v[] = { 1,5,3,4,5 };
	for (int i = 0; i < 5; i++) {
		p = ListInsertBack(p, &v[i]);
	}*/
	ElemType e = -1;
	ListOccorrenze(p, &e);
}