#include "elemtype.h"
#include "tree.h"
void rec1(const Node* t, const ElemType* e, Node** prev, Node** ris) {
	if (TreeIsEmpty(t)) return;
    rec1(TreeLeft(t), e, prev, ris);
    if (ElemCompare(e, TreeGetRootValue(t)) == 0) {
        *ris = *prev;
    }
    *prev = t;
    rec1(TreeRight(t), e, prev, ris);


}
const Node* Predecessore(const Node* t, const ElemType* e) {
    if (TreeIsEmpty(t)) return TreeCreateEmpty();
    Node* ris = TreeCreateEmpty();
    Node* prev = TreeCreateEmpty();
    rec1(t, e,&prev, &ris);
    TreeDelete(prev);
    return ris;
}
void rec2(const Node* t, const ElemType* e, Node** ris,bool *control) {
    if (TreeIsEmpty(t)) return;
    rec2(TreeLeft(t), e, ris, control);
    if (control[0]) {
        *ris = t;
        control[0] = false;
    }
    if (ElemCompare(e, TreeGetRootValue(t)) == 0) {
        control[0] = true;
    }
    rec2(TreeRight(t), e, ris, control);
}
const Node* Successore(const Node* t, const ElemType* e) {
    if (TreeIsEmpty(t)) return TreeCreateEmpty();
    Node* ris = TreeCreateEmpty();
    Node* succ = TreeCreateEmpty();
    bool control = false;
    rec2(t, e, &ris,&control);
    TreeDelete(succ);
    return ris;
}

//int main(void) {
//    int e[] = { 0,1,2,3,4,5,6,7,8 };
//    Node* t = TreeCreateRoot(
//        e+7,
//        TreeCreateRoot(e+4,TreeCreateRoot(e+2,TreeCreateRoot(e+1,NULL,NULL),NULL),TreeCreateRoot(e+5,NULL,NULL)),
//        TreeCreateRoot(e+8,NULL,NULL)
//    );
//    ElemType c = 8;
//    Node *ris = Successore(t, &c);
//    Node* ris1 = Predecessore(t, &c);
//}


