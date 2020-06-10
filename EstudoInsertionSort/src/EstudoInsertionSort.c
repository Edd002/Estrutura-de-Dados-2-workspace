/*
 ============================================================================
 Name        : EstudoInsertionSort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int vetor[] = {5, 9, 8, 7, 3, 0, 1, 6, 4, 2};
	int tam = sizeof(vetor) / sizeof(int);
	int i, j, aux;

	for (i = 0; i < tam; i++) {
		j = i;
		while (vetor[j - 1] > vetor[j] && j > 0) {
			aux = vetor[j - 1];
			vetor[j - 1] = vetor[j];
			vetor[j] = aux;
			j--;
		}
	}

	puts("VETOR ORDENADO:");
	for (i = 0; i < tam; i++)
		printf("%i ", vetor[i]);

	return 0;
}
