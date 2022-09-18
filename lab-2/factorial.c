#include <stdio.h>

int main(int argc, char const* argv[]) {
	int output = 1;
	const int number = 8;

	for (int i = 1; i <= number; i++) {
		output = i * output;
		// printf("%d a %d faktorialisa\n", output, i);
	}

	printf("%d a %d faktorialisa\n", output, number);

	return 0;
}
