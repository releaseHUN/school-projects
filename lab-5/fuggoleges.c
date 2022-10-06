#include <stdio.h>
#include <string.h>

int main(int argc, char const* argv[]) {
	char input[32];
	scanf("%s", input);
	int lenght = strlen(input);
	for (int i = 0; i < lenght; i++) {
		printf("%c\n", input[i]);
	}

	return 0;
}
