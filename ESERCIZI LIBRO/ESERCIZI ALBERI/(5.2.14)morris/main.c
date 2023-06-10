#include "tree.h"
extern void TreeMorrisInOrder(Node* t);
int main(void) {
    const ElemType e[] = { 0,1,2,3,4,5,6,7,8 };
    Node* t = TreeCreateRoot(
        e + 2,
        TreeCreateRoot(e + 3, TreeCreateRoot(e + 4, NULL, NULL), TreeCreateRoot(e + 7, NULL, NULL)),
        TreeCreateRoot(e + 5,NULL, TreeCreateRoot(e + 6, NULL, NULL))
    );
    TreeMorrisInOrder(t);
    return 0;

}