#include "tree.h"
#include <stdbool.h>
bool EqualTree(Node* t1, Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) return true;
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) return false;
	
	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
		return false;
	}
	return EqualTree(TreeLeft(t1), TreeLeft(t2)) && EqualTree(TreeRight(t1), TreeRight(t2));
}
bool Rec2(const Node* t1, int n,int *add1,Node *t2) {
	if (TreeIsEmpty(t1)) return false;
	if (!EqualTree(t1, t2)) {
		int sum = (*TreeGetRootValue(t1)) + add1[0];
		if (ElemCompare(&n, &sum) == 0) return true;
	}
	return Rec2(TreeLeft(t1), n, add1, t2) || Rec2(TreeRight(t1), n, add1, t2);
}
bool Rec1(const Node* t,const Node *tmp, int n) {
	if (TreeIsEmpty(tmp)) return false;
	
	if (Rec2(t, n, TreeGetRootValue(tmp), tmp)) return true;
	
	return Rec1(t, TreeLeft(tmp), n) || Rec1(t, TreeRight(tmp), n);
		
}
bool CheckSumN(const Node* t, int n) {
	if (TreeIsEmpty(t) || n < 0) return false;
	Node* tmp = t;
	return Rec1(t,tmp, n);
	
}