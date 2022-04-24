#pragma once

#define TRUE 1
#define FALSE 0

typedef struct {
	int isReversed;
	int isNumIgnrd;
	char space;
	char ignrdChars[40];
}options;

void setIsReversed(options* optn, int boolean);
void setIsNumIgnrd(options* optn, int boolean);
void setSpace(options* optn, char space);
void setIgnrdChars(options* optn, char* str);
char* decode(char* str, options* optn);

