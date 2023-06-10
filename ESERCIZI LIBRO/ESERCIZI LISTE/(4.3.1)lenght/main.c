#include "list.h"
extern int ListLength(const Item* i);
int main(void) {
	Item* p = ListCreateEmpty();
	int v[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	ListLength(p);
	return 0;
}