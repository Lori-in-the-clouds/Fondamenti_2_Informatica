#include "tree.h"
extern int Diameter(const Node* t);
int main(void) {
    const ElemType e[] = { 12,4,21,0,2,77,8,9,21,5,18 };
    Node* t = TreeCreateEmpty();
    t = TreeCreateRoot(
        e,
        TreeCreateRoot(e + 1, TreeCreateRoot(e + 3, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 6, NULL, NULL)), TreeCreateRoot(e + 4, TreeCreateRoot(e + 7, NULL, NULL), NULL)),
        TreeCreateRoot(e + 8, TreeCreateRoot(e + 9, NULL, NULL), TreeCreateRoot(e + 10, NULL, NULL))
    );
 
    Diameter(t);
}