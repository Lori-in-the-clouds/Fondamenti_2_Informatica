#include "list.h"
extern Item* BucketSort(Item* i);
int main(void) {
	Item* p = ListCreateEmpty();
	int v[] ={7,2,5,4};
	for (int i = 0; i < 4; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	BucketSort(p);
	return 0;
}