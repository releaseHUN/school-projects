#include <stdio.h>

int main(int argc, char const* argv[]) {
	const int input[10] = { 10, 25, 8, 7, 12, 85, 4, 16, 19, 22 };
	int legkissebbIndex = 0;

	printf("a tomb: ");
	for (int i = 0; i < 10; i++) {
		if (input[legkissebbIndex] > input[i]) {
			legkissebbIndex = i;
		}
		printf("[%d]=%d ", i, input[i]);
	}
	printf("\na legkisseb szam: %d", input[legkissebbIndex]);
	printf("\na legkissebb indexe: %d", legkissebbIndex);

	printf("\njelolve: ");
	for (int i = 0; i < 10; i++) {
		if (i == legkissebbIndex)
			printf("%d[MIN] ", input[i]);
		else
			printf("%d ", input[i]);
	}



	return 0;
}
