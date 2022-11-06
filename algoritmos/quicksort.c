#include "quicksort.h"

#define SWAP(x, y) { int SWAP = x; x = y; y = SWAP; };

void quicksort(int *array, int n) {
    int i, j;
    int pivot = array[n / 2];

    if (n < 2) return;

    for (i = 0, j = n - 1; ; i++, j--) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;

        if (i >= j) break;

        SWAP(array[i], array[j])
    }

    quicksort(array, i);
    quicksort(array + i, n - i);
}