#include "list.h"
extern Item* Intersect(const Item* i1, const Item* i2);
int main(void) {
	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();
	int  i11[] = {1,3,4,2,0,45,2,1};
	int i22[] = { 45,8,5,2,3,45,7,5 };
	for (int i = 0; i < 8; i++) {
		i1 =ListInsertBack(i1,&i11[i]);
	}
	for (int i = 0; i < 8; i++) {
		i2 =ListInsertBack(i2,&i22[i]);
	}
	Intersect(i1, i2);
	return 0;

}