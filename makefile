#	-std=iso9899:1990  			usar el standar iso9899:1990 (ANSI C)
#	-O							minimas optimizaciones de codigo, necesario para -foptimize-sibling-calls
#	-foptimize-sibling-calls	optimiza funciones de recursión de cola
#	-D_GNU_SOURCE				necesario para usar extensiones de GNU
#	-Wl							permite pasar opiciones al linker
#	--stack						le indica al linker el tamaño especifico del stack
#	-Wall						habilita todos mensajes de advertencia
#	-Wextra						habilita mensajes de advertencia extras que no estan incluidos en -Wall
#	-pedantic					habilita mensajes de advertencia releacionados con el estandar ISO
#	-g							compila con información de debugeo
CFLAGS = -std=iso9899:1990 -O -foptimize-sibling-calls -D_GNU_SOURCE -Wl,--stack,16777216
CFLAGS2 = -Wall -Wextra -pedantic -g
CC = gcc
MAKEFLAGS += --silent
FILENAME = main
INCLUDE = ./algoritmos
saltar-b =

default:
	$(CC) $(CFLAGS) $(FILENAME).c $(INCLUDE)/*.c -o $(FILENAME) -I $(INCLUDE)

run:
	$(CC) $(CFLAGS) $(FILENAME).c $(INCLUDE)/*.c -o $(FILENAME) -I $(INCLUDE)
	./$(FILENAME) -i data.txt -n 100 $(saltar-b) | tee logs.txt
	./$(FILENAME) -i data.txt -n 1000 $(saltar-b)| tee -a logs.txt
	./$(FILENAME) -i data.txt -n 5000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 10000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 50000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 100000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 200000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 400000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 600000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 800000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 1000000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 2000000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 3000000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 4000000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 5000000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 6000000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 7000000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 8000000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 9000000 $(saltar-b) | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 10000000 $(saltar-b) | tee -a logs.txt
	$(CC) $(CFLAGS) exportar.c -o exportar.o
	./exportar.o
	rm exportar.o

generar:
	$(CC) generador.c -o generador.o
	./generador.o
	rm generador.o

check:
	$(CC) $(CFLAGS) $(FILENAME).c $(INCLUDE)/*.c -o $(FILENAME) -I $(INCLUDE)
	./$(FILENAME) -i data.txt -n $(n) $(saltar-b)

test:
	$(CC) $(CFLAGS) $(CFLAGS2) $(FILENAME).c $(INCLUDE)/*.c -o $(FILENAME) -I $(INCLUDE)
	./$(FILENAME) -i data.txt -n 100 -s | tee logs.txt
	./$(FILENAME) -i data.txt -n 1000 -s | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 5000 -s | tee -a logs.txts
	./$(FILENAME) -i data.txt -n 10000 -s | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 50000 -s | tee -a logs.txt
	./$(FILENAME) -i data.txt -n 100000 -s | tee -a logs.txt
	$(CC) $(CFLAGS) exportar.c -o exportar.o
	./exportar.o
	rm exportar.o
