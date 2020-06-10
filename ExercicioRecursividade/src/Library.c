/*
 * Library.c
 *
 *  Created on: 9 de ago de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Library.h"

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Questão 1 - Aquecimento - RECURSIVA DIRETA, LINEAR, DE CAUDA E NÃO ANINHADA
int aquecimentoQuestao1Tail(int n, int resultado) {
	if (n == 1)
		return resultado;
	else if (n > 1)
		return aquecimentoQuestao1Tail(n - 1, (3 * resultado * (n - 1)) - 2);
	else
		return 0;
}

int aquecimentoQuestao1Peel(int n) {
	return aquecimentoQuestao1Tail(n, 3);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Questão 2 - Aquecimento - RECURSIVA DIRETA, LINEAR, DE CAUDA E NÃO ANINHADA
void aquecimentoQuestao2Tail(int n, int q, int qAux, int resultado) {
	if (q >= qAux) {
		printf("%i x %i = %i\n", n, qAux, resultado);
		resultado = (qAux + 1) * n;
		aquecimentoQuestao2Tail(n, q, qAux + 1, resultado);
	}
}

void aquecimentoQuestao2Peel(int n, int q) {
	aquecimentoQuestao2Tail(n, q, (q - q + 1), n * 1);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Questão 3 - Aquecimento - RECURSIVA DIRETA, LINEAR, DE CAUDA E NÃO ANINHADA
int aquecimentoQuestao3RecursivaTail(int n, int a, int b) {
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	return aquecimentoQuestao3RecursivaTail(n - 1, b, a + b);
}

void aquecimentoQuestao3RecursivaPeel(int n) {
	int i = 0;

	printf("\nOs termos da série Fibonacci são (resultado por recursão):\n");
	for (i = 0; i < n; i++)
		printf("%d ", aquecimentoQuestao3RecursivaTail(i, 0, 1));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Questão 3 - Aquecimento - ITERATIVA
void aquecimentoQuestao3IterativaTail(int n) {
	int primeiro = 0;
	int segundo = 1;
	int proximo;
	int c;

	printf("\nOs termos da série Fibonacci são (resultado por iteração):\n");
	for (c = 0; c < n; c++) {
		if (c <= 1) {
			proximo = c;
		} else {
			proximo = primeiro + segundo;
			primeiro = segundo;
			segundo = proximo;
		}
		printf("%d ", proximo);
	}
}

void aquecimentoQuestao3IterativaPeel(int n) {
	aquecimentoQuestao3IterativaTail(n);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Questão 1 e Questão 2 - Entrega - RECURSIVA DIRETA, LINEAR, DE CAUDA E NÃO ANINHADA
char* entregaQuestao1Questao2Tail(char* string, char* stringInvertida, int posPrimeiroCaracter, int posUltimoCaracter) {
	if (string == NULL)
		return NULL;

	if (stringInvertida == NULL)
		stringInvertida = (char*) malloc(strlen(string) * sizeof(char));

	if (posUltimoCaracter >= 0) {
		stringInvertida[posPrimeiroCaracter] = string[posUltimoCaracter];
		return entregaQuestao1Questao2Tail(string, stringInvertida, posPrimeiroCaracter + 1, posUltimoCaracter - 1);
	}

	return stringInvertida;
}

void entregaQuestao1Peel(char* string) {
	printf("String invertida: %s", entregaQuestao1Questao2Tail(string, NULL, 0, strlen(string) - 1));
}

void entregaQuestao2Peel(char* string) {
	char* stringMinuscula = (char*) malloc(strlen(string) * sizeof(char));
	char* stringInvertidaMinuscula = entregaQuestao1Questao2Tail(string, NULL, 0, strlen(string) - 1);

	int i = 0;
	for (i = 0; i < strlen(string); i++) {
		stringMinuscula[i] = tolower(string[i]);
		stringInvertidaMinuscula[i] = tolower(stringInvertidaMinuscula[i]);
	}

	if (strcmp(stringMinuscula, stringInvertidaMinuscula) == 0)
		printf("A string é um palíndromo.");
	else
		printf("A string não é um palíndromo.");
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Quetão 3 - Entrega
void entregaQuestao3(unsigned int numero) {
	int contadorDigitos = 0;
	unsigned int aux = numero;
	while(aux != 0) {
		aux /= 10;
		contadorDigitos++;
	}

	char* numeroBinario = (char*) malloc(contadorDigitos * sizeof(char));
	itoa(numero, numeroBinario, 2);

	printf("Resultado (sem recursividade): %s", numeroBinario);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Quetão 3 - Entrega - RECURSIVA DIRETA, LINEAR, DE CAUDA E NÃO ANINHADA
char* entregaQuestao3Tail(unsigned int numero, char* resultado) {
	char* aux = (char*) malloc(20 * sizeof(char));
	int resto = numero % 2;

	itoa(resto, aux, 10);
	strcat(resultado, aux);
	if (numero != 1)
		entregaQuestao3Tail(numero / 2, resultado);

	char* resultadoInvertido = (char*) malloc(strlen(resultado) * sizeof(char));
	entregaQuestao1Questao2Tail(resultado, resultadoInvertido, 0, strlen(resultado) - 1);

	return resultadoInvertido;
}

void entregaQuestao3Peel(unsigned int numero) {
	printf("\nResultado (com recursividade): %s", entregaQuestao3Tail(numero, (char*) malloc(20 * sizeof(char))));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Questão 4A - Entrega - RECURSIVA DIRETA, LINEAR, DE CAUDA E NÃO ANINHADA
int entregaQuestao4ATail(int* vetor, int tamanho, int posicao, int maiorElemento) {
	if (posicao < tamanho) {
		if (vetor[posicao] >= maiorElemento)
			maiorElemento = vetor[posicao];

		posicao++;
		return entregaQuestao4ATail(vetor, tamanho, posicao, maiorElemento);
	} else {
		return maiorElemento;
	}
}

void entregaQuestao4APeel(int* vetor, int tamanho) {
	printf("Maior Elemento: %i", entregaQuestao4ATail(vetor, tamanho, 0, INT_MIN));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Questão 4B - Entrega - RECURSIVA DIRETA, LINEAR, DE CAUDA E NÃO ANINHADA
int entregaQuestao4BTail(int* vetor1, int* vetor2, int tamanhoVetor1, int tamanhoVetor2, int posicaoVetor1, int posicaoVetor2, int maiorElementoVetor1, int maiorElementoVetor2) {
	if (posicaoVetor1 < tamanhoVetor1) {
		if (vetor1[posicaoVetor1] >= maiorElementoVetor1)
			maiorElementoVetor1 = vetor1[posicaoVetor1];

		posicaoVetor1++;
		return entregaQuestao4BTail(vetor1, vetor2, tamanhoVetor1, tamanhoVetor2, posicaoVetor1, posicaoVetor2, maiorElementoVetor1, maiorElementoVetor2);
	}

	if (posicaoVetor2 < tamanhoVetor2) {
		if (vetor2[posicaoVetor2] >= maiorElementoVetor2)
			maiorElementoVetor2 = vetor2[posicaoVetor2];

		posicaoVetor2++;
		return entregaQuestao4BTail(vetor1, vetor2, tamanhoVetor1, tamanhoVetor2, posicaoVetor1, posicaoVetor2, maiorElementoVetor1, maiorElementoVetor2);
	}

	if (maiorElementoVetor1 >= maiorElementoVetor2)
		return maiorElementoVetor1;
	else
		return maiorElementoVetor2;
}

void entregaQuestao4BPeel(int* vetor1, int* vetor2, int tamanhoVetor1, int tamanhoVetor2) {
	printf("Maior Elemento: %i", entregaQuestao4BTail(vetor1, vetor2, tamanhoVetor1, tamanhoVetor2, 0, 0, INT_MIN, INT_MIN));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Questão 5 - Entrega - ITERATIVA
int entregaQuestao5Iterativa(int* vetor, int n, int elemento) {
	int inicio = 0;
	int meio;
	int final = n - 1;

	while (inicio <= final) {
		meio = (inicio + final) / 2;
		if (elemento < vetor[meio])
			final = meio - 1;
		else if (elemento > vetor[meio])
			inicio = meio + 1;
		else
			return meio;
	}

	return -1;
}

void entregaQuestao5IterativaPeel(int* vetor, int n, int elemento) {
	printf("Elemento (resultado por iteração): %i", entregaQuestao5Iterativa(vetor, n, elemento));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Questão 5 - Entrega - RECURSIVA DIRETA, LINEAR, DE CAUDA E NÃO ANINHADA
int entregaQuestao5Tail(int* vetor, int inicio, int final, int elemento) {
	int meio = (inicio + final) / 2;

	if (vetor[meio] == elemento)
		return meio;

	if (inicio >= final)
		return -1;
	else if (vetor[meio] < elemento)
		return entregaQuestao5Tail(vetor, meio + 1, final, elemento);
	else
		return entregaQuestao5Tail(vetor, inicio, meio - 1, elemento);
}

void entregaQuestao5RecursivaPeel(int* vetor, int n, int elemento) {
	printf("\nElemento (resultado por recursão): %i", entregaQuestao5Tail(vetor, 0, n - 1, elemento));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------- */
