#include "elemtype.h"
#include "tree.h"
extern Node* CreateMaxBinTree(const ElemType* v, size_t v_size);
int main(void) {
	int v[] = { 3,2,1 };
	Node *ris = CreateMaxBinTree(v, sizeof(v) / sizeof(int));
	TreeWriteInOrder(ris,stdout);
}