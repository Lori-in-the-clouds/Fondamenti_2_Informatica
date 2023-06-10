#include "elemtype.h"
#include "list.h"
extern Item* Differenza(const Item* i1, const Item* i2);
int main(void) {
	int v1[] = { 1,2,3};
	int *v2 = NULL;
	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();
	for (int j = 0; j < sizeof(v1) / sizeof(int); j++) {
		i1 = ListInsertBack(i1, v1 + j);
	}
	/*for (int j = 0; j < sizeof(v2) / sizeof(int); j++) {
		i2 = ListInsertBack(i2, v2 + j);
	}*/
	Differenza(i1,i2);

}