#include <stdio.h>

// ez a program egy szovegsort ker bemenetkent a felhasznalotol, miutan ezt a felhasznalo megadta kiirja a karakterek ascii kodjat
int main(void) {
	char betu;
	//az alabbi sornak az a 2 szerepe hogy hozzarendeli a begepelt sor karaktereit egyesevel egy valtozohoz es vegig lepked a soron karakterenkent
	while (scanf("%c", &betu) == 1)
		//a betu valtozo azert szerepel ketszer mert az elsonel magat a karaktert irja ki, a masodiknal pedig az ascii kodot
		printf("betu='%c', betu=%d\n", betu, betu);
		//kilepni a ctrl + z karakter kombinacioval lehet, ez adja meg az end of file-t
	return 0;
}
