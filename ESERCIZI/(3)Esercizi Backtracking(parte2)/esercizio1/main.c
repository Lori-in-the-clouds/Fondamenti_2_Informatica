#include <stdio.h>

#include "torrecartoni.h"

int main(void) {
	{
		Cartone c[] = { {.p = 10,.a = 10,.l = 8 },{.p = 10,.a = 20,.l = 40 },  {.p = 9,.a = 3,.l = 5 } };
		TorreCartoni(c, sizeof(c) / sizeof(Cartone));
		puts("");
	}
	{
		Cartone c[] = { {.p = 25,.a = 20,.l = 40 }, {.p = 10,.a = 10,.l = 12 }, {.p = 9,.a = 3,.l = 5 } };
		TorreCartoni(c, sizeof(c) / sizeof(Cartone));
		puts("");
	}
	{
		Cartone c[] = {
						{.p = 25,.a = 20,.l = 50 }, {.p = 10,.a = 10,.l = 8 }, {.p = 9,.a = 3,.l = 5 }, 
						{.p = 5,.a = 20,.l = 200 }, {.p = 10,.a = 10,.l = 202 }, {.p = 24,.a = 3,.l = 55 } 
					  };
		TorreCartoni(c, sizeof(c) / sizeof(Cartone));
		puts("");
	}
	
    return 0;
}

