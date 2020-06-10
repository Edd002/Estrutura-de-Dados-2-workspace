/*
 ============================================================================
 Name        : Lab03Exercicio4HeapSort.c
 Author      : n226804875
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "HeapSort.h"

// HeapSort: Ordena��o utilizando um tipo de �rvore bin�ria
// Heap: Vetor que simula uma �rvore bin�ria completa com exce��o do �ltimo n�vel
// Todo elemento "pai" do vetor (�rvore) possui dois elemento como "filhos"
// "pai" (i) -> "filhos": (2*i+1) e (2*i+2)
int main(void) {
	setbuf(stdout, NULL);

	printf("-- HEAP SORT --\n");

	int tam = 0;
	printf("Informe o tamanho do vetor: \n");
	fflush(stdin);
	scanf("%i", &tam);

	int* vet = preencherVetor(tam);

	printf("\nVETOR DESORDENADO\n");
	exibirVetor(vet, tam);

	heapSort(vet, tam);

	printf("\n\nVETOR ORDENADO\n");
	exibirVetor(vet, tam);

	printf("\n\n");
	system("PAUSE");
	printf("\nFim do programa.");

	return EXIT_SUCCESS;
}
