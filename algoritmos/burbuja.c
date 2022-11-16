#include "burbuja.h"

typedef enum { false, true } bool;
#define SWAP(x, y) { int SWAP = x; x = y; y = SWAP; };

void burbuja(int *array, int n) {
    int i;
    bool swapped;

    swapped = false;
    for (i = 0; i < n - 1; i++) {
        if (array[i] > array[i + 1]) {
            SWAP(array[i], array[i + 1]);
            swapped = true;
        }
    }
    if (swapped == false) return;
    burbuja(array, n - 1);
}