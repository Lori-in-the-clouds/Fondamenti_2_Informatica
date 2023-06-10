#include "tree.h"
#include <stdbool.h>
extern bool TreeIsMirror(Node* t);
int main(void) {
	Node* s = TreeCreateEmpty();
	Node* t = TreeCreateEmpty();
	int e[] = { 0,1,2,3,4,5 };
	s = TreeCreateRoot(
		e,
		TreeCreateRoot(e + 1, TreeCreateRoot(e + 4, NULL, NULL), TreeCreateRoot(e + 2, NULL, NULL)),
		TreeCreateRoot(e + 1, TreeCreateRoot(e + 4, NULL, NULL), TreeCreateRoot(e + 2, NULL, NULL))
	);
	t = TreeCreateRoot(
		e + 4,
		TreeCreateRoot(e + 5, TreeCreateRoot(e + 1, NULL, NULL), NULL),
		TreeCreateRoot(e + 5, NULL, NULL)
	);
	TreeIsMirror(t);
}