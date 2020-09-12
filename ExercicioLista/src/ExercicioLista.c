/*
 ============================================================================
 Name        : ExercicioLista.c
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
#include "lista.h"
#include "matriz.h"

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);

	MATRIZ_ESPARSA* a = leMatriz("matriz_A.txt");
	MATRIZ_ESPARSA* b = leMatriz("matriz_B.txt");
	MATRIZ_ESPARSA* c = leMatriz("matriz_C.txt");
	MATRIZ_ESPARSA* d = leMatriz("matriz_D.txt");

	MATRIZ_ESPARSA* result = NULL;

	printf("-- MATRIZES ESPARSAS --\n");
	printf("\nMatriz A");
	imprimeMatriz(a);

	printf("\nMatriz B");
	imprimeMatriz(b);

	printf("\nMatriz C");
	imprimeMatriz(c);

	printf("\nMatriz D");
	imprimeMatriz(d);

	printf("\n");

	printf("\nSoma: A + B");
	result = somaMatriz(a, b);
	imprimeMatriz(result);
	apagaMatriz(result);

	printf("\nProduto: A * B");
	result = multiplicaMatriz(a, b);
	imprimeMatriz(result);
	apagaMatriz(result);

	printf("\nProduto: C * D");
	result = multiplicaMatriz(c, d);
	imprimeMatriz(result);
	apagaMatriz(result);

	apagaMatriz(a);
	apagaMatriz(b);
	apagaMatriz(c);
	apagaMatriz(d);

	printf("\n\nFIM DO PROGRAMA.");

	return EXIT_SUCCESS;
}
