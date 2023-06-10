#include "tree.h"
extern void SostituisciSomma(Node* t);
int main(void) {
	int v[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	Node* t = TreeCreateRoot(
		v + 2,
		TreeCreateRoot(v + 1, TreeCreateRoot(v + 7, NULL, NULL), TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 3, TreeCreateRoot(v + 2, NULL, NULL), TreeCreateRoot(v + 4, NULL, NULL))
	);
	SostituisciSomma(t);
}
