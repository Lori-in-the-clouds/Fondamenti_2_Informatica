#include "tree.h"
#include <stdbool.h>
extern int GetBalanceCoeff(const Node* n);
extern bool TreeIsBalanced(const Node* t);
int main(void) {
	Node* t = TreeCreateEmpty();
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9 };
	t = TreeCreateRoot(
		e + 8,
		TreeCreateRoot(e + 2, TreeCreateRoot(TreeCreateRoot(e + 1, NULL, NULL),NULL, TreeCreateRoot(e + 4, NULL, TreeCreateRoot(e + 5, NULL, NULL))), NULL),
		TreeCreateRoot(e + 9, TreeCreateEmpty(), TreeCreateEmpty())
		);
	TreeIsBalanced(t);
	GetBalanceCoeff(t);
	TreeIsBalanced(TreeLeft(t));
	GetBalanceCoeff(TreeLeft(t));
}