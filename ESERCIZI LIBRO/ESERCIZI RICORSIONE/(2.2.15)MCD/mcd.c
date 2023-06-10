int MCDRec(int m, int n) {
	if (n == 0) {
		return m;
	}
	MCDRec(n, m % n);
 }
int MCD(int m, int n) {
	if (m <= n) {
		int tmp = m;
		m = n;
		n = tmp;
	}
	return MCDRec(m, n);
}