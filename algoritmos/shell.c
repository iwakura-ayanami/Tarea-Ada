#include "shell.h"

 int shell(int *array, int n) {
    int i, valor;

    if (n <= 1) return n;
    n = shell(array, n - 1);
    valor = array[n];
    i = n - 1;
    while ((i >= 0) && (array[i] > valor)) {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = valor;
    return n + 1;
}
