#include "shell.h"

void shell(int *array, int gap, int n) {
    int i, j, valor;
    
    if (gap < 1) return;

    for (i = gap; i < n; i++) {
        valor = array[i];
        for (j = i; j >= gap && valor < array[j - gap]; j -= gap) {
            array[j] = array[j - gap];
        }
        array[j] = valor;
    }
    shell(array, gap / 2, n);
}