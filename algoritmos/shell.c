#include "shell.h"

void shell(int *array, int n) {
    int h, i, j, t;
    for (h = n; h /= 2;) {
        for (i = h; i < n; i++) {
            t = array[i];
            for (j = i; j >= h && t < array[j - h]; j -= h) {
                array[j] = array[j - h];
            }
            array[j] = t;
        }
    }
}