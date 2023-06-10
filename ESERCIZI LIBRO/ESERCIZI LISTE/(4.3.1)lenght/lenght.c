#include "list.h"
//VERSIONE ITERATIVA 
//int ListLength(const Item* i) {
//	int sum = 0;
//	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
//		sum++;
//	}
//	return sum;
//}


//VERSIONE RICORSIVA 
int ListLengthRec(Item* i, int sum) {
	if (ListIsEmpty(i)) return sum;
	i = ListGetTail(i);
	ListLengthRec(i, sum + 1);
}
int ListLength(const Item* i) {
	int sum = 0;
	if (ListIsEmpty(i)) return sum;
	return ListLengthRec(i, sum);
}

