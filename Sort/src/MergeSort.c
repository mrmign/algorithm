#include "MergeSort.h"

void merge(Item a[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	float *L = (float*) malloc(sizeof(float) * n1);
	float *R = (float*) malloc(sizeof(float) * n2);

	int i, j;
	for (i = 0; i < n1; i++)
		L[i] = a[p + i];
	for (j = 0; j < n2; j++)
		R[j] = a[q + 1 + j]; //q is  the middle.

	i = j = 0;
	int k = p;
	while (i < n1 && j < n2)
		if (L[i] <= R[j]) {
			a[k++] = L[i];
			i++;
		} else {
			a[k++] = R[j];
			j++;
		}

	for (; i < n1; i++) {
		a[k++] = L[i];
	}

	for (; j < n2; j++) {
		a[k++] = R[j];
	}

	free(L);
	free(R);
	L = NULL;
	R = NULL;
}

void merge_sort(Item a[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}
