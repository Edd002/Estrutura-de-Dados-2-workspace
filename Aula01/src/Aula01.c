/*
 ============================================================================
 Name        : Aula01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

int main(void) {
	setbuf(stdout, NULL);

	printf("Resultado da exponencial: %f", calcularExponencial(2, -7));
	printf("\nResultado do máximo divisor comum (MDC): %i", calcularMaximoDivisorComum(10, 15));
	printf("\nResultado do fatorial: %i", calcularFatorial(2));
	printf("\nFibonacci: %i\n\n", aquecimentoQuestao3RecursivaTail(4));

	hanoi(3, 'A', 'B', 'C');

	return EXIT_SUCCESS;
}
