#include <stdio.h>

int counter = 0;

void itElore(char input[], int lenght) {
	for (int i = 0; i < lenght; i++)
		putchar(input[i]);
}

void itHatra(char input[], int lenght) {
	for (int i = lenght; i > 0; i--)
		putchar(input[i]);
}

void recElore(char* input, int lenght) {
	putchar(input[0]);
	counter++;
	if (counter <= lenght)
		recElore(input + 1, lenght);
}

void recHatra(char* input, int lenght) {
	putchar(input[0]);
	counter++;
	if (counter <= lenght)
		recHatra(input - 1, lenght);
}

int main(int argc, char const* argv[]) {
	char tomb1[] = "almaspite0";
	char tomb2[] = "alma0";
	itElore(tomb1, 10);
	itHatra(tomb1, 10);
	recElore(tomb1, 10);
	counter = 0;
	recHatra(&tomb1[10], 10);
	return 0;
}
