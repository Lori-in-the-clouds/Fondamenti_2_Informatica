#include "list.h"
#include "minheap.h"
#include "tree.h"
#include <stdlib.h>
extern Item* Reverse(Item* list, int right);
int main(void) {
    int v[] = { 0,1,2,3,4,5,6,7,8 };
    Item* i1 = ListCreateEmpty();
    for (int i = 0; i < sizeof(v) / sizeof(int); i++) {
        i1 = ListInsertBack(i1, v + i);
    }
    Reverse(i1, 12);

}
//LISTA


//ALBERO
/* const ElemType e[] = { 12,4,21,0,2,77,8,9,21,5,18 };
 Node* t = TreeCreateEmpty();
 t = TreeCreateRoot(
     e,
     TreeCreateRoot(e + 1, TreeCreateRoot(e + 3, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 6, NULL, NULL)), TreeCreateRoot(e + 4, TreeCreateRoot(e + 7, NULL, NULL), NULL)),
     TreeCreateRoot(e + 8, TreeCreateRoot(e + 9, NULL, NULL), TreeCreateRoot(e + 10, NULL, NULL))
 );*/
 /*    12
      /  \
     /    \
    4      21
   / \    / \
  /   \  5  18
 0     2
/ \   /
77  8 9*/


//ALBERO BST
 /* const ElemType e[] = { 0,1,2,3,4,5,6,7,8 };
  Node* t = TreeCreateRoot(
      e + 4,
      TreeCreateRoot(e + 2, TreeCreateRoot(e + 1, NULL, NULL), TreeCreateRoot(e + 3, NULL, NULL)),
      TreeCreateRoot(e + 6, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 7, NULL, NULL))
  );

  Node* s = TreeCreateRoot(
      e + 7,
      TreeCreateRoot(e + 4, TreeCreateRoot(e + 2, TreeCreateRoot(e + 1, NULL, NULL), NULL), TreeCreateRoot(e + 5, NULL, NULL)),
      TreeCreateRoot(e + 8, NULL, NULL)
  );
  TreeWriteInOrder(s, stdout);*/

  //HEAP
//   ElemType v[] = { 0,2,4,8,12,18,77,21,9 };
//   Heap* h = HeapCreateEmpty();
//   h->size = sizeof(v) / sizeof(ElemType);
//   h->data = malloc(h->size * sizeof(int));
//   memcpy(h->data, v, h->size * sizeof(int));
//   /*    0
//       /   \
 //      /     \
 //     2       4
 //    / \     / \
 //   /   \  18  77
 //  8     12
 // / \   
 //21  9 */