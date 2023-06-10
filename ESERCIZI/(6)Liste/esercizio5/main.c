#include "list.h"
extern const ElemType* MaxElement(const Item* i);
int main(void) {
	Item* i1 = ListCreateEmpty();
	int ii1[] = { 3, 4, 2, 0, 45, 1 };
	for (int i = 0; i < 6; i++) {
		i1 = ListInsertBack(i1, &ii1[i]);
	}
	MaxElement(i1);
	return 0;

}