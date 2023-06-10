int ProdottoRec(int a, int b) {
	if (b == 1) {
		return a;
	}
	b = b - 1;
	int ris = ProdottoRec(a, b)+a;
	
}
int Prodotto(int a, int b) {
	if (a < 0 || b < 0) {
		return -1;
	}
	if (b == 0 || a == 0) {
		return 0;
	}
	ProdottoRec(a, b);
}