#include <math.h>
#include <string.h> 
int rec(const char* str, int pow, int* ris,int i) {
	if (i == strlen(str)) {
		return ris[0];
	}
	ris[0]+= (str[i] - 48) * (int)powf(10, strlen(str) - i -1);
	rec(str, pow, ris, i + 1);
}
 int AToI(const char* str) {
	 if (str == NULL) return 0;
	 int ris = 0;
	 return rec(str, 1, &ris,0);
}

