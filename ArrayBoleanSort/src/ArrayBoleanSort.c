/*
 ============================================================================
 Name        : ArrayBoleanSort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int vetor[] = {0, 0, 1 , 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0};
	int tam = (int) sizeof(vetor) / sizeof(int);
	int contZ = 0;
	int i;

	printf("VETOR DE BOLEANOS DESORDENADOS\n");
	for (i = 0; i < tam; i++)
		printf("%i ", vetor[i]);

	for (i = 0; i < tam; i++)
		if (vetor[i] == 0)
			contZ++;

	for (i = 0; i < contZ; i++)
		vetor[i] = 0;

	for (i = contZ; i < tam; i++)
		vetor[i] = 1;

	printf("\n\nVETOR DE BOLEANOS ORDENADO\n");
	for (i = 0; i < tam; i++)
		printf("%i ", vetor[i]);

	printf("\n\n\nFim do programa.");

	return EXIT_SUCCESS;
}
