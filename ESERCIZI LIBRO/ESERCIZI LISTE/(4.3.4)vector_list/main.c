#include "list.h"
#include "vector_list.h"
int main(void) {
	Item* p = ListCreateEmpty();
	ElemType v[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	Item* ris = ListCreateEmpty();
	size_t nsol = 0;
	/*ElemType* ris1 = List2Vector(p, &nsol, kInOrder);*/
	 ElemType *ris1 = List2Vector(p, &nsol, kReverse);
	 ElemDelete(ris1);
	ris = Vector2List(v, 5, kInOrder);
	ris = Vector2List(v, 5, kReverse);
	return 0;
}