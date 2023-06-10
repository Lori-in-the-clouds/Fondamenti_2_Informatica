#include "list.h"
extern Item* Reverse(Item* i);
int main(void) {
	Item* p = ListCreateEmpty();
	int v[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	return 0;
}