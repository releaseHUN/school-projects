#include <stdio.h>


// hasonloan mukodik mint az elozo, csak ez fentrol lefele szamol
int main() {
	int szorzat = 1;
	int n = 8;
	// a szorzat erteke 6720 az n = 3-nal
	while (n > 1) {
		szorzat *= n;
		n -= 1;
	}
	printf("%d\n", szorzat);
	return 0;
}
