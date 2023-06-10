#include "differenza.h"
#include "list.h"
int main(void) {
	int v1[] = { 1,2,3 };
	int v2[] = { 3,2,4 };
	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();
	for (int i = 0; i < sizeof(v1) / sizeof(int); i++) {
		i1 = ListInsertBack(i1, v1 + i);
	}
	/*for (int i = 0; i < sizeof(v2) / sizeof(int); i++) {
		i2 = ListInsertBack(i2, v2 + i);
	}*/
	Item *ris = Differenza(i1, i2);
}