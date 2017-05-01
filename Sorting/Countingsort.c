#include <stdio.h>

void Countingsort(int *A, int *B, int k);

int main() {
	int X[9] = {23, 64, 13, 76, 87, 3, 858, 1, 9};
	int Y[9];
	Countingsort(X, Y, 858);
	int i;
	for (i = 0; i < 9; i++) printf("%d ", Y[i]);

	return 0;
}

void Countingsort(int *A, int *B, int k) {
	int counter[859];
	int i;
	for (i = 0; i <= 859; i++) {
		counter[i] = 0;
	}
	for (i = 0; i < 9; i++) {
		counter[A[i]]++;
	}
	for (i = 1; i <= 859; i++) {
		counter[i] += counter[i-1];
	}
	for (i = 8; i >= 0; i--) {
		B[counter[A[i]]-1] = A[i];
		counter[A[i]]--;
	}
}