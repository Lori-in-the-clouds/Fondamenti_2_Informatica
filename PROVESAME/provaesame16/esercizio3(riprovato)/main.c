#include "elemtype.h"
#include "list.h"
extern Item* Rotate(Item* i, int n);
int main(void) {
	int v[] = { 1,3,4,7,8 };
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i = ListInsertBack(i, v + j);
	}
	Item *ris = Rotate(i, 2);
}