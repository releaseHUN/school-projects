#include <stdio.h>
#include <ctype.h>

void madarasitas() {
	char c;
	while (scanf("%c", &c) != EOF) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			printf("%cv%c", c, c);
		else if (c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'U')
			printf("%cv%c", c, tolower(c));
		else
			printf("%c", c);
	}
}

int main(void) {
	madarasitas();

	return 0;
}

