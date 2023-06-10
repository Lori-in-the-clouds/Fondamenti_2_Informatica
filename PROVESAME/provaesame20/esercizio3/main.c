#include "list.h"
#include "remove.h"
int main(void) {
	int v[] = { 1,1,1,2,3};
	Item* i1 = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i1 = ListInsertBack(i1, v + j);
	}
	Item *ris = RemoveDuplicates(i1);
}