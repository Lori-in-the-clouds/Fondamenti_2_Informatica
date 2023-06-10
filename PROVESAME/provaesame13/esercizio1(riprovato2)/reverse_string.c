#include <stdlib.h>
#include <string.h>
void rec(const char* str, char* ris,int len,int i) {
	if (i == (int)strlen(str)+1) return;
	ris[i] = str[len];
	rec(str, ris, len - 1, i + 1);
}
char* ReverseString(const char* str) {
	if (str == NULL) return NULL;
	char* ris = calloc(strlen(str)+1, sizeof(char));
	rec(str, ris, strlen(str)-1,0);
	ris[strlen(str)]='\0';
	return ris;
}

