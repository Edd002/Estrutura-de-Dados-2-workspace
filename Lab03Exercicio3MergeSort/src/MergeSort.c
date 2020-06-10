/*
 * MergeSort.c
 *
 *  Created on: 13 de set de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "MergeSort.h"

int* preencherVetor(int tam) {
	int* vet = (int*) malloc(sizeof(int) * tam);
	srand(time(0));

	int i;
	for (i = 0; i < tam; i++)
		vet[i] = rand();

	return vet;
}

void exibirVetor(int* vet, int tam) {
	int i;
	for (i = 0; i < tam; i ++ )
		printf("%i ", vet[i]);
}

void mergeSort(int* vet, int inicio, int fim) {
	int meio;
	if (inicio < fim) {
		meio = floor((inicio + fim) / 2);
		mergeSort(vet, inicio, meio);
		mergeSort(vet, meio + 1, fim);
		merge(vet, inicio, meio, fim);
	}
}

void merge(int* vet, int inicio, int meio, int fim) {
	int* temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;

	tamanho = fim - inicio + 1;
	p1 = inicio;
	p2 = meio + 1;

	temp = (int*) malloc(tamanho * sizeof(int));
	if (temp != NULL) {
		for (i = 0; i < tamanho; i++) {
			if (!fim1 && !fim2) {
				if (vet[p1] < vet[p2])
					temp[i] = vet[p1++];
				else
					temp[i]=vet[p2++];

				if (p1 > meio) fim1=1;
				if (p2 > fim) fim2=1;
			} else {
				if (!fim1)
					temp[i]=vet[p1++];
				else
					temp[i]=vet[p2++];
			}
		}
		for (j = 0, k = inicio; j < tamanho; j++, k++)
			vet[k]=temp[j];
	}
	free(temp);
}
