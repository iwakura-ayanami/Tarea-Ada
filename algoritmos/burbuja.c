#include "burbuja.h"

void burbuja(int *array, int n) {
    int temp, i;
    int cta = 0;

    /* Caso base */
    if (n == 1) return;
 
    for (i = 0; i < n - 1; i++)
        if (array[i] > array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i+1] = temp;
            cta++;
        }
 
    if (cta == 0) return;
    burbuja(array, n - 1);
}