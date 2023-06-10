#include "elemtype.h"
#include "tree.h"

Node* left(Node* t) {
	if (TreeIsEmpty(TreeLeft(t))) return t;
	return left(TreeLeft(t));
}
void inserisci(Node* t, Node** prev) {
	if (TreeIsEmpty(t)) return;
	inserisci(TreeLeft(t), prev);
	if (t != *prev) {
		 (*prev)->next = t;
	}
	*prev = t;
	inserisci(TreeRight(t), prev);
}
void PopulatingNext(Node* t) {
	Node *starter = left(t);
	inserisci(t, &starter);
	return;
}


int main(void) {
	int e[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	Node* t = TreeCreateRoot(
		e+2,
		TreeCreateRoot(e+1,TreeCreateRoot(e+7,NULL,NULL), TreeCreateRoot(e+4,NULL,NULL)),
		TreeCreateRoot(e + 3, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e, NULL, NULL))
	);
	PopulatingNext(t);

}