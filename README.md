## Tarea Análisis de Algoritmos

Implementación de algoritmos de ordenamiento en ANSI C

**Algoritmos**:

*   Burbuja Recursivo

*   Shellsort Recursivo

*   Merge Sort

*   Quicksort

## Como Usar

**Automaticamente** *con make*

Generar nuevo archivo `data.txt` con 10M datos aleatorios. *(opcional)*

    $ make generar

Ejecutar algoritmos para 100, 1000, 5000,...10M datos y exportar output a archivo `logs.txt`

    $ make run

Testear algoritmos solo con N datos `n=numero`

    $ make check n=2000000

Testeo rapido, compila con `-Wall -Wextra -pedantic -g` para mejor debugging

    $ make test

Solo compilar, recomendado para uso manual

    $ make

***

**Manualmente** *sin make*

Compilar sin make

    $ gcc -std=iso9899:1990 -O -foptimize-sibling-calls -D_GNU_SOURCE main.c ./algoritmos/*.c -o main -I ./algoritmos

Opciones

```bash
$ ./main -i <filename> -n <number> -s
-i <archivo>            Especifica el archivo con datos aleatorios a utilizar
-n <numero>             Numero de datos o lineas que se ordenaran
-s                      Saltarse algoritmos lentos (burbuja), recomendado si solo se busca hacer un ordenamiento rapido
```

Ejemplo

    $ ./main -i data.txt -n 20000s -s
