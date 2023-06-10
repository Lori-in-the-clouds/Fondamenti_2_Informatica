#include "list.h"
extern Item* ElementiPari(const Item* i);

int main(void) {
	Item* n = ListCreateEmpty();
	int v[] = { 7,2,5,8,6};
	for (int j = 0; j < 5; j++) {
		n = ListInsertBack(n, v + j);
	}
	ElementiPari(n);
	return 0;

}
