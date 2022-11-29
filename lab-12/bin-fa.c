#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "debugmalloc.h"

typedef struct BiFa {
	int ertek;
	struct BiFa* bal, * jobb;
} BiFa;

BiFa* beszur(BiFa* gyoker, int ertek) {
	if (gyoker == NULL) {
		BiFa* uj = (BiFa*)malloc(sizeof(BiFa));
		uj->ertek = ertek;
		uj->bal = uj->jobb = NULL;
		return uj;
	}
	if (ertek < gyoker->ertek) {        /* balra szur */
		gyoker->bal = beszur(gyoker->bal, ertek);
	} else if (ertek > gyoker->ertek) {   /* jobbra szur */
		gyoker->jobb = beszur(gyoker->jobb, ertek);
	} else {
		/* mar benne van */
	}
	return gyoker;
}

void writeOut(BiFa* gyoker) {
	if (gyoker == NULL)
		return;

	writeOut(gyoker->bal);
	printf("%d ", gyoker->ertek);
	writeOut(gyoker->jobb);
}

void felszabadit(BiFa* gyoker) {
	if (gyoker == NULL)
		return;

	felszabadit(gyoker->bal);
	felszabadit(gyoker->jobb);
	free(gyoker);
}

int countElements(BiFa* gyoker) {
	if (gyoker == NULL) return 0;

	return countElements(gyoker->bal)
		+ countElements(gyoker->jobb)
		+ 1;
}

int addElements(BiFa* gyoker) {
	if (gyoker == NULL)
		return 0;

	return addElements(gyoker->bal) + gyoker->ertek + addElements(gyoker->jobb);
}

BiFa* search(BiFa* gyoker, int ertek) {
	BiFa* walker = gyoker;
	while (walker != NULL && walker->ertek != ertek) {
		if (abs(ertek) < abs(walker->ertek))
			walker = walker->bal;
		else
			walker = walker->jobb;
	}
	return walker;
}

void negate(BiFa* gyoker) {
	if (gyoker == NULL)
		return;

	negate(gyoker->bal);
	gyoker->ertek = gyoker->ertek * -1;
	negate(gyoker->jobb);
}

void tukroz(BiFa* gyoker) {
	if (gyoker == NULL)
		return;

	tukroz(gyoker->bal);
	tukroz(gyoker->jobb);
	BiFa* temp = gyoker->bal;
	gyoker->bal = gyoker->jobb;
	gyoker->jobb = temp;
}


int main(void) {
	int minta[] = { 15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0 };
	BiFa* gyoker = NULL;
	for (int i = 0; minta[i] > 0; i++)
		gyoker = beszur(gyoker, minta[i]);

	/* Ide tedd be a kipróbálandó függvények hívásait! */
	writeOut(gyoker);
	int count = countElements(gyoker);
	printf("\n%d", count);
	int value = addElements(gyoker);
	printf("\n%d", value);
	BiFa* searched = search(gyoker, 9);
	printf("\n%d\n", searched->ertek);
	negate(gyoker);
	writeOut(gyoker);
	searched = search(gyoker, -9);
	printf("\n%d\n", searched->ertek);
	tukroz(gyoker);
	writeOut(gyoker);
	felszabadit(gyoker);

	return 0;
}
