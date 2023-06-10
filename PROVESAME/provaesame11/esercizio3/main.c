#include "list.h"
#include <stdlib.h>
extern Item* BucketSort(Item* i);
int main(void) {
	ElemType v[] = { 7,2,5,4 };
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(ElemType); j++) {
		i = ListInsertBack(i, v + j);
	}
	Item *ris =BucketSort(i);
}