#include "list.h"
extern Item* Diff(const Item* i1, const Item* i2);
int main(void) {
	Item* i1 = ListCreateEmpty();
	int ii1[] = { 1,45,0,2,4,1,3 };
	int ii2[] = { 7,45,3,2,5 };

	Item* i2 = ListCreateEmpty();
	for (int i = 0; i < 7; i++) {
		i1 =ListInsertBack(i1,&ii1[i]);
	}
	for (int i = 0; i < 6; i++) {
		i2 = ListInsertBack(i2, &ii2[i]);
	}	
	Diff(i1, i2);
	
	return 0;
}