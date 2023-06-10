#include <string.h>
extern int atoi(const char* str);
int main(void) {
	const char str[] = { "42" };
	atoi("42");
	atoi("+42");
	atoi("-42");
	atoi("4-2");
	atoi("042");
	atoi("a42");
	atoi("42a");
	atoi(" 42");
	atoi("+ 42");




}