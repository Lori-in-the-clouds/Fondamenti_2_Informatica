#include "list.h"
extern Item* Sum(const Item* i1, const Item* i2);
int main(void) {
	Item* p = ListCreateEmpty();
	int v[] = { 3,2,4 };
	int v1[] = { 7 };
	Item* p2 = ListCreateEmpty();
	for (int i = 0; i < sizeof(v)/sizeof(int); i++) {
		p = ListInsertBack(p, &v[i]);
	}
	for (int i = 0; i < sizeof(v1) / sizeof(int); i++) {
		p2 = ListInsertBack(p2, &v1[i]);
	}
	Sum(p, p2);
	return 0;
}