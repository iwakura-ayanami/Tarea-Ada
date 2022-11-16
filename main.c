#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "burbuja.h"
#include "shell.h"
#include "mergesort.h"
#include "quicksort.h"

typedef enum { false, true } bool;

int main(int argc, char *argv[]) {
    FILE *stream;
    int linea = 0, i = 0, n;
    int *array;
    bool saltar = false;
    struct timespec inicio, fin;
    double tiempo_ejec;

    /* Parametros por consola */
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-i") && i + 1 < argc) {       /* Carga archivo que contiene los datos */
            stream = fopen(argv[i + 1], "r");
            	if (stream == NULL) {
                    printf("Archivo invalido");
		            exit(EXIT_FAILURE);
                }
            i++;
        } else if (!strcmp(argv[i], "-n") && i + 1 < argc) {
            n = atoi(argv[i + 1]);
            array = malloc(n * sizeof (int));
            i++;
        } else if (!strcmp(argv[i], "-s")) {
            saltar = true;
        } else {
            printf("Error de sintaxis");
            exit(EXIT_FAILURE);
        }
    }

    /* Cargar los datos linea por linea en un arreglo */
    while (fscanf(stream, "%d", &linea) != EOF) {
        if (i >= n) break;
        array[i++] = linea;
    }

    printf("----- N: %d ------------------\n", n);

    if (saltar) goto no_burbuja;

    /* Burbuja */
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    burbuja(array, n);
    clock_gettime(CLOCK_MONOTONIC, &fin);
    tiempo_ejec = (fin.tv_sec - inicio.tv_sec) * 1e9;
    tiempo_ejec = (tiempo_ejec + (fin.tv_nsec - inicio.tv_nsec)) * 1e-9;
    printf("Burbuja: \t %f segundos \n", tiempo_ejec);

    no_burbuja:

    /* Shell */
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    shell(array, n);
    clock_gettime(CLOCK_MONOTONIC, &fin);
    tiempo_ejec = (fin.tv_sec - inicio.tv_sec) * 1e9;
    tiempo_ejec = (tiempo_ejec + (fin.tv_nsec - inicio.tv_nsec)) * 1e-9;
    printf("Shell: \t\t %f segundos \n", tiempo_ejec);

     /* Print array ordenado (para testear) */
    /* for (i = 0; i < n; i++) {
        printf("%d \n", array[i]);
    } */

    /* Mergesort */
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    mergesort(array, n);
    clock_gettime(CLOCK_MONOTONIC, &fin);
    tiempo_ejec = (fin.tv_sec - inicio.tv_sec) * 1e9;
    tiempo_ejec = (tiempo_ejec + (fin.tv_nsec - inicio.tv_nsec)) * 1e-9;
    printf("Mergesort: \t %f segundos \n", tiempo_ejec);

    /* Quicksort */
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    quicksort(array, n);
    clock_gettime(CLOCK_MONOTONIC, &fin);
    tiempo_ejec = (fin.tv_sec - inicio.tv_sec) * 1e9;
    tiempo_ejec = (tiempo_ejec + (fin.tv_nsec - inicio.tv_nsec)) * 1e-9;
    printf("Quicksort: \t %f segundos \n", tiempo_ejec);

    free(array);
	fclose(stream);
	exit(EXIT_SUCCESS);
}