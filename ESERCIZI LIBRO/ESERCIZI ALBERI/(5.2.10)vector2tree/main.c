#include "vector_tree.h"
#include <limits.h>
int main(void) {
	ElemType v[] = { 8,2,4,5,INT_MAX,1,9 };
	Vector2Tree(v, 7, kOneBased);
	return  0;
}