#include "elemtype.h"
#include "tree.h"
extern void PopulatingNext(Node* t);
int main(void) {
    const ElemType e[] = { 0,1,2,3,4,5,6,7,8 };
    Node* t = TreeCreateEmpty();
    t = TreeCreateRoot(
        e+2,
        TreeCreateRoot(e+1,TreeCreateRoot(e+7,NULL,NULL),TreeCreateRoot(e+4,NULL,NULL)),
        TreeCreateRoot(e + 3, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e, NULL, NULL))
    );
    
    PopulatingNext(t);

}
//ALBERO

 /*    12
      /  \
     /    \
    4      21
   / \    / \
  /   \  5  18
 0     2
/ \   /
77  8 9*/
