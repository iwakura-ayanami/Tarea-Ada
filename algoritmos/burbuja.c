#include "burbuja.h"

#define SWAP(x, y) { int SWAP = x; x = y; y = SWAP; };

void burbuja(int *array, int n) {
    int i;
    int cta = 0;

    /* Caso base */
    if (n == 1) return;
 
    for (i = 0; i < n - 1; i++)
        if (array[i] > array[i + 1]) {
            SWAP(array[i], array[i + 1])
            cta++;
        }
 
    if (cta == 0) return;
    burbuja(array, n - 1);
}