#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
bool verifica(const ElemType* e, Node* tmp, int n,const Node *t) {
	if (TreeIsEmpty(tmp)) return false;
	int som = *e + *TreeGetRootValue(tmp);
	if (som == n && tmp != t) {
		return true;
	}
	return verifica(e, TreeLeft(tmp), n,t) || verifica(e, TreeRight(tmp), n,t);
}
bool rec(const Node* t, Node* tmp, int n) {
	
	if (TreeIsEmpty(t)) return false;
	if (verifica(TreeGetRootValue(t), tmp,n,t)) return true;
	return rec(TreeLeft(t), tmp, n) || rec(TreeRight(t), tmp, n);
}
bool CheckSumN(const Node* t, int n) {
	if (TreeIsEmpty(t) || (TreeIsEmpty(TreeLeft(t)) && TreeIsEmpty(TreeRight(t)))) return false;
	Node* tmp = t;
	return rec(t, tmp, n);
}