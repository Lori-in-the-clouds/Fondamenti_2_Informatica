#include "elemtype.h"
#include "list.h"
#include "tree.h"
#include "reverse.h"
int main(void) {
	int v[] = { 0,1,2,3,4,5,6,7,8 };
Item* i = ListCreateEmpty();
for (int j = 0; j < sizeof(v) / sizeof(int); j++) {
	i = ListInsertBack(i, v + j);
}
Item *ris =Reverse(i, 12);

}


//LISTA


//ALBERO
	//int e[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	//Node* t = TreeCreateRoot(
	//	e + 2,
	//	TreeCreateRoot(e + 1, TreeCreateRoot(e + 7, NULL, NULL), TreeCreateRoot(e + 4, NULL, NULL)),
	//	TreeCreateRoot(e + 3, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e, NULL, NULL))
	//);
	//  2
	///   \
 //  1      3
 // / \    / \
 //7   4  5   0


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
//   /*     0
//        /   \
 //      /     \
 //     2       4
 //    / \     / \
 //   /   \  18  77
 //  8     12
 // / \   
 //21  9 */

