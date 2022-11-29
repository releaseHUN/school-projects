#include <stdio.h>


// intre -2147483648 erteket ad vissza
// short intre -32768 erteket ad
// signed char-ra pedig -128-at
// ez azert van mert az elso bit az a sign bit ami ha aktiv akkor negativra valtoztatja a szamot
int main(void) {
	int i = 1;
	while (i > 0) {
		++i;
	}
	printf("%d\n", i);

	return 0;
}
