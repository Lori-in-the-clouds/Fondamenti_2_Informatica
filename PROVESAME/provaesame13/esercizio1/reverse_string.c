#include <stdlib.h>
#include <string.h>
void rec(const char* str, char* ris, int i) {
	if (strlen(str)==0) {
		return;
	}
	rec(str+1, ris, i-1);
	ris[i] = *str;
}
char* ReverseString(const char* str) {
	if (str == NULL) {
		return NULL;
	}
	char* ris = malloc((strlen(str)+1)*sizeof(char));
	rec(str, ris, strlen(str) -1);
	ris[strlen(str)] = '\0';
	return ris;
}