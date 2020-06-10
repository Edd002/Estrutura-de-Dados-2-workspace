/*
 ============================================================================
 Name        : EstudoHeapSort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void heapSort(int*, int);
void heapify(int*, int, int);
void imprime(int*, int);

int main(void) {
	setbuf(stdout, NULL);

	int vet[] = {5, 9, 0, 1, 6, 3, 4, 2, 7, 8};
	int tam = sizeof(vet) / sizeof(int);

	heapSort(vet, tam);
	imprime(vet, tam);

	return EXIT_SUCCESS;
}


void heapSort(int vet[], int tam) {
	int i, temp;

	for (i = tam / 2 - 1; i >= 0; i--)
		heapify(vet, tam, i);

	for (i = tam - 1; i >= 0; i--) {
		temp = vet[0];
		vet[0] = vet[i];
		vet[i] = temp;
		heapify(vet, i, 0);
	}
}

void heapify(int vet[], int tam, int i) {
	int esq = 2*i + 1;
	int dir = 2*i + 2;
	int max = i;

	if (esq < tam && vet[max] < vet[esq])
		max = esq;

	if (dir < tam && vet[max] < vet[dir])
		max = dir;

	if (max != i) {
		int temp = vet[max];
		vet[max] = vet[i];
		vet[i] = temp;
		heapify(vet, tam, max);
	}
}

void imprime(int vet[], int tam) {
	int i;
	for (i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	printf("\n");
}
