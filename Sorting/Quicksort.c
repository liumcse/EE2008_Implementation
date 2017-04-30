#include <stdio.h>

int partition(int *A, int p, int r);
void Quicksort(int *A, int p, int r);

int main() {
	int X[9] = {23, 64, 13, 76, 87, 3, 858, 1, 9};
	Quicksort(X, 0, 8);
	int i;
	for (i = 0; i < 9; i++) printf("%d ", X[i]);
}

int partition(int *A, int p ,int r) {
	int h = p;
	int k;
	for (k = p + 1; k <= r; k++) {
		if (A[k] < A[p]) {
			h++;
			int temp = A[k];
			A[k] = A[h];
			A[h] = temp;
		}
	}

	int temp = A[h];
	A[h] = A[p];
	A[p] = temp;

	return h;
}

void Quicksort(int *A, int p, int r) {
	if (p >= r) return;
	else {
		int m = partition(A, p, r);
		Quicksort(A, p, m-1);
		Quicksort(A, m+1, r);
	}
}