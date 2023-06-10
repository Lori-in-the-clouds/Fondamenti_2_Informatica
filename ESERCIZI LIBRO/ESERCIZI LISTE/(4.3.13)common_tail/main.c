#include "list.h"
extern const Item* CommonTail(const Item* i1, const Item* i2);
int main(void) {
	ElemType v[] = { 0,1,2,3,4,5,6,7,8,9 };
	//i1 -> 7 ->2 ->5 ->4->null
	Item* i1 = ListInsertHead(&v[7], ListInsertHead(&v[2], ListInsertHead(&v[5], ListInsertHead(&v[4], NULL))));
	////i2 -> 8 ->3->5->4->NULL
	Item* i2 = ListInsertHead(&v[8], ListInsertHead(&v[3], ListInsertHead(&v[5],ListInsertHead(&v[4],NULL))));
	/*Item* tail = ListInsertHead(&v[5], ListInsertHead(&v[4], NULL));
	Item* i1 = ListInsertHead(&v[7], ListInsertHead(&v[2], tail));
	Item* i2 = ListInsertHead(&v[8], ListInsertHead(&v[3], ListInsertHead(&v[6], tail)));*/
	const Item* common = CommonTail(i1, i2);
}