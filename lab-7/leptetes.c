#include <stdio.h>

int main(int argc, char const* argv[]) {
	int counter = 0;
	int harminc2 = 1;
	unsigned char Char = 1;
	unsigned int unsignedInt = 1;
	unsigned short int unsignedShort = 1;
	unsigned long int unsignedLong = 1;
	unsigned long long int unsignedLongLong = 1;
	for (int i = 1; i < 32; i++) {
		harminc2 <<= 1;
	}
	printf("%d\n", harminc2);

	while (unsignedInt != 0) {
		unsignedInt <<= 1;
		counter++;
	}
	printf("%d, %d\n", unsignedInt, counter);
	counter = 0;

	while (unsignedShort != 0) {
		unsignedShort <<= 1;
		counter++;
	}
	printf("%d, %d\n", unsignedInt, counter);
	counter = 0;

	while (unsignedLong != 0) {
		unsignedLong <<= 1;
		counter++;
	}
	printf("%ld, %d\n", unsignedLong, counter);
	counter = 0;

	while (unsignedLongLong != 0) {
		unsignedLongLong <<= 1;
		counter++;
	}
	printf("%lld, %d\n", unsignedLongLong, counter);

	return 0;
}
