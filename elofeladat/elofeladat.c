#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct data {
	int roomNumber;
	char name[50];
	struct data* next;
} data;

int main() {
	data* root = malloc(sizeof(data));
	data* searchroot = malloc(sizeof(data));
	char filename[128] = "input.txt", name[50], searchFilename[128], searchName[50];
	int szintLakok[8];

	readFile(filename, &root);
	writeout(root->next);
	for (int i = 0; i <= 7; i++) {
		szintLakok[i] = zsufolt(root->next, i);
	}

	printf("a(z) %d. szint a legzsufoltabb\n", legzsufoltabbSzintKeres(szintLakok));

	printf("adjon meg egy nevet: ");
	scanf("%s", name);
	int roomnuber = emberKeres(root->next, name);
	if (roomnuber > 0)
		printf("\na megadott (%s) nevu ember a(z) %d szobaban lakik\n", name, roomnuber);
	else
		printf("\na megadott (%s) nevu ember a(z) %d szobaban lakik\n", name, -roomnuber);


	printf("milyen file-ban keressek? ");
	scanf("%s", searchFilename);
	printf("\nmilyen nevet keressek? ");
	scanf("%s", searchName);

	searchInFile(searchFilename, searchName, &searchroot, &searchroot);

	return 0;
}


void readFile(char filename[128], data** first) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("rossz file nev!");
		exit(1);
	}
	char number[3];
	char line[54];

	while (fgets(line, sizeof(line), fp) != NULL) {
		data* new_node = malloc(sizeof(data));
		if (new_node == NULL)
			exit(1);
		new_node->next = NULL;
		strncpy(number, line, 3);
		if (number[0] != '0')
			new_node->roomNumber = atoi(number);
		else
			new_node->roomNumber = -atoi(number);
		strcpy(new_node->name, &line[4]);

		data* curr = *first;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_node;
	}
	fclose(fp);
}

void writeout(data* input) {
	data* curr = input;
	while (curr != NULL) {
		printf("szoba: %d | nev: %s\n", curr->roomNumber, curr->name);
		curr = curr->next;
	}
}

int zsufolt(data* input, int floor) {
	int floorCount = 0;
	data* curr = input;
	while (curr != NULL) {
		int firstDigit = curr->roomNumber / 100;
		if (floor == 0 && curr->roomNumber < 0)
			floorCount++;
		else if (firstDigit == floor)
			floorCount++;
		curr = curr->next;
	}
	return floorCount;
}

int legzsufoltabbSzintKeres(int input[8]) {
	int mostPeople = 0;
	for (int i = 0; i <= 7; i++) {
		if (mostPeople < input[i])
			mostPeople = input[i];
	}
	return mostPeople;
}

int emberKeres(data* list, char input[50]) {
	data* curr = list;
	while (curr != NULL) {
		if (curr->name == input) {
			int output = curr->roomNumber;
			return output;
		}
		curr = curr->next;
	}
}

void searchInFile(char filename[128], char name[50], data** first, data* node) {
	FILE* fp = fopen(filename, "r");
	bool exists = false;
	int floor;
	if (fp == NULL) {
		perror("rossz file nev!");
		exit(1);
	}
	char number[3];
	char line[54];

	while (fgets(line, sizeof(line), fp) != NULL) {
		data* new_node = malloc(sizeof(data));
		if (new_node == NULL)
			exit(1);
		new_node->next = NULL;
		strncpy(number, line, 3);
		if (number[0] != '0')
			new_node->roomNumber = atoi(number);
		else
			new_node->roomNumber = -atoi(number);
		strcpy(new_node->name, &line[4]);

		if (new_node->name == name) {
			exists = true;
			if (new_node->roomNumber < 100)
				floor = -new_node->roomNumber;
			else
				floor = new_node->roomNumber;
		}

		data* curr = *first;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_node;
	}
	fclose(fp);

	if (exists) {
		int szintLakok[8];
		for (int i = 0; i <= 7; i++) {
			szintLakok[i] = zsufolt(node->next, i);
		}
		int legzsufoltabbszint = legzsufoltabbSzintKeres(szintLakok);
		if (legzsufoltabbszint == 0 && floor < 0)
			printf("\na megadott szemely a(z) %d szobaban szall meg, ami a legzsufoltabb szinten van.", -floor);
		else if (legzsufoltabbszint == floor / 100)
			printf("\na megadott szemely a(z) %d szobaban szall meg, ami a legzsufoltabb szinten van.", floor);
		else
			printf("\na megadott szemely a(z) %d szobaban szall meg, ami a nem legzsufoltabb szinten van.", floor);

	} else {
		printf("\na megadott szemely a file-ban nem talalhato.");
	}
}

