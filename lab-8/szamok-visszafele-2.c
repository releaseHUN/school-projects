#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

int main(int argc, char const* argv[]) {
	double* tomb = malloc(sizeof(double));
	int lenght = 0;
	while (scanf("%lf", &tomb[lenght])) {
		if (tomb[lenght] != -1) {
			tomb = realloc(tomb, sizeof(double) * (lenght + 1));
			lenght++;
		} else {
			tomb = realloc(tomb, sizeof(double) * (lenght - 1));
			break;
		}
	}

	for (int i = lenght; i >= 0; i--) {
		printf("%lf\n", tomb[i]);
	}
	free(tomb);
	return 0;
}