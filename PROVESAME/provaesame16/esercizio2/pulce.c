#include <stdlib.h>
#include <stdbool.h>
void GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size, int* vcurr, size_t i, char* vbest,bool *modificato) {
	//1 va in avanti
	//0 va indietro 
	int sum = 0;
	if (i == n) {
		return;
	}
	for (size_t j = 0; j < i; j++) {
		sum += vcurr[j];
		if (vcurr[j] == b && vcurr[j - 1] == b) {
			vcurr[j] = 0;
			return;
		}
		if (sum < 0) {
			vcurr[j] = 0;
			return;
		}
	}
	//controllo se è andato in posti sbagliati
	for (size_t j = 0; j < i; j++) {
		for (size_t m = 0; m < f_size; m++) {
			if (vcurr[j] == f[m]) {
				//azzero quelli prima 
				vcurr[j] = 0;
				return;
			}
		}
	}
	//controllo se siamo arrivati 
	if (sum == h) {
		if (i < ret_size[0]) {
			ret_size[0] = i;
			modificato[0] = true;
			for (int j = 0; j < i; j++) {
				if (vcurr[j] == a) {
					vbest[j] = 'a';
				}
				else {
					vbest[j] = 'b';
				}
			}
		}
	}
	vcurr[i] = 1 * a;
	GuidaLaPulceRec(f, f_size, a, b, n, h,ret_size, vcurr, i + 1, vbest,modificato);
	vcurr[i] = -1 * b;
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, vcurr, i + 1, vbest,modificato);
}
char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h,size_t *ret_size) {
	int* vcurr = calloc(n, sizeof(int));
	char* vbest = calloc(n, sizeof(char));
	bool modificato = false;
	*ret_size = n;
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, vcurr, 0, vbest,&modificato);
	if (!modificato) {
		*ret_size = 0;
	}
	free(vcurr);
	return vbest;
 }