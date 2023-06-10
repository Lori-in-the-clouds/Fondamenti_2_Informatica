#include "tree.h"
extern bool Isomorfi(const Node* t1, const Node* t2);
int main(void) {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* t1 = TreeCreateRoot(
		e + 1,
		TreeCreateRoot(e + 2, TreeCreateRoot(e + 4, TreeCreateRoot(e + 7, NULL, NULL), TreeCreateRoot(e + 8, NULL, NULL)), TreeCreateRoot(e + 5, NULL, NULL)),
		TreeCreateRoot(e + 3, TreeCreateRoot(e + 6, NULL, NULL), NULL)
	);
	Node* t2 = TreeCreateRoot(
		e + 1,
		TreeCreateRoot(e + 3, TreeCreateRoot(e + 6, NULL, NULL), NULL),
		TreeCreateRoot(e + 2, TreeCreateRoot(e + 4, TreeCreateRoot(e + 8, NULL, NULL), TreeCreateRoot(e + 7, NULL, NULL)), TreeCreateRoot(e + 5, NULL, NULL))
	);
	Isomorfi(t1, t2);
}