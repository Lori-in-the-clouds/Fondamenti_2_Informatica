#include "elemtype.h"
#include "list.h"
#include "next_greater.h"
int main(void) {
	int v[] = { 2,3,1,4,7,2 };
	Item* list = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		list = ListInsertBack(list, v + j);
	}
	int size = 0;
	NextGreater(list, &size);
}