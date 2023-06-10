#include "list.h"
#include "merge.h"
int main(void) {
	ElemType v1[] = { 1,3,5,7,9,10 };
	ElemType v2[] = { 2,4,6,8};
	Item* i1 = ListCreateEmpty();
	for (int i = 0; i < sizeof(v1) / sizeof(int); i++) {
		i1 = ListInsertBack(i1, v1 + i);
	}
	Item* i2 = ListCreateEmpty();
	for (int i = 0; i < sizeof(v2) / sizeof(int); i++) {
		i2 = ListInsertBack(i2, v2 + i);
	}
	Item *ris = OrderedMerge(i1, i2,kNoCopy);

}