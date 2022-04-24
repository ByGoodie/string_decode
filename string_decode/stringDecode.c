#include "stringDecode.h"
#include <stdlib.h>

static int strlenSD(char* str);
static int strchrSD(char* str, char ch);

static int strchrSD(char* str, char ch) {
	int len = strlenSD(str), i = 0;
	for (i = 0; i < len; i++) {
		if (str[i] == ch){
			return 1;
		}
	}
	return 0;
}

static int strlenSD(char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

void setIsReversed(options* optn,int boolean) {
	optn->isReversed=boolean;
}

void setIsNumIgnrd(options* optn,int boolean) {
	optn->isNumIgnrd = boolean;
}

void setSpace(options* optn, char space) {
	optn->space = space;
}

void setIgnrdChars(options* optn, char* str) {
	int len = strlenSD(str), i = 0;
	for (i = 0; i < len; i++) {
		optn->ignrdChars[i] = str[i];
	}
}

char* decode(char* str, options* optn) {
	if (optn->isReversed) {
		int len = strlenSD(str), i = 0, j = 0;
		char* strD = malloc(sizeof(char) * len);
		if (strD == NULL) {
			return NULL;
		}
		for (i = 0; i < len; i++) {
			if (str[len - 1 - i] == optn->space || ((str[len - 1 - i] >= 65 && str[len - 1 - i] <= 90) || (str[len - 1 - i] >= 97 && str[len - 1 - i] <= 122)) || (str[len - 1 - i] >= 48 && str[len - 1 - i] <= 57 && optn->isNumIgnrd) || strchrSD(optn->ignrdChars, str[len - 1 - i])) {
				strD[j] = str[len - 1 - i];
				j++;
			}
		}
		strD[j] = '\0';
		return strD;
	}
	else {
		int len = strlenSD(str), i = 0, j = 0;
		char* strD = malloc(sizeof(char) * len);
		if (strD == NULL) {
			return NULL;
		}
		for (i = 0; i < len; i++) {
			if (str[i] == optn->space || ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) || (str[i] >= 48 && str[i] <= 57 && optn->isNumIgnrd) || strchrSD(optn->ignrdChars, str[i])) {
				strD[j] = str[i];
				j++;
			}
		}
		strD[j] = '\0';
		return strD;
	}
}