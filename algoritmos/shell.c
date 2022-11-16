#include "shell.h"

void shell(int *array, int n) {
    int gap, i, j, valor;
    for (gap = n; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            valor = array[i];
            for (j = i; j >= gap && valor < array[j - gap]; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = valor;
        }
    }
}