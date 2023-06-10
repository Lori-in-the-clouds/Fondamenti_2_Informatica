#include "tree.h"
#include <stdlib.h>
extern Node* Vector2Bst(const ElemType* v, size_t v_size);
int main(void) {
	ElemType v[] = { 8,2,4,5,2,1,9 };
	Vector2Bst(v, 6);
}