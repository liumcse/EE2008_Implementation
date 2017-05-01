#include <stdio.h>
#include "PriorityQueue.h"

int size = 0;
int *value;
int *key;

int main() {
	int scale;

	printf("Enter the size of the Priority Queue: ");
	scanf("%d", &scale);

	// Create two parallel arrays to store key and respective value
	key = malloc(sizeof(int)*scale);
	value = malloc(sizeof(int)*scale);

	int i;

	int inputKey = 0, inputValue = 0;

	while (inputKey != -1) {
		printf("Enter key (-1 to exit): ");
		scanf("%d", &inputKey);
		printf("Enter value: ");
		scanf("%d", &inputValue);
		insertItem(inputKey, inputValue);
		if (size == scale) break;
	}

	printf("\nKey: ");
	for (i = 0; i < size; i++) {
		printf("%d\t", key[i]);
	}
	printf("\nVal: ");
	for (i = 0; i < size; i++) {
		printf("%d\t", value[i]);
	}

	printf("\n\nPQ size is %d", Qsize());
	printf("\nElement with smallest key is %d", minElement());
	printf("\nSmallest key is %d", minKey());
	printf("\n\nAfter remove min key:\n");
	removeMin();

	printf("\nKey: ");
	for (i = 0; i < size; i++) {
		printf("%d\t", key[i]);
	}
	printf("\nVal: ");
	for (i = 0; i < size; i++) {
		printf("%d\t", value[i]);
	}

	return 0;
}

int Qsize() {
	return size;
}

int isEmpty() {
	if (size == 0) return 1;
	else return 0;
}

void insertItem(int key_, int value_) {
	int i;
	for (i = 0; i < size; i++) {
		if (key[i] == key_) {
			value[i] = value_;
			return;
		}
	}
	key[size] = key_;
	value[size] = value_;
	size++;
	return;
}

int minElement() {
	if (isEmpty()) return -1;
	int i, j;
	int minKey = key[i];
	for (i = 0; i < size; i++) {
		if (key[i] < minKey) {
			minKey = key[i];
			j = i;
		}
	}
	return value[j];
}

int minKey() {
	if (isEmpty()) return -1;
	int i;
	int minKey = key[0];
	for (i = 0; i < size; i++) {
		if (key[i] < minKey) {
			minKey = key[i];
		}
	}
	return minKey;
}

int removeMin() {
	if (isEmpty()) return -1;
	int i, j;
	int minKey = key[i];
	for (i = 0; i < size; i++) {
		if (key[i] < minKey) {
			minKey = key[i];
			j = i;
		}
	}
	int min = value[j];
	for (i = j; i < size; i++) {
		key[i] = key[i+1];
		value[i] = value[i+1];
	}
	size--;
	return min;
}