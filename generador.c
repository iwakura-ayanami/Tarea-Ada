#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    /* declaracion del vector con tamaño 10M  */
    FILE *fpt;
    int i;
    int array[10000000];
    int array2[10000000];
    
    /* calculo del largo del vector */
    int length = sizeof array / sizeof array[0];

    fpt = fopen("data.txt", "w+");
    
    /* creacion del vector desordenado */
    srand(time (NULL));
    for (i = 0; i < lenght; i++) {
        array[i] = rand(); 
        fprintf(fpt,"%d\n", array[i]);
    }

    fclose(fpt);
    return 0;
}
