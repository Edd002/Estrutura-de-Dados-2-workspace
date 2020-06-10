/*
 ============================================================================
 Name        : EstudoQuickSort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// TUTORIAL: https://www.youtube.com/watch?v=MZaf_9IZCrc

#include <stdio.h>
#include <stdlib.h>

int selecionarPivoMoverUltimaPosicao(int*, int);
void particionar(int*, int);
void exibirVetor(int*, int);

int main(void) {
	setbuf(stdout, NULL);

	int vetor[] = {5, 4, 9, 0, 7, 3, 2, 6, 8, 1};
	int tam = sizeof(vetor) / sizeof(int);

	puts("Vetor antes: ");
	exibirVetor(vetor, tam);

	particionar(vetor, tam);

	puts("\n\nVetor depois:");
	exibirVetor(vetor, tam);

	puts("\n\n\nFIM DO PROGRAMA.");
	return EXIT_SUCCESS;
}

int selecionarPivoMoverUltimaPosicao(int vetor[], int tam) {
	int elemI = vetor[0];
	int elemM = vetor[tam / 2];
	int elemF = vetor[tam - 1];

	if ((elemI >= elemF && elemI <= elemM) || (elemI <= elemF && elemI >= elemM)) {
		vetor[tam - 1] = elemI;
		vetor[0] = elemF;
		return elemI;
	} else if ((elemM >= elemF && elemM <= elemI) || (elemM <= elemF && elemM >= elemI)) {
		vetor[tam - 1] = elemM;
		vetor[tam / 2] = elemF;
		return elemM;
	} else {
		return elemF;
	}
}

void particionar(int vetor[], int tam) {
	int pivo = selecionarPivoMoverUltimaPosicao(vetor, tam);
	int posPivo = tam - 1;
	int i = -1;
	int j = 0;
	int aux;
	printf("\nPivô: %i", pivo);

	while (j <= posPivo) {
		if (vetor[j] > pivo) {
			j++;
		} else {
			i++;
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			j++;
		}
	}
}

void exibirVetor(int vetor[], int tam) {
	int i = 0;
	for (i = 0; i < tam; i++)
		printf("%i ", vetor[i]);
}
