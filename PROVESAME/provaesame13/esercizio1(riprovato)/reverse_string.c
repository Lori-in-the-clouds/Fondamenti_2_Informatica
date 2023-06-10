#include <stdlib.h>
#include <string.h>
void rec(const char* str, int len, char* nw,int i,int lenc) {
	nw[i] = str[len];
	if (i == lenc) return;

	rec(str, len - 1, nw, i + 1,lenc);
	return;
}
char* ReverseString(const char* str) {
	int n = strlen(str);
	if (n == 0 || str == NULL) return NULL;
	char* nw = calloc(n+1, sizeof(char));
	rec(str,n-1,nw,0,n);
	nw[n] = '\0';
	return nw;
}