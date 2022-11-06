#include "quicksort.h"

void quicksort(int *array, int n) {
    int temp;
    int i, j;
    int pivot = array[n / 2];

    if (n < 2) return;

    for (i = 0, j = n - 1; ; i++, j--) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;

        if (i >= j) break;

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    quicksort(array, i);
    quicksort(array + i, n - i);
}