#include <stdio.h>

int* search(int* input, int lenght, int number) {
	int* index;
	for (int i = 0; i < lenght; i++) {
		if (*(input + i) == number) {
			index = input + i;
		}
	}
	return index;
}

int main(int argc, char const* argv[]) {
	int tomb[10] = { 1, 21, 12, 34, 56, 43, 42, 15, 64, 10 };
	int* tombhely = tomb;
	int* talalt = search(tombhely, 10, 43);

	if (talalt == NULL)
		printf("nincs ilyen szam a tombben");
	else
		printf("a megadott szam %p indexen talalhato", talalt);
	return 0;
}