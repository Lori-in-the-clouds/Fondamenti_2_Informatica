#include "tree.h"
extern Node* CreateMinBinTree(const ElemType* v, size_t v_size);
int main(void) {
	ElemType v[] = { 3,2,1,6,8,5 };
	CreateMinBinTree(v, 6);

}