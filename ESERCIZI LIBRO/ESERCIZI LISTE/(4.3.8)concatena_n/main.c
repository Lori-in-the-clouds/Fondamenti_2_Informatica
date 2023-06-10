#include "list.h"
#include <stdlib.h>
extern Item* ConcatenaN(Item** v, size_t v_size);
int main(void) {
	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();
	Item* i3 = ListCreateEmpty();
	Item* i4 = ListCreateEmpty();
	Item* i5 = ListCreateEmpty();


	Item* v[] = { i1,i2,i3,i4,i5 };
	int s[] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		v[0] = ListInsertBack(v[0], s+i);
		//v[1] = ListInsertBack(v[1], &s[i]);0
		v[2] = ListInsertBack(v[2], &s[i]);
		v[3] = ListInsertBack(v[3], &s[i]);
		v[4] = ListInsertBack(v[4], &s[i]);


	}
	ConcatenaN(v, 4);
	return 0;
}