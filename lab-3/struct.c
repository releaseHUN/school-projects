#include <stdio.h>

typedef struct Datum {
	int ev, ho, nap;
} Datum;

typedef struct Versenyzo {
	char nev[31];
	Datum szuletes;
	int helyezes;
} Versenyzo;

void datum_kiir(Datum d);

void versenyzo_kiir(Versenyzo v);

int main() {
	Versenyzo versenyzok[5] = {
		{ "Am Erika", {1984, 5, 6}, 1 },
		{ "Break Elek", {1982, 9, 30}, 3 },
		{ "Dil Emma", {1988, 8, 25}, 2 },
		{ "Kasza Blanka", {1979, 6, 10}, 5 },
		{ "Reset Elek", {1992, 4, 5}, 4 },
	};

	/* 0-s versenyző neve - printf %s */
	printf("%s\n", versenyzok[0].nev);
	/* 2-es versenyző helyezése */
	printf("%d\n", versenyzok[2].helyezes);
	/* 4-es versenyző születési dátumát (írd meg a datum_kiir függvényt!) */
	datum_kiir(versenyzok[4].szuletes);
	/* 1-es versenyző nevének kezdőbetűjét (ne feledd, a sztring karaktertömb) */
	printf("%c\n", versenyzok[1].nev[0]);
	/* az 1-es versenyző dobogós-e? igen/nem, akár ?: operátorral, de egy printf-fel */
	versenyzok[1].helyezes >= 3 ? printf("igen\n") : printf("nem\n");
	/* az 4-es versenyző gyorsabb-e, mint a 3-as versenyző? */
	versenyzok[4].helyezes > versenyzok[3].helyezes ? printf("igen\n") : printf("nem\n");
	/* az 1-es versenyző ugyanabban az évben született-e, mint a 2-es? */
	/* egészítsd ki a versenyzo_kiir() függvényt,
	 * aztán írd ki az 1-es versenyző összes adatát */
	versenyzo_kiir(versenyzok[1]);
	/* végül listázd ki az összes versenyzőt sorszámozva, összes adatukkal. */
	for (int i = 0; i < 5; i++) {
		versenyzo_kiir(versenyzok[i]);
	}


	return 0;
}

void datum_kiir(Datum d) {
	/* dátum kiírása */
	printf("%d.", d.ev);
	printf("%d.", d.ho);
	printf("%d\n", d.nap);
}

void versenyzo_kiir(Versenyzo v) {
	/* a versenyző összes adatának kiírása */
	printf("%s %d.%d.%d %d\n", v.nev, v.szuletes.ev, v.szuletes.ho, v.szuletes.nap, v.helyezes);
}
