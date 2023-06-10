#include "elemtype.h"
#include "list.h"
#include "cc.h"
int main(void) {
	int v[] = { 0,1,3,4,5,6,8,7};
	int v1[] = {7,8,0,4,6};
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i = ListInsertBack(i, v + j);
	}
	ComponentiConnesse(i, v1, 5);
}