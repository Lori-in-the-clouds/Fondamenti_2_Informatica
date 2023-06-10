#include <stdio.h>
#include <math.h>
void FrazioneEgiziaRec(int n, int d,int i) {
	int d1 = ceil((double)d / (double)n);
	if (i == 0) printf("1/%d ", d1);
	else printf("+ 1/%d ", d1);
	if (d % n == 0) return;
	FrazioneEgiziaRec((n * (d1)) - 1 * (d), d1 * d,i+1);
}
void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
		return;
	}
	FrazioneEgiziaRec(n, d,0);
}