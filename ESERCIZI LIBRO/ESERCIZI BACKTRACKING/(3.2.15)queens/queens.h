#if !defined QUEENS_H
#define QUEENS_H
struct Matrix {
	int lato;
	int* data;
};
extern int PlaceQueens(int chessboard_size, int n_queens);
#endif //QUEENS_H