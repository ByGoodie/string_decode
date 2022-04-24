#include "stringDecode.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	char* str = "*@^&#^)@_H&^@&E)*(@*(@L(@&*(&@L@(&*#O";
	options myOptn = { 1,0,' ',"" };
	char* strD = decode(str, &myOptn);
	printf("%s", strD);
	free(strD);
}