#include "tree.h"
#include <stdbool.h>
extern bool CheckSumN(const Node* t, int n);
int main(void) {
    const ElemType e[] = { -2,1,2,3,4,5,-2 };
    Node* t = TreeCreateEmpty();
    t = TreeCreateRoot(
        e + 4,
        TreeCreateRoot(e+2,TreeCreateRoot(e+6,NULL,NULL),NULL),
        TreeCreateRoot(e+5,NULL,NULL)
    );
   
    /*      12
         /  \
        /    \
       4      21
      / \    / \
     /   \  5  18
    0     2
   / \   /
  77  8 9*/
    CheckSumN(t,0);
}