#include "list.h"
extern void Back2Front(Item** i);
int main(void) {
	ElemType v[] = { 0,1,2,3,4 };
	Item* i = ListInsertHead(&v[1], ListInsertHead(&v[2], ListInsertHead(&v[3], ListInsertHead(&v[4], NULL))));
	Back2Front(&i);
	ListDelete(i);

}