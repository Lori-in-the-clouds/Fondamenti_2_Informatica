#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
extern bool TreeWrite(const Node* t, const char* filename);
int main(void) {
    const ElemType e[] = {0,1,2,3,4,5,6,7};
    Node* t = TreeCreateEmpty();
    t = TreeCreateRoot(
       e+1,
        TreeCreateRoot(e+2,NULL,NULL),
        TreeCreateRoot(e+3,TreeCreateRoot(e+4,TreeCreateRoot(e+6,NULL,NULL), TreeCreateRoot(e+7,NULL,NULL)),TreeCreateRoot(e+5,NULL,NULL))
    );
    /*     1
         /  \
        /    \
       2      3
             / \
            4  5
           / \
          6  7 
 */
    char* filename = "prova.txt";
    TreeWrite(t, filename);
}