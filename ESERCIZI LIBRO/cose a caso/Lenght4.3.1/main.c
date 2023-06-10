#include "list.h"
extern int ListLenght(const Item* i);
int main(void) {
	Item* i = ListCreateEmpty();
	/*int v[] = { 1,2,3,4,5 };
	for (int j = 0; j < 5; j++) {
		i = ListInsertBack(i, &v[j]);
	}*/
	ListLenght(i);
}