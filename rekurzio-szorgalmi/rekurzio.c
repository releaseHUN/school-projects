#include <stdio.h>
#include <stdlib.h>

char* readLineHelper(int i) {
	char ch = getc(stdin);
	char* str;
	if (ch == EOF || ch == '\n') {
		str = malloc(i + 1);
		str[i] = 0;
	} else {
		str = readLineHelper(i + 1);
		str[i] = ch;
	}
	return str;
}

char* sort_beolvas(void) {
	return readLineHelper(0);
}

int main(int argc, char const* argv[]) {
	char* input = sort_beolvas();
	printf("%s", input);
	free(input);
	return 0;
}
