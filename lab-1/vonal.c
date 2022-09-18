#include <stdio.h>

int main() {
	int lenght;
	printf("milyen hosszu legyen?");
	scanf("%d", &lenght);
	printf("+");
	for (int i = 0; i < lenght; i++) {
		printf("-");
	}
	printf("+");
	return 0;
}