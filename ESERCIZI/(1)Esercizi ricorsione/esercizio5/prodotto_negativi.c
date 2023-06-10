int ProdottoNegativiRec(int a, int b) {
	
	if (b == 0) {
		return 0;
	}
	if (b <= 0) {
		b = b + 1;
		int ris = ProdottoNegativiRec(a, b) - a;
	
	}
	
	else {
		b = b - 1;
		int ris = ProdottoNegativiRec(a, b) + a;
		return ris;
	}
	}
int ProdottoNegativi(int a, int b) {
	
	if (b == 0 || a == 0) {
		return 0;
	}
	ProdottoNegativiRec(a, b);
}