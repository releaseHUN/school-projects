#include <stdio.h>

int fib(int n, int* counter, int* a, int* b) {
	int temp = *b;
	*b = *a + *b;
	*a = temp;
	*counter += 1;
	if (*counter < n)
		fib(n, counter, a, b);
}

int main(int argc, char const* argv[]) {
	int n = 40;
	int a = 0, b = 1, counter = 0;
	fib(n, &counter, &a, &b);
	printf("%d\n", b);
	return 0;
}
