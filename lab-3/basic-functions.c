#include <stdio.h>
#include <math.h>

double kob(double input) {
	return input * input * input;
}

double absolut(double input) {
	if (input < 0)
		return input * -1;
	else
		return input;
}

int main(int argc, char const* argv[]) {
	for (double i = -1; i <= 1; i += 0.1) {
		printf("%.4g ", i);
	}
	printf("\n\n");
	for (double i = -1; i <= 1; i += 0.1) {
		printf("%.4g ", kob(i));
	}
	printf("\n\n");
	for (double i = -1; i <= 1; i += 0.1) {
		printf("%.4g ", absolut(i));
	}
	printf("\n\n");
	for (double i = -1; i <= 1; i += 0.1) {
		printf("%.4g ", sin(i));
	}
	return 0;
}
