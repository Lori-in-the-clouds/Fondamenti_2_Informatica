#include "list.h"
#include "elemtype.h"
#include "reverse.h"
int main(void) {
	int v[] = { 0,1,2,3,4,5,6,7,8 };
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i = ListInsertBack(i, v + j);
	}
	Reverse(i, 3);
}
