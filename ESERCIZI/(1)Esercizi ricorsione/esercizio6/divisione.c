static int DivisioneRec(int a, int b) {
	
	if (a == 0) {
		return 0;
	} 
	if (a == 1 && b!=1) {
		return 0;
	}
		a = a - b;
		int ris = DivisioneRec(a, b) + 1;
		return ris;
}
int Divisione(int a, int b) {
	if (b == 0) {
		return -1;
	}
	if (a < 0 || b < 0) {
		return -1;
	}
	if (a < b) {
		return 0;
	}
	DivisioneRec(a, b);
}