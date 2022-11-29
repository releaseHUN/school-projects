#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

char* readLine(int* lenght) {
	char* tomb = malloc(sizeof(char));
	*lenght = 0;
	while (tomb[*lenght] != EOF) {
		tomb[*lenght] = getc(stdin);
		tomb = realloc(tomb, sizeof(char) * (*lenght + 1));
		lenght++;
	}
	return tomb;
}

int main(int argc, char const* argv[]) {
	int lenght;
	char* tomb = readLine(&lenght);

	for (int i = 0; i < lenght; i++) {
		putc(tomb[i], stdout);
	}
	free(tomb);
	return 0;
}