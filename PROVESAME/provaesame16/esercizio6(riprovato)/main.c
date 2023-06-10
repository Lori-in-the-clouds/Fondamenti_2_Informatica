#include "elemtype.h"
#include "tree.h"
extern Node* Tree2Bst(const Node* t);
int main(void) {
	int e[] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* t = TreeCreateRoot(
		e + 6,
		TreeCreateRoot(e + 2, TreeCreateRoot(e + 3, NULL, NULL), TreeCreateRoot(e + 8, NULL, TreeCreateRoot(e + 5, NULL, NULL))),
		TreeCreateRoot(e+9,NULL,TreeCreateRoot(e+3,NULL,NULL))
		);
	Node *ris = Tree2Bst(t);
}