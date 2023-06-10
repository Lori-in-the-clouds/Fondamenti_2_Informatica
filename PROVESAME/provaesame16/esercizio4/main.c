#include "tree.h"
extern Node* CreateMaxBinTree(const ElemType* v, size_t v_size);
int main(void) {
	ElemType v[] = { 3,2,1 };
	CreateMaxBinTree(v, 3);
	return 0;

}