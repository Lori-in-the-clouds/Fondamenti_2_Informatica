#include "tree.h"
#include <stdlib.h>
#include <crtdbg.h>
extern Node* TreePrune(Node* t, const ElemType* cut_value);
int main(void) {
	ElemType* e = malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++) {
		e[i] = i;
	}
	Node* t = TreeCreateRoot(
		e + 2,
		TreeCreateRoot(e + 3, TreeCreateRoot(e + 4, TreeCreateRoot(e + 8, NULL, NULL), TreeCreateRoot(e + 1, NULL, NULL)), NULL),
		TreeCreateRoot(e + 7,NULL, TreeCreateRoot(e + 4, TreeCreateRoot(e , NULL, NULL), TreeCreateRoot(e + 1, NULL, NULL)))
		);
	ElemType cut_value = 4;
	TreePrune(t, &cut_value);
	TreeDelete(t);
	free(e);
	_CrtDumpMemoryLeaks();
}