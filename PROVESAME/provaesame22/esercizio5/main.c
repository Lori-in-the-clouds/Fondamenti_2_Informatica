#include <stdlib.h>
extern void BrickSort(int* v, size_t v_size); 
int main(void)
{
	int v[] = { 3,6,2,4,-8 };
	BrickSort(v, 5);

}