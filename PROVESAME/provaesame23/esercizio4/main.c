#include "tree.h"
extern Node* Invert(Node* t);
int main(void) {
	int e[] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* t = TreeCreateEmpty();
	t = TreeCreateRoot(
		e + 2,
		TreeCreateRoot(e + 1, TreeCreateRoot(e + 7, NULL, NULL), TreeCreateRoot(e + 4, NULL, NULL)),
		TreeCreateRoot(e + 3, TreeCreateRoot(e + 2, NULL, NULL), TreeCreateRoot(e + 4, NULL, NULL))
	);
	Node *ris = Invert(t);
}