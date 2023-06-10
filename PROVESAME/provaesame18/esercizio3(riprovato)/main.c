#include "list.h"
#include "elemtype.h"
extern Item* PariDispari(Item* i);
int main(void) {
	int v[] = { 1,2,3,4 };
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
		i = ListInsertBack(i, v + j);
	}
	Item * ris = PariDispari(i);
}