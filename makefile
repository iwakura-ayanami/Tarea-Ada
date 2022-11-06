MAKEFLAGS += --silent
filename = main
include = ./algoritmos
default:
	gcc -std=iso9899:1990 $(filename).c $(include)/*.c -o $(filename) -I $(include)
	.\$(filename) data.txt 100
	.\$(filename) data.txt 1000
	.\$(filename) data.txt 5000
	.\$(filename) data.txt 10000
	.\$(filename) data.txt 50000
	.\$(filename) data.txt 100000
	.\$(filename) data.txt 200000
	.\$(filename) data.txt 400000
	.\$(filename) data.txt 600000
	.\$(filename) data.txt 800000
	.\$(filename) data.txt 1000000
	.\$(filename) data.txt 2000000
	.\$(filename) data.txt 3000000
	.\$(filename) data.txt 4000000
	.\$(filename) data.txt 5000000
	.\$(filename) data.txt 6000000
	.\$(filename) data.txt 7000000
	.\$(filename) data.txt 8000000
	.\$(filename) data.txt 9000000
	.\$(filename) data.txt 10000000

generar:
	gcc generador.c -o generador.o
	./generador.o
	rm generador.o

test:
	gcc -std=iso9899:1990 -Wall -Wextra -pedantic $(filename).c $(include)/*.c -o $(filename) -I $(include)
	.\$(filename) data.txt 10000

test2:
	gcc -std=iso9899:1990 -Wall -Wextra -pedantic $(filename).c $(include)/*.c -o $(filename) -I $(include)
	.\$(filename) data.txt 43686
	.\$(filename) data.txt 43687

exportar:
	gcc -std=iso9899:1990 $(filename).c $(include)/*.c -o $(filename) -I $(include)
	./$(filename) data.txt 100 > logs.txt
	./$(filename) data.txt 1000 >> logs.txt
	./$(filename) data.txt 5000 >> logs.txt
	./$(filename) data.txt 10000 >> logs.txt
	./$(filename) data.txt 50000 >> logs.txt
	./$(filename) data.txt 100000 >> logs.txt
	./$(filename) data.txt 200000 >> logs.txt
	./$(filename) data.txt 400000 >> logs.txt
	./$(filename) data.txt 600000 >> logs.txt
	./$(filename) data.txt 800000 >> logs.txt
	./$(filename) data.txt 1000000 >> logs.txt
	./$(filename) data.txt 2000000 >> logs.txt
	./$(filename) data.txt 3000000 >> logs.txt
	./$(filename) data.txt 4000000 >> logs.txt
	./$(filename) data.txt 5000000 >> logs.txt
	./$(filename) data.txt 6000000 >> logs.txt
	./$(filename) data.txt 7000000 >> logs.txt
	./$(filename) data.txt 8000000 >> logs.txt
	./$(filename) data.txt 9000000 >> logs.txt
	./$(filename) data.txt 10000000 >> logs.txt
	gcc -std=iso9899:1990 -Wall -Wextra -pedantic exportar.c -o exportar.o
	./exportar.o
	rm exportar.o
