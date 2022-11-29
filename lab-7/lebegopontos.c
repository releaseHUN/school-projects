#include <stdio.h>
#include <math.h>

int main(void) {
	// teljes alakban kiirja a normalalakos szamot
	printf("1. %f\n", 1e40);
	// kiirja a normalalakos szamot mert az a legrovidebb
	printf("2. %g\n", 1e40);
	// osszehasonlitja a 2 szam erteket es igaz, hamisat ad vissza szovegben
	printf("3. %s\n", 1e3 + 1 == 1e3 ? "igaz" : "hamis");

	printf("4. %s\n", 1e30 + 1 == 1e30 ? "igaz" : "hamis");
	// normalalakban kiirja a kiszamolt szamot
	printf("5. %g\n", pow(10, 40) / pow(10, -40));
	// vegtelent ad vissza
	printf("6. %g\n", powf(10, 40) / powf(10, -40));

	return 0;
}
