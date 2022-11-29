#include <stdio.h>

int main(int argc, char const* argv[]) {
	int szam = 29;
	do {
		if (szam & 1)
			printf("1");
		else
			printf("0");
		szam >>= 1;

	} while (szam != 0);
	return 0;
}
