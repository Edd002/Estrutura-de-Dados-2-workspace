/*
 * Library.c
 *
 *  Created on: 2 de ago de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

/*
 * 				1				para n = 0
 *
 * 		 		1 / x^(-n) 		para n < 0
 * 	x^n   =
 * 				(n^(n/2))^2		para n > 0; n par
 *
 * 				x * x^(n-1)		para n > 0; n ímpar
 * */
// CASO BASE: caso que finaliza a recursividade

// Recursividade
float calcularExponencial(float x, int n) {
	if (n == 0 )
		return 1.0;

	if (n < 0)
		return 1.0 / calcularExponencial(x, -n);

	if (n % 2 == 1)
		return x * calcularExponencial(x, n - 1);

	float f = calcularExponencial(x, n/2);
	return f * f;
}

/*
 * MDC (a, b) = MDC (b, a % b)		b != 0
 *
 * MDC (a, b) = a					b = 0
 * */
// Recursividade de cauda
int calcularMaximoDivisorComum(int a, int b) {
	return b == 0 ? a : calcularMaximoDivisorComum(b, a % b);
}

// Recursividade para torre de hanoi
// Três torres com três discos
void hanoi(int n, char origem, char destino, char auxiliar) {
	if (n > 1)
		hanoi(n - 1, origem, auxiliar, destino);

	printf("Transafeirir disco %d de %c para %c\n", n, origem, destino);

	if (n > 1)
		hanoi(n - 1, auxiliar, destino, origem);
}

// Recursividade para cálculo de fatorial
int calcularFatorial(int n) {
	return n == 0 ? 1 : n * calcularFatorial(n - 1);
}

int calcularFatorialCauda(int n, int resultado) {
	if (n == 0) return resultado;
	return calcularFatorialCauda(n - 1, n * resultado);
}

int fatorial(int n) {
	return calcularFatorialCauda(n, 1);
}

// Recursividade de Fibonacci (ineficiente)
int aquecimentoQuestao3RecursivaTail(int n) {
	return n < 3 ? 1 : aquecimentoQuestao3RecursivaTail(n -1) + aquecimentoQuestao3RecursivaTail(n - 2);
}
