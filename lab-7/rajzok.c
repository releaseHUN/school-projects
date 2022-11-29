#include <stdio.h>

int main(void) {
	int x = 5, y = 20, counter = 0;
	unsigned long szamok[24] = { 0U, 1931988508U, 581177634U, 581374240U,
							581177632U, 581177634U, 1919159836U, 0U };
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 32; j++) {
			if (counter == x && i == y)
				printf("#");
			else if (szamok[i] & 4294967296)
				printf("#");
			else
				printf(" ");
			szamok[i] <<= 1;
			counter++;
		};
		counter = 0;
		printf("\n");
	}
	return 0;
}