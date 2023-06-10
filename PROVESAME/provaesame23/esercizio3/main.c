#include "next_greater.h"
int main(void) {
	int v[] = { 2,3,1,4,7,2 };
	Item *list = ListCreateEmpty();
	for (int i = 0; i < sizeof(v) / sizeof(int); i++) {
		list = ListInsertBack(list, v + i);
	}
	size_t answer_size = 0;
	ElemType *ris = NextGreater(list, &answer_size);
}