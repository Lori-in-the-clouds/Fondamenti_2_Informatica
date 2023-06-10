#include <stdio.h>
void FrazioneEgiziaRec(int n, int d,int s) {
	if (d % n == 0) {
		printf("+ 1/%d", d / n);
		return;
	}
	int frat = (d / n) + 1;
	if (s == 0) {
		printf("1/%d ", frat);
		s++;
	} else{
		printf("+ 1/%d", frat);

	}
	FrazioneEgiziaRec((n*frat)-(d*1), d * frat, s);
}
void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0) {
		printf("%s", "Impossibile convertire la frazione.");
	}
	FrazioneEgiziaRec(n, d, 0);
	return;
}
