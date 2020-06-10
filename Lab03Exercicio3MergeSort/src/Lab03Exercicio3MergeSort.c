/*
 ============================================================================
 Name        : Lab03Exercicio3MergeSort.c
 Author      : n226804875
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"

int main(void) {
	setbuf(stdout, NULL);

	printf("-- MERGE SORT --\n");

	int tam = 0;
	printf("Informe o tamanho do vetor: \n");
	fflush(stdin);
	scanf("%i", &tam);

	int* vet = preencherVetor(tam);

	printf("\nVETOR DESORDENADO\n");
	exibirVetor(vet, tam);

	mergeSort(vet, 0, tam - 1);

	printf("\n\nVETOR ORDENADO\n");
	exibirVetor(vet, tam);

	printf("\n\n");
	system("PAUSE");
	printf("\nFim do programa.");

	return EXIT_SUCCESS;
}
