#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	double height = 0.0, radius = 0.0, festek = 0.0;

	printf("tartaly festese\n\n");
	printf("milyen magas? ");
	scanf("%lf", &height);

	printf("mennyi az atmeroje? ");

	scanf("%lf", &radius);

	festek = ((height * (radius * (M_PI * 2))) + radius * pow(M_PI, 2)) / 2;

	printf("%.6lf doboz festek kell", festek);

	return 0;
}