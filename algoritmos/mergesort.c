#include <stdlib.h>
#include "mergesort.h"

void merge(int *array, int n, int mitad) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = mitad, k = 0; k < n; k++) {
        x[k] = j == n ? array[i++]
             : i == mitad ? array[j++]
             : array[j] < array[i] ? array[j++]
             : array[i++];
    }
    for (i = 0; i < n; i++) {
        array[i] = x[i];
    }
    free(x);
}

void mergesort(int *array, int n) {
    int mitad = n / 2;
    if (n < 2) return;
    mergesort(array, mitad);
    mergesort(array + mitad, n - mitad);
    merge(array, n, mitad);
}
