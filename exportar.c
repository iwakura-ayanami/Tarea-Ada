#include <stdio.h>
#include <stdlib.h>

struct Algoritmos {
  float burbuja;
  float shell;
  float merge;
  float quick;
};

struct Algoritmos algo[20];

int main(void) {
    FILE *stream;
    char buf[100];
    float shell, merge, quick, burbuja;
    int i = 0, j = 0, lineas = 4;

	stream = fopen("logs.txt", "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);
		
	while (fgets(buf, 100, stream)) {
        i++;
        sscanf(buf, "Burbuja: 		 %f",&burbuja);
        if (burbuja) lineas = 5;
        sscanf(buf, "Shell: 		 %f",&shell);
        sscanf(buf, "Mergesort: 		 %f",&merge);
        sscanf(buf, "Quicksort: 		 %f",&quick);
        if (i == lineas) {
            algo[j].burbuja = burbuja;
            algo[j].shell = shell;
            algo[j].merge = merge;
            algo[j].quick = quick;
            i = 0;
            j++;
        }
    }

    fclose(stream);
    stream = fopen("logs.txt", "w+");

    fprintf(stream,"--Burbuja--\n");
    for (i = 0; i < 20; i++) {
        fprintf(stream,"%f\n", algo[i].burbuja);
    }
    fprintf(stream,"--Shell--\n");
    for (i = 0; i < 20; i++) {
        fprintf(stream,"%f\n", algo[i].shell);
    }
    fprintf(stream,"\n--Mergesort--\n");
    for (i = 0; i < 20; i++) {
        fprintf(stream,"%f\n", algo[i].merge);
    }
    fprintf(stream,"\n--Quicksort--\n");
    for (i = 0; i < 20; i++) {
        fprintf(stream,"%f\n", algo[i].quick);
    }

    fclose(stream);
	exit(EXIT_SUCCESS);
}