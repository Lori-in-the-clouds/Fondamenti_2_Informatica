#include "tree.h"
extern Node* Tree2Bst(const Node* t);
int main(void) {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* t = TreeCreateRoot(
		e + 6,
		TreeCreateRoot(e + 2, TreeCreateRoot(e + 3, TreeCreateEmpty(), TreeCreateEmpty()), TreeCreateRoot(e + 8, TreeCreateEmpty(), TreeCreateRoot(e + 5, TreeCreateEmpty(), TreeCreateEmpty()))),
		TreeCreateRoot(e + 9, TreeCreateEmpty(), TreeCreateRoot(e + 3, TreeCreateEmpty(), TreeCreateEmpty()))
		);
	Node *ris = Tree2Bst(t);
	TreeWriteInOrder(ris,stdout);
}