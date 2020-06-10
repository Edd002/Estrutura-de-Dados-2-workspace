/*
 * InsertionSort.c
 *
 *  Created on: 13 de set de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "InsertionSort.h"

long* preencherVetor(int tam) {
	long* vet = (long*) malloc(sizeof(long) * tam);
	srand(time(0));

	int i;
	for (i = 0; i < tam; i++)
		vet[i] = rand();

	return vet;
}

void exibirVetor(long* vet, int tam) {
	int i;
	for (i = 0; i < tam; i ++ )
		printf("%ld ", vet[i]);
}

void insertionSort(long* vet, int tam) {
	int i, j, aux;
	for (i = 1; i < tam; i++) {
		aux = vet[i];
		for (j = i; (j > 0) && (aux < vet[j - 1]); j--)
			vet[j] = vet[j - 1];
		vet[j] = aux;
	}
}
