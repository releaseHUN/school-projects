#include <stdio.h>

// kiirja a tomb 0. elemet, majd az 1. elemetol stringkent irja ki a tobbit
void sztringet_kiir_1(char* szoveg) {
	if (szoveg[0] == '\0')
		return;
	putchar(szoveg[0]);
	printf("%s", szoveg + 1);
}

// rekurzivan mukodik a fuggveny, es noveli a pointer erteket minden meghivaskor
void sztringet_kiir_2(char* szoveg) {
	if (szoveg[0] == '\0')
		return;
	putchar(szoveg[0]);
	sztringet_kiir_2(szoveg + 1);
}


int main(void) {
	sztringet_kiir_1("alma");
	sztringet_kiir_2("alma");

	return 0;
}
