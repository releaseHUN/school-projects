#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int tomb[10];

	for (int i = 0; i < 10; i += 1)
		tomb[i] = i * 10;

	int i = 0;

	//mikor true-ra irjuk at a while ciklus feltetelet akkor segmentation fault-ot dob a kod mivel a tombon kivuli memoriat akarunk elerni 
	while (true) {
		printf("%d. elem: %d\n", i, tomb[i]);
		i += 1;
	}

	return 0;
}
