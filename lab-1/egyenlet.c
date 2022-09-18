#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	double a, b, c, output1, output2;
	printf("az A valtozo erteke:");
	scanf("%lf", &a);
	printf("a B valtozo erteke:");
	scanf("%lf", &b);
	printf("a C valtozo erteke:");
	scanf("%lf", &c);

	output1 = (-b + sqrt(pow(b, 2) - 4.0 * a * c)) / (2 * a);
	output2 = (-b - sqrt(pow(b, 2) - 4.0 * a * c)) / (2 * a);

	printf("x1 = %.6lf\nx2 = %.6lf", output1, output2);

	return 0;
}