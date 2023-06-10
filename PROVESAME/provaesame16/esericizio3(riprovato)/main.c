#include "elemtype.h"
#include "list.h"

extern Item* CreaDaInterni(const Item* i, double r);
int main(void) {
	ElemType v[] = { {.x = 1,.y = 1},{.x = 3,.y = 4} };
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(ElemType); j++) {
		i = ListInsertBack(i, v + j);
	}
	CreaDaInterni(i, 2);
}

