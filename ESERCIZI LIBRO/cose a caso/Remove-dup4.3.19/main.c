#include "list.h"
#include <stdbool.h>
extern Item* RemoveDuplicates(Item* i, bool ordered);
int main(void) {
	Item* i = ListCreateEmpty();
	int v[] = { 1,1,23,4,56,23,4 };
	int m[] = { 1,1,1,3,4,4,4 };
	for (int j = 0; j < 7; j++) {
		i = ListInsertBack(i, &v[j]);
	}
	Item* ris = ListCreateEmpty();
	ris =RemoveDuplicates(i,true);

}