#include <stdio.h>
#include <math.h>

void feloszt(int input) {
	int lenght = ceil(log10(input));
	for (int i = lenght; i >= 3; i -= 3) {
		int temp = pow(10, i);
		int out = input % temp;
		temp = pow(10, i - 3);
		out = out / temp;
		printf(" %d", out);
	}
}

int main(int argc, char const* argv[]) {
	feloszt(123456789);
	return 0;
}
