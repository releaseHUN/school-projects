#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

// funkcio vonalak rajzolasara megadott szog (radianban) es hossz megadasaval, majd a kiszamolt vonalat beleirja a megadott file-ba
void drawLine(FILE* file, double rad, double starty, double center, int lenght, int width) {
	double point1[2], point2[2];
	point1[0] = (0 - starty * sin(rad)) + center;
	point1[1] = (0 + starty * cos(rad)) + center;
	point2[0] = (0 - (starty + lenght) * sin(rad)) + center;
	point2[1] = (0 + (starty + lenght) * cos(rad)) + center;
	fprintf(file, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" stroke-width=\"%d\" />\n", point1[0], point1[1], point2[0], point2[1], width);
}

int main(int argc, char const* argv[]) {
	FILE* file = fopen("ora.svg", "w");
	double h, m, s, starty = -180, center = 200, h_hand, m_hand, s_hand, h_hand_lenght = 80, m_hand_lenght = 120, s_hand_lenght = 150;
	int counter = 0;

	// bemenet kezelese
	printf("bemenet szokozzel elvalasztva: ");
	scanf("%lf %lf %lf", &h, &m, &s);

	// svg file elso sora es egy kor hatter rajzolasa
	fprintf(file, "<svg width=\"400\" height=\"400\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
	fprintf(file, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"white\" stroke=\"black\" />\n", center, center, -starty);

	// ora, es perc vonalak rajzolasa a szamlapra
	for (double i = 0; i < 2 * M_PI; i += M_PI / 30) {
		if (counter % 5 == 0 || counter == 0)
			drawLine(file, i, starty, center, 20, 3);
		else
			drawLine(file, i, starty, center, 10, 2);
		counter++;
	}

	// ora mutato szogenek szamolasa es rajzolasa
	h_hand = (M_PI * 2 / 12 * h) + (M_PI * 2 / 720 * m);
	drawLine(file, h_hand, -h_hand_lenght, center, 75, 5);

	// perc mutato szogenek szamolasa es rajzolasa
	m_hand = (M_PI * 2 / 60 * m) + (M_PI * 2 / 3600 * s);
	drawLine(file, m_hand, -m_hand_lenght, center, 115, 3);

	// masodperc mutato szogenek szamolasa es rajzolasa
	s_hand = (M_PI * 2 / 60 * s);
	drawLine(file, s_hand, -s_hand_lenght, center, 145, 1);

	// svg file bezarasa
	fprintf(file, "<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" fill=\"black\" stroke=\"black\" />\n", center, center);
	fprintf(file, "</svg>");

	fclose(file);
	return 0;
}
