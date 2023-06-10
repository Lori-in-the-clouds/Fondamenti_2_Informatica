#include "alpine_road.h"
#include <stdlib.h>
int main(void) {
	Point* c = malloc(5 * sizeof(Point));
	c[0].s = 0;
	c[1].s = 40;
	c[2].s = 60;
	c[3].s = 110;
	c[4].s = 170;
	
	c[0].h = 10;
	c[1].h = 19;
	c[2].h = 19;
	c[3].h = 25;
	c[4].h = 17;
	FindPath(c,5,10);
	return 0;
}