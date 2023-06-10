#include <stdlib.h>
#include <stdbool.h>

void rec(const int* bam, size_t bam_size, const int* bis, size_t bis_size,int *vcurr,bool *preso,int *ris,int i,bool control) {
	if (control) {
		//contiamo quanti sono i bambini soddisfatti
		int num = 0;
		for (size_t j = 0; j < bam_size; j++) {
			if (vcurr[j] >= bam[j]) num++;
		}
		if (num > *ris) *ris = num;
		return;
	}

	for (size_t j = 0; j < bis_size; j++) {
		if (preso[j] == false) {
			if (vcurr[i] < bam[i]) {
				vcurr[i] += bis[j];
				preso[j] = true;
				rec(bam, bam_size, bis, bis_size, vcurr, preso, ris, i,false);
				vcurr[i] -= bis[j];
				preso[j] = false;
			}
			else {
				//passiamo al prossimo bambino
				rec(bam, bam_size, bis, bis_size, vcurr, preso, ris, i+1, false);
			}
		}
	}
	//ho finito i biscotti
	rec(bam, bam_size, bis, bis_size, vcurr, preso, ris, i, true);

}
int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size) {
	if (bam == NULL || bam_size == 0 || bis == NULL || bis_size == 0) return 0;
	int* vcurr = calloc(bam_size, sizeof(int));
	bool* preso = calloc(bis_size, sizeof(bool));
	int ris = 0;
	rec(bam, bam_size, bis, bis_size, vcurr, preso, &ris,0,false);
	free(vcurr);
	free(preso);
	return ris;
}


//int  main(void) {
//	int bam[] = { 10,20,30 };
//	int bis[] = { 10,50 };
//	AssegnaBiscotti(bam, sizeof(bam) / sizeof(int), bis, sizeof(bis) / sizeof(int));
//}