#include <stdlib.h>
#include <stdbool.h>
void rec(const int* bam, size_t bam_size, const int* bis, size_t bis_size, int* vcurr, int i, bool* preso,int *max,bool control) {
	if (control || i == bam_size) {
		//controlliamo quanti bambini sono soddisfatti
		int ris = 0;
		for (size_t j = 0; j < bam_size; j++) {
			if (vcurr[j] >= bam[j]) ris++;
		}
		if (ris > max[0]) *max = ris;
		control = false;
		return;
	}
	for (size_t j = 0; j < bis_size; j++) {
		if (!preso[j]) {
			vcurr[i] += bis[j];
			preso[j] = true;
			if (vcurr[i] < bam[i]) rec(bam, bam_size, bis, bis_size, vcurr, i, preso, max, false);
			else rec(bam, bam_size, bis, bis_size, vcurr, i+1, preso, max, false);
			vcurr[i] -= bis[j];
			preso[j] = false;
		}
	}
	//abbiamo finiti i biscotti
	rec(bam, bam_size, bis, bis_size, vcurr, i, preso, max,true);
}
int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size) {
	if (bam == NULL || bis == NULL || bam_size <= 0 || bis_size <= 0) return 0;
	int* vcurr = calloc(bam_size, sizeof(int));
	bool* preso = calloc(bis_size, sizeof(bool));
	int max = 0;
	rec(bam, bam_size, bis, bis_size, vcurr, 0, preso,&max,false);
	free(vcurr);
	free(preso);
	return max;
}


//int main(void) {
//	int bam[] = { 5,10,15,20,25,30,35 };
//	int bis[] = { 32,29,10,7,29,3,11,23 };
//	AssegnaBiscotti(bam, sizeof(bam) / sizeof(int), bis, sizeof(bis) / sizeof(int));
//}