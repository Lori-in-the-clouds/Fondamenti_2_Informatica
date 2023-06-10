#include "list.h";
int ListLenghtRec(const Item* i,int *dim) {
	if (ListIsEmpty(i)) {
		return dim;
	}
	(*dim)++;
	ListLenghtRec(i = ListGetTail(i), dim);
}
int ListLenght(const Item* i) {
	int dim = 0;
	ListLenghtRec(i, &dim);
	return dim;
	
}