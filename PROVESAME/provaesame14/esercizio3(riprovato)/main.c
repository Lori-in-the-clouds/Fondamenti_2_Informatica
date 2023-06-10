#include "elemtype.h"
#include "list.h"
extern Item* ElementiPari(const Item* i);
int main(void) {
	int v[] = { 7,2,5,8,6,4 };
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i = ListInsertBack(i, v + j);
	}
	ElementiPari(i);
}