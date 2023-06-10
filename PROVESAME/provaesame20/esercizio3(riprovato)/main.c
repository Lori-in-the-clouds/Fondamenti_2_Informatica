#include "elemtype.h"
#include "list.h"
#include "remove.h"
int main(void) {
	int v[] = { 1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5};
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i = ListInsertBack(i, v + j);
	}
	Item *ris = RemoveDuplicates(i);
}