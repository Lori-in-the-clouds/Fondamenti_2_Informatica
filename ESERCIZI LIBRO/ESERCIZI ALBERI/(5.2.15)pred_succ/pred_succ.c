#include "tree.h"
void PredecessoreRec(Node* t, const ElemType* e,Node **past,Node **ris) {
	if (TreeIsEmpty(t)) return;
	PredecessoreRec(TreeLeft(t), e,past,ris);
	if (ElemCompare(TreeGetRootValue(t), e) == 0) {
		*ris = *past;
		return;
	}
	*past = t;
	PredecessoreRec(TreeRight(t), e,past,ris);
}
const Node* Predecessore(const Node* t, const ElemType* e) {
	Node* past = TreeCreateEmpty();
	Node* ris = TreeCreateEmpty();
	PredecessoreRec(t, e,&past,&ris);
	return ris;
}
 



void SuccessoreRec(const Node* t, const ElemType* e,int *control,Node **ris) {
	 if (TreeIsEmpty(t)) return;
	SuccessoreRec(TreeLeft(t), e,control,ris);
	if (*control == 1) {
		*ris = t;
		control[0]++;
		return;
	}
	if (ElemCompare(TreeGetRootValue(t), e) == 0) {
		control[0]++;
	}
	SuccessoreRec(TreeRight(t), e,control,ris);

}
const Node* Successore(const Node* t, const ElemType* e) {
	int control = 0;
	Node* ris = TreeCreateEmpty();
	SuccessoreRec(t, e, &control, &ris);
	return ris;
}



//Node* past = TreeCreateEmpty();
//Node* best = t;
//int diff = t->value;
//while (!TreeIsEmpty(t)) {
//	past = t;
//	if (ElemCompare(TreeGetRootValue(t), e) > 0)  t = TreeLeft(t);
//	else  t = TreeRight(t);
//	//trova il suo successore nel caso arrivi in fondo
//	if (((*TreeGetRootValue(t)) - e[0] < diff) && ((*TreeGetRootValue(t)) != e[0])) {
//		diff = *TreeGetRootValue(t) - e[0];
//		best = past;
//	}
//	if (ElemCompare(TreeGetRootValue(t), e) == 0) {
//		if (TreeIsLeaf(t)) {
//			if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(best)) > 0) return best;
//			else return TreeCreateEmpty();
//		}
//		else return TreeLeft(t);
//	}
//}