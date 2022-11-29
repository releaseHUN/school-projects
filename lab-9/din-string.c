#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// beker egy stringet, majd visszater egy dinamikusan lefoglalt string pointerevel amibe a bemeneti sztring be lett masolva
char* masolat(char* input) {
	int len = strlen(input);
	char* out = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		out[i] = input[i];
	return out;
}

// beker 2 stringet, az elsonek dinamikusan foglaltnak kell lennie, es az elso stringhez hozza fuzi a masodikat
void hozzafuz(char* in1, char* in2) {
	int len1 = strlen(in1);
	int len2 = strlen(in2);
	in1 = realloc(in1, sizeof(char) * (len1 + len2 + 1));
	for (int i = len1; i < len1 + len2; i++)
		in1[i] = in2[i - len1];
}

// beker egy stringet es 2 intet, a 2 int a kivagas elejet es veget jelzi,
// majd a megadott range - ben kivag a stringbol egy darabot es egy dinamikusan lefoglalt stringbe rakja, amit returnol
char* kivag(char* in, int start, int end) {
	int len = strlen(in);
	if (start < 0)
		start = 0;
	if (end > len)
		end = len;

	int outlen = end - start;
	char* out = malloc(sizeof(char) * (outlen + 1));
	for (int i = start; i < end; i++)
		out[i - start] = in[i];
	return out;
}

char* elhagy(char* in, int start, int end) {
	int len = strlen(in);
	char* out = malloc(sizeof(char) * (1 + len - (end - start)));
	for (int i = 0; i < start; i++)
		out[i] = in[i];

	for (int i = end; i < len; i++)
		out[i - end + start] = in[i];

	return out;
}

// beker 2 stringet es egy intet, a 2. stringet berakja az elso sztringben arra a helyre amit az int ad meg, majd ezt returnolja egy dinamikusan foglalt stringbe
char* beszur(char* in1, int place, char* in2) {
	int len1 = strlen(in1);
	int len2 = strlen(in2);
	char* out = malloc(sizeof(char) * (len1 + len2 + 1));
	for (int i = 0; i < len1 + len2; i++) {
		if (i > place && i <= place + len2)
			out[i] = in2[i - place - 1];
		else if (i > place + len2)
			out[i] = in1[i - place];
		else
			out[i] = in1[i];
	}
	return out;
}

int main(void) {
	char strin[] = "alma";
	char* lemasolt = masolat(strin);
	printf("%s\n", lemasolt);

	char strin2[] = "hello";
	hozzafuz(lemasolt, strin2);
	printf("%s\n", lemasolt);
	free(lemasolt);

	char strin3[] = "hello world";
	char* kivagott = kivag(strin3, 1, 7);
	printf("%s\n", kivagott);
	free(kivagott);

	char* elhagyott = elhagy(strin3, 4, 8);
	printf("%s\n", elhagyott);
	free(elhagyott);

	char* beszurt = beszur(strin3, 4, " alma");
	printf("%s\n", beszurt);
	free(beszurt);
	return 0;
}
