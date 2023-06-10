BinomialeRec(unsigned int n, unsigned int k) {
	if (k == 0 || k == n) {
		return 1;
	}
	return BinomialeRec(n - 1, k - 1) + BinomialeRec(n - 1, k);
}
double Binomiale(unsigned int n, unsigned int k) {
	if (n == 0 || k > n) {
		return -1;
	}
	return BinomialeRec(n, k);
}