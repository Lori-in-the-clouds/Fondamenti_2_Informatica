#include "tree.h"
extern bool Equivalenti(const Node* t1, const Node* t2);
int main(void) {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };
	Node* t1 = TreeCreateRoot(
		e+1,
		TreeCreateRoot(e+2,TreeCreateRoot(e+4,TreeCreateRoot(e+7,NULL,NULL), TreeCreateRoot(e+8,NULL,NULL)),TreeCreateRoot(e+5,NULL,NULL)),
		TreeCreateRoot(e+3,TreeCreateRoot(e+6,NULL,NULL),NULL)
	);
	Node* t2 = TreeCreateRoot(
		e + 1,
		TreeCreateRoot(e + 2, TreeCreateRoot(e + 4, TreeCreateRoot(e + 21, NULL, NULL), TreeCreateRoot(e + 2, NULL, NULL)), TreeCreateRoot(e + 5, NULL, NULL)),
		TreeCreateRoot(e + 3, TreeCreateRoot(e + 12, NULL, NULL),NULL)
	);
	Equivalenti(t1, t2);
}