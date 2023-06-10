#if !defined SUDOKU_H
#define SUDOKU_H
#include <stdlib.h>
static int sizeMatrix = 81;
typedef struct {
	size_t size;
	int* data;
} Matrix;

void ResolveSudoku(Matrix* p);
void PrintSudoku(Matrix* p);
#endif //SUDOKU_H