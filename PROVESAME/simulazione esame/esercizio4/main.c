#include "tree.h"
extern Node* TreeRead(const char* filename);
int main(void) {
	char* filename = "albero1.txt";
	TreeRead(filename);
}