/*
 ============================================================================
 Name        : EstudoSelectionSort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int vetor[] = {5, 9, 8, 7, 3, 0, 1, 6, 4, 2};
	int tam = sizeof(vetor) / sizeof(int);
	int i, j, aux;

	for (i = 0; i < tam; i++) {
		for (j = i + 1; j < tam; j++) {
			if (vetor[j] < vetor[i]) {
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}

	puts("VETOR ORDENADO:");
	for (i = 0; i < tam; i++)
		printf("%i ", vetor[i]);

	return 0;
}
