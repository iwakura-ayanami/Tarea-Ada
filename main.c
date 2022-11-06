#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "burbuja.h"
#include "shell.h"
#include "mergesort.h"
#include "quicksort.h"

int main(int argc, char *argv[]) {
    FILE *stream;
    int linea = 0, i = 0;
    int n = atoi(argv[2]);
    int *array = malloc(n * sizeof (int));     /* ANSI C workaround for: array(n) */
    int *array2 = array;
    clock_t tiempo;
    double tiempo_ejec;
    (void)argc;

    /* Carga archivo que contiene los datos */
	stream = fopen(argv[1], "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);

    /* Cargar los datos linea por linea en un arreglo */
    while (fscanf(stream, "%d", &linea) != EOF) {
        if (i >= n) break;
        array[i++] = linea;
    }

    printf("----- N: %d ------------------\n", n);

    /* Burbuja */ /* Muere en array[43687] */
    /* tiempo = clock();
    burbuja(array2, n);
    tiempo_ejec[0] = ((double)(clock() - tiempo)) / CLOCKS_PER_SEC;
    printf("Burbuja: \t %f segundos \n", tiempo_ejec); */
    
    /* Shell */
    tiempo = clock();
    shell(array2, n);
    tiempo_ejec = ((double)(clock() - tiempo)) / CLOCKS_PER_SEC;
    printf("Shell: \t\t %f segundos \n", tiempo_ejec);

    /* Mergesort */
    tiempo = clock();
    mergesort(array2, n);
    tiempo_ejec = ((double)(clock() - tiempo)) / CLOCKS_PER_SEC;
    printf("Mergesort: \t %f segundos \n", tiempo_ejec);

    /* Quicksort */
    tiempo = clock();
    quicksort(array2, n);
    tiempo_ejec= ((double)(clock() - tiempo)) / CLOCKS_PER_SEC;
    printf("Quicksort: \t %f segundos \n", tiempo_ejec);

    /* Print array ordenado (para testear) */
    /* for (i = 0; i < n; i++) {
        printf("%d \n", array2[i]);
    } */

    printf("\n");


    free(array);
	fclose(stream);
	exit(EXIT_SUCCESS);
}