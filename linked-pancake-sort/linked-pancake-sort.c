#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct node* prev, * next;
} node;

typedef struct {
	node* first;
	node* last;
} listType;

void print(listType list) {
	node* walker = list.first;
	while (walker->next != NULL) {
		printf("%d,", walker->data);
		walker = walker->next;
	}
	printf("%d,", walker->data);
}

void flipForward(listType list, int* prevmax) {
	node* walker = list.first;
	node* temp;
	while (walker->next != NULL) {
		if (walker->data == *prevmax) {
			while (walker->next != NULL) {
				temp = walker->next;
				walker->next = walker->prev;
				walker->prev = temp;
			}
			walker->next = walker->prev;
			walker->prev = temp;
			print(list);
			return;
		}
	}
}

void flipBackward(listType input, int* prevmax) {

}


listType makeList(int len) {
	listType list;
	list.first = NULL;
	list.last = NULL;
	for (int i = 0; i < len; i++) {
		node* elem = (node*)malloc(sizeof(node));
		scanf("%d", &(elem->data));
		if (list.first == NULL) {
			list.first = elem;
			list.last = elem;
			elem->prev = NULL;
			elem->next = NULL;
		} else {
			elem->prev = list.last->next;
			list.last->next = elem;
			list.last = elem;
			elem->next = NULL;
		}
	}
	return list;
}

int searchMax(listType list) {
	node* walker = list.first;
	int max = -__INT_MAX__;
	while (walker->next != NULL) {
		if (walker->data > max)
			max = walker->data;
		walker = walker->next;
	}
	// if (walker->data > max)
	// 	max = walker->data;
	return max;
}

int main() {
	int prevmax, len = 10;
	listType list = makeList(len);
	print(list);
	int max = searchMax(list);
	for (int i = 0; i < len; i++) {
		flipForward(list, max);
		searchMax(list);
	}

	return 0;
}
