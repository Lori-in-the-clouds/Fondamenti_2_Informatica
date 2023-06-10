static int FibonacciRec(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	
	int sum = FibonacciRec(n - 1) +FibonacciRec(n-2);
	return sum;
} 
int Fibonacci(int n) {
	if (n < 0) {
		return -1;
	}
	FibonacciRec(n);
}