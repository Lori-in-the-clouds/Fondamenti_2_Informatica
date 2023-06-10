#if !defined ROBOT_MOD_H
#define ROBOT_MOD_H
struct Grid {
	size_t rows, cols;
	int* cells;
};
extern int FindPaths(const struct Grid* g, int max_moves);
extern void PrintGrid(const struct Grid* g);
#endif //ROBOT_MOD_H