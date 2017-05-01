#include <stdio.h>
#include <stdlib.h>

void Mergesort(int *A, int i, int j);
void merge(int *A, int i, int m, int j);

int main() {

	int X[9] = {23, 64, 13, 76, 87, 3, 858, 1, 9};
	Mergesort(X, 0, 8);
	// int X[9] = {6, 7, 8, 9, 1, 2, 3, 4, 5};
	// merge(X, 0, 4, 8);
	int i;
	for (i = 0; i < 9; i++) printf("%d ", X[i]);

	return 0;
}

void Mergesort(int *A, int i, int j) {
	if (i == j) return;
	int m = (i + j)/2;

	Mergesort(A, i, m);
	Mergesort(A, m+1, j);
	merge(A, i, m, j);
}

void merge(int *A, int i, int m, int j) {

	int L[10];
	int R[10];
	int k;
	for (k = 0; k < m - i + 1; k++) L[k] = A[i + k];
	for (k = 0; k < j - m; k++) R[k] = A[m + k + 1];

	// printf("\nL: ");
	// for (k = 0; k < m-i; k++) printf("%d ", L[k]);
	// printf("\nR: ");
	// for (k = 0; k < j - m + 1; k++) printf("%d ", R[k]);
	// printf("\n");

	int x = 0, y = 0;
	int r = i;

	while (x < m - i + 1 && y < j - m) {
		// printf("x = %d", x);
		if (L[x] <= R[y]) A[r++] = L[x++];
		else A[r++] = R[y++];
	}

	printf("\ni = %d, m = %d, j = %d", i , m, j);
	printf("\nL: ");
	for (k = 0; k < m-i; k++) printf("%d ", L[k]);
	printf("\nR: ");
	for (k = 0; k < j - m + 1; k++) printf("%d ", R[k]);
	printf("\n");

	while (x < m - i + 1) A[r++] = L[x++];
	while (y < j - m) A[r++] = R[y++];
}