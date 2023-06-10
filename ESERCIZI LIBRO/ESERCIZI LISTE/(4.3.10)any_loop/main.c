#include <stdbool.h>
#include "list.h"
extern bool AnyLoop(const Item* i1);
int main(void) {
	ElemType v[] = { 12,99,37 };
	Item* i = ListInsertHead(v, ListInsertHead(v + 1, ListInsertHead(v + 2, NULL)));
	//i->next->next->next = i;
	AnyLoop(i);
}