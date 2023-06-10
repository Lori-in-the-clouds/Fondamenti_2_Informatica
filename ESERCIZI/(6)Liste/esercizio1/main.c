#include "list.h"
extern Item* ListLoad(const char* filename);
//PER CREARE UNA LISTA 
// l = ListInsertHead(e+1,l); 
// 
//PER SCORRERE UNA LISTA 
// Item *tmp = l;  copio detro temp l'indirizzo della prima lista  
//while(!ListIsEmpty(l)) {
// ElemWriteStdout(ListGetHeadValue(l));
// l = ListGetTail(l);
//}
//PER COPIARE UNA LISTA 
//while(! ListIsEmpty(tmp)) {s
//	tmp = ListGetTail(tmp);
//}4
int main(void) {
	char* namefile = "data_00.txt";
	ListLoad(namefile);
	return 0;
}