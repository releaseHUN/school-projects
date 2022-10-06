#include <stdio.h>

void szamit(double oldal, double* felulet, double* terfogat) {
	*felulet = oldal * oldal * 6;
	*terfogat = oldal * oldal * oldal;
}

int main(int argc, char const* argv[]) {
	double felulet, terfogat;
	szamit(2.7, &felulet, &terfogat);
	printf("%lf %lf", felulet, terfogat);
	return 0;
}
