#include "tree.h"
extern double Mediano(const Node* t);
int main(void) {
    const ElemType e[] = { 0,1,2,3,4,5,6,7,8 };
    Node* t = TreeCreateRoot(
        e+4,
        TreeCreateRoot(e + 2,TreeCreateRoot(e+1,NULL,NULL), TreeCreateRoot(e + 3, NULL, NULL)),
        TreeCreateRoot(e + 6, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 7, NULL, NULL))
    );

    Node* s = TreeCreateRoot(
        e + 7,
        TreeCreateRoot(e+4,TreeCreateRoot(e+2,TreeCreateRoot(e+1,NULL,NULL),NULL),TreeCreateRoot(e+5,NULL,NULL)),
        TreeCreateRoot(e+8,NULL,NULL)
        );
    TreeWriteInOrder(s, stdout);
    Mediano(s);
    return 0;
}