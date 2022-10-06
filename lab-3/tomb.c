#include <stdio.h>

int main(void) {
	double szamok[10] = { 2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8 };
	int negative[10];
	int negativesCount = 0;

	/* Az eredeti tömb kiírása */
	printf("Összesen %d szám van.\n", 10);
	for (int i = 0; i < 10; ++i)
		printf("[%d]=%g ", i, szamok[i]);
	printf("\n\n");

	/* Negatívak indexeinek kigyűjtése */
	for (int i = 0; i < 10; i++) {
		if (szamok[i] < 0) {
			negative[negativesCount] = i;
			negativesCount++;
		}
	}

	/* Negatívak kiírása */
	printf("%d negativ szamot talaltam\n", negativesCount);
	for (int i = 0; i < negativesCount; i++) {
		printf("[%d]=%g ", i, szamok[negative[i]]);
	}


	return 0;
}
