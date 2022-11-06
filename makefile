filename = algoritmos
default:
	gcc -std=iso9899:1990 -D_GNU_SOURCE $(filename).c -o $(filename)
	.\$(filename) data.txt
generar:
	gcc generador.c -o generador.o
test:
	gcc -std=iso9899:1990 -D_GNU_SOURCE -Wall -Wextra -pedantic $(filename).c -o $(filename)
	.\$(filename) testdata.txt