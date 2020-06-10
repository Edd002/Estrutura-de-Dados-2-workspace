/*
 ============================================================================
 Name        : ExercicioRecursividade.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Library.h"

int main(void) {
	setbuf(stdout, NULL);

	printf("Aquecimento - Questão 1: \n%i\n", aquecimentoQuestao1Peel(2));

	printf("\nAquecimento - Questão 2:\n");
	aquecimentoQuestao2Peel(5, 6);

	printf("\nAquecimento - Questão 3:");
	aquecimentoQuestao3RecursivaPeel(40);
	aquecimentoQuestao3IterativaPeel(40);

	printf("\n\nEntrega - Questão 1:\n");
	entregaQuestao1Peel("Eduardo");

	printf("\n\nEntrega - Questão 2:\n");
	entregaQuestao2Peel("Ana");

	printf("\n\nEntrega - Questão 3:\n");
	entregaQuestao3(12546);
	entregaQuestao3Peel(12546);

	printf("\n\nEntrega - Questão 4A\n");
	int vetor[8] = {5, 20, 15, 4, 18, 14, 30, 60};
	entregaQuestao4APeel(vetor, 8);

	printf("\n\nEntrega - Questão 4B\n");
	int vetor1[4] = {5, 20, 15, 60};
	int vetor2[4] = {4, 18, 14, 30};
	entregaQuestao4BPeel(vetor1, vetor2, 4, 4);

	printf("\n\nEntrega - Questão 5\n");
	// Posições funcionando: 3, 5, 6, 7
	// Posições não funcionando: 0, 1, 2, 4
	int vetorBinarySearch[8] = {5, 20, 15, 4, 18, 14, 30, 60};
	entregaQuestao5IterativaPeel(vetorBinarySearch, 8, 4);
	entregaQuestao5RecursivaPeel(vetorBinarySearch, 8, 4);

	return EXIT_SUCCESS;
}
