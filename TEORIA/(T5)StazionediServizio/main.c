extern void stazioniconv(int* prezzolitro, int* distanza,int n);
int main(void) {
	int prezzolitro[] = { 35,35,33,29,23 };
	int distanza[] = { 260,284,308,332,356 };
	int n = 5;
	stazioniconv(&prezzolitro, &distanza,n);
}