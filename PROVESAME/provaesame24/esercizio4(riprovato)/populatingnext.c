#include "elemtype.h"
#include "tree.h"
void rec(Node* t, Node** prev) {
	if (TreeIsEmpty(t)) return;
	rec(TreeLeft(t), prev);
	if (t != *prev) {
		(*prev)->next = t;
	}
	*prev = t;
	rec(TreeRight(t), prev);
}
Node* cerca_primo(Node* t) {
	if (TreeIsEmpty(TreeLeft(t))) return t;
	else return cerca_primo(TreeLeft(t));
}
void PopulatingNext(Node* t) {
	Node* prev = cerca_primo(t);
	rec(t, &prev);
	return;
}

//int main(void) {
//	const ElemType e[] = { 0,1,2,3,4,5,6,7,8 };
//	Node* t = TreeCreateEmpty();
//	t = TreeCreateRoot(
//		e + 2,
//		TreeCreateRoot(e + 1, TreeCreateRoot(e + 7, NULL, NULL), TreeCreateRoot(e + 4, NULL, NULL)),
//		TreeCreateRoot(e + 3, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e, NULL, NULL))
//	);
//
//	PopulatingNext(t);
//
//}
//ALBERO

 /*    12
	  /  \
	 /    \
	4      21
   / \    / \
  /   \  5  18
 0     2
/ \   /
77  8 9*/