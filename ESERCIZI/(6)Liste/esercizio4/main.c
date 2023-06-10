#include "list.h"
extern Item* IntersectNoRep(const Item* i1, const Item* i2);
extern Item* DiffNoRep(const Item* i1, const Item* i2);
int main(void) {
	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();
	int ii1[] = { 1,3,4,2,0,45,2,1 };
	int ii2[] = { 45,8,5,2,3,45,7,5 };
	for (int i = 0; i < 8; i++) {
		i1 = ListInsertBack(i1, &ii1[i]);
	}
	for (int j = 0; j < 8; j++) {
		i2 = ListInsertBack(i2, &ii2[j]);
	}
	IntersectNoRep(i1, i2);
	//DiffNoRep(i1, i2);

	return 0;
}