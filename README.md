## Tarea Análisis de Algoritmos

Implementación de algoritmos de ordenamiento en ANSI C

**Algoritmos**:

*   Burbuja Recursivo

*   Shellsort Recursivo

*   Merge Sort

*   Quicksort

## Como Usar

**Automaticamente con make**

Generar nuevo archivo `data.txt` con 10M datos aleatorios. *(opcional)*

    $ make generar

Ejecutar algoritmos para 100, 1000, 5000, ...10M datos y exportar output a archivo `logs.txt`

    $ make run

Testear algoritmos solo con N datos `n=numero`

    $ make check n=2000000

Testeo rapido, compila con `-Wall -Wextra -pedantic -g` para mejor debugging

    $ make test

**Manualmente**

Compilar programa principal

    $ make

Compilar sin make

    $ gcc -std=iso9899:1990 -O -foptimize-sibling-calls -D_GNU_SOURCE main.c ./algoritmos/*.c -o main -I ./algoritmos

Ejemplo

    $ ./main -i <filename> -n <number> -s
