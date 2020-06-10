/*
 ============================================================================
 Name        : Lab03Exercicio2QuickSort.c
 Author      : n226804875
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);

	printf("-- QUICK SORT --\n");

	VETOR v;
	int n = sizeof(v)/sizeof(ITEM);
	int i;

	for(i=0; i<n; i++) v[i].chave = i;

	permuta(v,n);

	printf("Original\n");
	imprime(v,n);

	quicksort(v,n);

	printf("Ordenado\n");
	imprime(v,n);

	system("PAUSE");
	printf("\n\nFim do Programa.");

	return EXIT_SUCCESS;
}
