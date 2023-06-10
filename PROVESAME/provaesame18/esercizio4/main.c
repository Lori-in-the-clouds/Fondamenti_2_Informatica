#include "tree.h"
extern bool Cugini(const Node* t, int a, int b);
int main(void) {
	Node* s = TreeCreateEmpty();
	ElemType e[] = { 0,1,2,3,4,5,6,7,8 };
	s = TreeCreateRoot(
		e + 1,
		TreeCreateRoot(e + 2, TreeCreateRoot(e + 3, NULL, NULL), TreeCreateRoot(e + 4, NULL, NULL)),
		TreeCreateRoot(e + 5, TreeCreateRoot(e+6,NULL,TreeCreateRoot(e+8,NULL,NULL)),NULL)
	);
	int a = 3;
	int b = 4;
	Cugini(s, a, b);
}
