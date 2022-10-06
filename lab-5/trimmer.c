#include <stdio.h>
#include <string.h>

void trim(char input[], char output[]) {
	int lenght = strlen(input);
	int i = 0;
	int spacesLeft = 0, spacesRight = 0;
	while (input[i] == ' ') {
		spacesLeft++;
		i++;
	}
	i = 0;
	while (input[lenght - i] == ' ') {
		spacesRight++;
		i++;
	}

	for (int j = 0; j < lenght - spacesLeft - spacesRight; j++) {
		output[j] = input[j + spacesLeft];
	}
}

int main(int argc, char const* argv[]) {
	char input[32], output[32];
	scanf("%s", input);
	trim(input, output);
	printf("%s", output);

	return 0;
}
