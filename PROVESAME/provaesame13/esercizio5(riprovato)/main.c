#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
extern bool CheckSumN(const Node* t, int n);
int main(void) {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9 };

	Node* t = TreeCreateRoot(
		e + 7,
		TreeCreateRoot(e + 6, TreeCreateRoot(e + 2, TreeCreateRoot(e + 1, NULL, NULL), NULL), TreeCreateRoot(e + 5, NULL, NULL)),
		TreeCreateRoot(e + 8, TreeCreateEmpty(), TreeCreateEmpty())
	);
	CheckSumN(t, 7);
}
