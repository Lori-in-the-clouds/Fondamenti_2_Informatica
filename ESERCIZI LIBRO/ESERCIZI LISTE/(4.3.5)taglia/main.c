#include "list.h"
extern Item* Taglia(Item* i, int n);
int main(void) {
	Item* p = ListCreateEmpty();
	int v[] = {0, 1,2,3 };
	for (int i = 0; i < 4; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	Item* ris = Taglia(p, 4);
	return 0;
}