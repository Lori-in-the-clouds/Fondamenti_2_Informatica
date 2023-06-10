#include "list.h"
extern Item* Rotate(Item* i, int n);
int main(void) {
	int v[] = { 1,3,4,7,8 };
	int n = 0;
	Item* m = ListCreateEmpty();
	for (int j = 0; j < sizeof(v)/sizeof(int); j++) {
		m = ListInsertBack(m, &v[j]);
	}
	Rotate(m, n);
}