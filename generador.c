#include <stdio.h>
#include <stdlib.h>

int main() {

    // declaracion del vector poner el largo 
    static int array[10000000];
    static int array2[10000000];
    
    // calculo del largo del vector
    int lenght = sizeof array / sizeof array[0];
    
    // creacion del vector desordenado
    /*printf("Arreglo sin ordenar: \n");
    for(int x=0; x<lenght; x++ ){
        array[x]=rand(); 
        printf("%d.- %d\n",x,array[x]);
    }*/

    // Carga en un archivo csv 
    FILE *fpt;

    fpt = fopen("data.txt", "w+");
    
    for(int x=0; x<lenght; x++ ) {
        array[x]=rand(); 
        //printf("%d.- %d\n",x,array[x]);
        fprintf(fpt,"%d\n", array[x] );
    }
    printf("%d\n",array[0]);
    printf("%d\n",array[10]);
    printf("%d\n",array[100]);
    fclose(fpt);
    return 0;
}
