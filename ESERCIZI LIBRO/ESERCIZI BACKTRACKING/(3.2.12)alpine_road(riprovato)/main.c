#include <stdlib.h>
#include "alpine_road.h"
int main(void) {
	Point p[] = { {.s = 0,.h = 10},{.s = 40,.h = 19},{.s = 60,.h = 19},{.s = 110,.h = 25},{.s = 170,.h = 17} };
	FindPath(p, 5, 0);
}