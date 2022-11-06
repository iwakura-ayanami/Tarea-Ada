#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
    static long int array[10000000];
    int i = 0;
    char *filename = argv[1];
    (void)argc;

    /* Carga archivo que contiene los datos */
	stream = fopen(filename, "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);

    /* Cargar datos linea por linea en un arreglo */
	while ((read = getline(&line, &len, stream)) != -1) {
        array[i] = strtol(line, NULL, 10);
        i++;
	}
    
    while (i >= 0) {
        printf("%d \n", array[i]);
        i--;
    }

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}