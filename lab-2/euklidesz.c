#include <stdio.h>

int main() {
	int a = 11220;
	int b = 2002;
	//a b valtozo erteke 44 mikor az a 374-re valt
	while (b > 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	printf("lnko = %d\n", a);
	return 0;
}
