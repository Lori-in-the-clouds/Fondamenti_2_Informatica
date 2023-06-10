#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
extern Item* BucketSort(Item* l);
extern Item* ConcatenaN(Item** v, size_t v_size);
int main(void) {
	Item* i = ListCreateEmpty();
	int v[] = { 6, 5, 4, 3, 7 };
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i = ListInsertBack(i, v + j);
		

	}
	//BucketSort(i);
	Item* ris = BucketSort(i);

}