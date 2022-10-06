#include <stdio.h>

int len(const char* s) {
	int count = 0;
	while (*s != '\0') {
		count++;
		s++;
	}
	return count;
}

int main(int argc, char const* argv[]) {
	char code[] = "++++[++++>---<]>+.[--->+<]>+++.--.----.+++++.-----.++.";
	char tape[32768] = { 0 };
	int pointer = 0, loopCount = 0;

	if (code[0] == ']') {
		printf("szintaktikai hiba!");1
		return 1;
	}

	for (int i = 0; i < len(code); i++) {
		switch (code[i]) {
		case '>':
			if (pointer < 32768)
				pointer++;
			else {
				printf("szallagon kivulre mutatas!");
				return 1;
			}
			break;

		case '<':
			if (pointer > 0)
				pointer--;
			else {
				printf("szallagon kivulre mutatas!");
				return 1;
			}
			break;

		case '+':
			tape[pointer]++;
			break;

		case '-':
			tape[pointer]--;
			break;

		case '.':
			printf("%c", tape[pointer]);
			break;

		case ',':
			scanf("%c", &tape[pointer]);
			break;

		case '[':
			if ((int)tape[pointer] == 0) {
				loopCount++;
				while (code[i] != ']' || loopCount != 0) {
					i++;

					if (code[i] == '[') {
						loopCount++;
					} else if (code[i] == ']') {
						loopCount--;
					}
				}
			}
			break;

		case ']':
			if ((int)tape[pointer] != 0) {
				loopCount++;
				while (code[i] != '[' || loopCount != 0) {
					i--;

					if (code[i] == ']') {
						loopCount++;
					} else if (code[i] == '[') {
						loopCount--;
					}
				}
			}
			break;

		default:
			continue;
		}
	}

	return 0;
}
