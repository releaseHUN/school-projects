#include <stdio.h>

int main(void) {
	unsigned long szamok[9] = { 0U, 1931988508U, 581177634U, 581374240U,
							581177632U, 581177634U, 1919159836U, 0U };
	for (int i = 0; i < 9; i++) {
		do {
			if (szamok[i] & 4294967296)
				printf("#");
			else
				printf(" ");
			szamok[i] <<= 1;
		} while (szamok[i] != 0);
		printf("\n");
	}
	return 0;
}