#include "list.h"
extern Item* Reverse(Item* i);
int main(void) {
	Item* n = ListCreateEmpty();
	int v[] = { 1,3,4,7,8 };
	for (int i = 0; i < 5; i++) {
		n = ListInsertBack(n, v+i);
	}
	Reverse(n);
	return 0;
}