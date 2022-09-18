#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const* argv[]) {
	char pit[10] = "Pitagorasz";
	char temp;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c ", pit[j]);
		}
		printf("\n");

		temp = pit[9];
		for (int j = 9; j > 0; j--) {
			pit[j] = pit[j - 1];
		}
		pit[0] = temp;
	}


	return 0;
}
