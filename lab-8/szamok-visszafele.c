#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[]) {
	int lenght;
	printf("mennyi szamot olvassak be?\n");
	scanf("%d", &lenght);
	double* tomb = malloc(sizeof(double) * lenght);
	for (int i = 0; i < lenght; i++) {
		scanf("%lf", &tomb[i]);
	}

	for (int i = lenght - 1; i >= 0; i--) {
		printf("%lf\n", tomb[i]);
	}
	free(tomb);
	return 0;
}
