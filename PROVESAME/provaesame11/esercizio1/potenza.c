void PotenzaRec(int a, int b, int* ris, int i) {
	if (i == b) {
		return;
	}
	ris[0] = ris[0] * a;
	PotenzaRec(a, b, ris, i + 1);
}
int Potenza(int a, int b) {
	int ris = 1;
	PotenzaRec(a, b, &ris, 0);
	return ris;
}