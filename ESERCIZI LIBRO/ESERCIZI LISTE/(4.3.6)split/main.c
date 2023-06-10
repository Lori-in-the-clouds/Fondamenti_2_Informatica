#include "list.h"
extern Item* Split(Item* i);
int main(void) {
	Item* p = ListCreateEmpty();
	int v[] = { 5,1,7,3,8 };
	for (int i = 0; i < 5; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	Split(p);
	return 0;
}