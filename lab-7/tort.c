#include <stdio.h>

int main(int argc, char const* argv[]) {
	double temp = (double)(4 + 2 - (3 - (6 + (4.0 / 5)))) / (3 * (2 - 7));
	printf("%lf\n", temp);
	return 0;
}

