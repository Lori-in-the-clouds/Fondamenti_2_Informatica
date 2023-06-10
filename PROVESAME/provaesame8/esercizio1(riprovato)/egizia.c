#include <stdio.h>
#include <math.h>
void rec(int n, int d) {
	int d1 = (int)ceil((double)d / (double)n);
	if (d % n == 0) {
		printf("1/%d", d1);
		return;
	} else printf("1/%d + ", d1);
	rec((n * d1) - d, d1 * d);
}
void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
		return;
	}
	rec(n, d);
	return;
}
